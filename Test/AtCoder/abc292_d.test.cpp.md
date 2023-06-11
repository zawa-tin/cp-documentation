---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Basis/AdjacentList.hpp
    title: "\u30B0\u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/ConnectedComponents.hpp
    title: "\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3"
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
    PROBLEM: https://atcoder.jp/contests/abc292/tasks/abc292_d
    links:
    - https://atcoder.jp/contests/abc292/tasks/abc292_d
  bundledCode: "#line 1 \"Test/AtCoder/abc292_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc292/tasks/abc292_d\"\
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
    \    usize n, m;\n    std::vector<E> edges;\n    std::vector<std::vector<E>> g;\n\
    \npublic:\n    AdjacentList() = default;\n    AdjacentList(usize n_) : n{ n_ },\
    \ m{}, g(n_) {}\n\n    void addDirectedEdge(u32 from, u32 to, const CostType&\
    \ weight = 1) {\n        edges.emplace_back(from, to, weight, m);\n        g[from].emplace_back(from,\
    \ to, weight, m++);\n    }\n\n    void addUndirectedEdge(u32 u, u32 v, const CostType&\
    \ weight = 1) {\n        edges.emplace_back(u, v, weight, m);\n        g[u].emplace_back(u,\
    \ v, weight, m);\n        g[v].emplace_back(v, u, weight, m++);\n    }\n\n   \
    \ inline std::vector<E> operator[](u32 v) {\n        assert(v < n);\n        return\
    \ g[v];\n    }\n\n    inline const std::vector<E>& operator[](u32 v) const {\n\
    \        assert(v < n);\n        return g[v];\n    }\n\n    inline usize sizeV()\
    \ const {\n        return n;\n    }\n\n    inline usize sizeE() const {\n    \
    \    return m;\n    }\n\n    inline std::vector<E> enumerateEdges() const {\n\
    \        return edges;\n    }\n\n    inline E getEdge(u32 i) const {\n       \
    \ assert(i < m);\n        return edges[i];\n    }\n};\n\ntemplate <class CostType>\n\
    using Graph = AdjacentList<CostType>;\n\n} // namespace zawa\n#line 2 \"Src/Graph/ConnectedComponents.hpp\"\
    \n\n#line 5 \"Src/Graph/ConnectedComponents.hpp\"\n\n#line 8 \"Src/Graph/ConnectedComponents.hpp\"\
    \n#include <limits>\n#include <algorithm>\n#include <utility>\n#include <stack>\n\
    \nnamespace zawa {\n\ntemplate <class CostType = u32>\nclass ConnectedComponents\
    \ {\nprivate:\n    Graph<CostType> graph;\n    std::vector<u32> id;\n    usize\
    \ countComponents;\n\n    std::vector<std::vector<u32>> componentsV, componentsE;\n\
    \n\npublic:\n    ConnectedComponents() = default;\n    ConnectedComponents(const\
    \ Graph<CostType>& graph_) \n        : graph(graph_), id(graph_.sizeV()), countComponents{},\
    \ componentsV{}, componentsE{} {\n\n        const u32 inf = std::numeric_limits<u32>::max();\n\
    \n        std::fill(id.begin(), id.end(), inf);\n        id.shrink_to_fit();\n\
    \n\n        auto search = [&](u32 s) -> void {\n            std::stack<std::pair<u32,\
    \ u32>> stk;\n            stk.push({ s, inf }); \n            while (stk.size())\
    \ {\n                auto [v, eid] = stk.top();\n                stk.pop();\n\
    \                id[v] = countComponents;\n                for (const auto& e\
    \ : graph[v]) {\n                    if (id[e.to] == inf) {\n                \
    \        stk.push({ e.to, e.id });\n                    }\n                }\n\
    \            }\n        };\n\n        for (u32 i = 0 ; i < graph.sizeV() ; i++)\
    \ {\n            if (id[i] < inf) continue;\n            search(i);\n        \
    \    countComponents++;\n        }\n\n        componentsV.resize(countComponents);\n\
    \        for (u32 i = 0 ; i < graph.sizeV() ; i++) {\n            componentsV[id[i]].push_back(i);\n\
    \        }\n        componentsV.shrink_to_fit();\n        for (auto& comp : componentsV)\
    \ {\n            comp.shrink_to_fit();\n        }\n\n        componentsE.resize(countComponents);\n\
    \        for (u32 i = 0 ; i < graph.sizeE() ; i++) {\n            componentsE[id[graph.getEdge(i).from]].push_back(i);\n\
    \        }\n        componentsE.shrink_to_fit();\n        for (auto& comp : componentsE)\
    \ {\n            comp.shrink_to_fit();\n        }\n    }\n\n    inline usize size()\
    \ const {\n        return countComponents;\n    }\n\n    inline usize sizeV(u32\
    \ i) const {\n        assert(i < countComponents);\n        return componentsV[i].size();\n\
    \    }\n\n    inline usize sizeE(u32 i) const {\n        assert(i < countComponents);\n\
    \        return componentsE[i].size();\n    }\n\n    inline u32 operator[](u32\
    \ v) const {\n        assert(v < graph.sizeV());\n        return id[v];\n    }\n\
    \n    inline u32 getVId(u32 v) const {\n        assert(v < graph.sizeV());\n \
    \       return id[v];\n    }   \n\n    inline u32 getEId(u32 v) const {\n    \
    \    assert(v < graph.sizeE());\n        return id[graph.getEdge(v).from];\n \
    \   }   \n\n    inline bool same(u32 u, u32 v) const {\n        assert(u < graph.sizeV());\n\
    \        assert(v < graph.sizeV());\n        return id[u] == id[v];\n    }\n\n\
    \    inline std::vector<std::vector<u32>> enumerateV() const {\n        return\
    \ componentsV;\n    }\n\n    inline std::vector<u32> enumerateV(u32 i) const {\n\
    \        assert(i < countComponents);\n        return componentsV[i];\n    }\n\
    \n    inline std::vector<std::vector<Edge<CostType>>> enumerateE() const {\n \
    \       std::vector res(countComponents, std::vector<Edge<CostType>>());\n   \
    \     for (u32 i = 0 ; i < countComponents ; i++) {\n            for (auto eid\
    \ : componentsE[i]) {\n                res[i].push_back(graph.getEdge(eid));\n\
    \            }\n        }\n        return res;\n    }\n\n    inline std::vector<Edge<CostType>>\
    \ enumerateE(u32 i) const {\n        assert(i < countComponents);\n        std::vector<CostType>\
    \ res(componentsE[i].size());\n        for (u32 j = 0 ; j < componentsE[i].size()\
    \ ; j++) {\n            res[j] = graph.getEdge(componentsE[i][j]);\n        }\n\
    \        return res;\n    }\n\n    inline bool hasCycle(u32 i) const {\n     \
    \   assert(i < countComponents);\n        return sizeE(i) + 1 > sizeV(i);\n  \
    \  }\n};\n\n} // namespace zawa\n#line 6 \"Test/AtCoder/abc292_d.test.cpp\"\n\n\
    #include <iostream>\n\nusing namespace zawa;\n\nint main() {\n    usize N, M;\n\
    \    std::cin >> N >> M;\n    Graph<u32> G(N);\n    for (u32 _ = 0 ; _ < M ; _++)\
    \ {\n        u32 u, v;\n        std::cin >> u >> v;\n        u--; v--;\n     \
    \   G.addUndirectedEdge(u, v);\n    }\n\n    ConnectedComponents cc(G);\n\n  \
    \  bool ans = true;\n    for (u32 i = 0 ; i < cc.size() ; i++) {\n        ans\
    \ &= cc.sizeV(i) == cc.sizeE(i);\n    }\n\n    std::cout << (ans ? \"Yes\" : \"\
    No\") << std::endl;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc292/tasks/abc292_d\"\n\n\
    #include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Graph/Basis/AdjacentList.hpp\"\
    \n#include \"../../Src/Graph/ConnectedComponents.hpp\"\n\n#include <iostream>\n\
    \nusing namespace zawa;\n\nint main() {\n    usize N, M;\n    std::cin >> N >>\
    \ M;\n    Graph<u32> G(N);\n    for (u32 _ = 0 ; _ < M ; _++) {\n        u32 u,\
    \ v;\n        std::cin >> u >> v;\n        u--; v--;\n        G.addUndirectedEdge(u,\
    \ v);\n    }\n\n    ConnectedComponents cc(G);\n\n    bool ans = true;\n    for\
    \ (u32 i = 0 ; i < cc.size() ; i++) {\n        ans &= cc.sizeV(i) == cc.sizeE(i);\n\
    \    }\n\n    std::cout << (ans ? \"Yes\" : \"No\") << std::endl;\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Basis/AdjacentList.hpp
  - Src/Graph/ConnectedComponents.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc292_d.test.cpp
  requiredBy: []
  timestamp: '2023-06-11 23:05:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc292_d.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc292_d.test.cpp
- /verify/Test/AtCoder/abc292_d.test.cpp.html
title: Test/AtCoder/abc292_d.test.cpp
---
