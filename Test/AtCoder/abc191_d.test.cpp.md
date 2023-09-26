---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/IntegerDivision.hpp
    title: "\u6574\u6570\u540C\u58EB\u306E\u5207\u308A\u6368\u3066/\u5207\u308A\u4E0A\
      \u3052\u9664\u7B97"
  - icon: ':heavy_check_mark:'
    path: Src/Template/FloatingNumberAlias.hpp
    title: "\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\
      \u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/BinarySearch.hpp
    title: "\u4E8C\u5206\u63A2\u7D22"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/FloatingMarkerShift.hpp
    title: "\u6587\u5B57\u5217\u3067\u53D7\u3051\u53D6\u3063\u305F\u5C0F\u6570\u3092\
      10\u500D\u3057\u307E\u304F\u3063\u3066\u6574\u6570\u306B\u3059\u308B\u3084\u3064"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc191/tasks/abc191_d
    links:
    - https://atcoder.jp/contests/abc191/tasks/abc191_d
  bundledCode: "#line 1 \"Test/AtCoder/abc191_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc191/tasks/abc191_d\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Template/FloatingNumberAlias.hpp\"\
    \n\nnamespace zawa {\n\nusing ld = long double;\n\n} // namespace zawa\n#line\
    \ 2 \"Src/Number/IntegerDivision.hpp\"\n\n#include <type_traits>\n#include <cassert>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nconstexpr T DivFloor(T a, T b) {\n \
    \   static_assert(std::is_integral_v<T>, \"DivFloor argument must be Integer\"\
    );\n    assert(b != T{});\n    if constexpr (std::is_unsigned_v<T>) {\n      \
    \  return a / b;\n    }\n    else {\n        if (b < 0) {\n            a *= -1;\n\
    \            b *= -1;\n        }\n        return (a >= 0 ? a / b : (a - b + 1)\
    \ / b);\n    }\n}\n\ntemplate <class T>\nconstexpr T DivCeil(T a, T b) {\n   \
    \ static_assert(std::is_integral_v<T>, \"DivCeil argument must be Integer\");\n\
    \    assert(b != T{});\n    if constexpr (std::is_unsigned_v<T>) {\n        return\
    \ (a + b - 1) / b;\n    }\n    else {\n        if (b < 0) {\n            a *=\
    \ -1;\n            b *= -1;\n        }\n        return (a >= 0 ? (a + b - 1) /\
    \ b : a / b);\n    }\n}\n\n} // namespace zawa\n#line 2 \"Src/Utility/FloatingMarkerShift.hpp\"\
    \n\n#line 4 \"Src/Utility/FloatingMarkerShift.hpp\"\n\n#include <string>\n#line\
    \ 7 \"Src/Utility/FloatingMarkerShift.hpp\"\n#include <limits>\n\nnamespace zawa\
    \ {\n\ni64 FloatingMarkerShift(const std::string& S, u32 shift) {\n    static\
    \ i64 lim10{std::numeric_limits<i64>::max() / 10};\n    assert(not S.empty());\n\
    \    i64 res{};\n    u32 moved{};\n    bool start{};\n    bool minus{S[0] == '-'};\n\
    \    for (u32 i{(u32)minus} ; i < S.size() ; i++) {\n        if (S[i] == '.')\
    \ {\n            start = true;\n        }\n        else {\n            if (start)\
    \ moved++;\n            assert(res < lim10);\n            res = res * 10;\n  \
    \          assert(res < std::numeric_limits<i64>::max() - (S[i] - '0'));\n   \
    \         res += S[i] - '0';\n        }\n    }\n    assert(moved <= shift);\n\
    \    while (moved < shift) {\n        moved++;\n        assert(res < lim10);\n\
    \        res = res * 10;\n    }\n    if (minus) res *= -1;\n    return res;\n\
    }\n\n}// namespace zawa\n#line 2 \"Src/Utility/BinarySearch.hpp\"\n\n#line 4 \"\
    Src/Utility/BinarySearch.hpp\"\n\n#include <cmath>\n#include <functional>\n#line\
    \ 8 \"Src/Utility/BinarySearch.hpp\"\n#include <utility>\n\nnamespace zawa {\n\
    \nnamespace internal {\n\ntemplate <class T>\nT MidPoint(T a, T b) {\n    if (a\
    \ > b) std::swap(a, b);\n    return a + ((b - a) >> 1);\n}\n\ntemplate <class\
    \ T>\nT Abs(T a, T b) {\n    return (a >= b ? a - b : b - a);\n}\n\n} // namespace\
    \ zawa::internal\n\ntemplate <class T, class Function>\nT BinarySearch(T ok, T\
    \ ng, const Function& f) {\n    static_assert(std::is_integral_v<T>, \"T must\
    \ be integral type\");\n    static_assert(std::is_convertible_v<Function, std::function<bool(T)>>,\
    \ \"f must be function bool(T)\");\n    while (internal::Abs(ok, ng) > 1) {\n\
    \        T mid{ internal::MidPoint(ok, ng) };\n        (f(mid) ? ok : ng) = mid;\n\
    \    }\n    return ok;\n}\n\ntemplate <class T, class Function>\nT BinarySearch(T\
    \ ok, T ng, const Function& f, u32 upperLimit) {\n    static_assert(std::is_signed_v<T>,\
    \ \"T must be signed arithmetic type\");\n    static_assert(std::is_convertible_v<Function,\
    \ std::function<bool(T)>>, \"f must be function bool(T)\");\n    for (u32 _{}\
    \ ; _ < upperLimit ; _++) {\n        T mid{ (ok + ng) / (T)2 };\n        (f(mid)\
    \ ? ok : ng) = mid;\n    }\n    return ok;\n}\n\n} // namespace zawa\n#line 8\
    \ \"Test/AtCoder/abc191_d.test.cpp\"\n\n#include <iostream>\n#line 11 \"Test/AtCoder/abc191_d.test.cpp\"\
    \n\nusing namespace zawa;\n\ni64 parse() {\n    std::string s; std::cin >> s;\n\
    \    return FloatingMarkerShift(s, 4);\n}\n\nconstexpr i64 mul{10000}, range{200100};\n\
    \nint main() {\n    i64 X{parse()}, Y{parse()}, R{parse()}; \n    u64 ans{};\n\
    \    for (i64 x{-range * mul} ; x <= range * mul ; x += mul) {\n        if (abs(x\
    \ - X) > R) continue;\n        i64 y2{ R * R - (x - X) * (x - X) };\n        assert(y2\
    \ >= 0);\n        i64 u{BinarySearch(Y, Y + R + 1, [&](i64 p) -> bool { return\
    \ (p - Y) * (p - Y) <= y2;})};\n        u = DivFloor(u, mul);\n        i64 d{BinarySearch(Y,\
    \ Y - R - 1, [&](i64 p) -> bool { return (p - Y) * (p - Y) <= y2;})};\n      \
    \  d = DivCeil(d, mul);\n        ans += (u - d + 1);\n    }\n    std::cout <<\
    \ ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc191/tasks/abc191_d\"\n\n\
    #include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Template/FloatingNumberAlias.hpp\"\
    \n#include \"../../Src/Number/IntegerDivision.hpp\"\n#include \"../../Src/Utility/FloatingMarkerShift.hpp\"\
    \n#include \"../../Src/Utility/BinarySearch.hpp\"\n\n#include <iostream>\n#include\
    \ <cmath>\n\nusing namespace zawa;\n\ni64 parse() {\n    std::string s; std::cin\
    \ >> s;\n    return FloatingMarkerShift(s, 4);\n}\n\nconstexpr i64 mul{10000},\
    \ range{200100};\n\nint main() {\n    i64 X{parse()}, Y{parse()}, R{parse()};\
    \ \n    u64 ans{};\n    for (i64 x{-range * mul} ; x <= range * mul ; x += mul)\
    \ {\n        if (abs(x - X) > R) continue;\n        i64 y2{ R * R - (x - X) *\
    \ (x - X) };\n        assert(y2 >= 0);\n        i64 u{BinarySearch(Y, Y + R +\
    \ 1, [&](i64 p) -> bool { return (p - Y) * (p - Y) <= y2;})};\n        u = DivFloor(u,\
    \ mul);\n        i64 d{BinarySearch(Y, Y - R - 1, [&](i64 p) -> bool { return\
    \ (p - Y) * (p - Y) <= y2;})};\n        d = DivCeil(d, mul);\n        ans += (u\
    \ - d + 1);\n    }\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Template/FloatingNumberAlias.hpp
  - Src/Number/IntegerDivision.hpp
  - Src/Utility/FloatingMarkerShift.hpp
  - Src/Utility/BinarySearch.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc191_d.test.cpp
  requiredBy: []
  timestamp: '2023-09-24 02:48:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc191_d.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc191_d.test.cpp
- /verify/Test/AtCoder/abc191_d.test.cpp.html
title: Test/AtCoder/abc191_d.test.cpp
---
