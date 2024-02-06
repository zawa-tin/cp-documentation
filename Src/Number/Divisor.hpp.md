---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc272_g.test.cpp
    title: ABC172-G Yet Another mod M
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Number/Divisor.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Number/Divisor.hpp\"\n\n#include <cassert>\n\
    #include <type_traits>\n#include <vector>\n\nnamespace zawa {\n\n// @remark: \u7D04\
    \u6570\u306F\u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\u306A\u3044\ntemplate <class\
    \ T>\nstd::vector<T> Divisor(T v) {\n    assert(v > static_cast<T>(0));\n    std::vector<T>\
    \ res;\n    for (T i{1} ; i * i <= v ; i++) {\n        if (v % i) continue;\n\
    \        res.emplace_back(i);\n        if (i * i != v) {\n            res.emplace_back(v\
    \ / i);\n        }\n    }\n    return res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <cassert>\n\
    #include <type_traits>\n#include <vector>\n\nnamespace zawa {\n\n// @remark: \u7D04\
    \u6570\u306F\u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\u306A\u3044\ntemplate <class\
    \ T>\nstd::vector<T> Divisor(T v) {\n    assert(v > static_cast<T>(0));\n    std::vector<T>\
    \ res;\n    for (T i{1} ; i * i <= v ; i++) {\n        if (v % i) continue;\n\
    \        res.emplace_back(i);\n        if (i * i != v) {\n            res.emplace_back(v\
    \ / i);\n        }\n    }\n    return res;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Number/Divisor.hpp
  requiredBy: []
  timestamp: '2024-02-06 11:57:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Manual/abc272_g.test.cpp
documentation_of: Src/Number/Divisor.hpp
layout: document
title: "\u7D04\u6570\u5217\u6319"
---

## 概要

$O(\sqrt{v})$ の約数列挙

**約数はソートされていない！！！！！**

**vが0以下だとassertにひっかかる！！！！！**
