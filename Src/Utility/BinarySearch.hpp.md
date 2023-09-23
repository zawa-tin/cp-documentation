---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc191_d.test.cpp
    title: Test/AtCoder/abc191_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc236_e.test.cpp
    title: Test/AtCoder/abc236_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/arc165_c.test.cpp
    title: Test/AtCoder/arc165_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Utility/BinarySearch.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Utility/BinarySearch.hpp\"\n\n#include <cmath>\n\
    #include <functional>\n#include <type_traits>\n#include <utility>\n\nnamespace\
    \ zawa {\n\nnamespace internal {\n\ntemplate <class T>\nT MidPoint(T a, T b) {\n\
    \    if (a > b) std::swap(a, b);\n    return a + ((b - a) >> 1);\n}\n\ntemplate\
    \ <class T>\nT Abs(T a, T b) {\n    return (a >= b ? a - b : b - a);\n}\n\n} //\
    \ namespace zawa::internal\n\ntemplate <class T, class Function>\nT BinarySearch(T\
    \ ok, T ng, const Function& f) {\n    static_assert(std::is_integral_v<T>, \"\
    T must be integral type\");\n    static_assert(std::is_convertible_v<Function,\
    \ std::function<bool(T)>>, \"f must be function bool(T)\");\n    while (internal::Abs(ok,\
    \ ng) > 1) {\n        T mid{ internal::MidPoint(ok, ng) };\n        (f(mid) ?\
    \ ok : ng) = mid;\n    }\n    return ok;\n}\n\ntemplate <class T, class Function>\n\
    T BinarySearch(T ok, T ng, const Function& f, u32 upperLimit) {\n    static_assert(std::is_signed_v<T>,\
    \ \"T must be signed arithmetic type\");\n    static_assert(std::is_convertible_v<Function,\
    \ std::function<bool(T)>>, \"f must be function bool(T)\");\n    for (u32 _{}\
    \ ; _ < upperLimit ; _++) {\n        T mid{ (ok + ng) / (T)2 };\n        (f(mid)\
    \ ? ok : ng) = mid;\n    }\n    return ok;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <cmath>\n\
    #include <functional>\n#include <type_traits>\n#include <utility>\n\nnamespace\
    \ zawa {\n\nnamespace internal {\n\ntemplate <class T>\nT MidPoint(T a, T b) {\n\
    \    if (a > b) std::swap(a, b);\n    return a + ((b - a) >> 1);\n}\n\ntemplate\
    \ <class T>\nT Abs(T a, T b) {\n    return (a >= b ? a - b : b - a);\n}\n\n} //\
    \ namespace zawa::internal\n\ntemplate <class T, class Function>\nT BinarySearch(T\
    \ ok, T ng, const Function& f) {\n    static_assert(std::is_integral_v<T>, \"\
    T must be integral type\");\n    static_assert(std::is_convertible_v<Function,\
    \ std::function<bool(T)>>, \"f must be function bool(T)\");\n    while (internal::Abs(ok,\
    \ ng) > 1) {\n        T mid{ internal::MidPoint(ok, ng) };\n        (f(mid) ?\
    \ ok : ng) = mid;\n    }\n    return ok;\n}\n\ntemplate <class T, class Function>\n\
    T BinarySearch(T ok, T ng, const Function& f, u32 upperLimit) {\n    static_assert(std::is_signed_v<T>,\
    \ \"T must be signed arithmetic type\");\n    static_assert(std::is_convertible_v<Function,\
    \ std::function<bool(T)>>, \"f must be function bool(T)\");\n    for (u32 _{}\
    \ ; _ < upperLimit ; _++) {\n        T mid{ (ok + ng) / (T)2 };\n        (f(mid)\
    \ ? ok : ng) = mid;\n    }\n    return ok;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Utility/BinarySearch.hpp
  requiredBy: []
  timestamp: '2023-09-24 02:48:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc236_e.test.cpp
  - Test/AtCoder/abc191_d.test.cpp
  - Test/AtCoder/arc165_c.test.cpp
documentation_of: Src/Utility/BinarySearch.hpp
layout: document
title: "\u4E8C\u5206\u63A2\u7D22"
---

## 概要

整数や実数を一つ引数にとり、真理値を返り値とする関数 $f$ を考えます。 $f$ に以下の性質の一方を満たすと仮定します。
- ある値 $m$ が存在して、 $m$ 以下の値 $x$ では $f(x) = \text{true}$ 、 $m$ より大きい値 $x$ では $f(x) = \text{false}$
- ある値 $m$ が存在して、 $m$ 未満の値 $x$ では $f(x) = \text{false}$ 、 $m$ 以上の値 $x$ では $f(x) = \text{true}$

このような場合で、 $m$ を発見して返します。

#### ライブラリの使い方

```cpp
(1) 
template<class T, class Function>
T BinarySearch(T ok, T ng, const Function& f)

(2)
template<class T, class Function>
T BinarySearch(T ok, T ng, const Functioni& f, u32 upperLimit)
```

#### テンプレート引数

`T`

- `f`の引数の型です。

**制約**:

(1) **整数**型であること

(2) 算術型であること
- (2) は浮動小数点数型等も許される。

`Function`

- `f`の型です。

**制約**: 

- `T`型の値を一つ引数にとり、`bool`値を返り値とする関数オブジェクトであること
- 副作用が無いこと(特にエラーを吐きませんが、 $m$ を正しく発見できる保証が無いです)

<br />

#### 引数

`ok`

**制約**: `f(ok) = true`を満たすこと

`ng`

**制約**: `f(ng) = false`を満たすこと

`f`

**制約**: 概要の条件を満たすこと

`upperLimit`

探索回数の上限を設定します。

<br />

#### 返り値

$m$ を返します。

<br />

#### 計算量の見積もり

(1) `f`を $\mid \text{ok} - \text{ng}\mid$ 回呼び出します。

(2) `f`を`upperLimit`回呼び出します。

<br />

#### アルゴリズム

名前の通り、二分探索しています。

所謂、めぐる式二分探索を採用しています。
- (https://twitter.com/meguru_comp/status/697008509376835584)

#### メモ

2023/9/24: (1)においてunsignedな整数型も利用できるように修正しました。オーバーフローする問題を解消しました。
