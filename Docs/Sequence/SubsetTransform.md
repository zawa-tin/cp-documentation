---
title: Subset Zeta/Mobius Transform ( $U$ の方へ集めるやつ )
documentation_of: //Src/Sequence/SubsetTransform.hpp
---

## 概要

$n$ 要素の集合に関するゼータ・メビウス変換で特に下位集合に関して集めてくるもの。

ここでのゼータ変換は $B_{S} = \sum_{T \subseteq S} A_{T}$ なる $B$ を計算し、メビウス変換はその逆変換。

自分は $\{ 0, 1, \dots, n - 1 \}$ の方向へ累積和を取るやつと覚えている。

## ライブラリの使い方

```cpp
void SubsetZetaTransform(usize n, std::vector<T>& a)
void SubsetMobiusTransform(usize n, std::vector<T>& a)
```

$n$ も指定する
