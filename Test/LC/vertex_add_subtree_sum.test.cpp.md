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
    path: Src/Graph/Tree/Sack.hpp
    title: Sack
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"Test/LC/vertex_add_subtree_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#line 2 \"Src/Template/IOSetting.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\
    \n\n#include <iostream>\n#include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO()\
    \ {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n}\n\nvoid SetPrecision(u32\
    \ dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Graph/Tree/Sack.hpp\"\n\n#line 4 \"Src/Graph/Tree/Sack.hpp\"\
    \n\n#include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace zawa\
    \ {\n\nclass Sack {\nprivate:    \n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n\
    \    usize n_{};\n    std::vector<std::vector<u32>> g_;\n    std::vector<u32>\
    \ sz_, euler_, L_, R_;\n\n    u32 dfsHLD(u32 v, u32 p) {\n        sz_[v] = 1;\n\
    \        usize m{g_[v].size()};\n        usize max{};\n        if (m > 1u and\
    \ g_[v][0] == p) std::swap(g_[v][0], g_[v][1]);\n        for (u32 i{} ; i < m\
    \ ; i++) if (g_[v][i] != p) {\n            sz_[v] += dfsHLD(g_[v][i], v);\n  \
    \          if (max < sz_[g_[v][i]]) {\n                max = sz_[g_[v][i]];\n\
    \                if (i) std::swap(g_[v][0], g_[v][i]);\n            }\n      \
    \  }\n        return sz_[v];\n    }\n\n    void dfsEuler(u32 v, u32 p, u32& t)\
    \ {\n        euler_[t] = v;\n        L_[v] = t++;\n        for (auto x : g_[v])\
    \ if (x != p) {\n            dfsEuler(x, v, t);\n        }\n        R_[v] = t;\n\
    \    }\n\npublic:\n    constexpr usize size() const noexcept {\n        return\
    \ n_;\n    }\n\n    Sack() = default;\n    Sack(u32 n) \n        : n_{n}, g_(n),\
    \ sz_(n), euler_(n), L_(n), R_(n) {\n        assert(n);\n        g_.shrink_to_fit();\n\
    \        sz_.shrink_to_fit();\n        euler_.shrink_to_fit();\n        L_.shrink_to_fit();\n\
    \        R_.shrink_to_fit();\n    }\n    void addEdge(u32 u, u32 v) {\n      \
    \  assert(u < size());\n        assert(v < size());\n        g_[u].emplace_back(v);\n\
    \        g_[v].emplace_back(u);\n    }\n\n    const std::vector<u32>& operator[](u32\
    \ v) const noexcept {\n        assert(v < size());\n        return g_[v];\n  \
    \  }\n\n    template <class ADD, class DEL, class QUERY, class RESET>\n    u32\
    \ execute(u32 root, const ADD& add, const DEL& del, const QUERY& query, const\
    \ RESET& reset) {\n        dfsHLD(root, INVALID);\n        u32 t{};\n        dfsEuler(root,\
    \ INVALID, t);\n        \n        auto sack{[&](auto dfs, u32 v, u32 p, bool keep)\
    \ -> void {\n            usize m{g_[v].size()};\n            for (u32 i{1} ; i\
    \ < m ; i++) if (g_[v][i] != p) {\n                dfs(dfs, g_[v][i], v, false);\n\
    \            }\n            if (sz_[v] > 1u) dfs(dfs, g_[v][0], v, true);\n  \
    \          if (sz_[v] > 1u) {\n                for (u32 i{R_[g_[v][0]]} ; i <\
    \ R_[v] ; i++) {\n                    add(euler_[i]);\n                }\n   \
    \         }\n            add(v);\n            query(v);\n            if (!keep)\
    \ {\n                for (u32 i{L_[v]} ; i < R_[v] ; i++) {\n                \
    \    del(euler_[i]);\n                }\n                reset();\n          \
    \  }\n        }};\n        sack(sack, root, INVALID, false);\n\n        return\
    \ sz_[root];\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n \
    \   using Element = T;\n    static constexpr T identity() noexcept {\n       \
    \ return T{};\n    }\n    static constexpr T operation(const T& l, const T& r)\
    \ noexcept {\n        return l + r;\n    }\n    static constexpr T inverse(const\
    \ T& v) noexcept {\n        return -v;\n    }\n};\n\n} // namespace zawa\n#line\
    \ 2 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n\n#line 4 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\n#line 7 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n#include <ostream>\n\
    #include <functional>\n#include <type_traits>\n\nnamespace zawa {\n\ntemplate\
    \ <class Group>\nclass FenwickTree {\nprivate:\n    using Value = typename Group::Element;\n\
    \n    usize n_;\n    u32 bitWidth_;\n    std::vector<Value> a_, dat_;\n\n    constexpr\
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
    \ << (i == ft.size() ? \"\" : \" \");\n        }\n        return os;\n    }\n\n\
    };\n\n\n} // namespace zawa\n#line 7 \"Test/LC/vertex_add_subtree_sum.test.cpp\"\
    \n\n#line 12 \"Test/LC/vertex_add_subtree_sum.test.cpp\"\n\nusing namespace zawa;\n\
    \nint main() {\n    SetFastIO();\n\n    int n, q; std::cin >> n >> q;\n    std::vector\
    \ dat(n, std::vector<std::pair<int, long long>>{});\n    for (int i{} ; i < n\
    \ ; i++) {\n        long long a; std::cin >> a;\n        dat[i].emplace_back(0,\
    \ a);\n    }\n    Sack sack(n);\n    for (int i{1} ; i < n ; i++) {\n        int\
    \ p; std::cin >> p;\n        sack.addEdge(p, i);\n    }\n    std::vector<long\
    \ long> ans;\n    ans.reserve(q);\n    int id{};\n    std::vector query(n, std::vector<std::pair<int,\
    \ int>>{});\n    query.reserve(q);\n    for (int i{1} ; i <= q ; i++) {\n    \
    \    int t, v; std::cin >> t >> v;\n        if (t == 0) {\n            long long\
    \ x; std::cin >> x;\n            dat[v].emplace_back(i, x);\n        }\n     \
    \   else if (t == 1) {\n            ans.emplace_back(-1LL);\n            query[v].emplace_back(i,\
    \ id++);\n        }\n        else {\n            assert(false);\n        }\n \
    \   }\n    FenwickTree<AdditiveGroup<long long>> fen(q + 1);\n    auto add{[&](int\
    \ v) -> void {\n        for (auto [time, x] : dat[v]) {\n            fen.operation(time,\
    \ x);\n        }\n    }};\n    auto del{[&](int v) -> void {\n        for (auto\
    \ [time, x] : dat[v]) {\n            fen.operation(time, -x);\n        }\n   \
    \ }};\n    auto answer{[&](int v) -> void {\n        for (auto [time, i] : query[v])\
    \ {\n            ans[i] = fen.prefixProduct(time + 1);\n        }\n    }};\n \
    \   auto reset{[](){}};\n    sack.execute(0, add, del, answer, reset);\n    for\
    \ (auto v : ans) {\n        std::cout << v << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Graph/Tree/Sack.hpp\"\
    \n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\n#include \"../../Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <utility>\n#include <vector>\n\
    \nusing namespace zawa;\n\nint main() {\n    SetFastIO();\n\n    int n, q; std::cin\
    \ >> n >> q;\n    std::vector dat(n, std::vector<std::pair<int, long long>>{});\n\
    \    for (int i{} ; i < n ; i++) {\n        long long a; std::cin >> a;\n    \
    \    dat[i].emplace_back(0, a);\n    }\n    Sack sack(n);\n    for (int i{1} ;\
    \ i < n ; i++) {\n        int p; std::cin >> p;\n        sack.addEdge(p, i);\n\
    \    }\n    std::vector<long long> ans;\n    ans.reserve(q);\n    int id{};\n\
    \    std::vector query(n, std::vector<std::pair<int, int>>{});\n    query.reserve(q);\n\
    \    for (int i{1} ; i <= q ; i++) {\n        int t, v; std::cin >> t >> v;\n\
    \        if (t == 0) {\n            long long x; std::cin >> x;\n            dat[v].emplace_back(i,\
    \ x);\n        }\n        else if (t == 1) {\n            ans.emplace_back(-1LL);\n\
    \            query[v].emplace_back(i, id++);\n        }\n        else {\n    \
    \        assert(false);\n        }\n    }\n    FenwickTree<AdditiveGroup<long\
    \ long>> fen(q + 1);\n    auto add{[&](int v) -> void {\n        for (auto [time,\
    \ x] : dat[v]) {\n            fen.operation(time, x);\n        }\n    }};\n  \
    \  auto del{[&](int v) -> void {\n        for (auto [time, x] : dat[v]) {\n  \
    \          fen.operation(time, -x);\n        }\n    }};\n    auto answer{[&](int\
    \ v) -> void {\n        for (auto [time, i] : query[v]) {\n            ans[i]\
    \ = fen.prefixProduct(time + 1);\n        }\n    }};\n    auto reset{[](){}};\n\
    \    sack.execute(0, add, del, answer, reset);\n    for (auto v : ans) {\n   \
    \     std::cout << v << '\\n';\n    }\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Tree/Sack.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/DataStructure/FenwickTree/FenwickTree.hpp
  isVerificationFile: true
  path: Test/LC/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2024-02-11 01:31:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/vertex_add_subtree_sum.test.cpp
- /verify/Test/LC/vertex_add_subtree_sum.test.cpp.html
title: Test/LC/vertex_add_subtree_sum.test.cpp
---
