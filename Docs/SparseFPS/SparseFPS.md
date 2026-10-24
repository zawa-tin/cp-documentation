---
title: 非零の係数の個数が十分少ないFPS
documentation_of: //Src/SparseFPS/SparseFPS.hpp
---

## 概要

係数が非零であるような項の個数が十分に少ないような形式的冪級数の各演算を提供するライブラリ。

```cpp
template <std::integral Degree,class Coef>
struct Term {
    Degree degree;
    Coef coef;
};

template <std::integral Degree,class Coef>
using Series = std::vector<Term<Degree,Coef>>;
```

`SparseFPS`という名前空間上に上記の実装がある。コンテナとして`Series<Degree,Coef>`を用いることができる。

非負整数 $n$ に対して`SparseFPS::Series<Degree,Coef> f(n)`は次が満たされている必要がある。

- `Degree`は通常の符号付き、符号なし整数型を想定し、`bool`や`char`などは対象外
- $i=0,1,\dots,n-1$ について、 `f[i]`のdegreeは非負
- 各`degree`は狭義単調増加に並んでいる必要がある

各`coef`が必ずしも非零である必要はない。ただし、「非零の係数の個数」が計算量に関わる解析では、本ライブラリの実装では `f.size()` に対応することになる。よって、`coef`に大量の $0$ があると計算量が壊れる場合がある。

## 更新履歴

- 2026/10/24: 作成
