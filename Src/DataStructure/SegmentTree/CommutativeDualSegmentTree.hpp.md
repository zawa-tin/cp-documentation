---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/DualSegmentTree.hpp
    title: Src/DataStructure/SegmentTree/DualSegmentTree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_E.test.cpp
    title: Test/AOJ/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/range_affine_point_get.test.cpp
    title: Test/LC/range_affine_point_get.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp\"\
    \n\n#include <vector>\n#include <iterator>\n#include <ostream>\n#include <cassert>\n\
    \nnamespace zawa {\n\ntemplate <class Monoid>\nclass CommutativeDualSegmentTree\
    \ {\npublic:\n    using Operator = typename Monoid::Element;\nprotected:\n\n \
    \   static constexpr u32 parent(u32 v) noexcept {\n        return v >> 1;\n  \
    \  }\n    static constexpr u32 left(u32 v) noexcept {\n        return v << 1;\n\
    \    }\n    static constexpr u32 right(u32 v) noexcept {\n        return v <<\
    \ 1 | 1;\n    }\n\n    usize n_;\n    std::vector<Operator> dat_;\n\n    template\
    \ <class InputIterator>\n    inline void initDat(InputIterator first, InputIterator\
    \ last) {\n        for (auto it{ first } ; it != last ; it++) {\n            dat_[n_\
    \ + std::distance(first, it)] = *it;\n        }\n    }\n\n    void push(u32 i)\
    \ {\n        assert(i < n_);\n        i += n_;\n        u32 height{ 32u - __builtin_clz(i)\
    \ };\n        for (u32 h{ height } ; --h ; ) {\n            u32 v{ i >> h };\n\
    \            dat_[left(v)] = Monoid::operation(dat_[left(v)], dat_[v]);\n    \
    \        dat_[right(v)] = Monoid::operation(dat_[right(v)], dat_[v]);\n      \
    \      dat_[v] = Monoid::identity();\n        }\n    }\n\npublic:\n    CommutativeDualSegmentTree()\
    \ = default;\n    CommutativeDualSegmentTree(usize n) \n        : n_{ n }, dat_((n\
    \ << 1), Monoid::identity()) {}\n    CommutativeDualSegmentTree(const std::vector<Operator>&\
    \ dat) \n        : n_{ dat.size() }, dat_((n_ << 1), Monoid::identity()) {\n \
    \       initDat(dat.begin(), dat.end());\n    }\n    template <class InputIterator>\n\
    \    CommutativeDualSegmentTree(InputIterator first, InputIterator last)\n   \
    \     : n_{ static_cast<usize>(std::distance(first, last)) }, dat_((n_ << 1),\
    \ Monoid::identity()) {\n        initDat(first, last);\n    }\n\n    void update(u32\
    \ l, u32 r, const Operator& v) {\n        assert(l < n_);\n        assert(l <=\
    \ r and r <= n_);\n        for (l += n_, r += n_ ; l < r ; l = parent(l), r =\
    \ parent(r)) {\n            if (l & 1) {\n                dat_[l] = Monoid::operation(dat_[l],\
    \ v);\n                l++;\n            }\n            if (r & 1) {\n       \
    \         r--;\n                dat_[r] = Monoid::operation(dat_[r], v);\n   \
    \         }\n        }\n    }\n\n    void set(u32 i, const Operator& v) {\n  \
    \      assert(i < n_);\n        push(i);\n        dat_[i + n_] = v;\n    }\n\n\
    \    Operator operator[](u32 i) const {\n        assert(i < n_);\n        Operator\
    \ res{ Monoid::identity() };\n        for (i += n_ ; i ; i = parent(i)) {\n  \
    \          res = Monoid::operation(res, dat_[i]);\n        }\n        return res;\n\
    \    }\n\n    friend std::ostream& operator<<(std::ostream& os, const CommutativeDualSegmentTree\
    \ seg) {\n        usize size{ seg.dat_.size() };\n        for (u32 i{1} ; i <\
    \ size ; i++) {\n            os << seg.dat_[i] << (i + 1 == size ? \"\" : \" \"\
    );\n        }\n        return os;\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <vector>\n\
    #include <iterator>\n#include <ostream>\n#include <cassert>\n\nnamespace zawa\
    \ {\n\ntemplate <class Monoid>\nclass CommutativeDualSegmentTree {\npublic:\n\
    \    using Operator = typename Monoid::Element;\nprotected:\n\n    static constexpr\
    \ u32 parent(u32 v) noexcept {\n        return v >> 1;\n    }\n    static constexpr\
    \ u32 left(u32 v) noexcept {\n        return v << 1;\n    }\n    static constexpr\
    \ u32 right(u32 v) noexcept {\n        return v << 1 | 1;\n    }\n\n    usize\
    \ n_;\n    std::vector<Operator> dat_;\n\n    template <class InputIterator>\n\
    \    inline void initDat(InputIterator first, InputIterator last) {\n        for\
    \ (auto it{ first } ; it != last ; it++) {\n            dat_[n_ + std::distance(first,\
    \ it)] = *it;\n        }\n    }\n\n    void push(u32 i) {\n        assert(i <\
    \ n_);\n        i += n_;\n        u32 height{ 32u - __builtin_clz(i) };\n    \
    \    for (u32 h{ height } ; --h ; ) {\n            u32 v{ i >> h };\n        \
    \    dat_[left(v)] = Monoid::operation(dat_[left(v)], dat_[v]);\n            dat_[right(v)]\
    \ = Monoid::operation(dat_[right(v)], dat_[v]);\n            dat_[v] = Monoid::identity();\n\
    \        }\n    }\n\npublic:\n    CommutativeDualSegmentTree() = default;\n  \
    \  CommutativeDualSegmentTree(usize n) \n        : n_{ n }, dat_((n << 1), Monoid::identity())\
    \ {}\n    CommutativeDualSegmentTree(const std::vector<Operator>& dat) \n    \
    \    : n_{ dat.size() }, dat_((n_ << 1), Monoid::identity()) {\n        initDat(dat.begin(),\
    \ dat.end());\n    }\n    template <class InputIterator>\n    CommutativeDualSegmentTree(InputIterator\
    \ first, InputIterator last)\n        : n_{ static_cast<usize>(std::distance(first,\
    \ last)) }, dat_((n_ << 1), Monoid::identity()) {\n        initDat(first, last);\n\
    \    }\n\n    void update(u32 l, u32 r, const Operator& v) {\n        assert(l\
    \ < n_);\n        assert(l <= r and r <= n_);\n        for (l += n_, r += n_ ;\
    \ l < r ; l = parent(l), r = parent(r)) {\n            if (l & 1) {\n        \
    \        dat_[l] = Monoid::operation(dat_[l], v);\n                l++;\n    \
    \        }\n            if (r & 1) {\n                r--;\n                dat_[r]\
    \ = Monoid::operation(dat_[r], v);\n            }\n        }\n    }\n\n    void\
    \ set(u32 i, const Operator& v) {\n        assert(i < n_);\n        push(i);\n\
    \        dat_[i + n_] = v;\n    }\n\n    Operator operator[](u32 i) const {\n\
    \        assert(i < n_);\n        Operator res{ Monoid::identity() };\n      \
    \  for (i += n_ ; i ; i = parent(i)) {\n            res = Monoid::operation(res,\
    \ dat_[i]);\n        }\n        return res;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const CommutativeDualSegmentTree seg) {\n     \
    \   usize size{ seg.dat_.size() };\n        for (u32 i{1} ; i < size ; i++) {\n\
    \            os << seg.dat_[i] << (i + 1 == size ? \"\" : \" \");\n        }\n\
    \        return os;\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp
  requiredBy:
  - Src/DataStructure/SegmentTree/DualSegmentTree.hpp
  timestamp: '2023-10-02 00:27:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/DSL_2_E.test.cpp
  - Test/LC/range_affine_point_get.test.cpp
documentation_of: Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp
layout: document
title: "Dual Segment Tree (\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9)"
---

ドキュメントを書く気力が行方不明！

[テンプレート引数](https://zawa-tin.github.io/cp-documentation/Docs/Appendix/Monoid.html)

`Operator = Monoid::Element`

`update(u32 l, u32 r, const Operator& v)` 半開区間 $[l, r)$ に $v$ を合成(ACLでいう`composition`)

`set(u32 i, const Operator& v)` $i$ 番目の要素に $v$ を「代入」

`Operator operator[](u32 i)`
- $i$ 番目の要素を取得
