---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/CompressedSequence.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
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
    PROBLEM: https://atcoder.jp/contests/abc213/tasks/abc213_c
    links:
    - https://atcoder.jp/contests/abc213/tasks/abc213_c
  bundledCode: "#line 1 \"Test/AtCoder/abc213_c.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc213/tasks/abc213_c\"\
    \n\n#line 2 \"Src/Sequence/CompressedSequence.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Sequence/CompressedSequence.hpp\"\n\n#include\
    \ <vector>\n#include <algorithm>\n#include <cassert>\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nclass CompressedSequence {\nprivate:\n    std::vector<T> comped;\n\
    \    std::vector<u32> f;\n    \npublic:\n    CompressedSequence() = default;\n\
    \    CompressedSequence(const std::vector<T>& A) : comped(A), f(A.size()) {\n\
    \        std::sort(comped.begin(), comped.end());\n        comped.erase(std::unique(comped.begin(),\
    \ comped.end()), comped.end());\n        comped.shrink_to_fit();\n        f.shrink_to_fit();\n\
    \        for (u32 i = 0 ; i < A.size() ; i++) {\n            f[i] = std::lower_bound(comped.begin(),\
    \ comped.end(), A[i]) - comped.begin();\n        }\n    }     \n\n    inline usize\
    \ size() const {\n        return comped.size();\n    }\n\n    u32 operator[](const\
    \ T& v) const {\n        return std::lower_bound(comped.begin(), comped.end(),\
    \ v) - comped.begin();\n    }\n\n    inline u32 map(u32 i) const {\n        assert(i\
    \ < f.size());\n        return f[i];\n    }\n};\n\n} // namespace zawa\n#line\
    \ 5 \"Test/AtCoder/abc213_c.test.cpp\"\n\n#include <iostream>\n#line 8 \"Test/AtCoder/abc213_c.test.cpp\"\
    \n\nusing namespace zawa;\n\ni32 main() {\n    usize H, W, N;\n    std::cin >>\
    \ H >> W >> N; \n    std::vector<u32> A(N), B(N);\n    for (u32 i = 0 ; i < N\
    \ ; i++) {\n        std::cin >> A[i] >> B[i];\n    }\n\n    CompressedSequence\
    \ compY(A), compX(B);\n    for (u32 i = 0 ; i < N ; i++) {\n        std::cout\
    \ << compY.map(i) + 1 << ' ' << compX.map(i) + 1 << std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc213/tasks/abc213_c\"\n\n\
    #include \"../../Src/Sequence/CompressedSequence.hpp\"\n#include \"../../Src/Template/TypeAlias.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nusing namespace zawa;\n\ni32 main()\
    \ {\n    usize H, W, N;\n    std::cin >> H >> W >> N; \n    std::vector<u32> A(N),\
    \ B(N);\n    for (u32 i = 0 ; i < N ; i++) {\n        std::cin >> A[i] >> B[i];\n\
    \    }\n\n    CompressedSequence compY(A), compX(B);\n    for (u32 i = 0 ; i <\
    \ N ; i++) {\n        std::cout << compY.map(i) + 1 << ' ' << compX.map(i) + 1\
    \ << std::endl;\n    }\n}\n"
  dependsOn:
  - Src/Sequence/CompressedSequence.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc213_c.test.cpp
  requiredBy: []
  timestamp: '2023-06-07 04:27:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc213_c.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc213_c.test.cpp
- /verify/Test/AtCoder/abc213_c.test.cpp.html
title: Test/AtCoder/abc213_c.test.cpp
---
