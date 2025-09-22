---
title: Superset Zeta/Mobius Transform ( $\emptyset$ の方へ集めるやつ )
documentation_of: //Src/Sequence/SupersetTransform.hpp
---

## 概要

$n$ 要素の集合に関するゼータ・メビウス変換で特に上位集合に関して集めてくるもの。

ここでのゼータ変換は $B_{S} = \sum_{S\subseteq T} A_{T}$ なる $B$ を計算し、メビウス変換はその逆変換。

自分は $\emptyset$ の方向へ累積和を取るやつと覚えている。

## ライブラリの使い方

```cpp
void SupersetZetaTransform(usize n, std::vector<T>& a)
void SupersetMobiusTransform(usize n, std::vector<T>& a)
```

$n$ も指定する
