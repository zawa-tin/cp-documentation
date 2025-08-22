---
title: 離散対数問題(モノイド)
documentation_of: //Src/Algebra/Monoid/MonoidDiscreteLogarithm.hpp
---

## 概要

モノイド $(X, \oplus)$ と集合 $S$ に対して関数 $f : X\times S\rightarrow S$ が定義されているとする。

$x \in S, s, t \in S$ に対して $f(x^{n}, s) = t$ を満たす最小の $n$ を計算する。それが入力で与えられる正整数 $N$ 以上である、または存在しないならば`std::nullopt`を返す。

## ライブラリの使い方

```cpp
template <class X, class S, class H>
std::optional<usize> MonoidDiscreteLogarithm(typename X::Element x, S s, S t, usize N)  (1)

template <class X, class S>
std::optional<usize> MonoidDiscreteLogarithm(X x, S s, S t, usize N) (2)
```

(1) `X`は`concepts::Monoid`を満たす必要がある。 `X`に対して`S action(X, S)`が定義されている必要がある。`H`は`S`の要素のハッシュを取る関数オブジェクトである必要がある。

$S$ に対して`std::hash`が定義されているならば(2)を用いることができる((2)は未verify...)

例えば、通常の離散対数問題( $x^{n} \equiv y\pmod{M}$ なる最小の $n$ を見つける)ときは以下のようにする。

```cpp
using S = mint;
struct X {
    using Element = mint;
    static Element identity() {
        return mint{1};
    }
    static Element operation(Element L, Element R) {
        return L * R;
    }
    static Element action(Element x, S s) {
        return x * s;
    }
};
struct Hasher {
    size_t operator()(const S& v) const {
        return v.val();
    }
};
int main() {
    auto ans = MonoidDiscreteLogarithm<M, mint, Hasher>(mint{x}, mint{1}, mint{y}, M);
}
```

## 計算量

- `X::identity()`を高々 $2$ 回呼び出す
- `X::operation()`を高々 $4\lfloor \sqrt{N}\rfloor + O(1)$ 回呼び出す
- `X::action()`を高々 $3\lfloor\sqrt{N}\rfloor + O(1)$ 回呼び出す
- `std::unordered<S>`に高々 $\lfloor\sqrt{N}\rfloor$ 要素挿入され、高々 $\lfloor\sqrt{N}\rfloor + O(1)$ 回検索を行う

## 参考

- [モノイド作用に関する離散対数問題](https://maspypy.com/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89%E4%BD%9C%E7%94%A8%E3%81%AB%E9%96%A2%E3%81%99%E3%82%8B%E9%9B%A2%E6%95%A3%E5%AF%BE%E6%95%B0%E5%95%8F%E9%A1%8C)

## メモ

逆元が定義できるなら、最初に $x^{km}s\in T$ を発見して、あとは逆元かけながら高々 $m$ ステップ戻る... みたいにすると早くなるかも？

## 変更履歴

2025/8/21 作成
