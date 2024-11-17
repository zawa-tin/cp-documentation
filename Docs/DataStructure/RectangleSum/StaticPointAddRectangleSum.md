---
title: Static Point Add Rectangle Sum
documentation_of: //Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp
---

## 概要

以下のようなクエリを処理する

始めに $N$ 個の重み付きの点が与えられる。その次に $Q$ 個の矩形領域が与えられる。各矩形領域の中にある点の重みの総和を求めよ。

## ライブラリの使い方

```cpp
template <class T, class U>
std::vector<typename T::W> StaticPointAddRectangleSum(std::vector<T> ps, std::vector<U> qs) {
```

#### ps

重み付きの点の`std::vector`

`T`は基本的には以下をコピれば問題無いはず。

```cpp
struct Point {
    using P = int; // 座標の型、int, long long 
    using W = long long; // 重みの型、int, long long, mint
    P x, y;
    W w;
};
```

`P`は**符号付き整数**であることが期待される。

P型のメンバ変数`x, y`とW型のメンバ変数`w`が必要。

## qs

矩形領域の`std::vector`

基本的には以下をコピれば問題無い

```cpp
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
