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
    path: Src/DataStructure/PrefixSum/Imos2D.hpp
    title: Src/DataStructure/PrefixSum/Imos2D.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/PrefixSum/PrefixSum2D.hpp
    title: Src/DataStructure/PrefixSum/PrefixSum2D.hpp
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
    - https://atcoder.jp/contests/abc434/submissions/71356471
    - https://atcoder.jp/contests/abc434/tasks/abc434_d
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc434_d.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/abc434/tasks/abc434_d\"\n\n\
    /*\n * AtCoder Beginner Contest 434 D - Clouds\n * https://atcoder.jp/contests/abc434/submissions/71356471\n\
    \ */\n\n#line 2 \"Src/DataStructure/PrefixSum/PrefixSum2D.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\
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
    \n} // namespace zawa\n#line 5 \"Src/DataStructure/PrefixSum/PrefixSum2D.hpp\"\
    \n\n#include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace zawa\
    \ {\n\nnamespace internal {\n\ntemplate <concepts::Group G>\nclass StaticRectSumSolver\
    \ {\npublic:\n    \n    using T = typename G::Element;\n\n    explicit StaticRectSumSolver(const\
    \ std::vector<std::vector<T>>& a) : m_H{a.size()}, m_W{a.empty() ? 0u : a[0].size()},\
    \ m_sum(m_H + 1, std::vector<T>(m_W + 1, G::identity())) {\n        for (usize\
    \ i = 0 ; i < m_H ; i++)\n            for (usize j = 0 ; j < m_W ; j++)\n    \
    \            m_sum[i + 1][j + 1] = G::operation(\n                        G::operation(m_sum[i\
    \ + 1][j], m_sum[i][j + 1]), \n                        G::operation(G::inverse(m_sum[i][j]),\
    \ a[i][j])\n                        );\n    }\n\n    inline usize height() const\
    \ {\n        return m_H;\n    }\n\n    inline usize width() const {\n        return\
    \ m_W;\n    }\n\n    // [l, r) x [d, u)\n    T product(usize l, usize d, usize\
    \ r, usize u) const {\n        assert((l <= r and r <= height()) and \"invalid\
    \ i range: StaticRectSumSolver::product\");\n        assert((d <= u and u <= width())\
    \ and \"invalid j range: StaticRectSumSolver::product\");\n        return G::operation(\n\
    \                G::operation(m_sum[r][u], m_sum[l][d]),\n                G::inverse(G::operation(m_sum[r][d],\
    \ m_sum[l][u]))\n                );\n    }\n\n    const std::vector<T>& operator[](usize\
    \ i) const {\n        assert(i <= height() and \"invalid access m_sum[i]: StaticRectSumSolver::operator[]\"\
    );\n        return m_sum[i];\n    }\n\nprivate:\n\n    usize m_H, m_W;\n\n   \
    \ std::vector<std::vector<T>> m_sum;\n};\n\n} // namespace internal\n\ntemplate\
    \ <concepts::Group G>\nclass Ruisekiwa2D {\npublic:\n    \n    using T = typename\
    \ G::Element;\n\n    Ruisekiwa2D(usize H, usize W) : m_H{H}, m_W{W}, m_a(H, std::vector<T>(W,\
    \ G::identity())) {}\n\n    explicit Ruisekiwa2D(std::vector<std::vector<T>>&&\
    \ a) : m_H{a.size()}, m_W{a.empty() ? 0u : a[0].size()}, m_a{std::move(a)} {}\n\
    \n    explicit Ruisekiwa2D(const std::vector<std::vector<T>>& a) : m_H{a.size()},\
    \ m_W{a.empty() ? 0u : a[0].size()}, m_a{a} {}\n\n    inline usize height() const\
    \ {\n        return m_H;\n    }\n\n    inline usize width() const {\n        return\
    \ m_W;\n    }\n\n    void operation(usize i, usize j, T v) {\n        assert((i\
    \ < height() and j < width()) and \"invalid range: Ruisekiwa2D::add\");\n    \
    \    m_a[i][j] = G::operation(m_a[i][j], v);\n    }\n\n    const std::vector<T>&\
    \ operator[](const usize i) const {\n        assert(i < height() and \"invalid\
    \ range: Ruisekiwa2D::operator[]\");\n        return m_a[i];\n    }\n\n    internal::StaticRectSumSolver<G>\
    \ build() const {\n        return internal::StaticRectSumSolver<G>{m_a};\n   \
    \ }\n\n\nprivate:\n\n    usize m_H = 0, m_W = 0;\n\n    std::vector<std::vector<T>>\
    \ m_a;\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/PrefixSum/Imos2D.hpp\"\
    \n\n#line 5 \"Src/DataStructure/PrefixSum/Imos2D.hpp\"\n\n#line 9 \"Src/DataStructure/PrefixSum/Imos2D.hpp\"\
    \n\nnamespace zawa {\n\nnamespace internal {\n\ntemplate <concepts::Group G>\n\
    class StaticRectAddSolver {\npublic:\n    \n    using T = typename G::Element;\n\
    \n    explicit StaticRectAddSolver(const std::vector<std::vector<T>>& imos) :\
    \ m_H{imos.size() - 1}, m_W{imos[0].size() - 1}, m_a(imos) {\n        for (usize\
    \ i = 0 ; i < m_H ; i++)\n            for (usize j = 1 ; j <= m_W ; j++)\n   \
    \             m_a[i][j] = G::operation(m_a[i][j], m_a[i][j - 1]);\n        for\
    \ (usize i = 1 ; i <= m_H ; i++)\n            for (usize j = 0 ; j < m_W ; j++)\n\
    \                m_a[i][j] = G::operation(m_a[i][j], m_a[i - 1][j]);\n    }\n\n\
    \    inline usize height() const {\n        return m_H;\n    }\n\n    inline usize\
    \ width() const {\n        return m_W;\n    }\n\n    const std::vector<T>& operator[](usize\
    \ i) const {\n        assert(i < height() and \"invalid access m_sum[i]: StaticRectSumSolver::operator[]\"\
    );\n        return m_a[i];\n    }\n\nprivate:\n\n    usize m_H, m_W;\n\n    std::vector<std::vector<T>>\
    \ m_a;\n};\n\n} // namespace internal\n\ntemplate <concepts::Group G>\nclass Imos2D\
    \ {\npublic:\n    \n    using T = typename G::Element;\n\n    Imos2D(usize H,\
    \ usize W) : m_H{H}, m_W{W}, m_imos(H + 1, std::vector<T>(W + 1, G::identity()))\
    \ {}\n\n    inline usize height() const {\n        return m_H;\n    }\n\n    inline\
    \ usize width() const {\n        return m_W;\n    }\n\n    // [l, r) x [d, u)\n\
    \    void operation(usize l, usize d, usize r, usize u, T v) {\n        assert((l\
    \ <= r and r <= height()) and \"invalid i range: Imos2D::add\");\n        assert((d\
    \ <= u and u <= width()) and \"invalid j range: Imos2D::add\");\n        T inv\
    \ = G::inverse(v);\n        m_imos[l][d] = G::operation(m_imos[l][d], v);\n  \
    \      m_imos[l][u] = G::operation(m_imos[l][u], inv);\n        m_imos[r][d] =\
    \ G::operation(m_imos[r][d], inv);\n        m_imos[r][u] = G::operation(m_imos[r][u],\
    \ v);\n    }\n\n    const std::vector<T>& operator[](const usize i) const {\n\
    \        assert(i < height() and \"invalid range: Imos2D::operator[]\");\n   \
    \     return m_imos[i];\n    }\n\n    internal::StaticRectAddSolver<G> build()\
    \ const {\n        return internal::StaticRectAddSolver<G>{m_imos};\n    }\n\n\
    private:\n\n    usize m_H = 0, m_W = 0;\n\n    std::vector<std::vector<T>> m_imos;\n\
    };\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\n\
    namespace zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n    using\
    \ Element = T;\n    static constexpr T identity() noexcept {\n        return T{};\n\
    \    }\n    static constexpr T operation(const T& l, const T& r) noexcept {\n\
    \        return l + r;\n    }\n    static constexpr T inverse(const T& v) noexcept\
    \ {\n        return -v;\n    }\n};\n\n} // namespace zawa\n#line 12 \"Test/AtCoder/abc434_d.test.cpp\"\
    \n\n#include <iostream>\n#line 15 \"Test/AtCoder/abc434_d.test.cpp\"\n#include\
    \ <tuple>\nusing namespace std;\nusing namespace zawa;\n\nint main() {\n    cin.tie(0);\n\
    \    cout.tie(0);\n    ios::sync_with_stdio(0);\n#ifdef ATCODER\n    const int\
    \ MAX = 2000;\n    int N;\n    cin >> N;\n    Imos2D<AdditiveGroup<int>> imos(MAX,\
    \ MAX);\n    vector<tuple<int, int, int, int>> A(N);\n    for (auto& [l, r, d,\
    \ u] : A) {\n        cin >> l >> r >> d >> u;\n        l--;\n        d--;\n  \
    \      imos.operation(l, d, r, u, 1);\n    }\n    auto a = imos.build();\n   \
    \ Ruisekiwa2D<AdditiveGroup<int>> sum(MAX, MAX);\n    int base = 0;\n    for (int\
    \ i = 0 ; i < MAX ; i++)\n        for (int j = 0 ; j < MAX ; j++) {\n        \
    \    if (a[i][j] == 0)\n                base++;\n            else if (a[i][j]\
    \ == 1)\n                sum.operation(i, j, 1);\n        }\n    auto solver =\
    \ sum.build();\n    for (auto [l, r, d, u] : A) {\n        int ans = base + solver.product(l,\
    \ d, r, u);\n        cout << ans << '\\n';\n    }\n#else\n    cout << \"Hello\
    \ World\\n\";\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/abc434/tasks/abc434_d\"\n\n\
    /*\n * AtCoder Beginner Contest 434 D - Clouds\n * https://atcoder.jp/contests/abc434/submissions/71356471\n\
    \ */\n\n#include \"../../Src/DataStructure/PrefixSum/PrefixSum2D.hpp\"\n#include\
    \ \"../../Src/DataStructure/PrefixSum/Imos2D.hpp\"\n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n#include <tuple>\nusing namespace\
    \ std;\nusing namespace zawa;\n\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n#ifdef ATCODER\n    const int MAX = 2000;\n   \
    \ int N;\n    cin >> N;\n    Imos2D<AdditiveGroup<int>> imos(MAX, MAX);\n    vector<tuple<int,\
    \ int, int, int>> A(N);\n    for (auto& [l, r, d, u] : A) {\n        cin >> l\
    \ >> r >> d >> u;\n        l--;\n        d--;\n        imos.operation(l, d, r,\
    \ u, 1);\n    }\n    auto a = imos.build();\n    Ruisekiwa2D<AdditiveGroup<int>>\
    \ sum(MAX, MAX);\n    int base = 0;\n    for (int i = 0 ; i < MAX ; i++)\n   \
    \     for (int j = 0 ; j < MAX ; j++) {\n            if (a[i][j] == 0)\n     \
    \           base++;\n            else if (a[i][j] == 1)\n                sum.operation(i,\
    \ j, 1);\n        }\n    auto solver = sum.build();\n    for (auto [l, r, d, u]\
    \ : A) {\n        int ans = base + solver.product(l, d, r, u);\n        cout <<\
    \ ans << '\\n';\n    }\n#else\n    cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/DataStructure/PrefixSum/PrefixSum2D.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/DataStructure/PrefixSum/Imos2D.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc434_d.test.cpp
  requiredBy: []
  timestamp: '2025-11-30 18:03:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc434_d.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc434_d.test.cpp
- /verify/Test/AtCoder/abc434_d.test.cpp.html
title: Test/AtCoder/abc434_d.test.cpp
---
