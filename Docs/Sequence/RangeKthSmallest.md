---
title: Range Kth Smallest
documentation_of: //Src/Sequence/RangeKthSmallest.hpp
---

## 概要

長さ $N$ 静的な列に対して、「区間 $[l, r)$ の中で $k$ 番目に小さい値は？」という $Q$ 個のクエリをオフラインで計算する。

## ライブラリの説明

```cpp
template <class T, class U>
std::vector<T> RangeKthSmallest(const std::vector<T>& A, const std::vector<U>& Q)
```

#### A

**要件**

- 非空であること
- `operator<`が定義されていること
    - 当然だが、 $a\lt b$ であるとき、またそのときに限り`a<b`がtrueでないといけない

#### Q

**要件**

- `U`はpublicメンバ変数`l, r, k`が定義されているclass, structであること
- さらに、`l, r, k`は符号無し整数であることが期待される。符号あり整数だとWarningが発生する
- $l\lt r \le N$ かつ $k\lt r - l$
    - `l, r`は0-indexedの**非空な**半開区間
    - `k`は0-indexedで、 $r - l$ 以上の値は許されない

`U`は基本的には以下のstructをコピれば問題無い

```cpp
struct query {
    usize l, r, k;
};
```

#### アルゴリズム

一行で: 並列二分探索 + 平面走査

$A$ をソートして重複を消した列を $(B_{1}, B_{2}, \dots, B_{M})$ とする。本問題は「区間 $[l, r)$ の中に $B_{1}, B_{2}, \dots, B_{i}$ が合計 $k$ 個以上含まれているか？」という判定問題で二分探索すれば解ける。

区間 $[1, p)$ に含まれる $B_{1}, B_{2}, \dots, B_{i}$ の数の合計を $\text{pref}(p, i)$ とする。興味のある値は $-\text{pref}(l, i) + \text{pref}(r, i)$ である。

クエリを先読みして $l, r$ を集計し、平面走査を行うことで各クエリに対して判定問題を一回ずつ解くことができる。 $\text{pref}(p, i)$ の計算にセグメント木を用いるとlog2つでできる。

セグメント木上の二分探索に想いを馳せるとさらにlogを一個落とすことができる。本ライブラリでは時間計算量 $\Theta ((N + Q)\log N)$ 、空間計算量 $\Theta (N + Q)$ を達成している。
