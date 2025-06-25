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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"Test/AOJ/DSL_2_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
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
    \      }\n        for (usize i{m_n} ; i-- ; i) {\n            m_dat[i] = VM::operation(m_dat[left(i)],\
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
    \    template <class Function>\n    [[nodiscard]] usize maxRight(usize l, const\
    \ Function& f) {\n        assert(l < size());\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(V)>>, \"maxRight's argument f must be function bool(T)\"\
    );\n        assert(f(VM::identity()));\n        usize res{l}, width{1};\n    \
    \    V prod{ VM::identity() };\n        // \u73FE\u5728\u306E\u898B\u3066\u3044\
    \u308B\u9802\u70B9\u306E\u5E45\u3092width\u3067\u6301\u3064\n        // \u5883\
    \u754C\u304C\u3042\u308B\u9802\u70B9\u3092\u542B\u3080\u90E8\u5206\u6728\u306E\
    \u6839\u3092\u63A2\u3059\n        // (\u6298\u308A\u8FD4\u3059\u6642\u306F\u5FC5\
    \u8981\u4EE5\u4E0A\u306E\u5E45\u3092\u6301\u3064\u6839\u306B\u306A\u308B\u304C\
    \u3001width\u3092\u6301\u3063\u3066\u3044\u308B\u306E\u3067\u30AA\u30FC\u30D0\u30FC\
    \u3057\u306A\u3044)\n        for (l += size() ; res + width <= size() ; l = parent(l),\
    \ width <<= 1) if (l & 1) {\n            if (not f(VM::operation(prod, m_dat[l])))\
    \ break; \n            res += width;\n            prod = VM::operation(prod, m_dat[l++]);\n\
    \        }\n        // \u6839\u304B\u3089\u4E0B\u3063\u3066\u3001\u5883\u754C\u3092\
    \u767A\u898B\u3059\u308B\n        while (l = left(l), width >>= 1) {\n       \
    \     if (res + width <= size() and f(VM::operation(prod, m_dat[l]))) {\n    \
    \            res += width;\n                prod = VM::operation(prod, m_dat[l++]);\n\
    \            } \n        }\n        return res;\n    }\n\n    template <class\
    \ Function>\n    [[nodiscard]] usize minLeft(usize r, const Function& f) const\
    \ {\n        assert(r <= size());\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(V)>>, \"minLeft's argument f must be function bool(T)\");\n\
    \        assert(f(VM::identity()));\n        usize res{r}, width{1};\n       \
    \ V prod{ VM::identity() };\n        for (r += size() ; res >= width ; r = parent(r),\
    \ width <<= 1) if (r & 1) {\n            if (not f(VM::operation(m_dat[r - 1],\
    \ prod))) break;\n            res -= width;\n            prod = VM::operation(prod,\
    \ m_dat[--r]);\n        }\n        while (r = left(r), width >>= 1) {\n      \
    \      if (res >= width and f(VM::operation(m_dat[r - 1], prod))) {\n        \
    \        res -= width;\n                prod = VM::operation(m_dat[--r], prod);\n\
    \            }\n        }\n        return res;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const SegmentTree& st) {\n        for (usize i{1}\
    \ ; i < 2 * st.size() ; i++) {\n            os << st.m_dat[i] << (i + 1 == 2 *\
    \ st.size() ? \"\" : \" \");\n        }\n        return os;\n    }\n\nprivate:\n\
    \n    constexpr u32 left(u32 v) const {\n        return v << 1;\n    }\n\n   \
    \ constexpr u32 right(u32 v) const {\n        return v << 1 | 1;\n    }\n\n  \
    \  constexpr u32 parent(u32 v) const {\n        return v >> 1;\n    }\n\n    usize\
    \ m_n;\n\n    std::vector<V> m_dat;\n};\n\n} // namespace zawa\n#line 4 \"Test/AOJ/DSL_2_A.test.cpp\"\
    \n\n#line 6 \"Test/AOJ/DSL_2_A.test.cpp\"\n#include <iostream>\n#include <limits>\n\
    struct M {\n    using Element = int;\n    static Element identity() { return std::numeric_limits<int>::max();\
    \ }\n    static Element operation(Element L, Element R) { return std::min(L, R);\
    \ }\n};\nint main() {\n    using namespace zawa;\n    using MD = M::Element;\n\
    \    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, q; \n    std::cin >> n >> q; \n    SegmentTree<M> seg(std::vector(n,\
    \ M::identity()));\n    while (q--) {\n        int com, x, y; \n        std::cin\
    \ >> com >> x >> y;\n        if (com == 0) {\n            seg.assign(x, y);\n\
    \        }\n        else if (com == 1) {\n            std::cout << seg.product(x,\
    \ y + 1) << '\\n';\n        }\n        else {\n            assert(false);\n  \
    \      }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include \"../../Src/DataStructure/SegmentTree/SegmentTree.hpp\"\n\n#include\
    \ <cassert>\n#include <iostream>\n#include <limits>\nstruct M {\n    using Element\
    \ = int;\n    static Element identity() { return std::numeric_limits<int>::max();\
    \ }\n    static Element operation(Element L, Element R) { return std::min(L, R);\
    \ }\n};\nint main() {\n    using namespace zawa;\n    using MD = M::Element;\n\
    \    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, q; \n    std::cin >> n >> q; \n    SegmentTree<M> seg(std::vector(n,\
    \ M::identity()));\n    while (q--) {\n        int com, x, y; \n        std::cin\
    \ >> com >> x >> y;\n        if (com == 0) {\n            seg.assign(x, y);\n\
    \        }\n        else if (com == 1) {\n            std::cout << seg.product(x,\
    \ y + 1) << '\\n';\n        }\n        else {\n            assert(false);\n  \
    \      }\n    }\n}\n"
  dependsOn:
  - Src/DataStructure/SegmentTree/SegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: true
  path: Test/AOJ/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2025-06-24 15:30:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/DSL_2_A.test.cpp
- /verify/Test/AOJ/DSL_2_A.test.cpp.html
title: Test/AOJ/DSL_2_A.test.cpp
---
