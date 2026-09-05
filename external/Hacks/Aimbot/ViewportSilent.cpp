#include "ViewportSilent.hpp"

#define NOMINMAX
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>
#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdint>
#include <thread>

namespace Hacks::ViewportSilent
{
	namespace
	{
		struct Vec2i16 {
			std::int16_t x = 0;
			std::int16_t y = 0;
		};

		std::atomic<bool> g_active{ false };
		std::atomic<bool> g_stop{ false };
		std::atomic<bool> g_spoofed{ false };
		std::atomic<float> g_tx{ 0.f }, g_ty{ 0.f }, g_tz{ 0.f };

		HANDLE g_thread = nullptr;
		uintptr_t g_cam = 0;
		SDK::Vector2 g_dims{};
		Vec2i16 g_last{};
		int g_fails = 0;

		SDK::Vector2 world_to_screen(const SDK::Vector3& pos, SDK::Vector2& dims_out)
		{
			SDK::Matrix4 view = SDK::VisualEngineCache::ViewMatrix;
			SDK::Vector2 dims = SDK::VisualEngineCache::Dimensions;
			if (dims.x < 1.f || dims.y < 1.f)
				return {};

			float x = pos.x * view.data[0] + pos.y * view.data[1] + pos.z * view.data[2] + view.data[3];
			float y = pos.x * view.data[4] + pos.y * view.data[5] + pos.z * view.data[6] + view.data[7];
			float w = pos.x * view.data[12] + pos.y * view.data[13] + pos.z * view.data[14] + view.data[15];
			if (w < 0.001f)
				return {};

			float inv = 1.0f / w;
			x *= inv;
			y *= inv;

			dims_out = dims;
			return {
				(dims.x * 0.5f) * (1.0f + x),
				(dims.y * 0.5f) * (1.0f - y)
			};
		}

		Vec2i16 calc_viewport(const SDK::Vector2& target, const SDK::Vector2& dims, const SDK::Vector2& mouse)
		{
			double ty = (double)target.y;
			if (ty > (double)dims.y - 1.0) ty = (double)dims.y - 1.0;
			if (ty < 1.0) ty = 1.0;

			double ratio = (double)mouse.y / ty;
			double vy = (double)dims.y * ratio;
			if (vy > 32767.0) vy = 32767.0;
			if (vy < 1.0) vy = 1.0;

			ratio = vy / (double)dims.y;
			double vx = 2.0 * (double)mouse.x - ratio * (2.0 * (double)target.x - (double)dims.x);
			if (vx > 32767.0) vx = 32767.0;
			if (vx < 1.0) vx = 1.0;

			return { (std::int16_t)std::lround(vx), (std::int16_t)std::lround(vy) };
		}

		bool mouse_in_viewport(const SDK::Vector2& dims, SDK::Vector2& out)
		{
			HWND hwnd = Globals::RobloxWindow;
			if (!hwnd || !IsWindow(hwnd))
				return false;

			POINT pt{};
			if (!GetCursorPos(&pt) || !ScreenToClient(hwnd, &pt))
				return false;

			RECT cr{};
			if (!GetClientRect(hwnd, &cr))
				return false;

			float cw = (float)(cr.right - cr.left);
			float ch = (float)(cr.bottom - cr.top);
			if (cw < 1.f || ch < 1.f)
				return false;

			if (pt.x < 0 || pt.y < 0 || pt.x >= cr.right || pt.y >= cr.bottom)
				return false;

			float mx = (float)pt.x * (dims.x / cw);
			float my = (float)pt.y * (dims.y / ch);
			if (mx > dims.x - 1.f) mx = dims.x - 1.f;
			if (mx < 1.f) mx = 1.f;
			if (my > dims.y - 1.f) my = dims.y - 1.f;
			if (my < 1.f) my = 1.f;

			out.x = mx;
			out.y = my;
			return true;
		}

		bool resolve_cam(uintptr_t& cam)
		{
			try
			{
				SDK::Camera Camera = (SDK::Camera)Globals::Workspace.FindFirstChildOfClass("Camera");
				if (!Camera.Address || !SDK::Memory->IsValid(Camera.Address))
					return false;
				cam = Camera.Address;
				return true;
			}
			catch (...)
			{
				return false;
			}
		}

		void write_viewport(const Vec2i16& v)
		{
			if (!SDK::Memory->IsValid(g_cam))
				return;

			SDK::Memory->WriteRaw(g_cam + SDK::Offsets::ViewportInt16, &v, sizeof(v));
			g_spoofed.store(true, std::memory_order_release);
		}

		void restore_viewport()
		{
			if (!SDK::Memory->IsValid(g_cam) || g_dims.x < 1.f || g_dims.y < 1.f)
				return;

			Vec2i16 v{
				(std::int16_t)std::lround(g_dims.x),
				(std::int16_t)std::lround(g_dims.y)
			};
			SDK::Memory->WriteRaw(g_cam + SDK::Offsets::ViewportInt16, &v, sizeof(v));
		}

		bool compute(Vec2i16& out)
		{
			SDK::Vector3 world{
				g_tx.load(std::memory_order_relaxed),
				g_ty.load(std::memory_order_relaxed),
				g_tz.load(std::memory_order_relaxed)
			};

			uintptr_t cam = g_cam;
			if (!cam || !SDK::Memory->IsValid(cam))
			{
				if (!resolve_cam(cam))
					return false;
			}

			SDK::Vector2 dims{};
			SDK::Vector2 w2s = world_to_screen(world, dims);
			if (w2s.x <= 0.f || w2s.y <= 0.f || w2s.x >= dims.x || w2s.y >= dims.y)
				return false;

			SDK::Vector2 mouse{};
			if (!mouse_in_viewport(dims, mouse))
				return false;

			out = calc_viewport(w2s, dims, mouse);
			g_cam = cam;
			g_dims = dims;
			return true;
		}

		DWORD WINAPI writer_thread(LPVOID)
		{
			SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);
			bool on = false;

			while (!g_stop.load(std::memory_order_acquire))
			{
				if (!g_active.load(std::memory_order_acquire))
				{
					if (on)
					{
						restore_viewport();
						g_spoofed.store(false, std::memory_order_release);
						g_fails = 0;
						on = false;
					}
					Sleep(16);
					continue;
				}

				Vec2i16 v{};
				if (compute(v))
				{
					g_last = v;
					g_fails = 0;
					on = true;
					write_viewport(g_last);
				}
				else if (on && g_fails < 40)
				{
					++g_fails;
					write_viewport(g_last);
				}
				else if (on)
				{
					restore_viewport();
					g_spoofed.store(false, std::memory_order_release);
					on = false;
					g_fails = 0;
				}

				Sleep(1);
			}

			restore_viewport();
			g_spoofed.store(false, std::memory_order_release);
			return 0;
		}

		void ensure_thread()
		{
			if (g_thread) return;
			g_stop.store(false, std::memory_order_release);
			g_thread = CreateThread(nullptr, 0, &writer_thread, nullptr, 0, nullptr);
			if (g_thread)
				SetThreadPriority(g_thread, THREAD_PRIORITY_HIGHEST);
		}
	}

	void Restore()
	{
		g_active.store(false, std::memory_order_release);
		restore_viewport();
		g_spoofed.store(false, std::memory_order_release);
	}

	void SetActive(bool on, const SDK::Vector3& world_target)
	{
		if (!on)
		{
			Restore();
			return;
		}

		ensure_thread();
		g_tx.store(world_target.x, std::memory_order_relaxed);
		g_ty.store(world_target.y, std::memory_order_relaxed);
		g_tz.store(world_target.z, std::memory_order_relaxed);
		g_active.store(true, std::memory_order_release);
	}

	void Shutdown()
	{
		g_active.store(false, std::memory_order_release);
		if (!g_thread) return;
		g_stop.store(true, std::memory_order_release);
		WaitForSingleObject(g_thread, 1000);
		CloseHandle(g_thread);
		g_thread = nullptr;
		g_cam = 0;
		g_dims = {};
	}

	bool Aiming()
	{
		return g_active.load(std::memory_order_acquire) &&
			g_spoofed.load(std::memory_order_acquire);
	}
}