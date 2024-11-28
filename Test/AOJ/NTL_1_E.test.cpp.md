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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
  bundledCode: "#line 1 \"Test/AOJ/NTL_1_E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#line 2 \"Src/Number/ExtendGCD.hpp\"\n\n#include <utility>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nstd::pair<T, T> ExtendGCD(T a, T b) {\n    if (a ==\
    \ 0) return { T{0}, 1 };\n    if (b == 0) return { T{1}, 0 };\n    T px{1}, py{0},\
    \ x{0}, y{1};\n    while (a % b) {\n        T d{a / b}, r{a % b};\n        T nx{px\
    \ - d*x}, ny{py - d*y};\n        px = x;\n        py = y;\n        x = nx;\n \
    \       y = ny;\n        a = b;\n        b = r;\n    }\n    return {x, y};\n}\n\
    \n} // namespace zawa\n#line 4 \"Test/AOJ/NTL_1_E.test.cpp\"\n\n#include <iostream>\n\
    \nint main() {\n    int a, b;\n    std::cin >> a >> b;\n    auto [x, y]{zawa::ExtendGCD(a,\
    \ b)};\n    std::cout << x << ' ' << y << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#include \"../../Src/Number/ExtendGCD.hpp\"\n\n#include <iostream>\n\nint\
    \ main() {\n    int a, b;\n    std::cin >> a >> b;\n    auto [x, y]{zawa::ExtendGCD(a,\
    \ b)};\n    std::cout << x << ' ' << y << '\\n';\n}\n"
  dependsOn:
  - Src/Number/ExtendGCD.hpp
  isVerificationFile: true
  path: Test/AOJ/NTL_1_E.test.cpp
  requiredBy: []
  timestamp: '2024-11-29 05:08:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/NTL_1_E.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/NTL_1_E.test.cpp
- /verify/Test/AOJ/NTL_1_E.test.cpp.html
title: Test/AOJ/NTL_1_E.test.cpp
---
