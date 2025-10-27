---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc429_g.test.cpp
    title: Test/AtCoder/abc429_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/My/Number/SqrtHeuristicArithmetic.test.cpp
    title: Test/My/Number/SqrtHeuristicArithmetic.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc429/submissions/70468550
    - https://codeforces.com/blog/entry/141889
  bundledCode: "#line 2 \"Src/Number/SqrtHeuristicArithmetic.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Number/SqrtHeuristicArithmetic.hpp\"\n\n\
    #include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <concepts>\n\
    #include <ranges>\n#include <tuple>\n#include <vector>\n#include <numeric>\n\n\
    namespace zawa {\n\n// ax + b\ntemplate <std::integral T>\nstruct Arithmetic {\n\
    \    T a, b;\n    usize n;\n    // original sequence f(l), f(l + gap), f(l + 2gap),\
    \ ..., f(l + (n-1)gap)\n    usize l, gap;\n    T operator()(usize i) const {\n\
    \        assert(i < n);\n        return a * i + b;\n    }\n    usize originIndex(usize\
    \ i) const {\n        assert(i < n);\n        return gap * i + l;\n    }\n};\n\
    \n// { B, A + B, 2A + B, 3A + B, ..., (N-1)A + B } (each values are mod M)\n//\
    \ require: 0 <= N < M, gcd(A, M) = 1\n// reference: https://codeforces.com/blog/entry/141889\n\
    // reference: https://atcoder.jp/contests/abc429/submissions/70468550\n// response:\
    \ get<0> * get<1>[i](j) + get<2> = B + A * get<1>[i].origin_index(j)\n// memo:\
    \ if gcd(A, M) = g > 1, transform to g((A/g)x + (B/g) (mod M)) + B%g\n// memo:\
    \ if N >= M, reduce to gcd(A, M) = 1 and partition to {0, 1, 2, ..., M - 1} (N/M\
    \ times), {B, A+B, ..., A*(N%M)+B} mod M\ntemplate <std::integral T>\nstd::vector<Arithmetic<T>>\
    \ SqrtHeuristicArithmetic(T A, T B, usize M, usize N) {\n    assert(M > usize{0});\n\
    \    assert(N < M);\n    A %= M;\n    B %= M;\n    if (N == 0)\n        return\
    \ {};\n    if (N == 1)\n        return {Arithmetic{A, B, N, 0, 0}};\n    assert(std::gcd(A,\
    \ M) == 1);\n    // floor(sqrt(M)) + 1\n    const usize n = [&]() {\n        usize\
    \ res = static_cast<usize>(sqrtl(M));\n        while (res * res > M)\n       \
    \     res--;\n        while (res * res <= M)\n            res++;\n        return\
    \ res;\n    }();\n    assert(std::min(n, M) >= 2);\n    std::vector<std::pair<T,\
    \ usize>> app;\n    app.reserve(std::min(n, N));\n    for (usize i = 0 ; i < std::min(n,\
    \ N) ; i++)\n        app.emplace_back((A * i + B) % M, i);\n    std::ranges::sort(app);\n\
    \    T minDiff = M;\n    usize idx = 0;\n    for (usize i = 1 ; i < app.size()\
    \ ; i++) {\n        if (minDiff > std::abs(app[i].first - app[i - 1].first)) {\n\
    \            minDiff = std::abs(app[i].first - app[i - 1].first);\n          \
    \  idx = i;\n        }\n    }\n    const usize gap = std::max(app[idx].second,\
    \ app[idx - 1].second) - std::min(app[idx].second, app[idx - 1].second);\n   \
    \ assert(minDiff > 0); \n    assert(gap > 0);\n    std::vector<Arithmetic<T>>\
    \ res;\n    const T a = \n        ((A * std::max(app[idx].second, app[idx - 1].second)\
    \ + B) % M)\n        -\n        ((A * std::min(app[idx].second, app[idx - 1].second)\
    \ + B) % M);\n    assert(a != 0);\n    for (usize i = 0 ; i < gap ; i++)\n   \
    \     for (usize j = i ; j < N ; ) {\n            const T stVal = (A * j + B)\
    \ % M;\n            const T n = std::min<usize>(\n                    (N - j +\
    \ gap - 1) / gap - 1, \n                    a > 0 ? ((M - stVal + a - 1) / a -\
    \ 1) : stVal / (-a));\n            assert(stVal + n * a < static_cast<T>(M) and\
    \ stVal + n * a >= 0);\n            assert(j + n * gap < N);\n            res.emplace_back(a,\
    \ stVal, n + 1, j, gap);\n            j += gap * (n + 1);\n        }\n    return\
    \ res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <concepts>\n#include <ranges>\n\
    #include <tuple>\n#include <vector>\n#include <numeric>\n\nnamespace zawa {\n\n\
    // ax + b\ntemplate <std::integral T>\nstruct Arithmetic {\n    T a, b;\n    usize\
    \ n;\n    // original sequence f(l), f(l + gap), f(l + 2gap), ..., f(l + (n-1)gap)\n\
    \    usize l, gap;\n    T operator()(usize i) const {\n        assert(i < n);\n\
    \        return a * i + b;\n    }\n    usize originIndex(usize i) const {\n  \
    \      assert(i < n);\n        return gap * i + l;\n    }\n};\n\n// { B, A + B,\
    \ 2A + B, 3A + B, ..., (N-1)A + B } (each values are mod M)\n// require: 0 <=\
    \ N < M, gcd(A, M) = 1\n// reference: https://codeforces.com/blog/entry/141889\n\
    // reference: https://atcoder.jp/contests/abc429/submissions/70468550\n// response:\
    \ get<0> * get<1>[i](j) + get<2> = B + A * get<1>[i].origin_index(j)\n// memo:\
    \ if gcd(A, M) = g > 1, transform to g((A/g)x + (B/g) (mod M)) + B%g\n// memo:\
    \ if N >= M, reduce to gcd(A, M) = 1 and partition to {0, 1, 2, ..., M - 1} (N/M\
    \ times), {B, A+B, ..., A*(N%M)+B} mod M\ntemplate <std::integral T>\nstd::vector<Arithmetic<T>>\
    \ SqrtHeuristicArithmetic(T A, T B, usize M, usize N) {\n    assert(M > usize{0});\n\
    \    assert(N < M);\n    A %= M;\n    B %= M;\n    if (N == 0)\n        return\
    \ {};\n    if (N == 1)\n        return {Arithmetic{A, B, N, 0, 0}};\n    assert(std::gcd(A,\
    \ M) == 1);\n    // floor(sqrt(M)) + 1\n    const usize n = [&]() {\n        usize\
    \ res = static_cast<usize>(sqrtl(M));\n        while (res * res > M)\n       \
    \     res--;\n        while (res * res <= M)\n            res++;\n        return\
    \ res;\n    }();\n    assert(std::min(n, M) >= 2);\n    std::vector<std::pair<T,\
    \ usize>> app;\n    app.reserve(std::min(n, N));\n    for (usize i = 0 ; i < std::min(n,\
    \ N) ; i++)\n        app.emplace_back((A * i + B) % M, i);\n    std::ranges::sort(app);\n\
    \    T minDiff = M;\n    usize idx = 0;\n    for (usize i = 1 ; i < app.size()\
    \ ; i++) {\n        if (minDiff > std::abs(app[i].first - app[i - 1].first)) {\n\
    \            minDiff = std::abs(app[i].first - app[i - 1].first);\n          \
    \  idx = i;\n        }\n    }\n    const usize gap = std::max(app[idx].second,\
    \ app[idx - 1].second) - std::min(app[idx].second, app[idx - 1].second);\n   \
    \ assert(minDiff > 0); \n    assert(gap > 0);\n    std::vector<Arithmetic<T>>\
    \ res;\n    const T a = \n        ((A * std::max(app[idx].second, app[idx - 1].second)\
    \ + B) % M)\n        -\n        ((A * std::min(app[idx].second, app[idx - 1].second)\
    \ + B) % M);\n    assert(a != 0);\n    for (usize i = 0 ; i < gap ; i++)\n   \
    \     for (usize j = i ; j < N ; ) {\n            const T stVal = (A * j + B)\
    \ % M;\n            const T n = std::min<usize>(\n                    (N - j +\
    \ gap - 1) / gap - 1, \n                    a > 0 ? ((M - stVal + a - 1) / a -\
    \ 1) : stVal / (-a));\n            assert(stVal + n * a < static_cast<T>(M) and\
    \ stVal + n * a >= 0);\n            assert(j + n * gap < N);\n            res.emplace_back(a,\
    \ stVal, n + 1, j, gap);\n            j += gap * (n + 1);\n        }\n    return\
    \ res;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Number/SqrtHeuristicArithmetic.hpp
  requiredBy: []
  timestamp: '2025-10-27 16:11:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc429_g.test.cpp
  - Test/My/Number/SqrtHeuristicArithmetic.test.cpp
documentation_of: Src/Number/SqrtHeuristicArithmetic.hpp
layout: document
redirect_from:
- /library/Src/Number/SqrtHeuristicArithmetic.hpp
- /library/Src/Number/SqrtHeuristicArithmetic.hpp.html
title: Src/Number/SqrtHeuristicArithmetic.hpp
---
