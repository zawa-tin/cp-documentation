---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/ArrayIO.hpp
    title: "std::array\u306E\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
  - icon: ':heavy_check_mark:'
    path: Src/Template/Input.hpp
    title: "\u6A19\u6E96\u5165\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/Output.hpp
    title: "\u6A19\u6E96\u51FA\u529B"
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb
    links:
    - https://judge.yosupo.jp/problem/many_aplusb
  bundledCode: "#line 1 \"Test/LC/many_aplusb.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Template/IOSetting.hpp\"\
    \n\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n#include <iomanip>\n\
    \nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Template/Input.hpp\"\n\n#line 2 \"Src/Template/ArrayIO.hpp\"\
    \n\n#line 4 \"Src/Template/ArrayIO.hpp\"\n\n#line 6 \"Src/Template/ArrayIO.hpp\"\
    \n#include <array>\n\nnamespace zawa {\n\ntemplate <class T, usize N>\nstd::istream\
    \ &operator>>(std::istream& is, std::array<T, N>& A) {\n    for (T& a : A) {\n\
    \        is >> a;\n    }\n    return is;\n}\n\ntemplate <class T, usize N>\nstd::ostream\
    \ &operator<<(std::ostream& os, const std::array<T, N>& A) {\n    for (u32 i{}\
    \ ; i < A.size() ; i++) {\n        os << A[i] << (i + 1 == A.size() ? \"\" : \"\
    \ \");\n    }\n    return os;\n}\n\n} // namespace zawa\n#line 2 \"Src/Template/VectorIO.hpp\"\
    \n\n#line 4 \"Src/Template/VectorIO.hpp\"\n\n#line 6 \"Src/Template/VectorIO.hpp\"\
    \n#include <vector>\n\nnamespace zawa {\n\ntemplate <class T>\nstd::istream &operator>>(std::istream&\
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
    \    return os;\n}\n\n} // namespace zawa\n#line 6 \"Src/Template/Input.hpp\"\n\
    \n#line 8 \"Src/Template/Input.hpp\"\n\nnamespace zawa {\n\ntemplate <class T>\n\
    void input(T& value) {\n    std::cin >> value;\n}\n\ntemplate <class Head, class...\
    \ Tail>\nvoid input(Head& head, Tail&... tail) {\n    input(head);\n    input(tail...);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Template/Output.hpp\"\n\n#line 6 \"Src/Template/Output.hpp\"\
    \n\n#line 8 \"Src/Template/Output.hpp\"\n\nnamespace zawa {\n\nvoid out() {\n\
    \    std::cout << std::endl;\n}\n\ntemplate <class T>\nvoid out(const T& value)\
    \ {\n    std::cout << value << std::endl;\n}\n\ntemplate <class Head, class...\
    \ Tail>\nvoid out(const Head& head, const Tail&... tail) {\n    std::cout << head;\n\
    \    if (sizeof...(tail)) {\n        std::cout << ' ';\n    }\n    out(tail...);\n\
    }\n\nvoid eout() {\n    std::cerr << std::endl;\n}\n\ntemplate <class T>\nvoid\
    \ eout(const T& value) {\n    std::cerr << value << std::endl;\n}\n\ntemplate\
    \ <class Head, class... Tail>\nvoid eout(const Head& head, const Tail&... tail)\
    \ {\n    std::cerr << head;\n    if (sizeof...(tail)) {\n        std::cerr <<\
    \ ' ';\n    }\n    eout(tail...);\n}\n\n} // namespace zawa\n#line 7 \"Test/LC/many_aplusb.test.cpp\"\
    \n\nusing namespace zawa;\n\nint main() {\n    SetFastIO();\n    SetPrecision(15);\n\
    \    u32 T; input(T);\n    for (u32 _{} ; _ < T ; _++) {\n        u64 A, B; input(A,\
    \ B);\n        out(A + B);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n\n#include\
    \ \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Template/IOSetting.hpp\"\
    \n#include \"../../Src/Template/Input.hpp\"\n#include \"../../Src/Template/Output.hpp\"\
    \n\nusing namespace zawa;\n\nint main() {\n    SetFastIO();\n    SetPrecision(15);\n\
    \    u32 T; input(T);\n    for (u32 _{} ; _ < T ; _++) {\n        u64 A, B; input(A,\
    \ B);\n        out(A + B);\n    }\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Template/IOSetting.hpp
  - Src/Template/Input.hpp
  - Src/Template/ArrayIO.hpp
  - Src/Template/VectorIO.hpp
  - Src/Template/PairIO.hpp
  - Src/Template/Output.hpp
  isVerificationFile: true
  path: Test/LC/many_aplusb.test.cpp
  requiredBy: []
  timestamp: '2023-08-08 12:59:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/many_aplusb.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/many_aplusb.test.cpp
- /verify/Test/LC/many_aplusb.test.cpp.html
title: Test/LC/many_aplusb.test.cpp
---
