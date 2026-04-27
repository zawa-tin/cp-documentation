---
title: Bridge tree (+ 二重辺連結成分分解)
documentation_of: //Src/Graph/Components/BridgeTree.hpp
---

## 概要

二辺連結成分をまとめて一頂点にし、グラフを縮約します。このグラフは木であり、各辺は元のグラフでは橋です。

```cpp
explicit BridgeTreeBuilder<T>(usize n);
```

で $n$ 頂点 $0$ 辺のグラフ (頂点のindexの型が`T`) を作って

```cpp
usize BridgeTreeBuilder<T>::addEdge(T u,T v)
```

で辺を追加して

```cpp
BridgeTreeBuilder<T>::BridgeTree BridgeTreeBuilder<T>::build()
```

でBridge Treeを返す

## 更新履歴

2026/04/20: 書き直した。

2026/04/27: クラス名を変更、`getEdge`を追加。CF1043-Fでverify
