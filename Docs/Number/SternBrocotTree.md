---
title: Stern-Brocot Tree
documentation_of: //Src/Number/SternBrocotTree.hpp
---

## 概要

有理数の問題では、この構造を考えると、嬉しいことがあります！

## ライブラリの使い方

他のライブラリとは異なり、`SternBrocotTree`という名前空間の下で型エイリアスや関数を提供している。

### Node

```cpp
template <sbt_internal::Integer T>
using Node = std::pair<T, T>;
```

有理数を表す。`T`は`std::integral`または128bit整数である必要がある。

### Path

```cpp
enum Direction {
    Left,
    Right
};

template <sbt_internal::Integer T>
using Path = std::vector<std::pair<Direction, T>>;
```

Stern-Brocot Tree(SBT)の根からのパスを表す。SBTは二分木であり左子に進むことを`Left`、右子に進むことを`Right`で表す。

パスは非常に長くなることがあるため、連長圧縮して表現されている。

- 既約分数 $\frac{a}{b}$ のパスを連長圧縮するとその長さは $O(\log\max\\{a, b\\})$ になることが知られている。

### Encode

```
template <sbt_internal::Integer T>
Path<T> Encode(Node<T> node)
```

`node` に対応するパスを返す。

**計算量**: $O(\log \max\\{ a, b \\})$

### Decode

```
template <sbt_internal::Integer T>
Node<T> Decode(const Path<T>& path)
```

`path`に対応する`Node`を返す。

**計算量**: `path`の要素数を $n$ として $O(n)$

### LCA

```
template <sbt_internal::Integer T>
Node<T> LCA(Node<T> p, Node<T> q)
```

`p, q`に対応するLCAの`Node`を返す。 $p\le \frac{a}{b} \le q$ を満たす $\frac{a}{b}$ であって $b$ が最小であるものを見つけることに対応している。

**計算量**: `Encode`を2回、`Decode`を1回呼び出すことがボトルネック

### Ancestor

```
template <sbt_internal::Integer T>
std::optional<Node<T>> Ancestor(u64 dep, Node<T> n)
```

`n`に対応するパス上の深さ`dep`の頂点を返す。根の深さを $0$ としている。

**計算量**: `Encode, Decode`をそれぞれ1回呼び出すことがボトルネック

### Range

```
template <sbt_internal::Integer T>
std::pair<Node<T>, Node<T>> Range(Node<T> n)
```

`n`の部分木の有理数は有理数の開区間を成す。この両端を返す。

**計算量**: `Decode`を一回呼び出す
