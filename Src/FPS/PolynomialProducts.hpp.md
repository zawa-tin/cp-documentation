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
    path: Test/AtCoder/abc385_g.test.cpp
    title: Test/AtCoder/abc385_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/product_of_polynomial_sequence.test.cpp
    title: Test/LC/product_of_polynomial_sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/FPS/PolynomialProducts.hpp\"\n\n#line 2 \"Src/FPS/FPS.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/FPS/FPS.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class FPS>\nconcept IndexedFPS = requires(FPS f, usize i) {\n    typename FPS::value_type;\n\
    \    { f.size() } -> std::convertible_to<usize>;\n    { f[i] } -> std::convertible_to<typename\
    \ FPS::value_type>;\n    f.reserve(0);\n    f.push_back(f[i]);\n};\n\ntemplate\
    \ <class FPS, class Conv>\nconcept Convolution = \n    std::regular_invocable<Conv,\
    \ const FPS&, const FPS&> &&\n    std::same_as<std::invoke_result_t<Conv, const\
    \ FPS&, const FPS&>, FPS>;\n\n} // namespace concepts\n\nstruct FPSMult {\n  \
    \  template <class FPS>\n    requires requires(const FPS& a, const FPS& b) {\n\
    \        { a * b } -> std::same_as<FPS>;\n    }\n    FPS operator()(const FPS&\
    \ a, const FPS& b) const {\n        return a * b;\n    }\n};\n\nstruct NaiveConvolution\
    \ {\n    template <class FPS>\n    FPS operator()(const FPS& a, const FPS& b)\
    \ const {\n        if (a.empty())\n            return b;\n        if (b.empty())\n\
    \            return a;\n        FPS res(a.size() + b.size() - 1);\n        for\
    \ (usize i = 0 ; i < a.size() ; i++)\n            for (usize j = 0 ; j < b.size()\
    \ ; j++)\n                res[i + j] += a[i] * b[j];\n        return res;\n  \
    \  }\n};\n\n} // namespace zawa\n#line 4 \"Src/FPS/PolynomialProducts.hpp\"\n\n\
    #include <vector>\n\nnamespace zawa {\n\ntemplate <concepts::IndexedFPS FPS, class\
    \ Conv = FPSMult>\nrequires concepts::Convolution<FPS, Conv>\nFPS PolynomialProducts(std::vector<FPS>\
    \ F, Conv convolution = {}) {\n    if (F.empty())\n        return {1};\n    auto\
    \ rec = [&](auto rec, usize l, usize r) -> void {\n        if (l + 1 >= r)\n \
    \           return;\n        const usize md = (l + r) >> 1;\n        rec(rec,\
    \ l, md);\n        rec(rec, md, r);\n        F[l] = convolution(F[l], F[md]);\n\
    \    };\n    rec(rec, 0u, F.size());\n    return F[0];\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"FPS.hpp\"\n\n#include <vector>\n\nnamespace zawa\
    \ {\n\ntemplate <concepts::IndexedFPS FPS, class Conv = FPSMult>\nrequires concepts::Convolution<FPS,\
    \ Conv>\nFPS PolynomialProducts(std::vector<FPS> F, Conv convolution = {}) {\n\
    \    if (F.empty())\n        return {1};\n    auto rec = [&](auto rec, usize l,\
    \ usize r) -> void {\n        if (l + 1 >= r)\n            return;\n        const\
    \ usize md = (l + r) >> 1;\n        rec(rec, l, md);\n        rec(rec, md, r);\n\
    \        F[l] = convolution(F[l], F[md]);\n    };\n    rec(rec, 0u, F.size());\n\
    \    return F[0];\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/FPS/PolynomialProducts.hpp
  requiredBy: []
  timestamp: '2026-01-12 19:02:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/product_of_polynomial_sequence.test.cpp
  - Test/AtCoder/abc385_g.test.cpp
documentation_of: Src/FPS/PolynomialProducts.hpp
layout: document
title: "\u6B21\u6570\u306E\u7DCF\u548C\u304C\u6291\u3048\u3089\u308C\u3066\u3044\u308B\
  \u591A\u9805\u5F0F\u306E\u5217\u306E\u7DCF\u7A4D"
---

## 概要

## ライブラリの説明

```
template <concepts::IndexedFPS FPS, class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
FPS PolynomialProducts(std::vector<FPS> F, Conv convolution = {}) {
```

`conv`は`FPSNTTFriendly`のときは何も指定しなくても良い。それ以外のときは畳み込みをする関数オブジェクトを与える。

$\Theta O(NM)$ の畳み込みは`FPS.hpp`の`NaiveConvolution`を与えると良い。

**計算量:** 次数の総和を $N$ として $O(N\log^2 N)$ (畳み込みが $O(n\log n)$ であることを前提)
