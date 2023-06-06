---
title: ABC172-C Tsundoku
documentation_of: //Test/AtCoder/abc172_c.test.cpp
---

読んだ本の集合が等しいなら本を読んだ合計時間は等しい -> 本を読む順番は考慮しなくて良い。

ここで、 机Aから読む本の冊数を $a$ 冊に固定したとする。机Aから $a$ 冊の本を読むのにかかる時間は $\displaystyle S_{a} = \sum_{i = 1}^{a} A_i$ 分であり、残りの $K - S_{a}$ 分で机Bから何冊よむことができるかを高速に判定できれば良い。

これは $B$ の累積和上で二分探索すれば良い。
