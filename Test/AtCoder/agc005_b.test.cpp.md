---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/SegmentTree.hpp
    title: Segment Tree
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
    - https://atcoder.jp/contests/agc005/submissions/68182027
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/agc005_b.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line\
    \ 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\n\
    namespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n#include <functional>\n#include <type_traits>\n\
    #include <ostream>\n\nnamespace zawa {\n\ntemplate <concepts::Monoid Monoid>\n\
    class SegmentTree {\npublic:\n\n    using VM = Monoid;\n\n    using V = typename\
    \ VM::Element;\n\n    using OM = Monoid;\n\n    using O = typename OM::Element;\n\
    \n    SegmentTree() = default;\n\n    explicit SegmentTree(usize n) : m_n{ n },\
    \ m_dat(n << 1, VM::identity()) {}\n\n    explicit SegmentTree(const std::vector<V>&\
    \ dat) : m_n{ dat.size() }, m_dat(dat.size() << 1, VM::identity()) {\n       \
    \ for (usize i{} ; i < m_n ; i++) {\n            m_dat[i + m_n] = dat[i];\n  \
    \      }\n        for (usize i{m_n} ; i-- ; ) {\n            m_dat[i] = VM::operation(m_dat[left(i)],\
    \ m_dat[right(i)]);\n        }\n    }\n\n    [[nodiscard]] inline usize size()\
    \ const noexcept {\n        return m_n;\n    }\n\n    [[nodiscard]] V get(usize\
    \ i) const {\n        assert(i < size());\n        return m_dat[i + m_n];\n  \
    \  }\n\n    [[nodiscard]] V operator[](usize i) const {\n        assert(i < size());\n\
    \        return m_dat[i + m_n];\n    }\n\n    void operation(usize i, const O&\
    \ value) {\n        assert(i < size());\n        i += size();\n        m_dat[i]\
    \ = OM::operation(m_dat[i], value);\n        while (i = parent(i), i) {\n    \
    \        m_dat[i] = VM::operation(m_dat[left(i)], m_dat[right(i)]);\n        }\n\
    \    }\n\n    void assign(usize i, const V& value) {\n        assert(i < size());\n\
    \        i += size();\n        m_dat[i] = value;\n        while (i = parent(i),\
    \ i) {\n            m_dat[i] = VM::operation(m_dat[left(i)], m_dat[right(i)]);\n\
    \        }\n    }\n\n    [[nodiscard]] V product(u32 l, u32 r) const {\n     \
    \   assert(l <= r and r <= size());\n        V L{ VM::identity() }, R{ VM::identity()\
    \ };\n        for (l += size(), r += size() ; l < r ; l = parent(l), r = parent(r))\
    \ {\n            if (l & 1) {\n                L = VM::operation(L, m_dat[l++]);\n\
    \            }\n            if (r & 1) {\n                R = VM::operation(m_dat[--r],\
    \ R);\n            }\n        }\n        return VM::operation(L, R);\n    }\n\n\
    \    template <class F>\n    requires std::predicate<F, V>\n    [[nodiscard]]\
    \ usize maxRight(usize l, const F& f) {\n        assert(l < size());\n       \
    \ static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>, \"\
    maxRight's argument f must be function bool(T)\");\n        assert(f(VM::identity()));\n\
    \        usize res{l}, width{1};\n        V prod{ VM::identity() };\n        for\
    \ (l += size() ; res + width <= size() ; l = parent(l), width <<= 1) if (l & 1)\
    \ {\n            if (not f(VM::operation(prod, m_dat[l]))) break; \n         \
    \   res += width;\n            prod = VM::operation(prod, m_dat[l++]);\n     \
    \   }\n        while (l = left(l), width >>= 1) {\n            if (res + width\
    \ <= size() and f(VM::operation(prod, m_dat[l]))) {\n                res += width;\n\
    \                prod = VM::operation(prod, m_dat[l++]);\n            } \n   \
    \     }\n        return res;\n    }\n\n    template <class F>\n    requires std::predicate<F,\
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
    \ m_dat;\n};\n\n} // namespace zawa\n#line 4 \"Test/AtCoder/agc005_b.test.cpp\"\
    \n\n/*\n * AtCoder Grand Contest 005 B - Minimum Sum\n * https://atcoder.jp/contests/agc005/submissions/68182027\n\
    \ */\n\n#include <iostream>\n#line 12 \"Test/AtCoder/agc005_b.test.cpp\"\n\nstruct\
    \ M {\n    using Element = int;\n    static Element identity() { return (int)1e9;\
    \ }\n    static Element operation(Element L, Element R) { return std::min(L, R);\
    \ }\n};\n\nlong long solve() {\n    using namespace zawa;\n    std::cin.tie(nullptr);\n\
    \    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    using\
    \ MD = M::Element;\n    int n; \n    std::cin >> n;\n    std::vector<MD> a(n);\n\
    \    for (auto& x : a) {\n        int v; std::cin >> v;\n        x = v;\n    }\n\
    \    SegmentTree<M> seg(a);\n    long long ans{};\n    for (int i{} ; i < n ;\
    \ i++) {\n        auto f{[&](MD v) -> bool {\n            return v >= a[i];\n\
    \        }};\n        auto left{ seg.minLeft(i, f) }, right{ seg.maxRight(i, f)\
    \ };\n        ans += (long long)(right - i) * (long long)(i - left + 1) * (long\
    \ long)a[i];\n    }\n    return ans;\n}\n\nint main() {\n#ifdef ATCODER\n    std::cout\
    \ << solve() << '\\n';\n#else\n    std::cout << \"Hello World\" << '\\n';\n#endif\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/DataStructure/SegmentTree/SegmentTree.hpp\"\n\n/*\n *\
    \ AtCoder Grand Contest 005 B - Minimum Sum\n * https://atcoder.jp/contests/agc005/submissions/68182027\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\nstruct M {\n    using Element\
    \ = int;\n    static Element identity() { return (int)1e9; }\n    static Element\
    \ operation(Element L, Element R) { return std::min(L, R); }\n};\n\nlong long\
    \ solve() {\n    using namespace zawa;\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    using MD = M::Element;\n    int n;\
    \ \n    std::cin >> n;\n    std::vector<MD> a(n);\n    for (auto& x : a) {\n \
    \       int v; std::cin >> v;\n        x = v;\n    }\n    SegmentTree<M> seg(a);\n\
    \    long long ans{};\n    for (int i{} ; i < n ; i++) {\n        auto f{[&](MD\
    \ v) -> bool {\n            return v >= a[i];\n        }};\n        auto left{\
    \ seg.minLeft(i, f) }, right{ seg.maxRight(i, f) };\n        ans += (long long)(right\
    \ - i) * (long long)(i - left + 1) * (long long)a[i];\n    }\n    return ans;\n\
    }\n\nint main() {\n#ifdef ATCODER\n    std::cout << solve() << '\\n';\n#else\n\
    \    std::cout << \"Hello World\" << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/DataStructure/SegmentTree/SegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: true
  path: Test/AtCoder/agc005_b.test.cpp
  requiredBy: []
  timestamp: '2025-10-17 20:47:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/agc005_b.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/agc005_b.test.cpp
- /verify/Test/AtCoder/agc005_b.test.cpp.html
title: Test/AtCoder/agc005_b.test.cpp
---
