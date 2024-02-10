---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Components/Lowlink.hpp
    title: "Lowlink (\u6A4B\u30FB\u95A2\u7BC0\u70B9)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A
  bundledCode: "#line 1 \"Test/AOJ/GRL_3_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A\"\
    \n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Graph/Components/Lowlink.hpp\"\n\n#line\
    \ 4 \"Src/Graph/Components/Lowlink.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\nclass Lowlink {\n\
    private:\n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n    usize n_{},\
    \ m_{};\n    std::vector<std::vector<std::pair<u32, u32>>> g_;\n    std::vector<std::pair<u32,\
    \ u32>> e_;\n    std::vector<u32> in_, low_;\n    std::vector<u32> articulation_;\n\
    \    std::vector<bool> bridge_;\n\n    void dfs(u32 v, u32 p, u32& t) {\n    \
    \    low_[v] = in_[v] = t++;\n        u32 deg{}; \n        for (const auto& [x,\
    \ i] : g_[v]) {\n            if (in_[x] == INVALID) {\n                deg++;\n\
    \                dfs(x, v, t);\n                low_[v] = std::min(low_[v], low_[x]);\n\
    \                if (p != INVALID and low_[x] >= in_[v]) {\n                 \
    \   articulation_[v]++;\n                }\n                if (low_[x] > in_[v])\
    \ {\n                    bridge_[i] = true;\n                }\n            }\n\
    \            else if (x != p) {\n                low_[v] = std::min(low_[v], in_[x]);\n\
    \            }\n        }\n        if (p == INVALID) {\n            articulation_[v]\
    \ = deg;\n        }\n    }\n\npublic:\n    constexpr usize size() const noexcept\
    \ {\n        return n_;\n    }\n    constexpr usize edgeSize() const noexcept\
    \ {\n        return m_;\n    }\n\n    Lowlink() = default;\n    Lowlink(usize\
    \ n) \n        : n_{n}, m_{}, g_(n), in_(n, INVALID), low_(n), articulation_(n,\
    \ u32{1}), bridge_{} {\n        g_.shrink_to_fit();\n        in_.shrink_to_fit();\n\
    \        low_.shrink_to_fit();\n        articulation_.shrink_to_fit();\n    }\n\
    \    \n    usize addEdge(u32 u, u32 v) {\n        usize res{m_++};\n        e_.emplace_back(u,\
    \ v);\n        g_[u].emplace_back(v, res);\n        g_[v].emplace_back(u, res);\n\
    \        return res;\n    }\n\n    const std::vector<std::pair<u32, u32>>& operator[](u32\
    \ v) const noexcept {\n        assert(v < size());\n        return g_[v];\n  \
    \  }\n    const std::pair<u32, u32>& edge(u32 i) const noexcept {\n        assert(i\
    \ < edgeSize());\n        return e_[i];\n    }\n\n    void build() {\n       \
    \ bridge_.resize(edgeSize());\n        u32 t{};\n        for (u32 v{} ; v < size()\
    \ ; v++) if (in_[v] == INVALID) {\n            dfs(v, INVALID, t);\n        }\n\
    \    }\n\n    bool articular(u32 v) const noexcept {\n        assert(v < size());\n\
    \        return articulation_[v] > 1u;\n    }\n    u32 cut(u32 v) const noexcept\
    \ {\n        assert(v < size());\n        return articulation_[v];\n    }\n  \
    \  bool bridge(u32 i) const noexcept {\n        assert(i < edgeSize());\n    \
    \    return bridge_[i];\n    }\n};\n\n} // namespace zawa\n#line 5 \"Test/AOJ/GRL_3_A.test.cpp\"\
    \n\nusing namespace zawa;\n\nint main() {\n    SetFastIO();\n    int n, m; std::cin\
    \ >> n >> m;\n    Lowlink g(n);\n    for (int _{} ; _ < m ; _++) {\n        int\
    \ s, t; std::cin >> s >> t;\n        g.addEdge(s, t);\n    }\n    g.build();\n\
    \    for (int i{} ; i < n ; i++) {\n        if (g.articular(i)) {\n          \
    \  std::cout << i << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A\"\
    \n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Graph/Components/Lowlink.hpp\"\
    \n\nusing namespace zawa;\n\nint main() {\n    SetFastIO();\n    int n, m; std::cin\
    \ >> n >> m;\n    Lowlink g(n);\n    for (int _{} ; _ < m ; _++) {\n        int\
    \ s, t; std::cin >> s >> t;\n        g.addEdge(s, t);\n    }\n    g.build();\n\
    \    for (int i{} ; i < n ; i++) {\n        if (g.articular(i)) {\n          \
    \  std::cout << i << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Components/Lowlink.hpp
  isVerificationFile: true
  path: Test/AOJ/GRL_3_A.test.cpp
  requiredBy: []
  timestamp: '2024-02-10 12:22:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/GRL_3_A.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/GRL_3_A.test.cpp
- /verify/Test/AOJ/GRL_3_A.test.cpp.html
title: Test/AOJ/GRL_3_A.test.cpp
---
