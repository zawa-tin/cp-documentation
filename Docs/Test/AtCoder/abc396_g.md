---
title: ABC396-G Flip Row or Col
documentation_of: //Test/AtCoder/abc396_g.test.cpp
---

$A_{i}$ の $i$ 行目を二進表記の整数だと思うことにする。この整数を $a_{i}$ とする。

解は $\min_{i=0}^{2^W-1}\\{\sum_{j = 1}^{H} \min\\{\text{popcnt}(a_j \oplus i), W - \text{popcnt}(a_j\oplus i)\\}\\}$ であるため、これを頑張って早く求めたい。

$a_{j}$ の頻度列を取り $c$ とする。目的の式は $c$ を用いて $\min_{i=0}^{2^W-1}\\{\sum_{j = 0}^{2^{W}-1} c_{j}\times \min\\{\text{popcnt}(j \oplus i), W - \text{popcnt}(j\oplus i)\\}\\}$ と表せる。

xor畳み込みの形になっているので、OK
