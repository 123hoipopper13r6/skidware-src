#pragma once
#include "PreviewModel.hpp"
#include <d3d11.h>
#include <d3dcompiler.h>
#include <array>
#include <string>
#include <vector>
#include <utility>

namespace Hacks::Preview
{
	struct BoneBox {
		std::string name;
		float cx, cy, cz;
		float sx, sy, sz;
		float r[9];
	};

	class PreviewRenderer {
	public:
		PreviewRenderer() = default;
		~PreviewRenderer() { Shutdown(); }

		bool Initialize(ID3D11Device* device, ID3D11DeviceContext* ctx,
			unsigned int rt_width = 600, unsigned int rt_height = 900);

		bool LoadModel(const std::string& obj_path);
		bool LoadModelFromMemory(const char* obj_src, std::size_t obj_len);
		bool LoadModelFromBones(const std::vector<BoneBox>& boxes);
		bool LoadTexture(const std::string& tex_path);
		bool LoadTextureFromMemory(const unsigned char* png, std::size_t png_len);

		void Update(float dt_seconds);
		void AddRotationDelta(float dyaw, float dpitch);
		void AddZoom(float delta);
		void SetAutoSpin(bool on) {
			m_AutoSpin = on;
			if (on) m_SpinPauseRemaining = 0.0f;
		}
		bool IsAutoSpinning() const { return m_AutoSpin; }
		void NotifyManualInput() { m_SpinPauseRemaining = 2.0f; }

		void SetClearColor(float r, float g, float b) {
			m_ClearColor[0] = r; m_ClearColor[1] = g; m_ClearColor[2] = b;
			m_SceneDirty = true;
		}
		void SetTint(float r, float g, float b) {
			m_Tint[0] = r; m_Tint[1] = g; m_Tint[2] = b;
			m_SceneDirty = true;
		}
		void SetSolid(bool on) {
			m_SolidPass = on;
			m_SceneDirty = true;
		}

		void* GetTextureID() const;
		bool GetProjectedUVBounds(float& u0, float& v0, float& u1, float& v1) const;
		bool GetProjectedPartBoxes(std::vector<std::array<std::pair<float, float>, 8>>& out) const;
		bool GetProjectedR6Skeleton(std::vector<float>& out_uv_segs) const;

		bool IsReady() const { return m_Ready && m_VB != nullptr && m_BodyVertCount > 0; }
		bool IsInitialized() const { return m_Ready; }
		void Shutdown();

	private:
		bool CreateRenderTarget(unsigned int w, unsigned int h);
		bool CreateShaders();
		bool ApplyLoadedModel(LoadedModel& model);
		void BuildR6SkeletonFromParts();
		float WingAlpha() const;

		ID3D11Device* m_Device = nullptr;
		ID3D11DeviceContext* m_Ctx = nullptr;

		ID3D11Texture2D* m_RTTex = nullptr;
		ID3D11RenderTargetView* m_RTV = nullptr;
		ID3D11Texture2D* m_ResolveTex = nullptr;
		ID3D11ShaderResourceView* m_SRV = nullptr;
		ID3D11Texture2D* m_DepthTex = nullptr;
		ID3D11DepthStencilView* m_DSV = nullptr;
		unsigned int m_Width = 0;
		unsigned int m_Height = 0;
		unsigned int m_SampleCount = 1;

		ID3D11VertexShader* m_VS = nullptr;
		ID3D11PixelShader* m_PS = nullptr;
		ID3D11InputLayout* m_IL = nullptr;
		ID3D11Buffer* m_CB = nullptr;
		ID3D11Buffer* m_VB = nullptr;
		unsigned int m_BodyVertCount = 0;
		unsigned int m_WingVertCount = 0;

		float m_ModelScale = 1.0f;
		float m_ModelCenter[3] = {};
		float m_FrameScale = 1.0f;
		float m_FrameCenter[3] = {};
		float m_RawMin[3] = {};
		float m_RawMax[3] = {};
		float m_BodyMin[3] = {};
		float m_BodyMax[3] = {};
		float m_BoxMin[3] = {};
		float m_BoxMax[3] = {};
		std::vector<float> m_UniquePos;
		std::vector<float> m_BodyPos;
		std::vector<float> m_BoxPos;
		std::vector<ModelPartAABB> m_BodyParts;
		std::vector<ModelPartAABB> m_BoxParts;

		static constexpr int MaxSkelSegs = 12;
		float m_SkelSeg[MaxSkelSegs][2][3] = {};
		int m_SkelSegCount = 0;

		ID3D11Texture2D* m_TexRes = nullptr;
		ID3D11ShaderResourceView* m_TexSRV = nullptr;
		ID3D11SamplerState* m_Sampler = nullptr;

		ID3D11RasterizerState* m_RS = nullptr;
		ID3D11DepthStencilState* m_DSState = nullptr;
		ID3D11DepthStencilState* m_DSNoWrite = nullptr;
		ID3D11BlendState* m_BlendOpaque = nullptr;
		ID3D11BlendState* m_BlendAlpha = nullptr;

		float m_Angle = 0.0f;
		float m_ManualYaw = 0.0f;
		float m_ManualPitch = 0.0f;
		float m_Zoom = 0.936f;
		float m_ClearColor[4] = { 0.082f, 0.086f, 0.098f, 1.0f };
		float m_Tint[3] = { 1.0f, 1.0f, 1.0f };
		bool m_SolidPass = false;
		bool m_AutoSpin = false;
		float m_SpinPauseRemaining = 0.0f;
		float m_SpinAccum = 0.0f;
		bool m_SceneDirty = true;
		float m_WingAnimTime = 0.0f;

		float m_LastMVP[16] = {};
		bool m_LastMVPValid = false;

		mutable float m_CachedU0 = 0, m_CachedV0 = 0, m_CachedU1 = 1, m_CachedV1 = 1;
		mutable bool m_CachedBoundsValid = false;

		bool m_Ready = false;
	};
}
