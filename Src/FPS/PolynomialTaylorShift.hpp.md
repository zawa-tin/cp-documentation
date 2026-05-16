---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPS.hpp
    title: Src/FPS/FPS.hpp
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
    \n} // namespace zawa\n#line 2 \"Src/FPS/FPS.hpp\"\n\n#line 4 \"Src/FPS/FPS.hpp\"\
    \n\n#line 6 \"Src/FPS/FPS.hpp\"\n\nnamespace zawa {\n\nnamespace concepts {\n\n\
    template <class FPS>\nconcept IndexedFPS = requires(FPS f, usize i) {\n    typename\
    \ FPS::value_type;\n    { f.size() } -> std::convertible_to<usize>;\n    { f[i]\
    \ } -> std::convertible_to<typename FPS::value_type>;\n    f.reserve(0);\n   \
    \ f.push_back(f[i]);\n};\n\ntemplate <class FPS, class Conv>\nconcept Convolution\
    \ = \n    std::regular_invocable<Conv, const FPS&, const FPS&> &&\n    std::same_as<std::invoke_result_t<Conv,\
    \ const FPS&, const FPS&>, FPS>;\n\n} // namespace concepts\n\nstruct FPSMult\
    \ {\n    template <class FPS>\n    requires requires(const FPS& a, const FPS&\
    \ b) {\n        { a * b } -> std::same_as<FPS>;\n    }\n    FPS operator()(const\
    \ FPS& a, const FPS& b) const {\n        return a * b;\n    }\n};\n\nstruct NaiveConvolution\
    \ {\n    template <class FPS>\n    FPS operator()(const FPS& a, const FPS& b)\
    \ const {\n        if (a.empty())\n            return b;\n        if (b.empty())\n\
    \            return a;\n        FPS res(a.size() + b.size() - 1);\n        for\
    \ (usize i = 0 ; i < a.size() ; i++)\n            for (usize j = 0 ; j < b.size()\
    \ ; j++)\n                res[i + j] += a[i] * b[j];\n        return res;\n  \
    \  }\n};\n\n} // namespace zawa\n#line 10 \"Src/FPS/PolynomialTaylorShift.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class C, concepts::IndexedFPS FPS, class Conv\
    \ = FPSMult>\nrequires concepts::Convolution<FPS, Conv>\nFPS PolynomialTaylorShift(FPS\
    \ a, C c, Conv conv = {}) {\n    assert(a.size());\n    FPS invfact(a.size());\n\
    \    using T = typename FPS::value_type;\n    T f{1};\n    for (usize i = 1 ;\
    \ i < a.size() ; i++) {\n        f *= i;\n        a[i] *= f;\n    }\n    invfact.back()\
    \ = T{1} / f;\n    for (usize i = a.size() - 1 ; i >= 1 ; i--) \n        invfact[i\
    \ - 1] = invfact[i] * T{i};\n    FPS right(a.size());\n    T powc = 1;\n    for\
    \ (usize i = 0 ; i < a.size() ; i++) {\n        right[i] = invfact[i] * powc;\n\
    \        powc *= T{c};\n    }\n    std::ranges::reverse(a);\n    const usize n\
    \ = a.size();\n    FPS b = conv(std::move(a), std::move(right));\n    b.resize(n);\n\
    \    std::ranges::reverse(b);\n    for (usize i = 0 ; i < b.size() ; i++) \n \
    \       b[i] *= invfact[i];\n    return b;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    #include <concepts>\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"FPS.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class C, concepts::IndexedFPS FPS, class Conv\
    \ = FPSMult>\nrequires concepts::Convolution<FPS, Conv>\nFPS PolynomialTaylorShift(FPS\
    \ a, C c, Conv conv = {}) {\n    assert(a.size());\n    FPS invfact(a.size());\n\
    \    using T = typename FPS::value_type;\n    T f{1};\n    for (usize i = 1 ;\
    \ i < a.size() ; i++) {\n        f *= i;\n        a[i] *= f;\n    }\n    invfact.back()\
    \ = T{1} / f;\n    for (usize i = a.size() - 1 ; i >= 1 ; i--) \n        invfact[i\
    \ - 1] = invfact[i] * T{i};\n    FPS right(a.size());\n    T powc = 1;\n    for\
    \ (usize i = 0 ; i < a.size() ; i++) {\n        right[i] = invfact[i] * powc;\n\
    \        powc *= T{c};\n    }\n    std::ranges::reverse(a);\n    const usize n\
    \ = a.size();\n    FPS b = conv(std::move(a), std::move(right));\n    b.resize(n);\n\
    \    std::ranges::reverse(b);\n    for (usize i = 0 ; i < b.size() ; i++) \n \
    \       b[i] *= invfact[i];\n    return b;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/FPS/FPS.hpp
  isVerificationFile: false
  path: Src/FPS/PolynomialTaylorShift.hpp
  requiredBy: []
  timestamp: '2026-01-03 20:52:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc215_g.test.cpp
  - Test/LC/polynomial_taylor_shift.test.cpp
documentation_of: Src/FPS/PolynomialTaylorShift.hpp
layout: document
title: Polynomial Taylor Shift
---

## 概要

多項式 $f(x)$ 及び整数 $c$ に対して $f(x+c) = g(x)$ を満たす多項式 $g(x)$ の係数列を $\Theta (N\log N)$ で計算する。

## ライブラリの使い方

```cpp
template <class C, concepts::IndexedFPS FPS, class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
FPS PolynomialTaylorShift(FPS a, C c, Conv conv = {})
```

`conv`は畳み込みの関数。`FPSNTTFriendly`を使う際は何も指定しなくて良い。

$\Theta(NM)$ かけてやる愚直な畳み込みは `FPS.hpp` の `NaiveConvolution` の実体を与えると良い。
