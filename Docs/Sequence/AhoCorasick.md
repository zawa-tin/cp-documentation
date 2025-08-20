---
title: Aho-Corasick
documentation_of: //Src/Sequence/AhoCorasick.hpp
---

## 概要

辞書 $T = \\{S_1, S_2, \dots, S_N\\}$ に関するパターンマッチングに秀でたデータ構造。トライ木の各ノードにFailure Linkなるものを張ったものであり、オートマトンをなしている。

競プロの文脈では、このトライ木のノードをキーとしたdpが典型的なテクニックとなっている。

## ライブラリの使い方

### コンストラクタ

```cpp
template <ahocorasick_internal::HasValueType Container>
AhoCorasick() = default;
```

$S_i$ の型に該当する`Container`クラスをテンプレート引数に与える。これは`value_type`という型エイリアスを提供しているクラスならば受理される。例えば`std::string`や`std::vector<T>`等が該当する。

### insert

```cpp
usize insert(Container s)
```

$s$ を辞書 $T$ に追加する。

### build

```cpp
Trie build() const (1)

template <class T, class S>
requires ahocorasick_internal::AuxiliaryData<T, S>
std::pair<Trie, std::vector<typename T::Element>> build(const std::vector<S>& values) const (2)
```

現在の $T$ をもとにオートマトンを構築する。構築されたオートマトンを返す。

各ノードは $T$ に属するいずれかの列のprefixに対応している。

(2)ではオートマトンのノードに関係する補助的なデータを計算する。具体的には、ノード $v$ に対応している文字列のsuffixとして $S_i$ が出現するような $i$ の集合を $U_{v}$ とする。 

可換モノイド $M = (P, \oplus)$ に対する $\bigoplus_{i\in U_{v}} f(i)$ を計算する。ただし、 $f(i)$ は $i$ をある $P$ の要素に対応させる関数とする。

`T`はモノイドであり、$S$ は`T::Element`に作用する必要がある。

雛形

```cpp
class M {
    using Element ;
    static Element identity() {
    }
    static Element operation(Element, Element) {
    }
    static Element acted(Element, S) {
    }
};
```
例えば以下のように定義すると、オートマトンの各状態が $S_i$ とマッチしているかという意味で受理状態か否かが計算できる。

```cpp
struct Monoid {
    using Element = bool;
    static Element identity() {
        return false;
    }
    static Element operation(Element l, Element r) {
        return l or r;
    }
};
using M = AddSelfAction<Monoid>;
// valuesはvector<bool>(N, true)とする。
```

### Trie::Root

```cpp
static constexpr usize Root()
```

空文字列に対応している状態はオートマトン上にただ一つあり、その状態の番号を返す。ちなみにどんな $T$ に対しても`0`である。

### Trie::size

```cpp
usize size() const
```

オートマトンのノード数を返す。

### Trie::trace

```cpp
usize trace(usize cur, V v)
usize trace(usize cur, const Container& S)
```

オートマトンの状態`cur`から`v`を読み込んだ先の状態の番号を返す。

### Trie::match

```cpp
usize match(usize i) const {
    assert(i < m_match.size());
    return m_match[i];
}
```

$S_i$ に対応しているオートマトンの状態の番号を返す。

### Trie::nodes

```cpp
const std::vector<Node>& nodes() const&
```

内部のノードの列を`const&`で返す。LCのベリ用に作った関数であり、特に使いみちは無い？

## 参考

- [Aho-Corasick algorithm](https://cp-algorithms.com/string/aho_corasick.html)
- [Aho-Corasick Automata](https://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Slides02.pdf)
- [AOJ2257の解説](https://jag-icpc.org/?plugin=attach&refer=2011%2FPractice%2F%E6%A8%A1%E6%93%AC%E5%9B%BD%E5%86%85%E4%BA%88%E9%81%B8%2F%E8%AC%9B%E8%A9%95&openfile=f.pdf)
