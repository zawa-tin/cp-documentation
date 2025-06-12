---
title: Bridge tree (+ 二重辺連結成分分解)
documentation_of: //Src/Graph/Components/BridgeTree.hpp
---

## 概要

二辺連結成分をまとめて一頂点にし、グラフを縮約します。このグラフは木であり、各辺は元のグラフでは橋です。

## ライブラリ

### constructor

```cpp
BridgeTree() = default;
explicit BridgeTree(const std::vector<std::vector<T>>& g)
```

無向グラフの隣接リストを与える。`T`は`std::integral<T>`が`true`である必要がある。

### size

```cpp
inline usize size() const noexcept
```

縮約後の頂点数を返す

### operator[]

```
const std::vector<V>& operator[](V v) const;
```

縮約後の頂点 $v$ の隣接する頂点の列を返す。ここで、`V = usize`である。

### component

```
const std::vector<T>& component(V v) const
```

縮約後の頂点 $v$ に対応している元のグラフの頂点の列を返す。

### components

```
const std::vector<std::vector<T>>& components() const
```

`component`の列である。すなわち二重辺連結成分分解した列を返す。

## メモ

内部で`unordered_map`を使って多重辺を処理しているので、ちょっとオーバヘッドがやばそう？

LCでは133msで普通に良さそうだったけど。
