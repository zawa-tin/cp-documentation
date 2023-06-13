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
    PROBLEM: https://atcoder.jp/contests/abc288/tasks/abc288_c
    links:
    - https://atcoder.jp/contests/abc288/tasks/abc288_c
  bundledCode: "#line 1 \"Test/AtCoder/abc288_c.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc288/tasks/abc288_c\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Graph/Basis/AdjacentList.hpp\"\
    \n\n#line 4 \"Src/Graph/Basis/AdjacentList.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n\nnamespace zawa {\n\ntemplate <class CostType>\nclass Edge {\nprivate:\n\
    \    u32 from_, to_;\n    CostType weight_;\n    u32 id_;\n\npublic:\n    Edge()\
    \ = default;\n    Edge(u32 from, u32 to, const CostType& weight, u32 id)\n   \
    \     : from_{ from }, to_{ to }, weight_{ weight }, id_{ id } {}\n\n    inline\
    \ u32 from() const noexcept {\n        return from_;\n    }\n\n    inline u32\
    \ to() const noexcept {\n        return to_;\n    }\n\n    inline CostType weight()\
    \ const {\n        return weight_;\n    }\n\n    inline u32 id() const noexcept\
    \ {\n        return id_;\n    }\n\n};\n\ntemplate <class CostType>\nclass AdjacentList\
    \ {\nprivate:\n    using E = Edge<CostType>;\n\n    usize n_, m_;\n    std::vector<E>\
    \ edges_;\n    std::vector<std::vector<E>> g_;\n\npublic:\n    AdjacentList()\
    \ = default;\n    AdjacentList(usize n) : n_{ n }, m_{}, g_(n) {}\n\n    void\
    \ addDirectedEdge(u32 from, u32 to, const CostType& weight = 1) {\n        edges_.emplace_back(from,\
    \ to, weight, m_);\n        g_[from].emplace_back(from, to, weight, m_++);\n \
    \   }\n\n    void addUndirectedEdge(u32 u, u32 v, const CostType& weight = 1)\
    \ {\n        edges_.emplace_back(u, v, weight, m_);\n        g_[u].emplace_back(u,\
    \ v, weight, m_);\n        g_[v].emplace_back(v, u, weight, m_++);\n    }\n\n\
    \    inline std::vector<E> operator[](u32 v) {\n        assert(v < n_);\n    \
    \    return g_[v];\n    }\n\n    inline const std::vector<E>& operator[](u32 v)\
    \ const {\n        assert(v < n_);\n        return g_[v];\n    }\n\n    inline\
    \ usize sizeV() const noexcept {\n        return n_;\n    }\n\n    inline usize\
    \ sizeE() const noexcept {\n        return m_;\n    }\n\n    inline std::vector<E>\
    \ enumerateEdges() const {\n        return edges_;\n    }\n\n    inline E getEdge(u32\
    \ i) const {\n        assert(i < m_);\n        return edges_[i];\n    }\n};\n\n\
    template <class CostType>\nusing Graph = AdjacentList<CostType>;\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Graph/ConnectedComponents.hpp\"\n\n#line 5 \"Src/Graph/ConnectedComponents.hpp\"\
    \n\n#line 8 \"Src/Graph/ConnectedComponents.hpp\"\n#include <limits>\n#include\
    \ <algorithm>\n#include <utility>\n#include <stack>\n\nnamespace zawa {\n\ntemplate\
    \ <class CostType = u32>\nclass ConnectedComponents {\nprivate:\n    Graph<CostType>\
    \ graph_;\n    std::vector<u32> id_;\n    usize countComponents_;\n\n    std::vector<std::vector<u32>>\
    \ componentsV_, componentsE_;\n\n\npublic:\n    ConnectedComponents() = default;\n\
    \    ConnectedComponents(const Graph<CostType>& graph) \n        : graph_(graph),\
    \ id_(graph.sizeV()), countComponents_{}, componentsV_{}, componentsE_{} {\n\n\
    \        const u32 inf = std::numeric_limits<u32>::max();\n\n        std::fill(id_.begin(),\
    \ id_.end(), inf);\n        id_.shrink_to_fit();\n\n\n        auto search = [&](u32\
    \ s) -> void {\n            std::stack<std::pair<u32, u32>> stk;\n           \
    \ stk.push({ s, inf }); \n            while (stk.size()) {\n                auto\
    \ [v, eid] = stk.top();\n                stk.pop();\n                id_[v] =\
    \ countComponents_;\n                for (const auto& e : graph_[v]) {\n     \
    \               if (id_[e.to()] == inf) {\n                        stk.push({\
    \ e.to(), e.id() });\n                    }\n                }\n            }\n\
    \        };\n\n        for (u32 i = 0 ; i < graph_.sizeV() ; i++) {\n        \
    \    if (id_[i] < inf) continue;\n            search(i);\n            countComponents_++;\n\
    \        }\n\n        componentsV_.resize(countComponents_);\n        for (u32\
    \ i = 0 ; i < graph_.sizeV() ; i++) {\n            componentsV_[id_[i]].push_back(i);\n\
    \        }\n        componentsV_.shrink_to_fit();\n        for (auto& comp : componentsV_)\
    \ {\n            comp.shrink_to_fit();\n        }\n\n        componentsE_.resize(countComponents_);\n\
    \        for (u32 i = 0 ; i < graph_.sizeE() ; i++) {\n            componentsE_[id_[graph_.getEdge(i).from()]].push_back(i);\n\
    \        }\n        componentsE_.shrink_to_fit();\n        for (auto& comp : componentsE_)\
    \ {\n            comp.shrink_to_fit();\n        }\n    }\n\n    inline usize size()\
    \ const {\n        return countComponents_;\n    }\n\n    inline usize sizeV(u32\
    \ i) const {\n        assert(i < countComponents_);\n        return componentsV_[i].size();\n\
    \    }\n\n    inline usize sizeE(u32 i) const {\n        assert(i < countComponents_);\n\
    \        return componentsE_[i].size();\n    }\n\n    inline u32 operator[](u32\
    \ v) const {\n        assert(v < graph_.sizeV());\n        return id_[v];\n  \
    \  }\n\n    inline u32 getVId(u32 v) const {\n        assert(v < graph_.sizeV());\n\
    \        return id_[v];\n    }   \n\n    inline u32 getEId(u32 v) const {\n  \
    \      assert(v < graph_.sizeE());\n        return id_[graph_.getEdge(v).from()];\n\
    \    }   \n\n    inline bool same(u32 u, u32 v) const {\n        assert(u < graph_.sizeV());\n\
    \        assert(v < graph_.sizeV());\n        return id_[u] == id_[v];\n    }\n\
    \n    inline std::vector<std::vector<u32>> enumerateV() const {\n        return\
    \ componentsV_;\n    }\n\n    inline std::vector<u32> enumerateV(u32 i) const\
    \ {\n        assert(i < countComponents_);\n        return componentsV_[i];\n\
    \    }\n\n    inline std::vector<std::vector<Edge<CostType>>> enumerateE() const\
    \ {\n        std::vector res(countComponents_, std::vector<Edge<CostType>>());\n\
    \        for (u32 i = 0 ; i < countComponents_ ; i++) {\n            for (auto\
    \ eid_ : componentsE_[i]) {\n                res[i].push_back(graph_.getEdge(eid_));\n\
    \            }\n        }\n        return res;\n    }\n\n    inline std::vector<Edge<CostType>>\
    \ enumerateE(u32 i) const {\n        assert(i < countComponents_);\n        std::vector<CostType>\
    \ res(componentsE_[i].size());\n        for (u32 j = 0 ; j < componentsE_[i].size()\
    \ ; j++) {\n            res[j] = graph_.getEdge(componentsE_[i][j]);\n       \
    \ }\n        return res;\n    }\n\n    inline bool hasCycle(u32 i) const {\n \
    \       assert(i < countComponents_);\n        return sizeE(i) + 1 > sizeV(i);\n\
    \    }\n};\n\n} // namespace zawa\n#line 6 \"Test/AtCoder/abc288_c.test.cpp\"\n\
    \n#include <iostream>\n#line 9 \"Test/AtCoder/abc288_c.test.cpp\"\n\nusing namespace\
    \ zawa;\n\nint main() {\n    usize N, M;\n    std::cin >> N >> M;\n    Graph<u32>\
    \ G(N);\n    for (u32 _ = 0 ; _ < M ; _++) {\n        u32 u, v;\n        std::cin\
    \ >> u >> v;\n        u--; v--;\n        G.addUndirectedEdge(u, v);\n    }\n\n\
    \    ConnectedComponents cc(G);\n\n    u32 ans{};\n    for (u32 i = 0 ; i < cc.size()\
    \ ; i++) {\n        ans += cc.sizeE(i) - cc.sizeV(i) + 1;\n    }\n\n    std::cout\
    \ << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc288/tasks/abc288_c\"\n\n\
    #include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Graph/Basis/AdjacentList.hpp\"\
    \n#include \"../../Src/Graph/ConnectedComponents.hpp\"\n\n#include <iostream>\n\
    #include <cassert>\n\nusing namespace zawa;\n\nint main() {\n    usize N, M;\n\
    \    std::cin >> N >> M;\n    Graph<u32> G(N);\n    for (u32 _ = 0 ; _ < M ; _++)\
    \ {\n        u32 u, v;\n        std::cin >> u >> v;\n        u--; v--;\n     \
    \   G.addUndirectedEdge(u, v);\n    }\n\n    ConnectedComponents cc(G);\n\n  \
    \  u32 ans{};\n    for (u32 i = 0 ; i < cc.size() ; i++) {\n        ans += cc.sizeE(i)\
    \ - cc.sizeV(i) + 1;\n    }\n\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Basis/AdjacentList.hpp
  - Src/Graph/ConnectedComponents.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc288_c.test.cpp
  requiredBy: []
  timestamp: '2023-06-13 11:49:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc288_c.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc288_c.test.cpp
- /verify/Test/AtCoder/abc288_c.test.cpp.html
title: Test/AtCoder/abc288_c.test.cpp
---
