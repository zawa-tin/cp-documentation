---
title: ABC185-E Adjacent GCD (約数・倍数関係の高速ゼータ・メビウス変換)
documentation_of: //Test/AtCoder/abc185_e.test.cpp
---

整数 $a, b$ に関して $a$ が $b$ の約数であることを $a\mid b$ と表記する。

## 約数関係のメビウス変換

$x_{i} = \sum_{j\mid i} y_{j}$ を満たす $x, y$ に対して、 $x$ から $y$ を $\Theta (N\log \log N)$ で得ることができる。

```cpp
for (int p = 1 ; p <= MAX ; p++) if (p is prime) {
    for (int k = MAX / p ; k >= 1 ; k--) x[p * k] -= x[k];
}
```

## 約数関係のゼータ変換

$x_{i} = \sum_{j\mid i} y_{j}$ を満たす $x, y$ に対して、 $y$ から $x$ を $\Theta (N\log \log N)$ で得ることができる。

```cpp
for (int p = 1 ; p <= MAX ; p++) if (p is prime) {
    for (int k = 1 ; p * k <= MAX ; k++) y[p * k] += y[k];
}
```

## 倍数関係のメビウス変換

$x_{i} = \sum_{i\mid j} y_{j}$ を満たす $x, y$ に対して、 $x$ から $y$ を $\Theta (N\log \log N)$ で得ることができる。

```cpp
for (int p = 1 ; p <= MAX ; p++) if (p is prime) {
    for (int k = 1 ; k * p <= MAX ; k++) x[k] -= x[p * k];
}
```

## 倍数関係のゼータ変換

$x_{i} = \sum_{i\mid j} y_{j}$ を満たす $x, y$ に対して、 $y$ から $x$ を $\Theta (N\log \log N)$ で得ることができる。

```cpp
for (int p = 1 ; p <= MAX ; p++) if (p is prime) {
    for (int k = 1 ; k * p <= MAX ; k++) y[k] += y[p * k];
}
```

## コンテスト中

どっちがどっちだが頭が壊れた -> $1$ の方に値が集まっているなら倍数関係、 $N$ の方に値が集まっているなら約数関係

包除原理とか考えると大体嵌る。多次元累積和をとっていると考えて向きを考えるとすっと変換の式が書けるはず。

ゼータ・メビウス変換をする上で、メビウス関数を陽に求める必要は無い。また、考察上でも変換するだけならメビウス関数は出てこない。

## 参考

- [ユーザー解説 ARC185-E](https://atcoder.jp/contests/arc185/editorial/11161)
