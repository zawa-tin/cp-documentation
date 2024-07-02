#pragma once

#include "../../Template/TypeAlias.hpp"

#include <vector>

namespace zawa {

using Tree = std::vector<std::vector<u32>>;

void AddEdge(Tree& T, u32 u, u32 v) {
    T[u].emplace_back(v);
    T[v].emplace_back(u);
}

void AddDirectedEdge(Tree& T, u32 from, u32 to) {
    T[from].emplace_back(to);
}

} // namespace zawa
