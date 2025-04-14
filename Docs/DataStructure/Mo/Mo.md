---
title: Mo's algorithm
documentation_of: //Src/DataStructure/Mo/Mo.hpp
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
