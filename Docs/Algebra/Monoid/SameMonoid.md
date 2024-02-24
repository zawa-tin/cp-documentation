---
title: 単一要素からなる多重集合か判定するモノイド
documentation_of: //Src/Algebra/Monoid/SameMonoid.hpp
---

# 概要

しばしば「指定された集合 $S$ に属する要素が全て同じ値か $o(|S|)$ で判定せよ」といった問題が要求されることがある。
- 数列 $A$ の区間 $[l, r)$ に属する要素が... 等

こういったクエリをデータ構造に載せたい時用。

`std::optional<T>`の運用については [std::optional cpprefjp](https://cpprefjp.github.io/reference/optional/optional.html) 等も参考にすること。

## 使い方

#### コンストラクタ

```cpp
(1) SameMonoidData<T>() = default;
(2) SameMonoidData<T>(const T& element)
(3) SameMonoidData<T>(const std::optional<T>& element, bool same)
```

(1) 空集合の時
(2) 単一要素`element`からなる集合の時
(3) ユーザー側からの使用は特に想定していない。protectedとかにすればよかったかも。

<br />

#### empty

```cpp
bool SameMonoidData<T>::empty() const noexcept
```

持っている集合が空集合の時`true`

<br />

#### same

```cpp
bool SameMonoidData<T>::same() const noexcept
```

持っている集合が空または単一要素からなる多重集合の時`true`

<br />

#### element

```cpp
std::optional<T> SameMonoidData<T>::element() const noexcept
```

集合の代表元を返す。集合が空だったり単一要素から構成されていない場合は`std::nullopt`が返る。

<br />

#### value

```cpp
T SameMonoidData<T>::value() const noexcept
```

集合の代表元を返す。集合が空だったり単一要素から構成されていない場合は**実行時エラー**になる。

<br />
