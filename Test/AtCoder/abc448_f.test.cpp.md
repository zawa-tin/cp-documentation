---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/Mo.hpp
    title: Src/Utility/Mo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/abc448/submissions/74165490
    - https://atcoder.jp/contests/abc448/tasks/abc448_f
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/AtCoder/abc448_f.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc448/tasks/abc448_f\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n/*\n * AtCoder Beginner Contest 448 - F Authentic Traveling Salesman Problem\n\
    \ * https://atcoder.jp/contests/abc448/submissions/74165490\n */\n\n#line 2 \"\
    Src/Utility/Mo.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n\
    #include <cstddef>\n\nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32\
    \ = std::int32_t;\nusing i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing\
    \ u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\n} // namespace zawa\n\
    #line 4 \"Src/Utility/Mo.hpp\"\n\n#include <algorithm>\n#include <cmath>\n#include\
    \ <concepts>\n#include <ranges>\n#include <utility>\n#include <numeric>\n#include\
    \ <limits>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <std::signed_integral\
    \ T>\nstd::vector<usize> Mo(const std::vector<std::pair<T,T>>& P) {\n    if (P.empty())\n\
    \        return {};\n    T minY = std::numeric_limits<T>::max();\n    const u64\
    \ W = [&]() {\n        T minX = std::numeric_limits<T>::max();\n        T maxX\
    \ = std::numeric_limits<T>::min(), maxY = std::numeric_limits<T>::min();\n   \
    \     for (auto [x,y] : P) {\n            minX = std::min(minX,x);\n         \
    \   maxX = std::max(maxX,x);\n            minY = std::min(minY,y);\n         \
    \   maxY = std::max(maxY,y);\n        }\n        return std::max<u64>({1,u64(maxX-minX),u64(maxY-minY)});\n\
    \    }();\n    const usize B = [&]() {\n        u64 sq = std::max<u64>(1,sqrt(P.size()));\n\
    \        return (W + sq - 1) / sq;\n    }();\n    T sub = minY;\n    auto makeRank\
    \ = [&]() -> std::vector<std::pair<T,T>> {\n        std::vector<std::pair<T,T>>\
    \ res(P.size());\n        for (usize i = 0 ; i < P.size() ; i++) {\n         \
    \   res[i].first = (P[i].second - sub) / B;\n            res[i].second = (res[i].first\
    \ & 1 ? -1 : 1) * P[i].first;\n        }\n        return res;\n    };\n    std::vector<usize>\
    \ ord1(P.size()), ord2(P.size());\n    std::iota(ord1.begin(),ord1.end(),0);\n\
    \    std::iota(ord2.begin(),ord2.end(),0);\n    auto rank = makeRank();\n    std::ranges::sort(ord1,[&](usize\
    \ i, usize j) { return rank[i] < rank[j]; });\n    sub -= B / 2;\n    rank = makeRank();\n\
    \    std::ranges::sort(ord2,[&](usize i, usize j) { return rank[i] < rank[j];\
    \ });\n    auto cost = [&](const std::vector<usize>& ord) {\n        u64 res =\
    \ 0;\n        for (usize i = 0 ; i + 1 < ord.size() ; i++) {\n            res\
    \ += abs(P[ord[i+1]].first-P[ord[i]].first);\n            res += abs(P[ord[i+1]].second-P[ord[i]].second);\n\
    \        }\n        return res;\n    };\n    return cost(ord1) <= cost(ord2) ?\
    \ ord1 : ord2;\n}\n\n} // namespace zawa\n#line 10 \"Test/AtCoder/abc448_f.test.cpp\"\
    \n#include <iostream>\n#line 12 \"Test/AtCoder/abc448_f.test.cpp\"\n#include <cassert>\n\
    #line 17 \"Test/AtCoder/abc448_f.test.cpp\"\nusing namespace std;\nint main()\
    \ {\n#ifdef ATCODER\n    int N;\n    cin >> N;\n    vector<pair<int,int>> P(N);\n\
    \    for (auto& [x,y] : P)\n        cin >> x >> y;\n    auto ans = zawa::Mo(P);\n\
    \    ranges::rotate(ans,ranges::find(ans,0));\n    long long cost = 0;\n    for\
    \ (int i = 0 ; i < ssize(ans) ; i++) {\n        int j = ans[i], k = ans[(i+1)%N];\n\
    \        cost += abs(P[j].first-P[k].first);\n        cost += abs(P[j].second-P[k].second);\n\
    \    }\n    assert(cost <= (long long)7.5e9);\n    for (int i = 0 ; i < ssize(ans)\
    \ ; i++)\n        cout << ++ans[i] << (i + 1 == ssize(ans) ? '\\n' : ' ');\n#else\n\
    \    int a,b;\n    cin >> a >> b;\n    cout << a+b << '\\n';\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc448/tasks/abc448_f\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n/*\n * AtCoder Beginner\
    \ Contest 448 - F Authentic Traveling Salesman Problem\n * https://atcoder.jp/contests/abc448/submissions/74165490\n\
    \ */\n\n#include \"../../Src/Utility/Mo.hpp\"\n#include <iostream>\n#include <cmath>\n\
    #include <cassert>\n#include <vector>\n#include <algorithm>\n#include <ranges>\n\
    #include <utility>\nusing namespace std;\nint main() {\n#ifdef ATCODER\n    int\
    \ N;\n    cin >> N;\n    vector<pair<int,int>> P(N);\n    for (auto& [x,y] : P)\n\
    \        cin >> x >> y;\n    auto ans = zawa::Mo(P);\n    ranges::rotate(ans,ranges::find(ans,0));\n\
    \    long long cost = 0;\n    for (int i = 0 ; i < ssize(ans) ; i++) {\n     \
    \   int j = ans[i], k = ans[(i+1)%N];\n        cost += abs(P[j].first-P[k].first);\n\
    \        cost += abs(P[j].second-P[k].second);\n    }\n    assert(cost <= (long\
    \ long)7.5e9);\n    for (int i = 0 ; i < ssize(ans) ; i++)\n        cout << ++ans[i]\
    \ << (i + 1 == ssize(ans) ? '\\n' : ' ');\n#else\n    int a,b;\n    cin >> a >>\
    \ b;\n    cout << a+b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Utility/Mo.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc448_f.test.cpp
  requiredBy: []
  timestamp: '2026-03-16 19:40:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc448_f.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc448_f.test.cpp
- /verify/Test/AtCoder/abc448_f.test.cpp.html
title: Test/AtCoder/abc448_f.test.cpp
---
