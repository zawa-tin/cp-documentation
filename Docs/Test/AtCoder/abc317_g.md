---
title: ABC317-G Rearranging
documentation_of: //Test/Manual/abc317_g.test.cpp
---

左の列から順番に条件を満たすように配置を変えることを考える。

順列を構成することを「完全マッチングを一つ抜き去る」と言い換える。

$i$ 行目に要素 $j$ が残り何個あるか？を辺容量として二部マッチングを構成する。

計算量は全ての辺容量が1である $2n + 2$ 頂点 $O(nm)$ 辺の最大流問題を $m$ 回解くので $O(n^{\frac{3}{2}}m^2)$

Tips: [https://37zigen.com/noga-alon-edge-coloring-bipartite/](https://37zigen.com/noga-alon-edge-coloring-bipartite/) を使うともっと効率的に解ける。いつか盆栽に植えたいねぇ
