---
title: 要素追加・削除・mex計算
documentation_of: //Src/DataStructure/Other/MexManager.hpp
---

## 概要

**多重集合** $S$ に対して、要素の追加、削除、全体のmexの計算が高速に行えるデータ構造

$0$ 以上`numeric_limits<T>::max() - 1`以下の値を扱うことができる。実装の都合上`T`は符号付き整数である必要がある。

結構雑に書いたため遅いみたい。mexが要素数以下であることを利用した枝刈りとか入れたらもっと早くなると思う。
