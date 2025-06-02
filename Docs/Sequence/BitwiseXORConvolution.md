---
title: Bitwise XOR Convolution
documentation_of: //Src/Sequence/BitwiseXORConvolution.hpp
---

## 概要

長さ $N = 2^{K}$ の数列 $a, b$ に対して $\displaystyle c_{i} = \sum_{p, q, p\oplus q = i} a_{p}\times b_{q}$ を $O(N\log N)$ で計算する。

内部でWalsh-Hadamard Transformというものを用いている。愚直なTransformは低速で、これを用いても畳み込みの計算量は $\Theta (N^{2})$ から改善しない。しかし、Transformの式をぐっと睨むことにより高速化に成功する(俗に高速アダマール変換と呼ばれる)。

計算結果の値が小さいと見積もることができても、計算途中でオーバーフローする場合があるので、返り値の型には注意すること(例: ABC396-G)

## 参考

- [xor畳み込みと高速Hadamard変換](https://qiita.com/izu_nori/items/7810fc2bc0423c8d407f)
- [Fast Walsh Hadamard Transform (高速ウォルシュアダマール変換)](https://ei1333.github.io/library/math/fft/fast-walsh-hadamard-transform.hpp.html)
