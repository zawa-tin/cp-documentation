---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2587.test.cpp
    title: Test/AOJ/2587.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc484_g.test.cpp
    title: Test/AtCoder/abc484_g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Sequence/PowersetConstruction.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Sequence/PowersetConstruction.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <concepts>\n#include <utility>\n#include\
    \ <vector>\n#include <iterator>\n#include <limits>\n#include <unordered_map>\n\
    \nnamespace zawa {\n\ntemplate <std::integral T,std::integral U>\nclass PowersetConstruction\
    \ {\npublic:\n\n    PowersetConstruction() = default;\n\n    PowersetConstruction(usize\
    \ N,usize alpMax,T start,std::vector<T> accept)\n        : m_n{N}, m_alp{alpMax},\
    \ m_st{start}, m_accept{0}, m_to(alpMax,std::vector<u64>(N)), m_epsilon(N) {\n\
    \        assert(N < 64);\n        assert(alpMax <= static_cast<usize>(std::numeric_limits<U>::max()));\n\
    \        assert(static_cast<usize>(start)<size());\n        for (T v : accept)\
    \ {\n            assert(static_cast<usize>(v)<size());\n            m_accept|=u64{1}<<v;\n\
    \        }\n    }\n\n    inline usize size() const noexcept {\n        return\
    \ m_n;\n    }\n\n    inline usize sigma() const noexcept {\n        return m_alp;\n\
    \    }\n\n    void addTransition(T from, T to, U c) {\n        assert(static_cast<usize>(from)\
    \ < size());\n        assert(static_cast<usize>(to) < size());\n        assert(static_cast<usize>(c)\
    \ < sigma());\n        m_to[c][from]|=u64{1}<<to;\n    }\n\n    void addEpsilonTransition(T\
    \ from,T to) {\n        assert(static_cast<usize>(from) < size());\n        assert(static_cast<usize>(to)\
    \ < size());\n        m_epsilon[from]|=u64{1}<<to;\n    }\n\n    std::pair<std::vector<std::vector<T>>,std::vector<bool>>\
    \ build() {\n        std::vector<u64> epsilon(size());\n        for (usize i =\
    \ 0 ; i < size() ; i++)\n            epsilon[i]=epsilonClosure(i);\n        for\
    \ (usize i = 0 ; i < size() ; i++)\n            for (usize j = 0 ; j < sigma()\
    \ ; j++)\n                for (usize k = 0 ; k < size() ; k++)\n             \
    \       if (m_to[j][i]>>k&1)\n                        m_to[j][i]|=epsilon[k];\n\
    \        std::unordered_map<u64,T> id;\n        T inf=std::numeric_limits<T>::max();\n\
    \        std::vector to(1,std::vector<T>(sigma(),inf));\n        std::vector<std::pair<u64,T>>\
    \ que;\n        id[epsilon[m_st]]=0;\n        que.push_back({epsilon[m_st],T{0}});\n\
    \        for (usize t = 0 ; t < que.size() ; t++) {\n            auto [b,v]=que[t];\n\
    \            std::vector<T> nw;\n            for (usize i = 0 ; i < size() ; i++)\n\
    \                if (b>>i&1)\n                    nw.push_back(i);\n         \
    \   for (usize i = 0 ; i < sigma() ; i++) {\n                u64 nxt=0;\n    \
    \            for (T j : nw)\n                    nxt|=m_to[i][j];\n          \
    \      if (!nxt)\n                    to[v][i]=inf;\n                else if (auto\
    \ it=id.find(nxt) ; it!=id.end())\n                    to[v][i]=it->second;\n\
    \                else {\n                    T x=std::ssize(to);\n           \
    \         to.push_back(std::vector<T>(sigma(),inf));\n                    to[v][i]=x;\n\
    \                    id[nxt]=x;\n                    que.push_back({nxt,x});\n\
    \                }\n            }\n        }\n        const usize n=id.size();\n\
    \        for (usize i = 0 ; i < n ; i++)\n            std::ranges::replace(to[i],inf,static_cast<T>(n));\n\
    \        std::vector<bool> accept(n);\n        for (auto [b,v] : id)\n       \
    \     accept[v]=(b&m_accept)>0;\n        return {std::move(to),std::move(accept)};\n\
    \    }\n\nprivate:\n\n    usize m_n,m_alp;\n\n    T m_st;\n\n    u64 m_accept;\n\
    \n    std::vector<std::vector<u64>> m_to;\n\n    std::vector<u64> m_epsilon;\n\
    \n    u64 epsilonClosure(T s) {\n        u64 vis=u64{1}<<s;\n        std::vector<T>\
    \ que{s};\n        for (usize t = 0 ; t < que.size() ; t++) {\n            T v=que[t];\n\
    \            for (usize i = 0 ; i < size() ; i++)\n                if (!(vis>>i&1)\
    \ and m_epsilon[v]>>i&1) {\n                    vis|=u64{1}<<i;\n            \
    \        que.push_back(i);\n                }\n        }\n        return vis;\n\
    \    }\n\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <concepts>\n#include <utility>\n#include <vector>\n\
    #include <iterator>\n#include <limits>\n#include <unordered_map>\n\nnamespace\
    \ zawa {\n\ntemplate <std::integral T,std::integral U>\nclass PowersetConstruction\
    \ {\npublic:\n\n    PowersetConstruction() = default;\n\n    PowersetConstruction(usize\
    \ N,usize alpMax,T start,std::vector<T> accept)\n        : m_n{N}, m_alp{alpMax},\
    \ m_st{start}, m_accept{0}, m_to(alpMax,std::vector<u64>(N)), m_epsilon(N) {\n\
    \        assert(N < 64);\n        assert(alpMax <= static_cast<usize>(std::numeric_limits<U>::max()));\n\
    \        assert(static_cast<usize>(start)<size());\n        for (T v : accept)\
    \ {\n            assert(static_cast<usize>(v)<size());\n            m_accept|=u64{1}<<v;\n\
    \        }\n    }\n\n    inline usize size() const noexcept {\n        return\
    \ m_n;\n    }\n\n    inline usize sigma() const noexcept {\n        return m_alp;\n\
    \    }\n\n    void addTransition(T from, T to, U c) {\n        assert(static_cast<usize>(from)\
    \ < size());\n        assert(static_cast<usize>(to) < size());\n        assert(static_cast<usize>(c)\
    \ < sigma());\n        m_to[c][from]|=u64{1}<<to;\n    }\n\n    void addEpsilonTransition(T\
    \ from,T to) {\n        assert(static_cast<usize>(from) < size());\n        assert(static_cast<usize>(to)\
    \ < size());\n        m_epsilon[from]|=u64{1}<<to;\n    }\n\n    std::pair<std::vector<std::vector<T>>,std::vector<bool>>\
    \ build() {\n        std::vector<u64> epsilon(size());\n        for (usize i =\
    \ 0 ; i < size() ; i++)\n            epsilon[i]=epsilonClosure(i);\n        for\
    \ (usize i = 0 ; i < size() ; i++)\n            for (usize j = 0 ; j < sigma()\
    \ ; j++)\n                for (usize k = 0 ; k < size() ; k++)\n             \
    \       if (m_to[j][i]>>k&1)\n                        m_to[j][i]|=epsilon[k];\n\
    \        std::unordered_map<u64,T> id;\n        T inf=std::numeric_limits<T>::max();\n\
    \        std::vector to(1,std::vector<T>(sigma(),inf));\n        std::vector<std::pair<u64,T>>\
    \ que;\n        id[epsilon[m_st]]=0;\n        que.push_back({epsilon[m_st],T{0}});\n\
    \        for (usize t = 0 ; t < que.size() ; t++) {\n            auto [b,v]=que[t];\n\
    \            std::vector<T> nw;\n            for (usize i = 0 ; i < size() ; i++)\n\
    \                if (b>>i&1)\n                    nw.push_back(i);\n         \
    \   for (usize i = 0 ; i < sigma() ; i++) {\n                u64 nxt=0;\n    \
    \            for (T j : nw)\n                    nxt|=m_to[i][j];\n          \
    \      if (!nxt)\n                    to[v][i]=inf;\n                else if (auto\
    \ it=id.find(nxt) ; it!=id.end())\n                    to[v][i]=it->second;\n\
    \                else {\n                    T x=std::ssize(to);\n           \
    \         to.push_back(std::vector<T>(sigma(),inf));\n                    to[v][i]=x;\n\
    \                    id[nxt]=x;\n                    que.push_back({nxt,x});\n\
    \                }\n            }\n        }\n        const usize n=id.size();\n\
    \        for (usize i = 0 ; i < n ; i++)\n            std::ranges::replace(to[i],inf,static_cast<T>(n));\n\
    \        std::vector<bool> accept(n);\n        for (auto [b,v] : id)\n       \
    \     accept[v]=(b&m_accept)>0;\n        return {std::move(to),std::move(accept)};\n\
    \    }\n\nprivate:\n\n    usize m_n,m_alp;\n\n    T m_st;\n\n    u64 m_accept;\n\
    \n    std::vector<std::vector<u64>> m_to;\n\n    std::vector<u64> m_epsilon;\n\
    \n    u64 epsilonClosure(T s) {\n        u64 vis=u64{1}<<s;\n        std::vector<T>\
    \ que{s};\n        for (usize t = 0 ; t < que.size() ; t++) {\n            T v=que[t];\n\
    \            for (usize i = 0 ; i < size() ; i++)\n                if (!(vis>>i&1)\
    \ and m_epsilon[v]>>i&1) {\n                    vis|=u64{1}<<i;\n            \
    \        que.push_back(i);\n                }\n        }\n        return vis;\n\
    \    }\n\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Sequence/PowersetConstruction.hpp
  requiredBy: []
  timestamp: '2026-11-19 16:34:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/2587.test.cpp
  - Test/AtCoder/abc484_g.test.cpp
documentation_of: Src/Sequence/PowersetConstruction.hpp
layout: document
title: "Powerset Construction (NFA\u3092DFA\u306B\u5909\u63DB\u3059\u308B)"
---

## 概要

ε 遷移を持つ非決定性有限オートマトン (NFA) を構築し、部分集合構成法 (Powerset Construction) によって同じ言語を受理する決定性有限オートマトン (DFA) に変換する。

NFA の状態数を $N$、アルファベットサイズを $\sigma$ とする。状態番号は $0$ 以上 $N$ 未満、文字は $0$ 以上 $\sigma$ 未満の整数で表す。ε 遷移は文字を消費せずに移動できる遷移であり、通常の文字とは別のメンバ関数で追加する。

本実装では NFA の状態集合を `u64` で管理するため、$1 \le N < 64$ を満たす必要がある。

## ライブラリの使い方

### テンプレート引数

```cpp
template <std::integral T, std::integral U>
class PowersetConstruction;
```

- `T` は NFA と構築後の DFA の状態番号を表す整数型。
- `U` は文字を表す整数型。

`T` には `int`、`unsigned`、`std::size_t`、`long long` のいずれかを推奨する。構築後の DFA の状態数を $n$ とすると、遷移なしの値として $n$ も使用するため、`T` は $0$ 以上 $n$ 以下の整数と、NFA の全状態番号を表現できる必要がある。

### コンストラクタ

```cpp
PowersetConstruction() = default;
PowersetConstruction(usize N, usize alpMax, T start, std::vector<T> accept);
```

$N$ 状態、アルファベットサイズ `alpMax` の NFA を構築する。初期状態を `start`、受理状態を `accept` に含まれる状態とする。初期状態から出発して入力を読み終えたとき、受理状態に到達できる経路が一つでも存在すれば、その入力を受理する。

構築直後の遷移は空である。`accept` は空でもよく、同じ状態番号を複数回含んでもよい。

デフォルトコンストラクタで構築した場合は、引数付きコンストラクタで構築したオブジェクトを代入してから各メンバ関数を利用する。

**制約**

- $1 \le N < 64$
- $0 \le \text{start} < N$
- `accept` の各要素 $v$ は $0 \le v < N$ を満たす。
- $0 \le \text{alpMax} \le \text{std::numeric_limits<U>::max()}$

以降、$\sigma = \text{alpMax}$ とする。$\sigma = 0$ の場合も利用でき、入力として空文字列を扱う。

**計算量**

引数付きコンストラクタは $O(N(\sigma + 1) + |\text{accept}|)$ 時間、構築後の使用空間は $O(N(\sigma + 1))$。

### size

```cpp
usize size() const noexcept;
```

NFA の状態数 $N$ を返す。

**計算量** 定数時間。

### sigma

```cpp
usize sigma() const noexcept;
```

アルファベットサイズ $\sigma$ を返す。

**計算量** 定数時間。

### addTransition

```cpp
void addTransition(T from, T to, U c);
```

状態 `from` から文字 `c` を読んで状態 `to` へ移動する遷移を追加する。同じ状態から同じ文字で複数の状態へ遷移できる。同じ遷移を複数回追加しても結果は変わらない。

**制約**

- $0 \le \text{from}, \text{to} < N$
- $0 \le c < \sigma$

**計算量** 定数時間。

### addEpsilonTransition

```cpp
void addEpsilonTransition(T from, T to);
```

状態 `from` から状態 `to` への ε 遷移を追加する。遷移は有向であり、文字を消費せずに利用できる。ε 遷移を利用するかどうかは自由に選べる。

自己ループ、ε 遷移によるサイクル、同じ遷移の複数回の追加にも対応する。

**制約** $0 \le \text{from}, \text{to} < N$。

**計算量** 定数時間。

### build

```cpp
std::pair<std::vector<std::vector<T>>, std::vector<bool>> build();
```

現在の NFA と同じ言語を受理する DFA を構築し、遷移表 `to` と受理状態の情報 `accept` のペアを返す。内部の遷移情報に ε 閉包を反映する破壊的な処理を行う。

構築後の状態数を $n = \text{to.size()}$ とする。

| 項目 | 意味 |
| --- | --- |
| 状態番号 | $0$ 以上 $n$ 未満 |
| 初期状態 | 常に $0$ |
| `to[v][c]` | 状態 `v` で文字 `c` を読んだときの遷移先 |
| `to[v][c] == n` | 対応する NFA の遷移先集合が空であることを表す |
| `accept[v]` | 状態 `v` が受理状態なら `true` |

`to` の各行の長さは $\sigma$、`accept` の長さは $n$ である。`n` は番兵値なので、`to[n]` や `accept[n]` へのアクセスは範囲外になる。入力を読む途中で状態が `n` になったら、その入力は拒否する。

DFA の各状態は、初期状態から到達可能な、空でない NFA 状態集合に対応する。初期状態に対応する集合には、NFA の初期状態から ε 遷移だけで到達できる状態も含まれる。そのため、空文字列を受理するかどうかは `accept[0]` で判定できる。

状態数は $1 \le n \le 2^N - 1$ を満たす。状態数の最小化は別途行う。

**計算量**

`u64` のビット演算を定数時間とし、`std::unordered_map` の検索・挿入を期待償却定数時間として評価する。

- ε 閉包の前計算は $O(N^3)$ 時間。
- 通常遷移の行き先への ε 閉包の反映は $O(\sigma N^2)$ 時間。
- 部分集合構成と返り値の作成は期待 $O(nN(\sigma + 1))$ 時間。

全体では期待 $O(N^3 + \sigma N^2 + nN(\sigma + 1))$ 時間、返り値を含む使用空間は $O((N + n)(\sigma + 1))$。DFA の状態数は最悪で指数的に増加する。

## 使用例

文字 `a` を $0$、文字 `b` を $1$ と表す。以下の NFA は、`a` を $0$ 回以上読んだ後に `b` を一つ読む文字列を受理する。

```cpp
#include "Src/Sequence/PowersetConstruction.hpp"

#include <iostream>
#include <vector>

int main() {
    zawa::PowersetConstruction<int, int> nfa(3, 2, 0, {2});
    nfa.addEpsilonTransition(0, 1);
    nfa.addTransition(1, 1, 0);
    nfa.addTransition(1, 2, 1);

    auto [to, accept] = nfa.build();
    const int n = static_cast<int>(to.size());
    const std::vector<int> input{0, 0, 0, 1};  // aaab

    int state = 0;
    for (int c : input) {
        state = to[state][c];
        if (state == n)
            break;
    }

    const bool accepted = state != n && accept[state];
    std::cout << accepted << '\n';  // 1
}
```

## アルゴリズム

状態集合 $S$ の ε 閉包 $E(S)$ は、$S$ のいずれかの状態から ε 遷移を $0$ 回以上使って到達できる状態全体とする。各状態 $v$ について、ε 遷移だけを使う BFS によって $E(\{v\})$ を前計算する。

初期状態 `start` に対して $E(\{\text{start}\})$ を最初の集合とし、集合を頂点とする BFS を行う。集合 $S$ で文字 $c$ を読んだ遷移先は、$S$ 内の各状態から文字 $c$ で到達する状態を集め、その ε 閉包を取った集合である。

本実装では通常遷移の各行き先集合に ε 閉包をあらかじめ反映し、BFS 中はビット論理和で遷移先集合を求める。新しい空でない集合を発見するたびに DFA の状態番号を割り当てる。集合に NFA の受理状態が一つでも含まれていれば、その DFA 状態を受理状態とする。

## 更新履歴

- 2026/11/19 作成 (ドキュメントはAI生成)
