---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/agc002_d.test.cpp
    title: Test/AtCoder/agc002_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Utility/ParallelBinarySearch.hpp\"\n\n#include <cassert>\n\
    #include <concepts>\n#include <utility>\n#include <vector>\n\nnamespace zawa {\n\
    \ntemplate <std::integral T, class F>\nstd::vector<T> ParallelBinarySearch(std::vector<T>\
    \ oks, std::vector<T> ngs, F f) {\n    assert(oks.size() == ngs.size());\n   \
    \ while (true) {\n        std::vector<std::pair<T, usize>> remains; \n       \
    \ std::vector<usize> inv(oks.size(), static_cast<usize>(-1));\n        for (usize\
    \ i = 0 ; i < oks.size() ; i++) if ((oks[i] >= ngs[i] ? oks[i] - ngs[i] : ngs[i]\
    \ - oks[i]) > T{1}) {\n            T mid = (oks[i]&ngs[i]) + ((oks[i]^ngs[i])>>1);\n\
    \            inv[i] = remains.size();\n            remains.push_back({mid, i});\n\
    \        }\n        if (remains.empty()) break;\n        auto res = f(remains);\n\
    \        assert(res.size() == remains.size());\n        for (usize i = 0 ; i <\
    \ res.size() ; i++) {\n            T mid = remains[inv[res[i].second]].first;\n\
    \            if (res[i].first) oks[res[i].second] = mid;\n            else ngs[res[i].second]\
    \ = mid;\n            i++;\n        }\n    } \n    return oks;\n}\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include <cassert>\n#include <concepts>\n#include <utility>\n\
    #include <vector>\n\nnamespace zawa {\n\ntemplate <std::integral T, class F>\n\
    std::vector<T> ParallelBinarySearch(std::vector<T> oks, std::vector<T> ngs, F\
    \ f) {\n    assert(oks.size() == ngs.size());\n    while (true) {\n        std::vector<std::pair<T,\
    \ usize>> remains; \n        std::vector<usize> inv(oks.size(), static_cast<usize>(-1));\n\
    \        for (usize i = 0 ; i < oks.size() ; i++) if ((oks[i] >= ngs[i] ? oks[i]\
    \ - ngs[i] : ngs[i] - oks[i]) > T{1}) {\n            T mid = (oks[i]&ngs[i]) +\
    \ ((oks[i]^ngs[i])>>1);\n            inv[i] = remains.size();\n            remains.push_back({mid,\
    \ i});\n        }\n        if (remains.empty()) break;\n        auto res = f(remains);\n\
    \        assert(res.size() == remains.size());\n        for (usize i = 0 ; i <\
    \ res.size() ; i++) {\n            T mid = remains[inv[res[i].second]].first;\n\
    \            if (res[i].first) oks[res[i].second] = mid;\n            else ngs[res[i].second]\
    \ = mid;\n            i++;\n        }\n    } \n    return oks;\n}\n\n} // namespace\
    \ zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Utility/ParallelBinarySearch.hpp
  requiredBy: []
  timestamp: '2025-02-24 03:31:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/agc002_d.test.cpp
documentation_of: Src/Utility/ParallelBinarySearch.hpp
layout: document
title: "\u4E26\u5217\u4E8C\u5206\u63A2\u7D22"
---

## ライブラリの使い方

```
template <class T, class F>
std::vector<T> ParallelBinarySearch(std::vector<T> oks, std::vector<T> ngs, F f) {
```

#### T

整数型のみ

#### oks, ngs

$i$ 個目のクエリの必ず条件を満たす値、必ず条件を満たさない値

#### f

以下の条件を満たす関数。

その一。`f`には引数として、まだ探索が終わっていないクエリの`std::pair<T, usize>{x, id}`のvectorが突っ込まれる。
引数のvector内部の`{x, id}`について、`id`番目のクエリの`x`の場合の判定問題を解く必要がある。

その二。返り値として、`std::pair<bool, hoge>`{T/F, id}`のvectorを入れる。firstは判定問題の結果。secondはそれが何番目のクエリかの添字。

## 計算量

$O(\max_{i} L)$ 回、`f`が呼ばれ、別途に $O(Q)$ の処理が入る。

テストを見る感じ、直書きするよりもだいぶ実測が遅い...
