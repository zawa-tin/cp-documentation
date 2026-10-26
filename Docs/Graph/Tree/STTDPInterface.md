---
title: STT上のdpのインターフェース
documentation_of: //Src/Graph/Tree/STTDPInterface.hpp
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
    static PointCluster rake(const PointCluster&, const PointCluster&) {
    }
    static PathCluster compress(const PathCluster& p, const Edge& e, const PathCluster& c) {
    }
};
```

基本的に[ABC351-G 公式解説](https://atcoder.jp/contests/abc351/editorial/9868)の説明の通りに設計されている。

`compress`については、間の辺を陽に考慮するような設計に変更している。`Edge e`を挟んで祖先側の`PathCluster`が`p`、子孫側の`PathCluster`が`c`である。

## 更新履歴

- 2026/10/26: 作成(`DynamicTreeDP`から切り出した)
