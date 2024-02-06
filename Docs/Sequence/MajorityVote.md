---
title: Boyer-MooreのMajority vote algorithm
documentation_of: //Src/Sequence/MajorityVote.hpp
---

## 使い方

```cpp
template <class T, class InputIterator>
std::optional<T> MajorityVote(InputIterator first, InputIterator last)
```

引数に与えたイテレータ範囲`[first, last)`に過半数を占める要素が存在するなら、その値を返す。存在しない場合は`std::nullopt`を返す。

`std::optional`は`std::nullopt`でないなら`true`と評価される。

- [cpprefjp std::optional](https://cpprefjp.github.io/reference/optional/optional.html)

```cpp
auto v{MajorityVote<T>(A.begin(), A.end())};
if (v) {
    std::cout << v << '\n';
}
else {
    std::cout << "not exist" << '\n';
}
```

#### 計算量

長さ $N$ の列に対して $O(N)$ で動作する

## 参考

- [Kyopro Encyclopedia of Algorithms](https://noshi91.github.io/algorithm-encyclopedia/boyer-moore-majority-vote-algorithm)
