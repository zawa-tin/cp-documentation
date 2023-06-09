---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Basis/AdjacentList.hpp
    title: "\u30B0\u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_B
  bundledCode: "#line 1 \"Test/AOJ/ALDS1_11_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_B\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Graph/Basis/AdjacentList.hpp\"\
    \n\n#line 4 \"Src/Graph/Basis/AdjacentList.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n\nnamespace zawa {\n\ntemplate <class CostType>\nstruct Edge {\n\
    \    u32 from, to;\n    CostType weight;\n    u32 id;\n\n    Edge() = default;\n\
    \    Edge(u32 from_, u32 to_, const CostType& weight_, u32 id = -1)\n        :\
    \ from{ from_ }, to{ to_ }, weight{ weight_ }, id{ id } {}\n};\n\ntemplate <class\
    \ CostType>\nclass AdjacentList {\nprivate:\n    using E = Edge<CostType>;\n\n\
    \    usize N, M;\n    std::vector<std::vector<E>> G;\n\npublic:\n    AdjacentList()\
    \ = default;\n    AdjacentList(usize N) : N{ N }, M{ 0 }, G(N) {}\n\n    void\
    \ addDirectedEdge(u32 from, u32 to, const CostType& weight = 1) {\n        G[from].emplace_back(from,\
    \ to, weight, M++);\n    }\n\n    void addUndirectedEdge(u32 u, u32 v, const CostType&\
    \ weight = 1) {\n        G[u].emplace_back(u, v, weight, M);\n        G[v].emplace_back(v,\
    \ u, weight, M++);\n    }\n\n    inline std::vector<E> operator[](u32 v) {\n \
    \       assert(v < N);\n        return G[v];\n    }\n\n    inline const std::vector<E>&\
    \ operator[](u32 v) const {\n        assert(v < N);\n        return G[v];\n  \
    \  }\n\n    inline usize sizeV() const {\n        return N;\n    }\n\n    inline\
    \ usize sizeE() const {\n        return M;\n    }\n};\n\ntemplate <class CostType>\n\
    using Graph = AdjacentList<CostType>;\n\n} // namespace zawa\n#line 5 \"Test/AOJ/ALDS1_11_B.test.cpp\"\
    \n\n#include <iostream>\n#line 9 \"Test/AOJ/ALDS1_11_B.test.cpp\"\n\nusing namespace\
    \ zawa;\n\nint main() {\n    usize N;\n    std::cin >> N;\n    Graph<u16> G(N);\n\
    \    for (usize i = 0 ; i < N ; i++) {\n        u32 u, k;\n        std::cin >>\
    \ u >> k;\n        for (u32 j = 0 ; j < k ; j++) {\n            u32 v;\n     \
    \       std::cin >> v;\n            G.addDirectedEdge(u - 1, v - 1);\n       \
    \ }\n    }\n\n    for (u32 i = 0 ; i < N ; i++) {\n        for (const auto& e\
    \ : G[i]) \n            assert(i == e.from);\n    }\n\n    std::vector<bool> visited(N);\n\
    \    std::vector<u32> d(N), f(N);\n    u32 time = 0;\n\n    auto dfs = [&](auto\
    \ dfs, u32 v) -> void {\n        visited[v] = true;\n        d[v] = ++time;\n\
    \        for (const auto& e : G[v]) if (!visited[e.to])\n            dfs(dfs,\
    \ e.to);\n        f[v] = ++time;\n    };\n\n    for (u32 i = 0 ; i < N ; i++)\
    \ if (!visited[i]) \n        dfs(dfs, i);\n\n\n    for (u32 i = 0 ; i < N ; i++)\
    \ {\n        std::cout << i + 1 << ' ' << d[i] << ' ' << f[i] << std::endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_B\"\n\
    \n#include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Graph/Basis/AdjacentList.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n#include <cassert>\n\nusing namespace\
    \ zawa;\n\nint main() {\n    usize N;\n    std::cin >> N;\n    Graph<u16> G(N);\n\
    \    for (usize i = 0 ; i < N ; i++) {\n        u32 u, k;\n        std::cin >>\
    \ u >> k;\n        for (u32 j = 0 ; j < k ; j++) {\n            u32 v;\n     \
    \       std::cin >> v;\n            G.addDirectedEdge(u - 1, v - 1);\n       \
    \ }\n    }\n\n    for (u32 i = 0 ; i < N ; i++) {\n        for (const auto& e\
    \ : G[i]) \n            assert(i == e.from);\n    }\n\n    std::vector<bool> visited(N);\n\
    \    std::vector<u32> d(N), f(N);\n    u32 time = 0;\n\n    auto dfs = [&](auto\
    \ dfs, u32 v) -> void {\n        visited[v] = true;\n        d[v] = ++time;\n\
    \        for (const auto& e : G[v]) if (!visited[e.to])\n            dfs(dfs,\
    \ e.to);\n        f[v] = ++time;\n    };\n\n    for (u32 i = 0 ; i < N ; i++)\
    \ if (!visited[i]) \n        dfs(dfs, i);\n\n\n    for (u32 i = 0 ; i < N ; i++)\
    \ {\n        std::cout << i + 1 << ' ' << d[i] << ' ' << f[i] << std::endl;\n\
    \    }\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Basis/AdjacentList.hpp
  isVerificationFile: true
  path: Test/AOJ/ALDS1_11_B.test.cpp
  requiredBy: []
  timestamp: '2023-06-09 17:43:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/ALDS1_11_B.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/ALDS1_11_B.test.cpp
- /verify/Test/AOJ/ALDS1_11_B.test.cpp.html
title: Test/AOJ/ALDS1_11_B.test.cpp
---
