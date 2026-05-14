---
title: 2次元累積和
documentation_of: //Src/DataStructure/PrefixSum/PrefixSum2D.hpp
---

## ライブラリの使い方

```cpp
Ruisekiwa2D(usize H, usize W);
explicit Ruisekiwa2D(std::vector<std::vector<T>>&& a);
explicit Ruisekiwa2D(const std::vector<std::vector<T>>& a);
```

がコンストラクタ

```cpp
inline usize height() const;
inline usize width() const;
```

でサイズを取得できる

```
void operation(usize i, usize j, T v);
const std::vector<T>& operator[](const usize i) const;
```

一点加算と一点取得

```
internal::StaticRectSumSolver<G> build() const;
internal::StaticRectSumSolver<G> inplaceBuild();
```

で累積和を構築。`inplaceBuild`は一回までしか呼んではならない。

`StaticRectSumSolver`では`height(),width(),operator[]`及び矩形和を取得する`produt(l,d,r,u)`が提供されている。

`product`の引数の順番は

1. 1次元目の下
2. 2次元目の下
3. 1次元目の上
4. 2次元目の上

である。いつも通り

`const_iterator`を返す`begin(),end()`もあるが、使いどころわかんない。


```cpp
internal::StaticRectSumSolver<G> BuildRuisekiwa2D(std::vector<std::vector<typename G::Element>> A)
```

という関数も提供していて、`A`から直接累積和を構築することもできる。

## 更新履歴

- 昔: 作った
- 2026/05/14: `BuildRuisekiwa2D`メンバを追加、ドキュメントを書いた

