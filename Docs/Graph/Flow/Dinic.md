---
title: Dinic (最大流・最小カット)
documentation_of: //Src/Graph/Flow/Dinic.hpp
---

## 概要

## ライブラリの使い方

#### テンプレート引数

```cpp
template <class Cap>
```

容量・流量の型を`Cap`で指定します。残余ネットワークを構築する都合上、`signed`な型のみを受け付けます。


#### コンストラクタ

```cpp
Dinic() = default; (1)
Dinic(usize n, usize m = usize{}) (2)
```

(1) 特に使用を想定していない

(2) 頂点数 $n$ の辺が存在しないネットワークを構築する

$m$ は想定される辺数を与えることで内部の`std::vector`が`std::vector::reserve`を呼び、ちょっと早くなるかもしれません(検証はしていません)。デフォルトで0が指定されています

計算量: $O(n + m)$

<br />

#### size

```cpp
inline usize size() const noexcept
```

頂点数を返します。

計算量: 定数時間

<br />

#### edgeNumber

```cpp
inline usize edgeNumber() const noexcept
```

(ユーザーが追加した)辺数を返します。逆辺は考慮されていません

計算量: 定数時間

<br />

#### addEdge

```cpp
u32 addEdge(u32 from, u32 to, const Cap& cap)
```

頂点`from`から頂点`to`へ向けて辺容量`cap`の辺を貼ります。返り値としてこの辺が何番目に追加された辺かを返します。


計算量: 定数時間

<br />

#### from

```cpp
u32 from(u32 id) const noexcept
```

`id`番目に(`addEdge`で)追加された辺の接続元の頂点番号を返します。

計算量: 定数時間

<br />

#### to

```cpp
u32 to(u32 id) const noexcept 
```

`id`番目に(`addEdge`で)追加された辺の接続先の頂点番号を返します。

計算量: 定数時間

<br />

#### residual

```cpp
u32 residual(u32 id) const noexcept
```

`id`番目に(`addEdge`で)追加された辺の残余容量を返します。

計算量: 定数時間

<br />

#### flowed

```cpp
u32 flowed(u32 id) const noexcept
```

`id`番目に(`addEdge`で)追加された辺に流れた水の量を返します。

計算量: 定数時間

<br />

#### originCap

```cpp
u32 originCap(u32 id) const noexcept
```

`id`番目に(`addEdge`で)追加された辺の元々の容量を返します。

計算量: 定数時間

<br />

#### flow

```cpp
Cap flow(u32 s, u32 t)
```

ネットワーク $(V, E, s, t)$ 上の最大フロー $f$ を求めます。

内部で持っている残余ネットワークは $f$ で誘導される残余ネットワークになります。

返り値は $|f|$ です。

計算量: $O(n^{2}m)$

(ネットワークによってはもっとタイトに見積もれる場合があります。)

<br />

#### minCut

```cpp
std::vector<bool> minCut(u32 s) const
```

現在の残余ネットワーク上で`s`から正の残余容量の辺のみを伝って到達できる頂点に`true`が入った`std::vector<bool>`を返します。

計算量: $O(n + m)$

<br />

## 参考

- [https://misawa.github.io/others/flow/dinic_time_complexity.html](https://misawa.github.io/others/flow/dinic_time_complexity.html)
   - 内部の変数・メンバ名はこの記事に準じている(つもりである)
- [http://hos.ac/slides/20150319_flow.pdf](http://hos.ac/slides/20150319_flow.pdf)

