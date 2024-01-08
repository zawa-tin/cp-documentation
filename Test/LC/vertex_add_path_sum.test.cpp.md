---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/FenwickTree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/HeavyLightDecomposition.hpp
    title: Src/Graph/Tree/HeavyLightDecomposition.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/U32Pair.hpp
    title: Src/Utility/U32Pair.hpp
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
    \ zawa\n#line 2 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n\n#line 4 \"\
    Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n#include <ostream>\n#include <functional>\n#include <type_traits>\n\
    \nnamespace zawa {\n\ntemplate <class Group>\nclass FenwickTree {\nprivate:\n\
    \    using Value = typename Group::Element;\n\n    usize n_;\n    u32 bitWidth_;\n\
    \    std::vector<Value> a_, dat_;\n\n    constexpr i32 lsb(i32 x) const noexcept\
    \ {\n        return x & -x;\n    }\n    \n    // a[i] <- a[i] + v\n    void addDat(i32\
    \ i, const Value& v) {\n        assert(0 <= i and i < static_cast<i32>(n_));\n\
    \        for ( i++ ; i < static_cast<i32>(dat_.size()) ; i += lsb(i)) {\n    \
    \        dat_[i] = Group::operation(dat_[i], v);\n        }\n    }\n\n    // return\
    \ a[0] + a[1] + .. + a[i - 1]\n    Value product(i32 i) const {\n        assert(0\
    \ <= i and i <= static_cast<i32>(n_));\n        Value res{ Group::identity() };\n\
    \        for ( ; i > 0 ; i -= lsb(i)) {\n            res = Group::operation(res,\
    \ dat_[i]);\n        }\n        return res;\n    }\n\npublic:\n    FenwickTree()\
    \ : n_{}, bitWidth_{}, a_{}, dat_{} {}\n\n    FenwickTree(usize n) : n_{ n },\
    \ bitWidth_{ std::__lg(static_cast<u32>(n)) + 1 }, a_(n), dat_(n + 1, Group::identity())\
    \ {\n        dat_.shrink_to_fit();\n    }\n\n    FenwickTree(const std::vector<Value>&\
    \ a) : n_{ a.size() }, bitWidth_{ std::__lg(static_cast<u32>(a.size())) + 1 },\
    \ a_(a), dat_(a.size() + 1, Group::identity()) {\n        dat_.shrink_to_fit();\
    \  \n        for (i32 i{} ; i < static_cast<i32>(n_) ; i++) {\n            addDat(i,\
    \ a[i]);\n        }\n    }\n\n    // return a[i]\n    const Value& get(usize i)\
    \ const noexcept {\n        assert(i < n_);\n        return a_[i];\n    }\n\n\
    \    // return a[i]\n    const Value& operator[](usize i) const noexcept {\n \
    \       assert(i < n_);\n        return a_[i];\n    }\n\n    usize size() const\
    \ noexcept {\n        return n_;\n    }\n\n    // a[i] <- a[i] + v\n    void operation(usize\
    \ i, const Value& v) {\n        assert(i < n_);\n        addDat(i, v);\n     \
    \   a_[i] = Group::operation(a_[i], v);\n    }\n\n    // a[i] <- v\n    void set(usize\
    \ i, const Value& v) {\n        assert(i < n_);\n        addDat(i, Group::operation(Group::inverse(a_[i]),\
    \ v));\n        a_[i] = v;\n    }\n\n    // return a[0] + a[1] + ... + a[r - 1]\n\
    \    Value prefixProduct(usize r) const {\n        assert(r <= n_);\n        return\
    \ product(r);\n    }\n\n    // return a[l] + a[l + 1] ... + a[r - 1]\n    Value\
    \ product(usize l, usize r) const {\n        assert(l <= r and r <= n_);\n   \
    \     return Group::operation(Group::inverse(product(l)), product(r));\n    }\n\
    \n    template <class Function>\n    u32 maxRight(usize l, const Function& f)\
    \ const {\n        static_assert(std::is_convertible_v<decltype(f), std::function<bool(Value)>>,\
    \ \"maxRight's argument f must be function bool(T)\");\n        assert(l < n_);\n\
    \        Value sum{ Group::inverse(product(l)) }; \n        u32 r{};\n       \
    \ for (u32 bit{ bitWidth_ } ; bit ; ) {\n            bit--;\n            u32 nxt{\
    \ r | (1u << bit) };\n            if (nxt < dat_.size() and f(Group::operation(sum,\
    \ dat_[nxt]))) {\n                sum = Group::operation(sum, dat_[nxt]);\n  \
    \              r = std::move(nxt);\n            }\n        }\n        assert(l\
    \ <= r);\n        return r;\n    }\n\n    template <class Function>\n    u32 minLeft(usize\
    \ r, const Function& f) const {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(Value)>>, \"minLeft's argument f must be function bool(T)\"\
    );\n        assert(r <= n_);\n        Value sum{ product(r) };\n        u32 l{};\n\
    \        for (u32 bit{ bitWidth_ } ; bit ; ) {\n            bit--;\n         \
    \   u32 nxt{ l | (1u << bit) };\n            if (nxt <= r and not f(Group::operation(Group::inverse(dat_[nxt]),\
    \ sum))) {\n                sum = Group::operation(Group::inverse(dat_[nxt]),\
    \ sum);\n                l = std::move(nxt);\n            }\n        }\n     \
    \   assert(l <= r);\n        return l;\n    }\n\n    // debug print\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const FenwickTree& ft) {\n      \
    \  for (u32 i{} ; i <= ft.size() ; i++) {\n            os << ft.prefixProduct(i)\
    \ << (i == ft.size() ? \"\" : \" \");\n        }\n        return os;\n    }\n\n\
    };\n\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\
    \nnamespace zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n   \
    \ using Element = T;\n    static constexpr T identity() noexcept {\n        return\
    \ T{};\n    }\n    static constexpr T operation(const T& l, const T& r) noexcept\
    \ {\n        return l + r;\n    }\n    static constexpr T inverse(const T& v)\
    \ noexcept {\n        return -v;\n    }\n};\n\n} // namespace zawa\n#line 2 \"\
    Src/Graph/Tree/HeavyLightDecomposition.hpp\"\n\n#line 2 \"Src/Utility/U32Pair.hpp\"\
    \n\n#line 4 \"Src/Utility/U32Pair.hpp\"\n\n#line 7 \"Src/Utility/U32Pair.hpp\"\
    \n\nnamespace zawa {\n\nclass U32Pair {\nprivate:\n    static constexpr u32 SHIFT{32};\n\
    \    static constexpr u32 MASK{static_cast<u32>((1LL << SHIFT) - 1)};\n    u64\
    \ value_{};\npublic:\n    constexpr U32Pair() {}\n    constexpr U32Pair(u32 first,\
    \ u32 second) {\n        value_ = (static_cast<u64>(first) << SHIFT) | second;\n\
    \    }\n    constexpr u32 first() const noexcept {\n        return static_cast<u32>(value_\
    \ >> SHIFT);\n    }\n    constexpr u32 second() const noexcept {\n        return\
    \ static_cast<u32>(value_ & MASK);\n    }\n    constexpr u64 combined() const\
    \ noexcept {\n        return value_;\n    }\n    constexpr U32Pair& operator=(const\
    \ U32Pair& rhs) {\n        value_ = rhs.value_;\n        return *this;\n    }\n\
    \    friend constexpr bool operator==(const U32Pair& lhs, const U32Pair& rhs)\
    \ {\n        return lhs.value_ == rhs.value_;\n    }\n    friend constexpr bool\
    \ operator!=(const U32Pair& lhs, const U32Pair& rhs) {\n        return lhs.value_\
    \ != rhs.value_;\n    }\n    friend constexpr bool operator<(const U32Pair& lhs,\
    \ const U32Pair& rhs) {\n        return lhs.value_ < rhs.value_;\n    }\n    friend\
    \ constexpr bool operator<=(const U32Pair& lhs, const U32Pair& rhs) {\n      \
    \  return lhs.value_ <= rhs.value_;\n    }\n    friend constexpr bool operator>(const\
    \ U32Pair& lhs, const U32Pair& rhs) {\n        return lhs.value_ > rhs.value_;\n\
    \    }\n    friend constexpr bool operator>=(const U32Pair& lhs, const U32Pair&\
    \ rhs) {\n        return lhs.value_ >= rhs.value_;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const U32Pair& pair) {\n        os << '(' << pair.first()\
    \ << ',' << pair.second() << ')';\n        return os;\n    }\n};\n\nstruct U32PairHash\
    \ {\n    usize operator()(const U32Pair& pair) const noexcept {\n        return\
    \ std::hash<u64>{}(pair.combined());\n    }\n};\n\n} // namespace zawa\n#line\
    \ 5 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\n\n#include <algorithm>\n#line\
    \ 8 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\n#include <iterator>\n#include\
    \ <limits>\n#include <utility>\n#line 12 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \n\nnamespace zawa {\n\nclass HeavyLightDecomposition {\nprivate:\n    usize n_;\n\
    \    std::vector<std::vector<u32>> g_;\n    std::vector<u32> index_, top_, depth_,\
    \ par_;\n    std::vector<u32> subtree_;\n\n    static constexpr u32 invalid()\
    \ noexcept {\n        return std::numeric_limits<u32>::max();\n    }\n\n    u32\
    \ dfsInit(u32 v, u32 p) {\n        par_[v] = p;\n        for (auto it{g_[v].begin()}\
    \ ; it != g_[v].end() ; ) {\n            if (*it == p) {\n                it =\
    \ g_[v].erase(it);\n            }\n            else {\n                subtree_[v]\
    \ += dfsInit(*it, v);\n                it++;\n            }\n        }\n     \
    \   return ++subtree_[v];\n    }\n    void dfs(u32 v, u32 p, u32 tp, u32& t) {\n\
    \        top_[v] = tp;\n        index_[v] = t;\n        depth_[v] = (p == invalid()\
    \ ? u32{} : depth_[p] + 1);\n        if (g_[v].empty()) return;\n        auto\
    \ max{std::distance(g_[v].begin(), std::max_element(g_[v].begin(), g_[v].end(),\
    \ [&](const auto& i, const auto& j) {\n                    return subtree_[i]\
    \ < subtree_[j];\n                }))};\n        if (max) std::swap(g_[v][0],\
    \ g_[v][max]);\n        dfs(g_[v][0], v, tp, ++t);\n        for (u32 i{1u} ; i\
    \ < g_[v].size() ; i++) {\n            dfs(g_[v][i], v, g_[v][i], ++t);\n    \
    \    }\n    }\n\npublic:\n    constexpr usize size() const noexcept {\n      \
    \  return n_;\n    }\n    HeavyLightDecomposition() = default;\n    HeavyLightDecomposition(usize\
    \ n) \n        : n_{n}, g_(n), index_(n), top_(n), depth_(n), par_(n, invalid()),\
    \ subtree_(n) {\n        g_.shrink_to_fit();\n        index_.shrink_to_fit();\n\
    \        top_.shrink_to_fit();\n        depth_.shrink_to_fit();\n        par_.shrink_to_fit();\n\
    \        subtree_.shrink_to_fit();\n    } \n    void addEdge(u32 u, u32 v) {\n\
    \        assert(u < size());\n        assert(v < size());\n        g_[u].emplace_back(v);\n\
    \        g_[v].emplace_back(u);\n    }\n    void build(u32 r) {\n        assert(r\
    \ < size()); \n        dfsInit(r, invalid());\n        u32 t{};\n        dfs(r,\
    \ invalid(), r, t);\n    }\n\n    const u32& operator[](u32 i) const noexcept\
    \ {\n        assert(i < size());\n        return index_[i];\n    }\n\n    std::vector<U32Pair>\
    \ operator()(u32 s, u32 t) const {\n        assert(s < size());\n        assert(t\
    \ < size());\n        std::vector<U32Pair> res, ser; \n        while (top_[s]\
    \ != top_[t]) {\n            if (depth_[top_[s]] <= depth_[top_[t]]) {\n     \
    \           ser.emplace_back(index_[top_[t]], index_[t] + 1);\n              \
    \  t = top_[t];\n                t = (par_[t] == invalid() ? t : par_[t]);\n \
    \           }\n            else {\n                res.emplace_back(index_[top_[s]],\
    \ index_[s] + 1);\n                s = top_[s];\n                s = (par_[s]\
    \ == invalid() ? s : par_[s]);\n            }\n        }\n        res.emplace_back(std::min(index_[s],\
    \ index_[t]), std::max(index_[s], index_[t]) + 1u);\n        res.insert(res.end(),\
    \ ser.begin(), ser.end());\n        return res;\n    }\n\n    u32 lca(u32 u, u32\
    \ v) {\n        assert(u < size());\n        assert(v < size());\n        while\
    \ (top_[u] != top_[v]) {\n            if (depth_[top_[u]] <= depth_[top_[v]])\
    \ {\n                v = top_[v];\n                v = (par_[v] == invalid() ?\
    \ v : par_[v]);\n            }\n            else {\n                u = top_[u];\n\
    \                u = (par_[u] == invalid() ? u : par_[u]);\n            }\n  \
    \      }\n        return (depth_[u] <= depth_[v] ? u : v);\n    }\n};\n\n} //\
    \ namespace zawa\n#line 7 \"Test/LC/vertex_add_path_sum.test.cpp\"\n\n#line 11\
    \ \"Test/LC/vertex_add_path_sum.test.cpp\"\n\nint main() {\n    using namespace\
    \ zawa; \n    SetFastIO();\n    int n, q; std::cin >> n >> q;\n    std::vector<long\
    \ long> a(n);\n    for (auto& x : a) std::cin >> x;\n\n    HeavyLightDecomposition\
    \ hld(n);\n    for (int _{} ; _ < n - 1 ; _++) {\n        int u, v; std::cin >>\
    \ u >> v;\n        hld.addEdge(u, v);\n    }\n    hld.build(0);\n\n    FenwickTree<AdditiveGroup<long\
    \ long>> ft(n); \n    for (int i{} ; i < n ; i++) {\n        ft.operation(hld[i],\
    \ a[i]);\n    }\n    for (int _{} ; _ < q ; _++) {\n        int t; std::cin >>\
    \ t;\n        if (t == 0) {\n            int p, x; std::cin >> p >> x;\n     \
    \       ft.operation(hld[p], x);\n            a[hld[p]] += x;\n        }\n   \
    \     else if (t == 1) {\n            int u, v; std::cin >> u >> v;\n        \
    \    long long ans{};\n            auto decomp{hld(u, v)};\n            for (const\
    \ auto& p : hld(u, v)) {\n                ans += ft.product(p.first(), p.second());\n\
    \            }\n            std::cout << ans << '\\n';\n        }\n        else\
    \ {\n            assert(false);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\n#include \"../../Src/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <vector>\n\nint main() {\n\
    \    using namespace zawa; \n    SetFastIO();\n    int n, q; std::cin >> n >>\
    \ q;\n    std::vector<long long> a(n);\n    for (auto& x : a) std::cin >> x;\n\
    \n    HeavyLightDecomposition hld(n);\n    for (int _{} ; _ < n - 1 ; _++) {\n\
    \        int u, v; std::cin >> u >> v;\n        hld.addEdge(u, v);\n    }\n  \
    \  hld.build(0);\n\n    FenwickTree<AdditiveGroup<long long>> ft(n); \n    for\
    \ (int i{} ; i < n ; i++) {\n        ft.operation(hld[i], a[i]);\n    }\n    for\
    \ (int _{} ; _ < q ; _++) {\n        int t; std::cin >> t;\n        if (t == 0)\
    \ {\n            int p, x; std::cin >> p >> x;\n            ft.operation(hld[p],\
    \ x);\n            a[hld[p]] += x;\n        }\n        else if (t == 1) {\n  \
    \          int u, v; std::cin >> u >> v;\n            long long ans{};\n     \
    \       auto decomp{hld(u, v)};\n            for (const auto& p : hld(u, v)) {\n\
    \                ans += ft.product(p.first(), p.second());\n            }\n  \
    \          std::cout << ans << '\\n';\n        }\n        else {\n           \
    \ assert(false);\n        }\n    }\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/FenwickTree/FenwickTree.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/Graph/Tree/HeavyLightDecomposition.hpp
  - Src/Utility/U32Pair.hpp
  isVerificationFile: true
  path: Test/LC/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-09 00:25:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/vertex_add_path_sum.test.cpp
- /verify/Test/LC/vertex_add_path_sum.test.cpp.html
title: Test/LC/vertex_add_path_sum.test.cpp
---
