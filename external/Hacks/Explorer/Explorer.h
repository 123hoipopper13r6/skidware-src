#pragma once
#include <string>
#include <vector>

namespace SDK { class Instance; struct Vector3; }

SDK::Vector3 FindFirstPartPosition(SDK::Instance& inst);

struct CachedNode {
    uintptr_t address = 0;
    std::string name;
    std::string className;
    std::string path;
    std::vector<CachedNode> children;
};

struct FilterResult {
    uintptr_t address;
    std::string name;
    std::string className;
    std::string path;
};

void CacheTree();
void RenderPausedTree();

namespace Hacks::Explorer
{
	void Render();
	void RenderTree();
}
