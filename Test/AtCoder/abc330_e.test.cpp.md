---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Other/MexManager.hpp
    title: "\u8981\u7D20\u8FFD\u52A0\u30FB\u524A\u9664\u30FBmex\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc330/tasks/abc330_e
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc330_e.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc330/tasks/abc330_e\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/DataStructure/Other/MexManager.hpp\"\n\n#include <cassert>\n\
    #include <concepts>\n#include <limits>\n#include <utility>\n#include <set>\n\n\
    namespace zawa {\n\ntemplate <std::signed_integral T>\nclass MexManager {\npublic:\n\
    \n    static constexpr T MAX = std::numeric_limits<T>::max();\n\n    static constexpr\
    \ T MIN = T{-1};\n\n    MexManager() {\n        m_rg.insert({MIN, MIN});\n   \
    \     m_rg.insert({MAX, MAX});\n    }\n\n    void insert(T v) {\n        assert(MIN\
    \ + 1 <= v and v <= MAX - 1);\n        if (!m_set.contains(v)) {\n           \
    \ const T r = [&]() {\n                auto it = m_rg.lower_bound({v + 1, MIN});\n\
    \                if (it->first == v + 1) {\n                    int res = it->second;\n\
    \                    m_rg.erase(it);\n                    return res;\n      \
    \          }\n                else\n                    return v;\n          \
    \  }();\n            const T l = [&]() {\n                auto it = prev(m_rg.lower_bound({v,\
    \ MIN}));\n                if (it->second + 1 == v) {\n                    int\
    \ res = it->first;\n                    m_rg.erase(it);\n                    return\
    \ res;\n                }\n                else\n                    return v;\n\
    \            }();\n            m_rg.insert({l, r});\n        }\n        m_set.insert(v);\n\
    \    }\n\n    void erase(T v) {\n        if (!m_set.contains(v))\n           \
    \ return;\n        m_set.erase(m_set.find(v));\n        if (m_set.contains(v))\n\
    \            return;\n        auto it = prev(m_rg.lower_bound({v + 1, MIN}));\n\
    \        const auto [l, r] = *it;\n        assert(l <= v and v <= r);\n      \
    \  it = m_rg.erase(it);\n        if (l < v) m_rg.insert({l, v - 1});\n       \
    \ if (v < r) m_rg.insert({v + 1, r});\n    }\n\n    T operator()() const {\n \
    \       return m_rg.begin()->second + 1;\n    }\n\nprivate:\n\n    std::set<std::pair<T,\
    \ T>> m_rg;\n\n    std::multiset<T> m_set;\n};\n\n} // namespace zawa\n#line 5\
    \ \"Test/AtCoder/abc330_e.test.cpp\"\n\n#include <iostream>\n\nusing namespace\
    \ std;\nint N, Q, A[200020];\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n\
    \    cout.tie(0);\n    ios::sync_with_stdio(0);\n    cin >> N >> Q;\n    zawa::MexManager<int>\
    \ mex;\n    for (int i = 0 ; i < N ; i++) {\n        std::cin >> A[i];\n     \
    \   mex.insert(A[i]);\n    }\n    while (Q--) {\n        int i, x;\n        cin\
    \ >> i >> x;\n        i--;\n        mex.erase(A[i]);\n        mex.insert(x);\n\
    \        A[i] = x;\n        cout << mex() << '\\n';\n    }\n#else\n    cout <<\
    \ \"Hello World\\n\"; \n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc330/tasks/abc330_e\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/DataStructure/Other/MexManager.hpp\"\n\n#include <iostream>\n\
    \nusing namespace std;\nint N, Q, A[200020];\nint main() {\n#ifdef ATCODER\n \
    \   cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n    cin >> N\
    \ >> Q;\n    zawa::MexManager<int> mex;\n    for (int i = 0 ; i < N ; i++) {\n\
    \        std::cin >> A[i];\n        mex.insert(A[i]);\n    }\n    while (Q--)\
    \ {\n        int i, x;\n        cin >> i >> x;\n        i--;\n        mex.erase(A[i]);\n\
    \        mex.insert(x);\n        A[i] = x;\n        cout << mex() << '\\n';\n\
    \    }\n#else\n    cout << \"Hello World\\n\"; \n#endif\n}\n"
  dependsOn:
  - Src/DataStructure/Other/MexManager.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc330_e.test.cpp
  requiredBy: []
  timestamp: '2025-08-15 21:25:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc330_e.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc330_e.test.cpp
- /verify/Test/AtCoder/abc330_e.test.cpp.html
title: Test/AtCoder/abc330_e.test.cpp
---
