---
title: 区間Prefix総積モノイド
documentation_of: //Src/Algebra/Monoid/PrefixProductMonoid.hpp
---

# 概要

セグ木とかのモノイドで抽象化できるデータ構造に乗るやつ。

列 $A$ 上の区間 $[l, r)$ に対して

$g_{l, r}(A) = g(A_{l}, f(A_{l}, A_{l + 1}), f(A_{l}, A_{l + 1}, A_{l + 2}), \dots, f(A_{l}, A_{l + 1}, \dots, A_{r}))$ を管理する。

例えば $\max(A_{1}, A_{1} + A_{2}, \dots, A_{1} + A_{2} + \dots, A_{N})$ とか...

え？これ遅延伝搬いらないんすね。うお〜〜〜〜。

# 使い方

```cpp
template <class Value>
class PrefixProductMonoidData(const Value& product, const Value& prefix)

template <class O, class F>
class PrefixProductMonoid
```

`PrefixProductMonoidData`は`product`, `prefix`のゲッタだけ提供する。
- `product`は $f(A_{l}, A_{l + 1}, \dots, A_{r})$
- `prefix` は $g_{l, r}(A)$

`PrefixProductMonoid`は`Element, identity(), operation()`を提供するクラス。

テンプレート引数について、`O` は $f$ 、 `F`は $g$ のモノイドを与える必要がある。

# 参考

- [ABC292-H Editional](https://atcoder.jp/contests/abc292/editorial/5887)
