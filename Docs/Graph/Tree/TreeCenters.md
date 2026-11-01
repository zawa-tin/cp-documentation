---
title: 木の直径にまつわるUtilityクラス
documentation_of: //Src/Graph/Tree/TreeCenters.hpp
---

## 概要

与えられた木を木の中心を根とした根付き木に変換する。

中心が辺の上にあるときは、辺を分割して仮想頂点を置き、仮想頂点を根とする。

## ライブラリの使い方

### テンプレート引数

```
template <std::integral T,class U>
class TreeCenters
```

`T`は頂点番号の型。`int`、`u32`、`usize`のいずれかであることが推奨される。

`U`は辺重みの型。整数であることが必要。直径の長さが`U`で表現できる(オーバーフローしない)ことが重要である。

### コンストラクタ

```
explicit TreeCenters(std::vector<std::vector<std::pair<T,U>>> g)  (1)
explicit TreeCenters(std::vector<std::vector<T>> g) (2)
```

(1)は辺に重みがある場合、いつもの隣接リストの形式で与える。

**重要な制約として、各辺の重みは正である必要がある。特に、辺の重みとして $0$ も許容されず、assertにひっかかる点に注意**

(2)は辺に重みが無い場合に用いることができる。全ての辺の重みが $1$ であると仮定してアルゴリズムを実行する。

それぞれについて与えられた木に対して以下の手続きを行う

- 直径を一つ求める
- 直径から中心を求める
- 中心が辺上にあるときは、仮想頂点 $N$ を追加して、もとの辺を消し、仮想頂点と接続する。このときの仮想頂点とつながる辺の重みはそれぞれ元の辺の重みを $w$ として $\lfloor\frac{w}{2}\rfloor$ 及び $\lceil\frac{w}{2}\rceil$ である。よって辺上に中心がある場合は、厳密に中心を取っているわけではない。
- 中心を根とした根付き木に変換する。特に、子孫から親方向への辺は削除され、有向木として管理される
- 各頂点の親頂点が計算される
- 各頂点について最遠点とその距離が計算される

**計算量**: $O(N)$

### メンバ

```
inline usize size() const noexcept
inline const std::vector<T>& diameterPath() const
U diameterLength() const
inline T root() const noexcept
inline const std::vector<std::pair<T,U>>& operator[](usize v) const noexcept
inline i32 parent(usize v) const noexcept
inline const std::pair<T,U>& farthest(usize v) const noexcept
```

- `size()` は根付き木の頂点数。木の中心が頂点にあるときは $N$ 、そうでないときは $N+1$ に一致する。  $O(1)$
- `diameterPath()` は発見した直径の頂点列を返す。中心が辺の場合の仮想頂点は含まない。
- `diameterLength()` は直径の長さ (辺重みの総和) を返す。 $O(1)$
- `root()` は変換後の根頂点の番号を返す。特に、仮想頂点が根のときは $N$ が返ることになる。 $O(1)$　
- `operator[](v)` は根付き木における $v$ の直接の子のリスト。コンストラクタ(1)の引数と同様に`pair{子,辺重み}`で返す。
- `parent(v)` は $v$ の親頂点。 $v$ が根のときは `-1` が返される。 $O(1)$
- `farthest(v)` は $v$ の最遠点の一つが `first` に、最遠点までの距離が `second` に返される。なお、`first`に入る最遠点は`diameterPath().front(),diameterPath().back()`のいずれか一方である。 $O(1)$


## 更新履歴

- 2026/11/01: 作成
