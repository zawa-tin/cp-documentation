---
title: Rectangle Sum of PointCloud
documentation_of: //Src/DataStructure/RectangleSum/RectangleSumOfPointCloud.hpp
---

## 概要

二次元平面上の $N$ 点 (重み付き)と $Q$ 個の矩形領域が与えられるので、各矩形領域内に属する点の重みの総和を計算する

## ライブラリの使い方

```cpp
template <class T, class U>
requires concepts::RSOPCQuery
std::vector<typename T::W> RectangleSumOfPointCloud(std::vector<T> ps, std::vector<U> qs) {
```

#### ps

重み付きの点の`std::vector`

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

## qs

矩形領域の`std::vector`

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

矩形クエリ $(l, d, r, u)$ は $(-\infty, -\infty, l, d), (-\infty, -\infty, r, d), (-\infty, -\infty, l, u), (-\infty, -\infty, r, u)$ の4つの矩形クエリの足し引きに帰着できる。

一方の軸について平面走査をすることにすると、一点更新・prefix和取得に帰着し、Fenwick Treeで処理できる。

- Fenwick Treeにのせる方の座標は座圧する。

時間計算量 $\Theta (N\log N + Q(\log Q + \log N))$ 、空間計算量 $\Theta (N + Q)$ でできる。

アルゴリズム・実装共に [ei1333の日記](https://ei1333.hateblo.jp/entry/2022/06/10/022355) を参考にした。
