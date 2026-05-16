---
title: Range Aggregation
documentation_of: //Src/DataStructure/Wavelet/RangeAggregation.hpp
---

長さ数列 $A$ に対して Wavelet Matrixを構築する。このとき $l\le i\lt r, d\le A_{i}\lt u$ を満たす $i$ というのを互いに重ならない $O(\log N)$ 個の区間の和で表現できる。

$l,d,r,u$ に対してそのような区間の列を計算する

## ライブラリの使い方

```
RangeAggregation(std::vector<T> A)
```

`A`を構築する。このとき、行数`height()`、列数 $N$ (=`size()`)の行列を構築する。各区間は $i$ 行目の $l,r$ という形で表される

```
std::vector<std::pair<usize,usize>> point(usize i) const;
```

$l = i,r = i + 1,d = A_{i},u = A_{i}+1$  を表現する区間の列を返す。このとき各区間は点であるため、`pair<int,int>`で返される

- `first`が行番号
- `second`が列番号
- $O(\log N)$

```
std::vector<std::tuple<usize,usize,usize>> rectangle(usize l,T d,usize r,T u)
```

- `get<0>`が行番号
- `get<1>`が左端
- `get<2>`が右端
- $O(\log N)$

```
u32 count(usize l,T d,usize r,T u) const
```

`l,d,r,u`に含まれる個数。 $O(\log N)$

## 更新履歴

- 2026/05/16 作成
