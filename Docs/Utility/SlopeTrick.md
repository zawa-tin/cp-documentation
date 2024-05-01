---
title: Slope Trick
documentation_of: //Src/Utility/SlopeTrick.hpp
---

## 概要

[slope trick (1) 解説編](https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8) で紹介されている操作をライブラリ化したもの。

取り扱う関数を $f$ 、傾きの変化する点の多重集合の要素数を $N$ とする。

当然だが、扱う $f$ は上記解説に書かれている制約を満たす必要がある。

## ライブラリの使い方

#### テンプレート引数

```
template <class D, class C>
```

`D`が $x$ の型、`C`が $f(x)$ の型。

制約: `std::is_integral<D>`、`std::is_integral<C>`が`std::true_type`から派生する。

<br />

#### コンストラクタ

```cpp
(1) SlopeTrick();
(2) SlopeTrick(const SlopeTrick&);
(3) SlopeTrick(SlopeTrick&&);
```

(1) $f(x) = 0$ で初期化する

(2) コピーコンストラクタ

(3) ムーブコンストラクタ

**計算量**

- (1) 定数時間
- (2) $O(N\log N)$
- (3) 定数時間

<br />

#### operator=

```cpp
(1) SlopeTrick& operator=(const SlopeTrick&)
(2) SlopeTrick& operator=(SlopeTrick&&)
```

**計算量**

- (1) $O(N\log N)$
- (2) 定数時間

<br />

#### min

```cpp
C min() const
```

$\min f(x)$ を返す。

**計算量**

- 定数時間

<br />

#### argmin

```cpp
std::pair<std::optional<D>, std::optional<D>> argmin() const
```

$\text{argmin} f(x)$ は区間になる。この左端、右端をこの順に`std::pair`に入れて返す。

左端が $-\infty$ 、右端が $\infty$ の場合は`std::nullopt`が返る。

**計算量**

- 定数時間

<br />

#### addConstant

```cpp
void addConstant(C c)
```

$f(x) \leftarrow f(x) + c$ とする。

**計算量**

- 定数時間

<br />

#### addMax0XA

```cpp
void addMax0XA(D a)
```

$f(x) \leftarrow f(x) + \max(0, x - a)$ とする。

**計算量**

- $O(\log N)$

<br />

#### addMax0AX

```cpp
void addMax0AX(D a)
```

$f(x) \leftarrow f(x) + \max(0, a - x)$ とする。

**計算量**

- $O(\log N)$

<br />

#### addAbsoluteXA

```cpp
void addAbsoluteXA(D a)
```

$f(x) \leftarrow f(x) + |x - a|$ とする。

**計算量**

- $O(\log N)$

<br />

#### prefixMin

```cpp
void prefixMin()
```

$f(x) \leftarrow \min_{x'\le x} f(x')$ とする。

**計算量**

- 定数時間

<br />

#### suffixMin

```cpp
void suffixMin()
```

$f(x) \leftarrow \min_{x'\ge x} f(x')$ とする。

**計算量**

- 定数時間

<br />

#### slidingWindowMin

```cpp
void slidingWindowMin(D a, D b)
```

$f(x) \leftarrow \min_{x - a\le x'\le x - b} f(x')$ とする。符号注意。

**計算量**

- 定数時間

<br />

#### translation

```cpp
void translation(D c)
```

$f(x) \leftarrow f(x - c)$ とする。

**計算量**

- 定数時間

<br />

#### enumerateL

```cpp
std::vector<D> enumerateL() const
```

変化点の左側集合を返す。

**計算量**

- $O(N\log N)$

<br />

#### enumerateR

```cpp
std::vector<D> enumerateR() const
```

変化点の右側集合を返す。

**計算量**

- $O(N\log N)$

<br />

#### f

```cpp
C f(D x) const
```

$f(x)$ を返す。

**計算量**

- $O(N\log N)$

<br />

#### clear

```cpp
void clear()
```

$f(x)\leftarrow 0$ とする。

<br />

#### operator+=

```cpp
SlopeTrick& operator+=(const SlopeTrick&)
```

左辺の関数に右辺の関数を足し込む。

**計算量**

- $O(N\log^{2} N)$
- マージテクをすると全体で $O(N\log^{2} N)$ を達成することも可能(例: じょうしょうツリー)

<br />

#### sizeL

```cpp
inline SizeType sizeL() const
```

`SizeType = zawa::usize (std::size_t)`

左側集合のサイズを返す。

**計算量**

<br />

- 定数時間

#### sizeR

```cpp
inline SizeType sizeR() const
```

右側集合のサイズを返す。

**計算量**

- 定数時間

<br />

#### size

```cpp
inline SizeType size() const
```

$N$ を返す。

**計算量**

- 定数時間

<br />

## メモ
