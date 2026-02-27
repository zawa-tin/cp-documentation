---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc384_g.test.cpp
    title: Test/AtCoder/abc384_g.test.cpp
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
    links:
    - https://codeforces.com/blog/entry/61203?#comment-1064868
  bundledCode: "#line 2 \"Src/DataStructure/Mo/Mo.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/DataStructure/Mo/Mo.hpp\"\n\n#include <algorithm>\n\
    #include <bit>\n#include <cassert>\n#include <vector>\n#include <type_traits>\n\
    \nnamespace zawa {\n\nnamespace internal {\n\n// reference: https://codeforces.com/blog/entry/61203?#comment-1064868\n\
    u64 hilbertOrder(u64 x, u64 y, usize dim) {\n    const u64 max{(1ull << dim) -\
    \ 1};\n    assert(x <= max);\n    assert(y <= max);\n    u64 res{};\n    for (u64\
    \ s{1ull << (dim - 1)} ; s ; s >>= 1) {\n        bool rx{static_cast<bool>(x &\
    \ s)}, ry{static_cast<bool>(y & s)};\n        res = (res << 2) | (rx ? ry ? 2\
    \ : 1 : ry ? 3 : 0);\n        if (!rx) {\n            if (ry) x ^= max, y ^= max;\n\
    \            std::swap(x, y);\n        }\n    }\n    return res;\n}\n\n} // namespace\
    \ internal\n\ntemplate <class T, class AddL, class AddR, class DelL, class DelR,\
    \ class Eval>\nstd::vector<typename std::invoke_result_t<Eval, usize>> Mo(std::vector<T>\
    \ qs, AddL addL, AddR addR, DelL delL, DelR delR, Eval eval, bool reset = false)\
    \ {\n    usize log{};\n    for (const T& lr : qs) log = std::max<usize>(log, std::bit_width(lr.r));\n\
    \    std::vector<std::pair<T, usize>> ord(qs.size());\n    std::vector<u64> h(qs.size());\n\
    \    for (usize i{} ; i < qs.size() ; i++) {\n        ord[i] = {qs[i], i};\n \
    \       h[i] = internal::hilbertOrder(qs[i].l, qs[i].r, log);\n    }\n    std::sort(ord.begin(),\
    \ ord.end(), [&](const auto& L, const auto& R) -> bool {\n            return h[L.second]\
    \ < h[R.second];\n            });\n    std::vector<typename std::invoke_result_t<Eval,\
    \ usize>> res(qs.size());\n    usize L{}, R{};\n    for (const auto& [lr, id]\
    \ : ord) {\n        while (R < lr.r) addR(R++);\n        while (L > lr.l) addL(--L);\n\
    \        while (R > lr.r) delR(--R);\n        while (L < lr.l) delL(L++);\n  \
    \      res[id] = eval(id);\n    }\n    if (reset) while (R > L) delR(--R);\n \
    \   return res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <bit>\n#include <cassert>\n#include <vector>\n#include <type_traits>\n\
    \nnamespace zawa {\n\nnamespace internal {\n\n// reference: https://codeforces.com/blog/entry/61203?#comment-1064868\n\
    u64 hilbertOrder(u64 x, u64 y, usize dim) {\n    const u64 max{(1ull << dim) -\
    \ 1};\n    assert(x <= max);\n    assert(y <= max);\n    u64 res{};\n    for (u64\
    \ s{1ull << (dim - 1)} ; s ; s >>= 1) {\n        bool rx{static_cast<bool>(x &\
    \ s)}, ry{static_cast<bool>(y & s)};\n        res = (res << 2) | (rx ? ry ? 2\
    \ : 1 : ry ? 3 : 0);\n        if (!rx) {\n            if (ry) x ^= max, y ^= max;\n\
    \            std::swap(x, y);\n        }\n    }\n    return res;\n}\n\n} // namespace\
    \ internal\n\ntemplate <class T, class AddL, class AddR, class DelL, class DelR,\
    \ class Eval>\nstd::vector<typename std::invoke_result_t<Eval, usize>> Mo(std::vector<T>\
    \ qs, AddL addL, AddR addR, DelL delL, DelR delR, Eval eval, bool reset = false)\
    \ {\n    usize log{};\n    for (const T& lr : qs) log = std::max<usize>(log, std::bit_width(lr.r));\n\
    \    std::vector<std::pair<T, usize>> ord(qs.size());\n    std::vector<u64> h(qs.size());\n\
    \    for (usize i{} ; i < qs.size() ; i++) {\n        ord[i] = {qs[i], i};\n \
    \       h[i] = internal::hilbertOrder(qs[i].l, qs[i].r, log);\n    }\n    std::sort(ord.begin(),\
    \ ord.end(), [&](const auto& L, const auto& R) -> bool {\n            return h[L.second]\
    \ < h[R.second];\n            });\n    std::vector<typename std::invoke_result_t<Eval,\
    \ usize>> res(qs.size());\n    usize L{}, R{};\n    for (const auto& [lr, id]\
    \ : ord) {\n        while (R < lr.r) addR(R++);\n        while (L > lr.l) addL(--L);\n\
    \        while (R > lr.r) delR(--R);\n        while (L < lr.l) delL(L++);\n  \
    \      res[id] = eval(id);\n    }\n    if (reset) while (R > L) delR(--R);\n \
    \   return res;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/Mo/Mo.hpp
  requiredBy: []
  timestamp: '2025-04-14 13:20:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/static_range_frequency.test.cpp
  - Test/CF/CF974-H.test.cpp
  - Test/AtCoder/abc384_g.test.cpp
documentation_of: Src/DataStructure/Mo/Mo.hpp
layout: document
title: Mo's algorithm
---

## 概要

Mo's Algorithm

## ライブラリの使い方

```cpp
template <class T, class AddL, class AddR, class DelL, class DelR, class Eval>
std::vector<typename std::invoke_result_t<Eval, usize>> Mo(std::vector<T> qs, AddL addL, AddR addR, DelL delL, DelR delR, Eval eval, bool reset = false) {
```

#### T

クエリで与えられる区間の型

- **符号なし整数型**のメンバ変数`l`、`r`をpublic下に持つクラスである必要がある
- `l`が半開区間の左端、`r`が半開区間の右端を意味する

`T`は基本的には以下をコピれば問題無いはず。

```cpp
struct query {
    usize l, r;
};
```

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
