---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/static_range_mode_query.test.cpp
    title: Test/LC/static_range_mode_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/Mo/RollbackMo.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/DataStructure/Mo/RollbackMo.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <concepts>\n#include <limits>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class T, class\
    \ RBT, class Add, class Rollback, class Eval>\nstd::vector<typename std::invoke_result_t<Eval,\
    \ usize, const RBT&>> RollbackMo(const std::vector<T>& qs, Add addL, Add addR,\
    \ Rollback rollback, Eval eval) {\n    const usize n = [&]() {\n        usize\
    \ mx = 0;\n        for (usize i = 0 ; i < qs.size() ; i++) {\n            assert(qs[i].l\
    \ <= qs[i].r);\n            mx = std::max<usize>(mx, qs[i].r);\n        }\n  \
    \      return mx;\n    }();\n    const usize SQ = [&]() {\n        usize i = 1;\n\
    \        while (i * i < n)\n            i++;\n        return i;\n    }();\n  \
    \  std::vector<std::vector<std::pair<usize, usize>>> rs((n + SQ - 1) / SQ);\n\
    \    std::vector<typename std::invoke_result_t<Eval, usize, const RBT&>> res(qs.size());\n\
    \    std::vector<RBT> history;\n    history.emplace_back();\n    for (usize i\
    \ = 0 ; i < qs.size() ; i++) {\n        if (qs[i].r - qs[i].l <= SQ) {\n     \
    \       for (usize j = qs[i].l ; j < qs[i].r ; j++)\n                history.push_back(addR(j,\
    \ history.back()));\n            res[i] = eval(i, history.back());\n         \
    \   for (usize j = qs[i].l ; j < qs[i].r ; j++) {\n                rollback(history.back());\n\
    \                history.pop_back();\n            }\n        }\n        else\n\
    \            rs[qs[i].l / SQ].emplace_back(qs[i].r, i);\n    }\n    for (usize\
    \ i = 0 ; i < rs.size() ; i++)\n        if (rs[i].size()) {\n            std::sort(rs[i].begin(),\
    \ rs[i].end());\n            const usize L = (i + 1) * SQ;\n            usize\
    \ R = L;\n            for (auto [r, idx] : rs[i]) {\n                while (R\
    \ < r)\n                    history.push_back(addR(R++, history.back()));\n  \
    \              for (usize j = L ; j > qs[idx].l ; )\n                    history.push_back(addL(--j,\
    \ history.back()));\n                res[idx] = eval(i, history.back());\n   \
    \             for (usize j = L ; j > qs[idx].l ; j--) {\n                    rollback(history.back());\n\
    \                    history.pop_back();\n                }\n            }\n \
    \           for (usize j = L ; j < R ; j++) {\n                rollback(history.back());\n\
    \                history.pop_back();\n            }\n        }\n    return res;\n\
    }\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <concepts>\n#include <limits>\n#include <utility>\n\
    #include <vector>\n\nnamespace zawa {\n\ntemplate <class T, class RBT, class Add,\
    \ class Rollback, class Eval>\nstd::vector<typename std::invoke_result_t<Eval,\
    \ usize, const RBT&>> RollbackMo(const std::vector<T>& qs, Add addL, Add addR,\
    \ Rollback rollback, Eval eval) {\n    const usize n = [&]() {\n        usize\
    \ mx = 0;\n        for (usize i = 0 ; i < qs.size() ; i++) {\n            assert(qs[i].l\
    \ <= qs[i].r);\n            mx = std::max<usize>(mx, qs[i].r);\n        }\n  \
    \      return mx;\n    }();\n    const usize SQ = [&]() {\n        usize i = 1;\n\
    \        while (i * i < n)\n            i++;\n        return i;\n    }();\n  \
    \  std::vector<std::vector<std::pair<usize, usize>>> rs((n + SQ - 1) / SQ);\n\
    \    std::vector<typename std::invoke_result_t<Eval, usize, const RBT&>> res(qs.size());\n\
    \    std::vector<RBT> history;\n    history.emplace_back();\n    for (usize i\
    \ = 0 ; i < qs.size() ; i++) {\n        if (qs[i].r - qs[i].l <= SQ) {\n     \
    \       for (usize j = qs[i].l ; j < qs[i].r ; j++)\n                history.push_back(addR(j,\
    \ history.back()));\n            res[i] = eval(i, history.back());\n         \
    \   for (usize j = qs[i].l ; j < qs[i].r ; j++) {\n                rollback(history.back());\n\
    \                history.pop_back();\n            }\n        }\n        else\n\
    \            rs[qs[i].l / SQ].emplace_back(qs[i].r, i);\n    }\n    for (usize\
    \ i = 0 ; i < rs.size() ; i++)\n        if (rs[i].size()) {\n            std::sort(rs[i].begin(),\
    \ rs[i].end());\n            const usize L = (i + 1) * SQ;\n            usize\
    \ R = L;\n            for (auto [r, idx] : rs[i]) {\n                while (R\
    \ < r)\n                    history.push_back(addR(R++, history.back()));\n  \
    \              for (usize j = L ; j > qs[idx].l ; )\n                    history.push_back(addL(--j,\
    \ history.back()));\n                res[idx] = eval(i, history.back());\n   \
    \             for (usize j = L ; j > qs[idx].l ; j--) {\n                    rollback(history.back());\n\
    \                    history.pop_back();\n                }\n            }\n \
    \           for (usize j = L ; j < R ; j++) {\n                rollback(history.back());\n\
    \                history.pop_back();\n            }\n        }\n    return res;\n\
    }\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/Mo/RollbackMo.hpp
  requiredBy: []
  timestamp: '2025-09-26 03:53:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/static_range_mode_query.test.cpp
documentation_of: Src/DataStructure/Mo/RollbackMo.hpp
layout: document
title: Rollback Mo
---

## 概要

Rollback Mo

Moから`del`関数を`rollback`に置き換えられるように工夫したMo's Algorithm。

## ライブラリの使い方

```cpp
template <class T, class RBT, class Add, class Rollback, class Eval>
std::vector<typename std::invoke_result_t<Eval, usize, const RBT&>> RollbackMo(const std::vector<T>& qs, Add addL, Add addR, Rollback rollback, Eval eval) {
```

面倒でコンセプトを書いていない(カス)

### T

クエリの区間を表す`class`。以下をコピれば基本的に問題無い。

```cpp
struct Query {
    usize l, r;
};
```

### RBT

ロールバックで管理させるデータを全部`class`にまとめてこれに指定する。

`RBT`の**デフォルトコンストラクタが単位元である必要がある。**

### Add

`usize, RBT`をこの順に引数に取り、`RBT`を返す関数。引数の前者は追加する要素(**添字に値するもの**)、`RBT`は現在のデータが与えられる。

要素を追加した後のデータを返せば良い。

### Rollback

`RBT`を引数に取る関数。引数に与えられたデータを用いて`RBT`で管理できないデータ(配列などの沢山メモリを食べるもの)をロールバックさせる。
- そのため、`RBT`には配列に対する「最後の操作」なども管理させると良い

### Eval

`usize, RBT`をこの順に引数に取る関数。引数の前者はクエリの番号、後者は現在のデータである。

クエリをデータで評価して、評価結果を返せば良い。

### 使用例

例えば区間最頻値クエリをMoに投げるとき、以下のようにする。

```cpp
struct Query {
    usize l, r;
};
struct Data {
    int top = -1, last = -1;
};
vector<int> cnt(ssize(comp));
auto add = [&](int i, Data d) {
    cnt[A[i]]++;
    if (d.top == -1 or cnt[A[i]] > cnt[d.top])
        d.top = A[i];
    d.last = A[i];
    return d;
};
auto rollback = [&](const Data& d) {
    cnt[d.last]--;
};
auto eval = [&](int, const Data& d) -> pair<int, int> {
    return {comp.inverse(d.top), cnt[d.top]};
};
for (auto [a, b] : RollbackMo<Query, Data, decltype(add), decltype(rollback), decltype(eval)>(q, add, add, rollback, eval))
    cout << a << ' ' << b << '\n';
```

## 計算量

以下の合計となる。

- `addL`を $O(Q\sqrt{N})$ 回呼び出す
- `addR`を $O((N + Q)\sqrt{N})$ 回呼び出す
- `addL, addR`を呼び出した回数の合計と同じ回数だけ`rollback`を呼び出す
- `eval`を $Q$ 回呼び出す
- $O((N + Q)\sqrt{N})$ (カウンタの管理など)

ロールバックの管理に関して、`vector<RBT>`を一個用いており、この要素数の最大は実行全体で高々 $N$ 個になる。
