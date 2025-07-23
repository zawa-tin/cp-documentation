---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.yosupo.jp/problem/rational_approximation
    links:
    - https://judge.yosupo.jp/problem/rational_approximation
  bundledCode: "#line 1 \"Test/LC/rational_approximation.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/rational_approximation\"\n\n#line 2 \"Src/Utility/RationalBinarySearch.hpp\"\
    \n\n#include <cassert>\n#include <concepts>\n#include <utility>\n\nnamespace zawa\
    \ {\n\ntemplate <class F, std::integral T>\nrequires std::predicate<F, T, T>\n\
    std::pair<std::pair<T, T>, std::pair<T, T>> RationalBinarySearch(F f, T n) {\n\
    \    assert(f(0, 1) and !f(1, 0));\n    auto dfs = [&](auto dfs, bool cur, T&\
    \ p, T& q, T pp, T pq) -> void {\n        if (p + pp > n or q + pq > n) return;\n\
    \        if (f(p + pp, q + pq) == cur) {\n            p += pp;\n            q\
    \ += pq;\n            dfs(dfs, cur, p, q, pp << 1, pq << 1);\n        }\n    \
    \    if (p + pp <= n and q + pq <= n and f(p + pp, q + pq) == cur) {\n       \
    \     p += pp;\n            q += pq;\n        }\n    };\n    T pl = 0, ql = 1,\
    \ pr = 1, qr = 0;\n    while (pl + pr <= n and ql + qr <= n) {\n        dfs(dfs,\
    \ true, pl, ql, pr, qr);\n        dfs(dfs, false, pr, qr, pl, ql);\n    }\n  \
    \  return std::pair{std::pair{pl, ql}, std::pair{pr, qr}};\n}\n\n} // namespace\
    \ zawa\n#line 4 \"Test/LC/rational_approximation.test.cpp\"\n\n#include <iostream>\n\
    using namespace zawa;\nusing namespace std;\n\nint main() {\n    cin.tie(0);\n\
    \    cout.tie(0);\n    ios::sync_with_stdio(0); \n    int T;\n    cin >> T;\n\
    \    while (T--) {\n        long long N, x, y;\n        cin >> N >> x >> y;\n\
    \        auto f = [&](long long a, long long b) -> bool {\n            return\
    \ a * y <= x * b;\n        };\n        auto [max_ok, min_ng] = RationalBinarySearch(f,\
    \ N);\n        auto [a, b] = max_ok;\n        auto [c, d] = min_ng;\n        if\
    \ (a * y == x * b) {\n            cout << a << ' ' << b << ' ' << a << ' ' <<\
    \ b << '\\n';\n        }\n        else {\n            cout << a << ' ' << b <<\
    \ ' ' << c << ' ' << d << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rational_approximation\"\
    \n\n#include \"../../Src/Utility/RationalBinarySearch.hpp\"\n\n#include <iostream>\n\
    using namespace zawa;\nusing namespace std;\n\nint main() {\n    cin.tie(0);\n\
    \    cout.tie(0);\n    ios::sync_with_stdio(0); \n    int T;\n    cin >> T;\n\
    \    while (T--) {\n        long long N, x, y;\n        cin >> N >> x >> y;\n\
    \        auto f = [&](long long a, long long b) -> bool {\n            return\
    \ a * y <= x * b;\n        };\n        auto [max_ok, min_ng] = RationalBinarySearch(f,\
    \ N);\n        auto [a, b] = max_ok;\n        auto [c, d] = min_ng;\n        if\
    \ (a * y == x * b) {\n            cout << a << ' ' << b << ' ' << a << ' ' <<\
    \ b << '\\n';\n        }\n        else {\n            cout << a << ' ' << b <<\
    \ ' ' << c << ' ' << d << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - Src/Utility/RationalBinarySearch.hpp
  isVerificationFile: true
  path: Test/LC/rational_approximation.test.cpp
  requiredBy: []
  timestamp: '2025-07-23 20:10:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/rational_approximation.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/rational_approximation.test.cpp
- /verify/Test/LC/rational_approximation.test.cpp.html
title: Test/LC/rational_approximation.test.cpp
---
