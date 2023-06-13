---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/enumerate_primes.test.cpp
    title: Test/LC/enumerate_primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Number/EratosthenesSieve.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Number/EratosthenesSieve.hpp\"\n\n#include\
    \ <vector>\n#include <cassert>\n#include <algorithm>\n\nnamespace zawa {\n\nclass\
    \ EratosthenesSieve {\nprivate:\n    usize tableSize_;\n    std::vector<bool>\
    \ table_;\n\npublic:\n    EratosthenesSieve() = default;\n\n    EratosthenesSieve(usize\
    \ tableSize) : tableSize_{ tableSize + 1 }, table_(tableSize + 1, true) {\n  \
    \      table_.shrink_to_fit();\n        assert(tableSize_ > 0);\n        table_[0]\
    \ = table_[1] = false;\n        for (u64 i = 2 ; i * i < tableSize_ ; i++) {\n\
    \            if (!table_[i]) continue;\n            for (u64 j = i * i ; j < tableSize_\
    \ ; j += i ) {\n                table_[j] = false;\n            }\n        }\n\
    \    }\n\n    inline bool operator[](u32 i) const {\n        assert(i < tableSize_);\n\
    \        return table_[i];\n    }\n\n    inline bool isPrime(u32 i) const {\n\
    \        assert(i < tableSize_);\n        return table_[i];\n    }\n\n    inline\
    \ usize size() const {\n        return tableSize_ - 1;\n    }\n\n    std::vector<u32>\
    \ enumeratePrimes(u32 N) const {\n        assert(N < tableSize_);\n        std::vector<u32>\
    \ primes{};\n        primes.reserve(std::count(table_.begin(), table_.begin()\
    \ + N + 1, true));\n        for (u32 i = 2 ; i <= N ; i++) {\n            if (table_[i])\
    \ {\n                primes.emplace_back(i);\n            }\n        }\n     \
    \   return primes;\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n#include <algorithm>\n\nnamespace zawa {\n\nclass EratosthenesSieve\
    \ {\nprivate:\n    usize tableSize_;\n    std::vector<bool> table_;\n\npublic:\n\
    \    EratosthenesSieve() = default;\n\n    EratosthenesSieve(usize tableSize)\
    \ : tableSize_{ tableSize + 1 }, table_(tableSize + 1, true) {\n        table_.shrink_to_fit();\n\
    \        assert(tableSize_ > 0);\n        table_[0] = table_[1] = false;\n   \
    \     for (u64 i = 2 ; i * i < tableSize_ ; i++) {\n            if (!table_[i])\
    \ continue;\n            for (u64 j = i * i ; j < tableSize_ ; j += i ) {\n  \
    \              table_[j] = false;\n            }\n        }\n    }\n\n    inline\
    \ bool operator[](u32 i) const {\n        assert(i < tableSize_);\n        return\
    \ table_[i];\n    }\n\n    inline bool isPrime(u32 i) const {\n        assert(i\
    \ < tableSize_);\n        return table_[i];\n    }\n\n    inline usize size()\
    \ const {\n        return tableSize_ - 1;\n    }\n\n    std::vector<u32> enumeratePrimes(u32\
    \ N) const {\n        assert(N < tableSize_);\n        std::vector<u32> primes{};\n\
    \        primes.reserve(std::count(table_.begin(), table_.begin() + N + 1, true));\n\
    \        for (u32 i = 2 ; i <= N ; i++) {\n            if (table_[i]) {\n    \
    \            primes.emplace_back(i);\n            }\n        }\n        return\
    \ primes;\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Number/EratosthenesSieve.hpp
  requiredBy: []
  timestamp: '2023-06-13 11:55:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/enumerate_primes.test.cpp
documentation_of: Src/Number/EratosthenesSieve.hpp
layout: document
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---

## 概要

指定された正整数 $S$ 以下の全ての非負整数が、素数であるか素数でないかを判定し、結果を配列で保持します。

例えば、 $S = 5$ ならば、 $\\{\ \text{false}, \text{false}, \text{true}, \text{true}, \text{false}, \text{true}\ \\}$ です。

## ライブラリの説明

#### コンストラクタ
```
(1) EratosthenesSieve()
(2) EratosthenesSieve(usize tableSize)
```

(1) デフォルトコンストラクタ  
(2) $S =$ `tableSize`として配列を構築します。

**計算量:** $O(S\log (\log S))$


#### operator[]
```
inline bool operator[](u32 i) const
```
整数 $i$ が素数であるかを判定します。


**制約:** $i\ \le\ S$

**計算量:** 定数時間


#### isPrime
```
inline bool isPrime(u32 i) const
```
整数 $i$ が素数であるかを判定します。
- `operator[]`と同じです。(タイピング量的には`[]`を使った方が良いです)


**制約:** $i\ \le\ S$

**計算量:** 定数時間

#### size
```
inline usize size() const
```
素数判定できる最大の整数、すなわち $S$ を返します。


**計算量:** 定数時間

#### enumeratePrimes
```
std::vector<u32> enumeratePrimes(u32 N) const
```
$N$ 以下の素数を昇順に列挙します。

**制約:** $N\ \le\ S$

**計算量:** $O(N)$


## アルゴリズム

エラトステネスの篩アルゴリズムを利用しています。

エラトステネスの篩アルゴリズム
```
目標: S 以下の非負整数 i について、 i が素数なら A_i = true 、素数でないなら A_i = false であるような列 A を構築することを考える。

ステップ1: A の全ての要素を \text{true} で初期化する。
ステップ2: A_1 = \text{false}$ とする。
ステップ3: A を昇順に走査する、 A_i が true なら A_{2i}, A_{3i}, A_{4i}, ... に false を代入する。 A_i = false なら何もせず次に進む。
ステップ4: i^2\ >\ S となったら走査を打ち切る。

```

このアルゴリズムの計算量は $O(S\log (\log S))$ です。素数の逆数和が $O(\log (\log S))$ の発散スピードが $\log (\log S)$ であることが由来しています。
- 勉強不足ゆえ、発散スピードが $\log (\log S)$ になる証明を追えていません....
- グーグル検索をかけると、例えば以下のような解説がでてきます。厳密なものは書籍等にたよった方が良さそう..?
   - [Mathlog](https://mathlog.info/articles/1453)
   - [高校数学の美しい物語](https://manabitimes.jp/math/920)
   - [Wikipedia Mertens' theorems](https://ja.wikipedia.org/wiki/%E3%83%A1%E3%83%AB%E3%83%86%E3%83%B3%E3%82%B9%E3%81%AE%E5%AE%9A%E7%90%86)


## メモ1

$S$ 以下の素数を線形時間で列挙できる線形篩というアルゴリズムが存在します。

じゃあ線形篩を使えよという話になりそうですが、線形篩はテーブルの構築に各整数の最小素因数を必要とします。
- エラトステネスの篩は素数か否かの真理値のみでテーブルが構築できるので、メモリ面ではエラトステネスの篩に軍配があがります。

本ライブラリでは、 $S$ 以下の整数を約数列挙・素因数分解せよ等といったクエリ処理には線形篩を、素数判定にはエラトステネスの篩を採用する予定です。

## メモ2

エラトステネスの篩、線形篩の他にもアトキンの篩や、サンダラムの篩といった素数列挙アルゴリズムがあるそうです。
- 勉強したら本ライブラリに実装します。
