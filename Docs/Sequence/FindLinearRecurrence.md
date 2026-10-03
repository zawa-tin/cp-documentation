---
title: 線形漸化式を発見する(Berlekamp-Massey)
documentation_of: //Src/Sequence/FindLinearRecurrence.hpp
---

## 概要

長さ $N$ 数列 $A$ が与えられたときに、 最初の $N$ 項が $A$ に一致する定数係数線形漸化式であって、位数が最小のものを一つ求める。

計算量は $O(N^2)$

## 参考

- [https://info.atcoder.jp/entry/algorithm_lectures/linearly_recurrent_sequence_reconstruction](https://info.atcoder.jp/entry/algorithm_lectures/linearly_recurrent_sequence_reconstruction)

多分初めてかな。中身を理解せずにライブラリを書いてしまった。今まで数々の文献を読んで理解できなくて、今回AALでお膳立てされてさえも理解できなかったので、もうBerlekamp-Masseyを理解できる日は一生来ないのだろう。

- Euclidの互除法での理解はまだ読んでないので、そっちはワンチャンあるかも。まぁ別記事の互除法での解説は理解できなかったんだけど。
