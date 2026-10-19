---
title: 木DP/全方位木DP
documentation_of: //Src/Graph/Tree/Rerooting.hpp
---

## 概要

全方位木dp。 [ABC351-G 公式解説](https://atcoder.jp/contests/abc351/editorial/9868) の内容を参考に抽象化されたもの。

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

![image](https://github.com/zawa-tin/cp-documentation/blob/main/Docs/Graph/Tree/Tree.jpg?raw=true)

上記の各staticメンバが木dpとどう対応しているのかというと...

```cpp
if (v is leaf)
    return Convert(v);
Cluster prod=Cluster::identity();
for (auto [x,e] : G[v])
    if (x != p)
        prod=Merge(prod,AddEdge(dp[x],e));
return AddVertex(prod,v);
```

といった塩梅である。なお、説明のために`Cluster::identity()`を用いたが、本ライブラリでは要求されない。

`DP`に対する詳細な要求は以下の通りである

- `Merge`は結合律を要求する。現在は辺のリストを順番に走査することで得られる隣接リストの前から順番にマージしていく設計となっている
- `Tree`及び`Cluster`にはデフォルト構築・コピー構築・コピー代入ができることが必要である。なお、デフォルト構築は単位元を返す必要はない。


## ライブラリの使い方

コンストラクタで全方位木DPが実行される。

```cpp
template <concepts::TreeDP DP,std::integral T>
Rerooting(usize n,std::vector<std::pair<T,T>> ed,std::vector<Vertex> vs,std::vector<Edge> es)
```

`DP`及び`T`は`Rerooting`のテンプレート引数である。

- `DP`は上記の雛形を適切に埋めたクラスであればよい。
- `T`は頂点番号の型。基本的に`int`、`unsigned`、`usize`のいずれかであることが推奨される。

$n$ は頂点数。 $n$ が $0$ のときはassertにひっかかる

`ed`は辺のリスト。頂点番号が $0,1,\dots,n-1$ であることを仮定している。辺数が $n-1$ でないときはassertにひっかかる。当然だが、`ed`は木の辺集合であることを要求する。

`vs`は頂点の情報を格納した要素数 $n$ の`vector`であり、`vs[v]`は頂点 $v$ の情報である必要がある。

`es`は辺の情報を格納した要素数 $n-1$ の`vector`であり、`es[i]` は`ed[i]`の情報である必要がある。

```
inline usize size() const noexcept
```

頂点数 $n$ を`usize`で返す。

```
const Tree& operator[](usize i) const noexcept
```

で頂点 $i$ を根としてfoldしたときの`Tree`を得ることができる。

```
const Tree& side(usize i,T v) const
```

で $i$ 番目の辺でぶったぎって得られる二つの木に関して、頂点 $v$ 側の木の $v$ を根としたfoldを`Tree`として返す。なお、 $i$ 番目の辺の端点の一方が $v$ である必要がある。そうでない場合はassertにひっかかる。

## 計算量

`DP`の各種演算、コピーが $O(1)$ であると仮定すると、構築 $O(n)$ 、取得 $O(1)$ 、空間 $O(n)$ メモリとなっている。

## 更新履歴

- 2025/12/01: 作成
- 2026/10/19: 木DPは使わないため削除。`Rerooting`をクラスにし、`side`メンバを追加した。
