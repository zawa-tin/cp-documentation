---
title: 文字列で受け取った小数を10倍しまくって整数にするやつ
documentation_of: //Src/Utility/FloatingMarkerShift.hpp
---

## 概要

文字列で受け取った小数を $10^t$ 倍して小数点を除去した整数にして返します。

引数は文字列 (`std::string`)である必要があります。


## ライブラリの使い方

```cpp
i64 FloatingMarkerShift(const std::string& S, u32 shift)
```

#### 引数

```cpp
const std::string& S
```
文字列として受け取った小数。

```cpp
u32 shift
```

小数点を右に何回ずらすかを指定する。`S`に対して`shift`回右に小数点をずらしても小数点以下が $0$ で無い場合はassertにひっかかって死ぬ
- 整数にして返すことを前提にしているので

<br />

#### 返り値

計算結果。符号付き`64`bit整数。

<br />

## 例

```cpp
FloatingMarkerShift("1.23", 3) // 1230
FloatingMarkerShift("-0.01", 2) // -1
```

<br />

## 必要になった経緯

[例えばこの問題](https://atcoder.jp/contests/abc191/tasks/abc191_d) 等で、浮動小数点型で入力を受け取ってそのまま $10$ 倍していって整数にした場合、誤差で死ぬ。
- ちょっと掛け算したくらいで...って感じてしまうが、浮動小数点型は $2$ 進数で値を保持していることを考えるとまぁ仕方ない話なのかもしれない。

逆に、 $2$ 進数で値を保持しているということは $2$ 倍や $2$ で割るのにはかなり強(いらし)く、 [例えばこの問題](https://atcoder.jp/contests/abc011/tasks/abc011_d) では許容誤差が $10^{-9}$ とかなり厳しいが小数点以下が絡む割り算が $4$ しか無いので愚直にやっても普通にACが出た。 
