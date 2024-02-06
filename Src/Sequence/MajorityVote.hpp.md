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
    title: ABC272-G Yet Another mod M
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Sequence/MajorityVote.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Sequence/MajorityVote.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <optional>\n#include <type_traits>\n\nnamespace zawa\
    \ {\n\ntemplate <class T, class InputIterator>\nstd::optional<T> MajorityVote(InputIterator\
    \ first, InputIterator last) {\n    static_assert(std::is_convertible_v<decltype(*first),\
    \ T>, \"InputIterator must be convertible T\");\n    assert(first != last);\n\
    \    std::optional<T> remain{}; \n    usize number{};\n    for (auto it{first}\
    \ ; it != last ; it++) {\n        if (number) {\n            if (remain.value()\
    \ == *it) {\n                number++;\n            }\n            else {\n  \
    \              number--;\n            }\n        }\n        else {\n         \
    \   remain = *it;\n            number++;\n        }\n    }\n    if (number and\
    \ 2u * std::count(first, last, remain.value()) > std::distance(first, last)) {\n\
    \        return remain;\n    }\n    else {\n        return std::nullopt;\n   \
    \ }\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <optional>\n#include <type_traits>\n\nnamespace zawa\
    \ {\n\ntemplate <class T, class InputIterator>\nstd::optional<T> MajorityVote(InputIterator\
    \ first, InputIterator last) {\n    static_assert(std::is_convertible_v<decltype(*first),\
    \ T>, \"InputIterator must be convertible T\");\n    assert(first != last);\n\
    \    std::optional<T> remain{}; \n    usize number{};\n    for (auto it{first}\
    \ ; it != last ; it++) {\n        if (number) {\n            if (remain.value()\
    \ == *it) {\n                number++;\n            }\n            else {\n  \
    \              number--;\n            }\n        }\n        else {\n         \
    \   remain = *it;\n            number++;\n        }\n    }\n    if (number and\
    \ 2u * std::count(first, last, remain.value()) > std::distance(first, last)) {\n\
    \        return remain;\n    }\n    else {\n        return std::nullopt;\n   \
    \ }\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Sequence/MajorityVote.hpp
  requiredBy: []
  timestamp: '2024-02-06 11:57:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Manual/abc272_g.test.cpp
documentation_of: Src/Sequence/MajorityVote.hpp
layout: document
title: "Boyer-Moore\u306EMajority vote algorithm"
---

## 使い方

```cpp
template <class T, class InputIterator>
std::optional<T> MajorityVote(InputIterator first, InputIterator last)
```

引数に与えたイテレータ範囲`[first, last)`に過半数を占める要素が存在するなら、その値を返す。存在しない場合は`std::nullopt`を返す。

`std::optional`は`std::nullopt`でないなら`true`と評価される。

- [cpprefjp std::optional](https://cpprefjp.github.io/reference/optional/optional.html)

```cpp
auto v{MajorityVote<T>(A.begin(), A.end())};
if (v) {
    std::cout << v << '\n';
}
else {
    std::cout << "not exist" << '\n';
}
```

#### 計算量

長さ $N$ の列に対して $O(N)$ で動作する

## 参考

- [Kyopro Encyclopedia of Algorithms](https://noshi91.github.io/algorithm-encyclopedia/boyer-moore-majority-vote-algorithm)
