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
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/FenwickTree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/Sack.hpp
    title: Sack
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
    - https://codeforces.com/contest/600/problem/E
    - https://codeforces.com/contest/600/submission/325866149
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/CF/EC2-E.test.cpp\"\n// #define PROBLEM \"https://codeforces.com/contest/600/problem/E\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/Graph/Tree/Sack.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Tree/Sack.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\nclass Sack {\nprivate:\
    \    \n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n    usize n_{};\n\
    \    std::vector<std::vector<u32>> g_;\n    std::vector<u32> sz_, euler_, L_,\
    \ R_;\n\n    u32 dfsHLD(u32 v, u32 p) {\n        sz_[v] = 1;\n        usize m{g_[v].size()};\n\
    \        usize max{};\n        if (m > 1u and g_[v][0] == p) std::swap(g_[v][0],\
    \ g_[v][1]);\n        for (u32 i{} ; i < m ; i++) if (g_[v][i] != p) {\n     \
    \       sz_[v] += dfsHLD(g_[v][i], v);\n            if (max < sz_[g_[v][i]]) {\n\
    \                max = sz_[g_[v][i]];\n                if (i) std::swap(g_[v][0],\
    \ g_[v][i]);\n            }\n        }\n        return sz_[v];\n    }\n\n    void\
    \ dfsEuler(u32 v, u32 p, u32& t) {\n        euler_[t] = v;\n        L_[v] = t++;\n\
    \        for (auto x : g_[v]) if (x != p) {\n            dfsEuler(x, v, t);\n\
    \        }\n        R_[v] = t;\n    }\n\npublic:\n    constexpr usize size() const\
    \ noexcept {\n        return n_;\n    }\n\n    Sack() = default;\n    Sack(u32\
    \ n) \n        : n_{n}, g_(n), sz_(n), euler_(n), L_(n), R_(n) {\n        assert(n);\n\
    \        g_.shrink_to_fit();\n        sz_.shrink_to_fit();\n        euler_.shrink_to_fit();\n\
    \        L_.shrink_to_fit();\n        R_.shrink_to_fit();\n    }\n    void addEdge(u32\
    \ u, u32 v) {\n        assert(u < size());\n        assert(v < size());\n    \
    \    g_[u].emplace_back(v);\n        g_[v].emplace_back(u);\n    }\n\n    const\
    \ std::vector<u32>& operator[](u32 v) const noexcept {\n        assert(v < size());\n\
    \        return g_[v];\n    }\n\n    template <class ADD, class DEL, class QUERY,\
    \ class RESET>\n    u32 execute(u32 root, const ADD& add, const DEL& del, const\
    \ QUERY& query, const RESET& reset) {\n        dfsHLD(root, INVALID);\n      \
    \  u32 t{};\n        dfsEuler(root, INVALID, t);\n        \n        auto sack{[&](auto\
    \ dfs, u32 v, u32 p, bool keep) -> void {\n            usize m{g_[v].size()};\n\
    \            for (u32 i{1} ; i < m ; i++) if (g_[v][i] != p) {\n             \
    \   dfs(dfs, g_[v][i], v, false);\n            }\n            if (sz_[v] > 1u)\
    \ dfs(dfs, g_[v][0], v, true);\n            if (sz_[v] > 1u) {\n             \
    \   for (u32 i{R_[g_[v][0]]} ; i < R_[v] ; i++) {\n                    add(euler_[i]);\n\
    \                }\n            }\n            add(v);\n            query(v);\n\
    \            if (!keep) {\n                for (u32 i{L_[v]} ; i < R_[v] ; i++)\
    \ {\n                    del(euler_[i]);\n                }\n                reset();\n\
    \            }\n        }};\n        sack(sack, root, INVALID, false);\n\n   \
    \     return sz_[root];\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n \
    \   using Element = T;\n    static constexpr T identity() noexcept {\n       \
    \ return T{};\n    }\n    static constexpr T operation(const T& l, const T& r)\
    \ noexcept {\n        return l + r;\n    }\n    static constexpr T inverse(const\
    \ T& v) noexcept {\n        return -v;\n    }\n};\n\n} // namespace zawa\n#line\
    \ 2 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n\n#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T>\nconcept Semigroup = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Inversible\
    \ = requires {\n    typename T::Element;\n    { T::inverse(std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\ntemplate <class\
    \ T>\nconcept Group = Monoid<T> and Inversible<T>;\n\n} // namespace Concept\n\
    \n} // namespace zawa\n#line 5 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\n#line 8 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n#include <ostream>\n\
    #include <functional>\n#include <type_traits>\n\nnamespace zawa {\n\ntemplate\
    \ <concepts::Group Group>\nclass FenwickTree {\npublic:\n\n    using VM = Group;\n\
    \    \n    using V = typename VM::Element;\n\n    FenwickTree() = default;\n\n\
    \    explicit FenwickTree(usize n) : m_n{ n }, m_bitwidth{ std::__lg(n) + 1 },\
    \ m_a(n), m_dat(n + 1, VM::identity()) {\n        m_dat.shrink_to_fit();\n   \
    \     m_a.shrink_to_fit();\n    }\n\n    explicit FenwickTree(const std::vector<V>&\
    \ a) : m_n{ a.size() }, m_bitwidth{ std::__lg(a.size()) + 1 }, m_a(a), m_dat(a.size()\
    \ + 1, VM::identity()) {\n        m_dat.shrink_to_fit();  \n        m_a.shrink_to_fit();\n\
    \        for (i32 i{} ; i < static_cast<i32>(m_n) ; i++) {\n            addDat(i,\
    \ a[i]);\n        }\n    }\n\n    inline usize size() const noexcept {\n     \
    \   return m_n;\n    }\n\n    // return a[i]\n    const V& get(usize i) const\
    \ noexcept {\n        assert(i < size());\n        return m_a[i];\n    }\n\n \
    \   // return a[i]\n    const V& operator[](usize i) const noexcept {\n      \
    \  assert(i < size());\n        return m_a[i];\n    }\n\n    // a[i] <- a[i] +\
    \ v\n    void operation(usize i, const V& v) {\n        assert(i < size());\n\
    \        addDat(i, v);\n        m_a[i] = VM::operation(m_a[i], v);\n    }\n\n\
    \    // a[i] <- v\n    void assign(usize i, const V& v) {\n        assert(i <\
    \ size());\n        addDat(i, VM::operation(VM::inverse(m_a[i]), v));\n      \
    \  m_a[i] = v;\n    }\n\n    // return a[0] + a[1] + ... + a[r - 1]\n    V prefixProduct(usize\
    \ r) const {\n        assert(r <= size());\n        return product(r);\n    }\n\
    \n    // return a[l] + a[l + 1] ... + a[r - 1]\n    V product(usize l, usize r)\
    \ const {\n        assert(l <= r and r <= size());\n        return VM::operation(VM::inverse(product(l)),\
    \ product(r));\n    }\n\n    template <class Function>\n    usize maxRight(usize\
    \ l, const Function& f) const {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(V)>>, \"maxRight's argument f must be function bool(T)\"\
    );\n        assert(l < size());\n        V sum{ VM::inverse(product(l)) }; \n\
    \        usize r{};\n        for (usize bit{ m_bitwidth } ; bit ; ) {\n      \
    \      bit--;\n            usize nxt{ r | (1u << bit) };\n            if (nxt\
    \ < m_dat.size() and f(VM::operation(sum, m_dat[nxt]))) {\n                sum\
    \ = VM::operation(sum, m_dat[nxt]);\n                r = std::move(nxt);\n   \
    \         }\n        }\n        assert(l <= r);\n        return r;\n    }\n\n\
    \    template <class Function>\n    usize minLeft(usize r, const Function& f)\
    \ const {\n        static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>,\
    \ \"minLeft's argument f must be function bool(T)\");\n        assert(r <= size());\n\
    \        V sum{ product(r) };\n        usize l{};\n        for (usize bit{ m_bitwidth\
    \ } ; bit ; ) {\n            bit--;\n            usize nxt{ l | (1u << bit) };\n\
    \            if (nxt <= r and not f(VM::operation(VM::inverse(m_dat[nxt]), sum)))\
    \ {\n                sum = VM::operation(VM::inverse(m_dat[nxt]), sum);\n    \
    \            l = std::move(nxt);\n            }\n        }\n        assert(l <=\
    \ r);\n        return l;\n    }\n\n    // debug print\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const FenwickTree& ft) {\n        for (usize i{}\
    \ ; i <= ft.size() ; i++) {\n            os << ft.prefixProduct(i) << (i == ft.size()\
    \ ? \"\" : \" \");\n        }\n        return os;\n    }\n\nprivate:\n\n    usize\
    \ m_n{};\n\n    usize m_bitwidth{};\n\n    std::vector<V> m_a, m_dat;\n\n    constexpr\
    \ i32 lsb(i32 x) const noexcept {\n        return x & -x;\n    }\n    \n    //\
    \ a[i] <- a[i] + v\n    void addDat(i32 i, const V& v) {\n        assert(0 <=\
    \ i and i < static_cast<i32>(m_n));\n        for ( i++ ; i < static_cast<i32>(m_dat.size())\
    \ ; i += lsb(i)) {\n            m_dat[i] = VM::operation(m_dat[i], v);\n     \
    \   }\n    }\n\n    // return a[0] + a[1] + .. + a[i - 1]\n    V product(i32 i)\
    \ const {\n        assert(0 <= i and i <= static_cast<i32>(m_n));\n        V res{\
    \ VM::identity() };\n        for ( ; i > 0 ; i -= lsb(i)) {\n            res =\
    \ VM::operation(res, m_dat[i]);\n        }\n        return res;\n    }\n\n};\n\
    \n} // namespace zawa\n#line 7 \"Test/CF/EC2-E.test.cpp\"\n\n#include <iostream>\n\
    #line 10 \"Test/CF/EC2-E.test.cpp\"\n\nusing namespace zawa;\n\n/*\n * Educational\
    \ Codeforces Round 2 - E Lomsat general\n * https://codeforces.com/contest/600/submission/325866149\n\
    \ */\n\nvoid solve() {\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n; std::cin >> n;\n    std::vector<int>\
    \ c(n);\n    for (auto& x : c) {\n        std::cin >> x;\n        x--;\n    }\n\
    \    Sack sack(n);\n    for (int _{} ; _ < n - 1 ; _++) {\n        int u, v; std::cin\
    \ >> u >> v;\n        u--; v--;\n        sack.addEdge(u, v);\n    }\n\n    FenwickTree<AdditiveGroup<long\
    \ long>> fen(n + 1);\n    std::vector<int> num(n);\n    std::vector<long long>\
    \ ans(n);\n\n    auto add{[&](int v) -> void {\n        fen.operation(num[c[v]],\
    \ -(c[v] + 1));\n        num[c[v]]++;\n        fen.operation(num[c[v]], c[v] +\
    \ 1);\n    }};\n    auto del{[&](int v) -> void {\n        fen.operation(num[c[v]],\
    \ -(c[v] + 1));\n        num[c[v]]--;\n        fen.operation(num[c[v]], c[v] +\
    \ 1);\n    }};\n    auto query{[&](int v) -> void {\n        auto it{fen.minLeft(n\
    \ + 1, [](const auto& x) -> bool { return x == 0LL; })};\n        ans[v] = fen[it];\n\
    \    }};\n    auto reset{[](){}};\n    sack.execute(0, add, del, query, reset);\n\
    \    for (int i{} ; i < n ; i++) {\n        std::cout << ans[i] << (i + 1 == n\
    \ ? '\\n' : ' ');\n    }\n}\n\nint main() {\n#ifdef ONLINE_JUDGE\n    solve();\n\
    #else\n    std::cout << \"Hello World\" << '\\n';\n#endif\n}\n"
  code: "// #define PROBLEM \"https://codeforces.com/contest/600/problem/E\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/Graph/Tree/Sack.hpp\"\n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\
    \n#include \"../../Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n\n#include\
    \ <iostream>\n#include <vector>\n\nusing namespace zawa;\n\n/*\n * Educational\
    \ Codeforces Round 2 - E Lomsat general\n * https://codeforces.com/contest/600/submission/325866149\n\
    \ */\n\nvoid solve() {\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n; std::cin >> n;\n    std::vector<int>\
    \ c(n);\n    for (auto& x : c) {\n        std::cin >> x;\n        x--;\n    }\n\
    \    Sack sack(n);\n    for (int _{} ; _ < n - 1 ; _++) {\n        int u, v; std::cin\
    \ >> u >> v;\n        u--; v--;\n        sack.addEdge(u, v);\n    }\n\n    FenwickTree<AdditiveGroup<long\
    \ long>> fen(n + 1);\n    std::vector<int> num(n);\n    std::vector<long long>\
    \ ans(n);\n\n    auto add{[&](int v) -> void {\n        fen.operation(num[c[v]],\
    \ -(c[v] + 1));\n        num[c[v]]++;\n        fen.operation(num[c[v]], c[v] +\
    \ 1);\n    }};\n    auto del{[&](int v) -> void {\n        fen.operation(num[c[v]],\
    \ -(c[v] + 1));\n        num[c[v]]--;\n        fen.operation(num[c[v]], c[v] +\
    \ 1);\n    }};\n    auto query{[&](int v) -> void {\n        auto it{fen.minLeft(n\
    \ + 1, [](const auto& x) -> bool { return x == 0LL; })};\n        ans[v] = fen[it];\n\
    \    }};\n    auto reset{[](){}};\n    sack.execute(0, add, del, query, reset);\n\
    \    for (int i{} ; i < n ; i++) {\n        std::cout << ans[i] << (i + 1 == n\
    \ ? '\\n' : ' ');\n    }\n}\n\nint main() {\n#ifdef ONLINE_JUDGE\n    solve();\n\
    #else\n    std::cout << \"Hello World\" << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Graph/Tree/Sack.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/DataStructure/FenwickTree/FenwickTree.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: true
  path: Test/CF/EC2-E.test.cpp
  requiredBy: []
  timestamp: '2025-06-24 20:48:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/CF/EC2-E.test.cpp
layout: document
redirect_from:
- /verify/Test/CF/EC2-E.test.cpp
- /verify/Test/CF/EC2-E.test.cpp.html
title: Test/CF/EC2-E.test.cpp
---
