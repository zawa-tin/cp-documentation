---
title: Bitwise XOR Convolution
documentation_of: //Src/Sequence/BitwiseXORConvolution.hpp
---

## 概要

### Bitwise XOR Convolution

```
template <class T>
std::vector<T> BitwiseXORConvolution(std::vector<T> A, std::vector<T> B) (1)

template <class T, class U>
requires (!std::same_as<T, U> and std::convertible_to<U, T>)
std::vector<T> BitwiseXORConvolution(std::vector<U> A, std::vector<U> B) (2)
```

長さ $2^N$ の(標数が $2$ でない)体上の列 $a,b$ に対して $c_{i}=\sum_{j\oplus k=i} a_{j}b_{k}$ を満たす列 $c$ を $O(N2^N)$ で計算する。

最終結果が型の範囲に収まっていても、計算途中でオーバフローする可能性が高い。**特に、`int`などの32bit整数の使用は推奨されない**

長さが $2^N$ でないときは、そのようなサイズになるまで後ろに $0$ 埋めがなされる。空列は空列のままかえす。

### XOR畳み込みの $K$ 乗

```
template <class T>
std::vector<T> BitwiseXORConvolutionPower(std::vector<T> A,usize K) (1)

template <class T,class U>
requires (!std::same_as<T, U> and std::convertible_to<U, T>)
std::vector<T> BitwiseXORConvolutionPower(std::vector<U> A,usize K)  (2)
```

$A$ をbitwise XOR 畳み込みで $K$ 乗する。なお $0$ 乗は(非空列のとき) $(1,0,0,0,\dots,0)$ と定義される。

こちらの計算量は $O((N+\log (K+1))2^N)$ 。

長さが $2^N$ でないときは、そのようなサイズになるまで後ろに $0$ 埋めがなされる。空列は空列のままかえす。

#### 高速Hadamard変換

```
// note: each values are multiplied by 2^{k/2} than truth value
template <class T>
void FastWalshHadamardTransform(std::vector<T>& A) 
```

XOR畳み込みは

1. $a,b$ をHadamard変換し、 $a',b'$ を得る。
2. $a',b'$ の各点積を取って $c'$ を得る。
3. $c'$ をHadamard変換して $c$ を得る。ただし実装上の都合で各点の値が $2^N$ 倍されている

という風に実装されている。

問題によってはこのHadamard変換を呼び出す回数を減らせたり、減らすことを要求してきたりする。例えば

- $K$ 乗する $\leftarrow$ $O(\log K)$ 回XOR畳み込みをするのではなく、$a'$ の各点を $K$ 乗して戻せば2回の変換で済む
- $a^0+a^1+ \cdots +a^K$ を求める( [ABC212-H](https://atcoder.jp/contests/abc212/tasks/abc212_h) ) $\leftarrow$ これも各点を等比数列の公式にしたがって変換すれば2回の変換で済む

といった例がある。

自分でそういったテクニックをする場合、`FastWalshHadamardTransform`を二回適用すると、各点の値が元の列の値の $2^N$ 倍になることに注意。変換 $\rightarrow$ 積を取る $\rightarrow$ 変換 の後は各点を $2^N$ で割る必要がある

## 参考

- [xor畳み込みと高速Hadamard変換](https://qiita.com/izu_nori/items/7810fc2bc0423c8d407f)
- [Fast Walsh Hadamard Transform (高速ウォルシュアダマール変換)](https://ei1333.github.io/library/math/fft/fast-walsh-hadamard-transform.hpp.html)

## 更新履歴

- 2025/06/02: 作成
- 2025/10/17: 日本語のコメントを英語にした
- 2026/10/22: verifyを増やした、 $K$ 乗専用の機能を作った、ドキュメントの刷新
