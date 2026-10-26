---
title: Static Top Tree上のDP
documentation_of: //Src/Graph/Tree/STTFold.hpp
---

## 雛形

```cpp
struct DP {
    using Vertex = ;
    using Edge = ;
    using PathCluster = ;
    using PointCluster = ;
    static PathCluster vertex(Vertex) {
    }
    static PathCluster addVertex(PointCluster,Vertex) {
    }
    static PointCluster addEdge(PathCluster,Edge) {
    }
    static PointCluster rake(PointCluster,PointCluster) {
    }
    static PathCluster compress(PathCluster p,Edge e,PathCluster c) {
    }
};
```

データは基本的に`std::move`を使って受け渡しを行っているため、const参照はつけなくても良い。

compressだけ引数の順番に注意。 $p$ が根に近いPath Cluster、 $c$ が根から離れたPath Cluster、 $e$ が間にあるHeavy Edgeに対応する。

## ライブラリの使い方

```
template <concepts::STTDPInterface DP>
typename DP::PathCluster STTFold(const STTGraph& g,usize root,std::vector<typename DP::Vertex> vs,std::vector<typename DP::Edge> es) 
```

`g`が隣接リストを表す`std::vector<std::vector<std::pair<usize,usize>>>`であり、型名は`STTGraph`というエイリアスが`StaticTopTree`から提供されている。

- `first`に頂点の行先、`second`に辺番号を収める

`root`は根頂点を指定する。

`vs,es`は`DP`の単一の頂点、辺の情報を収めた`vector`である。`vs[i]`が頂点 $i$ の情報、 `es[i]` が $i$ 番目の辺の情報である。

返り値は根付き木全体をfoldした`PathCluster`が返される。

## 更新履歴

- 2026/10/26: 作成

