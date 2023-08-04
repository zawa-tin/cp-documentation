---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/ITP2_4_A.test.cpp
    title: Test/AOJ/ITP2_4_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Template/VectorIO.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/VectorIO.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nnamespace zawa {\n\ntemplate <class T>\nstd::istream &operator>>(std::istream&\
    \ is, std::vector<T>& A) {\n    for (T& a : A) {\n        is >> a;\n    }\n  \
    \  return is;\n}\n\ntemplate <class T>\nstd::ostream &operator<<(std::ostream&\
    \ os, const std::vector<T>& A) {\n    for (u32 i{} ; i < A.size() ; i++) {\n \
    \       os << A[i] << (i + 1 == A.size() ? \"\" : \" \");\n    }\n    return os;\n\
    }\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"./TypeAlias.hpp\"\n\n#include <iostream>\n#include\
    \ <vector>\n\nnamespace zawa {\n\ntemplate <class T>\nstd::istream &operator>>(std::istream&\
    \ is, std::vector<T>& A) {\n    for (T& a : A) {\n        is >> a;\n    }\n  \
    \  return is;\n}\n\ntemplate <class T>\nstd::ostream &operator<<(std::ostream&\
    \ os, const std::vector<T>& A) {\n    for (u32 i{} ; i < A.size() ; i++) {\n \
    \       os << A[i] << (i + 1 == A.size() ? \"\" : \" \");\n    }\n    return os;\n\
    }\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Template/VectorIO.hpp
  requiredBy: []
  timestamp: '2023-08-05 04:55:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/ITP2_4_A.test.cpp
documentation_of: Src/Template/VectorIO.hpp
layout: document
title: "std::vector\u306E\u5165\u51FA\u529B"
---

## 概要

`std::vector`に対する入出力を定義しています。
- 1次元`vector`に対する利用を想定しています。
