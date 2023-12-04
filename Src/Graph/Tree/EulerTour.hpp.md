---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Tree/EulerTour.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Tree/EulerTour.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\nclass EulerTour {\n\
    private:\n    u32 root{};\n    std::vector<std::vector<u32>> tree;\n    std::vector<u32>\
    \ tour;\n    std::vector<u32> in, out;\n    static constexpr u32 invalid{static_cast<u32>(-1)};\n\
    \n    void dfs(u32 v, u32 p, u32& t) {\n        in[v] = ++t;\n        tour.emplace_back(v);\n\
    \        for (auto x : tree[v]) if (x != p) {\n            assert(in[x] == invalid\
    \ or !\"given graph is not tree\");\n            dfs(x, v, t);\n            tour.emplace_back(v);\n\
    \        }\n        out[v] = ++t;\n    }\n\npublic:\n    EulerTour() = default;\n\
    \    EulerTour(usize n, u32 r) : root{r}, tree(n), tour{}, in(n, invalid), out(n,\
    \ invalid) {\n        assert(n);\n        assert(r < n or !\"r must be (r < n)\"\
    );\n        tour.reserve(2 * n - 1);\n    }\n\n    usize size() const noexcept\
    \ {\n        return tree.size();\n    }\n    \n    usize rangeSize() const noexcept\
    \ {\n        return (size() << 1) - 1;\n    }\n\n    void addEdge(usize u, usize\
    \ v) {\n        assert(u < size());\n        assert(v < size());\n        tree[u].emplace_back(v);\n\
    \        tree[v].emplace_back(u);\n    }\n\n    void build() {\n        u32 t{invalid};\n\
    \        dfs(root, invalid, t);\n        assert(tour.size() == rangeSize());\n\
    \    }\n\n    bool isAncestor(usize anc, usize child) const {\n        assert(anc\
    \ < size());\n        assert(child < size());\n        return in[anc] < in[child]\
    \ and out[child] < in[child];\n    }\n\n    u32 pos(u32 v) const {\n        assert(v\
    \ < size());\n        return in[v];\n    }\n\n    std::pair<usize, usize> subtree(usize\
    \ v) const {\n        assert(v < size());\n        return std::pair<usize, usize>{\
    \ in[v], out[v] };\n    }\n\n    const u32& operator[](usize i) const noexcept\
    \ {\n        assert(i < rangeSize());\n        return tour[i];\n    }\n\n};\n\n\
    } // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\nclass EulerTour {\n\
    private:\n    u32 root{};\n    std::vector<std::vector<u32>> tree;\n    std::vector<u32>\
    \ tour;\n    std::vector<u32> in, out;\n    static constexpr u32 invalid{static_cast<u32>(-1)};\n\
    \n    void dfs(u32 v, u32 p, u32& t) {\n        in[v] = ++t;\n        tour.emplace_back(v);\n\
    \        for (auto x : tree[v]) if (x != p) {\n            assert(in[x] == invalid\
    \ or !\"given graph is not tree\");\n            dfs(x, v, t);\n            tour.emplace_back(v);\n\
    \        }\n        out[v] = ++t;\n    }\n\npublic:\n    EulerTour() = default;\n\
    \    EulerTour(usize n, u32 r) : root{r}, tree(n), tour{}, in(n, invalid), out(n,\
    \ invalid) {\n        assert(n);\n        assert(r < n or !\"r must be (r < n)\"\
    );\n        tour.reserve(2 * n - 1);\n    }\n\n    usize size() const noexcept\
    \ {\n        return tree.size();\n    }\n    \n    usize rangeSize() const noexcept\
    \ {\n        return (size() << 1) - 1;\n    }\n\n    void addEdge(usize u, usize\
    \ v) {\n        assert(u < size());\n        assert(v < size());\n        tree[u].emplace_back(v);\n\
    \        tree[v].emplace_back(u);\n    }\n\n    void build() {\n        u32 t{invalid};\n\
    \        dfs(root, invalid, t);\n        assert(tour.size() == rangeSize());\n\
    \    }\n\n    bool isAncestor(usize anc, usize child) const {\n        assert(anc\
    \ < size());\n        assert(child < size());\n        return in[anc] < in[child]\
    \ and out[child] < in[child];\n    }\n\n    u32 pos(u32 v) const {\n        assert(v\
    \ < size());\n        return in[v];\n    }\n\n    std::pair<usize, usize> subtree(usize\
    \ v) const {\n        assert(v < size());\n        return std::pair<usize, usize>{\
    \ in[v], out[v] };\n    }\n\n    const u32& operator[](usize i) const noexcept\
    \ {\n        assert(i < rangeSize());\n        return tour[i];\n    }\n\n};\n\n\
    } // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/EulerTour.hpp
  requiredBy: []
  timestamp: '2023-12-05 07:45:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Src/Graph/Tree/EulerTour.hpp
layout: document
redirect_from:
- /library/Src/Graph/Tree/EulerTour.hpp
- /library/Src/Graph/Tree/EulerTour.hpp.html
title: Src/Graph/Tree/EulerTour.hpp
---
