---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/PrimeSubsetTransform.hpp
    title: Src/Number/PrimeSubsetTransform.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/lcm_convolution.test.cpp
    title: Test/LC/lcm_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Number/LCMConvolution.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/Number/PrimeSubsetTransform.hpp\"\n\n#line\
    \ 4 \"Src/Number/PrimeSubsetTransform.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa {\n\ntemplate <class T>\nvoid PrimeSubsetZetaTransform(std::vector<T>&\
    \ a) {\n    std::vector<bool> p(a.size(), true);\n    for (usize i = 2 ; i < a.size()\
    \ ; i++)\n        if (p[i]) {\n            for (usize j = i ; j < a.size() ; j\
    \ += i) {\n                p[j] = 0;\n                a[j] += a[j / i];\n    \
    \        }\n        }\n}\n\ntemplate <class T>\nvoid PrimeSubsetMobiusTransform(std::vector<T>&\
    \ a) {\n    std::vector<bool> p(a.size(), true);\n    for (usize i = 2 ; i < a.size()\
    \ ; i++)\n        if (p[i]) {\n            for (usize j = (a.size() - 1) / i *\
    \ i ; j >= i ; j -= i) {\n                p[j] = 0;\n                a[j] -= a[j\
    \ / i];\n            }\n        }\n}\n\n} // namespace zawa\n#line 5 \"Src/Number/LCMConvolution.hpp\"\
    \n\n#include <algorithm>\n#line 8 \"Src/Number/LCMConvolution.hpp\"\n\nnamespace\
    \ zawa {\n\ntemplate <class T>\nstd::vector<T> LCMConvolution(std::vector<T> a,\
    \ std::vector<T> b) {\n    const usize n = std::max(a.size(), b.size());\n   \
    \ a.resize(n);\n    b.resize(n);\n    PrimeSubsetZetaTransform(a);\n    PrimeSubsetZetaTransform(b);\n\
    \    for (usize i = 0 ; i < n ; i++)\n        a[i] *= b[i];\n    PrimeSubsetMobiusTransform(a);\n\
    \    return a;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"./PrimeSubsetTransform.hpp\"\
    \n\n#include <algorithm>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nstd::vector<T> LCMConvolution(std::vector<T> a, std::vector<T> b) {\n  \
    \  const usize n = std::max(a.size(), b.size());\n    a.resize(n);\n    b.resize(n);\n\
    \    PrimeSubsetZetaTransform(a);\n    PrimeSubsetZetaTransform(b);\n    for (usize\
    \ i = 0 ; i < n ; i++)\n        a[i] *= b[i];\n    PrimeSubsetMobiusTransform(a);\n\
    \    return a;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Number/PrimeSubsetTransform.hpp
  isVerificationFile: false
  path: Src/Number/LCMConvolution.hpp
  requiredBy: []
  timestamp: '2025-09-23 17:35:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/lcm_convolution.test.cpp
documentation_of: Src/Number/LCMConvolution.hpp
layout: document
redirect_from:
- /library/Src/Number/LCMConvolution.hpp
- /library/Src/Number/LCMConvolution.hpp.html
title: Src/Number/LCMConvolution.hpp
---
