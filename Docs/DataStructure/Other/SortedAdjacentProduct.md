---
title: ソート列の隣接二項間の積を管理する
documentation_of: //Src/DataStructure/Other/SortedAdjacentProduct.hpp
---

## 概要

多重集合$S$がある。はじめ$S$は空である。$S$に対して以下のクエリを処理できる。

- $S$に要素$x$を挿入する。
- $S$中の$x$を一つ削除する。$x\in S$が必要である。
- $S$の各要素を昇順に並べた列を$A = (A_1, A_2, \dots, A_K)$とする。$f(A_{1}, A_{2}), f(A_{2}, A_{3}), \dots, f(A_{K - 1}, A_{K})$を管理する。

現状$f$としてxorを使う場合がプロコンで出題されている。
- $\min A_{i} \oplus A_{i + 1} = \min_{u\in S, v\in S} u\oplus v$が成り立つから
