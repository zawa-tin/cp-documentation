---
title: 並列二分探索
documentation_of: //Src/Utility/ParallelBinarySearch.hpp
---

## ライブラリの使い方

```
template <class T, class F>
std::vector<T> ParallelBinarySearch(std::vector<T> oks, std::vector<T> ngs, F f) {
```

#### T

整数型のみ

#### oks, ngs

$i$ 個目のクエリの必ず条件を満たす値、必ず条件を満たさない値

#### f

以下の条件を満たす関数。

その一。`f`には引数として、まだ探索が終わっていないクエリの`std::pair<T, usize>{x, id}`のvectorが突っ込まれる。
引数のvector内部の`{x, id}`について、`id`番目のクエリの`x`の場合の判定問題を解く必要がある。

その二。返り値として、`std::pair<bool, hoge>`{T/F, id}`のvectorを入れる。firstは判定問題の結果。secondはそれが何番目のクエリかの添字。

## 計算量

$O(\max_{i} L)$ 回、`f`が呼ばれ、別途に $O(Q)$ の処理が入る。

テストを見る感じ、直書きするよりもだいぶ実測が遅い...
