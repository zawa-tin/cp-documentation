---
title: ABC436-G Linear Inequation
documentation_of: //Test/AtCoder/abc436_g.test.cpp
---

$A_{N + 1} = 1$ を追加することで、 $\sum_{i}A_ix_i = M$ を満たす $x$ を数えることに帰着する。 要は[貯金箱の焦り](https://yukicoder.me/problems/no/137)をすれば良い。

- 貯金箱の焦りdpとか、桁上がりを考慮する桁dpと言われていたり、自分で呼んでいたりするもの。

このdpのテクニックの肝は「$x$ を何個でも選べる」を「 $x, 2x, 4x, 8x, \dots$ をそれぞれコスト $1, 2, 4, 8, \dots, $ かかるとして高々 $1$ 個とる」という話に置き換えるところだと思っている。

実は、あまり賢いことをしなくても $[x^{M}]1/\prod_{i}(1-x^{A_{i}})$ なのでBostan-Moriをして終わり。
