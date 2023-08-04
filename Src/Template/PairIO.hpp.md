---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Template/Input.hpp
    title: "\u6A19\u6E96\u5165\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/Output.hpp
    title: "\u6A19\u6E96\u51FA\u529B"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/ITP1_1_C.test.cpp
    title: Test/AOJ/ITP1_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc293_b.test.cpp
    title: Test/AtCoder/abc293_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc295_a.test.cpp
    title: Test/AtCoder/abc295_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Template/PairIO.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/PairIO.hpp\"\n\n#include <iostream>\n\
    #include <utility>\n\nnamespace zawa {\n\ntemplate <class T1, class T2>\nstd::istream\
    \ &operator>>(std::istream& is, std::pair<T1, T2>& P) {\n    is >> P.first >>\
    \ P.second;\n    return is;\n}\n\ntemplate <class T1, class T2>\nstd::ostream\
    \ &operator<<(std::ostream& os, const std::pair<T1, T2>& P) {\n    os << '(' <<\
    \ P.first << ',' << P.second << ')';\n    return os;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"./TypeAlias.hpp\"\n\n#include <iostream>\n#include\
    \ <utility>\n\nnamespace zawa {\n\ntemplate <class T1, class T2>\nstd::istream\
    \ &operator>>(std::istream& is, std::pair<T1, T2>& P) {\n    is >> P.first >>\
    \ P.second;\n    return is;\n}\n\ntemplate <class T1, class T2>\nstd::ostream\
    \ &operator<<(std::ostream& os, const std::pair<T1, T2>& P) {\n    os << '(' <<\
    \ P.first << ',' << P.second << ')';\n    return os;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Template/PairIO.hpp
  requiredBy:
  - Src/Template/Output.hpp
  - Src/Template/Input.hpp
  timestamp: '2023-08-05 05:25:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc295_a.test.cpp
  - Test/AtCoder/abc293_b.test.cpp
  - Test/AOJ/ITP1_1_C.test.cpp
documentation_of: Src/Template/PairIO.hpp
layout: document
title: "std::pair\u306E\u5165\u51FA\u529B"
---

## 概要

`std::pair`に対する入出力を定義しています。
- `T1 T2`にはプリミティブ型であることを想定しています
- 出力は`(first,second)`の形で出力されます。(あくまでデバッグ目的であり、解答の出力に利用することを想定していません)
