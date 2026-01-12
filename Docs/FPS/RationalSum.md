---
title: 次数の総和が抑えられている有理式の総和
documentation_of: //Src/FPS/RationalSum.hpp
---

## 概要

## ライブラリの説明

```
template <concepts::IndexedFPS FPS, class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
std::pair<FPS, FPS> RationalSum(std::vector<FPS> num, std::vector<FPS> den, Conv conv = {})
```

`num.size() == den.size()`が必要である。`den`のある要素が $0$ であるとき、返り値は共に $0$ になると予想される(チェックはしていない)

`conv`は`FPSNTTFriendly`のときは何も指定しなくても良い。それ以外のときは畳み込みをする関数オブジェクトを与える。

$\Theta O(NM)$ の畳み込みは`FPS.hpp`の`NaiveConvolution`を与えると良い。

**計算量:** 次数の総和を $N$ として $O(N\log^2 N)$ (畳み込みが $O(n\log n)$ であることを前提)
