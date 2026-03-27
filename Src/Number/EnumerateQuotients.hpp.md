---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/IntegerDivision.hpp
    title: "\u6574\u6570\u540C\u58EB\u306E\u5207\u308A\u6368\u3066/\u5207\u308A\u4E0A\
      \u3052\u9664\u7B97"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2957.test.cpp
    title: AOJ2957 MOD Rush
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc132_f.test.cpp
    title: ABC132-F Small Products
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc230_e.test.cpp
    title: Test/AtCoder/abc230_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/enumerate_quotients.test.cpp
    title: Test/LC/enumerate_quotients.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/My/Number/EnumerateQuotients/ceilBuild.test.cpp
    title: Test/My/Number/EnumerateQuotients/ceilBuild.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Number/EnumerateQuotients.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/Number/IntegerDivision.hpp\"\n\n#include\
    \ <type_traits>\n#include <cassert>\n\nnamespace zawa {\n\ntemplate <class T>\n\
    constexpr T DivFloor(T a, T b) {\n    static_assert(std::is_integral_v<T>, \"\
    DivFloor argument must be Integer\");\n    assert(b != T{});\n    if constexpr\
    \ (std::is_unsigned_v<T>) {\n        return a / b;\n    }\n    else {\n      \
    \  if (b < 0) {\n            a *= -1;\n            b *= -1;\n        }\n     \
    \   return (a >= 0 ? a / b : (a - b + 1) / b);\n    }\n}\n\ntemplate <class T>\n\
    constexpr T DivCeil(T a, T b) {\n    static_assert(std::is_integral_v<T>, \"DivCeil\
    \ argument must be Integer\");\n    assert(b != T{});\n    if constexpr (std::is_unsigned_v<T>)\
    \ {\n        return (a + b - 1) / b;\n    }\n    else {\n        if (b < 0) {\n\
    \            a *= -1;\n            b *= -1;\n        }\n        return (a >= 0\
    \ ? (a + b - 1) / b : a / b);\n    }\n}\n\n} // namespace zawa\n#line 5 \"Src/Number/EnumerateQuotients.hpp\"\
    \n\n#line 7 \"Src/Number/EnumerateQuotients.hpp\"\n#include <vector>\n#include\
    \ <utility>\n#line 10 \"Src/Number/EnumerateQuotients.hpp\"\n\nnamespace zawa\
    \ {\n\ntemplate <class Value>\nclass EnumerateQuotients {\npublic:\n    class\
    \ Data {\n    private:\n        Value quotient_;\n        Value l_, r_;\n    public:\n\
    \        Data() = default;\n        constexpr Data(Value quotient, Value l, Value\
    \ r) : quotient_{ quotient }, l_{ l }, r_{ r } {\n            assert(l < r);\n\
    \        }\n        \n        constexpr Value quotient() const noexcept {\n  \
    \          return quotient_;\n        }\n\n        constexpr Value l() const noexcept\
    \ {\n            return l_;\n        }\n\n        constexpr Value r() const noexcept\
    \ {\n            return r_;\n        }\n\n        constexpr std::pair<Value, Value>\
    \ range() const noexcept {\n            return std::pair{ l_, r_ };\n        }\n\
    \n        constexpr Value len() const noexcept {\n            return r_ - l_;\n\
    \        }\n    };\n\nprivate:\n    std::vector<Data> seq_;\n    Value n_;\n\n\
    \    constexpr void templateTypeAssert() const noexcept {\n        static_assert(std::is_integral_v<Value>,\
    \ \"Template argument must be unsigned integer type.\");\n        static_assert(std::is_unsigned_v<Value>,\
    \ \"Template argument must be unsigned integer type.\");\n    }\n\n    constexpr\
    \ void floorBuild() noexcept {\n        Value l{1U};\n        while (l <= n_)\
    \ {\n            Value quotient{ DivFloor(n_, l) };\n            Value r{ DivFloor(n_,\
    \ quotient) + 1 };\n            seq_.emplace_back(quotient, l, r);\n         \
    \   l = r;\n        } \n    }\n\n    constexpr void ceilBuild() noexcept {\n \
    \       Value l{1U};\n        while (l < n_) {\n            Value quotient{ DivCeil(n_,\
    \ l) };\n            Value r{ DivCeil(n_, quotient - 1) };\n            seq_.emplace_back(quotient,\
    \ l, r);\n            l = r;\n        }\n        if (n_) {\n            seq_.emplace_back(1U,\
    \ n_, n_ + 1);\n        }\n    }\n\npublic:\n    constexpr EnumerateQuotients()\
    \ : seq_{}, n_{} {\n        templateTypeAssert();\n    }\n\n    constexpr EnumerateQuotients(Value\
    \ n, bool floor = true) : seq_{}, n_{ n } {\n        templateTypeAssert();\n \
    \       floor ? floorBuild() : ceilBuild();\n        seq_.shrink_to_fit();\n \
    \   }\n\n    constexpr Value n() const noexcept {\n        return n_;\n    }\n\
    \n    constexpr Data operator[](u32 i) const noexcept {\n        return seq_[i];\n\
    \    }\n\n    constexpr Value quotient(u32 i) const noexcept {\n        assert(i\
    \ < seq_.size()); \n        return seq_[i].quotient();\n    }\n\n    constexpr\
    \ Value l(u32 i) const noexcept {\n        assert(i < seq_.size()); \n       \
    \ return seq_[i].l();\n    }\n\n    constexpr Value r(u32 i) const noexcept {\n\
    \        assert(i < seq_.size()); \n        return seq_[i].r();\n    }\n\n   \
    \ constexpr std::pair<Value, Value> range(u32 i) const noexcept {\n        assert(i\
    \ < seq_.size());\n        return std::move(seq_[i].range());\n    }\n\n    constexpr\
    \ Value len(u32 i) const noexcept {\n        assert(i < seq_.size());\n      \
    \  return seq_[i].len();\n    }\n\n    constexpr usize size() const noexcept {\n\
    \        return seq_.size();\n    }\n\n    constexpr typename decltype(seq_)::const_iterator\
    \ begin() const noexcept {\n        return seq_.begin();\n    }\n\n    constexpr\
    \ typename decltype(seq_)::const_iterator end() const noexcept {\n        return\
    \ seq_.end();\n    }\n\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"./IntegerDivision.hpp\"\
    \n\n#include <type_traits>\n#include <vector>\n#include <utility>\n#include <cassert>\n\
    \nnamespace zawa {\n\ntemplate <class Value>\nclass EnumerateQuotients {\npublic:\n\
    \    class Data {\n    private:\n        Value quotient_;\n        Value l_, r_;\n\
    \    public:\n        Data() = default;\n        constexpr Data(Value quotient,\
    \ Value l, Value r) : quotient_{ quotient }, l_{ l }, r_{ r } {\n            assert(l\
    \ < r);\n        }\n        \n        constexpr Value quotient() const noexcept\
    \ {\n            return quotient_;\n        }\n\n        constexpr Value l() const\
    \ noexcept {\n            return l_;\n        }\n\n        constexpr Value r()\
    \ const noexcept {\n            return r_;\n        }\n\n        constexpr std::pair<Value,\
    \ Value> range() const noexcept {\n            return std::pair{ l_, r_ };\n \
    \       }\n\n        constexpr Value len() const noexcept {\n            return\
    \ r_ - l_;\n        }\n    };\n\nprivate:\n    std::vector<Data> seq_;\n    Value\
    \ n_;\n\n    constexpr void templateTypeAssert() const noexcept {\n        static_assert(std::is_integral_v<Value>,\
    \ \"Template argument must be unsigned integer type.\");\n        static_assert(std::is_unsigned_v<Value>,\
    \ \"Template argument must be unsigned integer type.\");\n    }\n\n    constexpr\
    \ void floorBuild() noexcept {\n        Value l{1U};\n        while (l <= n_)\
    \ {\n            Value quotient{ DivFloor(n_, l) };\n            Value r{ DivFloor(n_,\
    \ quotient) + 1 };\n            seq_.emplace_back(quotient, l, r);\n         \
    \   l = r;\n        } \n    }\n\n    constexpr void ceilBuild() noexcept {\n \
    \       Value l{1U};\n        while (l < n_) {\n            Value quotient{ DivCeil(n_,\
    \ l) };\n            Value r{ DivCeil(n_, quotient - 1) };\n            seq_.emplace_back(quotient,\
    \ l, r);\n            l = r;\n        }\n        if (n_) {\n            seq_.emplace_back(1U,\
    \ n_, n_ + 1);\n        }\n    }\n\npublic:\n    constexpr EnumerateQuotients()\
    \ : seq_{}, n_{} {\n        templateTypeAssert();\n    }\n\n    constexpr EnumerateQuotients(Value\
    \ n, bool floor = true) : seq_{}, n_{ n } {\n        templateTypeAssert();\n \
    \       floor ? floorBuild() : ceilBuild();\n        seq_.shrink_to_fit();\n \
    \   }\n\n    constexpr Value n() const noexcept {\n        return n_;\n    }\n\
    \n    constexpr Data operator[](u32 i) const noexcept {\n        return seq_[i];\n\
    \    }\n\n    constexpr Value quotient(u32 i) const noexcept {\n        assert(i\
    \ < seq_.size()); \n        return seq_[i].quotient();\n    }\n\n    constexpr\
    \ Value l(u32 i) const noexcept {\n        assert(i < seq_.size()); \n       \
    \ return seq_[i].l();\n    }\n\n    constexpr Value r(u32 i) const noexcept {\n\
    \        assert(i < seq_.size()); \n        return seq_[i].r();\n    }\n\n   \
    \ constexpr std::pair<Value, Value> range(u32 i) const noexcept {\n        assert(i\
    \ < seq_.size());\n        return std::move(seq_[i].range());\n    }\n\n    constexpr\
    \ Value len(u32 i) const noexcept {\n        assert(i < seq_.size());\n      \
    \  return seq_[i].len();\n    }\n\n    constexpr usize size() const noexcept {\n\
    \        return seq_.size();\n    }\n\n    constexpr typename decltype(seq_)::const_iterator\
    \ begin() const noexcept {\n        return seq_.begin();\n    }\n\n    constexpr\
    \ typename decltype(seq_)::const_iterator end() const noexcept {\n        return\
    \ seq_.end();\n    }\n\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Number/IntegerDivision.hpp
  isVerificationFile: false
  path: Src/Number/EnumerateQuotients.hpp
  requiredBy: []
  timestamp: '2023-08-12 14:28:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc230_e.test.cpp
  - Test/AtCoder/abc132_f.test.cpp
  - Test/LC/enumerate_quotients.test.cpp
  - Test/My/Number/EnumerateQuotients/ceilBuild.test.cpp
  - Test/AOJ/2957.test.cpp
documentation_of: Src/Number/EnumerateQuotients.hpp
layout: document
title: "\u5546\u5217\u6319"
---

## 概要

正整数 $n$ に対して、 $n$ の商 $\frac{n}{i} (1\ \le\ i\ \le\ n)$ の切り捨て/切り上げの値、それに対応する $i$ の区間を保持します。


## ライブラリの使い方

#### テンプレート引数

```cpp
template <class Value>
```

$n$ の型を指定します。

**制約**: `Value`は**符号無し整数型**である必要がある

<br />

#### コンストラクタ

```cpp
(1) constexpr EnumerateQuotients() = default
(2) constexpr EnumerateQuotients(Value n, bool floor = true)
```

(1) 特に使用することを想定していない。`std::vector<EnumerateQuotients>`とかやりたくなった時用？

(2) $n$ に対して商を列挙する。`floor`を`true`にした場合、商の切り捨てが、`false`にした場合は商の切り上げが保持される。
- 切り上げの方は競プロの問題でverifyしていない(募: verifyに使える問題)
- デフォルトでは`true`が設定されているため、何もしていされなければ`floor`の方で計算される

**計算量**: $O(\sqrt{n})$

<br />

#### n

```cpp
constexpr Value n() const noexcept
```

$n$ を返す。

**計算量**: 定数時間

<br />

#### operator[]

```cpp
constexpr Data operator[](u32 i) const noexcept
```
$i + 1$ 番目に大きい商の情報にアクセスする。

`Data`とは以下のようなクラスです。

```cpp
class Data {
private:
public:
    constexpr Value quotient() const noexcept // 商を返す
    constexpr Value l() const noexcept // (n / i) = quotient()となる最小のiを返す。
    constexpr Value r() const noexcept // (n / i) < quotient()となる最小のiを返す。
    constexpr std::pair<Value, Value> range() const noexcept // (l, r)をstd::pair型で返す。
    constexpr Value len() const noexcept // (n / i) = quotient()となるiの数を返す。(r() - l())と等価
}
```

**制約**: `i < size()` (`size()`は後述するメンバで、商の数)

**計算量**: 定数時間

<br />

#### quotient

```cpp
constexpr Value quotient(u32 i) const noexcept
```

$i + 1$ 番目に大きい商にアクセスする。

**制約**: `i < size()`

**計算量**: 定数時間

<br />

#### l

```cpp
constexpr Value l(u32 i) const noexcept
```

$i + 1$ 番目に大きい商 $x$ について、 $\frac{n}{i} = x$ となる最小の $i$ を返す。

**制約**: `i < size()`

**計算量**: 定数時間

<br />


#### r

```cpp
constexpr Value r(u32 i) const noexcept
```

$i + 1$ 番目に大きい商 $x$ について、 $\frac{n}{i} < x$ となる最小の $i$ を返す。

**制約**: `i < size()`

**計算量**: 定数時間

<br />

#### len

```cpp
constexpr Value len(u32 i) const noexcept
```

$i + 1$ 番目に大きい商 $x$ について、 $\frac{n}{i} = x$ となる $i$ の数を返す。

**制約**: `i < size()`

**計算量**: 定数時間

<br />

#### size

```cpp
constexpr usize size() const noexcept
```

商の数を返す。

**計算量**: 定数時間

<br />

#### begin

```cpp
constexpr typename decltype(seq_)::const_iterator begin() const noexcept
```

最大の商の情報を持つ`const_iterator`を返します。

**計算量**: 定数時間

<br />

#### end

```cpp
constexpr typename decltype(seq_)::const_iterator end() const noexcept
```

最小の商の情報を持つ情報の次の`const_iterator`を返します。

**計算量**: 定数時間

<br />

#### begin endの役割

```cpp
EnumerateQuotients eq(n);
for (const auto& e : eq) {

}
```

とすることで、商の大きい順に商を保持する`Data`にアクセスすることができます。

<br />

## アルゴリズム

一般に正整数 $n$ と $i = 1, 2, \dots, n - 1, n$ に対して、 $\lfloor \frac{n}{i}\rfloor$ の種類数は $O(\sqrt{n})$ 個に抑えられます。

なぜなら $\lfloor \frac{n}{i}\rfloor > \sqrt{n}$ を満たす $i$ は $\sqrt{n}$ 以下であり、かつ $\sqrt{n}$ 以上の $i$ について $\lfloor \frac{n}{i}\rfloor\ \le\ \sqrt{n}$ が成り立つからです。

なので、順にそれを取得しているだけです。

<br />

#### Appendix

- [https://nyaannyaan.github.io/library/multiplicative-function/prime-counting-faster.hpp](https://nyaannyaan.github.io/library/multiplicative-function/prime-counting-faster.hpp
)
- [https://twitter.com/yosupot/status/1624735126163980289](https://twitter.com/yosupot/status/1624735126163980289)

$N\ \le\ 10^{12}$ 程度なら、除算は`double`型で行った方が(十分な精度を持ちながらも)速いという話がある。(`zawa::EnumerateQuotients`では採用していない)
