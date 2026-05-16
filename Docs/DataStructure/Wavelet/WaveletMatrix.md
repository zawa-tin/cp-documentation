---
title: Wavelet Matrix
documentation_of: //Src/DataStructure/Wavelet/WaveletMatrix.hpp
---

## ライブラリの使い方

```cpp
WaveletMatrix() = default;
explicit WaveletMatrix(std::vector<T> A);
```

`T`は`std::integral`である必要がある。`int`や`unsigned`、`long long`などが該当する

```
inline usize height() const;
inline usize size() const;
```

`size()`は`A`の要素数を返す(=内部の行列の列数)

`height()`は内部の行列の行数を返す

```
T access(usize i) const;
T get(usize i) const;
T operator[](usize i) const;
```

これらは全て`A[i]`を取得するメンバである。 $O(\log \max{A})$

```
T quantile(usize l,usize r,usize k) const
T kthSmallest(usize l,usize r,usize k) const
```

`A[l],A[l+1],...,A[r-1]`の中で`k`番目(0-indexed)に小さい値を返す。 $k\lt r-l$ が必要 $O(\log \max{A})$

```
u32 frequency(usize l,T d,usize r,T u)
```

$i=$ `l,l+1,...,r-1`の中で`A[i]`が $d$ 以上 $u$ 未満である $i$ の数を返す。 $O(\log \max{A})$

## 更新履歴

- 2026/05/16 作成
