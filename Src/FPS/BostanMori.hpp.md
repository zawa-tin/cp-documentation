---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPS.hpp
    title: Src/FPS/FPS.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/KthTerm.hpp
    title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u306EK\u9805\u76EE\u3092\u8A08\u7B97\u3059\
      \u308B"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc436_g.test.cpp
    title: ABC436-G Linear Inequation
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/tdpc_fibonacci.test.cpp
    title: Test/AtCoder/tdpc_fibonacci.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/3044.test.cpp
    title: Test/yukicoder/3044.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/FPS/BostanMori.hpp\"\n\n#line 2 \"Src/FPS/FPS.hpp\"\n\
    \n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
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
    \  }\n};\n\n} // namespace zawa\n#line 4 \"Src/FPS/BostanMori.hpp\"\n\nnamespace\
    \ zawa {\n\ntemplate <concepts::IndexedFPS FPS, class Conv = FPSMult>\nrequires\
    \ concepts::Convolution<FPS, Conv>\ntypename FPS::value_type BostanMori(usize\
    \ N, FPS P, FPS Q, Conv conv = {}) {\n    assert(P.size());\n    assert(Q.size()\
    \ and Q[0] != 0); \n    auto takeParity = [&](const FPS& f, usize p) {\n     \
    \   FPS res;\n        res.reserve(f.size() / 2);\n        for (usize i = p ; i\
    \ < f.size() ; i += 2)\n            res.push_back(f[i]);\n        return res;\n\
    \    };\n    while (N) {\n        FPS Qm(Q.size());\n        for (usize i = 0\
    \ ; i < Q.size() ; i++)\n            Qm[i] = i % 2 ? -Q[i] : Q[i];\n        P\
    \ = takeParity(conv(P, Qm), N % 2);\n        Q = takeParity(conv(Q, Qm), 0);\n\
    \        N >>= 1;\n    }\n    return P[0] / Q[0];\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"FPS.hpp\"\n\nnamespace zawa {\n\ntemplate <concepts::IndexedFPS\
    \ FPS, class Conv = FPSMult>\nrequires concepts::Convolution<FPS, Conv>\ntypename\
    \ FPS::value_type BostanMori(usize N, FPS P, FPS Q, Conv conv = {}) {\n    assert(P.size());\n\
    \    assert(Q.size() and Q[0] != 0); \n    auto takeParity = [&](const FPS& f,\
    \ usize p) {\n        FPS res;\n        res.reserve(f.size() / 2);\n        for\
    \ (usize i = p ; i < f.size() ; i += 2)\n            res.push_back(f[i]);\n  \
    \      return res;\n    };\n    while (N) {\n        FPS Qm(Q.size());\n     \
    \   for (usize i = 0 ; i < Q.size() ; i++)\n            Qm[i] = i % 2 ? -Q[i]\
    \ : Q[i];\n        P = takeParity(conv(P, Qm), N % 2);\n        Q = takeParity(conv(Q,\
    \ Qm), 0);\n        N >>= 1;\n    }\n    return P[0] / Q[0];\n}\n\n} // namespace\
    \ zawa\n"
  dependsOn:
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/FPS/BostanMori.hpp
  requiredBy:
  - Src/FPS/KthTerm.hpp
  timestamp: '2026-01-03 22:37:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
  - Test/yukicoder/3044.test.cpp
  - Test/AtCoder/tdpc_fibonacci.test.cpp
  - Test/AtCoder/abc436_g.test.cpp
documentation_of: Src/FPS/BostanMori.hpp
layout: document
title: "$[x^{N}]\\frac{P(x)}{Q(x)}$ \u306E\u9AD8\u901F\u8A08\u7B97 (Bostan-Mori \u30A2\
  \u30EB\u30B4\u30EA\u30BA\u30E0)"
---

## 概要

## ライブラリの説明

```
template <concepts::IndexedFPS FPS, class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
typename FPS::value_type BostanMori(usize N, FPS P, FPS Q, Conv conv = {})
```

$[x^N]\frac{P(x)}{Q(x)}$を計算する

`conv`は`FPSNTTFriendly`のときは何も指定しなくても良い。それ以外のときは畳み込みをする関数オブジェクトを与える。

$\Theta O(NM)$ の畳み込みは`FPS.hpp`の`NaiveConvolution`を与えると良い。

**計算量**

- 畳み込みを $2\times \lceil\log_{2}(N + 1)\rceil$ 回行うのがボトルネック
