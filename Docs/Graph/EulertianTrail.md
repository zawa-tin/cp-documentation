---
title: Eulerian Trail (オイラー路)
documentation_of: //Src/Graph/EulerianTrail.hpp
---

## 概要

オイラー路が存在するなら構築する。オイラー路とは全ての辺を丁度一回ずつ通るようなtrailを指す。

無向グラフ $(V, E)$ において以下の条件を満たすとき、またそのときに限りオイラー路が存在する。

1. 次数 $0$ の頂点を削除したとき、連結である
2. 次数が奇数の頂点が丁度二つ、またはひとつも存在しない

特に条件2で後者を満たすとき、オイラー路の始点と終点が一致する。

有向グラフ $(V, E)$ において以下の条件を満たすとき、またそのときに限りオイラー路が存在する。

1. 次数 $0$ の頂点を削除したとき、連結である
2. 以下のいずれか片方を満たす(両方を同時に満たすことはありえない)

    - 入次数-出次数=1である頂点がちょうど一つ、-1である頂点がちょうど一つ、残りの頂点は0である
    - 全ての頂点について入次数と出次数が等しい

## ライブラリの使い方

```cpp
temlplate <class T>
std::optional<std::pair<std::vector<T>, std::vector<usize>>> EulerianTrail(usize n, const std::vector<std::pair<T, T>>& edges, bool directed)
```

`n`は頂点数、`edges`は辺の列、`directed`は有向グラフなら`true`、無向グラフなら`false`を入れる。

返り値が`std::nullopt`のとき、入力に対してオイラー路は存在しない。

`first`にはオイラー路の頂点列、`second`には辺番号の列が順に入っている。
