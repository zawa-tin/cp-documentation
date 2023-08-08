---
title: 標準出力
documentation_of: //Src/Template/Output.hpp
---

## 概要

標準出力を扱います。

## ライブラリの使い方

#### out

```cpp
(1) void out()
(2) void out(const T& value)
(3) void out(const Head& head, const Tail&... tail)
```

(1) `std::cout << std::endl`と等価です。

(2) `std::cout << value << std::endl`と等価です。

(3) 引数に入れた変数を空白区切りで出力します。最後に改行が入ります。

<br />

#### eout

```cpp
(1) void eout()
(2) void eout(const T& value)
(3) void eout(const Head& head, const Tail&... tail)
```

(1) `std::cerr << std::endl`と等価です。

(2) `std::cerr << value << std::endl;`と等価です。

(3) 引数に入れた変数を空白区切りで標準エラー出力します。最後に改行はいります。
