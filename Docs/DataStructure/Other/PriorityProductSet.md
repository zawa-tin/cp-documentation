---
title: 昇順 $K$ 個の和を取れるpriority_queue
documentation_of: //Src/DataStructure/Other/PriorityProductSet.hpp
---

## 概要

要素の挿入と昇順 $K$ 要素の和が取れるデータ構造。要素の削除は $K$ 番目からしか行えないことに注意。

- 群を載せることができる

## ライブラリ

```cpp
PriorityProductSet()
PriorityProductSet(usize K)
void insert(V&& v)
void insert(const V& v)
usize size() const
inline usize K() const
std::optional<V> product() const
std::optional<V> productRemain() const
V productAll() const
V popK()
```
