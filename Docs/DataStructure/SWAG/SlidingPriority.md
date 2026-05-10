---
title: スライド最小値
documentation_of: //Src/DataStructure/SWAG/SlindingPriority.hpp
---

## ライブラリの使い方

### SlidingPriority

```cpp
template <class T,class F = std::less<T>>
requires std::predicate<F,T,T>
class SlidingPriority
```

デックに入っている要素の中で`F`が一番`true`になる要素を管理する

メンバは`size(),empty(),push(),top(),operator()()`を提供している。`operator()()`は`top()`と同じである。

空のときに`pop()`や`top()`を呼び出すとassertにひっかかる

### StaticLengthPriority

```cpp
template <class T,class F>
requires std::predicate<F,T,T>
std::vector<T> StaticLengthPriority(const std::vector<T>& A,usize K,F comp)

template <class T>
requires std::totally_ordered<T>
std::vector<T> StaticLengthPriority(const std::vector<T>& A,usize K) {
```

`A`の長さ`K`の全ての連続部分列に対して`comp`が最も`true`になる要素を列挙する。 $K\le N$ が必要である。(assertにひっかかる)

`comp`を指定しないバージョンは`std::less<T>`が指定される(=最小値)

## 更新履歴

- 2026/05/10: 作成
