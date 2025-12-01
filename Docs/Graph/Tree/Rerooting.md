---
title: 木DP/全方位木DP
documentation_of: //Src/Graph/Tree/Rerooting.hpp
---

## 概要

流石に木DPは自分で書いた方が早いので、用途は主に全方位木dpになると思う。
- 全方位木DPも自分で書いた方がマシかもしれないけど

## テンプレートの雛形

```cpp
struct DP {
    using Tree = ;
    using Cluster = ;
    using Edge = ;
    using Vertex = ;
    static Tree Convert(Vertex) {
    }
    static Cluster AddEdge(Tree,Edge) {
    }
    static Cluster Merge(Cluster,Cluster) {
    }
    static Tree AddVertex(Cluster,Vertex) {
    }
};
```

![image](https://github.com/zawa-tin/cp-documentation/blob/main/Docs/Graph/Tree/Tree.jpg)

木dpでは

```cpp
    for (int x : g[v])
        if (x != p)
            chs.push_back(rec(rec, x));
    dp[v] = prod(chs);
```

みたいにやると思うんですけど、それとこの雛形がどう関係しているのかというと

- Vertex: dpの計算に関する頂点の情報
- Edge: dpの計算に関する辺が持つ情報
- Cluster: prod(chs)のこと。ここでは木の根はvirtualなものと考える
- Tree: prod(chs)に頂点vの情報をマージして、根をvirtualで無いようにしたもの

みたいな感じ。

任意の木dpで全部を毎回使うわけではなくて、例えば最遠点を求める場合はVertexはdpの計算に何もかかわってこない。こういうときは適当にゴミをいれておけばいいと思います。SOLID のI(だっけ?)違反なライブラリだけど、使う側が頑張る形でいきましょう

## ライブラリの使い方

```cpp
template <concepts::TreeDP T>
using TreeDPGraph = std::vector<std::vector<std::pair<usize, typename T::Edge>>>;

template <concepts::TreeDP T>
std::vector<typename T::Tree> TreeDP(const TreeDPGraph<T>& g, const std::vector<typename T::Vertex>& vs, usize root) {
```

上の雛形にあるエイリアスとメンバが全部そろっていると`cocepts::TreeDP`の要求は満たされる。

`g`はいつもの隣接リストで、firstに行先の頂点番号、secondにその辺の情報Edgeを納めます。必ず $u\rightarrow v, v\rightarrow u$ 両方入れること。

`vs`は頂点の情報の列
