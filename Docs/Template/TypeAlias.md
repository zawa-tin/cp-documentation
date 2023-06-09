---
title: 標準データ型のエイリアス
documentation_of: //Src/Template/TypeAlias.hpp
---

## 概要

本ライブラリで使用する標準データ型のエイリアスを提供します。

<br />

```cpp
using i16 = std::int16_t;
```

16ビットの符号付き整数型。`short`の代わりにこちらを使用します。


```cpp
using i32 = std::int32_t;
```

32ビットの符号付き整数型。`int`の代わりにこちらを使用します。


```cpp
using i64 = std::int64_t;
```

64ビットの符号付き整数型。`long long`の代わりにこちらを使用します。

```cpp
using i128 = __int128_t;
```

128ビットの符号付き整数型。

```cpp
using u8 = std::uint8_t;
```

8ビットの符号無し整数型。`char`の代わりにこちらを使用します。
- `std::cout`してもちゃんと文字が出力されるっぽいです。

```cpp
using u16 = std::uint16_t;
```

16ビットの符号なし整数型。`unsigned short`の代わりにこちらを使用します。
- あまり出番が無いかもしれない

```cpp
using u32 = std::uint32_t;
```

32ビットの符号無し整数型。`unsigned int`の代わりにこちらを使用します。

```cpp
using u64 = std::uint64_t;
```

64ビットの符号無し整数型。`unsigned long long int`の代わりにこちらを使用します。


```cpp
using usize = std::size_t;
```

`std::vector::size()`等を値として利用する時に使用します。


## 参考

- [2016年、C言語はどう書くべきか (前編)](https://postd.cc/how-to-c-in-2016-1/)

- [long long型](https://cpprefjp.github.io/lang/cpp11/long_long_type.html)

> `long long`は64ビット以上の幅であることが保証されるが、64ビット固定の整数型が必要な場合には、`int64_t`型を使用することを推奨する。
