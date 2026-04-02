---
title: Binary Trie
documentation_of: //Src/DataStructure/Trie/BinaryTrie.hpp
---

遅延伝搬はまだ実装していない。

### テンプレート引数

```cpp
template <usize Height>
```

Binary Trieの高さ。挿入・削除する整数が $0$ 以上 $2^{\text{Height}}$ 未満であることを保証しなければならない。

Heightは $1$ 以上 $64$ 以下である必要がある。

### コンストラクタ

```cpp
BinaryTrie() = default;
```

デフォルトコンストラクタのみ。

### insert

```cpp
void insert(u64 v,u64 k = 1)
```

$v$ を $k$ 個挿入する。

### count

```cpp
void count(u64 v) const
```

$v$ が存在する個数を返す。

### erase

```cpp
usize erase(u64 v,u64 k = 1)
```

$v$ を $k$ 個消そうとする。実際に消すことができた数を返す。

### empty

```cpp
bool empty() const
```

現在空か判定

### size

```cpp
usize size() const
```

現在何要素あるか


### setmin

```cpp
usize setmin(u64 mask) const
```

トライの中にある要素 $x$ 全体に渡る $x \oplus \text{mask}$ の最小値を返す。

### setmax

```cpp
usize setmin(u64 mask) const
```

トライの中にある要素 $x$ 全体に渡る $x \oplus \text{mask}$ の最大値を返す。

**未verify**

### operator[]

```cpp
const Node& operator[](usize i) const
```

トライ木の内部のノードを取得する。 $0$ のとき空であることを意味する。

根ノードは常に存在し、 $1$ を引数に与えるとアクセスすることができる。

```cpp
struct Node {
    usize cnt=0;
    usize ch[2]{0,0};
};
```

`cnt`がそのノードの部分木にある要素数、`ch`が子のノード番号を意味する。`ch`が $0$ ならば、子が存在しないことを示す。
