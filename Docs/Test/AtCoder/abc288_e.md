---
title: ABC288-E Wish List
documentation_of: //Test/AtCoder/abc288_e.test.cpp
---

番号昇順に買うか買わないかを決定する。 $C_j$ の寄与は後ろの要素には全く影響されないので、そこからDPを考えることができる。

$\text{DP}_{i, j}$ $i$ 番目までの商品を考慮した、 $j$ 個の商品を既に購入している時の最小値

区間minの形になっているのでSparseTableで高速化できる。
