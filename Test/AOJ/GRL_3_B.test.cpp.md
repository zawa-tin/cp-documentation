---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Components/Lowlink.hpp
    title: "Lowlink (\u6A4B\u30FB\u95A2\u7BC0\u70B9)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B
  bundledCode: "#line 1 \"Test/AOJ/GRL_3_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B\"\
    \n\n#line 2 \"Src/Graph/Components/Lowlink.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Components/Lowlink.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ zawa {\n\nclass Lowlink {\npublic:\n\n    using V = usize;\n\n    using ID =\
    \ usize;\n\nprivate:\n\n    class LowlinkResponse {\n    public:\n\n        LowlinkResponse()\
    \ = default;\n\n        LowlinkResponse(std::vector<u32>&& articulation, std::vector<bool>&&\
    \ bridge)\n            : articulation_{std::move(articulation)}, bridge_{std::move(bridge)}\
    \ {}\n\n        inline bool isArticulation(V v) const {\n            assert(v\
    \ < articulation_.size());\n            return articulation_[v] > 1u;\n      \
    \  }\n\n        inline u32 cut(V v) const {\n            assert(v < articulation_.size());\n\
    \            return articulation_[v];\n        }\n\n        inline bool isBridge(ID\
    \ i) const {\n            assert(i < bridge_.size());\n            return bridge_[i];\n\
    \        }\n\n    private:\n\n        std::vector<u32> articulation_;\n\n    \
    \    std::vector<bool> bridge_;\n\n    };\n\n    static constexpr usize INVALID{static_cast<usize>(-1)};\n\
    \n    usize n_{}, m_{};\n\n    std::vector<std::vector<std::pair<V, ID>>> g_;\n\
    \n    std::vector<std::pair<V, V>> e_;\n\n    void dfs(V v, V p, u32& t, std::vector<u32>&\
    \ articulation, \n            std::vector<bool>& bridge, std::vector<usize>& in,\
    \ std::vector<usize>& low) const {\n        low[v] = in[v] = t++;\n        u32\
    \ deg{}; \n        for (const auto& [x, i] : g_[v]) {\n            if (in[x] ==\
    \ INVALID) {\n                deg++;\n                dfs(x, v, t, articulation,\
    \ bridge, in, low);\n                low[v] = std::min(low[v], low[x]);\n    \
    \            if (p != INVALID and low[x] >= in[v]) {\n                    articulation[v]++;\n\
    \                }\n                if (low[x] > in[v]) {\n                  \
    \  bridge[i] = true;\n                }\n            }\n            else if (x\
    \ != p) {\n                low[v] = std::min(low[v], in[x]);\n            }\n\
    \        }\n        if (p == INVALID) {\n            articulation[v] = deg;\n\
    \        }\n    }\n\npublic:\n\n    constexpr usize size() const noexcept {\n\
    \        return n_;\n    }\n\n    constexpr usize edgeSize() const noexcept {\n\
    \        return m_;\n    }\n\n    Lowlink() = default;\n\n    explicit Lowlink(usize\
    \ n) \n        : n_{n}, m_{}, g_(n) {\n        g_.shrink_to_fit();\n    }\n  \
    \  \n    ID addEdge(V u, V v) {\n        ID res{m_++};\n        e_.emplace_back(u,\
    \ v);\n        g_[u].emplace_back(v, res);\n        g_[v].emplace_back(u, res);\n\
    \        return res;\n    }\n\n    const std::vector<std::pair<V, ID>>& operator[](V\
    \ v) const noexcept {\n        assert(v < size());\n        return g_[v];\n  \
    \  }\n    const std::pair<V, V>& edge(ID i) const noexcept {\n        assert(i\
    \ < edgeSize());\n        return e_[i];\n    }\n\n    LowlinkResponse build()\
    \ const {\n        u32 t{};\n        std::vector<u32> articulation(size(), 1u);\n\
    \        std::vector<usize> in(size(), INVALID), low(size());\n        std::vector<bool>\
    \ bridge(edgeSize());\n        for (u32 v{} ; v < size() ; v++) if (in[v] == INVALID)\
    \ {\n            dfs(v, INVALID, t, articulation, bridge, in, low);\n        }\n\
    \        return LowlinkResponse{ std::move(articulation), std::move(bridge) };\n\
    \    }\n\n};\n\n} // namespace zawa\n#line 4 \"Test/AOJ/GRL_3_B.test.cpp\"\n\n\
    #line 6 \"Test/AOJ/GRL_3_B.test.cpp\"\n#include <iostream>\n#line 9 \"Test/AOJ/GRL_3_B.test.cpp\"\
    \n\nusing namespace zawa;\n\nint main() {\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n, m; \n    std::cin >> n >> m;\n\
    \    Lowlink g(n);\n    for (int _{} ; _ < m ; _++) {\n        int s, t; \n  \
    \      std::cin >> s >> t;\n        g.addEdge(s, t);\n    }\n    auto info{g.build()};\n\
    \    std::vector<std::pair<int, int>> ans;\n    for (int i{} ; i < m ; i++) {\n\
    \        if (info.isBridge(i)) {\n            auto [u, v]{g.edge(i)};\n      \
    \      ans.emplace_back(std::min(u, v), std::max(u, v));\n        }\n    }\n \
    \   std::sort(ans.begin(), ans.end());\n    for (auto [u, v] : ans) {\n      \
    \  std::cout << u << ' ' << v << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B\"\
    \n\n#include \"../../Src/Graph/Components/Lowlink.hpp\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <utility>\n#include <vector>\n\nusing namespace\
    \ zawa;\n\nint main() {\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n, m; \n    std::cin >> n >> m;\n\
    \    Lowlink g(n);\n    for (int _{} ; _ < m ; _++) {\n        int s, t; \n  \
    \      std::cin >> s >> t;\n        g.addEdge(s, t);\n    }\n    auto info{g.build()};\n\
    \    std::vector<std::pair<int, int>> ans;\n    for (int i{} ; i < m ; i++) {\n\
    \        if (info.isBridge(i)) {\n            auto [u, v]{g.edge(i)};\n      \
    \      ans.emplace_back(std::min(u, v), std::max(u, v));\n        }\n    }\n \
    \   std::sort(ans.begin(), ans.end());\n    for (auto [u, v] : ans) {\n      \
    \  std::cout << u << ' ' << v << '\\n';\n    }\n}\n"
  dependsOn:
  - Src/Graph/Components/Lowlink.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AOJ/GRL_3_B.test.cpp
  requiredBy: []
  timestamp: '2025-06-09 10:00:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/GRL_3_B.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/GRL_3_B.test.cpp
- /verify/Test/AOJ/GRL_3_B.test.cpp.html
title: Test/AOJ/GRL_3_B.test.cpp
---
