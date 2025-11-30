---
title: 静的な列上の区間和クエリ
documentation_of: //Src/DataStructure/PrefixSum/StaticRangeSumSolver.hpp
---

## 概要

値の変更が無い長さ $N$ の数列 $A$ 上で区間和クエリを処理します。

詳細は1次元累積和のドキュメントを確認お願いします。

## ライブラリの使い方

```cpp
(1) using StaticRangeSumSolver = PrefixSum1D<AdditiveGroup<T>>;
(2) using Ruisekiwa = PrefixSum1D<AdditiveGroup<T>>;
```

構造体を生やす必要は無く、`T`をテンプレート引数で指定するだけです。

(1)、(2)共に同様です。好きな名前の方をお使いください。
