---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/ArrayIO.hpp
    title: "std::array\u306E\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/Input.hpp
    title: "\u6A19\u6E96\u5165\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/PairIO.hpp
    title: "std::pair\u306E\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Template/VectorIO.hpp
    title: "std::vector\u306E\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/YesNo.hpp
    title: "Yes\u304BNo\u3092\u51FA\u529B\u3059\u308B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc295/tasks/abc295_a
    links:
    - https://atcoder.jp/contests/abc295/tasks/abc295_a
  bundledCode: "#line 1 \"Test/AtCoder/abc295_a.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc295/tasks/abc295_a\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Template/Input.hpp\"\
    \n\n#line 2 \"Src/Template/ArrayIO.hpp\"\n\n#line 4 \"Src/Template/ArrayIO.hpp\"\
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
    }\n\n} // namespace zawa\n#line 6 \"Src/Template/Input.hpp\"\n\n#line 8 \"Src/Template/Input.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T>\nvoid input(T& value) {\n    std::cin\
    \ >> value;\n}\n\ntemplate <class Head, class... Tail>\nvoid input(Head& head,\
    \ Tail&... tail) {\n    input(head);\n    input(tail...);\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Template/YesNo.hpp\"\n\n#include <string>\n#line 5 \"Src/Template/YesNo.hpp\"\
    \n\nnamespace zawa {\n\nnamespace internal {\n\nstd::string yes{\"Yes\"};\nstd::string\
    \ no{\"No\"};\n\n} // namespace internal\n\nvoid YesNo(bool answer) {\n    std::cout\
    \ << (answer ? internal::yes : internal::no) << std::endl;\n}\n\nvoid SetYes(const\
    \ std::string& yes) {\n    internal::yes = yes;\n}\n\nvoid SetNo(const std::string&\
    \ no) {\n    internal::no = no;\n}\n\nvoid SetAtCoderYesNo() {\n    SetYes(\"\
    Yes\");\n    SetNo(\"No\");\n}\n\nvoid SetCodeforcesYesNo() {\n    SetYes(\"YES\"\
    );\n    SetNo(\"NO\");\n}\n\n} // namespace zawa\n#line 6 \"Test/AtCoder/abc295_a.test.cpp\"\
    \n\nusing namespace zawa;\n\n#include <set>\n#line 11 \"Test/AtCoder/abc295_a.test.cpp\"\
    \n\nint main() {\n    SetAtCoderYesNo();\n    u32 N; input(N);\n    std::set<std::string>\
    \ st{ \"and\", \"not\", \"that\", \"the\", \"you\" };\n    bool ans{};\n    for\
    \ (u32 _{} ; _ < N ; _++) {\n        std::string w; input(w);\n        ans |=\
    \ st.count(w);\n    }\n    YesNo(ans);\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc295/tasks/abc295_a\"\n\n\
    #include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Template/Input.hpp\"\
    \n#include \"../../Src/Template/YesNo.hpp\"\n\nusing namespace zawa;\n\n#include\
    \ <set>\n#include <string>\n\nint main() {\n    SetAtCoderYesNo();\n    u32 N;\
    \ input(N);\n    std::set<std::string> st{ \"and\", \"not\", \"that\", \"the\"\
    , \"you\" };\n    bool ans{};\n    for (u32 _{} ; _ < N ; _++) {\n        std::string\
    \ w; input(w);\n        ans |= st.count(w);\n    }\n    YesNo(ans);\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Template/Input.hpp
  - Src/Template/ArrayIO.hpp
  - Src/Template/VectorIO.hpp
  - Src/Template/PairIO.hpp
  - Src/Template/YesNo.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc295_a.test.cpp
  requiredBy: []
  timestamp: '2023-08-08 12:55:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc295_a.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc295_a.test.cpp
- /verify/Test/AtCoder/abc295_a.test.cpp.html
title: Test/AtCoder/abc295_a.test.cpp
---
