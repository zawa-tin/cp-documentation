---
title: ABC157-F Yakiniku Optimization Problem
documentation_of: //Test/AtCoder/abc157_f.test.cpp
---

二分探索を考える。 $t$ 秒で $K$ 枚の焼肉を焼くことができる領域には必ず(その $K$ 枚のうちの) $2$ 枚の焼肉が $t$ 秒ぴったりで焼けるような点が存在する。

そのような点は 中心が焼肉の位置、 半径が $\frac{t}{c}$ である円の交点である。

ある円が片方の円を内包する場合に注意 (焼肉の位置ぴったりに熱源を置いた場合も考慮すること)
