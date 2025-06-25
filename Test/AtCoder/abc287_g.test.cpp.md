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
    path: Src/Sequence/CompressedSequence.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
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
    - https://atcoder.jp/contests/abc287/submissions/67045318
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc287_g.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Sequence/CompressedSequence.hpp\"\n\n\
    #line 4 \"Src/Sequence/CompressedSequence.hpp\"\n\n#include <vector>\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iterator>\n#include <limits>\n\n\
    namespace zawa {\n\ntemplate <class T>\nclass CompressedSequence {\npublic:\n\n\
    \    static constexpr u32 NotFound = std::numeric_limits<u32>::max();\n\n    CompressedSequence()\
    \ = default;\n\n    template <class InputIterator>\n    CompressedSequence(InputIterator\
    \ first, InputIterator last) : comped_(first, last), f_{} {\n        std::sort(comped_.begin(),\
    \ comped_.end());\n        comped_.erase(std::unique(comped_.begin(), comped_.end()),\
    \ comped_.end());\n        comped_.shrink_to_fit();\n        f_.reserve(std::distance(first,\
    \ last));\n        for (auto it{first} ; it != last ; it++) {\n            f_.emplace_back(std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), *it)));\n        }\n    }\n\
    \n    CompressedSequence(const std::vector<T>& A) : CompressedSequence(A.begin(),\
    \ A.end()) {}\n\n    inline usize size() const noexcept {\n        return comped_.size();\n\
    \    }\n\n    u32 operator[](const T& v) const {\n        return std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), v));\n    }\n\n    u32 upper_bound(const\
    \ T& v) const {\n        return std::distance(comped_.begin(), std::upper_bound(comped_.begin(),\
    \ comped_.end(), v));\n    }\n\n    u32 find(const T& v) const {\n        u32\
    \ i = std::distance(comped_.begin(), std::lower_bound(comped_.begin(), comped_.end(),\
    \ v));\n        return i == comped_.size() or comped_[i] != v ? NotFound : i;\n\
    \    }\n\n    bool contains(const T& v) const {\n        u32 i = std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), v));\n        return i < comped_.size()\
    \ and comped_[i] == v;\n    }\n\n    u32 at(const T& v) const {\n        u32 res\
    \ = find(v);\n        assert(res != NotFound);\n        return res;\n    }\n\n\
    \    inline u32 map(u32 i) const noexcept {\n        assert(i < f_.size());\n\
    \        return f_[i];\n    }\n\n    inline T inverse(u32 i) const noexcept {\n\
    \        assert(i < size());\n        return comped_[i];\n    }\n\n    inline\
    \ std::vector<T> comped() const noexcept {\n        return comped_;\n    }\n\n\
    private:\n\n    std::vector<T> comped_;\n\n    std::vector<u32> f_;\n\n};\n\n\
    } // namespace zawa\n#line 2 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\n#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
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
    \n} // namespace zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace\
    \ zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n    using Element\
    \ = T;\n    static constexpr T identity() noexcept {\n        return T{};\n  \
    \  }\n    static constexpr T operation(const T& l, const T& r) noexcept {\n  \
    \      return l + r;\n    }\n    static constexpr T inverse(const T& v) noexcept\
    \ {\n        return -v;\n    }\n};\n\n} // namespace zawa\n#line 7 \"Test/AtCoder/abc287_g.test.cpp\"\
    \n\n#line 11 \"Test/AtCoder/abc287_g.test.cpp\"\n\n/*\n * AtCoder Beginner Contest\
    \ 287 G - Balance Update Query\n * https://atcoder.jp/contests/abc287/submissions/67045318\n\
    \ */\n\nvoid solve() {\n    using namespace zawa;\n    SetFastIO();\n    int n;\
    \ std::cin >> n;\n    std::vector<int> a(n), b(n);\n    for (int i{} ; i < n ;\
    \ i++) {\n        std::cin >> a[i] >> b[i];\n    }\n    int q; std::cin >> q;\n\
    \    std::vector<int> t(q), x(q), y(q);\n    for (int i{} ; i < q ; i++) {\n \
    \       std::cin >> t[i] >> x[i];\n        if (t[i] == 1 or t[i] == 2) {\n   \
    \         x[i]--;\n            std::cin >> y[i];\n        }\n    }\n    std::vector<int>\
    \ app;\n    app.reserve(n + q);\n    for (int i{} ; i < n ; i++) app.push_back(a[i]);\n\
    \    for (int i{} ; i < q ; i++) if (t[i] == 1) app.push_back(y[i]);\n\n    CompressedSequence<int>\
    \ comp{ app.begin(), app.end() };\n    usize m{comp.size()};\n    FenwickTree<AdditiveGroup<int>>\
    \ ft1(m);\n    FenwickTree<AdditiveGroup<long long>> ft2(m);\n\n    for (int i{}\
    \ ; i < n ; i++) {\n        ft1.operation(comp[a[i]], b[i]);\n        ft2.operation(comp[a[i]],\
    \ (long long)a[i] * (long long)b[i]);\n    }\n\n    auto calcByMaxRight{[&](int\
    \ query) -> long long {\n        if (query > ft1.prefixProduct(m)) return -1LL;\n\
    \        query = ft1.prefixProduct(m) - query;\n        long long res{ft2.prefixProduct(m)};\n\
    \        auto it{ft1.maxRight(0, [&](int v) -> bool { return v <= query; })};\n\
    \        query -= ft1.prefixProduct(it);\n        res -= ft2.prefixProduct(it);\n\
    \        if (it < m) {\n            res -= (long long)comp.inverse(it) * query;\n\
    \        }\n        return res;\n    }};\n\n    auto calcByMinLeft{[&](int query)\
    \ -> long long {\n        if (query > ft1.prefixProduct(m)) return -1LL;\n   \
    \     auto it{ft1.minLeft(m, [&](int v) -> bool { return v <= query; })};\n  \
    \      query -= (it + 1 == m ? 0 : ft1.product(it + 1, m));\n        long long\
    \ res{it + 1 == m ? 0LL : ft2.product(it + 1, m)};\n        res += (long long)comp.inverse(it)\
    \ * query;\n        return res;\n    }};\n\n    for (int i{} ; i < q ; i++) {\n\
    \        if (t[i] == 1) {\n            int v{x[i]};\n            ft1.operation(comp.at(a[v]),\
    \ -b[v]);\n            ft2.operation(comp[a[v]], (long long)-a[v] * (long long)b[v]);\n\
    \            a[v] = y[i];\n            ft1.operation(comp[a[v]], b[v]);\n    \
    \        ft2.operation(comp[a[v]], (long long)a[v] * (long long)b[v]);\n     \
    \   }\n        else if (t[i] == 2) {\n            int v{x[i]};\n            ft1.operation(comp[a[v]],\
    \ -b[v]);\n            ft2.operation(comp[a[v]], (long long)-a[v] * (long long)b[v]);\n\
    \            b[v] = y[i];\n            ft1.operation(comp[a[v]], b[v]);\n    \
    \        ft2.operation(comp[a[v]], (long long)a[v] * (long long)b[v]);\n     \
    \   }\n        else if (t[i] == 3) {\n            long long l{calcByMinLeft(x[i])},\
    \ r{calcByMaxRight(x[i])};\n            assert(l == r);\n            std::cout\
    \ << r << std::endl;\n        }\n        else {\n            assert(false);\n\
    \        }\n    }\n}\n\nint main() {\n#ifdef ATCODER\n    solve();\n#else\n  \
    \  std::cout << \"Hello World\" << '\\n';\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Sequence/CompressedSequence.hpp\"\
    \n#include \"../../Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n#include \"\
    ../../Src/Algebra/Group/AdditiveGroup.hpp\"\n\n#include <cassert>\n#include <iostream>\n\
    #include <vector>\n\n/*\n * AtCoder Beginner Contest 287 G - Balance Update Query\n\
    \ * https://atcoder.jp/contests/abc287/submissions/67045318\n */\n\nvoid solve()\
    \ {\n    using namespace zawa;\n    SetFastIO();\n    int n; std::cin >> n;\n\
    \    std::vector<int> a(n), b(n);\n    for (int i{} ; i < n ; i++) {\n       \
    \ std::cin >> a[i] >> b[i];\n    }\n    int q; std::cin >> q;\n    std::vector<int>\
    \ t(q), x(q), y(q);\n    for (int i{} ; i < q ; i++) {\n        std::cin >> t[i]\
    \ >> x[i];\n        if (t[i] == 1 or t[i] == 2) {\n            x[i]--;\n     \
    \       std::cin >> y[i];\n        }\n    }\n    std::vector<int> app;\n    app.reserve(n\
    \ + q);\n    for (int i{} ; i < n ; i++) app.push_back(a[i]);\n    for (int i{}\
    \ ; i < q ; i++) if (t[i] == 1) app.push_back(y[i]);\n\n    CompressedSequence<int>\
    \ comp{ app.begin(), app.end() };\n    usize m{comp.size()};\n    FenwickTree<AdditiveGroup<int>>\
    \ ft1(m);\n    FenwickTree<AdditiveGroup<long long>> ft2(m);\n\n    for (int i{}\
    \ ; i < n ; i++) {\n        ft1.operation(comp[a[i]], b[i]);\n        ft2.operation(comp[a[i]],\
    \ (long long)a[i] * (long long)b[i]);\n    }\n\n    auto calcByMaxRight{[&](int\
    \ query) -> long long {\n        if (query > ft1.prefixProduct(m)) return -1LL;\n\
    \        query = ft1.prefixProduct(m) - query;\n        long long res{ft2.prefixProduct(m)};\n\
    \        auto it{ft1.maxRight(0, [&](int v) -> bool { return v <= query; })};\n\
    \        query -= ft1.prefixProduct(it);\n        res -= ft2.prefixProduct(it);\n\
    \        if (it < m) {\n            res -= (long long)comp.inverse(it) * query;\n\
    \        }\n        return res;\n    }};\n\n    auto calcByMinLeft{[&](int query)\
    \ -> long long {\n        if (query > ft1.prefixProduct(m)) return -1LL;\n   \
    \     auto it{ft1.minLeft(m, [&](int v) -> bool { return v <= query; })};\n  \
    \      query -= (it + 1 == m ? 0 : ft1.product(it + 1, m));\n        long long\
    \ res{it + 1 == m ? 0LL : ft2.product(it + 1, m)};\n        res += (long long)comp.inverse(it)\
    \ * query;\n        return res;\n    }};\n\n    for (int i{} ; i < q ; i++) {\n\
    \        if (t[i] == 1) {\n            int v{x[i]};\n            ft1.operation(comp.at(a[v]),\
    \ -b[v]);\n            ft2.operation(comp[a[v]], (long long)-a[v] * (long long)b[v]);\n\
    \            a[v] = y[i];\n            ft1.operation(comp[a[v]], b[v]);\n    \
    \        ft2.operation(comp[a[v]], (long long)a[v] * (long long)b[v]);\n     \
    \   }\n        else if (t[i] == 2) {\n            int v{x[i]};\n            ft1.operation(comp[a[v]],\
    \ -b[v]);\n            ft2.operation(comp[a[v]], (long long)-a[v] * (long long)b[v]);\n\
    \            b[v] = y[i];\n            ft1.operation(comp[a[v]], b[v]);\n    \
    \        ft2.operation(comp[a[v]], (long long)a[v] * (long long)b[v]);\n     \
    \   }\n        else if (t[i] == 3) {\n            long long l{calcByMinLeft(x[i])},\
    \ r{calcByMaxRight(x[i])};\n            assert(l == r);\n            std::cout\
    \ << r << std::endl;\n        }\n        else {\n            assert(false);\n\
    \        }\n    }\n}\n\nint main() {\n#ifdef ATCODER\n    solve();\n#else\n  \
    \  std::cout << \"Hello World\" << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Sequence/CompressedSequence.hpp
  - Src/DataStructure/FenwickTree/FenwickTree.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc287_g.test.cpp
  requiredBy: []
  timestamp: '2025-06-24 20:48:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc287_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc287_g.test.cpp
- /verify/Test/AtCoder/abc287_g.test.cpp.html
title: Test/AtCoder/abc287_g.test.cpp
---
