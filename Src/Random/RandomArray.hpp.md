---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Random/RandomArray.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Random/RandomArray.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <concepts>\n#include <vector>\n#include <random>\n\
    \nnamespace zawa {\n\nnamespace Random {\n\ntemplate <std::integral T>\nstd::vector<T>\
    \ Array(usize n, T min, T max, bool verify = true) {\n    assert(min <= max);\n\
    \    std::mt19937_64 mt{std::random_device{}()};\n    std::vector<T> res(n);\n\
    \    for (T& v : res) {\n        v = static_cast<T>(mt() % (max - min + 1)) +\
    \ min;\n    }\n    if (verify)\n        std::ranges::all_of(res, [&](T v) { return\
    \ min <= v and v <= max; });\n    return res;\n}\n\n} // namespace Random\n\n\
    } // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <concepts>\n#include <vector>\n#include <random>\n\
    \nnamespace zawa {\n\nnamespace Random {\n\ntemplate <std::integral T>\nstd::vector<T>\
    \ Array(usize n, T min, T max, bool verify = true) {\n    assert(min <= max);\n\
    \    std::mt19937_64 mt{std::random_device{}()};\n    std::vector<T> res(n);\n\
    \    for (T& v : res) {\n        v = static_cast<T>(mt() % (max - min + 1)) +\
    \ min;\n    }\n    if (verify)\n        std::ranges::all_of(res, [&](T v) { return\
    \ min <= v and v <= max; });\n    return res;\n}\n\n} // namespace Random\n\n\
    } // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Random/RandomArray.hpp
  requiredBy: []
  timestamp: '2025-09-06 12:13:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Src/Random/RandomArray.hpp
layout: document
redirect_from:
- /library/Src/Random/RandomArray.hpp
- /library/Src/Random/RandomArray.hpp.html
title: Src/Random/RandomArray.hpp
---
