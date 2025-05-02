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
    path: Src/DataStructure/SegmentTree/SparseSegmentTree.hpp
    title: "\u5358\u4F4D\u5143\u3067\u7121\u3044\u8981\u7D20\u304C\u758E\u306A\u30BB\
      \u30B0\u30E1\u30F3\u30C8\u6728"
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
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/My/DataStructure/SegmentTree/SparseSegmentTreeGetTest.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/DataStructure/SegmentTree/SparseSegmentTree.hpp\"\n\n#line 2\
    \ \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\n\
    namespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SegmentTree/SparseSegmentTree.hpp\"\
    \n\n#include <cassert>\n#include <limits>\n#include <optional>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <concepts::Monoid M>\nclass SparseSegmentTree {\n\
    public:\n\n    using V = typename M::Element;\n\n    SparseSegmentTree() = default;\n\
    \n    explicit SparseSegmentTree(usize n, usize poolSize = 0u) : m_n{n}, m_pool(1)\
    \ {\n        m_pool.reserve(poolSize);\n    }\n\n    void set(usize p, V v) {\n\
    \        assert(p < size());\n        set(0, p, v, 0, size());\n    }\n\n    V\
    \ get(usize p) const {\n        return get(0, p, 0, size());\n    }\n\n    V product(usize\
    \ l, usize r) const {\n        assert(l <= r and r <= size());\n        return\
    \ product(0, l, r, 0, size());\n    }\n\n    inline usize size() const {\n   \
    \     return m_n;\n    }\n\nprivate:\n\n    struct node {\n        static constexpr\
    \ usize INVALID = std::numeric_limits<usize>::max();\n        usize lch{INVALID},\
    \ rch{INVALID};\n        V v{M::identity()};\n    };\n\n    static constexpr usize\
    \ mid(usize l, usize r) {\n        return (l & r) + ((l ^ r) >> 1);\n    }\n \
    \   \n    void set(usize i, usize p, const V& v, usize l, usize r) {\n       \
    \ if (l + 1 == r) {\n            m_pool[i].v = v;\n            return;\n     \
    \   }\n        const usize m = mid(l, r);\n        if (p < m) {\n            if\
    \ (m_pool[i].lch == node::INVALID) m_pool[i].lch = makeNode();\n            set(m_pool[i].lch,\
    \ p, v, l, m);\n        }\n        else {\n            if (m_pool[i].rch == node::INVALID)\
    \ m_pool[i].rch = makeNode();\n            set(m_pool[i].rch, p, v, m, r);\n \
    \       }\n        m_pool[i].v = M::operation(\n                m_pool[i].lch\
    \ == node::INVALID ? M::identity() : m_pool[m_pool[i].lch].v,\n              \
    \  m_pool[i].rch == node::INVALID ? M::identity() : m_pool[m_pool[i].rch].v\n\
    \                );\n    }\n\n    V get(usize i, usize p, usize l, usize r) const\
    \ {\n        if (i == node::INVALID) return M::identity();\n        if (l + 1\
    \ == r) return m_pool[i].v;\n        const usize m = mid(l, r);\n        if (p\
    \ < m) return get(m_pool[i].lch, p, l, m);\n        else return get(m_pool[i].rch,\
    \ p, m, r);\n    }\n\n    V product(usize i, usize l, usize r, usize curL, usize\
    \ curR) const {\n        if (i == node::INVALID) return M::identity();\n     \
    \   if (r <= curL or curR <= l) return M::identity();\n        if (l <= curL and\
    \ curR <= r) return m_pool[i].v;\n        else {\n            const usize m =\
    \ mid(curL, curR);\n            return M::operation(\n                       \
    \ product(m_pool[i].lch, l, r, curL, m),\n                        product(m_pool[i].rch,\
    \ l, r, m, curR)\n                    );\n        }\n    }\n\n    usize makeNode()\
    \ {\n        usize res = m_pool.size();\n        m_pool.emplace_back();\n    \
    \    return res;\n    }\n\n    usize m_n{};\n\n    std::vector<node> m_pool{};\n\
    };\n\n} // namespace zawa\n#line 4 \"Test/My/DataStructure/SegmentTree/SparseSegmentTreeGetTest.test.cpp\"\
    \n\n#include <iostream>\n#line 7 \"Test/My/DataStructure/SegmentTree/SparseSegmentTreeGetTest.test.cpp\"\
    \n#include <random>\nstruct M {\n    using Element = int;\n    static Element\
    \ identity() {\n        return 0;\n    }\n    static Element operation(Element,Element)\
    \ {\n        return 0;\n    }\n};\n\nint main() {\n    std::mt19937 mt{std::random_device{}()};\n\
    \    const int size = 10000;\n    std::vector<int> a(size, M::identity());\n \
    \   zawa::SparseSegmentTree<M> seg(size);\n    int q = 1000000;\n    while (q--)\
    \ {\n        if (mt() % 2) {\n            int i = mt() % size;\n            assert(a[i]\
    \ == seg.get(i));\n        }\n        else {\n            int i = mt() % size,\
    \ v = mt() % 100;\n            a[i] = v;\n            seg.set(i, v);\n       \
    \ }\n    }\n    std::cout << \"Hello World\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../../../Src/DataStructure/SegmentTree/SparseSegmentTree.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n#include <random>\nstruct M {\n  \
    \  using Element = int;\n    static Element identity() {\n        return 0;\n\
    \    }\n    static Element operation(Element,Element) {\n        return 0;\n \
    \   }\n};\n\nint main() {\n    std::mt19937 mt{std::random_device{}()};\n    const\
    \ int size = 10000;\n    std::vector<int> a(size, M::identity());\n    zawa::SparseSegmentTree<M>\
    \ seg(size);\n    int q = 1000000;\n    while (q--) {\n        if (mt() % 2) {\n\
    \            int i = mt() % size;\n            assert(a[i] == seg.get(i));\n \
    \       }\n        else {\n            int i = mt() % size, v = mt() % 100;\n\
    \            a[i] = v;\n            seg.set(i, v);\n        }\n    }\n    std::cout\
    \ << \"Hello World\\n\";\n}\n"
  dependsOn:
  - Src/DataStructure/SegmentTree/SparseSegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: true
  path: Test/My/DataStructure/SegmentTree/SparseSegmentTreeGetTest.test.cpp
  requiredBy: []
  timestamp: '2025-05-02 21:30:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/My/DataStructure/SegmentTree/SparseSegmentTreeGetTest.test.cpp
layout: document
redirect_from:
- /verify/Test/My/DataStructure/SegmentTree/SparseSegmentTreeGetTest.test.cpp
- /verify/Test/My/DataStructure/SegmentTree/SparseSegmentTreeGetTest.test.cpp.html
title: Test/My/DataStructure/SegmentTree/SparseSegmentTreeGetTest.test.cpp
---
