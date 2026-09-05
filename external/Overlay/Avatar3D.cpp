#include "Avatar3D.hpp"
#include "../Includes.hpp"
#include "../Libs/stb_image.h"
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <WinHttp.h>
#pragma comment(lib, "winhttp.lib")

using json = nlohmann::json;

static ID3D11Device* D() { return Globals::g_pd3dDevice; }
static ID3D11DeviceContext* C() { return Globals::g_pd3dDeviceContext; }

static std::string HttpGetUA(const std::wstring& host, const std::wstring& path, bool secure = true) {
    std::string result;
    HINTERNET hSession = WinHttpOpen(L"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, NULL, NULL, 0);
    if (!hSession) return result;
    WinHttpSetTimeouts(hSession, 5000, 5000, 15000, 15000);
    HINTERNET hConnect = WinHttpConnect(hSession, host.c_str(), secure ? INTERNET_DEFAULT_HTTPS_PORT : INTERNET_DEFAULT_HTTP_PORT, 0);
    if (hConnect) {
        HINTERNET hRequest = WinHttpOpenRequest(hConnect, L"GET", path.c_str(), NULL, NULL, NULL, secure ? WINHTTP_FLAG_SECURE : 0);
        if (hRequest) {
            WinHttpAddRequestHeaders(hRequest, L"Accept: application/json\r\n", -1, WINHTTP_ADDREQ_FLAG_ADD);
            WinHttpAddRequestHeaders(hRequest, L"Origin: https://www.roblox.com\r\n", -1, WINHTTP_ADDREQ_FLAG_ADD);
            WinHttpAddRequestHeaders(hRequest, L"Referer: https://www.roblox.com/\r\n", -1, WINHTTP_ADDREQ_FLAG_ADD);
            if (WinHttpSendRequest(hRequest, NULL, 0, NULL, 0, 0, 0)) {
                if (WinHttpReceiveResponse(hRequest, NULL)) {
                    DWORD size = 0;
                    while (WinHttpQueryDataAvailable(hRequest, &size) && size > 0) {
                        std::vector<char> buf(size);
                        DWORD read = 0;
                        if (WinHttpReadData(hRequest, buf.data(), size, &read))
                            result.append(buf.data(), read);
                    }
                }
            }
            WinHttpCloseHandle(hRequest);
        }
        WinHttpCloseHandle(hConnect);
    }
    WinHttpCloseHandle(hSession);
    return result;
}

static std::vector<uint8_t> HttpGetBinaryUA(const std::wstring& host, const std::wstring& path, bool secure = true) {
    std::vector<uint8_t> result;
    HINTERNET hSession = WinHttpOpen(L"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, NULL, NULL, 0);
    if (!hSession) return result;
    WinHttpSetTimeouts(hSession, 5000, 5000, 15000, 30000);
    HINTERNET hConnect = WinHttpConnect(hSession, host.c_str(), secure ? INTERNET_DEFAULT_HTTPS_PORT : INTERNET_DEFAULT_HTTP_PORT, 0);
    if (hConnect) {
        HINTERNET hRequest = WinHttpOpenRequest(hConnect, L"GET", path.c_str(), NULL, NULL, NULL, secure ? WINHTTP_FLAG_SECURE : 0);
        if (hRequest) {
            WinHttpAddRequestHeaders(hRequest, L"Origin: https://www.roblox.com\r\n", -1, WINHTTP_ADDREQ_FLAG_ADD);
            WinHttpAddRequestHeaders(hRequest, L"Referer: https://www.roblox.com/\r\n", -1, WINHTTP_ADDREQ_FLAG_ADD);
            if (WinHttpSendRequest(hRequest, NULL, 0, NULL, 0, 0, 0)) {
                if (WinHttpReceiveResponse(hRequest, NULL)) {
                    DWORD size = 0;
                    while (WinHttpQueryDataAvailable(hRequest, &size) && size > 0) {
                        std::vector<uint8_t> buf(size);
                        DWORD read = 0;
                        if (WinHttpReadData(hRequest, buf.data(), size, &read))
                            result.insert(result.end(), buf.data(), buf.data() + read);
                    }
                }
            }
            WinHttpCloseHandle(hRequest);
        }
        WinHttpCloseHandle(hConnect);
    }
    WinHttpCloseHandle(hSession);
    return result;
}

std::string Avatar3DRenderer::DownloadString(const std::string& url) {
    size_t pos = url.find("://");
    if (pos == std::string::npos) return {};
    std::string remainder = url.substr(pos + 3);
    size_t pathPos = remainder.find('/');
    if (pathPos == std::string::npos) return {};
    std::string host = remainder.substr(0, pathPos);
    std::string path = remainder.substr(pathPos);
    bool secure = url.find("https:") != std::string::npos;
    return HttpGetUA(std::wstring(host.begin(), host.end()), std::wstring(path.begin(), path.end()), secure);
}

std::vector<uint8_t> Avatar3DRenderer::DownloadBinary(const std::string& url) {
    size_t pos = url.find("://");
    if (pos == std::string::npos) return {};
    std::string remainder = url.substr(pos + 3);
    size_t pathPos = remainder.find('/');
    if (pathPos == std::string::npos) return {};
    std::string host = remainder.substr(0, pathPos);
    std::string path = remainder.substr(pathPos);
    bool secure = url.find("https:") != std::string::npos;
    return HttpGetBinaryUA(std::wstring(host.begin(), host.end()), std::wstring(path.begin(), path.end()), secure);
}

static ID3D11ShaderResourceView* CreateTextureFromData(const std::vector<uint8_t>& data) {
    int w, h, channels;
    stbi_uc* pixels = stbi_load_from_memory(data.data(), (int)data.size(), &w, &h, &channels, 4);
    if (!pixels) return nullptr;

    D3D11_TEXTURE2D_DESC td = {};
    td.Width = w;
    td.Height = h;
    td.MipLevels = 1;
    td.ArraySize = 1;
    td.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    td.SampleDesc.Count = 1;
    td.Usage = D3D11_USAGE_IMMUTABLE;
    td.BindFlags = D3D11_BIND_SHADER_RESOURCE;

    D3D11_SUBRESOURCE_DATA sd = {};
    sd.pSysMem = pixels;
    sd.SysMemPitch = w * 4;

    ID3D11Texture2D* tex = nullptr;
    ID3D11ShaderResourceView* srv = nullptr;
    if (SUCCEEDED(D()->CreateTexture2D(&td, &sd, &tex)) && tex) {
        D3D11_SHADER_RESOURCE_VIEW_DESC srvd = {};
        srvd.Format = td.Format;
        srvd.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
        srvd.Texture2D.MipLevels = 1;
        D()->CreateShaderResourceView(tex, &srvd, &srv);
        tex->Release();
    }
    stbi_image_free(pixels);
    return srv;
}

bool Avatar3DRenderer::CreatePipeline() {
    // Vertex shader
    const char* vsCode = R"(
        cbuffer CB : register(b0) {
            float4x4 worldViewProj;
            float4x4 world;
            float4 ambient;
            float4 lightDir;
        };
        struct VSIn {
            float3 pos : POSITION0;
            float3 normal : NORMAL0;
            float2 uv : TEXCOORD0;
        };
        struct VSOut {
            float4 pos : SV_POSITION;
            float2 uv : TEXCOORD0;
            float3 normalW : NORMAL0;
            float3 posW : POSITION0;
        };
        VSOut main(VSIn input) {
            VSOut o;
            o.pos = mul(float4(input.pos, 1.0), worldViewProj);
            o.uv = input.uv;
            o.normalW = normalize(mul(float4(input.normal, 0.0), world).xyz);
            o.posW = mul(float4(input.pos, 1.0), world).xyz;
            return o;
        }
    )";
    ID3DBlob* vsBlob = nullptr, *errBlob = nullptr;
    if (FAILED(D3DCompile(vsCode, strlen(vsCode), nullptr, nullptr, nullptr, "main", "vs_4_0", 0, 0, &vsBlob, &errBlob))) {
        if (errBlob) { OutputDebugStringA((char*)errBlob->GetBufferPointer()); errBlob->Release(); }
        return false;
    }
    if (FAILED(D()->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &m_vs))) {
        vsBlob->Release(); return false;
    }
    D3D11_INPUT_ELEMENT_DESC layout[] = {
        {"POSITION0",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0},
        {"NORMAL0",0,DXGI_FORMAT_R32G32B32_FLOAT,0,12,D3D11_INPUT_PER_VERTEX_DATA,0},
        {"TEXCOORD0",0,DXGI_FORMAT_R32G32_FLOAT,0,24,D3D11_INPUT_PER_VERTEX_DATA,0},
    };
    if (FAILED(D()->CreateInputLayout(layout, 3, vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), &m_layout))) {
        vsBlob->Release(); return false;
    }
    vsBlob->Release();

    // Pixel shader
    const char* psCode = R"(
        cbuffer CB : register(b0) {
            float4x4 worldViewProj;
            float4x4 world;
            float4 ambient;
            float4 lightDir;
            float4 chams;
        };
        struct PSIn {
            float4 pos : SV_POSITION;
            float2 uv : TEXCOORD0;
            float3 normalW : NORMAL0;
            float3 posW : POSITION0;
        };
        Texture2D tex : register(t0);
        SamplerState samp : register(s0);
        float4 main(PSIn input) : SV_TARGET {
            float3 N = normalize(input.normalW);
            float3 L = normalize(float3(0.577, -0.577, 0.577));
            float diff = max(dot(N, L), 0.0);
            float4 color = tex.Sample(samp, input.uv);
            color.rgb = lerp(color.rgb, chams.rgb, chams.a);
            float3 ambientC = ambient.rgb;
            float3 lighting = ambientC + diff * float3(0.65, 0.65, 0.65);
            return float4(color.rgb * lighting, color.a);
        }
    )";
    ID3DBlob* psBlob = nullptr;
    if (FAILED(D3DCompile(psCode, strlen(psCode), nullptr, nullptr, nullptr, "main", "ps_4_0", 0, 0, &psBlob, &errBlob))) {
        if (errBlob) { OutputDebugStringA((char*)errBlob->GetBufferPointer()); errBlob->Release(); }
        return false;
    }
    if (FAILED(D()->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &m_ps))) {
        psBlob->Release(); return false;
    }
    psBlob->Release();

    // Constant buffer
    D3D11_BUFFER_DESC cbd = {};
    cbd.ByteWidth = 176; // wvp(64) + world(64) + ambient(16) + lightDir(16) + chams(16)
    cbd.Usage = D3D11_USAGE_DYNAMIC;
    cbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    cbd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    if (FAILED(D()->CreateBuffer(&cbd, nullptr, &m_cb))) return false;

    // Render target
    D3D11_TEXTURE2D_DESC td = {};
    td.Width = m_width; td.Height = m_height; td.MipLevels = 1; td.ArraySize = 1;
    td.Format = DXGI_FORMAT_R8G8B8A8_UNORM; td.SampleDesc.Count = 1;
    td.Usage = D3D11_USAGE_DEFAULT;
    td.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
    if (FAILED(D()->CreateTexture2D(&td, nullptr, &m_outputTex))) return false;
    if (FAILED(D()->CreateRenderTargetView(m_outputTex, nullptr, &m_outputRTV))) return false;
    if (FAILED(D()->CreateShaderResourceView(m_outputTex, nullptr, &m_outputView))) return false;

    // Depth stencil
    td.Format = DXGI_FORMAT_D24_UNORM_S8_UINT; td.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    ID3D11Texture2D* dsTex = nullptr;
    if (FAILED(D()->CreateTexture2D(&td, nullptr, &dsTex))) return false;
    if (FAILED(D()->CreateDepthStencilView(dsTex, nullptr, &m_dsv))) return false;
    dsTex->Release();

    // Sampler
    D3D11_SAMPLER_DESC sd = {};
    sd.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    sd.AddressU = sd.AddressV = sd.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
    if (FAILED(D()->CreateSamplerState(&sd, &m_sampler))) return false;

    return true;
}

static std::string CdnUrl(const std::string& hash) {
    int i = 31;
    for (int t = 0; t < (int)hash.size(); t++)
        i ^= (unsigned char)hash[t];
    return "https://t" + std::to_string(i % 8) + ".rbxcdn.com/" + hash;
}

bool Avatar3DRenderer::Load(int64_t userId) {
    if (m_loading) return false;
    m_loading = true;
    m_error.clear();
    Release();
    m_loaded = false;

    try {
        // Step 1: Try the avatar-3d API - look for imageUrl OR direct obj/mtl fields
        std::string metaJson, objHash, mtlHash;
        std::vector<std::string> texHashes;

        std::vector<std::pair<std::string, std::string>> endpoints = {
            {"https://thumbnails.roblox.com/v1/users/avatar-3d?userId=" + std::to_string(userId), "thumbnails"},
            {"https://web.roblox.com/avatar-thumbnail-3d/json?userId=" + std::to_string(userId), "web"},
            {"https://www.roblox.com/avatar-thumbnail-3d/json?userId=" + std::to_string(userId), "www"},
        };

        for (auto& ep : endpoints) {
            std::string raw = DownloadString(ep.first);
            if (raw.empty()) continue;
            if (raw.size() < 10 || raw[0] != '{') {
                OutputDebugStringA(("[Avatar3D] " + ep.second + " returned non-JSON (" + std::to_string(raw.size()) + " bytes, starts with " + (raw.empty() ? "empty" : std::string(1, raw[0])) + "): " + raw.substr(0, 120) + "\n").c_str());
                continue;
            }
            try {
                auto doc = json::parse(raw);
                // Check for standard thumbnail response: data[0].imageUrl
                if (doc.contains("data") && doc["data"].is_array() && !doc["data"].empty()) {
                    auto& first = doc["data"][0];
                    if (first.contains("imageUrl") && !first["imageUrl"].is_null()) {
                        std::string imageUrl = first["imageUrl"].get<std::string>();
                        OutputDebugStringA(("[Avatar3D] Got imageUrl: " + imageUrl + "\n").c_str());
                        metaJson = DownloadString(imageUrl);
                        if (!metaJson.empty()) break;
                    } else if (first.contains("obj")) {
                        metaJson = raw;
                        break;
                    }
                } else if (doc.contains("obj")) {
                    metaJson = raw;
                    break;
                }
            } catch (const std::exception& e) {
                OutputDebugStringA(("[Avatar3D] Parse error for " + ep.second + ": " + e.what() + "\n").c_str());
                metaJson = raw; // store anyway for debugging
                continue;
            }
        }

        if (metaJson.empty()) {
            m_error = "All endpoints returned non-JSON responses";
            m_loading = false; return false;
        }

        // Parse metadata
        auto meta = json::parse(metaJson);
        OutputDebugStringA(("[Avatar3D] Meta: " + metaJson.substr(0, 400) + "\n").c_str());

        if (meta.contains("obj")) {
            objHash = meta["obj"].get<std::string>();
            mtlHash = meta["mtl"].get<std::string>();
            if (meta.contains("textures") && meta["textures"].is_array()) {
                for (auto& t : meta["textures"])
                    texHashes.push_back(t.get<std::string>());
            }
        } else {
            // Maybe data[0] has it directly
            if (meta.contains("data") && meta["data"].is_array() && !meta["data"].empty()) {
                auto& d = meta["data"][0];
                if (d.contains("obj")) {
                    objHash = d["obj"].get<std::string>();
                    mtlHash = d["mtl"].get<std::string>();
                    if (d.contains("textures") && d["textures"].is_array()) {
                        for (auto& t : d["textures"])
                            texHashes.push_back(t.get<std::string>());
                    }
                }
            }
        }

        if (objHash.empty()) {
            m_error = "No obj hash found in response";
            OutputDebugStringA(("[Avatar3D] " + m_error + "\n").c_str());
            m_loading = false; return false;
        }

        // Step 3: Download OBJ
        std::string objUrl = CdnUrl(objHash);
        OutputDebugStringA(("[Avatar3D] OBJ URL: " + objUrl + "\n").c_str());
        std::string objData = DownloadString(objUrl);
        if (objData.empty()) {
            m_error = "Failed to download OBJ";
            m_loading = false; return false;
        }
        OutputDebugStringA(("[Avatar3D] OBJ: " + std::to_string(objData.size()) + " bytes\n").c_str());

        // Step 4: Download MTL
        std::string mtlUrl = CdnUrl(mtlHash);
        OutputDebugStringA(("[Avatar3D] MTL URL: " + mtlUrl + "\n").c_str());
        std::string mtlData = DownloadString(mtlUrl);
        if (mtlData.empty()) {
            m_error = "Failed to download MTL";
            m_loading = false; return false;
        }
        OutputDebugStringA(("[Avatar3D] MTL: " + std::to_string(mtlData.size()) + " bytes\n").c_str());

        // Step 5: Download textures
        for (auto& texHash : texHashes) {
            AvatarTexture at;
            at.hash = texHash;
            std::string texUrl = CdnUrl(texHash);
            auto imgData = DownloadBinary(texUrl);
            if (!imgData.empty()) {
                at.view = CreateTextureFromData(imgData);
                OutputDebugStringA(("[Avatar3D] Texture " + texHash.substr(0, 16) + "... loaded\n").c_str());
            } else {
                OutputDebugStringA(("[Avatar3D] Texture " + texHash.substr(0, 16) + "... FAILED\n").c_str());
            }
            m_textures.push_back(at);
        }

        // Step 6: Create pipeline
        if (!CreatePipeline()) {
            m_error = "Failed to create D3D11 pipeline";
            m_loading = false; return false;
        }

        // Step 7: Parse OBJ with MTL
        if (!ParseObj(objData, mtlData)) {
            m_error = "Failed to parse OBJ file";
            m_loading = false; return false;
        }

        if (m_meshes.empty()) {
            m_error = "No meshes found in OBJ";
            m_loading = false; return false;
        }

        BuildSkeletonFromParts();

        OutputDebugStringA(("[Avatar3D] Loaded " + std::to_string(m_meshes.size()) + " meshes, " +
            std::to_string(m_textures.size()) + " textures\n").c_str());

        m_loaded = true;
        m_loading = false;
        return true;

    } catch (const std::exception& e) {
        m_error = std::string("Exception: ") + e.what();
        OutputDebugStringA(("[Avatar3D] " + m_error + "\n").c_str());
        m_loading = false;
        return false;
    }
}

bool Avatar3DRenderer::ParseObj(const std::string& objData, const std::string& mtlData) {
    std::vector<float> positions, normals, uvs;

    // Build map from texture hash -> index in m_textures
    std::unordered_map<std::string, int> texHashIndex;
    for (int i = 0; i < (int)m_textures.size(); i++)
        texHashIndex[m_textures[i].hash] = i;

    // Parse MTL for material -> texture hash mapping
    std::unordered_map<std::string, std::string> matTexHash;
    std::string currentMat;
    {
        std::istringstream stream(mtlData);
        std::string line;
        while (std::getline(stream, line)) {
            if (line.empty()) continue;
            if (line.size() > 7 && line.substr(0, 7) == "newmtl ") {
                currentMat = line.substr(7);
                while (!currentMat.empty() && (currentMat.back() == ' ' || currentMat.back() == '\r'))
                    currentMat.pop_back();
            } else if (line.size() > 7 && line.substr(0, 7) == "map_Kd ") {
                std::string texPath = line.substr(7);
                while (!texPath.empty() && (texPath.back() == ' ' || texPath.back() == '\r'))
                    texPath.pop_back();
                // Extract hash from path (remove any directory)
                size_t slash = texPath.find_last_of("/\\");
                if (slash != std::string::npos) texPath = texPath.substr(slash + 1);
                matTexHash[currentMat] = texPath;
            }
        }
    }

    // Parse OBJ
    std::vector<float> meshPos, meshNorm, meshUV;
    std::vector<uint32_t> meshIdx;
    std::vector<ObjVertex> verts;
    std::vector<uint32_t> idxs;
    int currentTexIndex = -1;

    auto flushMesh = [&]() {
        if (idxs.empty() && verts.empty()) return;
        ObjMesh m;
        m.vertices = std::move(verts);
        m.indices = std::move(idxs);
        m.textureIndex = (currentTexIndex >= 0 && currentTexIndex < (int)m_textures.size()) ? currentTexIndex : -1;
        m_meshes.push_back(std::move(m));
        if (!m_meshes.back().vertices.empty()) {
            PartAABB a{};
            for (const auto& v : m_meshes.back().vertices) {
                if (!a.valid) {
                    a.min[0] = a.max[0] = v.x;
                    a.min[1] = a.max[1] = v.y;
                    a.min[2] = a.max[2] = v.z;
                    a.valid = true;
                } else {
                    if (v.x < a.min[0]) a.min[0] = v.x;
                    if (v.x > a.max[0]) a.max[0] = v.x;
                    if (v.y < a.min[1]) a.min[1] = v.y;
                    if (v.y > a.max[1]) a.max[1] = v.y;
                    if (v.z < a.min[2]) a.min[2] = v.z;
                    if (v.z > a.max[2]) a.max[2] = v.z;
                }
            }
            m_parts.push_back(a);
        }
        verts.clear(); idxs.clear();
    };

    std::istringstream objStream(objData);
    std::string line;
    while (std::getline(objStream, line)) {
        if (line.empty() || line[0] == '#') continue;

        if (line.size() > 2 && line[0] == 'v' && line[1] == ' ') {
            float x, y, z;
            if (sscanf_s(line.c_str() + 2, "%f %f %f", &x, &y, &z) >= 3) {
                positions.push_back(x); positions.push_back(y); positions.push_back(z);
            }
        } else if (line.size() > 3 && line[0] == 'v' && line[1] == 't' && line[2] == ' ') {
            float u, v;
            if (sscanf_s(line.c_str() + 3, "%f %f", &u, &v) >= 2) {
                uvs.push_back(u); uvs.push_back(1.0f - v);
            }
        } else if (line.size() > 3 && line[0] == 'v' && line[1] == 'n' && line[2] == ' ') {
            float x, y, z;
            if (sscanf_s(line.c_str() + 3, "%f %f %f", &x, &y, &z) >= 3) {
                normals.push_back(x); normals.push_back(y); normals.push_back(z);
            }
        } else if (line.size() > 2 && line[0] == 'g' && line[1] == ' ') {
            flushMesh();
        } else if (line.size() > 7 && line.substr(0, 7) == "usemtl ") {
            flushMesh();
            std::string mtlName = line.substr(7);
            while (!mtlName.empty() && (mtlName.back() == ' ' || mtlName.back() == '\r'))
                mtlName.pop_back();
            auto it = matTexHash.find(mtlName);
            if (it != matTexHash.end()) {
                auto ti = texHashIndex.find(it->second);
                currentTexIndex = (ti != texHashIndex.end()) ? ti->second : -1;
            } else {
                currentTexIndex = -1;
            }
        } else if (line[0] == 'f' && line[1] == ' ') {
            // Parse face
            std::string fdata = line.substr(2);
            std::vector<int> fv, ft, fn;
            std::istringstream fs(fdata);
            std::string token;
            while (fs >> token) {
                int vi = 0, ti = 0, ni = 0;
                if (sscanf_s(token.c_str(), "%d/%d/%d", &vi, &ti, &ni) >= 3) {
                    fv.push_back(vi); ft.push_back(ti); fn.push_back(ni);
                } else if (sscanf_s(token.c_str(), "%d//%d", &vi, &ni) >= 2) {
                    fv.push_back(vi); ft.push_back(0); fn.push_back(ni);
                } else if (sscanf_s(token.c_str(), "%d/%d", &vi, &ti) >= 2) {
                    fv.push_back(vi); ft.push_back(ti); fn.push_back(0);
                } else if (sscanf_s(token.c_str(), "%d", &vi) >= 1) {
                    fv.push_back(vi); ft.push_back(0); fn.push_back(0);
                }
            }

            if (fv.size() >= 3) {
                for (size_t i = 2; i < fv.size(); i++) {
                    int tris[] = { fv[0], fv[i-1], fv[i] };
                    int tts[] = { ft.size() > 0 ? ft[0] : 0, ft.size() > i-1 ? ft[i-1] : 0, ft.size() > i ? ft[i] : 0 };
                    int nns[] = { fn.size() > 0 ? fn[0] : 0, fn.size() > i-1 ? fn[i-1] : 0, fn.size() > i ? fn[i] : 0 };

                    for (int j = 0; j < 3; j++) {
                        int vi = tris[j];
                        int pvi = (vi > 0) ? (vi - 1) * 3 : (int)positions.size() + vi * 3;
                        ObjVertex ov = {};
                        if (pvi >= 0 && pvi + 2 < (int)positions.size()) {
                            ov.x = positions[pvi]; ov.y = positions[pvi + 1]; ov.z = positions[pvi + 2];
                        }
                        if (nns[j] != 0) {
                            int pni = (nns[j] > 0) ? (nns[j] - 1) * 3 : (int)normals.size() + nns[j] * 3;
                            if (pni >= 0 && pni + 2 < (int)normals.size()) {
                                ov.nx = normals[pni]; ov.ny = normals[pni + 1]; ov.nz = normals[pni + 2];
                            }
                        }
                        if (tts[j] != 0) {
                            int pti = (tts[j] > 0) ? (tts[j] - 1) * 2 : (int)uvs.size() + tts[j] * 2;
                            if (pti >= 0 && pti + 1 < (int)uvs.size()) {
                                ov.u = uvs[pti]; ov.v = uvs[pti + 1];
                            }
                        }
                        verts.push_back(ov);
                        idxs.push_back((uint32_t)verts.size() - 1);
                    }
                }
            }
        }
    }

    flushMesh();

    // If no meshes have textures but we have textures and there's no usemtl info,
    // assign the first texture to all meshes
    for (auto& mesh : m_meshes) {
        if (mesh.textureIndex < 0 && !m_textures.empty())
            mesh.textureIndex = 0;
    }

    return !m_meshes.empty();
}

void Avatar3DRenderer::BuildSkeletonFromParts() {
    m_skelSegCount = 0;

    if (m_parts.empty()) return;

    float bx0 = FLT_MAX, bx1 = -FLT_MAX, by0 = FLT_MAX, by1 = -FLT_MAX;
    for (const auto& p : m_parts) {
        if (!p.valid) continue;
        bx0 = (std::min)(bx0, p.min[0]); bx1 = (std::max)(bx1, p.max[0]);
        by0 = (std::min)(by0, p.min[1]); by1 = (std::max)(by1, p.max[1]);
    }
    if (by1 - by0 < 0.01f) return;

    const float cx = (bx0 + bx1) * 0.5f;
    const float h = by1 - by0;
    const float w = bx1 - bx0;

    const PartAABB* torso = nullptr;
    const PartAABB* lArm = nullptr;
    const PartAABB* rArm = nullptr;
    const PartAABB* lLeg = nullptr;
    const PartAABB* rLeg = nullptr;

    for (const auto& p : m_parts) {
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
        if (m_skelSegCount >= MaxSkelSegs) return;
        m_skelSeg[m_skelSegCount][0][0] = ax;
        m_skelSeg[m_skelSegCount][0][1] = ay;
        m_skelSeg[m_skelSegCount][0][2] = az;
        m_skelSeg[m_skelSegCount][1][0] = bx;
        m_skelSeg[m_skelSegCount][1][1] = by;
        m_skelSeg[m_skelSegCount][1][2] = bz;
        ++m_skelSegCount;
    };

    auto axis = [](const PartAABB& p, float top[3], float bot[3]) {
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

    auto arm_bones = [&](const PartAABB* arm) {
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

    auto leg_bones = [&](const PartAABB* leg) {
        if (!leg) return;
        float t[3], b[3];
        axis(*leg, t, b);
        add(torso_bot[0], torso_bot[1], torso_bot[2], t[0], t[1], t[2]);
        add(t[0], t[1], t[2], b[0], b[1], b[2]);
    };
    leg_bones(lLeg);
    leg_bones(rLeg);
}

bool Avatar3DRenderer::GetProjectedSkeleton(std::vector<float>& out_uv_segs) const {
    out_uv_segs.clear();
    if (!m_lastMVPValid || m_skelSegCount <= 0) return false;
    out_uv_segs.reserve((size_t)m_skelSegCount * 4);
    for (int i = 0; i < m_skelSegCount; ++i) {
        float u0, v0, u1, v1;
        const float* M = m_lastMVP;
        auto proj = [&](const float p[3], float& u, float& v) -> bool {
            const float clip_x = p[0] * M[0] + p[1] * M[4] + p[2] * M[8] + M[12];
            const float clip_y = p[0] * M[1] + p[1] * M[5] + p[2] * M[9] + M[13];
            const float clip_w = p[0] * M[3] + p[1] * M[7] + p[2] * M[11] + M[15];
            if (clip_w <= 1e-5f) return false;
            const float inv = 1.0f / clip_w;
            u = clip_x * inv * 0.5f + 0.5f;
            v = -clip_y * inv * 0.5f + 0.5f;
            return true;
        };
        if (!proj(m_skelSeg[i][0], u0, v0)) continue;
        if (!proj(m_skelSeg[i][1], u1, v1)) continue;
        out_uv_segs.push_back(u0);
        out_uv_segs.push_back(v0);
        out_uv_segs.push_back(u1);
        out_uv_segs.push_back(v1);
    }
    return out_uv_segs.size() >= 4;
}

void Avatar3DRenderer::Render(float dt) {
    if (!m_loaded || m_meshes.empty() || !D() || !C()) return;

    auto* c = C();

    // Save state
    D3D11_VIEWPORT oldVP;
    UINT numVP = 1;
    c->RSGetViewports(&numVP, &oldVP);
    ID3D11RenderTargetView* oldRTV = nullptr;
    ID3D11DepthStencilView* oldDSV = nullptr;
    c->OMGetRenderTargets(1, &oldRTV, &oldDSV);

    // Set render target
    D3D11_VIEWPORT vp = {0, 0, (float)m_width, (float)m_height, 0, 1};
    c->RSSetViewports(1, &vp);
    c->OMSetRenderTargets(1, &m_outputRTV, m_dsv);

    float clearColor[4] = {0, 0, 0, 0};
    c->ClearRenderTargetView(m_outputRTV, clearColor);
    c->ClearDepthStencilView(m_dsv, D3D11_CLEAR_DEPTH, 1.0f, 0);

    // Pipeline state
    c->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    c->IASetInputLayout(m_layout);
    c->VSSetShader(m_vs, nullptr, 0);
    c->PSSetShader(m_ps, nullptr, 0);
    c->VSSetConstantBuffers(0, 1, &m_cb);
    c->PSSetSamplers(0, 1, &m_sampler);

    // Compute bounding box for camera
    float bmin[3] = {FLT_MAX, FLT_MAX, FLT_MAX};
    float bmax[3] = {-FLT_MAX, -FLT_MAX, -FLT_MAX};
    for (auto& mesh : m_meshes) {
        for (auto& v : mesh.vertices) {
            bmin[0] = (std::min)(bmin[0], v.x); bmin[1] = (std::min)(bmin[1], v.y); bmin[2] = (std::min)(bmin[2], v.z);
            bmax[0] = (std::max)(bmax[0], v.x); bmax[1] = (std::max)(bmax[1], v.y); bmax[2] = (std::max)(bmax[2], v.z);
        }
    }
    float cx = (bmin[0] + bmax[0]) / 2, cy = (bmin[1] + bmax[1]) / 2, cz = (bmin[2] + bmax[2]) / 2;
    float dx = bmax[0] - bmin[0], dy = bmax[1] - bmin[1], dz = bmax[2] - bmin[2];
    float radius = sqrt(dx * dx + dy * dy + dz * dz) / 2;
    float dist = (std::max)(radius * 2.5f, 3.0f) / (m_zoom > 0.0001f ? m_zoom : 1.0f);

    // auto-spin
    if (m_autoSpin)
        m_angle += dt * 0.5f;
    float totalYaw = m_angle + m_manualYaw;
    float cosA = cosf(totalYaw), sinA = sinf(totalYaw);
    float ry[16];
    memset(ry, 0, sizeof(ry));
    ry[0] = cosA; ry[2] = sinA; ry[5] = 1; ry[8] = -sinA; ry[10] = cosA; ry[15] = 1;

    // Build view-projection matrix manually
    // LookAtLH: eye at (0, 0, dist) -- model center is at origin after world translate, so look at origin
    float view[16], proj[16];
    {
        // view matrix
        float f[3] = {0 - 0, 0 - 0, 0 - dist}; // forward: at(0,0,0) - eye(0,0,dist)
        float flen = sqrt(f[0]*f[0] + f[1]*f[1] + f[2]*f[2]);
        if (flen > 0) { f[0] /= flen; f[1] /= flen; f[2] /= flen; }
        float up[3] = {0, 1, 0};
        float s[3];
        s[0] = f[1]*up[2] - f[2]*up[1];
        s[1] = f[2]*up[0] - f[0]*up[2];
        s[2] = f[0]*up[1] - f[1]*up[0];
        float slen = sqrt(s[0]*s[0] + s[1]*s[1] + s[2]*s[2]);
        if (slen > 0) { s[0] /= slen; s[1] /= slen; s[2] /= slen; }
        float u[3];
        u[0] = s[1]*f[2] - s[2]*f[1];
        u[1] = s[2]*f[0] - s[0]*f[2];
        u[2] = s[0]*f[1] - s[1]*f[0];

        float ex = 0, ey = 0, ez = dist;
        memset(view, 0, sizeof(view));
        view[0] = s[0]; view[1] = u[0]; view[2] = f[0]; view[3] = 0;
        view[4] = s[1]; view[5] = u[1]; view[6] = f[1]; view[7] = 0;
        view[8] = s[2]; view[9] = u[2]; view[10] = f[2]; view[11] = 0;
        view[12] = -(s[0]*ex + s[1]*ey + s[2]*ez);
        view[13] = -(u[0]*ex + u[1]*ey + u[2]*ez);
        view[14] = -(f[0]*ex + f[1]*ey + f[2]*ez);
        view[15] = 1;

        // PerspectiveFovLH
        float fov = 3.14159f / 4, aspect = (float)m_width / m_height, zn = 0.1f, zf2 = 1000.0f;
        float h = 1.0f / tan(fov / 2), w = h / aspect;
        memset(proj, 0, sizeof(proj));
        proj[0] = w; proj[5] = h; proj[10] = zf2 / (zf2 - zn); proj[11] = 1; proj[14] = -zn * zf2 / (zf2 - zn);
    }

    // world matrix: rotate model around its center about Y, then translate center to origin
    float t[16];
    memset(t, 0, sizeof(t));
    t[0] = 1; t[5] = 1; t[10] = 1; t[15] = 1;
    t[12] = -cx; t[13] = -cy; t[14] = -cz;

    // world = T * R (rotate first, then translate)
    float world[16];
    for (int r = 0; r < 4; r++) {
        for (int c2 = 0; c2 < 4; c2++) {
            world[r*4+c2] = t[r*4]*ry[c2] + t[r*4+1]*ry[4+c2] + t[r*4+2]*ry[8+c2] + t[r*4+3]*ry[12+c2];
        }
    }

    // Multiply: wvp = world * view * proj
    float wvp[16];
    // world * view
    float wv[16];
    for (int r = 0; r < 4; r++) {
        for (int c2 = 0; c2 < 4; c2++) {
            wv[r*4+c2] = world[r*4]*view[c2] + world[r*4+1]*view[4+c2] + world[r*4+2]*view[8+c2] + world[r*4+3]*view[12+c2];
        }
    }
    for (int r = 0; r < 4; r++) {
        for (int c2 = 0; c2 < 4; c2++) {
            wvp[r*4+c2] = wv[r*4]*proj[c2] + wv[r*4+1]*proj[4+c2] + wv[r*4+2]*proj[8+c2] + wv[r*4+3]*proj[12+c2];
        }
    }

    std::memcpy(m_lastMVP, wvp, sizeof(wvp));
    m_lastMVPValid = true;

    // Render each mesh
    for (auto& mesh : m_meshes) {
        if (mesh.vertices.empty() || mesh.indices.empty()) continue;

        // Create temp vertex buffer
        D3D11_BUFFER_DESC vbd = {};
        vbd.ByteWidth = (UINT)(mesh.vertices.size() * sizeof(ObjVertex));
        vbd.Usage = D3D11_USAGE_IMMUTABLE;
        vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
        D3D11_SUBRESOURCE_DATA vsd = {mesh.vertices.data(), 0, 0};
        ID3D11Buffer* vb = nullptr;
        if (FAILED(D()->CreateBuffer(&vbd, &vsd, &vb))) continue;

        D3D11_BUFFER_DESC ibd = {};
        ibd.ByteWidth = (UINT)(mesh.indices.size() * sizeof(uint32_t));
        ibd.Usage = D3D11_USAGE_IMMUTABLE;
        ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;
        D3D11_SUBRESOURCE_DATA isd = {mesh.indices.data(), 0, 0};
        ID3D11Buffer* ib = nullptr;
        if (FAILED(D()->CreateBuffer(&ibd, &isd, &ib))) { vb->Release(); continue; }

        // Update constant buffer
        D3D11_MAPPED_SUBRESOURCE ms;
        if (SUCCEEDED(c->Map(m_cb, 0, D3D11_MAP_WRITE_DISCARD, 0, &ms))) {
            float* cb = (float*)ms.pData;
            memcpy(cb, wvp, 64);
            memcpy(cb + 16, world, 64);
            cb[32] = 0.35f; cb[33] = 0.35f; cb[34] = 0.35f; cb[35] = 1.0f;
            cb[36] = 0.577f; cb[37] = -0.577f; cb[38] = 0.577f; cb[39] = 0;
            cb[40] = m_tint[0]; cb[41] = m_tint[1]; cb[42] = m_tint[2]; cb[43] = m_tint[3];
            c->Unmap(m_cb, 0);
        }

        UINT stride = sizeof(ObjVertex), offset = 0;
        c->IASetVertexBuffers(0, 1, &vb, &stride, &offset);
        c->IASetIndexBuffer(ib, DXGI_FORMAT_R32_UINT, 0);

        ID3D11ShaderResourceView* srv = nullptr;
        if (mesh.textureIndex >= 0 && mesh.textureIndex < (int)m_textures.size())
            srv = m_textures[mesh.textureIndex].view;
        c->PSSetShaderResources(0, 1, &srv);

        c->DrawIndexed((UINT)mesh.indices.size(), 0, 0);

        vb->Release();
        ib->Release();
    }

    // Restore
    c->RSSetViewports(numVP, &oldVP);
    c->OMSetRenderTargets(1, &oldRTV, oldDSV);
    if (oldRTV) oldRTV->Release();
    if (oldDSV) oldDSV->Release();
}

void Avatar3DRenderer::Release() {
    m_loaded = false;
    m_meshes.clear();
    for (auto& t : m_textures) if (t.view) { t.view->Release(); t.view = nullptr; }
    m_textures.clear();
    if (m_vs) { m_vs->Release(); m_vs = nullptr; }
    if (m_ps) { m_ps->Release(); m_ps = nullptr; }
    if (m_layout) { m_layout->Release(); m_layout = nullptr; }
    if (m_cb) { m_cb->Release(); m_cb = nullptr; }
    if (m_sampler) { m_sampler->Release(); m_sampler = nullptr; }
    if (m_outputTex) { m_outputTex->Release(); m_outputTex = nullptr; }
    if (m_outputRTV) { m_outputRTV->Release(); m_outputRTV = nullptr; }
    if (m_outputView) { m_outputView->Release(); m_outputView = nullptr; }
    if (m_dsv) { m_dsv->Release(); m_dsv = nullptr; }
}
