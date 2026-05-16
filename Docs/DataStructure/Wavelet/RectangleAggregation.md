---
title: Rectangle Aggregation
documentation_of: //Src/DataStructure/Wavelet/RectangleAggregation.hpp
---

二次元平面の点の列 $P = ((x_0,y_0),(x_1,y_1),\dots,(x_{N-1},y_{N-1}))$ が与えられる。

各要素が $0$ 以上 $N$ 未満の行列であって次の条件を満たすものを構築する

- 行数は $O(\log N)$
- 列数は $O(N)$
- $l\le x_{i}\lt r,d\le y_{i}\lt u$ を満たす $i$ の集合を各行の連続部分列の和として表現することができる

このようなとき`l,d,r,u`に対して連続部分列を区間として表したものを返すことができるようにする。

## ライブラリの使い方

```cpp
RectangleAggregation(std::vector<std::pair<T,T>> p);
```

`p` で構築する。 $O(N\log N)$

```cpp
inline usize size() const;
inline usize width() const;
inline usize height() const;
```

- `size()`は $N$
- `width()`、`height()`は列数、行数
- $O(1)$

```cpp
std::vector<std::pair<usize,usize>> point(usize i) const;
```

行列において $i$ が書き込まれている (行番号,列番号)の列を返す

- $O(\log N)$

```
std::vector<std::tuple<usize,usize,usize>> rectangle(T l,T d,T r,T u) const;
```

`l,d,r,u`でやる。`{i行目,l,r}`

```cpp
u32 count(T l,T d,T r,T u) const
```

$l\le x_i\lt r,d\le y_i\lt u$ を満たす $i$ の個数を返す。 $O(\log N)$


## 更新履歴

- 2026/05/16 作成
