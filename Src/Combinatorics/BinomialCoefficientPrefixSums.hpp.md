---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/Mo.hpp
    title: Src/Utility/Mo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/tenka1_2014_final_d.test.cpp
    title: Test/AtCoder/tenka1_2014_final_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Combinatorics/BinomialCoefficientPrefixSums.hpp\"\n\n\
    #line 2 \"Src/Utility/Mo.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include\
    \ <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 = std::int16_t;\n\
    using i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128 = __int128_t;\n\
    \nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\n} // namespace zawa\n\
    #line 4 \"Src/Utility/Mo.hpp\"\n\n#include <algorithm>\n#include <cmath>\n#include\
    \ <concepts>\n#include <ranges>\n#include <utility>\n#include <numeric>\n#include\
    \ <limits>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <std::signed_integral\
    \ T>\nstd::vector<usize> Mo(const std::vector<std::pair<T,T>>& P) {\n    if (P.empty())\n\
    \        return {};\n    T minY = std::numeric_limits<T>::max();\n    const u64\
    \ W = [&]() {\n        T minX = std::numeric_limits<T>::max();\n        T maxX\
    \ = std::numeric_limits<T>::min(), maxY = std::numeric_limits<T>::min();\n   \
    \     for (auto [x,y] : P) {\n            minX = std::min(minX,x);\n         \
    \   maxX = std::max(maxX,x);\n            minY = std::min(minY,y);\n         \
    \   maxY = std::max(maxY,y);\n        }\n        return std::max<u64>({1,u64(maxX-minX),u64(maxY-minY)});\n\
    \    }();\n    const usize B = [&]() {\n        u64 sq = std::max<u64>(1,sqrt(P.size()));\n\
    \        return (W + sq - 1) / sq;\n    }();\n    T sub = minY;\n    auto makeRank\
    \ = [&]() -> std::vector<std::pair<T,T>> {\n        std::vector<std::pair<T,T>>\
    \ res(P.size());\n        for (usize i = 0 ; i < P.size() ; i++) {\n         \
    \   res[i].first = (P[i].second - sub) / B;\n            res[i].second = (res[i].first\
    \ & 1 ? -1 : 1) * P[i].first;\n        }\n        return res;\n    };\n    std::vector<usize>\
    \ ord1(P.size()), ord2(P.size());\n    std::iota(ord1.begin(),ord1.end(),0);\n\
    \    std::iota(ord2.begin(),ord2.end(),0);\n    auto rank = makeRank();\n    std::ranges::sort(ord1,[&](usize\
    \ i, usize j) { return rank[i] < rank[j]; });\n    sub -= B / 2;\n    rank = makeRank();\n\
    \    std::ranges::sort(ord2,[&](usize i, usize j) { return rank[i] < rank[j];\
    \ });\n    auto cost = [&](const std::vector<usize>& ord) {\n        u64 res =\
    \ 0;\n        for (usize i = 0 ; i + 1 < ord.size() ; i++) {\n            res\
    \ += abs(P[ord[i+1]].first-P[ord[i]].first);\n            res += abs(P[ord[i+1]].second-P[ord[i]].second);\n\
    \        }\n        return res;\n    };\n    return cost(ord1) <= cost(ord2) ?\
    \ ord1 : ord2;\n}\n\n} // namespace zawa\n#line 4 \"Src/Combinatorics/BinomialCoefficientPrefixSums.hpp\"\
    \n\n#line 6 \"Src/Combinatorics/BinomialCoefficientPrefixSums.hpp\"\n#include\
    \ <cassert>\n#line 10 \"Src/Combinatorics/BinomialCoefficientPrefixSums.hpp\"\n\
    \nnamespace zawa {\n\ntemplate <class T,std::signed_integral U>\nstd::vector<T>\
    \ BinomialCoefficientPrefixSums(std::vector<std::pair<U,U>> P) {\n    U maxN =\
    \ 0;\n    for (auto& [n,k] : P) {\n        assert(n >= 0 and k >= 0);\n      \
    \  k = std::min(k,n);\n        maxN = std::max(maxN,n);\n    }\n    auto ord =\
    \ Mo(P);\n    std::vector<T> res(P.size()),fac(maxN+1),ifac(maxN+1);\n    fac[0]\
    \ = 1;\n    for (U i = 1 ; i <= maxN ; i++)\n        fac[i] = fac[i-1] * T{i};\n\
    \    ifac[maxN] = T{1} / fac[maxN];\n    for (U i = maxN ; i >= 1 ; i--)\n   \
    \     ifac[i-1] = ifac[i] * T{i};\n    auto comb = [&](U n,U k) -> T {\n     \
    \   return fac[n] * ifac[k] * ifac[n-k];\n    };\n    U n = 0, k = 0;\n    const\
    \ T inv2 = T{1} / T{2};\n    T cur = T{1};\n    for (auto idx : ord) {\n     \
    \   auto [N,K] = P[idx];\n        while (n < N) {\n            cur = T{2} * cur\
    \ - comb(n,k);\n            n++;\n        }\n        while (k < K) {\n       \
    \     cur += comb(n,k+1);\n            k++;\n        }\n        while (k > K)\
    \ {\n            cur -= comb(n,k);\n            k--;\n        }\n        while\
    \ (n > N) {\n            cur = inv2 * (cur + comb(n-1,k));\n            n--;\n\
    \        }\n        res[idx] = cur;\n    }\n    return res;\n}\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include \"../Utility/Mo.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <concepts>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class T,std::signed_integral U>\nstd::vector<T>\
    \ BinomialCoefficientPrefixSums(std::vector<std::pair<U,U>> P) {\n    U maxN =\
    \ 0;\n    for (auto& [n,k] : P) {\n        assert(n >= 0 and k >= 0);\n      \
    \  k = std::min(k,n);\n        maxN = std::max(maxN,n);\n    }\n    auto ord =\
    \ Mo(P);\n    std::vector<T> res(P.size()),fac(maxN+1),ifac(maxN+1);\n    fac[0]\
    \ = 1;\n    for (U i = 1 ; i <= maxN ; i++)\n        fac[i] = fac[i-1] * T{i};\n\
    \    ifac[maxN] = T{1} / fac[maxN];\n    for (U i = maxN ; i >= 1 ; i--)\n   \
    \     ifac[i-1] = ifac[i] * T{i};\n    auto comb = [&](U n,U k) -> T {\n     \
    \   return fac[n] * ifac[k] * ifac[n-k];\n    };\n    U n = 0, k = 0;\n    const\
    \ T inv2 = T{1} / T{2};\n    T cur = T{1};\n    for (auto idx : ord) {\n     \
    \   auto [N,K] = P[idx];\n        while (n < N) {\n            cur = T{2} * cur\
    \ - comb(n,k);\n            n++;\n        }\n        while (k < K) {\n       \
    \     cur += comb(n,k+1);\n            k++;\n        }\n        while (k > K)\
    \ {\n            cur -= comb(n,k);\n            k--;\n        }\n        while\
    \ (n > N) {\n            cur = inv2 * (cur + comb(n-1,k));\n            n--;\n\
    \        }\n        res[idx] = cur;\n    }\n    return res;\n}\n\n} // namespace\
    \ zawa\n"
  dependsOn:
  - Src/Utility/Mo.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Combinatorics/BinomialCoefficientPrefixSums.hpp
  requiredBy: []
  timestamp: '2026-10-13 17:04:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/tenka1_2014_final_d.test.cpp
documentation_of: Src/Combinatorics/BinomialCoefficientPrefixSums.hpp
layout: document
title: "\u4E8C\u9805\u4FC2\u6570prefix sum $(\\sum_{i=0}^{k}\\binom{n}{i})$"
---

## 概要

```cpp
template <class T,std::signed_integral U>
std::vector<T> BinomialCoefficientPrefixSums(std::vector<std::pair<U,U>> P)
```

$Q$ クエリ与えられる。 $i$ 番目のクエリでは $\sum_{j=0}^{k_{i}}\binom{n_i}{j}$ を求めよ

という問題をMo's Algorithmでオフライン処理する。 クエリ $(n,k)$ に対する答えを $f(n,k)$ とすると...

$$
\begin{aligned}
f(n+1,k) &= 2f(n,k)-\binom{n}{k} \\
\frac{1}{2}(f(n+1,k)+\binom{n}{k}) &= f(n,k)
\end{aligned}
$$

という関係式が成り立つので、 $n$ を $1$ 動かす差分更新が高速にできる。 $k$ に対する差分更新は自明。

クエリの $n$ の最大値を $N$ として、計算量は $O(N\sqrt{Q} + Q\log Q)$ である。

## 制約

`T`として基本的に $\mathbb{F}_{p}$ を用いることが暗黙に仮定されている。このときの`T`は $2,N!$ の乗法逆元が定義できることが必要であることに注意せよ。

クエリで与える $n,k$ はどちらも非負であることを仮定している。なお、内部で用いるMo's Algorithmの都合上、 $n,k$ の型である`U`は符号付である必要がある。

## 更新履歴

- 2026/10/13: 作成
