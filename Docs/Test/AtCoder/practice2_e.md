---
title: AtCoder Library Practice Contest - E MinCostFlow
documentation_of: //Test/Manual/practice2_e.test.cpp
---

知らなかったテクがあった。

最小費用流に帰着するが、最小費用最大流ではない( $NK$ 流すのが最適とは限らない )

こういう時はsourceからsinkに向けて容量無限、コスト $0$ の辺を張ると良い。

今回は最大化問題を最小化問題に変換するために下駄を履かせているので、この辺にも下駄を履かせること
