---
title: 1点更新付き木DP(根固定)
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
    static PointCluster rake(const PointCluster&, const PointCluster&) {
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

- `v`がSTT上での頂点番号、`par`が`v`の親頂点の番号、`type`が演算の種類である。

ノード番号は1-indexであり、葉側にあるノードほど頂点番号が小さい。

## ライブラリの使い方

```cpp
DynamicTreeDP(const DynamicTreeDPGraph& g, usize root, std::vector<Vertex> vs, std::vector<Edge> es)
```

`DynamicTreeDPGraph`とは`vector<vector<pair<usize, usize>>>`である。いつもの隣接リストで、`first`には接続先、`second`には辺番号を収める。

子から親方向への辺が存在していれば良い。両方向に辺が張られていても問題なく動作する。

`root`は根の頂点番号

`vs`は各頂点に対応する情報

`es`は各辺に対応する情報

他のメンバはメンバ名から意図が容易に分かるため、説明を省略する。

## 更新履歴

- 2025/12/02: 作成。子ノードへのアクセス方法と初期化処理を修正し、デバッグ出力を無効化した。
- 2025/12/03: visitを追加した。
- 2026/10/26: DPのインターフェースをSTTDPInterface.hppに切り出した。コンストラクタでグラフ・頂点情報・辺情報をメンバへmoveするように変更した。
