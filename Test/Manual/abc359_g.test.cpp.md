---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/ChminMonoid.hpp
    title: Src/Algebra/Monoid/ChminMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SparseTable/SparseTable.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/AuxiliaryTree.hpp
    title: "Auxiliary Tree (\u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\u3061\
      \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\
      \u6728\u3092\u5727\u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\
      \u6728)"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/LowestCommonAncestor.hpp
    title: Lowest Common Ancestor
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
    - https://atcoder.jp/contests/abc359/submissions/55138867
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/Manual/abc359_g.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * ABC359-G Sum of Tree Distance\n * TODO: Dropbox\u306B\u30C6\u30B9\u30C8\
    \u30B1\u30FC\u30B9\u304C\u767B\u9332\u3055\u308C\u305F\u3089\u81EA\u52D5verify\u306B\
    \u79FB\u884C\u3059\u308B\n * https://atcoder.jp/contests/abc359/submissions/55138867\n\
    \ */\n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Graph/Tree/AuxiliaryTree.hpp\"\n\n#line\
    \ 2 \"Src/Graph/Tree/Tree.hpp\"\n\n#line 4 \"Src/Graph/Tree/Tree.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace zawa {\n\nusing Tree = std::vector<std::vector<u32>>;\n\
    \nvoid AddEdge(Tree& T, u32 u, u32 v) {\n    assert(u < T.size());\n    assert(v\
    \ < T.size());\n    T[u].emplace_back(v);\n    T[v].emplace_back(u);\n}\n\nvoid\
    \ AddDirectedEdge(Tree& T, u32 from, u32 to) {\n    assert(from < T.size());\n\
    \    assert(to < T.size());\n    T[from].emplace_back(to);\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\n\n#line 2 \"Src/Algebra/Monoid/ChminMonoid.hpp\"\
    \n\n#line 4 \"Src/Algebra/Monoid/ChminMonoid.hpp\"\n\n#include <algorithm>\n#include\
    \ <optional>\n\nnamespace zawa {\n\ntemplate <class T, class U>\nclass ChminMonoidData\
    \ {\nprivate:\n    std::optional<T> priority_{};\n    U value_{};\npublic:\n \
    \   ChminMonoidData() = default;\n    ChminMonoidData(const U& value)\n      \
    \  : priority_{std::nullopt}, value_{value} {}\n    ChminMonoidData(const T& priority,\
    \ const U& value)\n        : priority_{priority}, value_{value} {}\n\n    constexpr\
    \ bool infty() const noexcept {\n        return !priority_.has_value();\n    }\n\
    \    constexpr const T& priority() const noexcept {\n        return priority_.value();\n\
    \    }\n    constexpr const U& value() const noexcept {\n        return value_;\n\
    \    }\n    friend constexpr bool operator<(const ChminMonoidData& l, const ChminMonoidData&\
    \ r) {\n        if (l.infty()) return false;\n        else if (r.infty()) return\
    \ true;\n        else return l.priority() < r.priority();\n    }\n};\n\ntemplate\
    \ <class T, class U>\nstruct ChminMonoid {\n    using Element = ChminMonoidData<T,\
    \ U>;\n    static Element identity() noexcept {\n        return Element{};\n \
    \   }\n    // \u30BF\u30A4\u30D6\u30EC\u30FC\u30AF\u306Fl\u5074\u3092\u512A\u5148\
    \u3059\u308B\u3088\u3046\u306B\u306A\u3063\u3066\u3044\u308B\u3002\n    static\
    \ Element operation(const Element& l, const Element& r) noexcept {\n        return\
    \ (r < l ? r : l);\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\
    \n\n#line 4 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\n\n#line 7 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\
    \n#include <ostream>\n\nnamespace zawa {\n\ntemplate <class Structure>\nclass\
    \ SparseTable {\nprivate:\n    using Value = typename Structure::Element;\n  \
    \  std::vector<u32> L;\n    std::vector<std::vector<Value>> dat;\npublic:\n\n\
    \    SparseTable() : L{}, dat{} {}\n    SparseTable(const std::vector<Value>&\
    \ a) : L(a.size() + 1), dat{} {\n        for (u32 i{1} ; i < L.size() ; i++) {\n\
    \            L[i] = L[i - 1] + (i >> (L[i - 1] + 1));\n        }\n        dat.resize(L.back()\
    \ + 1);\n        dat[0] = a;\n        for (u32 i{1}, len{2} ; i < dat.size() ;\
    \ i++, len <<= 1) {\n            dat[i] = dat[i - 1];\n            for (u32 j{}\
    \ ; j + len - 1 < dat[i].size() ; j++) {\n                dat[i][j] = Structure::operation(dat[i\
    \ - 1][j], dat[i - 1][j + (len >> 1)]);\n            }\n        }\n    }\n\n \
    \   Value product(u32 l, u32 r) const {\n        assert(l <= r);\n        assert(l\
    \ < dat[0].size());\n        assert(r <= dat[0].size());\n        u32 now{L[r\
    \ - l]};\n        return Structure::operation(dat[now][l], dat[now][r - (1 <<\
    \ now)]);\n    }\n\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ SparseTable<Structure>& spt) {\n        for (u32 i{}, len{1} ; i < spt.dat.size()\
    \ ; i++, len <<= 1) {\n            os << \"length = \" << len << '\\n';\n    \
    \        for (u32 j{} ; j + len - 1 < spt.dat[i].size() ; j++) {\n           \
    \     os << spt.dat[i][j] << (j + len == spt.dat[i].size() ? '\\n' : ' ');\n \
    \           }\n        }\n        return os;\n    }\n};\n\n} // namespace zawa\n\
    #line 7 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\n\n#line 10 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\
    \n\nnamespace zawa {\n\nclass LowestCommonAncestor {\nprivate:\n    using Monoid\
    \ = ChminMonoid<u32, u32>;\n\npublic:\n    LowestCommonAncestor() = default;\n\
    \n    LowestCommonAncestor(const Tree& tree, u32 r = 0u) \n        : n_{tree.size()},\
    \ depth_(tree.size()), L_(tree.size()), R_(tree.size()), st_{} {\n           \
    \ std::vector<Monoid::Element> init;\n            init.reserve(2 * size());\n\
    \            auto dfs{[&](auto dfs, u32 v, u32 p) -> void {\n                depth_[v]\
    \ = (p == INVALID ? 0u : depth_[p] + 1);\n                L_[v] = (u32)init.size();\n\
    \                for (auto x : tree[v]) {\n                    if (x == p) {\n\
    \                        continue;\n                    }\n                  \
    \  init.emplace_back(depth_[v], v);\n                    dfs(dfs, x, v);\n   \
    \             }\n                R_[v] = (u32)init.size();\n            }};\n\
    \            dfs(dfs, r, INVALID);\n            st_ = SparseTable<Monoid>(init);\n\
    \    }\n\n    u32 operator()(u32 u, u32 v) const {\n        assert(verify(u));\n\
    \        assert(verify(v));\n        if (L_[u] > L_[v]) {\n            std::swap(u,\
    \ v);\n        }\n        return st_.product(L_[u], R_[v]).value();\n    }\n\n\
    \    u32 lca(u32 u, u32 v) const {\n        return (*this)(u, v);\n    }\n\n \
    \   inline u32 depth(u32 v) const noexcept {\n        assert(verify(v));\n   \
    \     return depth_[v];\n    }\n\n    u32 distance(u32 u, u32 v) const {\n   \
    \     assert(verify(u));\n        assert(verify(v));\n        return depth(u)\
    \ + depth(v) - 2u * depth((*this)(u, v));\n    }\n\n    bool isAncestor(u32 p,\
    \ u32 v) const {\n        assert(verify(p));\n        assert(verify(v));\n   \
    \     return L_[p] <= L_[v] and R_[v] <= R_[p];\n    }\n\nprotected:\n    u32\
    \ left(u32 v) const noexcept {\n        return L_[v];\n    }\n\n    inline usize\
    \ size() const {\n        return n_;\n    }\n\n    inline bool verify(u32 v) const\
    \ {\n        return v < size();\n    }\n\nprivate:\n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n\
    \    usize n_{};\n    std::vector<u32> depth_, L_, R_;\n    SparseTable<Monoid>\
    \ st_;\n};\n\n} // namespace zawa\n#line 5 \"Src/Graph/Tree/AuxiliaryTree.hpp\"\
    \n\n#line 7 \"Src/Graph/Tree/AuxiliaryTree.hpp\"\n\nnamespace zawa {\n\nclass\
    \ AuxiliaryTree : public LowestCommonAncestor {\npublic:\n    using V = u32;\n\
    \    AuxiliaryTree() = default;\n    AuxiliaryTree(const Tree& T, V r = 0u) \n\
    \        : LowestCommonAncestor{ T, r }, T_(T.size()), dist_(T.size()), used_(T.size())\
    \ {}\n\n    V construct(const std::vector<V>& vs) {\n        assert(vs.size());\n\
    \        clear();\n        vs_ = vs;\n        return build();\n    }\n\n    const\
    \ std::vector<V>& operator[](V v) const {\n        verify(v);\n        return\
    \ T_[v];\n    }\n\n    inline bool contains(V v) const {\n        assert(verify(v));\n\
    \        return used_[v];\n    }\n\n    inline u32 parentEdgeLength(V v) const\
    \ {\n        assert(contains(v));\n        return dist_[v];\n    }\n\n    std::vector<V>\
    \ current() const {\n        return vs_;\n    }\n\nprivate:\n    Tree T_{}; \n\
    \    std::vector<V> vs_{};\n    std::vector<u32> dist_{};\n    std::vector<bool>\
    \ used_{};\n\n    void addEdge(V p, V v) {\n        assert(depth(p) < depth(v));\n\
    \        AddEdge(T_, p, v);\n        dist_[v] = depth(v) - depth(p);\n    }\n\n\
    \    V build() {\n        std::sort(vs_.begin(), vs_.end(), [&](V u, V v) -> bool\
    \ {\n                return left(u) < left(v);\n                });\n        vs_.erase(std::unique(vs_.begin(),\
    \ vs_.end()), vs_.end());\n        V k{(V)vs_.size()};\n        std::vector<V>\
    \ stack;\n        stack.reserve(2u * vs_.size());\n        stack.emplace_back(vs_[0]);\n\
    \        for (u32 i{} ; i + 1 < k ; i++) {\n            if (!LowestCommonAncestor::isAncestor(vs_[i],\
    \ vs_[i + 1])) {\n                V w{LowestCommonAncestor::lca(vs_[i], vs_[i\
    \ + 1])};\n                V l{stack.back()};\n                stack.pop_back();\n\
    \                while (stack.size() and LowestCommonAncestor::depth(w) < LowestCommonAncestor::depth(stack.back()))\
    \ {\n                    addEdge(stack.back(), l);\n                    l = stack.back();\n\
    \                    stack.pop_back();\n                }\n                if\
    \ (stack.empty() or stack.back() != w) {\n                    stack.emplace_back(w);\n\
    \                    vs_.emplace_back(w);\n                }\n               \
    \ addEdge(w, l);\n            }\n            stack.emplace_back(vs_[i + 1]);\n\
    \        }\n        while (stack.size() > 1u) {\n            V l{stack.back()};\n\
    \            stack.pop_back();\n            addEdge(stack.back(), l);\n      \
    \  }\n        for (V v : vs_) {\n            used_[v] = true;\n        }\n   \
    \     return stack.back();\n    }\n\n    void clear() {\n        for (V v : vs_)\
    \ {\n            T_[v].clear();\n            used_[v] = false;\n            dist_[v]\
    \ = 0u;\n        }\n        vs_.clear();\n    }\n};\n\n} // namespace zawa\n#line\
    \ 11 \"Test/Manual/abc359_g.test.cpp\"\n\n#line 14 \"Test/Manual/abc359_g.test.cpp\"\
    \n\nusing namespace zawa;\nusing vertex = AuxiliaryTree::V;\n\nint main() {\n\
    #ifdef ATCODER\n    SetFastIO();\n\n    int N;\n    std::cin >> N;\n    Tree g(N);\n\
    \    for (int i{1} ; i < N ; i++) {\n        int u, v;\n        std::cin >> u\
    \ >> v;\n        AddEdge(g, u - 1, v - 1);\n    }\n    std::vector<int> A(N);\n\
    \    std::vector<std::vector<vertex>> B(N);\n    for (int i{} ; i < N ; i++) {\n\
    \        std::cin >> A[i];\n        A[i]--;\n        B[A[i]].push_back(i);\n \
    \   }\n    AuxiliaryTree AT(g);\n    long long ans{};\n    std::vector<int> size(N);\n\
    \    std::vector<long long> dp(N);\n    for (int c{} ; c < N ; c++) {\n      \
    \  if (B[c].empty()) {\n            continue;\n        }\n        int r{(int)AT.construct(B[c])};\n\
    \        auto dfs{[&](auto dfs, int v, int p) -> long long {\n            if (A[v]\
    \ == c) size[v]++; \n            long long res{};\n            for (auto x : AT[v])\
    \ {\n                if ((int)x == p) continue;\n                res += dfs(dfs,\
    \ x, v);\n                res += dp[v] * size[x] + size[v] * (size[x] * AT.parentEdgeLength(x)\
    \ + dp[x]);\n                dp[v] += dp[x] + AT.parentEdgeLength(x) * size[x];\n\
    \                size[v] += size[x];\n            }\n            return res;\n\
    \        }}; \n        long long val{dfs(dfs, r, -1)};\n        ans += val;\n\
    \        for (auto v : AT.current()) {\n            size[v] = 0;\n           \
    \ dp[v] = 0;\n        }\n    }\n    std::cout << ans << '\\n';\n#else\n    std::cout\
    \ << \"Hello World\" << '\\n';\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * ABC359-G Sum of Tree Distance\n * TODO: Dropbox\u306B\u30C6\u30B9\u30C8\
    \u30B1\u30FC\u30B9\u304C\u767B\u9332\u3055\u308C\u305F\u3089\u81EA\u52D5verify\u306B\
    \u79FB\u884C\u3059\u308B\n * https://atcoder.jp/contests/abc359/submissions/55138867\n\
    \ */\n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Graph/Tree/AuxiliaryTree.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nusing namespace zawa;\nusing vertex\
    \ = AuxiliaryTree::V;\n\nint main() {\n#ifdef ATCODER\n    SetFastIO();\n\n  \
    \  int N;\n    std::cin >> N;\n    Tree g(N);\n    for (int i{1} ; i < N ; i++)\
    \ {\n        int u, v;\n        std::cin >> u >> v;\n        AddEdge(g, u - 1,\
    \ v - 1);\n    }\n    std::vector<int> A(N);\n    std::vector<std::vector<vertex>>\
    \ B(N);\n    for (int i{} ; i < N ; i++) {\n        std::cin >> A[i];\n      \
    \  A[i]--;\n        B[A[i]].push_back(i);\n    }\n    AuxiliaryTree AT(g);\n \
    \   long long ans{};\n    std::vector<int> size(N);\n    std::vector<long long>\
    \ dp(N);\n    for (int c{} ; c < N ; c++) {\n        if (B[c].empty()) {\n   \
    \         continue;\n        }\n        int r{(int)AT.construct(B[c])};\n    \
    \    auto dfs{[&](auto dfs, int v, int p) -> long long {\n            if (A[v]\
    \ == c) size[v]++; \n            long long res{};\n            for (auto x : AT[v])\
    \ {\n                if ((int)x == p) continue;\n                res += dfs(dfs,\
    \ x, v);\n                res += dp[v] * size[x] + size[v] * (size[x] * AT.parentEdgeLength(x)\
    \ + dp[x]);\n                dp[v] += dp[x] + AT.parentEdgeLength(x) * size[x];\n\
    \                size[v] += size[x];\n            }\n            return res;\n\
    \        }}; \n        long long val{dfs(dfs, r, -1)};\n        ans += val;\n\
    \        for (auto v : AT.current()) {\n            size[v] = 0;\n           \
    \ dp[v] = 0;\n        }\n    }\n    std::cout << ans << '\\n';\n#else\n    std::cout\
    \ << \"Hello World\" << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Tree/AuxiliaryTree.hpp
  - Src/Graph/Tree/Tree.hpp
  - Src/Graph/Tree/LowestCommonAncestor.hpp
  - Src/Algebra/Monoid/ChminMonoid.hpp
  - Src/DataStructure/SparseTable/SparseTable.hpp
  isVerificationFile: true
  path: Test/Manual/abc359_g.test.cpp
  requiredBy: []
  timestamp: '2024-07-02 11:54:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Manual/abc359_g.test.cpp
layout: document
title: ABC359-F Sum of Tree Distance
---

$N$ 頂点からなる木について $\sum_{i = 1}^{N - 1} \sum_{j = i + 1}^{N} \text{dist}(i, j)$ を求める方法。

木dpを考える。頂点 $v$ を根とした部分木について以下の三つの情報を持つ。

- $K_{v}$ 部分木の頂点数
- $A_{v}$ 部分木の頂点集合を $C = (C_{1}, C_{2}, \dots, C_{K_{v}})$ としたときの $\sum_{i = 1}^{K_{v} - 1} \sum_{j = i + 1}^{K_{v}} \text{dist}(C_{i}, C_{j})$
- $B_{v}$ 部分木の各頂点について、その頂点から頂点 $v$ までの寄与の和。

$K_{v}$ はOK

$v$ に $x$ をマージするとき、 $A_{v}$ への寄与は $B_{v} \times K_{x} + B_{v} \times (K_{x} + B_{x})$ 。 $B_{v}$ への寄与は $B_{x} + K_{x}$

この問題では木を圧縮しているので、辺の長さが $1$ とは限らず、いくらかの係数をかけ合わせた値が寄与しているところがある。
