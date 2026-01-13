---
title: Binary Heap (優先度付きキュー)
documentation_of: //Src/DataStructure/Heap/BinaryHeap.hpp
---

## ライブラリの使い方

要素`a`に対して、`comp(a, b)`が`true`になる方が強いという優先度を設けたPriority Queue。`std::priority_queue`とは逆向きの優先度付けをしているが、こちらの方が直感的に自然だと思う。

### テンプレート

```cpp
template <class T, class Comp = std::less<T>>
requires std::strict_weak_order<Comp, const T&, const T&>
```

デフォルトでは最小値を`top`に持ってくるようになる

### コンストラクタ

```cpp
BinaryHeap(Comp comp = {}) // (1)

template <std::forward_iterator It>
requires std::same_as<std::iter_value_t<It>, T>
BinaryHeap(It first, It last, Comp comp = {}) // (2)

BinaryHeap(std::vector<T>&& a, Comp comp = {})  // (3)

BinaryHeap(const std::vector<T>& a, Comp comp = {}) // (4)
```

(1): 空で初期化 $O(1)$

(2), (3), (4): ヒープを構築する。 $O(N)$
- 空から一個ずつ挿入するより計算量が良いことに注意。まぁ実測はあまり変わらなかったんだけど...

### メンバ

```cpp
inline usize size() const;
inline bool empty() const;
const_iterator begin() const;
const_iterator end() const;
const T& top() const;
void push(T&&);
void push(const T&);
void pop();
```

`std::priority_queue`と同じ。`begin(), end()`が提供されているので、`cout << std::vector(que.begin(), que.end()) << endl;`みたいなこともできる。
- また、空のキューに対する`top, pop`は`assert`で落ちるようになっている。
