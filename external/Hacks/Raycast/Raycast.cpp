#include "Raycast.hpp"
#include <atomic>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <limits>

namespace Hacks::Raycast
{
	namespace
	{
		using OccluderList = std::vector<Occluder>;

		static std::atomic<std::shared_ptr<const OccluderList>> g_Occluders =
			std::make_shared<const OccluderList>();
		static std::chrono::steady_clock::time_point g_LastScan;
	}

	static SDK::Vector3 RotateIntoLocal(const SDK::Matrix3& m, const SDK::Vector3& v)
	{
		return SDK::Vector3(
			m.data[0] * v.x + m.data[1] * v.y + m.data[2] * v.z,
			m.data[3] * v.x + m.data[4] * v.y + m.data[5] * v.z,
			m.data[6] * v.x + m.data[7] * v.y + m.data[8] * v.z);
	}

	static bool AxisBoxHit(const SDK::Vector3& From, const SDK::Vector3& dir, float len,
		const SDK::Vector3& Center, const SDK::Vector3& Half, float& tHit)
	{
		SDK::Vector3 o = From - Center;

		float t0 = 0.0f;
		float t1 = len;

		for (int axis = 0; axis < 3; axis++)
		{
			float ov = axis == 0 ? o.x : axis == 1 ? o.y : o.z;
			float dv = axis == 0 ? dir.x : axis == 1 ? dir.y : dir.z;
			float hv = axis == 0 ? Half.x : axis == 1 ? Half.y : Half.z;

			if (std::abs(dv) < 1e-8f)
			{
				if (ov < -hv || ov > hv)
					return false;
				continue;
			}

			float invD = 1.0f / dv;
			float tNear = (-hv - ov) * invD;
			float tFar = (hv - ov) * invD;
			if (tNear > tFar)
				std::swap(tNear, tFar);

			t0 = (std::max)(t0, tNear);
			t1 = (std::min)(t1, tFar);
			if (t0 > t1)
				return false;
		}

		tHit = t0;
		return true;
	}

	static bool SegmentBoxHit(const SDK::Vector3& From, const SDK::Vector3& To,
		const SDK::Vector3& Center, const SDK::Vector3& Half, float& tHit)
	{
		SDK::Vector3 dir = To - From;
		float len = dir.magnitude();
		if (len < 1e-6f)
		{
			SDK::Vector3 min = Center - Half;
			SDK::Vector3 max = Center + Half;
			if (From.x >= min.x && From.x <= max.x &&
				From.y >= min.y && From.y <= max.y &&
				From.z >= min.z && From.z <= max.z)
			{
				tHit = 0.0f;
				return true;
			}
			return false;
		}
		return AxisBoxHit(From, dir * (1.0f / len), len, Center, Half, tHit);
	}

	// ray vs OBB (rotation-aware), ported from the "jew" external
	static bool RotatedBoxHit(const SDK::Vector3& From, const SDK::Vector3& To,
		const Occluder& o, float& tHit)
	{
		SDK::Vector3 delta = To - From;
		float len = delta.magnitude();
		if (len < 1e-5f)
			return SegmentBoxHit(From, To, o.Center, o.Size * 0.5f, tHit);

		SDK::Vector3 dir = delta * (1.0f / len);

		// cheap sphere pre-reject
		SDK::Vector3 toPart = o.Center - From;
		float radius = o.Size.magnitude() * 0.5f;
		float distSq = toPart.x * toPart.x + toPart.y * toPart.y + toPart.z * toPart.z;
		float comb = radius + len;
		if (distSq > comb * comb)
			return false;

		SDK::Vector3 localOrigin = RotateIntoLocal(o.Rotation, From - o.Center);
		SDK::Vector3 localDir = RotateIntoLocal(o.Rotation, dir);
		SDK::Vector3 half = o.Size * 0.5f;

		float tmin = -(std::numeric_limits<float>::max)();
		float tmax = (std::numeric_limits<float>::max)();

		for (int axis = 0; axis < 3; axis++)
		{
			float oo = axis == 0 ? localOrigin.x : axis == 1 ? localOrigin.y : localOrigin.z;
			float dd = axis == 0 ? localDir.x : axis == 1 ? localDir.y : localDir.z;
			float mn = -(axis == 0 ? half.x : axis == 1 ? half.y : half.z);
			float mx = (axis == 0 ? half.x : axis == 1 ? half.y : half.z);

			if (std::fabs(dd) < 1e-6f)
			{
				if (oo < mn || oo > mx)
					return false;
				continue;
			}

			float t1 = (mn - oo) / dd;
			float t2 = (mx - oo) / dd;
			if (t1 > t2)
				std::swap(t1, t2);

			if (t1 > tmin) tmin = t1;
			if (t2 < tmax) tmax = t2;
			if (tmin > tmax || tmax < 0.0f || tmin > len)
				return false;
		}

		float hit = tmax;
		if (tmin >= 0.0f)
			hit = tmin;

		if (hit < 0.0f || hit > len || tmin > tmax)
			return false;

		tHit = hit;
		return true;
	}

	// walk an instance tree collecting every primitive address; used to ignore a
	// player's entire character (body + accessories + 3D layered clothing + hats)
	// so none of his own parts block the hit test
	static void CollectTreePrimitives(SDK::Instance inst, int depth, std::unordered_set<uintptr_t>& out)
	{
		if (!inst.Address || depth > 24)
			return;
		SDK::Primitive prim = inst.Primitive();
		if (prim.Address)
			out.insert(prim.Address);
		for (const SDK::Instance& child : inst.Children())
			CollectTreePrimitives(child, depth + 1, out);
	}

	// never let a player's own body parts become occluders, otherwise aiming at
	// a player constantly gets blocked by his limbs/torso and flickers
	static void CollectPlayerPrimitives(std::unordered_set<uintptr_t>& out)
	{
		out.clear();

		// snapshot the cached instances under a brief lock, then walk the live
		// instance trees outside it; the old version held PlayersMutex for the
		// whole tree walk (starvation) and deadlocked callers that already held it
		std::vector<SDK::Instance> roots;
		roots.reserve(256);

		SDK::Cache::PlayersMutex.lock();
		try
		{
			auto addPlayer = [&](const SDK::Cache::Player& p)
			{
				if (p.CharacterObject.Address) roots.push_back(p.CharacterObject);
				if (p.Head.Object.Address) roots.push_back(p.Head.Object);
				if (p.HumanoidRootPart.Object.Address) roots.push_back(p.HumanoidRootPart.Object);
				for (const auto& bone : p.Bones)
					if (bone.Object.Address) roots.push_back(bone.Object);
			};
			for (const auto& p : SDK::Cache::Players)
				addPlayer(p);
			addPlayer(SDK::Cache::LocalPlayer);
		}
		catch (...)
		{
		}
		SDK::Cache::PlayersMutex.unlock();

		for (const SDK::Instance& inst : roots)
			CollectTreePrimitives(inst, 0, out);
	}

	static void WalkChildren(SDK::Instance inst, int depth,
		const std::unordered_set<uintptr_t>& ignore, std::vector<Occluder>& Out)
	{
		if (!inst.Address || depth > 16)
			return;

		SDK::Primitive prim = inst.Primitive();
		if (prim.Address && ignore.find(prim.Address) == ignore.end())
		{
			SDK::Vector3 size = prim.Size();
			if (size.x > 1e-3f && size.y > 1e-3f && size.z > 1e-3f &&
				size.x < 2000.0f && size.y < 2000.0f && size.z < 2000.0f)
			{
				Occluder o;
				o.Primitive = prim.Address;
				o.Center = prim.Position();
				o.Size = size;
				try
				{
					o.Rotation = prim.Rotation();
				}
				catch (...)
				{
					o.Rotation = SDK::Matrix3{};
				}
				Out.emplace_back(o);
			}
		}

		for (const SDK::Instance& child : inst.Children())
			WalkChildren(child, depth + 1, ignore, Out);
	}

	static void Rescan()
	{
		std::unordered_set<uintptr_t> ignore;
		try { CollectPlayerPrimitives(ignore); } catch (...) {}

		std::vector<Occluder> next;
		try { WalkChildren(Globals::Workspace, 0, ignore, next); } catch (...) {}

		g_Occluders.store(std::make_shared<const OccluderList>(std::move(next)), std::memory_order_release);
		g_LastScan = std::chrono::steady_clock::now();
	}

	void Setup()
	{
		g_LastScan = std::chrono::steady_clock::now();
		std::thread([]() {
			while (true)
			{
				if (Hacks::Raycast::ScanNeeded())
				{
					int delayMs = (std::max)(50, Globals::Raycast::Delay);
					if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - g_LastScan).count() >= delayMs)
					{
						try { Rescan(); } catch (...) {}
					}
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(20));
			}
		}).detach();
	}

	static double NowSec()
	{
		return std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count();
	}

	// raw per-query check (no smoothing), only walls/geometry count
	static bool QueryVisible(const SDK::Vector3& From, const SDK::Vector3& To, uintptr_t IgnoreA, uintptr_t IgnoreB)
	{
		auto occl = g_Occluders.load(std::memory_order_acquire);
		if (!occl || occl->empty())
			return true;

		SDK::Vector3 delta = To - From;
		float len = delta.magnitude();

		for (const Occluder& o : *occl)
		{
			if (o.Primitive == IgnoreA || o.Primitive == IgnoreB)
				continue;

			float tHit;
			if (!RotatedBoxHit(From, To, o, tHit))
				continue;

			// ignore hits basically at the camera, otherwise walls on your face
			// constantly trigger; ignore hits basically at the target too, so a
			// wall hugging the target doesn't flicker the result
			if (tHit <= 0.15f)
				continue;
			if ((len - tHit) <= 0.55f)
				continue;

			return false;
		}
		return true;
	}

	struct SmoothedState
	{
		float smoothed = 1.0f;
		bool visible = true;
		double lastTime = 0.0;
		double lastQuery = 0.0;
		int visConf = 0;
		int occConf = 0;
		bool lastResult = true;
	};

	bool IsVisible(const SDK::Vector3& From, const SDK::Vector3& To, uintptr_t IgnoreA, uintptr_t IgnoreB)
	{
		uintptr_t key = IgnoreB ? IgnoreB : IgnoreA;
		thread_local std::unordered_map<uintptr_t, SmoothedState> smooth;
		SmoothedState& state = smooth[key];

		double now = NowSec();

		// don't re-query every frame per target
		if (state.lastQuery != 0.0 && (now - state.lastQuery) < 0.015)
			return state.lastResult;
		state.lastQuery = now;

		bool raw = QueryVisible(From, To, IgnoreA, IgnoreB);

		float coverage = raw ? 1.0f : 0.0f;
		float alpha = 0.28f;
		if (state.lastTime == 0.0)
			alpha = 1.0f;
		else if (raw)
			alpha = 0.4f;

		state.smoothed = state.smoothed * (1.0f - alpha) + coverage * alpha;

		if (raw)
		{
			if (state.visConf < 16) state.visConf += 1;
			state.occConf = 0;
			if (state.smoothed < coverage) state.smoothed = coverage;
		}
		else
		{
			if (state.occConf < 16) state.occConf += 1;
			state.visConf = 0;
		}

		// hysteresis: different on/off thresholds stop the microsecond flicker
		if (state.visible)
		{
			if (!raw && state.smoothed <= 0.22f && state.occConf >= 4)
				state.visible = false;
		}
		else
		{
			if ((state.smoothed >= 0.48f && state.visConf >= 2) || state.visConf >= 3)
				state.visible = true;
		}

		if (state.lastTime == 0.0)
		{
			state.visible = raw;
			state.smoothed = coverage;
			state.visConf = raw ? 1 : 0;
			state.occConf = raw ? 0 : 1;
		}

		state.lastTime = now;
		state.lastResult = state.visible;
		return state.visible;
	}

	void TestSegment(const SDK::Vector3& From, const SDK::Vector3& To, std::vector<Occluder>& Out)
	{
		Out.clear();
		auto occl = g_Occluders.load(std::memory_order_acquire);
		if (!occl || occl->empty())
			return;

		float best = (std::numeric_limits<float>::max)();
		int bestIdx = -1;
		for (int i = 0; i < (int)occl->size(); i++)
		{
			float tHit;
			if (RotatedBoxHit(From, To, (*occl)[i], tHit))
			{
				if (tHit < best)
				{
					best = tHit;
					bestIdx = i;
				}
			}
		}
		if (bestIdx >= 0)
			Out.push_back((*occl)[bestIdx]);
	}
}