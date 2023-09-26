---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/ITP1_1_A.test.cpp
    title: Test/AOJ/ITP1_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Template/SupInf.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/SupInf.hpp\"\n\nnamespace zawa {\n\
    \ni32 supi{ (1 << 30) - 1 };\ni64 supl{ (1LL << 62) - 1 };\ni32 infi{ -supi };\n\
    i64 infl{ -supl };\n\nvoid SetSupi(i32 value) {\n    supi = value;\n}\n\nvoid\
    \ SetSupl(i64 value) {\n    supl = value;\n}\n\nvoid SetInfi(i32 value) {\n  \
    \  infi = value;\n}\n\nvoid SetInfl(i64 value) {\n    infl = value;\n}\n\n} //\
    \ namespace zawa\n"
  code: "#pragma once\n\n#include \"./TypeAlias.hpp\"\n\nnamespace zawa {\n\ni32 supi{\
    \ (1 << 30) - 1 };\ni64 supl{ (1LL << 62) - 1 };\ni32 infi{ -supi };\ni64 infl{\
    \ -supl };\n\nvoid SetSupi(i32 value) {\n    supi = value;\n}\n\nvoid SetSupl(i64\
    \ value) {\n    supl = value;\n}\n\nvoid SetInfi(i32 value) {\n    infi = value;\n\
    }\n\nvoid SetInfl(i64 value) {\n    infl = value;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Template/SupInf.hpp
  requiredBy: []
  timestamp: '2023-08-05 12:58:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/ITP1_1_A.test.cpp
documentation_of: Src/Template/SupInf.hpp
layout: document
title: "sup inf\u5909\u6570"
---

## 概要

適当な初期値として利用できる`sup`と`inf`を提供します。

#### ライブラリの使い方

```cpp
i32 supi;
i32 infi;
i64 supl;
i64 infl;

void SetSupi(i32)
void SetInfi(i32)
void SetSupl(i64)
void SetInfl(i64)
```

それぞれ`i32`型と`i64`型で`sup`と`inf`を提供します。予め`Set...`でこれらの値を各自設定することを想定しています。
- デフォルトでは、 $2^{30} - 1$ と $2^{62} - 1$ となっています。
