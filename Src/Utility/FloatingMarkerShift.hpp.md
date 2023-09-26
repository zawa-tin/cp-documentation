---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc191_d.test.cpp
    title: Test/AtCoder/abc191_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/agc047_a.test.cpp
    title: AGC047-A Integer Product
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Utility/FloatingMarkerShift.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Utility/FloatingMarkerShift.hpp\"\n\n#include\
    \ <string>\n#include <cassert>\n#include <limits>\n\nnamespace zawa {\n\ni64 FloatingMarkerShift(const\
    \ std::string& S, u32 shift) {\n    static i64 lim10{std::numeric_limits<i64>::max()\
    \ / 10};\n    assert(not S.empty());\n    i64 res{};\n    u32 moved{};\n    bool\
    \ start{};\n    bool minus{S[0] == '-'};\n    for (u32 i{(u32)minus} ; i < S.size()\
    \ ; i++) {\n        if (S[i] == '.') {\n            start = true;\n        }\n\
    \        else {\n            if (start) moved++;\n            assert(res < lim10);\n\
    \            res = res * 10;\n            assert(res < std::numeric_limits<i64>::max()\
    \ - (S[i] - '0'));\n            res += S[i] - '0';\n        }\n    }\n    assert(moved\
    \ <= shift);\n    while (moved < shift) {\n        moved++;\n        assert(res\
    \ < lim10);\n        res = res * 10;\n    }\n    if (minus) res *= -1;\n    return\
    \ res;\n}\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <string>\n\
    #include <cassert>\n#include <limits>\n\nnamespace zawa {\n\ni64 FloatingMarkerShift(const\
    \ std::string& S, u32 shift) {\n    static i64 lim10{std::numeric_limits<i64>::max()\
    \ / 10};\n    assert(not S.empty());\n    i64 res{};\n    u32 moved{};\n    bool\
    \ start{};\n    bool minus{S[0] == '-'};\n    for (u32 i{(u32)minus} ; i < S.size()\
    \ ; i++) {\n        if (S[i] == '.') {\n            start = true;\n        }\n\
    \        else {\n            if (start) moved++;\n            assert(res < lim10);\n\
    \            res = res * 10;\n            assert(res < std::numeric_limits<i64>::max()\
    \ - (S[i] - '0'));\n            res += S[i] - '0';\n        }\n    }\n    assert(moved\
    \ <= shift);\n    while (moved < shift) {\n        moved++;\n        assert(res\
    \ < lim10);\n        res = res * 10;\n    }\n    if (minus) res *= -1;\n    return\
    \ res;\n}\n\n}// namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Utility/FloatingMarkerShift.hpp
  requiredBy: []
  timestamp: '2023-08-11 15:55:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc191_d.test.cpp
  - Test/AtCoder/agc047_a.test.cpp
documentation_of: Src/Utility/FloatingMarkerShift.hpp
layout: document
title: "\u6587\u5B57\u5217\u3067\u53D7\u3051\u53D6\u3063\u305F\u5C0F\u6570\u309210\u500D\
  \u3057\u307E\u304F\u3063\u3066\u6574\u6570\u306B\u3059\u308B\u3084\u3064"
---

## 概要

文字列で受け取った小数を $10^t$ 倍して小数点を除去した整数にして返します。

引数は文字列 (`std::string`)である必要があります。


## ライブラリの使い方

```cpp
i64 FloatingMarkerShift(const std::string& S, u32 shift)
```

#### 引数

```cpp
const std::string& S
```
文字列として受け取った小数。

```cpp
u32 shift
```

小数点を右に何回ずらすかを指定する。`S`に対して`shift`回右に小数点をずらしても小数点以下が $0$ で無い場合はassertにひっかかって死ぬ
- 整数にして返すことを前提にしているので

<br />

#### 返り値

計算結果。符号付き`64`bit整数。

<br />

## 例

```cpp
FloatingMarkerShift("1.23", 3) // 1230
FloatingMarkerShift("-0.01", 2) // -1
```

<br />

## 必要になった経緯

[例えばこの問題](https://atcoder.jp/contests/abc191/tasks/abc191_d) 等で、浮動小数点型で入力を受け取ってそのまま $10$ 倍していって整数にした場合、誤差で死ぬ。
- ちょっと掛け算したくらいで...って感じてしまうが、浮動小数点型は $2$ 進数で値を保持していることを考えるとまぁ仕方ない話なのかもしれない。

逆に、 $2$ 進数で値を保持しているということは $2$ 倍や $2$ で割るのにはかなり強(いらし)く、 [例えばこの問題](https://atcoder.jp/contests/abc011/tasks/abc011_d) では許容誤差が $10^{-9}$ とかなり厳しいが小数点以下が絡む割り算が $4$ しか無いので愚直にやっても普通にACが出た。 
