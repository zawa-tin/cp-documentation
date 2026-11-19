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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc384_g.test.cpp
    title: Test/AtCoder/abc384_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc405.test.cpp
    title: Test/AtCoder/abc405.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/CF/CF974-H.test.cpp
    title: Test/CF/CF974-H.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/static_range_frequency.test.cpp
    title: Test/LC/static_range_frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Sequence/MoRangeQuery.hpp\"\n\n#include <algorithm>\n\
    #include <concepts>\n#include <ranges>\n\n#line 2 \"Src/Utility/Mo.hpp\"\n\n#line\
    \ 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Utility/Mo.hpp\"\
    \n\n#line 6 \"Src/Utility/Mo.hpp\"\n#include <cmath>\n#line 9 \"Src/Utility/Mo.hpp\"\
    \n#include <utility>\n#include <numeric>\n#include <limits>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <std::signed_integral T>\nstd::vector<usize> Mo(const\
    \ std::vector<std::pair<T,T>>& P) {\n    if (P.empty())\n        return {};\n\
    \    T minY = std::numeric_limits<T>::max();\n    const u64 W = [&]() {\n    \
    \    T minX = std::numeric_limits<T>::max();\n        T maxX = std::numeric_limits<T>::min(),\
    \ maxY = std::numeric_limits<T>::min();\n        for (auto [x,y] : P) {\n    \
    \        minX = std::min(minX,x);\n            maxX = std::max(maxX,x);\n    \
    \        minY = std::min(minY,y);\n            maxY = std::max(maxY,y);\n    \
    \    }\n        return std::max<u64>({1,u64(maxX-minX),u64(maxY-minY)});\n   \
    \ }();\n    const usize B = [&]() {\n        u64 sq = std::max<u64>(1,sqrt(P.size()));\n\
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
    \ ord1 : ord2;\n}\n\n} // namespace zawa\n#line 8 \"Src/Sequence/MoRangeQuery.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <std::signed_integral T, class AddL, class AddR,\
    \ class DelL, class DelR, class Eval>\nstd::vector<typename std::invoke_result_t<Eval,\
    \ usize>> Mo(const std::vector<std::pair<T,T>>& qs, AddL addL, AddR addR, DelL\
    \ delL, DelR delR, Eval eval, bool reset = false) {\n    auto ord = Mo(qs);\n\
    \    std::vector<typename std::invoke_result_t<Eval, usize>> res(qs.size());\n\
    \    T L = 0, R = 0;\n    for (usize i : ord) {\n        const auto [l, r] = qs[i];\n\
    \        while (R < r) \n            addR(R++);\n        while (L > l) \n    \
    \        addL(--L);\n        while (R > r) \n            delR(--R);\n        while\
    \ (L < l) \n            delL(L++);\n        res[i] = eval(i);\n    }\n    if (reset)\
    \ \n        while (R > L) \n            delR(--R);\n    return res;\n}\n\n} //\
    \ namespace zawa\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <concepts>\n#include <ranges>\n\
    \n#include \"../Utility/Mo.hpp\"\n\nnamespace zawa {\n\ntemplate <std::signed_integral\
    \ T, class AddL, class AddR, class DelL, class DelR, class Eval>\nstd::vector<typename\
    \ std::invoke_result_t<Eval, usize>> Mo(const std::vector<std::pair<T,T>>& qs,\
    \ AddL addL, AddR addR, DelL delL, DelR delR, Eval eval, bool reset = false) {\n\
    \    auto ord = Mo(qs);\n    std::vector<typename std::invoke_result_t<Eval, usize>>\
    \ res(qs.size());\n    T L = 0, R = 0;\n    for (usize i : ord) {\n        const\
    \ auto [l, r] = qs[i];\n        while (R < r) \n            addR(R++);\n     \
    \   while (L > l) \n            addL(--L);\n        while (R > r) \n         \
    \   delR(--R);\n        while (L < l) \n            delL(L++);\n        res[i]\
    \ = eval(i);\n    }\n    if (reset) \n        while (R > L) \n            delR(--R);\n\
    \    return res;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Utility/Mo.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Sequence/MoRangeQuery.hpp
  requiredBy: []
  timestamp: '2026-03-16 19:40:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/static_range_frequency.test.cpp
  - Test/CF/CF974-H.test.cpp
  - Test/AtCoder/abc405.test.cpp
  - Test/AtCoder/abc384_g.test.cpp
documentation_of: Src/Sequence/MoRangeQuery.hpp
layout: document
title: Mo's algorithm
---

## 概要

Mo's Algorithm

## ライブラリの使い方

```cpp
template <std::signed_integral T, class AddL, class AddR, class DelL, class DelR, class Eval>
std::vector<typename std::invoke_result_t<Eval, usize>> Mo(const std::vector<std::pair<T,T>>& qs, AddL addL, AddR addR, DelL delL, DelR delR, Eval eval, bool reset = false) {
```

#### T

クエリで与えられる区間の型

- `first`が半開区間の左端、`secondr`が半開区間の右端を意味する
- 内部の`Mo`アルゴリズムの都合上符号付整数である必要がある。区間クエリの用途に限らなければ、符号さえがついていれば浮動小数でもよいのだが、そういうコンセプトを知らなかったので整数になっている。


#### addL addR

それぞれ要素 $i$ を左 or 右に追加するときの処理を実行する関数オブジェクト。

注意すべきは、ライブラリが`addL, addR`に渡す引数は数列**添字**や木の**頂点番号**に値するものであることに注意。

例えば、Range Count Distinctなら

```cpp
auto add = [&](int i) { cnt[A[i]]++; } // cnt[i]++は間違い
```

のようにする。

#### delL delR

それぞれ要素 $i$ が左/右端にあるとき、これを削除するときの処理を行う関数オブジェクト

#### eval

$i$ 番目のクエリを処理する際の関数オブジェクト

- 返り値を持つ必要がある

#### reset

データ処理の最後に、残った要素をすべて`del`したいときにtrueを指定する。

- 例えばmulti test caseの問題で利用する(CF974-H.test)

#### 参考

- [An alternative sorting order for Mo's algorithm](https://codeforces.com/blog/entry/61203)
- [Mo's algorithm で解ける問題](https://37zigen.com/mos-algorithm-%E3%81%A7%E8%A7%A3%E3%81%91%E3%82%8B%E5%95%8F%E9%A1%8C/)
- [Mo's algorithm](https://take44444.github.io/Algorithm-Book/range/mo/main.html)
- [Mo's algorithm](https://ei1333.hateblo.jp/entry/2017/09/11/211011)
- [定数倍が最適なMo's Algorithm](https://noshi91.hatenablog.com/entry/2023/04/13/224811)
    - これを採用している。ABC448-Fでは距離の総和が最大ケースにおいて $\9\times 10^9$ 程度であるものが $7.5\times 10^9$ 程度に削減されていることを確認した。
    - しかし、区間クエリに投げると前の実装(Hilbert Curve)より実測がかかっており厳しい気持ちに。思ったより`Mo`の順序の計算にネックがある可能性がある？
