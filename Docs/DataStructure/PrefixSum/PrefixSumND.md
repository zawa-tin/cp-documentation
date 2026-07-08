---
title: $N$ 次元累積和
documentation_of: //Src/DataStructure/PrefixSum/PrefixSumND.hpp
---

## 概要

このライブラリ本当にいるのか？

6次元累積和の問題に6次元Fenwick Treeをやってしまう(2敗)のを防ぐことができるかも。

$N$ が動的のときは、最大次数をテンプレートに与えて、参照しない軸の大きさを $1$ にする。

計算量は、構築に $O(N\prod H_{i})$ 、クエリに $O(2^N)$

- クエリの計算量dfsで頑張ることで、 $N$ を一個落とした。
