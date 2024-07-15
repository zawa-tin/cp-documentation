---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/Centroid.hpp
    title: "\u6728\u306E\u91CD\u5FC3"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/Tree.hpp
    title: Src/Graph/Tree/Tree.hpp
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
    - https://atcoder.jp/contests/yahoo-procon2018-final-open/submissions/55629303
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/Manual/yahoo_procon2018_final_c.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * \u300C\u307F\u3093\u306A\u306E\u30D7\u30ED\u30B3\u30F3 2018\u300D\u6C7A\
    \u52DD \u30AA\u30FC\u30D7\u30F3\u30B3\u30F3\u30C6\u30B9\u30C8 - C \u6728\u306E\
    \u554F\u984C\n * https://atcoder.jp/contests/yahoo-procon2018-final-open/submissions/55629303\n\
    \ */\n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Graph/Tree/Tree.hpp\"\n\n#line 4 \"Src/Graph/Tree/Tree.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\nnamespace zawa {\n\nusing Tree =\
    \ std::vector<std::vector<u32>>;\n\nvoid AddEdge(Tree& T, u32 u, u32 v) {\n  \
    \  assert(u < T.size());\n    assert(v < T.size());\n    T[u].emplace_back(v);\n\
    \    T[v].emplace_back(u);\n}\n\nvoid AddDirectedEdge(Tree& T, u32 from, u32 to)\
    \ {\n    assert(from < T.size());\n    assert(to < T.size());\n    T[from].emplace_back(to);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Graph/Tree/Centroid.hpp\"\n\n#line 5 \"\
    Src/Graph/Tree/Centroid.hpp\"\n\n#line 7 \"Src/Graph/Tree/Centroid.hpp\"\n#include\
    \ <utility>\n#line 9 \"Src/Graph/Tree/Centroid.hpp\"\n\nnamespace zawa {\n\nclass\
    \ Centroid {\npublic:\n\n    using Vertex = u32;\n\n    Centroid() = default;\n\
    \n    Centroid(const Tree& T) : T_{T}, size_(T_.size(), usize{1}) {}\n    Centroid(Tree&&\
    \ T) : T_{std::move(T)}, size_(T_.size(), usize{1}) {}\n\n    inline usize size()\
    \ const noexcept {\n        return T_.size();\n    }\n\n    inline usize size(Vertex\
    \ v) const noexcept {\n        assert(v < size());\n        return size_[v];\n\
    \    }\n\n    bool isRemoved(Vertex v) const noexcept {\n        assert(v < size());\n\
    \        return size_[v] == 0u;\n    }\n\n    void remove(Vertex v) noexcept {\n\
    \        assert(v < size());\n        size_[v] = 0u;\n    }\n\n    const std::vector<Vertex>&\
    \ operator[](Vertex v) const noexcept {\n        assert(v < size());\n       \
    \ return T_[v];\n    }\n\n    // @response: centroid of component which v belongs\n\
    \    Vertex rooting(Vertex v) {\n        assert(v < size());\n        assert(!isRemoved(v));\n\
    \        usize all{dfsSize(v, INVALID)};\n        Vertex par{INVALID};\n     \
    \   bool fn{false};\n        while (!fn) {\n            fn = true;\n         \
    \   for (Vertex x : T_[v]) {\n                if (x == par or isRemoved(x) or\
    \ usize{2} * size_[x] <= all) {\n                    continue;\n             \
    \   }\n                fn = false;\n                par = v;\n               \
    \ v = x;\n                break;\n            }\n        }\n        return v;\n\
    \    }\n\n    std::vector<Vertex> component(Vertex v) const {\n        assert(v\
    \ < size());\n        assert(!isRemoved(v));\n        std::vector<Vertex> res;\n\
    \        dfsComponent(v, INVALID, res);\n        return res;\n    }\n\n    std::vector<Vertex>\
    \ adjlist(Vertex v) const {\n        assert(v < size());\n        std::vector<Vertex>\
    \ res;\n        res.reserve(T_[v].size());\n        for (auto x : T_[v]) if (!isRemoved(x))\
    \ {\n            res.emplace_back(x);\n        }\n        return res;\n    }\n\
    \nprivate:\n    static constexpr Vertex INVALID{static_cast<u32>(-1)};\n    Tree\
    \ T_{};\n    std::vector<usize> size_{};\n\n    usize dfsSize(Vertex v, u32 par)\
    \ {\n        size_[v] = 1u;\n        for (Vertex x : T_[v]) if (x != par and !isRemoved(x))\
    \ {\n            size_[v] += dfsSize(x, v);\n        }\n        return size_[v];\n\
    \    }\n\n    void dfsComponent(Vertex v, Vertex par, std::vector<Vertex>& comp)\
    \ const {\n        comp.emplace_back(v);\n        for (Vertex x : T_[v]) if (x\
    \ != par and !isRemoved(x)) {\n            dfsComponent(x, v, comp);\n       \
    \ }\n    }\n};\n\n} // namespace zawa\n#line 11 \"Test/Manual/yahoo_procon2018_final_c.test.cpp\"\
    \n\n#line 15 \"Test/Manual/yahoo_procon2018_final_c.test.cpp\"\n\nusing namespace\
    \ zawa;\n\nvoid solve() {\n    int N, Q;\n    std::cin >> N >> Q;\n    Tree g(N);\n\
    \    for (int _{} ; _ < N - 1 ; _++) {\n        int A, B;\n        std::cin >>\
    \ A >> B;\n        AddEdge(g, A - 1, B - 1);\n    }\n    std::vector<std::vector<std::pair<int,\
    \ int>>> query(N);\n    for (int i{} ; i < Q ; i++) {\n        int v, k;\n   \
    \     std::cin >> v >> k;\n        v--;\n        query[v].push_back(std::make_pair(k,\
    \ i));\n    }\n    Centroid C(std::move(g));\n    std::vector<int> dep(N);\n \
    \   auto calc_dep{[&](auto dfs, int v, int p, int d) -> void {\n        dep[v]\
    \ = d;\n        for (auto x : C[v]) if (!C.isRemoved(x) and (int)x != p) {\n \
    \           dfs(dfs, x, v, d + 1);\n        }\n    }};\n    std::vector<int> ans(Q);\n\
    \    auto dfs{[&](auto dfs, int v) -> void {\n        v = C.rooting(v);\n    \
    \    calc_dep(calc_dep, v, -1, 0);\n        C.remove(v);\n        std::vector<std::vector<u32>>\
    \ comp;\n        for (auto x : C.adjlist(v)) {\n            comp.push_back(C.component(x));\n\
    \        }\n        int max_d{};\n        for (const auto& com : comp) {\n   \
    \         for (auto x : com) max_d = std::max(max_d, dep[x]);\n        }\n   \
    \     std::vector<int> cnt(max_d + 1);\n        cnt[0]++;\n        for (const\
    \ auto& com : comp) {\n            for (auto x : com) cnt[dep[x]]++;\n       \
    \ }\n        for (auto [k, i] : query[v]) {\n            if (k <= max_d) {\n \
    \               ans[i] += cnt[k];\n            }\n        }\n        for (const\
    \ auto& com : comp) {\n            for (auto x : com) cnt[dep[x]]--;\n       \
    \     for (auto x : com) {\n                for (auto [k, i] : query[x]) {\n \
    \                   int d{k - dep[x]};\n                    if (0 <= d and d <=\
    \ max_d) ans[i] += cnt[d];\n                }\n            }\n            for\
    \ (auto x : com) cnt[dep[x]]++;\n        }\n        for (auto x : C.adjlist(v))\
    \ {\n            dfs(dfs, x);\n        }\n    }};\n    dfs(dfs, 0);\n    for (int\
    \ i{} ; i < Q ; i++) {\n        std::cout << ans[i] << '\\n';\n    }\n}\n\nint\
    \ main() {\n#ifdef ATCODER\n    SetFastIO();\n    solve();\n#else\n    std::cout\
    \ << \"Hello World\" << '\\n';\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * \u300C\u307F\u3093\u306A\u306E\u30D7\u30ED\u30B3\u30F3 2018\u300D\u6C7A\
    \u52DD \u30AA\u30FC\u30D7\u30F3\u30B3\u30F3\u30C6\u30B9\u30C8 - C \u6728\u306E\
    \u554F\u984C\n * https://atcoder.jp/contests/yahoo-procon2018-final-open/submissions/55629303\n\
    \ */\n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Graph/Tree/Tree.hpp\"\
    \n#include \"../../Src/Graph/Tree/Centroid.hpp\"\n\n#include <iostream>\n#include\
    \ <utility>\n#include <vector>\n\nusing namespace zawa;\n\nvoid solve() {\n  \
    \  int N, Q;\n    std::cin >> N >> Q;\n    Tree g(N);\n    for (int _{} ; _ <\
    \ N - 1 ; _++) {\n        int A, B;\n        std::cin >> A >> B;\n        AddEdge(g,\
    \ A - 1, B - 1);\n    }\n    std::vector<std::vector<std::pair<int, int>>> query(N);\n\
    \    for (int i{} ; i < Q ; i++) {\n        int v, k;\n        std::cin >> v >>\
    \ k;\n        v--;\n        query[v].push_back(std::make_pair(k, i));\n    }\n\
    \    Centroid C(std::move(g));\n    std::vector<int> dep(N);\n    auto calc_dep{[&](auto\
    \ dfs, int v, int p, int d) -> void {\n        dep[v] = d;\n        for (auto\
    \ x : C[v]) if (!C.isRemoved(x) and (int)x != p) {\n            dfs(dfs, x, v,\
    \ d + 1);\n        }\n    }};\n    std::vector<int> ans(Q);\n    auto dfs{[&](auto\
    \ dfs, int v) -> void {\n        v = C.rooting(v);\n        calc_dep(calc_dep,\
    \ v, -1, 0);\n        C.remove(v);\n        std::vector<std::vector<u32>> comp;\n\
    \        for (auto x : C.adjlist(v)) {\n            comp.push_back(C.component(x));\n\
    \        }\n        int max_d{};\n        for (const auto& com : comp) {\n   \
    \         for (auto x : com) max_d = std::max(max_d, dep[x]);\n        }\n   \
    \     std::vector<int> cnt(max_d + 1);\n        cnt[0]++;\n        for (const\
    \ auto& com : comp) {\n            for (auto x : com) cnt[dep[x]]++;\n       \
    \ }\n        for (auto [k, i] : query[v]) {\n            if (k <= max_d) {\n \
    \               ans[i] += cnt[k];\n            }\n        }\n        for (const\
    \ auto& com : comp) {\n            for (auto x : com) cnt[dep[x]]--;\n       \
    \     for (auto x : com) {\n                for (auto [k, i] : query[x]) {\n \
    \                   int d{k - dep[x]};\n                    if (0 <= d and d <=\
    \ max_d) ans[i] += cnt[d];\n                }\n            }\n            for\
    \ (auto x : com) cnt[dep[x]]++;\n        }\n        for (auto x : C.adjlist(v))\
    \ {\n            dfs(dfs, x);\n        }\n    }};\n    dfs(dfs, 0);\n    for (int\
    \ i{} ; i < Q ; i++) {\n        std::cout << ans[i] << '\\n';\n    }\n}\n\nint\
    \ main() {\n#ifdef ATCODER\n    SetFastIO();\n    solve();\n#else\n    std::cout\
    \ << \"Hello World\" << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Tree/Tree.hpp
  - Src/Graph/Tree/Centroid.hpp
  isVerificationFile: true
  path: Test/Manual/yahoo_procon2018_final_c.test.cpp
  requiredBy: []
  timestamp: '2024-07-15 15:20:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Manual/yahoo_procon2018_final_c.test.cpp
layout: document
redirect_from:
- /verify/Test/Manual/yahoo_procon2018_final_c.test.cpp
- /verify/Test/Manual/yahoo_procon2018_final_c.test.cpp.html
title: Test/Manual/yahoo_procon2018_final_c.test.cpp
---
