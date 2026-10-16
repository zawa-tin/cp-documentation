---
title: Heavy Light Decomposition
documentation_of: //Src/Graph/Tree/HeavyLightDecomposition.hpp
---

## 概要

与えられた木上でHLD、オイラーツアーを行い、木の古典的な操作を大抵行えるように機能を提供する。

一方、重心、直径まわりの機能はオーバーヘッドを嫌って提供しないこととしている。

### テンプレート引数

```
template <std::integral V>
class HeavyLightDecomposition
```

`V`は`int`または`unsigned`であることが強く推奨される。例えば`V=std::uint8_t`であって頂点数 $N$ が $256$ の場合、`subtreeQuery`などがオーバーフローすることが確認できる。

### コンストラクタ

```
HeavyLightDecomposition(std::vector<std::vector<V>> T, V root = 0u)
```

`T`はグラフの隣接リストを指定する。`root`は根頂点に該当し、何も指定しなかった場合は頂点 $0$ が自動的に根となる。

- 隣接リストは**無向木**である必要がある

暗黙的に木の頂点数 $N$ は正であることが仮定されている。特に、空グラフは木ではないという木の定義に従っているため、この仮定は正当だと思われる。

### メンバ

```cpp
inline usize size() const noexcept
```

頂点数 $N$ を返す。 $O(1)$

```cpp
usize size(V v) const noexcept
```

部分木 $v$ の頂点数を返す。 $O(1)$

```cpp
usize depth(V v) const noexcept
```

$v$ の深さ。 $O(1)$

```cpp
V parent(V v) const noexcept
```

$v$ の親頂点を返す。 $v$ が根のときは`static_cast<V>(-1)`が返される。 $O(1)$

```cpp
V index(V v) const noexcept
V operator[](V v) const noexcept
```

$v$ がオイラーツアー上で何番目か？を返す。 $O(1)$

ただオイラーツアー上に並んでいるだけでなく、Heavy Pathの並び順にも対応している。具体的には任意のHeavy Path $v_1,v_2,\dots,v_k$ に対して、ある整数 $l(0\le l\le N-k)$ が存在して $\text{index}(v_i)=l+i-1$ となる。

```cpp
V top(V v) const noexcept
```

$v$ が属するHeavy Path上の頂点であって、最も深さが小さいものを返す。 $O(1)$

```cpp
V bottom(V v) const noexcept
```

$v$ が属するHeavy Path上の頂点であって、最も深さが大きいものを返す。 $O(1)$

```cpp
std::pair<V,V> heavyPath(V v) const
```

$v$ が属するHeavy Pathの両端点を返す。 $O(1)$

```cpp
std::vector<std::pair<V,V>> decomp(V s,V t) const
std::vector<std::pair<V,V>> operator()(V s,V t) const
```

$s-t$ パスをいくつかのHeavy Pathの区間に分割する。 $s$ に近い順から区間の両端点の頂点を返す。 $O(\log N)$

```cpp
std::vector<std::pair<V,V>> pathQuery(V s,V t) const
```

$s-t$ パスがオイラー上で対応する**閉区間**の集合を返す。`first>second`のときは逆向きのパスのaggregationが必要であることを指す。 $O(\log N)$

```cpp
std::pair<V,V> subtreeQuery(V v) const
```

$v$ のオイラーツアーによって対応された半開区間を返す。 $O(1)$

```cpp
V lca(V u,V v) const
```

$u,v$ のLCAを返す。 $O(\log N)$

```cpp
bool isAncestor(V v,V p) const
```

$p$ が $v$ の祖先に存在するなら`true`、そうでないなら`false`を返す。 $O(1)$

- Is $p$ an ancestor of $v$ ? という英文で引数の順番を覚えると良い

```cpp
std::optional<V> levelAncestor(V v,usize step) const
```

$v$ から $\text{step}$ 回親を辿ったときにいる頂点を返す。そのような頂点が存在しないときは `std::nullopt` が返される。 $O(\log N)$

```cpp
std::optional<V> jump(V s,V t,usize step) const
```

$s-t$ パスにおいて、 $s$ から $\text{step}$ 回辺を辿ったときにいる頂点を返す。そのような頂点が存在しないときは `std::nullopt` が返される。 $O(\log N)$

```cpp
usize distance(V s,V t) const
```

$s-t$ パスに含まれる辺の数を返す。 $O(\log N)$

## 更新履歴


- 2024/01/09: 初回実装。
- 2024/07/17: 実装を全面的に書き直した。`size(v)`、`depth`、`parent`、`index`、`decomp`、`isAncestor`、`levelAncestor`、`jump`、`distance`を整備し、ドキュメントを追加した。
- 2024/12/06: `Tree`への依存を廃止しテンプレート引数`V`による隣接リストをコンストラクタで受け取る形式に変更した。
- 2025/09/18: テンプレート引数を`std::integral`で制約した。`top`、`bottom`、`heavyPath`を追加した。
- 2026/01/01: `isAncestor`を`const`メンバ関数に変更した。
- 2026/02/23: `distance`が複数のHeavy Pathをまたぐ場合に辺数を正しく計算できない不具合を修正した。`levelAncestor`と`jump`の戻り値を`std::optional<V>`に変更した。
- 2026/03/27: パスに対応するオイラーツアー上の閉区間列を返す`pathQuery`を追加した。
- 2026/10/16: `subtreeQuery`を追加した。`isAncestor`を $O(1)$ に改善し、構築時に各部分木のオイラーツアー上の右端を記録するようにした。
