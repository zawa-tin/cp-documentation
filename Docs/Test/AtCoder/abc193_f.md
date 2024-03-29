---
title: ABC193-F Zebraness
documentation_of: //Test/AtCoder/abc193_f.test.cpp
---

燃やす埋める。

$f: \\{ 0, 1 \\}^{n^{2}}\ \to\ \mathbb{Z}$

$f$ の定義域: 長さ $n^{2}$ の01列全体
- マス $(i, j)$ の色を列の要素に対応させる
- 例えば、 $(n = 5)$ 「マス $(2, 3)$ が黒色」を表現したいなら「列の $2\times 5 + 3 = 13$ 番目の要素を $1$ にする」など

$f$ の値域: 整数全体
- しまうま度を意味する
- 入力とは矛盾したグリッドの状態(に対応した列)を引数にとった時は、 $-\infty$ を返すこととする

このように $f$ を上手く表現することができるならば、 $f$ を最大化する問題に帰着することができる。
- よくある賞金・罰金の考え方に思いをはせると割と自然に表現できる
- `?`じゃないマスに矛盾した色を割り当てる状態ならば(`W`なのに黒を割り当てたとか...) $-\infty$ 、そうでなければ $+0$ 
- 隣合うマスに異なる色を割り当てたら $+1$

最小カットに帰着させたいので、全ての賞金・罰金を $-1$ 倍する。すると困ったことに劣モジュラでなくなる。困ります。

そこで、「隣合うマスに異なる色を割り当てたら $+1$ (現在は $-1$ 倍しているので $-1$ )」に注目する。グリッドグラフ上で $4$ 近傍で隣合う関係は二部グラフをなす。

マス $(i, j)$ の色を $(i + j)$ が偶数なら白黒の割り当てを反転する。-> 「隣合うマスに異なる色を割り当てたら $-1$ 」が「隣合うマスに同じ色を割り当てたら $-1$ 」になる

劣モジュラ性を持つようになりました。goodgoodgood

全体を $-1$ 倍しているので、`BurnBury`が返す値は最適解の $-1$ 倍であることに注意
