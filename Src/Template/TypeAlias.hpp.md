---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/PrefixSum1D/PrefixSum1D.hpp
    title: "1\u6B21\u5143\u7D2F\u7A4D\u548C"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp
    title: "\u9759\u7684\u306A\u5217\u4E0A\u306E\u533A\u9593\u548C\u30AF\u30A8\u30EA"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Components/ConnectedComponents.hpp
    title: "\u7121\u5411\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: Src/Number/EratosthenesSieve.hpp
    title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/CompressedSequence.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  - icon: ':question:'
    path: Src/Sequence/RunLengthEncoding.hpp
    title: "\u9023\u9577\u5727\u7E2E"
  - icon: ':heavy_check_mark:'
    path: Src/Template/ArrayIO.hpp
    title: "std::array\u306E\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/PairIO.hpp
    title: "std::pair\u306E\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/VectorIO.hpp
    title: "std::vector\u306E\u5165\u51FA\u529B"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/ALDS1_11_D.test.cpp
    title: Test/AOJ/ALDS1_11_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/GRL_1_A.test.cpp
    title: Test/AOJ/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/ITP1_1_C.test.cpp
    title: Test/AOJ/ITP1_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/ITP1_2_C.test.cpp
    title: Test/AOJ/ITP1_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/ITP2_4_A.test.cpp
    title: Test/AOJ/ITP2_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc172_c.test.cpp
    title: ABC172-C Tsundoku
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc213_c.test.cpp
    title: Test/AtCoder/abc213_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc229_d.test.cpp
    title: ABC229-D Longest X
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc247_d.test.cpp
    title: Test/AtCoder/abc247_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc288_c.test.cpp
    title: Test/AtCoder/abc288_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc292_d.test.cpp
    title: Test/AtCoder/abc292_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc293_d.test.cpp
    title: Test/AtCoder/abc293_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc299_c.test.cpp
    title: Test/AtCoder/abc299_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/agc023_a.test.cpp
    title: AGC023-A Zero-Sum Ranges
  - icon: ':x:'
    path: Test/AtCoder/agc026_a.test.cpp
    title: Test/AtCoder/agc026_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/aplusb.test.cpp
    title: Test/LC/aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/enumerate_primes.test.cpp
    title: Test/LC/enumerate_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/static_range_sum.test.cpp
    title: Test/LC/static_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 2 "Src/Template/TypeAlias.hpp"


    #include <cstdint>

    #include <cstddef>


    namespace zawa {


    using i16 = std::int16_t;

    using i32 = std::int32_t;

    using i64 = std::int64_t;

    using i128 = __int128_t;


    using u8 = std::uint8_t;

    using u16 = std::uint16_t;

    using u32 = std::uint32_t;

    using u64 = std::uint64_t;


    using usize = std::size_t;


    } // namespace zawa

    '
  code: '#pragma once


    #include <cstdint>

    #include <cstddef>


    namespace zawa {


    using i16 = std::int16_t;

    using i32 = std::int32_t;

    using i64 = std::int64_t;

    using i128 = __int128_t;


    using u8 = std::uint8_t;

    using u16 = std::uint16_t;

    using u32 = std::uint32_t;

    using u64 = std::uint64_t;


    using usize = std::size_t;


    } // namespace zawa

    '
  dependsOn: []
  isVerificationFile: false
  path: Src/Template/TypeAlias.hpp
  requiredBy:
  - Src/Number/EratosthenesSieve.hpp
  - Src/DataStructure/PrefixSum1D/PrefixSum1D.hpp
  - Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp
  - Src/Sequence/RunLengthEncoding.hpp
  - Src/Sequence/CompressedSequence.hpp
  - Src/Graph/Components/ConnectedComponents.hpp
  - Src/Template/ArrayIO.hpp
  - Src/Template/VectorIO.hpp
  - Src/Template/PairIO.hpp
  timestamp: '2023-06-01 19:19:31+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Test/AtCoder/abc299_c.test.cpp
  - Test/AtCoder/agc026_a.test.cpp
  - Test/AtCoder/abc247_d.test.cpp
  - Test/AtCoder/abc213_c.test.cpp
  - Test/AtCoder/abc293_d.test.cpp
  - Test/AtCoder/abc172_c.test.cpp
  - Test/AtCoder/abc292_d.test.cpp
  - Test/AtCoder/agc023_a.test.cpp
  - Test/AtCoder/abc288_c.test.cpp
  - Test/AtCoder/abc229_d.test.cpp
  - Test/LC/enumerate_primes.test.cpp
  - Test/LC/static_range_sum.test.cpp
  - Test/LC/aplusb.test.cpp
  - Test/AOJ/ITP1_1_C.test.cpp
  - Test/AOJ/ITP2_4_A.test.cpp
  - Test/AOJ/GRL_1_A.test.cpp
  - Test/AOJ/ALDS1_11_D.test.cpp
  - Test/AOJ/ITP1_2_C.test.cpp
documentation_of: Src/Template/TypeAlias.hpp
layout: document
title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
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
