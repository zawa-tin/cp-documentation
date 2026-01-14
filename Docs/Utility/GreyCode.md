---
title: グレイコードによる部分集合列挙
documentation_of: //Src/Utility/GreyCode.hpp
---

# 概要

$0$ 以上 $2^n$ 未満の要素からなる順列であって、任意の隣接する $2$ 要素のpopcountの差が $1$ であるものを取得する。

これによって、例えばbit全探索で $\Theta (N2^{N})$ かかるパートを $O(2^N)$ に改善できる事があるかもしれない。

- あまり頭の良いことをしなくても、例えばDFSで $O(2^N)$ は達成できるのだが、グレイコードをしたほうが定数倍がよさそう

## ライブラリの使い方

### GreyCode

```cpp
std::vector<std::pair<GreyCodeOp, usize>> GreyCode(usize n)
```

順列を得るための操作の命令の列が与えられる。 `GreyCodeOp`とは以下のような`enum class`であり、`second`に入っている非負整数(`idx`と呼ぶ)に応じて以下のような意味がある

```cpp
enum class GreyCodeOp {
    Add, // 2^idxを足す
    Remove, // 2^idxを引く
    Access // 現在idxがある
};
```

**計算量:** $O(2^{n})$

### EnumerateSubsetProduct

```cpp
template <class S, class T>
requires concepts::SetOperator<S, T>
std::vector<typename S::Element> EnumerateSubsetProduct(const std::vector<typename T>& A)
```

先述の`Add, Remove`の演算を`S`に与えたとき、 $2^{n}$ 個の要素を列挙して返す。

返り値の $i$ 番目の要素は $i$ の二進数表示で立っている桁が $S_i = \\{ j_1, j_2, \dots, j_k \\}$ だとしたとき、 $\prod_{j\in S_i} A_j$ である。

テンプレートの雛形

```cpp
struct SPD {
    using Element = ;
    static Element identity() {
    } 
    static void add(Element& s, const T& v) {
    }
    static void remove(Element& s, const T& v) {
    }
};
```

ここで、`remove`とは`l`に含まれている`r`を削除する関数である。可換群の逆元を計算するのとは若干違うことに注意する必要があるかもしれない。
- たとえば`add`が掛け算をする関数だったとして、`remove`に与えられる引数は、`l`が`r`の倍数であることが保証される。(そのため、整数で閉じていると考えてよい)

**計算量**

- $A$ の要素数を $N$ とする
- `add, remove`を合計 $2^N - 1$ 回呼び出す
- `identity()`を丁度一回呼び出す
- `GreyCode(N)`を一回呼び出す
- $+O(2^N)$
