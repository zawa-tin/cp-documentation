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
    path: Test/AtCoder/abc345_g.test.cpp
    title: Test/AtCoder/abc345_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/My/FPS/PowerProjection.test.cpp
    title: Test/My/FPS/PowerProjection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/FPS/PowerProjection.hpp\"\n\n#line 2 \"Src/FPS/FPS.hpp\"\
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
    \  }\n};\n\n} // namespace zawa\n#line 4 \"Src/FPS/PowerProjection.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <bit>\n#include <vector>\n#include\
    \ <ranges>\n\nnamespace zawa {\n\n// i = 0, 1, 2, \\dots, M - 1\n// res[i] = \\\
    sum_{j} W([x^j]F(x)^i)\ntemplate <concepts::IndexedFPS FPS, class Conv = FPSMult>\n\
    requires concepts::Convolution<FPS, Conv>\nstd::vector<typename FPS::value_type>\
    \ PowerProjection(usize m, FPS W, FPS F, Conv convolution = {}) {\n    using Element\
    \ = typename FPS::value_type;\n    assert(W.size());\n    if (!m)\n        return\
    \ {};\n    if (F[0] != Element{0}) {\n        std::vector<Element> fact(m, 1),\
    \ invFact(m);\n        for (usize i = 1 ; i < m ; i++)\n            fact[i] =\
    \ fact[i - 1] * Element{i};\n        invFact[m - 1] = Element{1} / fact[m - 1];\n\
    \        for (usize i = m ; --i ; )\n            invFact[i - 1] = invFact[i] *\
    \ Element{i};\n        const Element c = F[0];\n        F[0] = 0;\n        FPS\
    \ cur{PowerProjection(m, W, F, convolution)};\n        FPS op(m);\n        Element\
    \ pw = 1;\n        for (usize i = 0 ; i < m ; i++, pw *= c) {\n            op[i]\
    \ = pw * invFact[i];\n            cur[i] *= invFact[i];\n        }\n        auto\
    \ res = convolution(cur, op);\n        res.resize(m);\n        for (usize i =\
    \ 0 ; i < m ; i++)\n            res[i] *= fact[i];\n        return res;\n    }\n\
    \    usize nx = std::bit_ceil(W.size()), ny = 1;\n    W.resize(nx);\n    F.resize(nx);\n\
    \    std::ranges::reverse(W);\n    // bostan mori [x^{n-1}](g(x)/(1-yf(x)))\n\
    \    FPS P(2 * nx * ny), Q(2 * nx * ny);\n    for (usize x = 0 ; x < nx ; x++)\
    \ {\n        P[x] = W[x];\n        Q[x] = -F[x];\n    }\n    while (nx > 1) {\n\
    \        FPS R = Q;\n        for (usize i = 1 ; i < R.size() ; i += 2)\n     \
    \       R[i] = -R[i];\n        auto PR = convolution(P, R), QR = convolution(Q,\
    \ R);\n        PR.resize(4 * nx * ny);\n        QR.resize(4 * nx * ny);\n    \
    \    for (usize i = 0 ; i < P.size() ; i++) {\n            PR[i + P.size()] +=\
    \ P[i];\n            QR[i + P.size()] += Q[i] + R[i];\n        }\n        std::ranges::fill(P,\
    \ Element{0});\n        std::ranges::fill(Q, Element{0});\n        for (usize\
    \ y = 0 ; y < (ny << 1) ; y++) {\n            for (usize x = 1 ; x < nx ; x +=\
    \ 2)\n                P[y * nx + (x >> 1)] = PR[y * (nx << 1) + x];\n        \
    \    for (usize x = 0 ; x < nx ; x += 2)\n                Q[y * nx + (x >> 1)]\
    \ = QR[y * (nx << 1) + x];\n        }\n        nx >>= 1;\n        ny <<= 1;\n\
    \    }\n    std::vector<Element> res(ny);\n    for (usize i = 0 ; i < ny ; i++)\n\
    \        res[i] = P[i << 1];\n    std::ranges::reverse(res);\n    res.resize(m);\n\
    \    return res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"FPS.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <bit>\n#include <vector>\n#include <ranges>\n\nnamespace zawa {\n\n//\
    \ i = 0, 1, 2, \\dots, M - 1\n// res[i] = \\sum_{j} W([x^j]F(x)^i)\ntemplate <concepts::IndexedFPS\
    \ FPS, class Conv = FPSMult>\nrequires concepts::Convolution<FPS, Conv>\nstd::vector<typename\
    \ FPS::value_type> PowerProjection(usize m, FPS W, FPS F, Conv convolution = {})\
    \ {\n    using Element = typename FPS::value_type;\n    assert(W.size());\n  \
    \  if (!m)\n        return {};\n    if (F[0] != Element{0}) {\n        std::vector<Element>\
    \ fact(m, 1), invFact(m);\n        for (usize i = 1 ; i < m ; i++)\n         \
    \   fact[i] = fact[i - 1] * Element{i};\n        invFact[m - 1] = Element{1} /\
    \ fact[m - 1];\n        for (usize i = m ; --i ; )\n            invFact[i - 1]\
    \ = invFact[i] * Element{i};\n        const Element c = F[0];\n        F[0] =\
    \ 0;\n        FPS cur{PowerProjection(m, W, F, convolution)};\n        FPS op(m);\n\
    \        Element pw = 1;\n        for (usize i = 0 ; i < m ; i++, pw *= c) {\n\
    \            op[i] = pw * invFact[i];\n            cur[i] *= invFact[i];\n   \
    \     }\n        auto res = convolution(cur, op);\n        res.resize(m);\n  \
    \      for (usize i = 0 ; i < m ; i++)\n            res[i] *= fact[i];\n     \
    \   return res;\n    }\n    usize nx = std::bit_ceil(W.size()), ny = 1;\n    W.resize(nx);\n\
    \    F.resize(nx);\n    std::ranges::reverse(W);\n    // bostan mori [x^{n-1}](g(x)/(1-yf(x)))\n\
    \    FPS P(2 * nx * ny), Q(2 * nx * ny);\n    for (usize x = 0 ; x < nx ; x++)\
    \ {\n        P[x] = W[x];\n        Q[x] = -F[x];\n    }\n    while (nx > 1) {\n\
    \        FPS R = Q;\n        for (usize i = 1 ; i < R.size() ; i += 2)\n     \
    \       R[i] = -R[i];\n        auto PR = convolution(P, R), QR = convolution(Q,\
    \ R);\n        PR.resize(4 * nx * ny);\n        QR.resize(4 * nx * ny);\n    \
    \    for (usize i = 0 ; i < P.size() ; i++) {\n            PR[i + P.size()] +=\
    \ P[i];\n            QR[i + P.size()] += Q[i] + R[i];\n        }\n        std::ranges::fill(P,\
    \ Element{0});\n        std::ranges::fill(Q, Element{0});\n        for (usize\
    \ y = 0 ; y < (ny << 1) ; y++) {\n            for (usize x = 1 ; x < nx ; x +=\
    \ 2)\n                P[y * nx + (x >> 1)] = PR[y * (nx << 1) + x];\n        \
    \    for (usize x = 0 ; x < nx ; x += 2)\n                Q[y * nx + (x >> 1)]\
    \ = QR[y * (nx << 1) + x];\n        }\n        nx >>= 1;\n        ny <<= 1;\n\
    \    }\n    std::vector<Element> res(ny);\n    for (usize i = 0 ; i < ny ; i++)\n\
    \        res[i] = P[i << 1];\n    std::ranges::reverse(res);\n    res.resize(m);\n\
    \    return res;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/FPS/PowerProjection.hpp
  requiredBy: []
  timestamp: '2026-01-12 16:27:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc345_g.test.cpp
  - Test/My/FPS/PowerProjection.test.cpp
documentation_of: Src/FPS/PowerProjection.hpp
layout: document
title: FPS Power Projection
---

## 概要

長さ $n$ の数列 $W = (W_0, W_1, \dots, W_{n - 1})$ 、正整数 $m$ 、 FPS $F(x)$ に対して

$$
\sum_{i = 0}^{n - 1} w_{i}([x^i]F(x)^{j})
$$

を $j = 0, 1, 2, \dots, m - 1$ に対して列挙する。

## ライブラリの使い方

```cpp
template <concepts::IndexedFPS FPS, class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
std::vector<typename FPS::value_type> PowerProjection(usize m, FPS W, FPS F, Conv convolution = {}) {
```

`FPS=FPSNTTFriendly<MOD>`の場合、`convolution`は自動的に`operator*`が使われる。それ以外の場合は自分で`convolution`を指定する必要がある。

- $2$ 乗かけて愚直にやる畳み込みは`FPS.hpp`の`NaiveConvolution`を使うと良い。

**計算量**
- $N$ を `bit_ceil<usize>(n)` とする。
- 長さ $2N$ の列同士の畳み込みを $\log_{2}N$ 回行う
- 長さ $m$ の列同士の畳み込みを高々 $1$ 回行う
- $+O(N\log N + m)$
- つまるところ、`FPSNTTFriendly<MOD>`では $O(n\log^2 n + m\log m)$
