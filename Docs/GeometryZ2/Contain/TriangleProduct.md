---
title: 三角形に含まれる点重みの総積
documentation_of: //Src/GeometryZ2/Contain/TriangleProduct.hpp
---

## ライブラリの使い方

```
template <concepts::Group G>
```

テンプレートに群を指定知る必要がある。さらに、**可換**である必要がある。

```cpp
TriangleProduct() = default;
TriangleProduct(const PointCloud& A,const PointCloud& B,const std::vector<typename G::Element>& W);
TriangleProduct(const PointCloud& A,const std::vector<typename G::Element>& W) : TriangleProduct(A,A,W);
```

コンストラクタ $A$ から三点選んでその三角形に属している $B$ の点の重み $W_{i}$ の`G`による総積を計算する。

`B.size()==W.size()`が必要で、そうでないと`assert`にひっかかる

```cpp
T product(usize a,usize b,usize c) const
```

$A_{a},A_{b},A_{c}$の凸包に**真に内側に**含まれる$B$の点$B_{i}$の重み$W_{i}$の総積を計算する。

- `std::pair`が返ってきて、`first`は総積、`second`は点の個数

$a,b,c$はdistinctである必要はない。その場合は自明に空なので単位元が返ってくる。

```cpp
T onLine(usize i,usize j) const
```

$A_i,A_j$を端点とした線分に、端点を除いて含まれる$B$の点の総積を返す。返り値は`product`と同様

```cpp
T exact(usize i) const
```

$A_i$同じ位置にある$B$の点の総積を返す。

## 計算量

初期化に $\Theta(N^2M)$ 、クエリに $\Theta(1)$ 。ただし、`G::operation`が $O(1)$ であることを仮定している。
