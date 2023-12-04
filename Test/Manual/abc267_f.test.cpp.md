---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/LevelAncestor.hpp
    title: Src/Graph/Tree/LevelAncestor.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc267/submissions/48201106
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/Manual/abc267_f.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * ABC267-F Exactly K Steps\n * https://atcoder.jp/contests/abc267/submissions/48201106\n\
    \ */\n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Graph/Tree/LevelAncestor.hpp\"\n\n#line\
    \ 4 \"Src/Graph/Tree/LevelAncestor.hpp\"\n\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\nnamespace zawa {\n\nclass LevelAncestor {\nprivate:\n   \
    \ usize n_{};\n    u32 root_{};\n    std::vector<std::vector<u32>> tree_;\n  \
    \  std::vector<std::vector<u32>> jump_;\n    std::vector<u32> depth_;\n\n    static\
    \ constexpr u32 invalid_{static_cast<u32>(-1)};\n    static constexpr u32 ceilLog2(u32\
    \ n) noexcept {\n        assert(n or !\"empty graph is not allowed\");\n     \
    \   return 32 - __builtin_clz(n);\n    }\n\npublic:\n    constexpr usize size()\
    \ const noexcept {\n        return n_;\n    }\n\n    u32 log() const noexcept\
    \ {\n        return jump_.size();\n    }\n\n    const u32& depth(u32 v) const\
    \ noexcept {\n        assert(v < size());\n        return depth_[v];\n    }\n\n\
    \    static constexpr u32 invalid() noexcept {\n        return invalid_;\n   \
    \ }\n\n    static constexpr bool invalid(usize v) noexcept {\n        return v\
    \ == invalid_;\n    }\n\n    constexpr u32 root() const noexcept {\n        return\
    \ root_;\n    }\n\nprivate:\n\n    void dfs(u32 v, u32 p) {\n        depth_[v]\
    \ = (invalid(p) ? invalid_ : depth_[p]) + 1;\n        jump_[0][v] = (invalid(p)\
    \ ? v : p);\n        for (u32 i{} ; i + 1 < log() ; i++) {\n            jump_[i\
    \ + 1][v] = jump_[i][jump_[i][v]];\n        }\n        for (auto x : tree_[v])\
    \ if (x != p) {\n            assert(invalid(depth_[x]) or !\"given graph is not\
    \ tree\");\n            dfs(x, v);\n        }\n    }\n\npublic:\n    LevelAncestor()\
    \ = default;\n    LevelAncestor(usize n, u32 root = 0)\n        : n_{n}, root_{root},\
    \ tree_(n), jump_(ceilLog2(n), std::vector<u32>(n)), depth_(n, invalid_) {}\n\
    \    LevelAncestor(const std::vector<std::vector<u32>>& tree, u32 root = 0) \n\
    \        : n_{tree.size()}, root_{root}, tree_{tree}, jump_(ceilLog2(n_), std::vector<u32>(n_)),\
    \ depth_(n_, invalid_) {\n        build();\n    }\n\n    void addEdge(usize u,\
    \ usize v) {\n        assert(u < size());\n        assert(v < size());\n     \
    \   tree_[u].emplace_back(v);\n        tree_[v].emplace_back(u);\n    }\n\n  \
    \  void build() {\n        dfs(root(), invalid_);\n    }\n\n    usize lca(usize\
    \ u, usize v) const {\n        if (depth(u) > depth(v)) std::swap(u, v);\n   \
    \     for (u32 i{log()} ; i-- ; ) {\n            if ((depth(v) - depth(u)) & (1u\
    \ << i)) {\n                v = jump_[i][v];\n            }\n        }\n     \
    \   if (u == v) return u;\n        for (u32 i{log()} ; i-- ; ) {\n           \
    \ if (jump_[i][u] != jump_[i][v]) {\n                u = jump_[i][u];\n      \
    \          v = jump_[i][v];\n            }\n        }\n        return jump_[0][u];\n\
    \    }\n\n    u32 operator()(u32 v, u32 up) const {\n        assert(v < size());\n\
    \        if (depth(v) < up) return invalid();\n        if (depth(v) == up) return\
    \ root();\n        for (u32 i{log()} ; i-- ; ) {\n            if (up & (1u <<\
    \ i)) {\n                up ^= (1u << i);\n                v = jump_[i][v];\n\
    \            }\n        }\n        return v;\n    }\n\n};\n\n} // namespace zawa\n\
    #line 10 \"Test/Manual/abc267_f.test.cpp\"\nusing namespace zawa;\n\n#include\
    \ <algorithm>\n#line 14 \"Test/Manual/abc267_f.test.cpp\"\n#include <iterator>\n\
    #line 16 \"Test/Manual/abc267_f.test.cpp\"\n#include <queue>\n#line 18 \"Test/Manual/abc267_f.test.cpp\"\
    \n\nvoid solve() {\n    SetFastIO();\n    int n; std::cin >> n;\n    std::vector\
    \ g(n, std::vector<u32>{});\n    for (u32 _{} ; _ < (u32)n - 1 ; _++) {\n    \
    \    u32 a, b; std::cin >> a >> b;\n        a--; b--;\n        g[a].emplace_back(b);\n\
    \        g[b].emplace_back(a);\n    }\n\n    auto bfs{[&](int s) -> std::vector<int>\
    \ {\n        std::vector<int> dist(n, n);\n        dist[s] = 0;\n        std::queue<int>\
    \ que{ { s } };\n        while (que.size()) {\n            int v{que.front()};\n\
    \            que.pop();\n            for (auto x : g[v]) if (dist[x] > dist[v]\
    \ + 1) {\n                dist[x] = dist[v] + 1;\n                que.emplace(x);\n\
    \            }\n        }\n        return dist;\n    }};\n\n    auto dist1{bfs(0)};\n\
    \    u32 L{(u32)std::distance(dist1.begin(), std::max_element(dist1.begin(), dist1.end()))};\n\
    \    auto dist2{bfs(L)};\n    u32 R{(u32)std::distance(dist2.begin(), std::max_element(dist2.begin(),\
    \ dist2.end()))};\n\n    LevelAncestor laL{g, L}, laR{g, R};\n    int q; std::cin\
    \ >> q;\n    for (int _{} ; _ < q ; _++) {\n        int u, k; std::cin >> u >>\
    \ k;\n        u--;\n        auto vL{laL(u, k)};\n        if (LevelAncestor::invalid(vL))\
    \ {\n            auto vR{laR(u, k)};\n            if (LevelAncestor::invalid(vR))\
    \ {\n                std::cout << -1 << '\\n';\n            }\n            else\
    \ {\n                std::cout << vR + 1 << '\\n';\n            }\n        }\n\
    \        else {\n            std::cout << vL + 1 << '\\n';\n        }\n    }\n\
    }\n\nint main() {\n#ifdef ATCODER\n    solve();\n#else\n    std::cout << \"Hello\
    \ World\" << '\\n';\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * ABC267-F Exactly K Steps\n * https://atcoder.jp/contests/abc267/submissions/48201106\n\
    \ */\n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Graph/Tree/LevelAncestor.hpp\"\
    \nusing namespace zawa;\n\n#include <algorithm>\n#include <iostream>\n#include\
    \ <iterator>\n#include <utility>\n#include <queue>\n#include <vector>\n\nvoid\
    \ solve() {\n    SetFastIO();\n    int n; std::cin >> n;\n    std::vector g(n,\
    \ std::vector<u32>{});\n    for (u32 _{} ; _ < (u32)n - 1 ; _++) {\n        u32\
    \ a, b; std::cin >> a >> b;\n        a--; b--;\n        g[a].emplace_back(b);\n\
    \        g[b].emplace_back(a);\n    }\n\n    auto bfs{[&](int s) -> std::vector<int>\
    \ {\n        std::vector<int> dist(n, n);\n        dist[s] = 0;\n        std::queue<int>\
    \ que{ { s } };\n        while (que.size()) {\n            int v{que.front()};\n\
    \            que.pop();\n            for (auto x : g[v]) if (dist[x] > dist[v]\
    \ + 1) {\n                dist[x] = dist[v] + 1;\n                que.emplace(x);\n\
    \            }\n        }\n        return dist;\n    }};\n\n    auto dist1{bfs(0)};\n\
    \    u32 L{(u32)std::distance(dist1.begin(), std::max_element(dist1.begin(), dist1.end()))};\n\
    \    auto dist2{bfs(L)};\n    u32 R{(u32)std::distance(dist2.begin(), std::max_element(dist2.begin(),\
    \ dist2.end()))};\n\n    LevelAncestor laL{g, L}, laR{g, R};\n    int q; std::cin\
    \ >> q;\n    for (int _{} ; _ < q ; _++) {\n        int u, k; std::cin >> u >>\
    \ k;\n        u--;\n        auto vL{laL(u, k)};\n        if (LevelAncestor::invalid(vL))\
    \ {\n            auto vR{laR(u, k)};\n            if (LevelAncestor::invalid(vR))\
    \ {\n                std::cout << -1 << '\\n';\n            }\n            else\
    \ {\n                std::cout << vR + 1 << '\\n';\n            }\n        }\n\
    \        else {\n            std::cout << vL + 1 << '\\n';\n        }\n    }\n\
    }\n\nint main() {\n#ifdef ATCODER\n    solve();\n#else\n    std::cout << \"Hello\
    \ World\" << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Tree/LevelAncestor.hpp
  isVerificationFile: true
  path: Test/Manual/abc267_f.test.cpp
  requiredBy: []
  timestamp: '2023-12-05 07:56:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Manual/abc267_f.test.cpp
layout: document
redirect_from:
- /verify/Test/Manual/abc267_f.test.cpp
- /verify/Test/Manual/abc267_f.test.cpp.html
title: Test/Manual/abc267_f.test.cpp
---
