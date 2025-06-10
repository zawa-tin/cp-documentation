---
title: Block-Cut tree (+ 二重頂点連結成分分解)
documentation_of: //Src/Graph/Components/BlockCutTree.hpp
---

## 概要

[Block Cut Tree](https://en.wikipedia.org/wiki/Biconnected_component#Block-cut_tree)を構築します。

ここでも簡単に補足しておくと

- 二重頂点連結成分
- 関節点

を適切につないだ木のことをBlock-Cut Treeといいます。

二重頂点連結成分分解のライブラリを単体で持ってないので、これで代用してください。

## ライブラリ

### constructor

```cpp
BlockCutTree() = default;
explicit BlockCutTree(const std::vector<std::vector<T>>& g);
```

隣接リストを与える。`T`は`std::integral`を満たす必要がある。

### size

```cpp
inline usize size() const noexcept
```

BCTの頂点数を返します。

### operator[]

```cpp
const std::vector<T>& operator[](usize i) const {
```

BCTの頂点 $i$ の隣接リストを返します。

###  type

```cpp
enum class Type {
    BLOCK,
    CUT
};

Type type(usize i) const;
```

BCTの頂点 $i$ がBlockを表す頂点ならば`BlockCutTree<T>::Type::BLOCK`を、関節点を表すならば`BlockCutTree<T>::Type::CUT`を返します。

### blocks 

```cpp
const std::vector<std::vector<T>>& blocks() const;
```

二重頂点連結成分全部を返します。

### block

```cpp
const std::vector<T>& block(usize i) const;
```

BCTの頂点 $i$ に対応する二重頂点連結成分を返します。

### cuts

```cpp
const std::vector<T>& cuts() const;
```

関節点を全部返します。

### cut

```cpp
const T cut(usize i) const;
```

BCTの頂点 $i$ に対応する関節点を返します。

### vertices

```cpp
std::vector<T> vertices(usize i) const;
```

BCTの頂点 $i$ に対応する頂点の列を返します。**これはconst参照では無くコピーされます**

### isCut

```cpp
bool isCut(T v) const
```

**元のグラフで** $v$ が関節点だったかどうか判定します。

### cutId

```cpp
std::optional<usize> cutId(usize i) const;
```

**元のグラフの**頂点 $i$ が関節点だった場合、BCTの対応する頂点の番号を返します。そうでなければ`std::nullopt`を返します。

