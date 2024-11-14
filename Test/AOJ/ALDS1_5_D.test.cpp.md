---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/InversionNumber.hpp
    title: Src/Sequence/InversionNumber.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D
  bundledCode: "#line 1 \"Test/AOJ/ALDS1_5_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D\"\
    \n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Sequence/InversionNumber.hpp\"\n\n#line\
    \ 4 \"Src/Sequence/InversionNumber.hpp\"\n\n#include <cassert>\n#include <iterator>\n\
    #include <type_traits>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class\
    \ InputIterator>\nu64 InversionNumber(InputIterator first, InputIterator last)\
    \ {\n    assert((usize)std::distance(first, last) >= usize{0});\n    std::vector<std::remove_reference_t<decltype(*first)>>\
    \ A(first, last);\n    auto rec{[&](auto rec, usize L, usize R) -> u64 {\n   \
    \     if (R - L <= usize{1}) return 0; \n        usize M{(L + R) >> 1};\n    \
    \    u64 res{rec(rec, L, M) + rec(rec, M, R)};\n        std::vector<u64> tmp(R\
    \ - L);\n        usize i{L}, j{M}, k{};\n        while (i < M and j < R) {\n \
    \           if (A[i] <= A[j]) {\n                tmp[k++] = A[i++];\n        \
    \    }\n            else {\n                res += M - i;\n                tmp[k++]\
    \ = A[j++];\n            }\n        }\n        while (i < M) tmp[k++] = A[i++];\n\
    \        while (j < R) tmp[k++] = A[j++];\n        for (usize l{L} ; l < R ; l++)\
    \ {\n            A[l] = tmp[l - L];\n        }\n        return res;\n    }};\n\
    \    return rec(rec, usize{0}, usize{A.size()});\n}\n\ntemplate <class InputIterator>\n\
    bool InversionParity(InputIterator first, InputIterator last) {\n    assert((usize)std::distance(first,\
    \ last) >= usize{0});\n    std::vector<std::remove_reference_t<decltype(*first)>>\
    \ A(first, last);\n    auto rec{[&](auto rec, usize L, usize R) -> bool {\n  \
    \      if (R - L <= usize{1}) return 0; \n        usize M{(L + R) >> 1};\n   \
    \     bool res{rec(rec, L, M) != rec(rec, M, R)};\n        std::vector<u64> tmp(R\
    \ - L);\n        usize i{L}, j{M}, k{};\n        while (i < M and j < R) {\n \
    \           if (A[i] <= A[j]) {\n                tmp[k++] = A[i++];\n        \
    \    }\n            else {\n                res ^= (M - i) & 1;\n            \
    \    tmp[k++] = A[j++];\n            }\n        }\n        while (i < M) tmp[k++]\
    \ = A[i++];\n        while (j < R) tmp[k++] = A[j++];\n        for (usize l{L}\
    \ ; l < R ; l++) {\n            A[l] = tmp[l - L];\n        }\n        return\
    \ res;\n    }};\n    return rec(rec, usize{0}, usize{A.size()});\n}\n\n} // namespace\
    \ zawa\n#line 5 \"Test/AOJ/ALDS1_5_D.test.cpp\"\n\nusing namespace zawa;\n\nint\
    \ main() {\n    SetFastIO();\n    int N;\n    std::cin >> N;\n    std::vector<int>\
    \ A(N);\n    for (auto& a : A) std::cin >> a;\n    std::cout << InversionNumber(A.begin(),\
    \ A.end()) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D\"\
    \n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Sequence/InversionNumber.hpp\"\
    \n\nusing namespace zawa;\n\nint main() {\n    SetFastIO();\n    int N;\n    std::cin\
    \ >> N;\n    std::vector<int> A(N);\n    for (auto& a : A) std::cin >> a;\n  \
    \  std::cout << InversionNumber(A.begin(), A.end()) << '\\n';\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Sequence/InversionNumber.hpp
  isVerificationFile: true
  path: Test/AOJ/ALDS1_5_D.test.cpp
  requiredBy: []
  timestamp: '2024-07-09 02:49:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/ALDS1_5_D.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/ALDS1_5_D.test.cpp
- /verify/Test/AOJ/ALDS1_5_D.test.cpp.html
title: Test/AOJ/ALDS1_5_D.test.cpp
---