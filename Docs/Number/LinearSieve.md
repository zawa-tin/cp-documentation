---
title: Linear Sieve
documentation_of: //Src/Number/LinearSieve.hpp
---

## 概要

ある正整数 $n$ 以下の任意の正整数 $x$ について、適切な前計算の後

- 素数判定
- 素因数分解
- 約数列挙

を提供することができます。いずれも試し割りのアルゴリズムより高速です。

## ライブラリの使い方

#### コンストラクタ

```cpp
LinearSieve(u32 n)
```

$n$ を設定します。

**制約**: $n$ は正整数である

**計算量**: $O(n)$

<br />

#### size

```cpp
usize size() const noexcept
```

コンストラクタで設定した $n$ を返します。

<br />

#### isPrime

```cpp
bool isPrime(u32 x) const noexcept
```

$x$ が素数か判定します。

**制約**: $x$ は $n$ 以下の正整数である

**計算量**: $O(1)$

<br />

#### operator[]

```cpp
bool operator[](u32 x) const noexcept
```

$x$ が素数か判定します。

**制約**: $x$ は $n$ 以下の正整数である

**計算量**: $O(1)$

<br />

#### divisor

```cpp
std::vector<u32> divisor(u32 x) const
```

$x$ の約数を列挙する。**ソートされていないことに注意**

**制約**: $x$ は $n$ 以下の正整数である

**計算量**: $x$ の約数の個数に比例する

<br />

#### factorize

```cpp
std::vector<PrimeFactor> factorize(u32 x) const

$x$ を素因数分解したものを返す。

`PrimeFactor`とは以下のような構造のclassである。

```cpp
class PrimeFactor {
public:
    u32 factor(); // 素因数を返す O(1)
    u32 exponent(); // 指数を返す O(1)
};
```

**制約**: $x$ は $n$ 以下の正整数である

**計算量**: $O(\log x)$

<br />

## 参考

- [線形篩](https://37zigen.com/linear-sieve/)
