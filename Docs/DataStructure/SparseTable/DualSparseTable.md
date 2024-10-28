---
title: Dual Sparse Table
documentation_of: //Src/DataStructure/SparseTable/DualSparseTable.hpp
---

区間更新が何回か来た後、取得クエリがあるようなやつに使える。当然だが、スパーステーブルなので等冪則が成り立つ演算でないと壊れる。

vectorで初期化、operation(l, r, v)で区間更新, buildで全要素取得。

初期化, buildが $O(n\log n)$ 、operationが $O(1)$
