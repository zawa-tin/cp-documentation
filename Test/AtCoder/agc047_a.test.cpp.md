---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
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
    PROBLEM: https://atcoder.jp/contests/agc047/tasks/agc047_a
    links:
    - https://atcoder.jp/contests/agc047/tasks/agc047_a
  bundledCode: "#line 1 \"Test/AtCoder/agc047_a.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/agc047/tasks/agc047_a\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Utility/FloatingMarkerShift.hpp\"\
    \n\n#line 4 \"Src/Utility/FloatingMarkerShift.hpp\"\n\n#include <string>\n#include\
    \ <cassert>\n#include <limits>\n\nnamespace zawa {\n\ni64 FloatingMarkerShift(const\
    \ std::string& S, u32 shift) {\n    static i64 lim10{std::numeric_limits<i64>::max()\
    \ / 10};\n    assert(not S.empty());\n    i64 res{};\n    u32 moved{};\n    bool\
    \ start{};\n    bool minus{S[0] == '-'};\n    for (u32 i{(u32)minus} ; i < S.size()\
    \ ; i++) {\n        if (S[i] == '.') {\n            start = true;\n        }\n\
    \        else {\n            if (start) moved++;\n            assert(res < lim10);\n\
    \            res = res * 10;\n            assert(res < std::numeric_limits<i64>::max()\
    \ - (S[i] - '0'));\n            res += S[i] - '0';\n        }\n    }\n    assert(moved\
    \ <= shift);\n    while (moved < shift) {\n        moved++;\n        assert(res\
    \ < lim10);\n        res = res * 10;\n    }\n    if (minus) res *= -1;\n    return\
    \ res;\n}\n\n}// namespace zawa\n#line 5 \"Test/AtCoder/agc047_a.test.cpp\"\n\n\
    using namespace zawa;\n\n#include <iostream>\n#include <vector>\n#line 11 \"Test/AtCoder/agc047_a.test.cpp\"\
    \n\nint main() {\n    usize N; std::cin >> N;\n\n    constexpr usize lg2{45},\
    \ lg5{20};\n    std::vector pos(lg2, std::vector<u32>(lg5));\n    \n    u64 ans{};\n\
    \    for (u32 _{} ; _ < N ; _++) {\n        std::string s; std::cin >> s;\n  \
    \      i64 value{FloatingMarkerShift(s, 9)};\n        u32 d2{}, d5{};\n      \
    \  while (value % 2 == 0) {\n            d2++;\n            value /= 2;\n    \
    \    }\n        while (value % 5 == 0) {\n            d5++;\n            value\
    \ /= 5;\n        }\n\n        for (u32 i{} ; i < lg2 ; i++) for (u32 j{} ; j <\
    \ lg5 ; j++) {\n            if (d2 + i >= 18 and d5 + j >= 18) {\n           \
    \     ans += pos[i][j];\n            }\n        }\n\n        pos[d2][d5]++;\n\
    \    }\n\n    std::cout << ans << std::endl;\n\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/agc047/tasks/agc047_a\"\n\n\
    #include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Utility/FloatingMarkerShift.hpp\"\
    \n\nusing namespace zawa;\n\n#include <iostream>\n#include <vector>\n#include\
    \ <string>\n\nint main() {\n    usize N; std::cin >> N;\n\n    constexpr usize\
    \ lg2{45}, lg5{20};\n    std::vector pos(lg2, std::vector<u32>(lg5));\n    \n\
    \    u64 ans{};\n    for (u32 _{} ; _ < N ; _++) {\n        std::string s; std::cin\
    \ >> s;\n        i64 value{FloatingMarkerShift(s, 9)};\n        u32 d2{}, d5{};\n\
    \        while (value % 2 == 0) {\n            d2++;\n            value /= 2;\n\
    \        }\n        while (value % 5 == 0) {\n            d5++;\n            value\
    \ /= 5;\n        }\n\n        for (u32 i{} ; i < lg2 ; i++) for (u32 j{} ; j <\
    \ lg5 ; j++) {\n            if (d2 + i >= 18 and d5 + j >= 18) {\n           \
    \     ans += pos[i][j];\n            }\n        }\n\n        pos[d2][d5]++;\n\
    \    }\n\n    std::cout << ans << std::endl;\n\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Utility/FloatingMarkerShift.hpp
  isVerificationFile: true
  path: Test/AtCoder/agc047_a.test.cpp
  requiredBy: []
  timestamp: '2023-08-14 16:52:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/agc047_a.test.cpp
layout: document
title: AGC047-A Integer Product
---

入力を全て $10^9$ して、整数の問題として考えると積が $10^18$ の倍数であるようなものの個数を数えれば良い。

これは積の素因数分解したものについて、 $2$ の指数と $5$ の指数がそれぞれ $18$ を超えていれば良い。

制約より、各要素の $2$ の指数の最大は $\log_2{10^{13}}$ 、 $5$ の指数の最大は $\log_5{10^{13}}$ とかなり小さいので、要素では無く指数の方を全探索すれば良い。
