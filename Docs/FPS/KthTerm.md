---
title: 線形漸化式のK項目を計算する
documentation_of: //Src/FPS/KthTerm.hpp
---

## 概要

漸化式 $a_{n} = \sum_{i = 1}^{d} c_{i}a_{n - i}$ の $K$ 項目を計算する。

## ライブラリの使い方

```
template <class T, class F>
T KthTerm(u64 K, std::vector<T> A, std::vector<T> C, F mult)
```

**引数の順番注意！: K -> A -> C -> multです！**

#### T (template)

基本的にはmintを入れることになるだろう。

コピペ禁止コンテストなどでmintを使えない場合は、**中身のライブラリの演算をmodを取るように書き換える**必要がある。

#### K

求めたい項、非負整数。

#### A

漸化式の始め $d$ 項 $(A_{0}, A_{1}, \dots, A_{d - 1})$ 、 $A_{d}$ 以降が混じっていても問題ないが、反対に項数が足りないとassertにひっかかる。

#### C

線形漸化式の係数 $(C_{1}, C_{2}, \dots, C_{d})$

#### mult

多項式の掛け算を行い、結果を返す関数。

```cpp
[](const auto& L, const auto& R) {
    return atcoder::convolution(L, R);
}
```

```cpp
[](const auto& L, const auto& R) {
    if (L.empty() or R.empty()) return std::vector<mint>{};
    std::vector<mint> res(L.size() + R.size() - 1);
    for (size_t i{} ; i < L.size() ; i++) for (size_t j{} ; j < R.size() ; j++) {
        res[i + j] += L[i] * R[j];
    }
    return res;
}
```

基本的には以上のどちらかで事足りるハズ。

## 計算量解析

`mult`を $\Theta(\log K)$ 回呼び出すのがボトルネック

- `mult`で前者の例を使うと $\Theta (d\log d\log K)$ 
- `mult`で後者の例を使うと $\Theta (d^2 \log K)$

## 補足

内部で[Bostan-Moriアルゴリズム](https://q.c.titech.ac.jp/docs/progs/polynomial_division.html)が走っている。

線形漸化式の $K$ 番目を求めるアルゴリズムとして、

$$ \begin{pmatrix}
0, 1, 0, \cdots, 0 \\
0, 0, 1, \cdots, 0 \\
\vdots \\
0, 0, 0, \cdots, 1 \\
C_{d}, C_{d - 1}, C_{d - 2}, \cdots, C{1} \\
\end{pmatrix} $$

の $K$ 乗を計算する方法(行列累乗)が有名だが、これの時間計算量は $\Theta (d^3 \log K)$ と見積もれる。

このライブラリの`mult`に愚直を使ったやつよりも計算量が劣っていることに注意(貼れるときはちゃんと貼ろう)

勉強不足故、[定数倍の良い実装の方針](https://qiita.com/ryuhe1/items/c18ddbb834eed724a42b)をまだ採用していない。定数倍バトルになったらおとなしく別ライブラリを探そう...
