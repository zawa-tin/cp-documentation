---
title: 連長圧縮
documentation_of: //Src/Sequence/RunLengthEncoding.hpp
---

## 概要

長さ $N$ の列 $A$ を連長圧縮して、各要素を管理します。また、先頭と末尾に限り要素の追加、削除に対応しています。

与えられた列の連続した要素を (要素、連続している数) のペアの列で表現することを連長圧縮といいます。

例えば、 $A = (1, 1, 2, 3, 3, 3, 4, 1, 1)$ を連長圧縮した列は $((1, 2), (2, 1), (3, 3), (4, 1), (1, 2))$ です。

以後、入力の列を $A$ 、連長圧縮後の列を $B$ とします。

<br />

## 使い方

#### テンプレート引数

```cpp
template <class Value, class Number = u64>
```

$A$ の要素の型を`Value`に指定します。 「連続している数」の型を`Number`に指定します。`Number`はデフォルトで`zawa::u64 = std::uint64_t`が指定されています。

<br />

#### コンストラクタ

```cpp
(1) RunLengthEncoding() = default;
(2) RunLengthEncoding<InputIterator>(InputIterator first, InputIterator last)
(3) RunLengthEncoding(const std::vector<Value>& a)
```

(1) デフォルトコンストラクタ: 空列で $B$ を構築する

**計算量**: 定数時間

(2) イテレータ範囲コンストラクタ: `[first, last)`の範囲を要素として $B$ を構築する

- `std::string`等に対してはこのコンストラクタを使用してください

**計算量**: `first`から`last`の距離に対して線形時間

(3) `A`から $B$ を構築する

**計算量**: $O(\mid A \mid)$

<br />

#### size

```cpp
constexpr usize size() const noexcept
```

$\mid B\mid$ を返します。

**計算量**: 定数時間

<br />

#### sum

```cpp
constexpr u64 sum() const noexcept
```

$\mid A\mid$ を返します。

**計算量**: 定数時間

<br />

#### operator[]

```cpp
const Data& operator[](u32 i) const noexcept
```

$B_{i}$ を返します。 `Data`は以下のようなクラスです。

```cpp
class Data {
private:
    Value value_;
    Number number_;
public:
    const Value& value() const noexcept // 要素の値
    Number number() const noexcept // 連続している数
};
```

**制約**: $0\ \le\ i\ \le\ \mid B\mid$

**計算量**: 定数時間

<br />

#### value

```cpp
const Value& value(u32 i) const noexcept
```

$B_i$ の保管している要素を返します。

**制約**: $0\ \le\ i\ \le\ \mid B\mid$

**計算量**: 定数時間

<br />

#### number

```cpp
const Number number(u32 i) const noexcept {
```

$B_i$ の連続している数を返します。

**制約**: $0\ \le\ i\ \le\ \mid B\mid$

**計算量**: 定数時間

<br />

#### begin

```cpp
typename decltype(seq_)::const_iterator begin() const noexcept
```

$B$ の先頭要素の`const_iterator`を返します。(要素の変更を想定していないため、`const`でないイテレータは提供していません)

**計算量**: 定数時間

<br />

#### end

```cpp
typename decltype(seq_)::const_iterator end() const noexcept
```

$B$ の末尾の次の要素の`const_iterator`を返します。(要素の変更を想定していないため、`const`でないイテレータは提供していません)

**計算量**: 定数時間

<br />

#### pushBack

```cpp
void pushBack(const Value& value, const Number number = Number{1})
```

$A$ の末尾に`value`を`number`個挿入します。応じて $B$ も変更されます。

- `number`はデフォルトで $1$ になっています。

**計算量**: 定数時間

<br />

#### pushFront

```cpp
void pushFront(const Value& value, const Number number = Number{1}) {
```

$A$ の末尾に`value`を`number`個挿入します。応じて $B$ も変更されます。

- `number`はデフォルトで $1$ になっています。

**計算量**: 定数時間

<br />

#### popBack

```cpp
(1) void popBack()
(2) std::vector<Data> popBack(u64 number)
```

(1) $B$ の末尾要素を除去する。 $A$ も応じて変更される (先頭から末尾要素を連続している分除去する)

**制約**: $B$ が非空であること

**計算量**: 定数時間


(2) $A$ を末尾から`number`要素除去する。除去した要素を連長圧縮した`vector`を返す。

- $B$ も応じて変更される

**制約**: $\text{number}\ \le\ \mid A\mid$

**計算量**: $O(\mid B\mid)$

- `pushBack`や`pushFront`を呼ば出さない場合、`(2)popFront``(2)popBack`を呼び出した全体の計算時間の実行限界が $O(\mid B\mid)$ に抑えられます。

<br />

#### popFront

```cpp
(1) void popFront()
(2) std::vector<Data> popFront(u64 number)
```

(1) $B$ の先頭要素を除去する。 $A$ も応じて変更される (先頭から先頭要素を連続している分除去する)

**制約**: $B$ が非空であること

**計算量**: 定数時間


(2) $A$ を先頭から`number`要素除去する。除去した要素を連長圧縮した`vector`を返す。

- $B$ も応じて変更される

**制約**: $\text{number}\ \le\ \mid A\mid$

**計算量**: $O(\mid B\mid)$

- `pushBack`や`pushFront`を呼ば出さない場合、`(2)popFront``(2)popBack`を呼び出した全体の計算時間の実行限界が $O(\mid B\mid)$ に抑えられます。

<br />

## アルゴリズム

よしなにやっています。 $B$ を`std::deque`で持つことで`pushHoge popHoge`に対応しています。
