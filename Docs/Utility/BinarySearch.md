---
title: 二分探索
documentation_of: //Src/Utility/BinarySearch.hpp
---

## 概要

整数や実数を一つ引数にとり、真理値を返り値とする関数 $f$ を考えます。 $f$ に以下の性質の一方を満たすと仮定します。
- ある値 $m$ が存在して、 $m$ 以下の値 $x$ では $f(x) = \text{true}$ 、 $m$ より大きい値 $x$ では $f(x) = \text{false}$
- ある値 $m$ が存在して、 $m$ 未満の値 $x$ では $f(x) = \text{false}$ 、 $m$ 以上の値 $x$ では $f(x) = \text{true}$

このような場合で、 $m$ を発見して返します。

#### ライブラリの使い方

```cpp
(1) 
template<class T, class Function>
T BinarySearch(T ok, T ng, const Function& f)

(2)
template<class T, class Function>
T BinarySearch(T ok, T ng, const Functioni& f, u32 upperLimit)
```

#### テンプレート引数

`T`

- `f`の引数の型です。

**制約**:

(1) 符号付き**整数**型であること

(2) 符号付き算術型であること
- (2) は浮動小数点数型等も許される。

`Function`

- `f`の型です。

**制約**: 

- `T`型の値を一つ引数にとり、`bool`値を返り値とする関数オブジェクトであること
- 副作用が無いこと(特にエラーを吐きませんが、 $m$ を正しく発見できる保証が無いです)

<br />

#### 引数

`ok`

**制約**: `f(ok) = true`を満たすこと

`ng`

**制約**: `f(ng) = false`を満たすこと

`f`

**制約**: 概要の条件を満たすこと

`upperLimit`

探索回数の上限を設定します。

<br />

#### 返り値

$m$ を返します。

<br />

#### 計算量の見積もり

(1) `f`を $\mid \text{ok} - \text{ng}\mid$ 回呼び出します。

(2) `f`を`upperLimit`回呼び出します。

<br />

#### アルゴリズム

名前の通り、二分探索しています。

所謂、めぐる式二分探索を採用しています。
- [https://twitter.com/meguru_comp/status/697008509376835584]
