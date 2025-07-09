---
title: Manacher (Enumerate Palindromes)
documentation_of: //Src/Sequence/Manacher.hpp
---

## 概要

長さ $N$ の列 $A$ に対して以下の要件を満たす $2N - 1$ 要素の列 $(D_1, D_2, \dots, D_{2N - 1})$ を返す。

- $i$ が奇数ならば、 $D_i$ は $A$ の $\frac{i + 1}{2}$ 番目の要素を中心とする極大な回文の要素数
- $i$ が偶数ならば、 $D_i$ は $A$ の $\frac{i}{2}$ 番目の要素と $\frac{i}{2}+1$ 番目の要素の間を中心とする極大な回文の要素数

## ライブラリの使い方

```cpp
template <std::integral RES = usize, std::equality_comparable T = char, class C = std::string>
requires concepts::Container<C, T>
```

`RES`は返り値の型`usize`や`int`など。
