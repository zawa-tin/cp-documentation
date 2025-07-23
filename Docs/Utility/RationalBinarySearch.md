---
title: 有理数で二分探索
documentation_of: //Src/Utility/RationalBinarySearch.hpp
---

## 概要

$N$ 以下の分母を持つ**非負の**有理数の集合上で二分探索を行い、 $f(\frac{a}{b})$ がTrueになる最大の $\frac{a}{b}$ と $f(\frac{a}{b})$ がFalseになる最小の $\frac{a}{b}$ を計算する。

$f$ は $f(\frac{0}{1}) = \text{T}, f(\frac{0}{1}(= \infty)) = \text{F}$ を満たす必要がある。
