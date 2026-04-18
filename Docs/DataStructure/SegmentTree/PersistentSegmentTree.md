---
title: Persistent Segment Tree
documentation_of: //Src/DataStructure/SegmentTree/PersistentSegmentTree.hpp
---

## コンストラクタ

```cpp
explicit PersistentSegmentTree(std::vector<V> a)
explicit PersistentSegmentTree(usize n)
```

ここで構築されたセグ木のバージョンの番号は`0`

ここから新しく変更がある度にバージョン番号が $+1$ ずつされて管理されていく。

$O(n\log n)$

## size

```
inline usize size() const
inline usize versionSize() const
```

`size()`でセグ木の要素数 $N$ を返す。

`versionSize()`で今まで作られたバージョンの数を返す。

$O(1)$

## セグ木の機能

```
V get(usize ver,usize i) const
V get(usize i) const
V product(usize ver,usize l,usize r) const
V product(usize l,usize r) const
usize assign(usize ver,usize i,V v)
usize assign(usize i,V v)
usize operation(usize ver,usize i,V v)
```

`ver`で取得、変更を行うバージョンを整数で指定する。`usize`が返り値であるメンバは全部その変更を行った後のセグ木に番号付けられたバージョンを返している。

全部 $O(\log n)$

## 永続セグ木特有の機能

```cpp
Node* access(usize ver) const
usize construct(std::vector<V> a)
usize copy(usize from,usize to,usize l,usize r)
```

`access`はバージョン番号が`ver`であるセグ木の根を返す。 $O(1)$

`construct`は長さが`size()`に**一致する**列`a`からセグ木を作って新しいバージョンに保管する。 $O(n\log n)$

`copy`はバージョン`from`のセグ木区間 $l,r$ を`to`の $l,r$ にコピーしてできるセグ木を作る。 $O(\log n)$
