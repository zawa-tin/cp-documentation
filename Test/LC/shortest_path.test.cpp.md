---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/ShortestPath/Dijkstra.hpp
    title: Src/Graph/ShortestPath/Dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Graph/ShortestPath/Edge.hpp
    title: Src/Graph/ShortestPath/Edge.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Graph/ShortestPath/WeightedShortestPathTree.hpp
    title: Src/Graph/ShortestPath/WeightedShortestPathTree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"Test/LC/shortest_path.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\
    \n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Graph/ShortestPath/Dijkstra.hpp\"\n\n\
    #line 2 \"Src/Graph/ShortestPath/WeightedShortestPathTree.hpp\"\n\n#line 2 \"\
    Src/Graph/ShortestPath/Edge.hpp\"\n\n#line 4 \"Src/Graph/ShortestPath/Edge.hpp\"\
    \n\nnamespace zawa {\n\nnamespace internal {\n\nclass Edge {\nprotected:\n   \
    \ static constexpr u32 INVALID{static_cast<u32>(-1)};\npublic:\n    u32 parent{INVALID};\
    \ \n    u32 id{INVALID};\n    Edge() = default;\n    Edge(u32 parent, u32 id)\
    \ : parent{parent}, id{id} {}\n    Edge& operator=(const Edge& edge) {\n     \
    \   parent = edge.parent;\n        id = edge.id;\n        return *this;\n    }\n\
    \    inline bool exist() const noexcept {\n        return parent != INVALID;\n\
    \    }\n    static constexpr u32 invalid() noexcept {\n        return INVALID;\
    \ \n    }\n};\n\ntemplate <class Weight>\nclass WeightedEdge : public Edge {\n\
    public:\n    Weight weight{INVALID};\n    WeightedEdge() = default;\n    WeightedEdge(u32\
    \ parent, const Weight& weight, u32 id)\n        : Edge{parent, id}, weight{weight}\
    \ {}\n\n    WeightedEdge& operator=(const WeightedEdge& edge) {\n        parent\
    \ = edge.parent;\n        id = edge.id;\n        weight = edge.weight;\n     \
    \   return *this;\n    }\n\n};\n\n} // namespace internal\n\n} // namespace zawa\n\
    #line 5 \"Src/Graph/ShortestPath/WeightedShortestPathTree.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <type_traits>\n#include <vector>\n\nnamespace zawa\
    \ {\n\nnamespace internal {\n\ntemplate <class Weight>\nclass WeightedShortestPathTree\
    \ {\npublic:\n    static_assert(std::is_unsigned_v<Weight>, \"Dijkstra's Algorithm\
    \ only be work well by unsigned weight\");\n    using E = WeightedEdge<Weight>;\n\
    \    static constexpr u32 invalid() noexcept {\n        return E::invalid();\n\
    \    }\nprivate:\n    static constexpr u32 INVALID{E::invalid()};\n    usize n_;\n\
    \    u32 root_;\n    std::vector<E> tree_;\n    std::vector<Weight> dist_;\npublic:\n\
    \    WeightedShortestPathTree() = default;\n    WeightedShortestPathTree(u32 n,\
    \ u32 root) \n        : n_{n}, root_{root}, tree_(n), dist_(n, static_cast<Weight>(-1))\
    \ {\n        assert(root < n);\n        tree_.shrink_to_fit();\n        dist_.shrink_to_fit();\n\
    \        dist_[root] = Weight{};\n    }\n\n    inline usize size() const noexcept\
    \ {\n        return n_;\n    }\n    inline u32 root() const noexcept {\n     \
    \   return root_;\n    }\n    inline u32 parent(u32 v) const noexcept {\n    \
    \    assert(v < size());\n        return tree_[v].parent;\n    }\n    inline u32\
    \ id(u32 v) const noexcept {\n        assert(v < size());\n        return tree_[v].id;\n\
    \    }\n    inline bool connect(u32 v) const noexcept {\n        assert(v < size());\n\
    \        return v == root_ or tree_[v].exist();\n    }\n    inline const Weight&\
    \ dist(u32 v) const noexcept {\n        assert(v < size());\n        return dist_[v];\n\
    \    }\n\n    const Weight& operator[](u32 v) const noexcept {\n        assert(v\
    \ < size());\n        return dist_[v];\n    }\n\n    bool relax(u32 from, u32\
    \ to, const Weight& weight, u32 id) {\n        if (dist_[to] > dist_[from] + weight)\
    \ {\n            dist_[to] = dist_[from] + weight;\n            tree_[to].parent\
    \ = from;\n            tree_[to].id = id;\n            return true;\n        }\n\
    \        return false;\n    }\n\n    std::vector<u32> pathV(u32 v) {\n       \
    \ assert(v < size());\n        assert(connect(v));\n        std::vector<u32> res(1);\n\
    \        res[0] = v;\n        while (parent(v) != invalid()) {\n            v\
    \ = parent(v);\n            res.emplace_back(v);\n        }\n        std::reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n\n    std::vector<E> pathE(u32 v) {\n\
    \        assert(v < size());\n        assert(connect(v));\n        std::vector<E>\
    \ res;\n        while (v != root()) {\n            res.emplace_back(tree_[v]);\n\
    \            v = parent(v);\n        }\n        std::reverse(res.begin(), res.end());\n\
    \        return res;\n    }\n};\n\n} // namespace internal\n\n} // namespace zawa\n\
    #line 5 \"Src/Graph/ShortestPath/Dijkstra.hpp\"\n\n#line 7 \"Src/Graph/ShortestPath/Dijkstra.hpp\"\
    \n#include <queue>\n#include <tuple>\n#include <utility>\n#line 11 \"Src/Graph/ShortestPath/Dijkstra.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class Weight>\nclass Dijkstra {\npublic:\n \
    \   using ShortestPathTree = internal::WeightedShortestPathTree<Weight>;\nprivate:\n\
    \    usize n_;\n    std::vector<std::vector<std::tuple<u32, Weight, u32>>> adj_;\n\
    \n    static constexpr u32 invalid() noexcept {\n        return ShortestPathTree::invalid();\n\
    \    }\n\npublic:\n    Dijkstra() = default;\n    Dijkstra(usize n) : n_{n}, adj_(n)\
    \ {\n        adj_.shrink_to_fit();\n    }\n    usize size() const noexcept {\n\
    \        return n_;\n    }\n    Dijkstra(const std::vector<std::pair<u32, Weight>>&\
    \ g) : n_{g.size()}, adj_(g.size()) {\n        adj_.shrink_to_fit();\n       \
    \ for (u32 v{} ; v < size() ; v++) {\n            for (auto [x, w] : g[v]) {\n\
    \                adj_[v].emplace_back(x, w, invalid);\n            }\n       \
    \ }\n    }\n    void addDirectedEdge(u32 from, u32 to, const Weight& weight, u32\
    \ id = invalid()) {\n        assert(from < size());\n        assert(to < size());\n\
    \        adj_[from].emplace_back(to, weight, id);\n    }\n    void addUndirectedEdge(u32\
    \ u, u32 v, const Weight& weight, u32 id = invalid()) {\n        assert(u < size());\n\
    \        assert(v < size());\n        adj_[u].emplace_back(v, weight, id);\n \
    \       adj_[v].emplace_back(u, weight, id);\n    }\n\n    ShortestPathTree build(u32\
    \ start) {\n        using QueueData = std::pair<Weight, u32>;\n        std::priority_queue<QueueData,\
    \ std::vector<QueueData>, std::greater<QueueData>> queue;\n        queue.emplace(Weight{},\
    \ start);\n        ShortestPathTree res(n_, start);\n        while (queue.size())\
    \ {\n            auto [w, v]{queue.top()};\n            queue.pop();\n       \
    \     if (res.dist(v) < w) {\n                continue;\n            }\n     \
    \       for (auto [x, w, id] : adj_[v]) {\n                if (res.relax(v, x,\
    \ w, id)) {\n                    queue.emplace(res.dist(x), x);\n            \
    \    }\n            } \n        }\n        return res;\n    }\n};\n\n} // namespace\
    \ zawa\n#line 5 \"Test/LC/shortest_path.test.cpp\"\n\nint main() {\n    using\
    \ namespace zawa;\n    SetFastIO();\n    int n, m, s, t; std::cin >> n >> m >>\
    \ s >> t;\n    Dijkstra<u64> solver(n);\n    for (int _{} ; _ < m ; _++) {\n \
    \       int a, b, c; std::cin >> a >> b >> c;\n        solver.addDirectedEdge(a,\
    \ b, (u64)c);\n    }\n    auto tree{solver.build(s)};\n    if (tree.connect(t))\
    \ {\n        auto recover{tree.pathV(t)};\n        std::cout << tree.dist(t) <<\
    \ ' ' << recover.size() - 1 << '\\n';\n        for (u32 i{} ; i + 1 < recover.size()\
    \ ; i++) {\n            std::cout << recover[i] << ' ' << recover[i + 1] << '\\\
    n';\n        }\n    }\n    else {\n        std::cout << -1 << '\\n';\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Graph/ShortestPath/Dijkstra.hpp\"\
    \n\nint main() {\n    using namespace zawa;\n    SetFastIO();\n    int n, m, s,\
    \ t; std::cin >> n >> m >> s >> t;\n    Dijkstra<u64> solver(n);\n    for (int\
    \ _{} ; _ < m ; _++) {\n        int a, b, c; std::cin >> a >> b >> c;\n      \
    \  solver.addDirectedEdge(a, b, (u64)c);\n    }\n    auto tree{solver.build(s)};\n\
    \    if (tree.connect(t)) {\n        auto recover{tree.pathV(t)};\n        std::cout\
    \ << tree.dist(t) << ' ' << recover.size() - 1 << '\\n';\n        for (u32 i{}\
    \ ; i + 1 < recover.size() ; i++) {\n            std::cout << recover[i] << '\
    \ ' << recover[i + 1] << '\\n';\n        }\n    }\n    else {\n        std::cout\
    \ << -1 << '\\n';\n    }\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/ShortestPath/Dijkstra.hpp
  - Src/Graph/ShortestPath/WeightedShortestPathTree.hpp
  - Src/Graph/ShortestPath/Edge.hpp
  isVerificationFile: true
  path: Test/LC/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2023-12-14 22:32:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/shortest_path.test.cpp
- /verify/Test/LC/shortest_path.test.cpp.html
title: Test/LC/shortest_path.test.cpp
---