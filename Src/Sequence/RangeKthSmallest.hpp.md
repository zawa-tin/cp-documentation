---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/CompressedSequence.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/range_kth_smallest.test.cpp
    title: Test/LC/range_kth_smallest.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Sequence/RangeKthSmallest.hpp\"\n\n#line 2 \"Src/Sequence/CompressedSequence.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Sequence/CompressedSequence.hpp\"\
    \n\n#include <vector>\n#include <algorithm>\n#include <cassert>\n#include <iterator>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nclass CompressedSequence {\nprivate:\n\
    \    std::vector<T> comped_;\n    std::vector<u32> f_;\n    \npublic:\n    CompressedSequence()\
    \ = default;\n\n    template <class InputIterator>\n    CompressedSequence(InputIterator\
    \ first, InputIterator last) : comped_(first, last), f_{} {\n        std::sort(comped_.begin(),\
    \ comped_.end());\n        comped_.erase(std::unique(comped_.begin(), comped_.end()),\
    \ comped_.end());\n        comped_.shrink_to_fit();\n        f_.reserve(std::distance(first,\
    \ last));\n        for (auto it{first} ; it != last ; it++) {\n            f_.emplace_back(std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), *it)));\n        }\n    }\n\
    \n    CompressedSequence(const std::vector<T>& A) : CompressedSequence(A.begin(),\
    \ A.end()) {}\n\n    inline usize size() const noexcept {\n        return comped_.size();\n\
    \    }\n\n    u32 operator[](const T& v) const {\n        return std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), v));\n    }\n\n    u32 at(const\
    \ T& v) const {\n        u32 res{(*this)[v]};\n        assert(res < size() and\
    \ comped_[res] == v);\n        return res;\n    }\n\n    inline u32 map(u32 i)\
    \ const noexcept {\n        assert(i < f_.size());\n        return f_[i];\n  \
    \  }\n\n    inline T inverse(u32 i) const noexcept {\n        assert(i < size());\n\
    \        return comped_[i];\n    }\n};\n\n} // namespace zawa\n#line 5 \"Src/Sequence/RangeKthSmallest.hpp\"\
    \n\n#line 7 \"Src/Sequence/RangeKthSmallest.hpp\"\n#include <bit>\n#line 9 \"\
    Src/Sequence/RangeKthSmallest.hpp\"\n#include <utility>\n#line 11 \"Src/Sequence/RangeKthSmallest.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T, class U>\nstd::vector<T> RangeKthSmallest(const\
    \ std::vector<T>& A, const std::vector<U>& Q) {\n    assert(A.size());\n    CompressedSequence\
    \ comp{A};\n    std::vector<std::vector<std::pair<usize, bool>>> event(A.size()\
    \ + 1);\n    for (usize i{} ; i < Q.size() ; i++) {\n        const U& q{Q[i]};\n\
    \        assert(q.l < q.r and q.r <= A.size());\n        assert(q.k < q.r - q.l);\n\
    \        event[q.l].emplace_back(i, true);\n        event[q.r].emplace_back(i,\
    \ false);\n    }\n    std::vector<usize> x(Q.size()), cnt(Q.size());\n    const\
    \ usize LOG{(usize)(std::bit_width(comp.size()) -\n            (std::has_single_bit(comp.size())\
    \ ? 1 : 0))};\n    for (usize i{LOG} ; i-- ; ) {\n        std::vector<i32> seg(1\
    \ << (LOG - i));\n        std::vector<i32> add(Q.size());\n        for (usize\
    \ j{1} ; j <= A.size() ; j++) {\n            seg[comp.map(j - 1) >> i]++;\n  \
    \          for (auto [k, s] : event[j]) {\n                add[k] += seg[(x[k]\
    \ >> i)] * (s ? -1 : 1);\n            }\n        }\n        for (u32 j{} ; j <\
    \ Q.size() ; j++) {\n            if (cnt[j] + add[j] <= Q[j].k) {\n          \
    \      x[j] += 1 << i;\n                cnt[j] += add[j];\n            }\n   \
    \     }\n    } \n    std::vector<T> res(Q.size());\n    for (usize i{} ; i < Q.size()\
    \ ; i++) {\n        res[i] = comp.inverse(x[i]);\n    }\n    return res;\n}\n\n\
    } // namespace zawa\n"
  code: "#pragma once\n\n#include \"./CompressedSequence.hpp\"\n#include \"../Template/TypeAlias.hpp\"\
    \n\n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\nnamespace zawa {\n\ntemplate <class T, class U>\nstd::vector<T>\
    \ RangeKthSmallest(const std::vector<T>& A, const std::vector<U>& Q) {\n    assert(A.size());\n\
    \    CompressedSequence comp{A};\n    std::vector<std::vector<std::pair<usize,\
    \ bool>>> event(A.size() + 1);\n    for (usize i{} ; i < Q.size() ; i++) {\n \
    \       const U& q{Q[i]};\n        assert(q.l < q.r and q.r <= A.size());\n  \
    \      assert(q.k < q.r - q.l);\n        event[q.l].emplace_back(i, true);\n \
    \       event[q.r].emplace_back(i, false);\n    }\n    std::vector<usize> x(Q.size()),\
    \ cnt(Q.size());\n    const usize LOG{(usize)(std::bit_width(comp.size()) -\n\
    \            (std::has_single_bit(comp.size()) ? 1 : 0))};\n    for (usize i{LOG}\
    \ ; i-- ; ) {\n        std::vector<i32> seg(1 << (LOG - i));\n        std::vector<i32>\
    \ add(Q.size());\n        for (usize j{1} ; j <= A.size() ; j++) {\n         \
    \   seg[comp.map(j - 1) >> i]++;\n            for (auto [k, s] : event[j]) {\n\
    \                add[k] += seg[(x[k] >> i)] * (s ? -1 : 1);\n            }\n \
    \       }\n        for (u32 j{} ; j < Q.size() ; j++) {\n            if (cnt[j]\
    \ + add[j] <= Q[j].k) {\n                x[j] += 1 << i;\n                cnt[j]\
    \ += add[j];\n            }\n        }\n    } \n    std::vector<T> res(Q.size());\n\
    \    for (usize i{} ; i < Q.size() ; i++) {\n        res[i] = comp.inverse(x[i]);\n\
    \    }\n    return res;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Sequence/CompressedSequence.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Sequence/RangeKthSmallest.hpp
  requiredBy: []
  timestamp: '2024-11-15 02:44:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/range_kth_smallest.test.cpp
documentation_of: Src/Sequence/RangeKthSmallest.hpp
layout: document
title: Range Kth Smallest
---

## 概要

静的な列に対して、「区間 $[l, r)$ の中で $k$ 番目に小さい値は？」というクエリをオフラインで計算する。

## ライブラリの説明

```cpp
template <class T, class U>
std::vector<T> RangeKthSmallest(const std::vector<T>& A, const std::vector<U>& Q)
```

#### A

**要件**

- 非空であること
- `operator<`が定義されていること
    - 当然だが、 $a\lt b$ であるとき、またそのときに限り`a<b`がtrueでないといけない

#### Q

**要件**

- `U`はpublicメンバ変数`l, r, k`が定義されているclass, structであること
- さらに、`l, r, k`は符号無し整数であることが期待される。符号あり整数だとWarningが発生する
- $l\lt r \le |A|$ かつ $k\lt r - l$
    - `l, r`は0-indexedの**非空な**半開区間
    - `k`は0-indexedで、 $r - l$ 以上の値は許されない

`U`は基本的には以下のstructをコピれば問題無い

```cpp
struct query {
    usize l, r, k;
};
```

#### アルゴリズム

一行で: 並列二分探索 + 平面走査

$A$ をソートして重複を消した列を $(A^{'}_{1}, A^{'}_{2}, \dots, A^{'}_{M})$ とする。本問題は「区間 $[l, r)$ の中に $A^{'}_{1}, A^{'}_{2}, \dots, A^{'}_{i}$ が合計 $k$ 個以上含まれているか？」という判定問題で二分探索すれば解ける。

区間 $[1, p)$ に含まれる $A^{'}_{1}, A^{'}_{2}, \dots, A^{'}_{i}$ の数の合計を $\text{pref}_{p, i}$ とする。興味のある値は $-\text{pref}(l, i) + +\text{pref}(r, i)$ である。

クエリを先読みして $l, r$ を集計し、平面走査を行うことで各クエリに対して判定問題を一回ずつ解くことができる。 $\text{pref}_{p, i}$ の計算にセグメント木を用いるとlog2つでできる。

セグメント木上の二分探索に想いを馳せるとさらにlogを一個落とすことができる。本ライブラリでは時間計算量 $\Theta ((N + Q)\log N)$ 、空間計算量 $\Theta (N + Q)$ を達成している。
