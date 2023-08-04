---
title: 標準出力
documentation_of: //Src/Template/Output.hpp
---

## 概要

標準出力を扱います。

## ライブラリの使い方

#### Cout

```cpp
(1) void Cout()
(2) void Cout(const T& value)
(3) void Cout(const Head& head, const Tail&... tail)
```

(1) `std::cout << std::endl`と等価です。

(2) `std::cout << value`と等価です。

(3) 引数に入れた変数を空白区切りで出力します。最後に改行が入りません。

<br />

#### Eout

```cpp
(1) void Eout()
(2) void Eout(const T& value)
(3) void Eout(const Head& head, const Tail&... tail)
```

(1) `std::cerr << std::endl`と等価です。

(2) `std::cerr << value`と等価です。

(3) 引数に入れた変数を空白区切りで標準エラー出力します。最後に改行が入りません。
