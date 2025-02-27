---
title: ABC332-F Random Update Query (a <- ap + qの処理)
documentation_of: //Test/AtCoder/abc332_f.test.cpp
---

簡単な考察を踏むと、以下の様な処理ができれば良いことがわかる。

- 長さ $N$ のmintの列 $A$ がある
- $M$ 個のクエリが与えられる
- 各クエリでは、mint $p, q$ が与えられるので、 $A_{i} (l\le i\lt r)$ について $A_{i} \leftarrow A_{i}\times p+q$ せよ

双対セグ木にAffineMonoidを載せると、これが楽に処理できる。

- $i$ 番目の要素を $0x + A_{i}$ で初期化する
- 区間に $px + q$ をoperationする
- 答えは定数項に入っている。はじめ $0x + A_{i}$ で初期化しているため、一次の係数は $0$ になっている。
