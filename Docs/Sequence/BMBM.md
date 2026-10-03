---
title: BMBM
documentation_of: //Src/Sequence/BMBM.hpp
---

BMBMパンチ。計算量は入力の長さの二乗log

求めたいものが位数 $d$ の定数係数線形漸化式の $N$ 項目であるならば、BMBMの入力には長さ $2d$ 以上になる。

- 内部で使っている`FindLinearReccurences`が入力の長さの半分の列を返したからOK!...というわけではない。

例えば、答えが $n$ 次行列の $k$ 乗の成分ですよーってことがわかっているときは、長さ $2n$ 以上の列を入力に与える。
