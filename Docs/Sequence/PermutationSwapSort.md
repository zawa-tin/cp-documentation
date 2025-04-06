---
title: Permutationを $N-1$ 回以下のswapでソートする
documentation_of: //Src/Sequence/PermutationSwapSort.hpp
---

## 概要

$(0,1,2,\dots, N-1)$ の並び替え $P$ を入力に与えると、 $N-1$ 回以下の(隣接とは限らない)二点swapでソートします。

なお、実際にソートは行われず操作列が返ります。

## ライブラリの使い方

```cpp
template <std::input_iterator It>
std::vector<std::pair<usize, usize>> PermutationSwapSort(It first, It last)
```

**計算量:** $O(N)$
- 順列であるかのチェックや`std::vector`へのコピーが行われるため、若干オーバーヘッドがあります
