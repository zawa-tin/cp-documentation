---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/ArrayIO.hpp
    title: "std::array\u306E\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/2/ITP1_2_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/2/ITP1_2_C
  bundledCode: "#line 1 \"Test/AOJ/ITP1_2_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/2/ITP1_2_C\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Template/ArrayIO.hpp\"\
    \n\n#line 4 \"Src/Template/ArrayIO.hpp\"\n\n#include <iostream>\n#include <array>\n\
    \nnamespace zawa {\n\ntemplate <class T, usize N>\nstd::istream &operator>>(std::istream&\
    \ is, std::array<T, N>& A) {\n    for (T& a : A) {\n        is >> a;\n    }\n\
    \    return is;\n}\n\ntemplate <class T, usize N>\nstd::ostream &operator<<(std::ostream&\
    \ os, const std::array<T, N>& A) {\n    for (u32 i{} ; i < A.size() ; i++) {\n\
    \        os << A[i] << (i + 1 == A.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\n\n} // namespace zawa\n#line 5 \"Test/AOJ/ITP1_2_C.test.cpp\"\n\n#line\
    \ 8 \"Test/AOJ/ITP1_2_C.test.cpp\"\n#include <utility>\n\nusing namespace zawa;\n\
    \nint main() {\n    std::array<u32, 3> a; std::cin >> a;\n    if (a[1] > a[2])\
    \ std::swap(a[1], a[2]);\n    if (a[0] > a[1]) std::swap(a[0], a[1]);\n    if\
    \ (a[1] > a[2]) std::swap(a[1], a[2]);\n    std::cout << a << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/2/ITP1_2_C\"\
    \n\n#include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Template/ArrayIO.hpp\"\
    \n\n#include <iostream>\n#include <array>\n#include <utility>\n\nusing namespace\
    \ zawa;\n\nint main() {\n    std::array<u32, 3> a; std::cin >> a;\n    if (a[1]\
    \ > a[2]) std::swap(a[1], a[2]);\n    if (a[0] > a[1]) std::swap(a[0], a[1]);\n\
    \    if (a[1] > a[2]) std::swap(a[1], a[2]);\n    std::cout << a << std::endl;\n\
    }\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Template/ArrayIO.hpp
  isVerificationFile: true
  path: Test/AOJ/ITP1_2_C.test.cpp
  requiredBy: []
  timestamp: '2023-08-05 04:55:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/ITP1_2_C.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/ITP1_2_C.test.cpp
- /verify/Test/AOJ/ITP1_2_C.test.cpp.html
title: Test/AOJ/ITP1_2_C.test.cpp
---
