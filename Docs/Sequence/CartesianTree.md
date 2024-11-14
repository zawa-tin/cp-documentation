---
title: Cartesian Tree
documentation_of: //Src/Sequence/CartesianTree.hpp
---

## 概要

数列に対して「最大値/最小値を境界に高々２つの区間に分ける」という操作の過程を木で表したものを構築する。

最大値・最小値で分ける分割統治と相性が良い。

## ライブラリの使い方

```cpp
template <class F>
requires std::strict_weak_order<F, T, T>
CartesianTree(const std::vector<T>& A, F comp)
```

`comp`は`T`に関する狭義の弱順序、$comp :T\times T\rightarrow \text{bool}$ である必要がある。
