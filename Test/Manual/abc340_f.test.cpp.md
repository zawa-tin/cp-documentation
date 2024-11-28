---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/ExtendGCD.hpp
    title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc340/submissions/60264792
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/Manual/abc340_f.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 340 - F S = 1\n * https://atcoder.jp/contests/abc340/submissions/60264792\n\
    \ */\n\n#line 2 \"Src/Number/ExtendGCD.hpp\"\n\n#include <utility>\n\nnamespace\
    \ zawa {\n\ntemplate <class T>\nstd::pair<T, T> ExtendGCD(T a, T b) {\n    if\
    \ (a == 0) return { T{0}, 1 };\n    if (b == 0) return { T{1}, 0 };\n    T px{1},\
    \ py{0}, x{0}, y{1};\n    while (a % b) {\n        T d{a / b}, r{a % b};\n   \
    \     T nx{px - d*x}, ny{py - d*y};\n        px = x;\n        py = y;\n      \
    \  x = nx;\n        y = ny;\n        a = b;\n        b = r;\n    }\n    return\
    \ {x, y};\n}\n\n} // namespace zawa\n#line 9 \"Test/Manual/abc340_f.test.cpp\"\
    \n\n#include <cmath>\n#include <iostream>\n\nvoid solve() {\n    long long X,\
    \ Y;\n    std::cin >> X >> Y;\n    auto [A, B]{zawa::ExtendGCD(Y, -X)};\n    long\
    \ long gcd{std::abs(A*Y + B*(-X))};\n    if (gcd == 1) {\n        A *= 2;\n  \
    \      B *= 2;\n    }\n    if (gcd <= 2) {\n        std::cout << A << ' ' << B\
    \ << '\\n';\n    }\n    else {\n        std::cout << -1 << '\\n';\n    }\n}\n\n\
    int main() {\n#ifdef ATCODER\n    solve();\n#else\n    std::cout << \"Hello World\\\
    n\";\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 340 - F S = 1\n * https://atcoder.jp/contests/abc340/submissions/60264792\n\
    \ */\n\n#include \"../../Src/Number/ExtendGCD.hpp\"\n\n#include <cmath>\n#include\
    \ <iostream>\n\nvoid solve() {\n    long long X, Y;\n    std::cin >> X >> Y;\n\
    \    auto [A, B]{zawa::ExtendGCD(Y, -X)};\n    long long gcd{std::abs(A*Y + B*(-X))};\n\
    \    if (gcd == 1) {\n        A *= 2;\n        B *= 2;\n    }\n    if (gcd <=\
    \ 2) {\n        std::cout << A << ' ' << B << '\\n';\n    }\n    else {\n    \
    \    std::cout << -1 << '\\n';\n    }\n}\n\nint main() {\n#ifdef ATCODER\n   \
    \ solve();\n#else\n    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/Number/ExtendGCD.hpp
  isVerificationFile: true
  path: Test/Manual/abc340_f.test.cpp
  requiredBy: []
  timestamp: '2024-11-29 05:08:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Manual/abc340_f.test.cpp
layout: document
title: ABC340-F S = 1
---

三点 $(a, b), (x, y), (p, q)$ からなる三角形の面積は $\frac{1}{2}\text{abs}((x - a)(q - b) - (y - b)(p - a))$ である。

とくに、三点 $(0, 0), (x, y), (p, q)$ からなる三角形の面積は $\frac{1}{2}\text{abs}(xq - yp)$ である。

本問題は一次不定方程式のかたちをしているため、拡張ユークリッドの互除法で解ける。
