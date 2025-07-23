---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/FloatingMarkerShift.hpp
    title: "\u6587\u5B57\u5217\u3067\u53D7\u3051\u53D6\u3063\u305F\u5C0F\u6570\u3092\
      10\u500D\u3057\u307E\u304F\u3063\u3066\u6574\u6570\u306B\u3059\u308B\u3084\u3064"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/RationalBinarySearch.hpp
    title: "\u6709\u7406\u6570\u3067\u4E8C\u5206\u63A2\u7D22"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc333/tasks/abc333_g
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc333_g.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc333/tasks/abc333_g\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/Utility/FloatingMarkerShift.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Utility/FloatingMarkerShift.hpp\"\n\n#include\
    \ <string>\n#include <cassert>\n#include <limits>\n\nnamespace zawa {\n\ni64 FloatingMarkerShift(const\
    \ std::string& S, u32 shift) {\n    static i64 lim10{std::numeric_limits<i64>::max()\
    \ / 10};\n    assert(not S.empty());\n    i64 res{};\n    u32 moved{};\n    bool\
    \ start{};\n    bool minus{S[0] == '-'};\n    for (u32 i{(u32)minus} ; i < S.size()\
    \ ; i++) {\n        if (S[i] == '.') {\n            start = true;\n        }\n\
    \        else {\n            if (start) moved++;\n            assert(res < lim10);\n\
    \            res = res * 10;\n            assert(res < std::numeric_limits<i64>::max()\
    \ - (S[i] - '0'));\n            res += S[i] - '0';\n        }\n    }\n    assert(moved\
    \ <= shift);\n    while (moved < shift) {\n        moved++;\n        assert(res\
    \ < lim10);\n        res = res * 10;\n    }\n    if (minus) res *= -1;\n    return\
    \ res;\n}\n\n}// namespace zawa\n#line 2 \"Src/Utility/RationalBinarySearch.hpp\"\
    \n\n#line 4 \"Src/Utility/RationalBinarySearch.hpp\"\n#include <concepts>\n#include\
    \ <utility>\n\nnamespace zawa {\n\ntemplate <class F, std::integral T>\nrequires\
    \ std::predicate<F, T, T>\nstd::pair<std::pair<T, T>, std::pair<T, T>> RationalBinarySearch(F\
    \ f, T n) {\n    assert(f(0, 1) and !f(1, 0));\n    auto dfs = [&](auto dfs, bool\
    \ cur, T& p, T& q, T pp, T pq) -> void {\n        if (p + pp > n or q + pq > n)\
    \ return;\n        if (f(p + pp, q + pq) == cur) {\n            p += pp;\n   \
    \         q += pq;\n            dfs(dfs, cur, p, q, pp << 1, pq << 1);\n     \
    \   }\n        if (p + pp <= n and q + pq <= n and f(p + pp, q + pq) == cur) {\n\
    \            p += pp;\n            q += pq;\n        }\n    };\n    T pl = 0,\
    \ ql = 1, pr = 1, qr = 0;\n    while (pl + pr <= n and ql + qr <= n) {\n     \
    \   dfs(dfs, true, pl, ql, pr, qr);\n        dfs(dfs, false, pr, qr, pl, ql);\n\
    \    }\n    return std::pair{std::pair{pl, ql}, std::pair{pr, qr}};\n}\n\n} //\
    \ namespace zawa\n#line 6 \"Test/AtCoder/abc333_g.test.cpp\"\n\n#include <iostream>\n\
    #line 9 \"Test/AtCoder/abc333_g.test.cpp\"\n#include <numeric>\n\nusing namespace\
    \ zawa;\nusing namespace std;\n\n__int128_t my_abs(__int128_t v) {\n    return\
    \ v < 0 ? -v : v;\n}\n\nint main() {\n#ifdef ATCODER\n    string rs;\n    long\
    \ long n;\n    cin >> rs >> n;\n    long long num = FloatingMarkerShift(rs, 18),\
    \ den = 1000000000000000000LL;\n    long long g = gcd(num, den);\n    num /= g;\n\
    \    den /= g;\n    auto f = [&](long long x, long long y) -> bool {\n       \
    \ return (__int128_t)x * den <= (__int128_t)num * y;\n    };\n    auto [max_ok,\
    \ min_ng] = RationalBinarySearch(f, n);\n    auto [a, b] = max_ok;\n    auto [c,\
    \ d] = min_ng;\n    if ((long double)2 * num * d * b > ((long double)c * b + (long\
    \ double)a * d) * den) {\n        swap(a, c);\n        swap(b, d);\n    }\n  \
    \  cout << a << ' ' << b << '\\n';\n#else\n    cout << \"Hello World\\n\";\n#endif\n\
    }\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc333/tasks/abc333_g\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/Utility/FloatingMarkerShift.hpp\"\n#include \"../../Src/Utility/RationalBinarySearch.hpp\"\
    \n\n#include <iostream>\n#include <string>\n#include <numeric>\n\nusing namespace\
    \ zawa;\nusing namespace std;\n\n__int128_t my_abs(__int128_t v) {\n    return\
    \ v < 0 ? -v : v;\n}\n\nint main() {\n#ifdef ATCODER\n    string rs;\n    long\
    \ long n;\n    cin >> rs >> n;\n    long long num = FloatingMarkerShift(rs, 18),\
    \ den = 1000000000000000000LL;\n    long long g = gcd(num, den);\n    num /= g;\n\
    \    den /= g;\n    auto f = [&](long long x, long long y) -> bool {\n       \
    \ return (__int128_t)x * den <= (__int128_t)num * y;\n    };\n    auto [max_ok,\
    \ min_ng] = RationalBinarySearch(f, n);\n    auto [a, b] = max_ok;\n    auto [c,\
    \ d] = min_ng;\n    if ((long double)2 * num * d * b > ((long double)c * b + (long\
    \ double)a * d) * den) {\n        swap(a, c);\n        swap(b, d);\n    }\n  \
    \  cout << a << ' ' << b << '\\n';\n#else\n    cout << \"Hello World\\n\";\n#endif\n\
    }\n"
  dependsOn:
  - Src/Utility/FloatingMarkerShift.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Utility/RationalBinarySearch.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc333_g.test.cpp
  requiredBy: []
  timestamp: '2025-07-23 20:10:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc333_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc333_g.test.cpp
- /verify/Test/AtCoder/abc333_g.test.cpp.html
title: Test/AtCoder/abc333_g.test.cpp
---
