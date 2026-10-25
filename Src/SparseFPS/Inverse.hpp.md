---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/SparseFPS.hpp
    title: "\u975E\u96F6\u306E\u4FC2\u6570\u306E\u500B\u6570\u304C\u5341\u5206\u5C11\
      \u306A\u3044FPS"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/inv_of_formal_power_series_sparse.test.cpp
    title: Test/LC/inv_of_formal_power_series_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/SparseFPS/Inverse.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/SparseFPS/SparseFPS.hpp\"\n\n#include <concepts>\n\
    #include <vector>\n\nnamespace zawa {\n\nnamespace SparseFPS {\n\ntemplate <std::integral\
    \ Degree,class Coef>\nstruct Term {\n    Degree degree;\n    Coef coef;\n};\n\n\
    template <std::integral Degree,class Coef>\nusing Series = std::vector<Term<Degree,Coef>>;\n\
    \n} // namespace SparseFPS\n\n} // namespace zawa\n#line 5 \"Src/SparseFPS/Inverse.hpp\"\
    \n\n#include <cassert>\n#include <utility>\n\nnamespace zawa {\n\nnamespace SparseFPS\
    \ {\n\ntemplate <std::integral Degree,class Coef>\nstd::vector<Coef> Inv(const\
    \ Series<Degree,Coef>& f,usize n) {\n    assert(f.size() and f[0].degree==0);\n\
    \    std::vector<Coef> res(n);\n    if (!n)\n        return res;\n    res[0]=Coef{1}/f[0].coef;\n\
    \    usize idx=0;\n    for (usize i = 1 ; i < n ; i++) {\n        while (idx <\
    \ f.size() and std::cmp_less_equal(f[idx].degree,i))\n            idx++;\n   \
    \     Coef val=0;\n        for (usize j = 1 ; j < idx ; j++)\n            val+=f[j].coef*res[i-f[j].degree];\n\
    \        res[i]=-val*res[0];\n    }\n    return res;\n}\n\n} // namespace SparseFPS\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"SparseFPS.hpp\"\
    \n\n#include <cassert>\n#include <utility>\n\nnamespace zawa {\n\nnamespace SparseFPS\
    \ {\n\ntemplate <std::integral Degree,class Coef>\nstd::vector<Coef> Inv(const\
    \ Series<Degree,Coef>& f,usize n) {\n    assert(f.size() and f[0].degree==0);\n\
    \    std::vector<Coef> res(n);\n    if (!n)\n        return res;\n    res[0]=Coef{1}/f[0].coef;\n\
    \    usize idx=0;\n    for (usize i = 1 ; i < n ; i++) {\n        while (idx <\
    \ f.size() and std::cmp_less_equal(f[idx].degree,i))\n            idx++;\n   \
    \     Coef val=0;\n        for (usize j = 1 ; j < idx ; j++)\n            val+=f[j].coef*res[i-f[j].degree];\n\
    \        res[i]=-val*res[0];\n    }\n    return res;\n}\n\n} // namespace SparseFPS\n\
    \n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/SparseFPS/SparseFPS.hpp
  isVerificationFile: false
  path: Src/SparseFPS/Inverse.hpp
  requiredBy: []
  timestamp: '2026-10-24 17:27:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/inv_of_formal_power_series_sparse.test.cpp
documentation_of: Src/SparseFPS/Inverse.hpp
layout: document
title: SparseFPS::Inv
---

## 概要

```cpp
template <std::integral Degree,class Coef>
std::vector<Coef> Inv(const Series<Degree,Coef>& f,usize n)
```

非零な係数の個数が十分に少ない形式的冪級数 $f$ に関して、 $fg=1$ を満たす $g$ の $\mod{x^n}$ を計算する。

返り値は長さ $n$ の列であり、 $i$ 番目の要素が $[x^i]g$ に対応している。

## 制約

形式的冪級数 $f$ は $[x^0]f$ が乗法逆元を持つときに、自身の逆元が定義される。これを本ライブラリの言葉で書くと次の通りとなる。

- $f$ は空ではなく、`f[0].degree`が $0$ であること。
- `f[0].coef`に乗法逆元が存在すること(特に、`atcoder::modint998244353`下では、単に $0$ でないこと)

## 計算量

計算量は、 $f$ の要素数を $k$ として $O(nk)$ 。ただし、 $n=0$ の場合は $O(1)$ であり、係数の演算を $O(1)$ とする。

乗法逆元の計算を $O(\log MOD)$ 、それ以外の係数の演算を $O(1)$ とする場合、 $n>0$ では全体で $O(nk+\log MOD)$ かかる。ここで、 $MOD$ は係数の法である。先頭で $[x^0]f$ の逆元を一度だけ計算し、以降の係数計算ではその値を使い回す。 $n=0$ の場合は逆元を計算せず、 $O(1)$ である。

## 更新履歴

- 2026/10/24: 作成
- 2026/10/25: 乗法逆元の計算量を含む解析を追記
