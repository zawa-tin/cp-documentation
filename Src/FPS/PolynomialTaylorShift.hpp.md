---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc215_g.test.cpp
    title: ABC215-G Colorful Candies 2
  - icon: ':heavy_check_mark:'
    path: Test/LC/polynomial_taylor_shift.test.cpp
    title: Test/LC/polynomial_taylor_shift.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/FPS/PolynomialTaylorShift.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n#include <concepts>\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 9 \"Src/FPS/PolynomialTaylorShift.hpp\"\n\nnamespace\
    \ zawa {\n\ntemplate <class T, std::integral C, class F>\nstd::vector<T> PolynomialTaylorShift(std::vector<T>\
    \ a, C c, F convolution) {\n    assert(a.size());\n    std::vector<T> invfact(a.size());\n\
    \    T f{1};\n    for (usize i = 1 ; i < a.size() ; i++) {\n        f *= i;\n\
    \        a[i] *= f;\n    }\n    invfact.back() = T{1} / f;\n    for (usize i =\
    \ a.size() - 1 ; i >= 1 ; i--) invfact[i - 1] = invfact[i] * T{i};\n    std::vector<T>\
    \ right(a.size());\n    T powc = 1;\n    for (usize i = 0 ; i < a.size() ; i++)\
    \ {\n        right[i] = invfact[i] * powc;\n        powc *= T{c};\n    }\n   \
    \ std::ranges::reverse(a);\n    const usize n = a.size();\n    std::vector<T>\
    \ b = convolution(std::move(a), std::move(right));\n    b.resize(n);\n    std::ranges::reverse(b);\n\
    \    for (usize i = 0 ; i < b.size() ; i++) b[i] *= invfact[i];\n    return b;\n\
    }\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    #include <concepts>\n\n#include \"../Template/TypeAlias.hpp\"\n\nnamespace zawa\
    \ {\n\ntemplate <class T, std::integral C, class F>\nstd::vector<T> PolynomialTaylorShift(std::vector<T>\
    \ a, C c, F convolution) {\n    assert(a.size());\n    std::vector<T> invfact(a.size());\n\
    \    T f{1};\n    for (usize i = 1 ; i < a.size() ; i++) {\n        f *= i;\n\
    \        a[i] *= f;\n    }\n    invfact.back() = T{1} / f;\n    for (usize i =\
    \ a.size() - 1 ; i >= 1 ; i--) invfact[i - 1] = invfact[i] * T{i};\n    std::vector<T>\
    \ right(a.size());\n    T powc = 1;\n    for (usize i = 0 ; i < a.size() ; i++)\
    \ {\n        right[i] = invfact[i] * powc;\n        powc *= T{c};\n    }\n   \
    \ std::ranges::reverse(a);\n    const usize n = a.size();\n    std::vector<T>\
    \ b = convolution(std::move(a), std::move(right));\n    b.resize(n);\n    std::ranges::reverse(b);\n\
    \    for (usize i = 0 ; i < b.size() ; i++) b[i] *= invfact[i];\n    return b;\n\
    }\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/FPS/PolynomialTaylorShift.hpp
  requiredBy: []
  timestamp: '2025-05-09 01:17:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/polynomial_taylor_shift.test.cpp
  - Test/AtCoder/abc215_g.test.cpp
documentation_of: Src/FPS/PolynomialTaylorShift.hpp
layout: document
title: Polynomial Taylor Shift
---

## 概要

多項式 $f(x)$ 及び整数 $c$ に対して $f(x+c) = g(x)$ を満たす多項式 $g(x)$ の係数列を $\Theta (N\log N)$ で計算する。

## ライブラリの使い方

```cpp
template <class T, std::integral C, class F>
std::vector<T> PolynomialTaylorShift(std::vector<T> a, C c, F convolution) {
```

`convolution`は畳み込み計算をする関数を渡す。`atcoder::convolution<atcoder::modint998244353>`を渡しておけば今の所は大丈夫そう？
