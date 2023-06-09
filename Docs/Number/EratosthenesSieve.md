---
title: エラトステネスの篩
documentation_of: "//Src/Number/EratosthenesSieve.hpp"
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
