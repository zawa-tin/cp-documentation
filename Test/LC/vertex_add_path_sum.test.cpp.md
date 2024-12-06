---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/GroupConcept.hpp
    title: Src/Algebra/Group/GroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/FenwickTree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"Test/LC/vertex_add_path_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 2 \"Src/Template/IOSetting.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\
    \n\n#include <iostream>\n#include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO()\
    \ {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n}\n\nvoid SetPrecision(u32\
    \ dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n\n#line 2 \"\
    Src/Algebra/Group/GroupConcept.hpp\"\n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace Concept {\n\ntemplate\
    \ <class T>\nconcept Monoid = requires {\n    typename T::Element;\n    { T::identity()\
    \ } -> std::same_as<typename T::Element>;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace Concept {\n\ntemplate <class T>\nconcept Inversible\
    \ = requires {\n    typename T::Element;\n    { T::inverse(std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\ntemplate <class\
    \ T>\nconcept Group = Monoid<T> and Inversible<T>;\n\n} // namespace Concept\n\
    \n} // namespace zawa\n#line 5 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n#include <ostream>\n#include <functional>\n\
    #include <type_traits>\n\nnamespace zawa {\n\ntemplate <Concept::Group Group>\n\
    class FenwickTree {\nprivate:\n    using Value = typename Group::Element;\n\n\
    \    usize n_;\n    u32 bitWidth_;\n    std::vector<Value> a_, dat_;\n\n    constexpr\
    \ i32 lsb(i32 x) const noexcept {\n        return x & -x;\n    }\n    \n    //\
    \ a[i] <- a[i] + v\n    void addDat(i32 i, const Value& v) {\n        assert(0\
    \ <= i and i < static_cast<i32>(n_));\n        for ( i++ ; i < static_cast<i32>(dat_.size())\
    \ ; i += lsb(i)) {\n            dat_[i] = Group::operation(dat_[i], v);\n    \
    \    }\n    }\n\n    // return a[0] + a[1] + .. + a[i - 1]\n    Value product(i32\
    \ i) const {\n        assert(0 <= i and i <= static_cast<i32>(n_));\n        Value\
    \ res{ Group::identity() };\n        for ( ; i > 0 ; i -= lsb(i)) {\n        \
    \    res = Group::operation(res, dat_[i]);\n        }\n        return res;\n \
    \   }\n\npublic:\n    FenwickTree() : n_{}, bitWidth_{}, a_{}, dat_{} {}\n\n \
    \   FenwickTree(usize n) : n_{ n }, bitWidth_{ std::__lg(static_cast<u32>(n))\
    \ + 1 }, a_(n), dat_(n + 1, Group::identity()) {\n        dat_.shrink_to_fit();\n\
    \    }\n\n    FenwickTree(const std::vector<Value>& a) : n_{ a.size() }, bitWidth_{\
    \ std::__lg(static_cast<u32>(a.size())) + 1 }, a_(a), dat_(a.size() + 1, Group::identity())\
    \ {\n        dat_.shrink_to_fit();  \n        for (i32 i{} ; i < static_cast<i32>(n_)\
    \ ; i++) {\n            addDat(i, a[i]);\n        }\n    }\n\n    // return a[i]\n\
    \    const Value& get(usize i) const noexcept {\n        assert(i < n_);\n   \
    \     return a_[i];\n    }\n\n    // return a[i]\n    const Value& operator[](usize\
    \ i) const noexcept {\n        assert(i < n_);\n        return a_[i];\n    }\n\
    \n    usize size() const noexcept {\n        return n_;\n    }\n\n    // a[i]\
    \ <- a[i] + v\n    void operation(usize i, const Value& v) {\n        assert(i\
    \ < n_);\n        addDat(i, v);\n        a_[i] = Group::operation(a_[i], v);\n\
    \    }\n\n    // a[i] <- v\n    void set(usize i, const Value& v) {\n        assert(i\
    \ < n_);\n        addDat(i, Group::operation(Group::inverse(a_[i]), v));\n   \
    \     a_[i] = v;\n    }\n\n    // return a[0] + a[1] + ... + a[r - 1]\n    Value\
    \ prefixProduct(usize r) const {\n        assert(r <= n_);\n        return product(r);\n\
    \    }\n\n    // return a[l] + a[l + 1] ... + a[r - 1]\n    Value product(usize\
    \ l, usize r) const {\n        assert(l <= r and r <= n_);\n        return Group::operation(Group::inverse(product(l)),\
    \ product(r));\n    }\n\n    template <class Function>\n    u32 maxRight(usize\
    \ l, const Function& f) const {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(Value)>>, \"maxRight's argument f must be function bool(T)\"\
    );\n        assert(l < n_);\n        Value sum{ Group::inverse(product(l)) };\
    \ \n        u32 r{};\n        for (u32 bit{ bitWidth_ } ; bit ; ) {\n        \
    \    bit--;\n            u32 nxt{ r | (1u << bit) };\n            if (nxt < dat_.size()\
    \ and f(Group::operation(sum, dat_[nxt]))) {\n                sum = Group::operation(sum,\
    \ dat_[nxt]);\n                r = std::move(nxt);\n            }\n        }\n\
    \        assert(l <= r);\n        return r;\n    }\n\n    template <class Function>\n\
    \    u32 minLeft(usize r, const Function& f) const {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(Value)>>, \"minLeft's argument f must be function bool(T)\"\
    );\n        assert(r <= n_);\n        Value sum{ product(r) };\n        u32 l{};\n\
    \        for (u32 bit{ bitWidth_ } ; bit ; ) {\n            bit--;\n         \
    \   u32 nxt{ l | (1u << bit) };\n            if (nxt <= r and not f(Group::operation(Group::inverse(dat_[nxt]),\
    \ sum))) {\n                sum = Group::operation(Group::inverse(dat_[nxt]),\
    \ sum);\n                l = std::move(nxt);\n            }\n        }\n     \
    \   assert(l <= r);\n        return l;\n    }\n\n    // debug print\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const FenwickTree& ft) {\n      \
    \  for (u32 i{} ; i <= ft.size() ; i++) {\n            os << ft.prefixProduct(i)\
    \ << (i == ft.size() ? \"\" : \" \");\n        }\n        return os;\n    }\n\
    };\n\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\
    \nnamespace zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n   \
    \ using Element = T;\n    static constexpr T identity() noexcept {\n        return\
    \ T{};\n    }\n    static constexpr T operation(const T& l, const T& r) noexcept\
    \ {\n        return l + r;\n    }\n    static constexpr T inverse(const T& v)\
    \ noexcept {\n        return -v;\n    }\n};\n\n} // namespace zawa\n#line 2 \"\
    Src/Graph/Tree/HeavyLightDecomposition.hpp\"\n\n#line 4 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \n\n#include <algorithm>\n#line 7 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \n#include <cmath>\n#include <limits>\n#include <utility>\n#line 11 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class V>\nclass HeavyLightDecomposition {\n\
    public:\n\n    static constexpr V Invalid() noexcept {\n        return INVALID;\n\
    \    }\n\n    HeavyLightDecomposition() = default;\n\n    HeavyLightDecomposition(std::vector<std::vector<V>>\
    \ T, V root = 0u) \n        : n_{T.size()}, par_(n_), top_(n_), idx_(n_), \n \
    \       inv_(n_), size_(n_, usize{1}), dep_(n_) {\n\n            auto dfs1{[&](auto\
    \ dfs, V v, V p, usize d) -> usize {\n                par_[v] = p;\n         \
    \       dep_[v] = d;\n                if (p != INVALID) {\n                  \
    \  for (u32 i{} ; i + 1 < T[v].size() ; i++) if (T[v][i] == p) {\n           \
    \             std::swap(T[v][i], T[v].back());\n                        break;\n\
    \                    }\n                    assert(T[v].back() == p);\n      \
    \              T[v].pop_back();\n                }\n                for (V x :\
    \ T[v]) {\n                    size_[v] += dfs(dfs, x, v, d + 1);\n          \
    \      }\n                for (u32 i{1} ; i < T[v].size() ; i++) if (size_[T[v][0]]\
    \ < size_[T[v][i]]) {\n                    std::swap(T[v][0], T[v][i]);\n    \
    \            }\n                return size_[v];\n            }};\n\n        \
    \    auto dfs2{[&](auto dfs, V v, V idx, V top) -> V {\n                idx_[v]\
    \ = idx++;\n                inv_[idx_[v]] = v;\n                top_[v] = top;\n\
    \                if (T[v].size()) {\n                    idx = dfs(dfs, T[v][0],\
    \ idx, top);\n                    for (u32 i{1} ; i < T[v].size() ; i++) {\n \
    \                       idx = dfs(dfs, T[v][i], idx, T[v][i]);\n             \
    \       }\n                }\n                return idx;\n            }};\n\n\
    \            dfs1(dfs1, root, INVALID, 0u);\n            dfs2(dfs2, root, 0u,\
    \ root);\n        }\n\n    inline usize size() const noexcept {\n        return\
    \ n_;\n    }\n\n    usize size(V v) const noexcept {\n        assert(v < (V)size());\n\
    \        return size_[v];\n    }\n\n    usize depth(V v) const noexcept {\n  \
    \      assert(v < (V)size());\n        return dep_[v];\n    }\n\n    V parent(V\
    \ v) const noexcept {\n        assert(v < (V)size());\n        return par_[v];\n\
    \    }\n\n    V index(V v) const noexcept {\n        assert(v < (V)size());\n\
    \        return idx_[v];\n    }\n\n    V operator[](V v) const noexcept {\n  \
    \      assert(v < (V)size());\n        return idx_[v];\n    }\n\n    std::vector<std::pair<V,\
    \ V>> decomp(V s, V t) const {\n        assert(s < (V)size());\n        assert(t\
    \ < (V)size());\n        std::vector<std::pair<V, V>> res, ser;\n        while\
    \ (top_[s] != top_[t]) {\n            if (dep_[top_[s]] >= dep_[top_[t]]) {\n\
    \                res.emplace_back(s, top_[s]);\n                s = top_[s];\n\
    \                if (par_[s] != INVALID) s = par_[s];\n            }\n       \
    \     else {\n                ser.emplace_back(top_[t], t);\n                t\
    \ = top_[t];\n                if (par_[t] != INVALID) t = par_[t];\n         \
    \   }\n        }\n        res.emplace_back(s, t);\n        std::reverse(ser.begin(),\
    \ ser.end());\n        res.insert(res.end(), ser.begin(), ser.end()); \n     \
    \   return res;\n    }\n\n    std::vector<std::pair<V, V>> operator()(V s, V t)\
    \ const {\n        return decomp(s, t);\n    }\n\n    V lca(V u, V v) const {\n\
    \        assert(u < (V)size());\n        assert(v < (V)size());\n        while\
    \ (top_[u] != top_[v]) {\n            if (dep_[top_[u]] >= dep_[top_[v]]) {\n\
    \                u = top_[u];\n                if (par_[u] != INVALID) u = par_[u];\n\
    \            }\n            else {\n                v = top_[v];\n           \
    \     if (par_[v] != INVALID) v = par_[v];\n            }\n        }\n       \
    \ return (dep_[u] <= dep_[v] ? u : v);\n    }\n\n    // p\u306Fv\u306E\u7956\u5148\
    \u304B\uFF1F\n    bool isAncestor(V v, V p) {\n        assert(v < size());\n \
    \       assert(p < size());\n        if (dep_[v] < dep_[p]) return false;\n  \
    \      while (v != INVALID and top_[v] != top_[p]) {\n            v = par_[top_[v]];\n\
    \        }\n        return v != INVALID;\n    }\n\n    V levelAncestor(V v, usize\
    \ step) const {\n        assert(v < (V)size());\n        if (step > dep_[v]) return\
    \ INVALID;\n        while (true) {\n            usize dist{dep_[v] - dep_[top_[v]]};\n\
    \            if (dist >= step) break;\n            step -= dist + 1;\n       \
    \     v = par_[top_[v]];\n        }\n        step = (dep_[v] - dep_[top_[v]])\
    \ - step;\n        return inv_[idx_[top_[v]] + step];\n    }\n\n    V jump(V s,\
    \ V t, usize step) const {\n        assert(s < (V)size());\n        assert(t <\
    \ (V)size());\n        V uu{INVALID}, vv{INVALID};\n        usize d{};\n     \
    \   for (auto [u, v] : decomp(s, t)) {\n            usize dist{std::max(dep_[u],\
    \ dep_[v]) - std::min(dep_[u], dep_[v])};\n            if (dist >= step) {\n \
    \               uu = u;\n                vv = v;\n                d = dist;\n\
    \                break;\n            }\n            step -= dist + 1;\n      \
    \  }\n        if (uu == INVALID) return INVALID;\n        if (dep_[uu] <= dep_[vv])\
    \ {\n            return inv_[idx_[uu] + step];\n        }\n        else {\n  \
    \          return inv_[idx_[vv] + (d - step)];\n        }\n    }\n\n    usize\
    \ distance(V s, V t) const {\n        assert(s < (V)size());\n        assert(t\
    \ < (V)size());\n        usize res{};\n        for (auto [u, v] : decomp(s, t))\
    \ {\n            if (dep_[u] > dep_[v]) std::swap(u, v);\n            res += dep_[v]\
    \ - dep_[u];\n        }\n        return res;\n    }\n\nprivate:\n    static constexpr\
    \ V INVALID{static_cast<V>(-1)};\n    usize n_{};\n    std::vector<V> par_{},\
    \ top_{}, idx_{}, inv_{};\n    std::vector<usize> size_{}, dep_{};\n};\n\n} //\
    \ namespace zawa\n#line 7 \"Test/LC/vertex_add_path_sum.test.cpp\"\n\n#line 12\
    \ \"Test/LC/vertex_add_path_sum.test.cpp\"\n\nint main() {\n    using namespace\
    \ zawa; \n    SetFastIO();\n\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int>\
    \ A(N);\n    for (int& a : A) std::cin >> a;\n    std::vector<std::vector<int>>\
    \ T(N);\n    for (int _{} ; _ < N - 1 ; _++) {\n        int u, v;\n        std::cin\
    \ >> u >> v;\n        T[u].push_back(v);\n        T[v].push_back(u);\n       \
    \ // AddEdge(T, u, v);\n    }\n    HeavyLightDecomposition hld(T);\n    std::vector<long\
    \ long> init(N);\n    for (int v{} ; v < N ; v++) {\n        init[hld[v]] = A[v];\n\
    \    }\n    FenwickTree<AdditiveGroup<long long>> fen{init};\n    while (Q--)\
    \ {\n        int t;\n        std::cin >> t;\n        if (t == 0) {\n         \
    \   int p, x;\n            std::cin >> p >> x;\n            fen.operation(hld[p],\
    \ x);\n        }\n        else if (t == 1) {\n            int u, v;\n        \
    \    std::cin >> u >> v;\n            long long ans{};\n            for (auto\
    \ [u, v] : hld(u, v)) {\n                u = hld[u];\n                v = hld[v];\n\
    \                if (u > v) std::swap(u, v);\n                ans += fen.product(u,\
    \ v + 1);\n            }\n            std::cout << ans << '\\n';\n        }\n\
    \        else {\n            assert(false);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\n#include \"../../Src/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <utility>\n#include <vector>\n\
    \nint main() {\n    using namespace zawa; \n    SetFastIO();\n\n    int N, Q;\n\
    \    std::cin >> N >> Q;\n    std::vector<int> A(N);\n    for (int& a : A) std::cin\
    \ >> a;\n    std::vector<std::vector<int>> T(N);\n    for (int _{} ; _ < N - 1\
    \ ; _++) {\n        int u, v;\n        std::cin >> u >> v;\n        T[u].push_back(v);\n\
    \        T[v].push_back(u);\n        // AddEdge(T, u, v);\n    }\n    HeavyLightDecomposition\
    \ hld(T);\n    std::vector<long long> init(N);\n    for (int v{} ; v < N ; v++)\
    \ {\n        init[hld[v]] = A[v];\n    }\n    FenwickTree<AdditiveGroup<long long>>\
    \ fen{init};\n    while (Q--) {\n        int t;\n        std::cin >> t;\n    \
    \    if (t == 0) {\n            int p, x;\n            std::cin >> p >> x;\n \
    \           fen.operation(hld[p], x);\n        }\n        else if (t == 1) {\n\
    \            int u, v;\n            std::cin >> u >> v;\n            long long\
    \ ans{};\n            for (auto [u, v] : hld(u, v)) {\n                u = hld[u];\n\
    \                v = hld[v];\n                if (u > v) std::swap(u, v);\n  \
    \              ans += fen.product(u, v + 1);\n            }\n            std::cout\
    \ << ans << '\\n';\n        }\n        else {\n            assert(false);\n  \
    \      }\n    }\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/FenwickTree/FenwickTree.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/Graph/Tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: Test/LC/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2024-12-06 16:40:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/vertex_add_path_sum.test.cpp
- /verify/Test/LC/vertex_add_path_sum.test.cpp.html
title: Test/LC/vertex_add_path_sum.test.cpp
---
