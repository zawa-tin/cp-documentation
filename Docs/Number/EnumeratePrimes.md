---
title: Enumerate Primes
documentation_of: //Src/Number/EnumeratePrimes.hpp
---

## 概要

Wheel Sieveを実装しようとして、失敗してできた残骸。自分のエラトステネスの篩より $5$ 倍くらい早いので取り敢えず実戦には耐えそう。

## ライブラリの使い方

```cpp
template <std::integral T>
std::vector<T> EnumeratePrimes(usize N)
```

$N$ 以下の素数を`T`型のvectorに昇順に並べて返す。

## 参考

- [素数列挙: Wheel Sieve](https://37zigen.com/wheel-sieve/)
- メモリの削減及びlpfに注目した高速化が説明されているが、今の所読解に失敗しており、本ライブラリでは実装されていない。
