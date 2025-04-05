---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Test/yukicoder/3090.cpp
    title: Test/yukicoder/3090.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Utility/MisereNim.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Utility/MisereNim.hpp\"\n\n#include <concepts>\n\
    #include <iterator>\n\nnamespace zawa {\n\nenum class GameWinner {\n    First,\n\
    \    Second,\n};\n\ntemplate <std::input_iterator It>\nGameWinner MisereNim(It\
    \ first, It last) {\n    u64 grundy = 0;\n    usize size = 0;\n    bool over2\
    \ = false;\n    for (auto it = first ; it != last ; it++, size++) {\n        u64\
    \ val = static_cast<u64>(*it);\n        over2 |= val >= 2;\n        grundy ^=\
    \ val;\n    }\n    if (over2) return grundy ? GameWinner::First : GameWinner::Second;\n\
    \    else return size & 1 ? GameWinner::Second : GameWinner::First;\n}\n\n} //\
    \ namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <concepts>\n\
    #include <iterator>\n\nnamespace zawa {\n\nenum class GameWinner {\n    First,\n\
    \    Second,\n};\n\ntemplate <std::input_iterator It>\nGameWinner MisereNim(It\
    \ first, It last) {\n    u64 grundy = 0;\n    usize size = 0;\n    bool over2\
    \ = false;\n    for (auto it = first ; it != last ; it++, size++) {\n        u64\
    \ val = static_cast<u64>(*it);\n        over2 |= val >= 2;\n        grundy ^=\
    \ val;\n    }\n    if (over2) return grundy ? GameWinner::First : GameWinner::Second;\n\
    \    else return size & 1 ? GameWinner::Second : GameWinner::First;\n}\n\n} //\
    \ namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Utility/MisereNim.hpp
  requiredBy:
  - Test/yukicoder/3090.cpp
  timestamp: '2025-04-05 14:11:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Src/Utility/MisereNim.hpp
layout: document
title: Misere Nim
---

## 概要

Misere Nimの勝敗を判定します

Misere Nimとは、「最後の一個をとったら負け」石取りゲームのこと。

$2$ 個以上の石からなる石山が存在すると通常のNimに帰着し、そうでない場合は自明

## 使い方

```cpp
enum class GameWinner {
    First,
    Second
}
```

返り値

```cpp
template <std::input_iterator It>
GameWinner MisereNim(It first, It last)
```

標準ライブラリと同じノリでイテレータを入れる
