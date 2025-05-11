---
title: 2要素の分離を網羅するテクニック
documentation_of: //Src/Utility/SeparatedFamilySet.hpp
---

$U = \{ 0, 1, 2, \dots, U - 1\}$ に対してある集合属 $S \subseteqq 2^{U}$ を計算する。 $S$ は以下の条件を満たす。

- 任意の $x, y\in U, x \ne y$ に対してある $s\in S$ が存在して $x\in s, y\notin s$ である。
- 条件を満たす $S$ は沢山あるが、そのなかで $\text{card}(S)$ が最小のものを一つ計算する。

計算量: $O(U\log U)$

- $\text{card}(S) \in \log_{2}U + O(\log \log U)$ らしい

## ライブラリの使い方

```
std::vector<std::vector<bool>> SeparatedFamilySet(usize U)
```

長さ $U$ の`std::vector<bool>`を $\text{card}(S)$ 個並べた`std::vector`を返す。

`res[i][j]` は $i$ 番目の集合に $j$ が属しているか。

## 参考

- [2要素の分離を網羅するテクニック](https://noshi91.hatenablog.com/entry/2024/05/31/012055)
