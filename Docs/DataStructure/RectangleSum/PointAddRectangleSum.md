---
title: Point Add Rectangle Sum
documentation_of: //Src/DataStructure/RectangleSum/PointAddRectangleSum.hpp
---

## 概要

以下のようなクエリを処理する

1. 二次元平面上に重み付きの点を追加する
2. 矩形領域が与えられる。矩形領域の中にある点の重みの総和を求める

ただし、オフライン処理である。すなわち全てのクエリは処理前に与えられている必要がある。

## ライブラリの使い方

```cpp
template <class T, class U>
requires concepts::RSOPCQuery
PointAddRectangleSum()
```

#### T

点の型

`T`は基本的には以下をコピれば問題無いはず。

- `P`が点の座標の型で、`W`が重みの型を表す

```cpp
struct Point {
    using P = int; 
    using W = long long;
    P x, y;
    W w;
};
```

`P`は**符号付き整数**であることが期待される。

P型のメンバ変数`x, y`とW型のメンバ変数`w`が必要。

## U

矩形領域型

基本的には以下をコピれば問題無い。`P`が座標の型を表す。

```cpp
// [l, r)x[d, u)
struct Rect {
    using P = int;
    int l, d, r, u;
};
```

`P`は座標の型、psの`P`と型が一致している必要がある。

メンバ変数`l`, `d`, `r`, `u`が必要。左下の点が $(l, d)$ 、右上の点が $(r, u)$ となるようにする。

## アルゴリズム

クエリ分割統治する。 $l$ 番目から $r - 1$ 番目のクエリを処理することを考える。 $m = \lfloor \frac{l+r}{2}\rfloor$ とする。

分割統治を考えているわけだから、結局の所 $m$ 番目から $r - 1$ 番目のクエリに含まれる求値に対する $l$ 番目から $m - 1$ 番目のクエリに含まれる点の寄与を計算できれば良い。

これは[Static Point Add Rectangle Sum](https://zawa-tin.github.io/cp-documentation/Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp)そのものである。

Static verはlog1つでできて、各クエリは高々 $\Theta (\log Q)$ 計算されるので、log2つ。

実装上は $r - l$ がある程度小さかったら再帰を打ち切って愚直を回している。この工夫でほんのちょっと早くなった。

アルゴリズム・実装共に [ei1333の日記](https://ei1333.hateblo.jp/entry/2022/06/10/022355) を参考にした。
