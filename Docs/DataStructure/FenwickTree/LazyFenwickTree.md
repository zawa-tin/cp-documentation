---
title: Lazy Fenwick Tree
documentation_of: //Src/DataStructure/FenwickTree/LazyFenwickTree.hpp
---

## 概要

可換群 $G = (S,\oplus)$ の元の列 $A = (A_1,A_2,\dots,A_n), (A_i\in S)$ に対して以下の操作ができる。

1. 区間可算 $i = l,l+1,\dots,r-1$ に対して $A_{i}\leftarrow A_{i}\oplus x$ をする
2. 区間和取得 $A_{l}\oplus A_{l+1}\oplus \cdots \oplus A_{r-1}$ を計算する

## ライブラリの使い方

セグ木と同じインターフェースで`operation`、`product`、`get`、`assign`ができる。ただし`assign`は一点代入のみで区間代入はできない。

計算量は全て $O(\log n)$

テンプレートで与えるクラスに`static Element power(Element,usize)`が定義されていると定数倍が早くなる。オーダーレベルで計算量が改善している分けでは無いので、誤った`power`を書くくらいなら書かない方がいいかも。

## 更新履歴

- 2026/05/04: 作成
