---
title: 連続部分列の総和の最大を管理する
documentation_of: //Src/Algebra/Monoid/SubarraySumMaxMonoid.hpp
---

# 概要

**非空**な連続部分列であって総和が最大なものの総和を計算する

`std::optional`でデータを保持していて、空列に対応する値は`std::nullopt`である。

`SubarraySumMaxMonoid<T>::convert(T a)`というstaticメンバがあって、`T`型の値をこのモノイドの元に変換することができる。
