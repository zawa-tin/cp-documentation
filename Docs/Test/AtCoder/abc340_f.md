---
title: ABC340-F S = 1
documentation_of: //Test/Manual/abc340_f.test.cpp
---

三点 $(a, b), (x, y), (p, q)$ からなる三角形の面積は $\frac{1}{2}\text{abs}((x - a)(q - b) - (y - b)(p - a))$ である。

とくに、三点 $(0, 0), (x, y), (p, q)$ からなる三角形の面積は $\frac{1}{2}\text{abs}(xq - yp)$ である。

本問題は一次不定方程式のかたちをしているため、拡張ユークリッドの互除法で解ける。
