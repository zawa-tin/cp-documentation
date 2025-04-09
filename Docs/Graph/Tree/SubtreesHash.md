---
title: 根付き木の各部分木をハッシュ値に変換した列
documentation_of: //Src/Graph/Tree/SubtreesHash.hpp
---

## 概要

[Rooted Tree Isomorphism Classification](https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification) をします。$O(N\log N)$でやる代わりに、ハッシュ値が衝突することはありません。

## ライブラリの使い方

```cpp
SubtreesHasher()
```

ハッシュ列を返す関数オブジェクト

複数の木に対して同型判定をしたい場合は単一の関数オブジェクトを利用すること

```cpp
template <class G>
std::vector<usize> SubtreesHasher::operator()(const G& g, usize r = 0u)
```

`g`を`r`を根とした木の隣接リストと捉え、各頂点 $v$ の部分木のハッシュ値を返す。

operator()を二回以上呼ぶとき、返り値の $\max + 1$ が種類数と限らないことに注意

- LCのテストでは一回しか呼ばないため、 $\max + 1$ が種類数と一致している
