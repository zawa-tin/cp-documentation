---
title: Static Top Tree + 木DP
documentation_of: //Src/Graph/Tree/DynamicTreeDP.hpp
---

## 雛形

```cpp
struct DP {
    using Vertex = ;
    using Edge = ;
    using PathCluster = ;
    using PointCluster = ;
    static PathCluster vertex(const Vertex&) {
    }
    static PathCluster addVertex(const PointCluster&, const Vertex&) {
    }
    static PointCluster addEdge(const PathCluster&, const Edge&) {
    }
    static PointCluster rake(const PointCluster, const PointCluster) {
    }
    static PathCluster compress(const PathCluster& p, const Edge& e, const PathCluster& c) {
    }
};
```

compressだけ引数の順番に注意。 $p$ が根に近いPath Cluster、 $c$ が根から離れたPath Cluster、 $e$ が間にあるHeavy Edgeに対応する。

```cpp
struct Printer {
    void operator()(int v, string type, int par, DP::PathCluster p) const {
    }
    void operator()(int v, string type, int par, DP::PointCluster p) const {
    }
};
```

この`operator()`を適切に定義し、`Printer`の実体を`visit`メンバに与えるとStatic Top Treeのすべてのノードを出力する。

ノード番号は1-indexであり、葉側にあるノードほど頂点番号が小さい。

なので、`DynamicTreeDP`を使わず`StaticTopTree`を用いてそのまま木dpなどを書くときは再帰をせずに $1$ から昇順にループを回せばよい。

- [Antichain](https://atcoder.jp/contests/abc269/tasks/abc269_h)などの子側のデータを保持しておく必要がない時にこのようなことをするかもしれない

## ライブラリの使い方

```cpp
DynamicTreeDP(const DynamicTreeDPGraph& g, usize root, std::vector<Vertex> vs, std::vector<Edge> es)
```

`DynamicTreeDPGraph`とは`vector<vector<pair<usize, usize>>>`である。いつもの隣接リストで、`first`には接続先、`second`には辺番号を収める。

子から親方向への辺が存在していれば良い。両方向に辺が張られていても問題なく動作する。

`root`は根の頂点番号

`vs`は各頂点に対応する情報

`es`は各辺に対応する情報

他のメンバは実装見ればわかると思います。
