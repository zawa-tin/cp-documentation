---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc127_f.test.cpp
    title: Test/AtCoder/abc127_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc217_h.test.cpp
    title: Test/AtCoder/abc217_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/arc070_e.test.cpp
    title: Test/AtCoder/arc070_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/arc123_d.test.cpp
    title: Test/AtCoder/arc123_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/dwango2016qual_e.test.cpp
    title: Test/Manual/dwango2016qual_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/kupc2016_h.test.cpp
    title: Test/Manual/kupc2016_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/utpc2012_12.test.cpp
    title: Test/Manual/utpc2012_12.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Utility/SlopeTrick.hpp\"\n\n#include <queue>\n#include\
    \ <optional>\n#include <type_traits>\n#include <vector>\n\nnamespace zawa {\n\n\
    \    // domain, codomain\n    template <class D, class C>\n    class SlopeTrick\
    \ {\n        static_assert(std::is_integral_v<D>, \"zawa::SlopeTrick::D must be\
    \ integral\");\n        static_assert(std::is_integral_v<C>, \"zawa::SlopeTrick::C\
    \ must be integral\");\n    public:\n        using SizeType = usize;\n       \
    \ SlopeTrick() = default;\n        SlopeTrick(const SlopeTrick& st) : L_{st.L_},\
    \ R_{st.R_}, min_{st.min_} {}\n        SlopeTrick(SlopeTrick&& st) : L_{std::move(st.L_)},\
    \ R_{std::move(st.R_)}, min_{st.min_} {}\n        SlopeTrick& operator=(const\
    \ SlopeTrick& st) {\n            L_ = st.L_;\n            R_ = st.R_;\n      \
    \      min_ = st.min_;\n            return *this;\n        }\n        SlopeTrick&\
    \ operator=(SlopeTrick&& st) {\n            L_ = std::move(st.L_);\n         \
    \   R_ = std::move(st.R_);\n            min_ = st.min_;\n            return *this;\n\
    \        }\n        // get min\n        C min() const {\n            return min_;\n\
    \        }\n        // get [l0, r0]\n        std::pair<std::optional<D>, std::optional<D>>\
    \ argmin() const {\n            return {\n                L_.empty() ? std::nullopt\
    \ : std::optional<D>{lvalue(L_.top())},\n                R_.empty() ? std::nullopt\
    \ : std::optional<D>{rvalue(R_.top())}\n            };\n        }\n        //\
    \ add y = c\n        void addConstant(C c) {\n            min_ += c;\n       \
    \ }\n        // add y = max(0, x - a)\n        void addMax0XA(D a) {\n       \
    \     if (L_.empty() or lvalue(L_.top()) <= a) {\n                pushR(a);\n\
    \            }\n            else {\n                pushR(lvalue(L_.top()));\n\
    \                min_ += lvalue(L_.top()) - a;\n                L_.pop();\n  \
    \              pushL(a);\n            }\n        }\n        // add y = max(0,\
    \ a - x)\n        void addMax0AX(D a) {\n            if (R_.empty() or a <= rvalue(R_.top()))\
    \ {\n                pushL(a);\n            }\n            else {\n          \
    \      pushL(rvalue(R_.top()));\n                min_ += a - rvalue(R_.top());\n\
    \                R_.pop();\n                pushR(a);\n            }\n       \
    \ }\n        // add y = |x - a|\n        void addAbsoluteXA(D a) {\n         \
    \   addMax0XA(a);\n            addMax0AX(a);\n        }\n        // \u524D\u304B\
    \u3089\u7D2F\u7A4Dmin\u3092\u3068\u3063\u305F\u95A2\u6570\u306B\u7F6E\u304D\u63DB\
    \u3048\u308B\n        void prefixMin() {\n            R_ = std::move(decltype(R_){});\n\
    \            addR_ = D{0};\n        }\n        // \u5F8C\u308D\u304B\u3089\u7D2F\
    \u7A4Dmin\u3092\u3068\u3063\u305F\u95A2\u6570\u306B\u7F6E\u304D\u63DB\u3048\u308B\
    \n        void suffixMin() {\n            L_ = std::move(decltype(L_){});\n  \
    \          addL_ = D{0};\n        }\n        // g(x) = min f(k) (x - a <= k <=\
    \ x - b)\u306B\u7F6E\u304D\u63DB\u3048\u308B\n        void slidingWindowMin(D\
    \ a, D b) {\n            addR_ += b;\n            addL_ += a;\n        }\n   \
    \     // x\u8EF8\u65B9\u5411\u306Bc\u5E73\u884C\u79FB\u52D5\u3059\u308B\n    \
    \    void translation(D c) {\n            slidingWindowMin(c, c);\n        }\n\
    \        // \u50BE\u304D\u304Ck -> k + 1 (x < 0)\u3068\u306A\u308B\u70B9\u3092\
    \u5217\u6319\u3059\u308B\n        std::vector<D> enumerateL() const {\n      \
    \      decltype(L_) L{L_};\n            std::vector<D> res;\n            while\
    \ (L.size()) {\n                res.emplace_back(lvalue(L.top()));\n         \
    \       L.pop();\n            }\n            return res;\n        }\n        //\
    \ \u50BE\u304D\u304Ck -> k + 1 (x >= 0)\u3068\u306A\u308B\u70B9\u3092\u5217\u6319\
    \u3059\u308B\n        std::vector<D> enumerateR() const {\n            decltype(R_)\
    \ R{R_};\n            std::vector<D> res;\n            while (R.size()) {\n  \
    \              res.emplace_back(rvalue(R.top()));\n                R.pop();\n\
    \            }\n            return res;\n        }\n        // get f(x)\n    \
    \    // \u6CE8\u610F: O(N\\log N)\u304B\u304B\u308B\n        C f(D x) const {\n\
    \            C res{min_};\n            for (auto l : enumerateL()) {\n       \
    \         res += std::max(D{0}, l - x);\n            }\n            for (auto\
    \ r : enumerateR()) {\n                res += std::max(D{0}, x - r);\n       \
    \     }\n            return res;\n        }\n        void clear() {\n        \
    \    L_ = decltype(L_){};\n            R_ = decltype(R_){};\n            min_\
    \ = D{0};\n        }\n        SlopeTrick& operator+=(const SlopeTrick& st) {\n\
    \            min_ += st.min();\n            for (auto l : st.enumerateL()) {\n\
    \                addMax0AX(l);\n            }\n            for (auto r : st.enumerateR())\
    \ {\n                addMax0XA(r);\n            }\n            return *this;\n\
    \        }\n        inline SizeType sizeL() const {\n            return L_.size();\n\
    \        }\n        inline SizeType sizeR() const {\n            return R_.size();\n\
    \        }\n        inline SizeType size() const {\n            return sizeL()\
    \ + sizeR();\n        }\n    private:\n        std::priority_queue<D> L_{};\n\
    \        std::priority_queue<D, std::vector<D>, std::greater<D>> R_{};\n     \
    \   D addL_{}, addR_{};\n        C min_{};\n\n        inline D lvalue(D l) const\
    \ noexcept {\n            return l + addL_;\n        }\n        inline D rvalue(D\
    \ r) const noexcept {\n            return r + addR_;\n        }\n        inline\
    \ void pushL(D v) noexcept {\n            L_.push(v - addL_);\n        }\n   \
    \     inline void pushR(D v) noexcept {\n            R_.push(v - addR_);\n   \
    \     }\n    };\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <queue>\n#include <optional>\n#include <type_traits>\n\
    #include <vector>\n\nnamespace zawa {\n\n    // domain, codomain\n    template\
    \ <class D, class C>\n    class SlopeTrick {\n        static_assert(std::is_integral_v<D>,\
    \ \"zawa::SlopeTrick::D must be integral\");\n        static_assert(std::is_integral_v<C>,\
    \ \"zawa::SlopeTrick::C must be integral\");\n    public:\n        using SizeType\
    \ = usize;\n        SlopeTrick() = default;\n        SlopeTrick(const SlopeTrick&\
    \ st) : L_{st.L_}, R_{st.R_}, min_{st.min_} {}\n        SlopeTrick(SlopeTrick&&\
    \ st) : L_{std::move(st.L_)}, R_{std::move(st.R_)}, min_{st.min_} {}\n       \
    \ SlopeTrick& operator=(const SlopeTrick& st) {\n            L_ = st.L_;\n   \
    \         R_ = st.R_;\n            min_ = st.min_;\n            return *this;\n\
    \        }\n        SlopeTrick& operator=(SlopeTrick&& st) {\n            L_ =\
    \ std::move(st.L_);\n            R_ = std::move(st.R_);\n            min_ = st.min_;\n\
    \            return *this;\n        }\n        // get min\n        C min() const\
    \ {\n            return min_;\n        }\n        // get [l0, r0]\n        std::pair<std::optional<D>,\
    \ std::optional<D>> argmin() const {\n            return {\n                L_.empty()\
    \ ? std::nullopt : std::optional<D>{lvalue(L_.top())},\n                R_.empty()\
    \ ? std::nullopt : std::optional<D>{rvalue(R_.top())}\n            };\n      \
    \  }\n        // add y = c\n        void addConstant(C c) {\n            min_\
    \ += c;\n        }\n        // add y = max(0, x - a)\n        void addMax0XA(D\
    \ a) {\n            if (L_.empty() or lvalue(L_.top()) <= a) {\n             \
    \   pushR(a);\n            }\n            else {\n                pushR(lvalue(L_.top()));\n\
    \                min_ += lvalue(L_.top()) - a;\n                L_.pop();\n  \
    \              pushL(a);\n            }\n        }\n        // add y = max(0,\
    \ a - x)\n        void addMax0AX(D a) {\n            if (R_.empty() or a <= rvalue(R_.top()))\
    \ {\n                pushL(a);\n            }\n            else {\n          \
    \      pushL(rvalue(R_.top()));\n                min_ += a - rvalue(R_.top());\n\
    \                R_.pop();\n                pushR(a);\n            }\n       \
    \ }\n        // add y = |x - a|\n        void addAbsoluteXA(D a) {\n         \
    \   addMax0XA(a);\n            addMax0AX(a);\n        }\n        // \u524D\u304B\
    \u3089\u7D2F\u7A4Dmin\u3092\u3068\u3063\u305F\u95A2\u6570\u306B\u7F6E\u304D\u63DB\
    \u3048\u308B\n        void prefixMin() {\n            R_ = std::move(decltype(R_){});\n\
    \            addR_ = D{0};\n        }\n        // \u5F8C\u308D\u304B\u3089\u7D2F\
    \u7A4Dmin\u3092\u3068\u3063\u305F\u95A2\u6570\u306B\u7F6E\u304D\u63DB\u3048\u308B\
    \n        void suffixMin() {\n            L_ = std::move(decltype(L_){});\n  \
    \          addL_ = D{0};\n        }\n        // g(x) = min f(k) (x - a <= k <=\
    \ x - b)\u306B\u7F6E\u304D\u63DB\u3048\u308B\n        void slidingWindowMin(D\
    \ a, D b) {\n            addR_ += b;\n            addL_ += a;\n        }\n   \
    \     // x\u8EF8\u65B9\u5411\u306Bc\u5E73\u884C\u79FB\u52D5\u3059\u308B\n    \
    \    void translation(D c) {\n            slidingWindowMin(c, c);\n        }\n\
    \        // \u50BE\u304D\u304Ck -> k + 1 (x < 0)\u3068\u306A\u308B\u70B9\u3092\
    \u5217\u6319\u3059\u308B\n        std::vector<D> enumerateL() const {\n      \
    \      decltype(L_) L{L_};\n            std::vector<D> res;\n            while\
    \ (L.size()) {\n                res.emplace_back(lvalue(L.top()));\n         \
    \       L.pop();\n            }\n            return res;\n        }\n        //\
    \ \u50BE\u304D\u304Ck -> k + 1 (x >= 0)\u3068\u306A\u308B\u70B9\u3092\u5217\u6319\
    \u3059\u308B\n        std::vector<D> enumerateR() const {\n            decltype(R_)\
    \ R{R_};\n            std::vector<D> res;\n            while (R.size()) {\n  \
    \              res.emplace_back(rvalue(R.top()));\n                R.pop();\n\
    \            }\n            return res;\n        }\n        // get f(x)\n    \
    \    // \u6CE8\u610F: O(N\\log N)\u304B\u304B\u308B\n        C f(D x) const {\n\
    \            C res{min_};\n            for (auto l : enumerateL()) {\n       \
    \         res += std::max(D{0}, l - x);\n            }\n            for (auto\
    \ r : enumerateR()) {\n                res += std::max(D{0}, x - r);\n       \
    \     }\n            return res;\n        }\n        void clear() {\n        \
    \    L_ = decltype(L_){};\n            R_ = decltype(R_){};\n            min_\
    \ = D{0};\n        }\n        SlopeTrick& operator+=(const SlopeTrick& st) {\n\
    \            min_ += st.min();\n            for (auto l : st.enumerateL()) {\n\
    \                addMax0AX(l);\n            }\n            for (auto r : st.enumerateR())\
    \ {\n                addMax0XA(r);\n            }\n            return *this;\n\
    \        }\n        inline SizeType sizeL() const {\n            return L_.size();\n\
    \        }\n        inline SizeType sizeR() const {\n            return R_.size();\n\
    \        }\n        inline SizeType size() const {\n            return sizeL()\
    \ + sizeR();\n        }\n    private:\n        std::priority_queue<D> L_{};\n\
    \        std::priority_queue<D, std::vector<D>, std::greater<D>> R_{};\n     \
    \   D addL_{}, addR_{};\n        C min_{};\n\n        inline D lvalue(D l) const\
    \ noexcept {\n            return l + addL_;\n        }\n        inline D rvalue(D\
    \ r) const noexcept {\n            return r + addR_;\n        }\n        inline\
    \ void pushL(D v) noexcept {\n            L_.push(v - addL_);\n        }\n   \
    \     inline void pushR(D v) noexcept {\n            R_.push(v - addR_);\n   \
    \     }\n    };\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Utility/SlopeTrick.hpp
  requiredBy: []
  timestamp: '2024-05-02 00:23:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Manual/kupc2016_h.test.cpp
  - Test/Manual/dwango2016qual_e.test.cpp
  - Test/Manual/utpc2012_12.test.cpp
  - Test/AtCoder/arc070_e.test.cpp
  - Test/AtCoder/arc123_d.test.cpp
  - Test/AtCoder/abc127_f.test.cpp
  - Test/AtCoder/abc217_h.test.cpp
documentation_of: Src/Utility/SlopeTrick.hpp
layout: document
title: Slope Trick
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
