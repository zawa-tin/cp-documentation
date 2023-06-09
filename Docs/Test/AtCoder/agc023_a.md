---
title: AGC023-A Zero-Sum Ranges
documentation_of: //Test/AtCoder/agc023_a.test.cpp
---

「空でない連続する $A$ の部分列」を「非空な区間」と言い換える。 非空な区間 $[l, r)$ であって $\displaystyle \sum_{i = l}^{r - 1} A_i = 0$ を満たすものの数を数える問題となる。

これは、 $A$ の累積和 $S$ をとることで $S_{r} - S_{l} = 0$ となる区間の数を数える問題に言い換えることができる。式変形して $S_{r} = S_{l}$ と解釈する。

ここで、 $S_{i} = x$ を満たす $i$ の数が $k$ 個存在する時、 $S_{l} = x, S_{r} = x$ となるように $l, r$ を選択する通り数は $\binom{k}{2} = \frac{k \times (k - 1)}{2}$ である。

よって連想配列等を利用して $S_{i}$ を値の種類と数にまとめ上げることでこの問題を解くことができた。

<br />

この問題を部分問題に含む問題が現在まで沢山出題されているので、解法を残した。
