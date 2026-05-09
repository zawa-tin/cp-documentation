---
title: Dual Segment Tree (非可換対応)
documentation_of: //Src/DataStructure/SegmentTree/DualSegmentTree.hpp
---

## ライブラリの使い方

#### テンプレート

```cpp
template <class M,class T,bool Commutative = false>
requires concepts::Monoid<M> and concepts::Action<M,T>
```

雛形

```cpp
struct M {
    using Element = ;
    static Element identity() {
    }
    static Element operation(Element L,Element R) {
    }
    static Element action(Element o,T x) {
    }
};
struct M : public HogeFuga {
    static Element action(HogeFuga::Element o,T x) {
    }
}
```

`action`が`operation`とまったく同じ場合、`Src/Algebra/Monoid/MonoidAction.hpp`内の`AddSelfAction`を用いることができる。

#### コンストラクタ


```
DualSegmentTree() = default;
explicit DualSegmentTree(usize n);
explicit DualSegmentTree(usize n,T init);
explicit DualSegmentTree(std::vector<T> a);
```

作用する値は全部単位元で初期化される

#### メンバ

```cpp
void operation(usize l,usize r,O o)
void operation(usize i,O o)
T get(usize i) const
T operator[](usize i) const
void assign(usize i,T x)
void assignOperator(usize i,O o)
std::vector<T> container() const
```

`operation`は $a_{i}$ に`o`を作用させる

`assignOperator`は $a_{i}$ にこれまでの作用を全てリセットし、`o`を作用させる。

- あまりこのメンバを使う機会はなさそう。`assign(i,get(i))`とすると事足りるケースが殆どだと思う。pakenのverifyで無理やり使った(本来`DualFenwickTree`で事足りる)

`assign`は $a_{i}$ を完全に`x`に変更する。 $a_{i}$ に対する溜まっている作用はリセットさせる。

- この操作は作用には該当しない。なのでこのあと`assignOperator`すると得られるのは`x`に`o`を作用させた値である

## 更新履歴

- 2026/05/10: 全部書き直した。設計変更
