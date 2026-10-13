---
title: セグ木コン O - 最小値 (履歴和のテクニック)
documentation_of: //Test/AtCoder/aalc001_o.test.cpp
---

履歴和(Historic Sum)のテクニック自体はこの問題の[公式解説](https://atcoder.jp/contests/aalc001/editorial/27089)が詳しい。

自分のライブラリで実装する場合、ちょっと工夫が必要。`LazySegmentTree`は既存の作用素 $L$ と新しい作用素 $R$ を`operation(L,R)`で合成する。通常の行列積を用いると合成結果は $LR$ になるが、列ベクトルに $L,R$ の順で作用させるために必要な行列は $RL$ である。

よって`ReverseOrder`で行列積の順序を逆転させる必要がある。
