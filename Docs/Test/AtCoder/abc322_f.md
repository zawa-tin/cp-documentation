---
title: ABC322-F Vacation Query
documentation_of: //Test/AtCoder/abc322_f.test.cpp
---

遅延セグ木に乗せる構造を以下の様に設計する

- 値が担当している区間における連続する0の長さの最大長
- 値が担当している区間における連続する1の長さの最大長
- 値が担当している区間における一番左に連続している値の種類とその長さ
- 値が担当している区間における一番右に連続している値の種類とその長さ
- 値が担当している区間で値の種類が全て同じか？

`product` (値のマージ) では、この意味に沿うようによしなに頑張る。

`operation`(値の更新)では、01列のflipなのでい つ も ので良い
