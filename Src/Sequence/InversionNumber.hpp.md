---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/ALDS1_5_D.test.cpp
    title: Test/AOJ/ALDS1_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc261_f.test.cpp
    title: Test/AtCoder/abc261_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc296_f.test.cpp
    title: "ABC296-F Simultaneous Swap (\u4E92\u63DB\u306F\u5947\u6570\u56DE\u306E\
      \u96A3\u63A5swap)"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Sequence/InversionNumber.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Sequence/InversionNumber.hpp\"\n\n#include\
    \ <cassert>\n#include <iterator>\n#include <type_traits>\n#include <vector>\n\n\
    namespace zawa {\n\ntemplate <class InputIterator>\nu64 InversionNumber(InputIterator\
    \ first, InputIterator last) {\n    assert((usize)std::distance(first, last) >=\
    \ usize{0});\n    std::vector<std::remove_reference_t<decltype(*first)>> A(first,\
    \ last);\n    auto rec{[&](auto rec, usize L, usize R) -> u64 {\n        if (R\
    \ - L <= usize{1}) return 0; \n        usize M{(L + R) >> 1};\n        u64 res{rec(rec,\
    \ L, M) + rec(rec, M, R)};\n        std::vector<u64> tmp(R - L);\n        usize\
    \ i{L}, j{M}, k{};\n        while (i < M and j < R) {\n            if (A[i] <=\
    \ A[j]) {\n                tmp[k++] = A[i++];\n            }\n            else\
    \ {\n                res += M - i;\n                tmp[k++] = A[j++];\n     \
    \       }\n        }\n        while (i < M) tmp[k++] = A[i++];\n        while\
    \ (j < R) tmp[k++] = A[j++];\n        for (usize l{L} ; l < R ; l++) {\n     \
    \       A[l] = tmp[l - L];\n        }\n        return res;\n    }};\n    return\
    \ rec(rec, usize{0}, usize{A.size()});\n}\n\ntemplate <class InputIterator>\n\
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
    \ zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <cassert>\n\
    #include <iterator>\n#include <type_traits>\n#include <vector>\n\nnamespace zawa\
    \ {\n\ntemplate <class InputIterator>\nu64 InversionNumber(InputIterator first,\
    \ InputIterator last) {\n    assert((usize)std::distance(first, last) >= usize{0});\n\
    \    std::vector<std::remove_reference_t<decltype(*first)>> A(first, last);\n\
    \    auto rec{[&](auto rec, usize L, usize R) -> u64 {\n        if (R - L <= usize{1})\
    \ return 0; \n        usize M{(L + R) >> 1};\n        u64 res{rec(rec, L, M) +\
    \ rec(rec, M, R)};\n        std::vector<u64> tmp(R - L);\n        usize i{L},\
    \ j{M}, k{};\n        while (i < M and j < R) {\n            if (A[i] <= A[j])\
    \ {\n                tmp[k++] = A[i++];\n            }\n            else {\n \
    \               res += M - i;\n                tmp[k++] = A[j++];\n          \
    \  }\n        }\n        while (i < M) tmp[k++] = A[i++];\n        while (j <\
    \ R) tmp[k++] = A[j++];\n        for (usize l{L} ; l < R ; l++) {\n          \
    \  A[l] = tmp[l - L];\n        }\n        return res;\n    }};\n    return rec(rec,\
    \ usize{0}, usize{A.size()});\n}\n\ntemplate <class InputIterator>\nbool InversionParity(InputIterator\
    \ first, InputIterator last) {\n    assert((usize)std::distance(first, last) >=\
    \ usize{0});\n    std::vector<std::remove_reference_t<decltype(*first)>> A(first,\
    \ last);\n    auto rec{[&](auto rec, usize L, usize R) -> bool {\n        if (R\
    \ - L <= usize{1}) return 0; \n        usize M{(L + R) >> 1};\n        bool res{rec(rec,\
    \ L, M) != rec(rec, M, R)};\n        std::vector<u64> tmp(R - L);\n        usize\
    \ i{L}, j{M}, k{};\n        while (i < M and j < R) {\n            if (A[i] <=\
    \ A[j]) {\n                tmp[k++] = A[i++];\n            }\n            else\
    \ {\n                res ^= (M - i) & 1;\n                tmp[k++] = A[j++];\n\
    \            }\n        }\n        while (i < M) tmp[k++] = A[i++];\n        while\
    \ (j < R) tmp[k++] = A[j++];\n        for (usize l{L} ; l < R ; l++) {\n     \
    \       A[l] = tmp[l - L];\n        }\n        return res;\n    }};\n    return\
    \ rec(rec, usize{0}, usize{A.size()});\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Sequence/InversionNumber.hpp
  requiredBy: []
  timestamp: '2024-07-09 02:49:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc296_f.test.cpp
  - Test/AtCoder/abc261_f.test.cpp
  - Test/AOJ/ALDS1_5_D.test.cpp
documentation_of: Src/Sequence/InversionNumber.hpp
layout: document
redirect_from:
- /library/Src/Sequence/InversionNumber.hpp
- /library/Src/Sequence/InversionNumber.hpp.html
title: Src/Sequence/InversionNumber.hpp
---
