---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/ArrayIO.hpp
    title: "std::array\u306E\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/Output.hpp
    title: "\u6A19\u6E96\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/PairIO.hpp
    title: "std::pair\u306E\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/SupInf.hpp
    title: "sup inf\u5909\u6570"
  - icon: ':question:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Template/VectorIO.hpp
    title: "std::vector\u306E\u5165\u51FA\u529B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AOJ/ITP1_1_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/Template/SupInf.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/SupInf.hpp\"\n\nnamespace zawa {\n\
    \ni32 supi{ (1 << 30) - 1 };\ni64 supl{ (1LL << 62) - 1 };\ni32 infi{ -supi };\n\
    i64 infl{ -supl };\n\nvoid SetSupi(i32 value) {\n    supi = value;\n}\n\nvoid\
    \ SetSupl(i64 value) {\n    supl = value;\n}\n\nvoid SetInfi(i32 value) {\n  \
    \  infi = value;\n}\n\nvoid SetInfl(i64 value) {\n    infl = value;\n}\n\n} //\
    \ namespace zawa\n#line 2 \"Src/Template/Output.hpp\"\n\n#line 2 \"Src/Template/ArrayIO.hpp\"\
    \n\n#line 4 \"Src/Template/ArrayIO.hpp\"\n\n#include <iostream>\n#include <array>\n\
    \nnamespace zawa {\n\ntemplate <class T, usize N>\nstd::istream &operator>>(std::istream&\
    \ is, std::array<T, N>& A) {\n    for (T& a : A) {\n        is >> a;\n    }\n\
    \    return is;\n}\n\ntemplate <class T, usize N>\nstd::ostream &operator<<(std::ostream&\
    \ os, const std::array<T, N>& A) {\n    for (u32 i{} ; i < A.size() ; i++) {\n\
    \        os << A[i] << (i + 1 == A.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\n\n} // namespace zawa\n#line 2 \"Src/Template/VectorIO.hpp\"\n\n#line\
    \ 4 \"Src/Template/VectorIO.hpp\"\n\n#line 6 \"Src/Template/VectorIO.hpp\"\n#include\
    \ <vector>\n\nnamespace zawa {\n\ntemplate <class T>\nstd::istream &operator>>(std::istream&\
    \ is, std::vector<T>& A) {\n    for (T& a : A) {\n        is >> a;\n    }\n  \
    \  return is;\n}\n\ntemplate <class T>\nstd::ostream &operator<<(std::ostream&\
    \ os, const std::vector<T>& A) {\n    for (u32 i{} ; i < A.size() ; i++) {\n \
    \       os << A[i] << (i + 1 == A.size() ? \"\" : \" \");\n    }\n    return os;\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Template/PairIO.hpp\"\n\n#line 4 \"Src/Template/PairIO.hpp\"\
    \n\n#line 6 \"Src/Template/PairIO.hpp\"\n#include <utility>\n\nnamespace zawa\
    \ {\n\ntemplate <class T1, class T2>\nstd::istream &operator>>(std::istream& is,\
    \ std::pair<T1, T2>& P) {\n    is >> P.first >> P.second;\n    return is;\n}\n\
    \ntemplate <class T1, class T2>\nstd::ostream &operator<<(std::ostream& os, const\
    \ std::pair<T1, T2>& P) {\n    os << '(' << P.first << ',' << P.second << ')';\n\
    \    return os;\n}\n\n} // namespace zawa\n#line 6 \"Src/Template/Output.hpp\"\
    \n\n#line 8 \"Src/Template/Output.hpp\"\n\nnamespace zawa {\n\nvoid Cout() {\n\
    \    std::cout << std::endl;\n}\n\ntemplate <class T>\nvoid Cout(const T& value)\
    \ {\n    std::cout << value;\n}\n\ntemplate <class Head, class... Tail>\nvoid\
    \ Cout(const Head& head, const Tail&... tail) {\n    std::cout << head;\n    if\
    \ (sizeof...(tail)) {\n        std::cout << ' ';\n        Cout(tail...);\n   \
    \ }\n}\n\nvoid Eout() {\n    std::cerr << std::endl;\n}\n\ntemplate <class T>\n\
    void Eout(const T& value) {\n    std::cerr << value;\n}\n\ntemplate <class Head,\
    \ class... Tail>\nvoid Eout(const Head& head, const Tail&... tail) {\n    std::cerr\
    \ << head;\n    if (sizeof...(tail)) {\n        std::cerr << ' ';\n        Eout(tail...);\n\
    \    }\n}\n\n} // namespace zawa\n#line 5 \"Test/AOJ/ITP1_1_A.test.cpp\"\n\nusing\
    \ namespace zawa;\n\nint main() {\n    Eout(supi); Eout();\n    Eout(supl); Eout();\n\
    \    Eout(infi); Eout();\n    Eout(infl); Eout();\n    SetSupi(100);\n    Eout(supi);\
    \ Eout();\n    Cout(\"Hello World\"); Cout();\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/Template/SupInf.hpp\"\n#include \"../../Src/Template/Output.hpp\"\
    \n\nusing namespace zawa;\n\nint main() {\n    Eout(supi); Eout();\n    Eout(supl);\
    \ Eout();\n    Eout(infi); Eout();\n    Eout(infl); Eout();\n    SetSupi(100);\n\
    \    Eout(supi); Eout();\n    Cout(\"Hello World\"); Cout();\n}\n"
  dependsOn:
  - Src/Template/SupInf.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Template/Output.hpp
  - Src/Template/ArrayIO.hpp
  - Src/Template/VectorIO.hpp
  - Src/Template/PairIO.hpp
  isVerificationFile: true
  path: Test/AOJ/ITP1_1_A.test.cpp
  requiredBy: []
  timestamp: '2023-08-05 12:58:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/ITP1_1_A.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/ITP1_1_A.test.cpp
- /verify/Test/AOJ/ITP1_1_A.test.cpp.html
title: Test/AOJ/ITP1_1_A.test.cpp
---
