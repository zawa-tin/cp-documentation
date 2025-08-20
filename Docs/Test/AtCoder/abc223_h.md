---
title: ABC223-H Xor Query
documentation_of: //Test/AtCoder/abc132_f.test.cpp
---

`DP[i][j] := 条件を満たすように正の整数を前から順番に $i$ 個並べた、 最後の要素が $j$ であるような通り数。

とする。 $\lfloor \frac{n}{v} \rfloor$ が同じ値になるような $v$ については、 `DP[i][v]`の値も等しくなることが観察等で得られれます。

よって商毎に`DP`の情報をまとめてしまえば良いです。
