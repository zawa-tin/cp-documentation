---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/ShortestPath/BFS.hpp
    title: Src/Graph/ShortestPath/BFS.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Graph/ShortestPath/ShortestPathTree.hpp
    title: Src/Graph/ShortestPath/ShortestPathTree.hpp
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
    - https://atcoder.jp/contests/abc271/submissions/48487470
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/Manual/abc271_d.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Graph/ShortestPath/BFS.hpp\"\n\n#line\
    \ 2 \"Src/Graph/ShortestPath/ShortestPathTree.hpp\"\n\n#line 4 \"Src/Graph/ShortestPath/ShortestPathTree.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace zawa\
    \ {\n\nnamespace internal {\n\nclass Edge {\nprotected:\n    static constexpr\
    \ u32 INVALID{static_cast<u32>(-1)};\npublic:\n    u32 parent{INVALID}; \n   \
    \ u32 id{INVALID};\n    Edge() = default;\n    Edge(u32 parent, u32 id) : parent{parent},\
    \ id{id} {}\n    Edge& operator=(const Edge& edge) {\n        parent = edge.parent;\n\
    \        id = edge.id;\n        return *this;\n    }\n    inline bool exist()\
    \ const noexcept {\n        return parent != INVALID;\n    }\n    static constexpr\
    \ u32 invalid() noexcept {\n        return INVALID; \n    }\n};\n\nclass ShortestPathTree\
    \ {\npublic:\n    using E = internal::Edge;\n    static constexpr u32 invalid()\
    \ noexcept {\n        return E::invalid();\n    }\nprotected:\n    static constexpr\
    \ u32 INVALID{E::invalid()};\n    usize n_;\n    u32 root_;\n    std::vector<E>\
    \ tree_;\n    std::vector<u32> dist_;\npublic:\n    ShortestPathTree() = default;\n\
    \    ShortestPathTree(usize n, u32 root) : n_{n}, root_{root}, tree_(n), dist_(n,\
    \ INVALID) {\n        assert(root < n);\n        tree_.shrink_to_fit();\n    \
    \    dist_.shrink_to_fit();\n        dist_[root] = 0;\n    }\n\n    inline usize\
    \ size() const noexcept {\n        return n_;\n    }\n    inline u32 parent(u32\
    \ v) const noexcept {\n        assert(v < size());\n        return tree_[v].parent;\n\
    \    }\n    inline u32 id(u32 v) const noexcept {\n        assert(v < size());\n\
    \        return tree_[v].id;\n    }\n    inline bool connect(u32 v) const noexcept\
    \ {\n        assert(v < size());\n        return tree_[v].exist();\n    }\n  \
    \  inline u32 dist(u32 v) const noexcept {\n        assert(v < size());\n    \
    \    return dist_[v];\n    }\n\n    u32 operator[](u32 v) const noexcept {\n \
    \       assert(v < size());\n        return dist_[v];\n    }\n\n    bool relax(u32\
    \ from, u32 to, u32 id) {\n        if (dist_[to] > dist_[from] + 1) {\n      \
    \      dist_[to] = dist_[from] + 1;\n            tree_[to].parent = from;\n  \
    \          tree_[to].id = id;\n            return true;\n        }\n        return\
    \ false;\n    }\n\n    std::vector<u32> pathV(u32 v) {\n        assert(v < size());\n\
    \        assert(connect(v));\n        std::vector<u32> res(dist(v) + 1);\n   \
    \     res[dist(v)] = v;\n        for (u32 i{dist(v)} ; i-- ; ) {\n           \
    \ v = parent(v);\n            res[i] = v;\n        }\n        return res;\n  \
    \  }\n    \n    std::vector<E> pathE(u32 v) {\n        assert(v < size());\n \
    \       assert(connect(v));\n        std::vector<E> res(dist(v));\n        for\
    \ (u32 i{dist(v)} ; i-- ; ) {\n            res[i] = tree_[v];\n            v =\
    \ parent(v);\n        }\n        return res;\n    }\n};\n\n} // namespace internal\n\
    \n} // namespace zawa\n#line 5 \"Src/Graph/ShortestPath/BFS.hpp\"\n\n#include\
    \ <utility>\n#line 8 \"Src/Graph/ShortestPath/BFS.hpp\"\n\nnamespace zawa {\n\n\
    class BFS {\npublic:\n    using ShortestPathTree = internal::ShortestPathTree;\n\
    private:\n    usize n_;\n    std::vector<std::vector<std::pair<u32, u32>>> adj_;\n\
    \n    static constexpr u32 invalid() noexcept {\n        return ShortestPathTree::invalid();\n\
    \    }\n\npublic:\n    BFS() = default;\n    BFS(usize n) : n_{n}, adj_(n) {\n\
    \        adj_.shrink_to_fit();\n    }\n\n    u32 size() const noexcept {\n   \
    \     return n_;\n    }\n    void addDirectedEdge(u32 from, u32 to, u32 id = invalid())\
    \ {\n        assert(from < size());\n        assert(to < size());\n        adj_[from].emplace_back(to,\
    \ id);\n    }\n    void addUndirectedEdge(u32 u, u32 v, u32 id = invalid()) {\n\
    \        assert(u < size());\n        assert(v < size());\n        adj_[u].emplace_back(v,\
    \ id);\n        adj_[v].emplace_back(u, id);\n    }\n\n    BFS(const std::vector<std::vector<u32>>&\
    \ g) : n_{g.size()}, adj_(g.size()) {\n        adj_.shrink_to_fit();\n       \
    \ for (u32 v{} ; v < size() ; v++) {\n            for (u32 x : g[v]) {\n     \
    \           adj_[v].emplace_back(x, invalid());\n            }\n        }\n  \
    \  }\n\n    ShortestPathTree build(u32 start) {\n        std::vector<u32> queue;\n\
    \        queue.reserve(n_);\n        ShortestPathTree res(n_, start);\n      \
    \  queue.emplace_back(start);\n        for (u32 head{} ; head < queue.size() ;\
    \ head++) {\n            u32 v{queue[head]};\n            for (auto [x, id] :\
    \ adj_[v]) {\n                if (res.relax(v, x, id)) {\n                   \
    \ queue.emplace_back(x);\n                }\n            }\n        }\n      \
    \  return res;\n    }\n};\n\n} // namespace zawa\n#line 5 \"Test/Manual/abc271_d.test.cpp\"\
    \n\n#line 7 \"Test/Manual/abc271_d.test.cpp\"\n#include <string>\n#line 10 \"\
    Test/Manual/abc271_d.test.cpp\"\n\n/*\n * ABC271-D Flip and Adjust\n * https://atcoder.jp/contests/abc271/submissions/48487470\n\
    \ */\n\nvoid solve() {\n    using namespace zawa; \n    SetFastIO();\n    int\
    \ n, s; std::cin >> n >> s;\n    \n    auto f{[&](int card, int sum) -> int {\n\
    \        return card * (s + 1) + sum;\n    }};\n\n    BFS bfs((n + 1) * (s + 1));\n\
    \    for (int i{} ; i < n ; i++) {\n        int a, b; std::cin >> a >> b;\n  \
    \      for (int j{} ; j + a <= s ; j++) {\n            bfs.addDirectedEdge(f(i,\
    \ j), f(i + 1, j + a), 0);\n        }\n        for (int j{} ; j + b <= s ; j++)\
    \ {\n            bfs.addDirectedEdge(f(i, j), f(i + 1, j + b), 1);\n        }\n\
    \    }\n\n    auto tree{bfs.build(f(0, 0))};\n    if (tree.connect(f(n, s))) {\n\
    \        std::cout << \"Yes\\n\";\n        for (const auto& e : tree.pathE(f(n,\
    \ s))) {\n            std::cout << (e.id ? 'T' : 'H');\n        }\n        std::cout\
    \ << '\\n';\n    }\n    else {\n        std::cout << \"No\" << '\\n';\n    }\n\
    }\n\nint main() {\n#ifdef ATCODER\n    solve();\n#else\n    std::cout << \"Hello\
    \ World\" << '\\n';\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Graph/ShortestPath/BFS.hpp\"\
    \n\n#include <iostream>\n#include <string>\n#include <utility>\n#include <vector>\n\
    \n/*\n * ABC271-D Flip and Adjust\n * https://atcoder.jp/contests/abc271/submissions/48487470\n\
    \ */\n\nvoid solve() {\n    using namespace zawa; \n    SetFastIO();\n    int\
    \ n, s; std::cin >> n >> s;\n    \n    auto f{[&](int card, int sum) -> int {\n\
    \        return card * (s + 1) + sum;\n    }};\n\n    BFS bfs((n + 1) * (s + 1));\n\
    \    for (int i{} ; i < n ; i++) {\n        int a, b; std::cin >> a >> b;\n  \
    \      for (int j{} ; j + a <= s ; j++) {\n            bfs.addDirectedEdge(f(i,\
    \ j), f(i + 1, j + a), 0);\n        }\n        for (int j{} ; j + b <= s ; j++)\
    \ {\n            bfs.addDirectedEdge(f(i, j), f(i + 1, j + b), 1);\n        }\n\
    \    }\n\n    auto tree{bfs.build(f(0, 0))};\n    if (tree.connect(f(n, s))) {\n\
    \        std::cout << \"Yes\\n\";\n        for (const auto& e : tree.pathE(f(n,\
    \ s))) {\n            std::cout << (e.id ? 'T' : 'H');\n        }\n        std::cout\
    \ << '\\n';\n    }\n    else {\n        std::cout << \"No\" << '\\n';\n    }\n\
    }\n\nint main() {\n#ifdef ATCODER\n    solve();\n#else\n    std::cout << \"Hello\
    \ World\" << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/ShortestPath/BFS.hpp
  - Src/Graph/ShortestPath/ShortestPathTree.hpp
  isVerificationFile: true
  path: Test/Manual/abc271_d.test.cpp
  requiredBy: []
  timestamp: '2023-12-14 17:56:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Manual/abc271_d.test.cpp
layout: document
redirect_from:
- /verify/Test/Manual/abc271_d.test.cpp
- /verify/Test/Manual/abc271_d.test.cpp.html
title: Test/Manual/abc271_d.test.cpp
---
