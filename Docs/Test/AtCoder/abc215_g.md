---
title: ABC215-G Colorful Candies 2
documentation_of: //Test/AtCoder/abc215_f.test.cpp
---

$C$ は座圧されているものとし、 種類 $i (1 \le i \le N)$ のキャンディの個数が $n_{i}$ であるとする。

**期待値の線型性**より、 $K$ 個のキャンディを選択したとき、少なくとも $1$ 個以上の種類 $i$ のキャンディを取る確率を $i = 1, 2, \dots, N$ について計算できれば良い。

余事象を考えると、 $K$ に対して解は $\frac{1}{\binom{N}{K}}\sum_{i = 1}^{N}(\binom{N}{K}-\binom{N-n_{i}}{K})$ である。

$=N-\frac{1}{\binom{N}{K}}\sum_{i=1}^{N}\binom{N-n_{i}}{K}$

結局の所 $\sum_{i=1}^{N}\binom{N-n_{i}}{K}$ が全ての $K$ で計算できれば良い。

$f(x) = \sum_{i = 0}^{N} \sum_{j = 1}^{N}\binom{N-n_{j}}{i}x^{i}$ とすると...

$= \sum_{j = 1}^{N} \sum_{i = 0}^{N} \binom{N-n_{j}}{i}x^{i} = \sum_{j = 1}^{N} (1+x)^{N-n_{j}}$ (二項定理)

よって $g(x) = \sum_{j = 1}^{N} x^{N-n_{j}}$ をPolynomial Taylor Shiftすることで $f(x)$ の係数列が $O(N\log N)$ で計算できて、元の解も求まった。
