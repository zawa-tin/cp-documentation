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
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc256_h.test.cpp
    title: Test/AtCoder/abc256_h.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/57319
  bundledCode: "#line 2 \"Src/DataStructure/SegmentTree/SegmentTreeBeats.hpp\"\n\n\
    #line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
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
    \n} // namespace\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SegmentTree/SegmentTreeBeats.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\nnamespace zawa {\n\n// ref: https://codeforces.com/blog/entry/57319\n\
    template <class S>\nclass SegmentTreeBeats {\npublic:\n\n    using VM = typename\
    \ S::ValueMonoid;\n\n    using OM = typename S::OperatorMonoid;\n\n    using V\
    \ = typename VM::Element;\n\n    using O = typename OM::Element;\n\n    static\
    \ usize treeSize(usize n) {\n        usize res = 1;\n        while (res < n) res\
    \ <<= 1;\n        return res;\n    }\n\n    SegmentTreeBeats() = default;\n\n\
    \    explicit SegmentTreeBeats(usize n) \n        : m_n{n}, m_treeSize{treeSize(n)},\
    \ m_tree(m_treeSize << 1, VM::identity()), m_lazy(m_treeSize << 1, OM::identity())\
    \ {}\n\n    explicit SegmentTreeBeats(const std::vector<V>& a) \n        : m_n{a.size()},\
    \ m_treeSize{treeSize(a.size())}, m_tree(m_treeSize << 1, VM::identity()), m_lazy(m_treeSize\
    \ << 1, OM::identity()) {\n        for (usize i = 0 ; i < m_n ; i++) m_tree[m_treeSize\
    \ + i] = a[i];\n        for (usize i = m_treeSize ; --i >= 1 ; ) m_tree[i] = VM::operation(m_tree[i\
    \ << 1 | 0], m_tree[i << 1 | 1]);\n    }\n\n    inline usize size() const noexcept\
    \ {\n        return m_n;\n    }\n\n    V product(usize l, usize r) {\n       \
    \ assert(l <= r and r <= size());\n        return product(1, 0, m_treeSize, l,\
    \ r);\n    }\n\n    V operator[](usize i) {\n        assert(i < size());\n   \
    \     return product(1, 0, m_treeSize, i, i + 1);\n    }\n\n    template <class\
    \ BREAK_CONDITION, class TAG_CONDITION>\n    void operation(usize l, usize r,\
    \ const O& act, BREAK_CONDITION breakCondition, TAG_CONDITION tagCondition) {\n\
    \        assert(l <= r and r <= size());\n        operation(act, 1, 0, m_treeSize,\
    \ l, r, breakCondition, tagCondition);\n    }\n\nprivate:\n\n    void pushDown(usize\
    \ v) {\n        if (v < m_treeSize) {\n            const usize lch = v << 1 |\
    \ 0, rch = v << 1 | 1;\n            m_tree[lch] = S::mapping(m_tree[lch], m_lazy[v]);\n\
    \            m_lazy[lch] = OM::operation(m_lazy[lch], m_lazy[v]);\n          \
    \  m_tree[rch] = S::mapping(m_tree[rch], m_lazy[v]);\n            m_lazy[rch]\
    \ = OM::operation(m_lazy[rch], m_lazy[v]);\n            m_lazy[v] = OM::identity();\n\
    \        }\n    }\n\n    void recalc(usize v) {\n        m_tree[v] = VM::operation(m_tree[v\
    \ << 1 | 0], m_tree[v << 1 | 1]);\n    }\n\n    V product(usize v, usize vl, usize\
    \ vr, usize ql, usize qr) {\n        if (vr <= ql or qr <= vl) return VM::identity();\n\
    \        if (ql <= vl and vr <= qr) return m_tree[v];\n        const usize m =\
    \ (vl + vr) >> 1;\n        pushDown(v);\n        return VM::operation(\n     \
    \           product(v << 1 | 0, vl, m, ql, qr),\n                product(v <<\
    \ 1 | 1, m, vr, ql, qr)\n                );\n    }\n\n    template <class BREAK_CONDITION,\
    \ class TAG_CONDITION>\n    void operation(const O& act, usize v, usize vl, usize\
    \ vr, usize ql, usize qr, BREAK_CONDITION breakCondition, TAG_CONDITION tagCondition)\
    \ {\n        if (vr <= ql or qr <= vl) return;\n        assert(v < m_tree.size()\
    \ or !\"failed to operation to node such that length is 1. break_condition or/and\
    \ tag_condition is something wrong\");\n        if (breakCondition(m_tree[v],\
    \ act)) return;\n        pushDown(v);\n        if (ql <= vl and vr <= qr and tagCondition(m_tree[v],\
    \ act)) {\n            m_tree[v] = S::mapping(m_tree[v], act);\n            m_lazy[v]\
    \ = act; \n            return;\n        }\n        const usize m = (vl + vr) >>\
    \ 1;\n        operation(act, v << 1 | 0, vl, m, ql, qr, breakCondition, tagCondition);\n\
    \        operation(act, v << 1 | 1, m, vr, ql, qr, breakCondition, tagCondition);\n\
    \        recalc(v);\n    }\n\n    usize m_n{}, m_treeSize{};\n\n    std::vector<V>\
    \ m_tree{};\n\n    std::vector<O> m_lazy{};\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\nnamespace zawa {\n\n// ref: https://codeforces.com/blog/entry/57319\n\
    template <class S>\nclass SegmentTreeBeats {\npublic:\n\n    using VM = typename\
    \ S::ValueMonoid;\n\n    using OM = typename S::OperatorMonoid;\n\n    using V\
    \ = typename VM::Element;\n\n    using O = typename OM::Element;\n\n    static\
    \ usize treeSize(usize n) {\n        usize res = 1;\n        while (res < n) res\
    \ <<= 1;\n        return res;\n    }\n\n    SegmentTreeBeats() = default;\n\n\
    \    explicit SegmentTreeBeats(usize n) \n        : m_n{n}, m_treeSize{treeSize(n)},\
    \ m_tree(m_treeSize << 1, VM::identity()), m_lazy(m_treeSize << 1, OM::identity())\
    \ {}\n\n    explicit SegmentTreeBeats(const std::vector<V>& a) \n        : m_n{a.size()},\
    \ m_treeSize{treeSize(a.size())}, m_tree(m_treeSize << 1, VM::identity()), m_lazy(m_treeSize\
    \ << 1, OM::identity()) {\n        for (usize i = 0 ; i < m_n ; i++) m_tree[m_treeSize\
    \ + i] = a[i];\n        for (usize i = m_treeSize ; --i >= 1 ; ) m_tree[i] = VM::operation(m_tree[i\
    \ << 1 | 0], m_tree[i << 1 | 1]);\n    }\n\n    inline usize size() const noexcept\
    \ {\n        return m_n;\n    }\n\n    V product(usize l, usize r) {\n       \
    \ assert(l <= r and r <= size());\n        return product(1, 0, m_treeSize, l,\
    \ r);\n    }\n\n    V operator[](usize i) {\n        assert(i < size());\n   \
    \     return product(1, 0, m_treeSize, i, i + 1);\n    }\n\n    template <class\
    \ BREAK_CONDITION, class TAG_CONDITION>\n    void operation(usize l, usize r,\
    \ const O& act, BREAK_CONDITION breakCondition, TAG_CONDITION tagCondition) {\n\
    \        assert(l <= r and r <= size());\n        operation(act, 1, 0, m_treeSize,\
    \ l, r, breakCondition, tagCondition);\n    }\n\nprivate:\n\n    void pushDown(usize\
    \ v) {\n        if (v < m_treeSize) {\n            const usize lch = v << 1 |\
    \ 0, rch = v << 1 | 1;\n            m_tree[lch] = S::mapping(m_tree[lch], m_lazy[v]);\n\
    \            m_lazy[lch] = OM::operation(m_lazy[lch], m_lazy[v]);\n          \
    \  m_tree[rch] = S::mapping(m_tree[rch], m_lazy[v]);\n            m_lazy[rch]\
    \ = OM::operation(m_lazy[rch], m_lazy[v]);\n            m_lazy[v] = OM::identity();\n\
    \        }\n    }\n\n    void recalc(usize v) {\n        m_tree[v] = VM::operation(m_tree[v\
    \ << 1 | 0], m_tree[v << 1 | 1]);\n    }\n\n    V product(usize v, usize vl, usize\
    \ vr, usize ql, usize qr) {\n        if (vr <= ql or qr <= vl) return VM::identity();\n\
    \        if (ql <= vl and vr <= qr) return m_tree[v];\n        const usize m =\
    \ (vl + vr) >> 1;\n        pushDown(v);\n        return VM::operation(\n     \
    \           product(v << 1 | 0, vl, m, ql, qr),\n                product(v <<\
    \ 1 | 1, m, vr, ql, qr)\n                );\n    }\n\n    template <class BREAK_CONDITION,\
    \ class TAG_CONDITION>\n    void operation(const O& act, usize v, usize vl, usize\
    \ vr, usize ql, usize qr, BREAK_CONDITION breakCondition, TAG_CONDITION tagCondition)\
    \ {\n        if (vr <= ql or qr <= vl) return;\n        assert(v < m_tree.size()\
    \ or !\"failed to operation to node such that length is 1. break_condition or/and\
    \ tag_condition is something wrong\");\n        if (breakCondition(m_tree[v],\
    \ act)) return;\n        pushDown(v);\n        if (ql <= vl and vr <= qr and tagCondition(m_tree[v],\
    \ act)) {\n            m_tree[v] = S::mapping(m_tree[v], act);\n            m_lazy[v]\
    \ = act; \n            return;\n        }\n        const usize m = (vl + vr) >>\
    \ 1;\n        operation(act, v << 1 | 0, vl, m, ql, qr, breakCondition, tagCondition);\n\
    \        operation(act, v << 1 | 1, m, vr, ql, qr, breakCondition, tagCondition);\n\
    \        recalc(v);\n    }\n\n    usize m_n{}, m_treeSize{};\n\n    std::vector<V>\
    \ m_tree{};\n\n    std::vector<O> m_lazy{};\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: false
  path: Src/DataStructure/SegmentTree/SegmentTreeBeats.hpp
  requiredBy: []
  timestamp: '2025-06-20 23:34:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc256_h.test.cpp
documentation_of: Src/DataStructure/SegmentTree/SegmentTreeBeats.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/SegmentTree/SegmentTreeBeats.hpp
- /library/Src/DataStructure/SegmentTree/SegmentTreeBeats.hpp.html
title: Src/DataStructure/SegmentTree/SegmentTreeBeats.hpp
---
