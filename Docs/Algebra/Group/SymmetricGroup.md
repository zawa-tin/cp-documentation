---
title: 対称群
documentation_of: //Src/Algebra/Group/SymmetricGroup.hpp
---

## 概要

順列に関するUtilityライブラリです。

`concepts::Group`の要件を満たすように設計されています。しかし、内部で逆順列も一緒に管理しているため、データ構造に載せると若干オーバーヘッドがきついです。

## ライブラリの使い方

### テンプレート引数

```cpp
template <usize N = std::dynamic_extent,std::integral T = usize>
class SymmetricGroup
```

要素数が固定(コンパイル時定数にできる)ときは`N`にその定数を指定する。

そうでないときは`std::dynamic_extent`を指定する。

`T`は(要素数を $n$ として) $0$ 以上 $n$ 未満の整数を表現できる型ならなんでも良いが、基本デフォルトの`usize`で良いハズ。

典型的な運用では以下のどちらかでクラスを指定すれば十分です

```cpp
zawa::SymmetricGroup<3> sym;// (要素数のみを指定する)
zawa::SymmetricGroup sym(n);//(n要素で初期化)
```

以降実際の要素数を $n$ とします。

### コンストラクタ

```cpp
constexpr SymmetricGroup() requires (N!=std::dynamic_extent) (1)
explicit SymmetricGroup(usize n) requires (N==std::dynamic_extent) (2)
explicit SymmetricGroup(std::array<T,N> p) requires (N!=std::dynamic_extent) (3)
explicit SymmetricGroup(std::vector<T> p) requires (N==std::dynamic_extent) (4)
```

(1),(2)どちらも恒等置換で初期化します。特に、(2)ではテンプレート引数で指定しなかった要素数をコンストラクタに与えます。

(3),(4)は順列 $p$ からクラスを作成します。 $p$ が順列でないときの動作は保証しません。

### メンバ

```cpp
inline constexpr usize size() const noexcept
inline usize operator[](usize i) const noexcept
inline T position(usize i) const noexcept
void swap(usize i,usize j)
void composite(const SymmetricGroup& sym) 
void invert()
```

- `size()`は要素数を取得する。 $O(1)$
- `operator[](i)`は順列の $i$ 番目の要素を取得する。 $O(1)$
- `position(i)`は逆順列の $i$ 番目の要素を取得する。 $O(1)$
- `swap(i,j)`は現在の順列の位置 $i,j$ をswapする。 $O(1)$
- `composite(sym)`は現在の順列を `sym` でpermuteする。 $O(n)$
- `invert()`は逆順列に取り換える。 
    - `N`が`std::dynamic_extent`のとき、 $O(1)$
    - そうでないとき、 $O(n)$

### Groupに関するstaticメンバ

```cpp
static SymmetricGroup identity()
static SymmetricGroup operation(SymmetricGroup l,const SymmetricGroup& r)
static SymmetricGroup inverse(SymmetricGroup sym)
```

他の`Group`と同じような意味で設計されている。特に、データ構造ライブラリに載せるときに使うので、これらを使用するときは`N`が`std::dynamic_extent`でないことが想定されている。

- `identity()`は恒等置換を返す
- `operation(l,r)`は $l\rightarrow r$ の順で置換を施して得られる順列を返す。
- `inverse()`は逆順列を返す。

### action

```
template <class U,usize M>
static std::array<U,M> action(const SymmetricGroup& g,const std::array<U,M>& a) requires (N == std::dynamic_extent or N <= M) 

template <class U>
static std::vector<U> action(const SymmetricGroup& g,const std::vector<U>& a) 
```

列`a`を`g`でpermuteして返す。`a`の要素数 $M$ は`g`の要素数 $N$ 以上である必要があり、特に $M\gt N$ のときは、前 $N$ 要素をpermuteし、残りの $M-N$ 要素はそのままの順番で返す。

## 更新履歴

- 2026/11/02: 作成
