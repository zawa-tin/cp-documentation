---
title: Rollback Mo
documentation_of: //Src/DataStructure/Mo/RollbackMo.hpp
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
