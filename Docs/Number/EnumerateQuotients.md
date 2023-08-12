---
title: 商列挙
documentation_of: //Src/Number/EnumerateQuotients.hpp
---

## 概要

正整数 $n$ に対して、 $n$ の商 $\frac{n}{i} (1\ \le\ i\ \le\ n)$ の切り捨て/切り上げの値、それに対応する $i$ の区間を保持します。


## ライブラリの使い方

#### テンプレート引数

```cpp
template <class Value>
```

$n$ の型を指定します。

**制約**: `Value`は**符号無し整数型**である必要がある

<br />

#### コンストラクタ

```cpp
(1) constexpr EnumerateQuotients() = default
(2) constexpr EnumerateQuotients(Value n, bool floor = true)
```

(1) 特に使用することを想定していない。`std::vector<EnumerateQuotients>`とかやりたくなった時用？

(2) $n$ に対して商を列挙する。`floor`を`true`にした場合、商の切り捨てが、`false`にした場合は商の切り上げが保持される。
- 切り上げの方は競プロの問題でverifyしていない(募: verifyに使える問題)
- デフォルトでは`true`が設定されているため、何もしていされなければ`floor`の方で計算される

**計算量**: $O(\sqrt{n})$

<br />

#### n

```cpp
constexpr Value n() const noexcept
```

$n$ を返す。

**計算量**: 定数時間

<br />

#### operator[]

```cpp
constexpr Data operator[](u32 i) const noexcept
```
$i + 1$ 番目に大きい商の情報にアクセスする。

`Data`とは以下のようなクラスです。

```cpp
class Data {
private:
public:
    constexpr Value quotient() const noexcept // 商を返す
    constexpr Value l() const noexcept // (n / i) = quotient()となる最小のiを返す。
    constexpr Value r() const noexcept // (n / i) < quotient()となる最小のiを返す。
    constexpr std::pair<Value, Value> range() const noexcept // (l, r)をstd::pair型で返す。
    constexpr Value len() const noexcept // (n / i) = quotient()となるiの数を返す。(r() - l())と等価
}
```

**制約**: `i < size()` (`size()`は後述するメンバで、商の数)

**計算量**: 定数時間

<br />

#### quotient

```cpp
constexpr Value quotient(u32 i) const noexcept
```

$i + 1$ 番目に大きい商にアクセスする。

**制約**: `i < size()`

**計算量**: 定数時間

<br />

#### l

```cpp
constexpr Value l(u32 i) const noexcept
```

$i + 1$ 番目に大きい商 $x$ について、 $\frac{n}{i} = x$ となる最小の $i$ を返す。

**制約**: `i < size()`

**計算量**: 定数時間

<br />


#### r

```cpp
constexpr Value r(u32 i) const noexcept
```

$i + 1$ 番目に大きい商 $x$ について、 $\frac{n}{i} < x$ となる最小の $i$ を返す。

**制約**: `i < size()`

**計算量**: 定数時間

<br />

#### len

```cpp
constexpr Value len(u32 i) const noexcept
```

$i + 1$ 番目に大きい商 $x$ について、 $\frac{n}{i} = x$ となる $i$ の数を返す。

**制約**: `i < size()`

**計算量**: 定数時間

<br />

#### size

```cpp
constexpr usize size() const noexcept
```

商の数を返す。

**計算量**: 定数時間

<br />

#### begin

```cpp
constexpr typename decltype(seq_)::const_iterator begin() const noexcept
```

最大の商の情報を持つ`const_iterator`を返します。

**計算量**: 定数時間

<br />

#### end

```cpp
constexpr typename decltype(seq_)::const_iterator end() const noexcept
```

最小の商の情報を持つ情報の次の`const_iterator`を返します。

**計算量**: 定数時間

<br />

#### begin endの役割

```cpp
EnumerateQuotients eq(n);
for (const auto& e : eq) {

}
```

とすることで、商の大きい順に商を保持する`Data`にアクセスすることができます。

<br />

## アルゴリズム

一般に正整数 $n$ と $i = 1, 2, \dots, n - 1, n$ に対して、 $\lfloor \frac{n}{i}\rfloor$ の種類数は $O(\sqrt{n})$ 個に抑えられます。

なぜなら $\lfloor \frac{n}{i}\rfloor > \sqrt{n}$ を満たす $i$ は $\sqrt{n}$ 以下であり、かつ $\sqrt{n}$ 以上の $i$ について $\lfloor \frac{n}{i}\rfloor\ \le\ \sqrt{n}$ が成り立つからです。

なので、順にそれを取得しているだけです。

<br />

#### Appendix

- [https://nyaannyaan.github.io/library/multiplicative-function/prime-counting-faster.hpp](https://nyaannyaan.github.io/library/multiplicative-function/prime-counting-faster.hpp
)
- [https://twitter.com/yosupot/status/1624735126163980289](https://twitter.com/yosupot/status/1624735126163980289)

$N\ \le\ 10^{12}$ 程度なら、除算は`double`型で行った方が(十分な精度を持ちながらも)速いという話がある。(`zawa::EnumerateQuotients`では採用していない)
