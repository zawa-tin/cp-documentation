---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/BitwiseAndConvolution.hpp
    title: Src/Sequence/BitwiseAndConvolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/bitwise_and_convolution.test.cpp
    title: Test/LC/bitwise_and_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Sequence/SupersetTransform.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Sequence/SupersetTransform.hpp\"\n\n#include\
    \ <vector>\n\nnamespace zawa {\n\ntemplate <class T>\nvoid SupersetZetaTransform(usize\
    \ n, std::vector<T>& a) {\n    for (usize i = 0 ; i < n ; i++)\n        for (usize\
    \ b = ssize(a) ; b-- ; )\n            if (b & (usize{1} << i))\n             \
    \   a[b ^ (usize{1} << i)] += a[b];\n}\n\ntemplate <class T>\nvoid SupersetMobiusTransform(usize\
    \ n, std::vector<T>& a) {\n    for (usize i = 0 ; i < n ; i++)\n        for (usize\
    \ b = ssize(a) ; b-- ; )\n            if (b & (usize{1} << i))\n             \
    \   a[b ^ (usize{1} << i)] -= a[b];\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nvoid SupersetZetaTransform(usize n,\
    \ std::vector<T>& a) {\n    for (usize i = 0 ; i < n ; i++)\n        for (usize\
    \ b = ssize(a) ; b-- ; )\n            if (b & (usize{1} << i))\n             \
    \   a[b ^ (usize{1} << i)] += a[b];\n}\n\ntemplate <class T>\nvoid SupersetMobiusTransform(usize\
    \ n, std::vector<T>& a) {\n    for (usize i = 0 ; i < n ; i++)\n        for (usize\
    \ b = ssize(a) ; b-- ; )\n            if (b & (usize{1} << i))\n             \
    \   a[b ^ (usize{1} << i)] -= a[b];\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Sequence/SupersetTransform.hpp
  requiredBy:
  - Src/Sequence/BitwiseAndConvolution.hpp
  timestamp: '2025-09-23 00:58:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/bitwise_and_convolution.test.cpp
documentation_of: Src/Sequence/SupersetTransform.hpp
layout: document
title: "Superset Zeta/Mobius Transform ( $\\emptyset$ \u306E\u65B9\u3078\u96C6\u3081\
  \u308B\u3084\u3064 )"
---

## 概要

$n$ 要素の集合に関するゼータ・メビウス変換で特に上位集合に関して集めてくるもの。

ここでのゼータ変換は $B_{S} = \sum_{S\subseteq T} A_{T}$ なる $B$ を計算し、メビウス変換はその逆変換。

自分は $\emptyset$ の方向へ累積和を取るやつと覚えている。

## ライブラリの使い方

```cpp
void SupersetZetaTransform(usize n, std::vector<T>& a)
void SupersetMobiusTransform(usize n, std::vector<T>& a)
```

$n$ も指定する
