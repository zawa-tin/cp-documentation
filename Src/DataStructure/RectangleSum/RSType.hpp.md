---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp
    title: Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/rectangle_sum.test.cpp
    title: Test/LC/rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/RectangleSum/RSType.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/RectangleSum/RSType.hpp\"\
    \n\n#include <cassert>\n#include <type_traits>\n\nnamespace zawa {\n\ntemplate\
    \ <class P, class W>\nstruct RSPoint {\n    static_assert(std::is_integral_v<P>,\
    \ \"RSPoint P must be integer\");\n    P x, y;\n    W w;\n    RSPoint() = default;\n\
    \    RSPoint(P x_, P y_) \n        : x{x_}, y{y_}, w{static_cast<W>(1)} {}\n \
    \   RSPoint(P x_, P y_, W w_)\n        : x{x_}, y{y_}, w{w_} {}\n};\n\n// \u6C42\
    \u5024\u3067\u4F7F\u3046\n// \u534A\u958B\u533A\u9593\ntemplate <class P>\nstruct\
    \ RSQuery {\n    static_assert(std::is_integral_v<P>, \"RSPoint P must be integer\"\
    );\n    P l, d, r, u;\n    RSQuery() = default;\n    RSQuery(P l_, P d_, P r_,\
    \ P u_)\n        : l{l_}, d{d_}, r{r_}, u{u_} {\n        assert(l < r);\n    \
    \    assert(d < u);\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <cassert>\n\
    #include <type_traits>\n\nnamespace zawa {\n\ntemplate <class P, class W>\nstruct\
    \ RSPoint {\n    static_assert(std::is_integral_v<P>, \"RSPoint P must be integer\"\
    );\n    P x, y;\n    W w;\n    RSPoint() = default;\n    RSPoint(P x_, P y_) \n\
    \        : x{x_}, y{y_}, w{static_cast<W>(1)} {}\n    RSPoint(P x_, P y_, W w_)\n\
    \        : x{x_}, y{y_}, w{w_} {}\n};\n\n// \u6C42\u5024\u3067\u4F7F\u3046\n//\
    \ \u534A\u958B\u533A\u9593\ntemplate <class P>\nstruct RSQuery {\n    static_assert(std::is_integral_v<P>,\
    \ \"RSPoint P must be integer\");\n    P l, d, r, u;\n    RSQuery() = default;\n\
    \    RSQuery(P l_, P d_, P r_, P u_)\n        : l{l_}, d{d_}, r{r_}, u{u_} {\n\
    \        assert(l < r);\n        assert(d < u);\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/RectangleSum/RSType.hpp
  requiredBy:
  - Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp
  timestamp: '2024-11-09 02:34:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/rectangle_sum.test.cpp
documentation_of: Src/DataStructure/RectangleSum/RSType.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/RectangleSum/RSType.hpp
- /library/Src/DataStructure/RectangleSum/RSType.hpp.html
title: Src/DataStructure/RectangleSum/RSType.hpp
---
