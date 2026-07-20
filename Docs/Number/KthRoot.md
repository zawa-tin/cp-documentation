---
title: $K$ 乗根を整数に切り捨て・切り上げ
documentation_of: //Src/Number/KthRoot.hpp
---

非負整数 $a,k$ に対して $\lfloor a^{\frac{1}{k}}\rfloor$ や $\lceil a^{\frac{1}{k}}\rceil$ を計算する。

- **ceilの方はverifyしていない**

制約: $a, k$ の型は**std::unsigned_integral**がtrueに派生する必要がある。 $k > 0$ が必要である。

標準関数で近い値を求めた後適当に足し引きするという実装方針を取っている(自分がいつもやっているやつ)

## 更新履歴

- 2026/07/20: 作成
