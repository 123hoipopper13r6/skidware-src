#pragma once
#include <string>
#include <vector>
#include <cstdint>
#include <istream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstdio>

namespace Hacks::Preview
{
	struct ModelVertex {
		float x, y, z;
		float nx, ny, nz;
		float u, v;
	};

	struct ModelTri {
		int i0, i1, i2;
	};

	struct ModelPartAABB {
		float min[3] = {};
		float max[3] = {};
		bool valid = false;
	};

	struct LoadedModel {
		std::vector<ModelVertex> vertices;
		std::vector<ModelVertex> wing_vertices;
		std::vector<float> positions;
		std::vector<ModelTri> tris;
		std::vector<ModelTri> body_tris;
		std::vector<float> body_positions;
		std::vector<float> box_positions;
		std::vector<ModelPartAABB> body_parts;
		std::vector<ModelPartAABB> box_parts;
		float scale = 1.0f;
		float center[3] = {};
		float raw_min[3] = {};
		float raw_max[3] = {};
		float body_min[3] = {};
		float body_max[3] = {};
		float box_min[3] = {};
		float box_max[3] = {};
	};

	namespace
	{
		struct GroupAccum {
			std::string name;
			bool handle = false;
			ModelPartAABB aabb{};
			std::vector<float> pos;
			std::vector<ModelVertex> mesh;
		};

		bool IsHandleGroup(const std::string& g)
		{
			return g.size() >= 6 && g.compare(0, 6, "Handle") == 0;
		}

		void ExpandAABB(ModelPartAABB& a, float x, float y, float z)
		{
			if (!a.valid)
			{
				a.min[0] = a.max[0] = x;
				a.min[1] = a.max[1] = y;
				a.min[2] = a.max[2] = z;
				a.valid = true;
				return;
			}
			if (x < a.min[0]) a.min[0] = x;
			if (x > a.max[0]) a.max[0] = x;
			if (y < a.min[1]) a.min[1] = y;
			if (y > a.max[1]) a.max[1] = y;
			if (z < a.min[2]) a.min[2] = z;
			if (z > a.max[2]) a.max[2] = z;
		}

		void BoundsFromPos(const std::vector<float>& pos, float mn[3], float mx[3])
		{
			mn[0] = mn[1] = mn[2] = 1e9f;
			mx[0] = mx[1] = mx[2] = -1e9f;
			for (size_t i = 0; i + 2 < pos.size(); i += 3) {
				mn[0] = (std::min)(mn[0], pos[i]);     mx[0] = (std::max)(mx[0], pos[i]);
				mn[1] = (std::min)(mn[1], pos[i + 1]); mx[1] = (std::max)(mx[1], pos[i + 1]);
				mn[2] = (std::min)(mn[2], pos[i + 2]); mx[2] = (std::max)(mx[2], pos[i + 2]);
			}
		}

		bool IsWingLikeAccessory(const ModelPartAABB& a, float bodyW, float bodyH)
		{
			if (!a.valid)
				return false;

			float ex = a.max[0] - a.min[0];
			float ey = a.max[1] - a.min[1];
			float ez = a.max[2] - a.min[2];

			float wingW = bodyW * 1.25f;
			if (wingW < 3.2f) wingW = 3.2f;
			float wingD = bodyW * 1.05f;
			if (wingD < 2.4f) wingD = 2.4f;

			if (ex >= wingW)
				return true;

			if (ez >= wingD && ez > ey * 0.85f)
				return true;

			if (ex >= bodyH * 0.85f && ex > ey * 1.4f)
				return true;

			return false;
		}

		void FinalizeModel(LoadedModel& out, std::vector<GroupAccum>& groups)
		{
			out.vertices.clear();
			out.wing_vertices.clear();
			out.body_positions.clear();
			out.body_parts.clear();
			out.box_positions.clear();
			out.box_parts.clear();

			for (auto& g : groups) {
				if (!g.handle && g.aabb.valid) {
					out.body_parts.push_back(g.aabb);
					out.body_positions.insert(out.body_positions.end(), g.pos.begin(), g.pos.end());
				}
			}

			if (!out.body_positions.empty())
				BoundsFromPos(out.body_positions, out.body_min, out.body_max);
			else if (!out.positions.empty())
				BoundsFromPos(out.positions, out.body_min, out.body_max);

			float bodyW = out.body_max[0] - out.body_min[0];
			float bodyH = out.body_max[1] - out.body_min[1];
			if (bodyW < 0.01f) bodyW = 0.01f;
			if (bodyH < 0.01f) bodyH = 0.01f;

			for (auto& g : groups)
			{
				bool wing = g.handle && IsWingLikeAccessory(g.aabb, bodyW, bodyH);
				if (wing)
				{
					out.wing_vertices.insert(out.wing_vertices.end(), g.mesh.begin(), g.mesh.end());
					continue;
				}

				out.vertices.insert(out.vertices.end(), g.mesh.begin(), g.mesh.end());

				if (g.aabb.valid)
				{
					out.box_parts.push_back(g.aabb);
					out.box_positions.insert(out.box_positions.end(), g.pos.begin(), g.pos.end());
				}
			}

			if (out.box_positions.empty())
				out.box_positions = out.body_positions;

			if (!out.box_positions.empty())
			{
				BoundsFromPos(out.box_positions, out.box_min, out.box_max);
			}
			else
			{
				for (int i = 0; i < 3; ++i)
				{
					out.box_min[i] = out.body_min[i];
					out.box_max[i] = out.body_max[i];
				}
			}

			std::vector<float> framePos = out.box_positions;
			if (framePos.empty())
			{
				for (const auto& v : out.vertices)
				{
					framePos.push_back(v.x);
					framePos.push_back(v.y);
					framePos.push_back(v.z);
				}
			}
			if (!framePos.empty())
				BoundsFromPos(framePos, out.raw_min, out.raw_max);
			else if (!out.positions.empty())
				BoundsFromPos(out.positions, out.raw_min, out.raw_max);

			out.center[0] = (out.raw_min[0] + out.raw_max[0]) * 0.5f;
			out.center[1] = (out.raw_min[1] + out.raw_max[1]) * 0.5f;
			out.center[2] = (out.raw_min[2] + out.raw_max[2]) * 0.5f;

			float ext0 = out.raw_max[0] - out.raw_min[0];
			float ext1 = out.raw_max[1] - out.raw_min[1];
			float ext2 = out.raw_max[2] - out.raw_min[2];
			float maxExt = ext0;
			if (ext1 > maxExt) maxExt = ext1;
			if (ext2 > maxExt) maxExt = ext2;

			out.scale = 1.0f;
			if (maxExt > 0.0f)
				out.scale = 1.0f / maxExt;
		}

		bool ParseOBJStream(std::istream& stream, LoadedModel& out)
		{
			out = {};
			std::vector<float> uvs;
			std::vector<float> norms;
			std::vector<GroupAccum> groups;
			GroupAccum* cur = nullptr;
			std::string line;

			auto beginGroup = [&](const std::string& name)
			{
				groups.push_back({});
				cur = &groups.back();
				cur->name = name;
				cur->handle = IsHandleGroup(name);
			};

			beginGroup("default");

			while (std::getline(stream, line))
			{
				if (line.empty() || line[0] == '#')
					continue;
				const char* s = line.c_str();

				if (s[0] == 'g' && (s[1] == ' ' || s[1] == '\t'))
				{
					std::string group = line.substr(2);
					while (!group.empty() && (group.back() == '\r' || group.back() == ' '))
						group.pop_back();
					beginGroup(group);
					continue;
				}

				if (s[0] == 'v' && s[1] == ' ')
				{
					float x, y, z;
					if (sscanf_s(s + 2, "%f %f %f", &x, &y, &z) == 3)
					{
						out.positions.push_back(x);
						out.positions.push_back(y);
						out.positions.push_back(z);
						if (cur)
						{
							cur->pos.push_back(x);
							cur->pos.push_back(y);
							cur->pos.push_back(z);
							ExpandAABB(cur->aabb, x, y, z);
						}
					}
				}
				else if (s[0] == 'v' && s[1] == 't')
				{
					float u, v;
					if (sscanf_s(s + 3, "%f %f", &u, &v) == 2)
					{
						uvs.push_back(u);
						uvs.push_back(v);
					}
				}
				else if (s[0] == 'v' && s[1] == 'n')
				{
					float nx, ny, nz;
					if (sscanf_s(s + 3, "%f %f %f", &nx, &ny, &nz) == 3)
					{
						norms.push_back(nx);
						norms.push_back(ny);
						norms.push_back(nz);
					}
				}
				else if (s[0] == 'f' && s[1] == ' ')
				{
					struct Idx { int v, vt, vn; };
					Idx idx[8];
					int count = 0;
					const char* p = s + 2;
					while (*p && count < 8) {
						while (*p == ' ') ++p;
						if (!*p) break;
						int vi = 0, vti = 0, vni = 0;
						while (*p >= '0' && *p <= '9') vi = vi * 10 + (*p++ - '0');
						if (*p == '/') {
							++p;
							if (*p != '/') {
								while (*p >= '0' && *p <= '9') vti = vti * 10 + (*p++ - '0');
							}
							if (*p == '/') {
								++p;
								while (*p >= '0' && *p <= '9') vni = vni * 10 + (*p++ - '0');
							}
						}
						if (vi > 0)
							idx[count++] = { vi - 1, vti - 1, vni - 1 };
						else
							break;
					}

					const bool bodyFace = cur && !cur->handle;
					auto emit = [&](Idx a, Idx b, Idx c) {
						auto make = [&](Idx i) {
							ModelVertex mv{};
							mv.nx = 0.0f; mv.ny = 1.0f; mv.nz = 0.0f;
							if (i.v >= 0 && i.v * 3 + 2 < (int)out.positions.size()) {
								mv.x = out.positions[i.v * 3 + 0];
								mv.y = out.positions[i.v * 3 + 1];
								mv.z = out.positions[i.v * 3 + 2];
							}
							if (i.vn >= 0 && i.vn * 3 + 2 < (int)norms.size()) {
								mv.nx = norms[i.vn * 3 + 0];
								mv.ny = norms[i.vn * 3 + 1];
								mv.nz = norms[i.vn * 3 + 2];
							}
							if (i.vt >= 0 && i.vt * 2 + 1 < (int)uvs.size()) {
								mv.u = uvs[i.vt * 2 + 0];
								mv.v = 1.0f - uvs[i.vt * 2 + 1];
							}
							return mv;
						};
						if (cur) {
							cur->mesh.push_back(make(a));
							cur->mesh.push_back(make(b));
							cur->mesh.push_back(make(c));
						}
						if (a.v >= 0 && b.v >= 0 && c.v >= 0) {
							ModelTri t{ a.v, b.v, c.v };
							out.tris.push_back(t);
							if (bodyFace) out.body_tris.push_back(t);
						}
					};

					if (count == 3)
						emit(idx[0], idx[1], idx[2]);
					else if (count == 4)
					{
						emit(idx[0], idx[1], idx[2]);
						emit(idx[0], idx[2], idx[3]);
					}
					else if (count > 4)
					{
						for (int i = 1; i + 1 < count; ++i)
							emit(idx[0], idx[i], idx[i + 1]);
					}
				}
			}

			FinalizeModel(out, groups);
			return !out.vertices.empty() || !out.wing_vertices.empty();
		}
	}

	inline bool LoadOBJ(const std::string& path, LoadedModel& out)
	{
		std::ifstream file(path, std::ios::binary);
		if (!file) return false;
		return ParseOBJStream(file, out);
	}

	inline bool LoadOBJFromMemory(const char* src, std::size_t len, LoadedModel& out)
	{
		if (!src || len == 0) return false;
		std::string buf(src, src + len);
		std::istringstream stream(buf);
		return ParseOBJStream(stream, out);
	}
}
