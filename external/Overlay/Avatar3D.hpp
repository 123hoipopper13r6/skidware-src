#pragma once
#include <string>
#include <vector>
#include <d3d11.h>
#include <d3dcompiler.h>
#include "../Includes.hpp"

struct ObjVertex {
    float x, y, z;
    float nx, ny, nz;
    float u, v;
};

struct ObjMesh {
    std::vector<ObjVertex> vertices;
    std::vector<uint32_t> indices;
    ID3D11ShaderResourceView* texture = nullptr;
    int textureIndex = -1;
};

struct AvatarTexture {
    std::string hash;
    ID3D11ShaderResourceView* view = nullptr;
};

class Avatar3DRenderer {
public:
    bool Load(int64_t userId);
    void Render(float dt = 0.0f);
    ID3D11ShaderResourceView* GetOutput() { return m_outputView; }
    bool IsLoaded() { return m_loaded; }
    bool IsLoading() { return m_loading; }
    const std::string& GetError() { return m_error; }
    void Release();
    void Unload() { if (!m_loading) Release(); }
    Avatar3DRenderer() { m_outputView = nullptr; m_loaded = false; m_loading = false; }

    void SetTint(float r, float g, float b, float a) {
        m_tint[0] = r; m_tint[1] = g; m_tint[2] = b; m_tint[3] = a;
    }
    void SetAutoSpin(bool on) { m_autoSpin = on; }
    bool IsAutoSpinning() const { return m_autoSpin; }
    void AddYaw(float dy) { m_manualYaw += dy; }
    void SetZoom(float z) { m_zoom = z < 0.45f ? 0.45f : (z > 2.8f ? 2.8f : z); }
    void AddZoom(float dz) {
        m_zoom += dz;
        if (m_zoom < 0.45f) m_zoom = 0.45f;
        if (m_zoom > 2.8f) m_zoom = 2.8f;
    }
    bool GetProjectedSkeleton(std::vector<float>& out_uv_segs) const;

private:
    bool m_loaded = false;
    bool m_loading = false;
    std::string m_error;
    std::vector<ObjMesh> m_meshes;
    std::vector<AvatarTexture> m_textures;
    ID3D11VertexShader* m_vs = nullptr;
    ID3D11PixelShader* m_ps = nullptr;
    ID3D11InputLayout* m_layout = nullptr;
    ID3D11Buffer* m_cb = nullptr;
    ID3D11SamplerState* m_sampler = nullptr;
    ID3D11Texture2D* m_outputTex = nullptr;
    ID3D11RenderTargetView* m_outputRTV = nullptr;
    ID3D11ShaderResourceView* m_outputView = nullptr;
    ID3D11DepthStencilView* m_dsv = nullptr;
    int m_width = 254, m_height = 356;

    struct PartAABB {
        float min[3] = {};
        float max[3] = {};
        bool valid = false;
    };
    std::vector<PartAABB> m_parts;

    float m_tint[4] = { 1.0f, 1.0f, 1.0f, 0.0f };
    bool m_autoSpin = false;
    float m_angle = 0.0f;
    float m_manualYaw = 0.0f;
    float m_zoom = 1.0f;
    float m_lastMVP[16] = {};
    bool m_lastMVPValid = false;

    void BuildSkeletonFromParts();
    static constexpr int MaxSkelSegs = 12;
    float m_skelSeg[MaxSkelSegs][2][3] = {};
    int m_skelSegCount = 0;

    bool CreatePipeline();
    bool ParseObj(const std::string& objData, const std::string& mtlData);
    std::string DownloadString(const std::string& url);
    std::vector<uint8_t> DownloadBinary(const std::string& url);
};

inline Avatar3DRenderer g_avatar3D;
