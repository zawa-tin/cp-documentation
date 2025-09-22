---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/SupersetTransform.hpp
    title: "Superset Zeta/Mobius Transform ( $\\emptyset$ \u306E\u65B9\u3078\u96C6\
      \u3081\u308B\u3084\u3064 )"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/bitwise_and_convolution.test.cpp
    title: Test/LC/bitwise_and_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Sequence/BitwiseAndConvolution.hpp\"\n\n#line 2 \"Src/Sequence/SupersetTransform.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Sequence/SupersetTransform.hpp\"\
    \n\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class T>\nvoid SupersetZetaTransform(usize\
    \ n, std::vector<T>& a) {\n    for (usize i = 0 ; i < n ; i++)\n        for (usize\
    \ b = ssize(a) ; b-- ; )\n            if (b & (usize{1} << i))\n             \
    \   a[b ^ (usize{1} << i)] += a[b];\n}\n\ntemplate <class T>\nvoid SupersetMobiusTransform(usize\
    \ n, std::vector<T>& a) {\n    for (usize i = 0 ; i < n ; i++)\n        for (usize\
    \ b = ssize(a) ; b-- ; )\n            if (b & (usize{1} << i))\n             \
    \   a[b ^ (usize{1} << i)] -= a[b];\n}\n\n} // namespace zawa\n#line 4 \"Src/Sequence/BitwiseAndConvolution.hpp\"\
    \n\n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <utility>\n\
    #line 10 \"Src/Sequence/BitwiseAndConvolution.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nstd::vector<T> BitwiseAndConvolution(std::vector<T> a, std::vector<T>\
    \ b) {\n    assert(a.size() and b.size());\n    const usize n = std::bit_width(std::max(a.size(),\
    \ b.size()) - 1);\n    a.resize(1 << n);\n    b.resize(1 << n);\n    SupersetZetaTransform(n,\
    \ a);\n    SupersetZetaTransform(n, b);\n    for (usize i = 0 ; i < (usize{1}\
    \ << n) ; i++)\n        a[i] *= b[i];\n    SupersetMobiusTransform(n, a);\n  \
    \  return a;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"SupersetTransform.hpp\"\n\n#include <algorithm>\n\
    #include <bit>\n#include <cassert>\n#include <utility>\n#include <vector>\n\n\
    namespace zawa {\n\ntemplate <class T>\nstd::vector<T> BitwiseAndConvolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    assert(a.size() and b.size());\n    const usize\
    \ n = std::bit_width(std::max(a.size(), b.size()) - 1);\n    a.resize(1 << n);\n\
    \    b.resize(1 << n);\n    SupersetZetaTransform(n, a);\n    SupersetZetaTransform(n,\
    \ b);\n    for (usize i = 0 ; i < (usize{1} << n) ; i++)\n        a[i] *= b[i];\n\
    \    SupersetMobiusTransform(n, a);\n    return a;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Sequence/SupersetTransform.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Sequence/BitwiseAndConvolution.hpp
  requiredBy: []
  timestamp: '2025-09-23 00:58:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/bitwise_and_convolution.test.cpp
documentation_of: Src/Sequence/BitwiseAndConvolution.hpp
layout: document
redirect_from:
- /library/Src/Sequence/BitwiseAndConvolution.hpp
- /library/Src/Sequence/BitwiseAndConvolution.hpp.html
title: Src/Sequence/BitwiseAndConvolution.hpp
---
