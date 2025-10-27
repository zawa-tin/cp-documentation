---
title: Mod of Linear をsqrt(M)個の等差数列に分割する
documentation_of: //Src/Number/BinomalCoefficients.hpp
---

## 概要

長さ $N$ の数列 $f_i = (Ai + B) \mod M$ があったとき、これを $O(\sqrt{M})$ 個の連続するとは限らない $f$ の部分列であって、それぞれが等差数列であるものに分ける。

任意の部分列の添え字の列はある整数 $l, g, n'$ に対して $(l, l + g, l + 2g, \dots, l + (n'-1)g)$ となる。

このライブラリが動作するために結構厳しい条件が必要で、コード内のコメントを参照すること。
