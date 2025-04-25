---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/ArrayIO.hpp
    title: "std::array\u306E\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/PairIO.hpp
    title: "std::pair\u306E\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Template/VectorIO.hpp
    title: "std::vector\u306E\u5165\u51FA\u529B"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/ITP1_1_A.test.cpp
    title: Test/AOJ/ITP1_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc236_e.test.cpp
    title: Test/AtCoder/abc236_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc293_b.test.cpp
    title: Test/AtCoder/abc293_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/many_aplusb.test.cpp
    title: Test/LC/many_aplusb.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Template/Output.hpp\"\n\n#line 2 \"Src/Template/ArrayIO.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Template/ArrayIO.hpp\"\
    \n\n#include <iostream>\n#include <array>\n\nnamespace zawa {\n\ntemplate <class\
    \ T, usize N>\nstd::istream &operator>>(std::istream& is, std::array<T, N>& A)\
    \ {\n    for (T& a : A) {\n        is >> a;\n    }\n    return is;\n}\n\ntemplate\
    \ <class T, usize N>\nstd::ostream &operator<<(std::ostream& os, const std::array<T,\
    \ N>& A) {\n    for (u32 i{} ; i < A.size() ; i++) {\n        os << A[i] << (i\
    \ + 1 == A.size() ? \"\" : \" \");\n    }\n    return os;\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Template/VectorIO.hpp\"\n\n#line 4 \"Src/Template/VectorIO.hpp\"\
    \n\n#line 6 \"Src/Template/VectorIO.hpp\"\n#include <vector>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nstd::istream &operator>>(std::istream& is, std::vector<T>&\
    \ A) {\n    for (T& a : A) {\n        is >> a;\n    }\n    return is;\n}\n\ntemplate\
    \ <class T>\nstd::ostream &operator<<(std::ostream& os, const std::vector<T>&\
    \ A) {\n    for (u32 i{} ; i < A.size() ; i++) {\n        os << A[i] << (i + 1\
    \ == A.size() ? \"\" : \" \");\n    }\n    return os;\n}\n\n} // namespace zawa\n\
    #line 2 \"Src/Template/PairIO.hpp\"\n\n#line 4 \"Src/Template/PairIO.hpp\"\n\n\
    #line 6 \"Src/Template/PairIO.hpp\"\n#include <utility>\n\nnamespace zawa {\n\n\
    template <class T1, class T2>\nstd::istream &operator>>(std::istream& is, std::pair<T1,\
    \ T2>& P) {\n    is >> P.first >> P.second;\n    return is;\n}\n\ntemplate <class\
    \ T1, class T2>\nstd::ostream &operator<<(std::ostream& os, const std::pair<T1,\
    \ T2>& P) {\n    os << '(' << P.first << ',' << P.second << ')';\n    return os;\n\
    }\n\n} // namespace zawa\n#line 6 \"Src/Template/Output.hpp\"\n\n#line 8 \"Src/Template/Output.hpp\"\
    \n\nnamespace zawa {\n\nvoid out() {\n    std::cout << std::endl;\n}\n\ntemplate\
    \ <class T>\nvoid out(const T& value) {\n    std::cout << value << std::endl;\n\
    }\n\ntemplate <class Head, class... Tail>\nvoid out(const Head& head, const Tail&...\
    \ tail) {\n    std::cout << head;\n    if (sizeof...(tail)) {\n        std::cout\
    \ << ' ';\n    }\n    out(tail...);\n}\n\nvoid eout() {\n    std::cerr << std::endl;\n\
    }\n\ntemplate <class T>\nvoid eout(const T& value) {\n    std::cerr << value <<\
    \ std::endl;\n}\n\ntemplate <class Head, class... Tail>\nvoid eout(const Head&\
    \ head, const Tail&... tail) {\n    std::cerr << head;\n    if (sizeof...(tail))\
    \ {\n        std::cerr << ' ';\n    }\n    eout(tail...);\n}\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include \"./ArrayIO.hpp\"\n#include \"./VectorIO.hpp\"\n\
    #include \"./PairIO.hpp\"\n\n#include <iostream>\n\nnamespace zawa {\n\nvoid out()\
    \ {\n    std::cout << std::endl;\n}\n\ntemplate <class T>\nvoid out(const T& value)\
    \ {\n    std::cout << value << std::endl;\n}\n\ntemplate <class Head, class...\
    \ Tail>\nvoid out(const Head& head, const Tail&... tail) {\n    std::cout << head;\n\
    \    if (sizeof...(tail)) {\n        std::cout << ' ';\n    }\n    out(tail...);\n\
    }\n\nvoid eout() {\n    std::cerr << std::endl;\n}\n\ntemplate <class T>\nvoid\
    \ eout(const T& value) {\n    std::cerr << value << std::endl;\n}\n\ntemplate\
    \ <class Head, class... Tail>\nvoid eout(const Head& head, const Tail&... tail)\
    \ {\n    std::cerr << head;\n    if (sizeof...(tail)) {\n        std::cerr <<\
    \ ' ';\n    }\n    eout(tail...);\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/ArrayIO.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Template/VectorIO.hpp
  - Src/Template/PairIO.hpp
  isVerificationFile: false
  path: Src/Template/Output.hpp
  requiredBy: []
  timestamp: '2023-08-08 12:17:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/ITP1_1_A.test.cpp
  - Test/LC/many_aplusb.test.cpp
  - Test/AtCoder/abc293_b.test.cpp
  - Test/AtCoder/abc236_e.test.cpp
documentation_of: Src/Template/Output.hpp
layout: document
title: "\u6A19\u6E96\u51FA\u529B"
---

## 概要

標準出力を扱います。

## ライブラリの使い方

#### out

```cpp
(1) void out()
(2) void out(const T& value)
(3) void out(const Head& head, const Tail&... tail)
```

(1) `std::cout << std::endl`と等価です。

(2) `std::cout << value << std::endl`と等価です。

(3) 引数に入れた変数を空白区切りで出力します。最後に改行が入ります。

<br />

#### eout

```cpp
(1) void eout()
(2) void eout(const T& value)
(3) void eout(const Head& head, const Tail&... tail)
```

(1) `std::cerr << std::endl`と等価です。

(2) `std::cerr << value << std::endl;`と等価です。

(3) 引数に入れた変数を空白区切りで標準エラー出力します。最後に改行はいります。
