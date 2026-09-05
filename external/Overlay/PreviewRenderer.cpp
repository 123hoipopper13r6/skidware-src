#include "PreviewRenderer.hpp"
#include "../Includes.hpp"
#include "../Libs/stb_image.h"
#include <d3dcompiler.h>
#include <cmath>
#include <cstring>
#include <algorithm>

namespace Hacks::Preview
{
	namespace
	{
		typedef float Mat4[16];

		void MatIdentity(Mat4& m)
		{
			for (int i = 0; i < 16; ++i) m[i] = 0.0f;
			m[0] = m[5] = m[10] = m[15] = 1.0f;
		}

		void MatTranslation(float x, float y, float z, Mat4& m)
		{
			MatIdentity(m);
			m[12] = x; m[13] = y; m[14] = z;
		}

		void MatScaling(float sx, float sy, float sz, Mat4& m)
		{
			MatIdentity(m);
			m[0] = sx; m[5] = sy; m[10] = sz;
		}

		void MatRotationX(float a, Mat4& m)
		{
			MatIdentity(m);
			float c = std::cos(a), s = std::sin(a);
			m[5] = c; m[6] = s;
			m[9] = -s; m[10] = c;
		}

		void MatRotationY(float a, Mat4& m)
		{
			MatIdentity(m);
			float c = std::cos(a), s = std::sin(a);
			m[0] = c; m[2] = -s;
			m[8] = s; m[10] = c;
		}

		void MatMultiply(const Mat4& a, const Mat4& b, Mat4& out)
		{
			Mat4 r{};
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
				{
					float v = 0.0f;
					for (int k = 0; k < 4; ++k)
						v += a[i * 4 + k] * b[k * 4 + j];
					r[i * 4 + j] = v;
				}
			std::memcpy(out, r, sizeof(r));
		}

		void MatTranspose(const Mat4& m, Mat4& out)
		{
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
					out[j * 4 + i] = m[i * 4 + j];
		}

		struct Vec3 { float x, y, z; };

		Vec3 V3(float x, float y, float z) { return { x, y, z }; }

		Vec3 V3Sub(const Vec3& a, const Vec3& b) { return { a.x - b.x, a.y - b.y, a.z - b.z }; }

		float V3Dot(const Vec3& a, const Vec3& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

		Vec3 V3Cross(const Vec3& a, const Vec3& b)
		{
			return {
				a.y * b.z - a.z * b.y,
				a.z * b.x - a.x * b.z,
				a.x * b.y - a.y * b.x
			};
		}

		Vec3 V3Normalize(const Vec3& v)
		{
			float len = std::sqrt(V3Dot(v, v));
			if (len < 1e-6f) return { 0.0f, 0.0f, 0.0f };
			return { v.x / len, v.y / len, v.z / len };
		}

		void MatLookAtLH(const Vec3& eye, const Vec3& at, const Vec3& up, Mat4& m)
		{
			Vec3 zaxis = V3Normalize(V3Sub(at, eye));
			Vec3 xaxis = V3Normalize(V3Cross(up, zaxis));
			Vec3 yaxis = V3Cross(zaxis, xaxis);

			Mat4 r{};
			r[0] = xaxis.x; r[4] = xaxis.y; r[8] = xaxis.z; r[12] = -V3Dot(xaxis, eye);
			r[1] = yaxis.x; r[5] = yaxis.y; r[9] = yaxis.z; r[13] = -V3Dot(yaxis, eye);
			r[2] = zaxis.x; r[6] = zaxis.y; r[10] = zaxis.z; r[14] = -V3Dot(zaxis, eye);
			r[15] = 1.0f;
			std::memcpy(m, r, sizeof(r));
		}

		void MatPerspectiveFovLH(float fovY, float aspect, float zn, float zf, Mat4& m)
		{
			float h = 1.0f / std::tan(fovY * 0.5f);
			float w = h / aspect;
			Mat4 r{};
			r[0] = w;
			r[5] = h;
			r[10] = zf / (zf - zn);
			r[11] = 1.0f;
			r[14] = -zn * zf / (zf - zn);
			std::memcpy(m, r, sizeof(r));
		}

		bool UploadVerts(ID3D11Device* device, std::vector<ModelVertex>& verts,
			ID3D11Buffer** ppVB, unsigned int& vertCount)
		{
			if (verts.empty()) return false;
			if (*ppVB) { (*ppVB)->Release(); *ppVB = nullptr; }
			vertCount = (unsigned int)verts.size();
			D3D11_BUFFER_DESC bd{};
			bd.ByteWidth = (UINT)(sizeof(ModelVertex) * verts.size());
			bd.Usage = D3D11_USAGE_IMMUTABLE;
			bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			D3D11_SUBRESOURCE_DATA sd{};
			sd.pSysMem = verts.data();
			return SUCCEEDED(device->CreateBuffer(&bd, &sd, ppVB));
		}

		bool UploadPng(ID3D11Device* device, const stbi_uc* data, int w, int h,
			ID3D11Texture2D** ppTex, ID3D11ShaderResourceView** ppSRV,
			ID3D11SamplerState** ppSamp)
		{
			if (*ppSRV) { (*ppSRV)->Release(); *ppSRV = nullptr; }
			if (*ppTex) { (*ppTex)->Release(); *ppTex = nullptr; }
			if (*ppSamp) { (*ppSamp)->Release(); *ppSamp = nullptr; }

			D3D11_TEXTURE2D_DESC td{};
			td.Width = (UINT)w; td.Height = (UINT)h; td.MipLevels = 0; td.ArraySize = 1;
			td.Format = DXGI_FORMAT_R8G8B8A8_UNORM; td.SampleDesc.Count = 1;
			td.Usage = D3D11_USAGE_DEFAULT;
			td.BindFlags = D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_RENDER_TARGET;
			td.MiscFlags = D3D11_RESOURCE_MISC_GENERATE_MIPS;
			if (FAILED(device->CreateTexture2D(&td, nullptr, ppTex))) return false;

			D3D11_SHADER_RESOURCE_VIEW_DESC srvd{};
			srvd.Format = td.Format;
			srvd.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
			srvd.Texture2D.MipLevels = (UINT)-1;
			if (FAILED(device->CreateShaderResourceView(*ppTex, &srvd, ppSRV))) return false;

			ID3D11DeviceContext* ctx = nullptr;
			device->GetImmediateContext(&ctx);
			if (ctx) {
				ctx->UpdateSubresource(*ppTex, 0, nullptr, data, (UINT)(w * 4), 0);
				ctx->GenerateMips(*ppSRV);
				ctx->Release();
			}

			D3D11_SAMPLER_DESC smd{};
			smd.Filter = D3D11_FILTER_ANISOTROPIC;
			smd.MaxAnisotropy = 8;
			smd.AddressU = smd.AddressV = smd.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
			smd.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
			smd.MinLOD = 0.0f;
			smd.MaxLOD = D3D11_FLOAT32_MAX;
			return SUCCEEDED(device->CreateSamplerState(&smd, ppSamp));
		}

		static const char s_VS[] = R"(
cbuffer CB : register(b0) {
    float4x4 g_MVP;
    float4x4 g_World;
    float4   g_Opacity;
    float4   g_Tint;
};
struct VS_In {
    float3 pos : POSITION;
    float3 nrm : NORMAL;
    float2 uv  : TEXCOORD;
};
struct VS_Out {
    float4 pos : SV_POSITION;
    float3 nrm : NORMAL;
    float2 uv  : TEXCOORD;
};
VS_Out main(VS_In v) {
    VS_Out o;
    o.pos = mul(float4(v.pos, 1.0), g_MVP);
    o.nrm = mul(v.nrm, (float3x3)g_World);
    o.uv  = v.uv;
    return o;
}
)";
		static const char s_PS[] = R"(
cbuffer CB : register(b0) {
    float4x4 g_MVP;
    float4x4 g_World;
    float4   g_Opacity;
    float4   g_Tint;
};
Texture2D    g_Tex  : register(t0);
SamplerState g_Sam  : register(s0);
struct VS_Out {
    float4 pos : SV_POSITION;
    float3 nrm : NORMAL;
    float2 uv  : TEXCOORD;
};
float4 main(VS_Out v) : SV_Target {
    float4 tex = g_Tex.Sample(g_Sam, v.uv);
    float solid = saturate(g_Opacity.w);
    float3 base = lerp(tex.rgb, float3(1.0, 1.0, 1.0), solid);
    float3 n = normalize(v.nrm);
    float ndl = saturate(dot(n, float3(0.0, 0.85, -0.3)));
    float light = 0.78 + ndl * 0.22;
    return float4(base * g_Tint.rgb * light * 0.92, saturate(g_Opacity.x));
}
)";

		bool CompileShader(const char* src, const char* entry, const char* profile, ID3DBlob** out)
		{
			ID3DBlob* err = nullptr;
			HRESULT hr = D3DCompile(src, strlen(src), nullptr, nullptr, nullptr,
				entry, profile, D3DCOMPILE_OPTIMIZATION_LEVEL3, 0, out, &err);
			if (err) err->Release();
			return SUCCEEDED(hr);
		}
	}

	bool PreviewRenderer::CreateRenderTarget(unsigned int w, unsigned int h)
	{
		m_SampleCount = 1;
		UINT quality = 0;
		if (SUCCEEDED(m_Device->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, 4, &quality)) && quality > 0)
			m_SampleCount = 4;
		else if (SUCCEEDED(m_Device->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, 2, &quality)) && quality > 0)
			m_SampleCount = 2;

		D3D11_TEXTURE2D_DESC td{};
		td.Width = w;
		td.Height = h;
		td.MipLevels = 1;
		td.ArraySize = 1;
		td.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		td.SampleDesc.Count = m_SampleCount;
		td.SampleDesc.Quality = 0;
		td.Usage = D3D11_USAGE_DEFAULT;
		td.BindFlags = D3D11_BIND_RENDER_TARGET;
		if (FAILED(m_Device->CreateTexture2D(&td, nullptr, &m_RTTex)))
			return false;
		if (FAILED(m_Device->CreateRenderTargetView(m_RTTex, nullptr, &m_RTV)))
			return false;

		D3D11_TEXTURE2D_DESC rd = td;
		rd.SampleDesc.Count = 1;
		rd.SampleDesc.Quality = 0;
		rd.BindFlags = D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_RENDER_TARGET;
		if (FAILED(m_Device->CreateTexture2D(&rd, nullptr, &m_ResolveTex)))
			return false;
		if (FAILED(m_Device->CreateShaderResourceView(m_ResolveTex, nullptr, &m_SRV)))
			return false;

		D3D11_TEXTURE2D_DESC dd{};
		dd.Width = w;
		dd.Height = h;
		dd.MipLevels = 1;
		dd.ArraySize = 1;
		dd.Format = DXGI_FORMAT_D32_FLOAT;
		dd.SampleDesc.Count = m_SampleCount;
		dd.SampleDesc.Quality = 0;
		dd.Usage = D3D11_USAGE_DEFAULT;
		dd.BindFlags = D3D11_BIND_DEPTH_STENCIL;
		if (FAILED(m_Device->CreateTexture2D(&dd, nullptr, &m_DepthTex)))
			return false;
		return SUCCEEDED(m_Device->CreateDepthStencilView(m_DepthTex, nullptr, &m_DSV));
	}

	bool PreviewRenderer::CreateShaders()
	{
		ID3DBlob* vsBlob = nullptr;
		ID3DBlob* psBlob = nullptr;
		if (!CompileShader(s_VS, "main", "vs_4_0", &vsBlob)) return false;
		if (!CompileShader(s_PS, "main", "ps_4_0", &psBlob)) { vsBlob->Release(); return false; }

		HRESULT hr = m_Device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &m_VS);
		if (SUCCEEDED(hr))
			hr = m_Device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &m_PS);

		D3D11_INPUT_ELEMENT_DESC layout[] = {
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,  0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,    0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		};
		if (SUCCEEDED(hr))
			hr = m_Device->CreateInputLayout(layout, 3, vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), &m_IL);

		vsBlob->Release();
		psBlob->Release();
		if (FAILED(hr)) return false;

		D3D11_BUFFER_DESC cbd{};
		cbd.ByteWidth = 160;
		cbd.Usage = D3D11_USAGE_DYNAMIC;
		cbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		cbd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		return SUCCEEDED(m_Device->CreateBuffer(&cbd, nullptr, &m_CB));
	}

	bool PreviewRenderer::Initialize(ID3D11Device* device, ID3D11DeviceContext* ctx,
		unsigned int rt_width, unsigned int rt_height)
	{
		if (!device || !ctx) return false;
		m_Device = device;
		m_Ctx = ctx;
		m_Width = rt_width;
		m_Height = rt_height;

		if (!CreateRenderTarget(rt_width, rt_height)) return false;
		if (!CreateShaders()) return false;

		D3D11_RASTERIZER_DESC rd{};
		rd.FillMode = D3D11_FILL_SOLID;
		rd.CullMode = D3D11_CULL_NONE;
		rd.DepthClipEnable = TRUE;
		rd.MultisampleEnable = TRUE;
		m_Device->CreateRasterizerState(&rd, &m_RS);

		D3D11_DEPTH_STENCIL_DESC dd{};
		dd.DepthEnable = TRUE;
		dd.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		dd.DepthFunc = D3D11_COMPARISON_LESS;
		m_Device->CreateDepthStencilState(&dd, &m_DSState);

		D3D11_DEPTH_STENCIL_DESC dd2 = dd;
		dd2.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
		m_Device->CreateDepthStencilState(&dd2, &m_DSNoWrite);

		D3D11_BLEND_DESC bld{};
		bld.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
		m_Device->CreateBlendState(&bld, &m_BlendOpaque);

		D3D11_BLEND_DESC abl{};
		abl.RenderTarget[0].BlendEnable = TRUE;
		abl.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
		abl.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		abl.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
		abl.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		abl.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_INV_SRC_ALPHA;
		abl.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
		abl.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
		m_Device->CreateBlendState(&abl, &m_BlendAlpha);

		m_Ready = true;
		return true;
	}

	void PreviewRenderer::BuildR6SkeletonFromParts()
	{
		m_SkelSegCount = 0;

		const float bx0 = m_BodyMin[0], bx1 = m_BodyMax[0];
		const float by0 = m_BodyMin[1], by1 = m_BodyMax[1];
		const float cx = (bx0 + bx1) * 0.5f;
		const float h = (std::max)(0.01f, by1 - by0);
		const float w = (std::max)(0.01f, bx1 - bx0);

		const ModelPartAABB* torso = nullptr;
		const ModelPartAABB* lArm = nullptr;
		const ModelPartAABB* rArm = nullptr;
		const ModelPartAABB* lLeg = nullptr;
		const ModelPartAABB* rLeg = nullptr;

		for (const auto& p : m_BodyParts) {
			if (!p.valid) continue;
			const float pcx = (p.min[0] + p.max[0]) * 0.5f;
			const float pcy = (p.min[1] + p.max[1]) * 0.5f;
			const float psy = p.max[1] - p.min[1];
			const float psx = p.max[0] - p.min[0];

			if (pcy > by0 + h * 0.82f && psy < h * 0.45f)
				continue;
			if (pcy < by0 + h * 0.45f) {
				if (pcx < cx) lLeg = &p; else rLeg = &p;
				continue;
			}
			if (std::fabs(pcx - cx) > w * 0.28f && psx < w * 0.55f) {
				if (pcx < cx) lArm = &p; else rArm = &p;
				continue;
			}
			if (std::fabs(pcx - cx) <= w * 0.35f && psy >= h * 0.25f)
				torso = &p;
		}

		auto add = [&](float ax, float ay, float az, float bx, float by, float bz) {
			if (m_SkelSegCount >= MaxSkelSegs) return;
			m_SkelSeg[m_SkelSegCount][0][0] = ax;
			m_SkelSeg[m_SkelSegCount][0][1] = ay;
			m_SkelSeg[m_SkelSegCount][0][2] = az;
			m_SkelSeg[m_SkelSegCount][1][0] = bx;
			m_SkelSeg[m_SkelSegCount][1][1] = by;
			m_SkelSeg[m_SkelSegCount][1][2] = bz;
			++m_SkelSegCount;
		};

		auto axis = [](const ModelPartAABB& p, float top[3], float bot[3]) {
			const float x = (p.min[0] + p.max[0]) * 0.5f;
			const float z = (p.min[2] + p.max[2]) * 0.5f;
			top[0] = x; top[1] = p.max[1]; top[2] = z;
			bot[0] = x; bot[1] = p.min[1]; bot[2] = z;
		};

		auto lerp3 = [](const float a[3], const float b[3], float t, float o[3]) {
			o[0] = a[0] + (b[0] - a[0]) * t;
			o[1] = a[1] + (b[1] - a[1]) * t;
			o[2] = a[2] + (b[2] - a[2]) * t;
		};

		float shoulder_drop = 0.18f;

		if (!torso) return;

		float torso_top[3], torso_bot[3], shoulder_c[3];
		axis(*torso, torso_top, torso_bot);
		lerp3(torso_top, torso_bot, shoulder_drop, shoulder_c);
		add(shoulder_c[0], shoulder_c[1], shoulder_c[2],
			torso_bot[0], torso_bot[1], torso_bot[2]);

		auto arm_bones = [&](const ModelPartAABB* arm) {
			if (!arm) return;
			const float ax = (arm->min[0] + arm->max[0]) * 0.5f;
			const float az = (arm->min[2] + arm->max[2]) * 0.5f;
			const float joint[3] = { ax, shoulder_c[1], az };
			const float bot[3] = { ax, arm->min[1], az };
			add(shoulder_c[0], shoulder_c[1], shoulder_c[2], joint[0], joint[1], joint[2]);
			add(joint[0], joint[1], joint[2], bot[0], bot[1], bot[2]);
		};
		arm_bones(lArm);
		arm_bones(rArm);

		auto leg_bones = [&](const ModelPartAABB* leg) {
			if (!leg) return;
			float t[3], b[3];
			axis(*leg, t, b);
			add(torso_bot[0], torso_bot[1], torso_bot[2], t[0], t[1], t[2]);
			add(t[0], t[1], t[2], b[0], b[1], b[2]);
		};
		leg_bones(lLeg);
		leg_bones(rLeg);
	}

	bool PreviewRenderer::ApplyLoadedModel(LoadedModel& model)
	{
		std::vector<ModelVertex> combined = model.vertices;
		m_BodyVertCount = (unsigned int)model.vertices.size();
		m_WingVertCount = (unsigned int)model.wing_vertices.size();
		if (!model.wing_vertices.empty())
			combined.insert(combined.end(), model.wing_vertices.begin(), model.wing_vertices.end());

		unsigned int total = 0;
		if (!UploadVerts(m_Device, combined, &m_VB, total)) return false;

		m_ModelScale = model.scale;
		for (int i = 0; i < 3; ++i) {
			m_ModelCenter[i] = model.center[i];
			m_RawMin[i] = model.raw_min[i];
			m_RawMax[i] = model.raw_max[i];
			m_BodyMin[i] = model.body_min[i];
			m_BodyMax[i] = model.body_max[i];
			m_BoxMin[i] = model.box_min[i];
			m_BoxMax[i] = model.box_max[i];
		}

		m_FrameCenter[0] = (m_BoxMin[0] + m_BoxMax[0]) * 0.5f;
		m_FrameCenter[1] = (m_BoxMin[1] + m_BoxMax[1]) * 0.5f;
		m_FrameCenter[2] = (m_BoxMin[2] + m_BoxMax[2]) * 0.5f;
		{
			const float ext[3] = {
				m_BoxMax[0] - m_BoxMin[0],
				m_BoxMax[1] - m_BoxMin[1],
				m_BoxMax[2] - m_BoxMin[2]
			};
			const float maxExt = (std::max)({ ext[0], ext[1], ext[2] });
			m_FrameScale = maxExt > 0.0f ? (1.22f / maxExt) : 1.0f;
		}

		m_UniquePos = std::move(model.positions);
		m_BodyPos = std::move(model.body_positions);
		m_BoxPos = std::move(model.box_positions);
		m_BodyParts = std::move(model.body_parts);
		m_BoxParts = std::move(model.box_parts);

		BuildR6SkeletonFromParts();

		m_SceneDirty = true;
		m_CachedBoundsValid = false;
		return true;
	}

	bool PreviewRenderer::LoadModel(const std::string& obj_path)
	{
		LoadedModel model;
		if (!LoadOBJ(obj_path, model)) return false;
		return ApplyLoadedModel(model);
	}

	bool PreviewRenderer::LoadModelFromMemory(const char* obj_src, std::size_t obj_len)
	{
		LoadedModel model;
		if (!LoadOBJFromMemory(obj_src, obj_len, model)) return false;
		return ApplyLoadedModel(model);
	}

	static void AppendBoxOBJ(std::string& out, const char* name,
		float cx, float cy, float cz, float sx, float sy, float sz, const float r[9])
	{
		const float hx = sx * 0.5f, hy = sy * 0.5f, hz = sz * 0.5f;
		const float local[8][3] = {
			{ -hx, -hy, -hz }, { hx, -hy, -hz }, { hx, hy, -hz }, { -hx, hy, -hz },
			{ -hx, -hy, hz }, { hx, -hy, hz }, { hx, hy, hz }, { -hx, hy, hz }
		};
		float corner[8][3];
		for (int i = 0; i < 8; ++i) {
			corner[i][0] = r[0] * local[i][0] + r[1] * local[i][1] + r[2] * local[i][2] + cx;
			corner[i][1] = r[3] * local[i][0] + r[4] * local[i][1] + r[5] * local[i][2] + cy;
			corner[i][2] = r[6] * local[i][0] + r[7] * local[i][1] + r[8] * local[i][2] + cz;
		}
		static const int faces[6][4] = {
			{ 0, 1, 2, 3 }, { 4, 5, 6, 7 }, { 1, 5, 6, 2 },
			{ 0, 4, 7, 3 }, { 3, 2, 6, 7 }, { 0, 1, 5, 4 }
		};
		static const float faceUV[4][2] = {
			{ 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f }
		};

		out += "g ";
		out += name;
		out += "\n";
		for (int f = 0; f < 6; ++f) {
			const int i0 = faces[f][0], i1 = faces[f][1], i2 = faces[f][2];
			float ex1 = corner[i1][0] - corner[i0][0], ey1 = corner[i1][1] - corner[i0][1], ez1 = corner[i1][2] - corner[i0][2];
			float ex2 = corner[i2][0] - corner[i0][0], ey2 = corner[i2][1] - corner[i0][1], ez2 = corner[i2][2] - corner[i0][2];
			float nx = ey1 * ez2 - ez1 * ey2;
			float ny = ez1 * ex2 - ex1 * ez2;
			float nz = ex1 * ey2 - ey1 * ex2;
			float nl = std::sqrt(nx * nx + ny * ny + nz * nz);
			if (nl > 1e-6f) { nx /= nl; ny /= nl; nz /= nl; }
			for (int k = 0; k < 4; ++k) {
				const int ci = faces[f][k];
				char buf[128];
				snprintf(buf, sizeof(buf), "v %.4f %.4f %.4f\nvn %.4f %.4f %.4f\nvt %.4f %.4f\n",
					corner[ci][0], corner[ci][1], corner[ci][2],
					nx, ny, nz,
					faceUV[k][0], faceUV[k][1]);
				out += buf;
			}
		}
	}

	bool PreviewRenderer::LoadModelFromBones(const std::vector<BoneBox>& boxes)	{
		if (boxes.empty()) return false;
		std::string obj;
		obj.reserve(boxes.size() * 512);

		int vbase = 0;
		for (const auto& b : boxes) {
			if (b.sx < 0.001f && b.sy < 0.001f && b.sz < 0.001f)
				continue;
			AppendBoxOBJ(obj, b.name.c_str(), b.cx, b.cy, b.cz, b.sx, b.sy, b.sz, b.r);

			const int count = 24;
			static const int faceIdx[12][3] = {
				{ 0, 1, 2 }, { 0, 2, 3 }, { 4, 5, 6 }, { 4, 6, 7 },
				{ 8, 9, 10 }, { 8, 10, 11 }, { 12, 13, 14 }, { 12, 14, 15 },
				{ 16, 17, 18 }, { 16, 18, 19 }, { 20, 21, 22 }, { 20, 22, 23 }
			};
			for (int t = 0; t < 12; ++t) {
				char buf[96];
				snprintf(buf, sizeof(buf), "f %d/%d/%d %d/%d/%d %d/%d/%d\n",
					vbase + faceIdx[t][0] + 1, vbase + faceIdx[t][0] + 1, vbase + faceIdx[t][0] + 1,
					vbase + faceIdx[t][1] + 1, vbase + faceIdx[t][1] + 1, vbase + faceIdx[t][1] + 1,
					vbase + faceIdx[t][2] + 1, vbase + faceIdx[t][2] + 1, vbase + faceIdx[t][2] + 1);
				obj += buf;
			}
			vbase += count;
		}

		if (obj.empty()) return false;
		LoadedModel model;
		if (!LoadOBJFromMemory(obj.c_str(), obj.size(), model)) return false;
		return ApplyLoadedModel(model);
	}

	bool PreviewRenderer::LoadTexture(const std::string& tex_path)
	{
		int w = 0, h = 0, n = 0;
		stbi_uc* data = stbi_load(tex_path.c_str(), &w, &h, &n, 4);
		if (!data) return false;
		const bool ok = UploadPng(m_Device, data, w, h, &m_TexRes, &m_TexSRV, &m_Sampler);
		stbi_image_free(data);
		if (ok) m_SceneDirty = true;
		return ok;
	}

	bool PreviewRenderer::LoadTextureFromMemory(const unsigned char* png, std::size_t png_len)
	{
		if (!png || png_len == 0) return false;
		int w = 0, h = 0, n = 0;
		stbi_uc* data = stbi_load_from_memory(png, (int)png_len, &w, &h, &n, 4);
		if (!data) return false;
		const bool ok = UploadPng(m_Device, data, w, h, &m_TexRes, &m_TexSRV, &m_Sampler);
		stbi_image_free(data);
		if (ok) m_SceneDirty = true;
		return ok;
	}

	float PreviewRenderer::WingAlpha() const
	{
		float fade_in = 1.15f;
		float hold = 1.60f;
		float fade_out = 1.15f;
		float pause = 0.90f;
		float period = fade_in + hold + fade_out + pause;

		float t = std::fmod(m_WingAnimTime, period);
		if (t < 0.f)
			t += period;

		auto smooth = [](float x)
		{
			if (x < 0.f) x = 0.f;
			if (x > 1.f) x = 1.f;
			return x * x * (3.f - 2.f * x);
		};

		if (t < fade_in)
			return smooth(t / fade_in);
		t -= fade_in;

		if (t < hold)
			return 1.f;
		t -= hold;

		if (t < fade_out)
			return 1.f - smooth(t / fade_out);

		(void)pause;
		return 0.f;
	}

	void PreviewRenderer::Update(float dt)
	{
		if (!m_Ready || !m_VB)
			return;

		if (m_SpinPauseRemaining > 0.0f)
			m_SpinPauseRemaining -= dt;

		if (m_AutoSpin && m_SpinPauseRemaining <= 0.0f)
		{
			m_SpinAccum += dt;
			if (m_SpinAccum >= 1.0f / 20.0f)
			{
				m_Angle += m_SpinAccum * 0.35f;
				m_SpinAccum = 0.0f;
				m_SceneDirty = true;
			}
		}
		else
		{
			m_SpinAccum = 0.0f;
		}

		if (m_WingVertCount > 0)
		{
			m_WingAnimTime += dt;
			m_SceneDirty = true;
		}

		if (!m_SceneDirty)
			return;
		m_SceneDirty = false;

		float totalYaw = -(m_Angle + m_ManualYaw);
		float totalPitch = -m_ManualPitch;
		float camDist = 2.35f / m_Zoom;

		Mat4 world, t, s, rx, ry, tmp;
		MatTranslation(-m_FrameCenter[0], -m_FrameCenter[1], -m_FrameCenter[2], t);
		MatScaling(m_FrameScale, m_FrameScale, m_FrameScale, s);
		MatRotationX(totalPitch, rx);
		MatRotationY(totalYaw, ry);
		MatMultiply(t, s, tmp);
		MatMultiply(tmp, ry, world);
		MatMultiply(world, rx, world);

		float aspect = (float)m_Width / (float)m_Height;
		Vec3 eye = V3(0.0f, 0.02f, -camDist);
		Vec3 at = V3(0.0f, 0.02f, 0.0f);
		Vec3 up = V3(0.0f, 1.0f, 0.0f);
		Mat4 view, proj, cpuMVP;
		MatLookAtLH(eye, at, up, view);
		MatPerspectiveFovLH(0.6981317f, aspect, 0.01f, 100.0f, proj);
		MatMultiply(world, view, tmp);
		MatMultiply(tmp, proj, cpuMVP);

		std::memcpy(m_LastMVP, cpuMVP, sizeof(cpuMVP));
		m_LastMVPValid = true;
		m_CachedBoundsValid = false;

		auto upload_cb = [&](float opacity, float solid)
		{
			Mat4 gpuMVP, gpuWorld;
			MatTranspose(cpuMVP, gpuMVP);
			MatTranspose(world, gpuWorld);
			D3D11_MAPPED_SUBRESOURCE ms{};
			if (SUCCEEDED(m_Ctx->Map(m_CB, 0, D3D11_MAP_WRITE_DISCARD, 0, &ms)))
			{
				float* dst = (float*)ms.pData;
				std::memcpy(dst, gpuMVP, 64);
				std::memcpy(dst + 16, gpuWorld, 64);
				dst[32] = opacity;
				dst[33] = 0.0f;
				dst[34] = 0.0f;
				dst[35] = solid;
				dst[36] = m_Tint[0];
				dst[37] = m_Tint[1];
				dst[38] = m_Tint[2];
				dst[39] = 1.0f;
				m_Ctx->Unmap(m_CB, 0);
			}
		};

		ID3D11RenderTargetView* prevRTV = nullptr;
		ID3D11DepthStencilView* prevDSV = nullptr;
		ID3D11RasterizerState* prevRS = nullptr;
		ID3D11DepthStencilState* prevDS = nullptr;
		UINT prevDSRef = 0;
		float prevBF[4]{}; UINT prevSM = 0;
		ID3D11BlendState* prevBS = nullptr;
		UINT numVP = 1; D3D11_VIEWPORT prevVP{};

		m_Ctx->OMGetRenderTargets(1, &prevRTV, &prevDSV);
		m_Ctx->RSGetState(&prevRS);
		m_Ctx->OMGetDepthStencilState(&prevDS, &prevDSRef);
		m_Ctx->OMGetBlendState(&prevBS, prevBF, &prevSM);
		m_Ctx->RSGetViewports(&numVP, &prevVP);

		m_Ctx->OMSetRenderTargets(1, &m_RTV, m_DSV);
		m_Ctx->ClearRenderTargetView(m_RTV, m_ClearColor);
		m_Ctx->ClearDepthStencilView(m_DSV, D3D11_CLEAR_DEPTH, 1.0f, 0);

		D3D11_VIEWPORT vp{};
		vp.Width = (float)m_Width; vp.Height = (float)m_Height; vp.MaxDepth = 1.0f;
		m_Ctx->RSSetViewports(1, &vp);
		m_Ctx->RSSetState(m_RS);

		UINT stride = sizeof(ModelVertex), offset = 0;
		m_Ctx->IASetInputLayout(m_IL);
		m_Ctx->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		m_Ctx->IASetVertexBuffers(0, 1, &m_VB, &stride, &offset);
		m_Ctx->VSSetShader(m_VS, nullptr, 0);
		m_Ctx->VSSetConstantBuffers(0, 1, &m_CB);
		m_Ctx->PSSetShader(m_PS, nullptr, 0);
		m_Ctx->PSSetConstantBuffers(0, 1, &m_CB);
		if (m_TexSRV) m_Ctx->PSSetShaderResources(0, 1, &m_TexSRV);
		if (m_Sampler) m_Ctx->PSSetSamplers(0, 1, &m_Sampler);

		float bf[4]{};
		upload_cb(1.0f, m_SolidPass ? 1.0f : 0.0f);
		m_Ctx->OMSetDepthStencilState(m_DSState, 0);
		m_Ctx->OMSetBlendState(m_BlendOpaque, bf, 0xFFFFFFFF);
		if (m_BodyVertCount > 0)
			m_Ctx->Draw(m_BodyVertCount, 0);

		float wingA = WingAlpha();
		if (m_WingVertCount > 0 && wingA > 0.001f)
		{
			upload_cb(wingA, 0.0f);
			m_Ctx->OMSetDepthStencilState(m_DSNoWrite, 0);
			m_Ctx->OMSetBlendState(m_BlendAlpha, bf, 0xFFFFFFFF);
			m_Ctx->Draw(m_WingVertCount, m_BodyVertCount);
		}

		if (m_SampleCount > 1 && m_ResolveTex)
			m_Ctx->ResolveSubresource(m_ResolveTex, 0, m_RTTex, 0, DXGI_FORMAT_R8G8B8A8_UNORM);
		else if (m_ResolveTex)
			m_Ctx->CopyResource(m_ResolveTex, m_RTTex);

		m_Ctx->OMSetRenderTargets(1, &prevRTV, prevDSV);
		m_Ctx->RSSetState(prevRS);
		m_Ctx->OMSetDepthStencilState(prevDS, prevDSRef);
		m_Ctx->OMSetBlendState(prevBS, prevBF, prevSM);
		m_Ctx->RSSetViewports(1, &prevVP);
		if (prevRTV) prevRTV->Release();
		if (prevDSV) prevDSV->Release();
		if (prevRS) prevRS->Release();
		if (prevDS) prevDS->Release();
		if (prevBS) prevBS->Release();
	}

	void PreviewRenderer::AddRotationDelta(float dyaw, float dpitch)
	{
		m_ManualYaw += dyaw;
		m_ManualPitch += dpitch;
		if (m_ManualPitch > 1.2f) m_ManualPitch = 1.2f;
		if (m_ManualPitch < -1.2f) m_ManualPitch = -1.2f;
		m_SceneDirty = true;
	}

	void PreviewRenderer::AddZoom(float delta)
	{
		m_Zoom += delta;
		if (m_Zoom < 0.45f) m_Zoom = 0.45f;
		if (m_Zoom > 2.8f) m_Zoom = 2.8f;
		m_SceneDirty = true;
	}

	void* PreviewRenderer::GetTextureID() const { return (void*)m_SRV; }

	static bool ProjectMVP(const float* M, float x, float y, float z, float& u, float& v)
	{
		const float clip_x = x * M[0] + y * M[4] + z * M[8] + M[12];
		const float clip_y = x * M[1] + y * M[5] + z * M[9] + M[13];
		const float clip_w = x * M[3] + y * M[7] + z * M[11] + M[15];
		if (clip_w <= 1e-5f) return false;
		const float inv = 1.0f / clip_w;
		u = clip_x * inv * 0.5f + 0.5f;
		v = -clip_y * inv * 0.5f + 0.5f;
		return true;
	}

	bool PreviewRenderer::GetProjectedUVBounds(float& u0, float& v0, float& u1, float& v1) const
	{
		if (!m_LastMVPValid) return false;
		if (m_CachedBoundsValid) {
			u0 = m_CachedU0; v0 = m_CachedV0; u1 = m_CachedU1; v1 = m_CachedV1;
			return true;
		}

		float minU = 1e9f, minV = 1e9f, maxU = -1e9f, maxV = -1e9f;
		bool any = false;
		const float* M = m_LastMVP;

		auto expand = [&](float x, float y, float z) {
			float u, v;
			if (!ProjectMVP(M, x, y, z, u, v)) return;
			minU = (std::min)(minU, u); maxU = (std::max)(maxU, u);
			minV = (std::min)(minV, v); maxV = (std::max)(maxV, v);
			any = true;
		};

		for (const auto& p : m_BodyParts) {
			if (!p.valid) continue;
			for (int i = 0; i < 8; ++i) {
				expand((i & 1) ? p.max[0] : p.min[0],
					(i & 2) ? p.max[1] : p.min[1],
					(i & 4) ? p.max[2] : p.min[2]);
			}
		}

		const std::vector<float>& pos =
			!m_BoxPos.empty() ? m_BoxPos :
			(!m_BodyPos.empty() ? m_BodyPos : m_UniquePos);
		for (size_t i = 0; i + 2 < pos.size(); i += 3)
			expand(pos[i], pos[i + 1], pos[i + 2]);

		if (!any) return false;

		m_CachedU0 = u0 = minU; m_CachedV0 = v0 = minV;
		m_CachedU1 = u1 = maxU; m_CachedV1 = v1 = maxV;
		m_CachedBoundsValid = true;
		return true;
	}

	bool PreviewRenderer::GetProjectedPartBoxes(
		std::vector<std::array<std::pair<float, float>, 8>>& out) const
	{
		out.clear();
		if (!m_LastMVPValid || m_BodyParts.empty()) return false;

		const float* M = m_LastMVP;
		out.reserve(m_BodyParts.size());
		for (const auto& p : m_BodyParts) {
			if (!p.valid) continue;
			std::array<std::pair<float, float>, 8> box{};
			bool ok = true;
			for (int i = 0; i < 8; ++i) {
				const float x = (i & 4) ? p.max[0] : p.min[0];
				const float y = (i & 2) ? p.max[1] : p.min[1];
				const float z = (i & 1) ? p.max[2] : p.min[2];
				float u, v;
				if (!ProjectMVP(M, x, y, z, u, v)) { ok = false; break; }
				box[i] = { u, v };
			}
			if (ok) out.push_back(box);
		}
		return !out.empty();
	}

	bool PreviewRenderer::GetProjectedR6Skeleton(std::vector<float>& out_uv_segs) const
	{
		out_uv_segs.clear();
		if (!m_LastMVPValid || m_SkelSegCount <= 0) return false;
		out_uv_segs.reserve((size_t)m_SkelSegCount * 4);
		for (int i = 0; i < m_SkelSegCount; ++i) {
			float u0, v0, u1, v1;
			if (!ProjectMVP(m_LastMVP,
				m_SkelSeg[i][0][0], m_SkelSeg[i][0][1], m_SkelSeg[i][0][2], u0, v0))
				continue;
			if (!ProjectMVP(m_LastMVP,
				m_SkelSeg[i][1][0], m_SkelSeg[i][1][1], m_SkelSeg[i][1][2], u1, v1))
				continue;
			out_uv_segs.push_back(u0);
			out_uv_segs.push_back(v0);
			out_uv_segs.push_back(u1);
			out_uv_segs.push_back(v1);
		}
		return out_uv_segs.size() >= 4;
	}

	void PreviewRenderer::Shutdown()
	{
		auto rel = [](auto*& p) { if (p) { p->Release(); p = nullptr; } };
		rel(m_VB); rel(m_CB); rel(m_IL); rel(m_VS); rel(m_PS);
		rel(m_TexSRV); rel(m_TexRes); rel(m_Sampler);
		rel(m_RS); rel(m_DSState); rel(m_DSNoWrite);
		rel(m_BlendOpaque); rel(m_BlendAlpha);
		rel(m_SRV); rel(m_RTV); rel(m_RTTex); rel(m_ResolveTex); rel(m_DSV); rel(m_DepthTex);
		m_BodyVertCount = 0;
		m_WingVertCount = 0;
		m_WingAnimTime = 0.0f;
		m_Ready = false;
		m_LastMVPValid = false;
	}
}
