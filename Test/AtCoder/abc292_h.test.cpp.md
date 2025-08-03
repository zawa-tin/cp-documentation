---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/AdditionMonoid.hpp
    title: Src/Algebra/Monoid/AdditionMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MaxMonoid.hpp
    title: "max\u6F14\u7B97\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/PrefixProductMonoid.hpp
    title: "\u533A\u9593Prefix\u7DCF\u7A4D\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/SegmentTree.hpp
    title: Segment Tree
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
    ERROR: 1e-9
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc292/submissions/68181944
    - https://atcoder.jp/contests/abc292/tasks/abc292_ex
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc292_h.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/abc292/tasks/abc292_ex\"\n\
    #define ERROR 1e-9\n\n/*\n * AtCoder Beginner Contest 292 Ex - Rating Estimator\n\
    \ * https://atcoder.jp/contests/abc292/submissions/68181944\n */\n\n#line 2 \"\
    Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include\
    \ <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 = std::int16_t;\n\
    using i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128 = __int128_t;\n\
    \nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\n} // namespace zawa\n\
    #line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n#include <iomanip>\n\
    \nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/AdditionMonoid.hpp\"\n\n\
    namespace zawa {\n\ntemplate <class T>\nstruct AdditionMonoid {\n    using Element\
    \ = T;\n    static T identity() noexcept {\n        return T{};\n    }\n    static\
    \ T operation(const T& a, const T& b) noexcept {\n        return a + b;\n    }\n\
    };\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MaxMonoid.hpp\"\n\n#include\
    \ <algorithm>\n#include <limits>\n#include <optional>\n\nnamespace zawa {\n\n\
    template <class T>\nclass MaxMonoid {\npublic:\n    using Element = std::optional<T>;\n\
    \    static constexpr Element identity() noexcept {\n        return std::nullopt;\n\
    \    }\n    static constexpr Element operation(const Element& l, const Element&\
    \ r) noexcept {\n        if (l and r) {\n            return std::max(l, r);\n\
    \        }\n        else if (l) {\n            return l;\n        }\n        else\
    \ if (r) {\n            return r;\n        }\n        else {\n            return\
    \ std::nullopt;\n        }\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/PrefixProductMonoid.hpp\"\
    \n\n#include <type_traits>\n\nnamespace zawa {\n\ntemplate <class Value>\nclass\
    \ PrefixProductMonoidData {\n    Value product_{}, prefix_{};\npublic:\n    PrefixProductMonoidData()\
    \ = default;\n    PrefixProductMonoidData(const Value& product, const Value& prefix)\n\
    \        : product_{product}, prefix_{prefix} {}\n\n    inline const Value& product()\
    \ const noexcept {\n        return product_;\n    }\n    inline const Value& prefix()\
    \ const noexcept {\n        return prefix_;\n    }\n};\n\ntemplate <class O, class\
    \ F>\nclass PrefixProductMonoid {\n    static_assert(std::is_same_v<typename O::Element,\
    \ typename F::Element>);\npublic:\n    using Element = PrefixProductMonoidData<typename\
    \ O::Element>;\n    static Element identity() noexcept {\n        return PrefixProductMonoidData{O::identity(),\
    \ F::identity()};\n    }\n    static Element operation(const Element& l, const\
    \ Element& r) noexcept {\n        return PrefixProductMonoidData{\n          \
    \  O::operation(l.product(), r.product()),\n            F::operation(l.prefix(),\
    \ O::operation(l.product(), r.prefix()))\n        };\n    }\n};\n\n} // namespace\
    \ zawa\n#line 2 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\n\n#line 2 \"\
    Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T>\nconcept Semigroup = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n#include <functional>\n#line 10 \"\
    Src/DataStructure/SegmentTree/SegmentTree.hpp\"\n#include <ostream>\n\nnamespace\
    \ zawa {\n\ntemplate <concepts::Monoid Monoid>\nclass SegmentTree {\npublic:\n\
    \n    using VM = Monoid;\n\n    using V = typename VM::Element;\n\n    using OM\
    \ = Monoid;\n\n    using O = typename OM::Element;\n\n    SegmentTree() = default;\n\
    \n    explicit SegmentTree(usize n) : m_n{ n }, m_dat(n << 1, VM::identity())\
    \ {}\n\n    explicit SegmentTree(const std::vector<V>& dat) : m_n{ dat.size()\
    \ }, m_dat(dat.size() << 1, VM::identity()) {\n        for (usize i{} ; i < m_n\
    \ ; i++) {\n            m_dat[i + m_n] = dat[i];\n        }\n        for (usize\
    \ i{m_n} ; i-- ; ) {\n            m_dat[i] = VM::operation(m_dat[left(i)], m_dat[right(i)]);\n\
    \        }\n    }\n\n    [[nodiscard]] inline usize size() const noexcept {\n\
    \        return m_n;\n    }\n\n    [[nodiscard]] V get(usize i) const {\n    \
    \    assert(i < size());\n        return m_dat[i + m_n];\n    }\n\n    [[nodiscard]]\
    \ V operator[](usize i) const {\n        assert(i < size());\n        return m_dat[i\
    \ + m_n];\n    }\n\n    void operation(usize i, const O& value) {\n        assert(i\
    \ < size());\n        i += size();\n        m_dat[i] = OM::operation(m_dat[i],\
    \ value);\n        while (i = parent(i), i) {\n            m_dat[i] = VM::operation(m_dat[left(i)],\
    \ m_dat[right(i)]);\n        }\n    }\n\n    void assign(usize i, const V& value)\
    \ {\n        assert(i < size());\n        i += size();\n        m_dat[i] = value;\n\
    \        while (i = parent(i), i) {\n            m_dat[i] = VM::operation(m_dat[left(i)],\
    \ m_dat[right(i)]);\n        }\n    }\n\n    [[nodiscard]] V product(u32 l, u32\
    \ r) const {\n        assert(l <= r and r <= size());\n        V L{ VM::identity()\
    \ }, R{ VM::identity() };\n        for (l += size(), r += size() ; l < r ; l =\
    \ parent(l), r = parent(r)) {\n            if (l & 1) {\n                L = VM::operation(L,\
    \ m_dat[l++]);\n            }\n            if (r & 1) {\n                R = VM::operation(m_dat[--r],\
    \ R);\n            }\n        }\n        return VM::operation(L, R);\n    }\n\n\
    \    template <class F>\n    requires std::predicate<F, V>\n    [[nodiscard]]\
    \ usize maxRight(usize l, const F& f) {\n        assert(l < size());\n       \
    \ static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>, \"\
    maxRight's argument f must be function bool(T)\");\n        assert(f(VM::identity()));\n\
    \        usize res{l}, width{1};\n        V prod{ VM::identity() };\n        //\
    \ \u73FE\u5728\u306E\u898B\u3066\u3044\u308B\u9802\u70B9\u306E\u5E45\u3092width\u3067\
    \u6301\u3064\n        // \u5883\u754C\u304C\u3042\u308B\u9802\u70B9\u3092\u542B\
    \u3080\u90E8\u5206\u6728\u306E\u6839\u3092\u63A2\u3059\n        // (\u6298\u308A\
    \u8FD4\u3059\u6642\u306F\u5FC5\u8981\u4EE5\u4E0A\u306E\u5E45\u3092\u6301\u3064\
    \u6839\u306B\u306A\u308B\u304C\u3001width\u3092\u6301\u3063\u3066\u3044\u308B\u306E\
    \u3067\u30AA\u30FC\u30D0\u30FC\u3057\u306A\u3044)\n        for (l += size() ;\
    \ res + width <= size() ; l = parent(l), width <<= 1) if (l & 1) {\n         \
    \   if (not f(VM::operation(prod, m_dat[l]))) break; \n            res += width;\n\
    \            prod = VM::operation(prod, m_dat[l++]);\n        }\n        // \u6839\
    \u304B\u3089\u4E0B\u3063\u3066\u3001\u5883\u754C\u3092\u767A\u898B\u3059\u308B\
    \n        while (l = left(l), width >>= 1) {\n            if (res + width <= size()\
    \ and f(VM::operation(prod, m_dat[l]))) {\n                res += width;\n   \
    \             prod = VM::operation(prod, m_dat[l++]);\n            } \n      \
    \  }\n        return res;\n    }\n\n    template <class F>\n    requires std::predicate<F,\
    \ V>\n    [[nodiscard]] usize minLeft(usize r, const F& f) const {\n        assert(r\
    \ <= size());\n        static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>,\
    \ \"minLeft's argument f must be function bool(T)\");\n        assert(f(VM::identity()));\n\
    \        usize res{r}, width{1};\n        V prod{ VM::identity() };\n        for\
    \ (r += size() ; res >= width ; r = parent(r), width <<= 1) if (r & 1) {\n   \
    \         if (not f(VM::operation(m_dat[r - 1], prod))) break;\n            res\
    \ -= width;\n            prod = VM::operation(prod, m_dat[--r]);\n        }\n\
    \        while (r = left(r), width >>= 1) {\n            if (res >= width and\
    \ f(VM::operation(m_dat[r - 1], prod))) {\n                res -= width;\n   \
    \             prod = VM::operation(m_dat[--r], prod);\n            }\n       \
    \ }\n        return res;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const SegmentTree& st) {\n        for (usize i{1} ; i < 2 * st.size() ;\
    \ i++) {\n            os << st.m_dat[i] << (i + 1 == 2 * st.size() ? \"\" : \"\
    \ \");\n        }\n        return os;\n    }\n\nprivate:\n\n    constexpr u32\
    \ left(u32 v) const {\n        return v << 1;\n    }\n\n    constexpr u32 right(u32\
    \ v) const {\n        return v << 1 | 1;\n    }\n\n    constexpr u32 parent(u32\
    \ v) const {\n        return v >> 1;\n    }\n\n    usize m_n;\n\n    std::vector<V>\
    \ m_dat;\n};\n\n} // namespace zawa\n#line 15 \"Test/AtCoder/abc292_h.test.cpp\"\
    \n\n#line 21 \"Test/AtCoder/abc292_h.test.cpp\"\n\nusing namespace zawa; \nusing\
    \ D = std::optional<long long>;\nusing vM = MaxMonoid<long long>;\nstruct oM {\n\
    \    using Element = D;\n    static D identity() noexcept {\n        return 0LL;\n\
    \    }\n    static D operation(const D& l, const D& r) noexcept {\n        if\
    \ (l and r) return l.value() + r.value();\n        else return (l ? l : (r ? r\
    \ : 0LL));\n    }\n};\nusing M = PrefixProductMonoid<oM, vM>;\n\nint main() {\n\
    #ifdef ATCODER\n    SetFastIO();\n    SetPrecision(10);\n\n    int n, q;\n   \
    \ long long b;\n    std::cin >> n >> b >> q;\n    std::vector<M::Element> a(n);\n\
    \    for (int i{} ; i < n ; i++) {\n        long long v; std::cin >> v;\n    \
    \    a[i] = M::Element{D{v - b}, D{v - b}};\n    }\n    SegmentTree<M> seg(a);\n\
    \    for (int _{} ; _ < q ; _++) {\n        int c; std::cin >> c;\n        c--;\n\
    \        long long x; std::cin >> x;\n        x -= b;\n        seg.assign(c, M::Element{D{x},\
    \ D{x}});\n        auto r{seg.maxRight(0, [](const M::Element& v) -> bool { return\
    \ (!(bool)v.prefix() or v.prefix().value() < 0LL); })};\n        r = std::min<int>(r\
    \ + 1, n);\n        assert(seg.product(0, r).product().has_value());\n       \
    \ long long sum{seg.product(0, r).product().value()};\n        long double ans{(long\
    \ double)(sum + b * (long long)r) / (long double)r};\n        std::cout << ans\
    \ << '\\n';\n    }\n#else\n    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/abc292/tasks/abc292_ex\"\n\
    #define ERROR 1e-9\n\n/*\n * AtCoder Beginner Contest 292 Ex - Rating Estimator\n\
    \ * https://atcoder.jp/contests/abc292/submissions/68181944\n */\n\n#include \"\
    ../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Algebra/Monoid/AdditionMonoid.hpp\"\
    \n#include \"../../Src/Algebra/Monoid/MaxMonoid.hpp\"\n#include \"../../Src/Algebra/Monoid/PrefixProductMonoid.hpp\"\
    \n#include \"../../Src/DataStructure/SegmentTree/SegmentTree.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iostream>\n#include <optional>\n\
    #include <vector>\n\nusing namespace zawa; \nusing D = std::optional<long long>;\n\
    using vM = MaxMonoid<long long>;\nstruct oM {\n    using Element = D;\n    static\
    \ D identity() noexcept {\n        return 0LL;\n    }\n    static D operation(const\
    \ D& l, const D& r) noexcept {\n        if (l and r) return l.value() + r.value();\n\
    \        else return (l ? l : (r ? r : 0LL));\n    }\n};\nusing M = PrefixProductMonoid<oM,\
    \ vM>;\n\nint main() {\n#ifdef ATCODER\n    SetFastIO();\n    SetPrecision(10);\n\
    \n    int n, q;\n    long long b;\n    std::cin >> n >> b >> q;\n    std::vector<M::Element>\
    \ a(n);\n    for (int i{} ; i < n ; i++) {\n        long long v; std::cin >> v;\n\
    \        a[i] = M::Element{D{v - b}, D{v - b}};\n    }\n    SegmentTree<M> seg(a);\n\
    \    for (int _{} ; _ < q ; _++) {\n        int c; std::cin >> c;\n        c--;\n\
    \        long long x; std::cin >> x;\n        x -= b;\n        seg.assign(c, M::Element{D{x},\
    \ D{x}});\n        auto r{seg.maxRight(0, [](const M::Element& v) -> bool { return\
    \ (!(bool)v.prefix() or v.prefix().value() < 0LL); })};\n        r = std::min<int>(r\
    \ + 1, n);\n        assert(seg.product(0, r).product().has_value());\n       \
    \ long long sum{seg.product(0, r).product().value()};\n        long double ans{(long\
    \ double)(sum + b * (long long)r) / (long double)r};\n        std::cout << ans\
    \ << '\\n';\n    }\n#else\n    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/AdditionMonoid.hpp
  - Src/Algebra/Monoid/MaxMonoid.hpp
  - Src/Algebra/Monoid/PrefixProductMonoid.hpp
  - Src/DataStructure/SegmentTree/SegmentTree.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc292_h.test.cpp
  requiredBy: []
  timestamp: '2025-08-03 16:41:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc292_h.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc292_h.test.cpp
- /verify/Test/AtCoder/abc292_h.test.cpp.html
title: Test/AtCoder/abc292_h.test.cpp
---
