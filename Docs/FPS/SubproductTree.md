---
title: Subproduct Tree
documentation_of: //Src/FPS/SubproductTree.hpp
---

## 概要

$n$ 個の多項式 $f_0,f_1,\dots,f_{n-1}$ が与えられたとき、セグ木上に区間の総積を保持する。

## ライブラリの使い方

### クラステンプレート

```
template <concepts::IndexedFPS FPS, class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
class SubproductTree
```

`PolynomialProducts`や`KthTerm`などと同じ形式である。

### コンストラクタ

```
SubproductTree(std::vector<FPS> fs,Conv convolution = {})
```

`fs` が多項式の列 $f$ に対応する。典型的には `FPS` は `FPSNTTFriendly<MOD>` が選ばれるが、このときは`convolution`には何も指定しなくてよい。

効率的な`convolution`の実装が無い場合は`NaiveConvolution`を与えると良い。

**内部で`fs`のサイズが $2$ 冪になるように多項式 $1$ を末尾に挿入した後**、セグ木上にSubproduct Treeを構築する。

### メンバ

```cpp
const FPS& root() const noexcept

const FPS& operator[](usize i) const noexcept

const FPS& leaf(usize i) const noexcept

inline usize size() const noexcept

inline usize innerSize() const noexcept
```

`root()`は $\prod_{i} f_{i}$ を返す。

`operator[](i)`は セグ木の $i$ 番目の添え字に対応するノードを返す。`LazySegmentTree`と同じ添え字管理になっており、特に1-indexedである点には注意が必要かもしれない。

`leaf(i)` は $f_{i}$ を返す。

`size()` は元々の $f$ の要素数であり、 `innerSize()`はセグ木の葉の数である。つまり、セグ木のノード数は合計して `2*innerSize()-1` である。

## 計算量

`convolution`が $O(n)$ 回実行される。

基本的に`PolynomialProducts`と同様の計算量となる。次のような典型的な状況では $O(n\log^2 n)$ となる。

- `convolution`に`atcoder::convolution`を利用する。`FPS`の型が`FPSNTTFriendly<MOD>`である
- $f$ の全ての次数が $1$ である。より典型的には $x-a_i$ という形をしている

## 更新履歴

- 2026/10/26: 作成
