---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/KthRoot.hpp
    title: "$K$ \u4E57\u6839\u3092\u6574\u6570\u306B\u5207\u308A\u6368\u3066\u30FB\
      \u5207\u308A\u4E0A\u3052"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_root_integer
    links:
    - https://judge.yosupo.jp/problem/kth_root_integer
  bundledCode: "#line 1 \"Test/LC/kth_root_integer.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/kth_root_integer\"\n#line 2 \"Src/Number/KthRoot.hpp\"\
    \n\n#include <cassert>\n#include <cmath>\n#include <concepts>\n#include <utility>\n\
    #include <limits>\n\nnamespace zawa {\n\n// floor(a^{1/k})\ntemplate <std::unsigned_integral\
    \ T>\nT KthRoot(T a,T k,bool floor=1) {\n    assert(k >= 1);\n    if (a <= 1 or\
    \ k == 1)\n        return a;\n    if (k >= std::numeric_limits<T>::digits)\n \
    \       return floor ? 1 : 2;\n    auto pw = [&](T x) -> T {\n        T res =\
    \ 1, exp = k;\n        while (exp) {\n            if (exp & 1) {\n           \
    \     if (res > std::numeric_limits<T>::max() / x)\n                    return\
    \ 0;\n                res *= x;\n            }\n            exp >>= 1;\n     \
    \       if (exp) {\n                if (x > std::numeric_limits<T>::max() / x)\n\
    \                    return 0;\n                x *= x;\n            }\n     \
    \   }\n        return res;\n    };\n    T res = k == 2 ? sqrtl(a) : (k == 3 ?\
    \ cbrtl(a) : powl(a,1.0l/(double)k));\n    while (res >= 1) {\n        T v = pw(res);\n\
    \        if (v and v <= a)\n            break;\n        res--;\n    }\n    while\
    \ (true) {\n        T v = pw(res+1);\n        if (v and v <= a)\n            res++;\n\
    \        else\n            break;\n    }\n    if (!floor and pw(res) < a)\n  \
    \      res++;\n    return res;\n}\n\n} // namespace zawa\n#line 3 \"Test/LC/kth_root_integer.test.cpp\"\
    \n#include <iostream>\nusing namespace std;\nint main() {\n    cin.tie(0);\n \
    \   cout.tie(0);\n    ios::sync_with_stdio(0);\n    int T;\n    cin >> T;\n  \
    \  while (T--) {\n        unsigned long long a,k;\n        cin >> a >> k;\n  \
    \      cout << zawa::KthRoot(a,k) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_integer\"\n#include\
    \ \"../../Src/Number/KthRoot.hpp\"\n#include <iostream>\nusing namespace std;\n\
    int main() {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int T;\n    cin >> T;\n    while (T--) {\n        unsigned long long a,k;\n\
    \        cin >> a >> k;\n        cout << zawa::KthRoot(a,k) << '\\n';\n    }\n\
    }\n"
  dependsOn:
  - Src/Number/KthRoot.hpp
  isVerificationFile: true
  path: Test/LC/kth_root_integer.test.cpp
  requiredBy: []
  timestamp: '2026-07-20 19:53:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/kth_root_integer.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/kth_root_integer.test.cpp
- /verify/Test/LC/kth_root_integer.test.cpp.html
title: Test/LC/kth_root_integer.test.cpp
---
