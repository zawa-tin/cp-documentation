---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/EnumeratePrimes.hpp
    title: Enumerate Primes
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://codeforces.com/contest/2104/problem/D
    - https://codeforces.com/contest/2104/submission/318930773
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/CF/ECR178-D.test.cpp\"\n// #define PROBLEM \"https://codeforces.com/contest/2104/problem/D\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * Educational Codeforces Round 178 - D Array and GCD\n * https://codeforces.com/contest/2104/submission/318930773\n\
    \ */\n\n#line 2 \"Src/Number/EnumeratePrimes.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Number/EnumeratePrimes.hpp\"\n\n#include\
    \ <concepts>\n#include <vector>\n#include <bit>\n\nnamespace zawa {\n\ntemplate\
    \ <std::integral T>\nstd::vector<T> EnumeratePrimes(usize N) {\n    static constexpr\
    \ u32 p[]{2,3,5,7,11,13,17,19,23,29,31};\n    u32 w = 1;\n    usize m = 0;\n \
    \   for ( ; m < std::size(p) and static_cast<u64>(w) * w < N ; w *= p[m++]) ;\n\
    \    std::vector<u32> R = [&]() {\n        std::vector<bool> siv(w, true);\n \
    \       for (usize i = 0 ; i < m ; i++) {\n            for (u32 j = p[i] ; j <\
    \ w ; j += p[i]) siv[j] = false;\n        }\n        std::vector<u32> res{1};\n\
    \        for (u32 i = 2 ; i < w ; i++) if (siv[i]) res.push_back(i);\n       \
    \ return res;\n    }();\n    std::vector<T> res;\n    res.reserve(N / (std::bit_width(N)\
    \ + 1));\n    std::vector<u32> S;\n    S.reserve(N / 5u);\n    for (u32 kw = 0\
    \ ; kw <= N ; kw += w) {\n        for (u32 r = 0 ; r < R.size() and kw + R[r]\
    \ <= N ; r++) {\n            S.push_back(kw + R[r]);\n        }\n    }\n    for\
    \ (usize i = 0 ; i < m ; i++) res.push_back(static_cast<T>(p[i]));\n    std::vector<bool>\
    \ siv(N + 1, true);\n    for (usize i = 1 ; i < S.size() ; i++) if (siv[S[i]])\
    \ {\n        res.push_back(static_cast<T>(S[i])); \n        for (u32 j = i ; j\
    \ < S.size() ; j++) {\n            u64 p = static_cast<u64>(S[i]) * S[j];\n  \
    \          if (p > N) break;\n            siv[p] = false;\n        }\n    }\n\
    \    return res;\n}\n\n} // namespace zawa\n#line 10 \"Test/CF/ECR178-D.test.cpp\"\
    \n\n#include <iostream>\n#include <numeric>\n#line 14 \"Test/CF/ECR178-D.test.cpp\"\
    \n#include <algorithm>\nint N, A[400040];\nstd::vector<int> P = zawa::EnumeratePrimes<int>(6000000);\n\
    int solve() {\n    std::sort(A, A + N);\n    long long p = std::accumulate(P.begin(),\
    \ P.begin() + N, 0LL);\n    long long a = std::accumulate(A, A + N, 0LL);\n  \
    \  for (int i = 0 ; i < N ; i++) {\n        if (a >= p) return i;\n        a -=\
    \ A[i];\n        p -= P[N - i - 1];\n    }\n    return N;\n}\nint main() {\n#ifdef\
    \ ONLINE_JUDGE\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int T;\n    std::cin >> T;\n    while (T--) {\n        std::cin >> N;\n \
    \       for (int i = 0 ; i < N ; i++) std::cin >> A[i];\n        std::cout <<\
    \ solve() << '\\n';\n    }\n#else\n    std::cout << \"Hello World\\n\";\n#endif\n\
    }\n"
  code: "// #define PROBLEM \"https://codeforces.com/contest/2104/problem/D\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * Educational Codeforces Round 178 - D Array and GCD\n * https://codeforces.com/contest/2104/submission/318930773\n\
    \ */\n\n#include \"../../Src/Number/EnumeratePrimes.hpp\"\n\n#include <iostream>\n\
    #include <numeric>\n#include <vector>\n#include <algorithm>\nint N, A[400040];\n\
    std::vector<int> P = zawa::EnumeratePrimes<int>(6000000);\nint solve() {\n   \
    \ std::sort(A, A + N);\n    long long p = std::accumulate(P.begin(), P.begin()\
    \ + N, 0LL);\n    long long a = std::accumulate(A, A + N, 0LL);\n    for (int\
    \ i = 0 ; i < N ; i++) {\n        if (a >= p) return i;\n        a -= A[i];\n\
    \        p -= P[N - i - 1];\n    }\n    return N;\n}\nint main() {\n#ifdef ONLINE_JUDGE\n\
    \    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int T;\n    std::cin >> T;\n    while (T--) {\n        std::cin >> N;\n \
    \       for (int i = 0 ; i < N ; i++) std::cin >> A[i];\n        std::cout <<\
    \ solve() << '\\n';\n    }\n#else\n    std::cout << \"Hello World\\n\";\n#endif\n\
    }\n"
  dependsOn:
  - Src/Number/EnumeratePrimes.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/CF/ECR178-D.test.cpp
  requiredBy: []
  timestamp: '2025-05-09 20:26:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/CF/ECR178-D.test.cpp
layout: document
redirect_from:
- /verify/Test/CF/ECR178-D.test.cpp
- /verify/Test/CF/ECR178-D.test.cpp.html
title: Test/CF/ECR178-D.test.cpp
---
