---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc268_h.test.cpp
    title: Test/AtCoder/abc268_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc419_f.test.cpp
    title: Test/AtCoder/abc419_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/aho_corasick.test.cpp
    title: Test/LC/aho_corasick.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Sequence/AhoCorasick.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Sequence/AhoCorasick.hpp\"\n\n#include <cassert>\n\
    #include <concepts>\n#include <ranges>\n#include <unordered_map>\n#include <vector>\n\
    \nnamespace zawa {\n\nnamespace ahocorasickinternal {\n\ntemplate <class T>\n\
    concept HasValueType = requires {\n    typename T::value_type;\n};\n\ntemplate\
    \ <class T>\nconcept AuxiliaryData = requires {\n    typename T::Element;\n  \
    \  { T::identity() } -> std::same_as<typename T::Element>;\n    { T::merge(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n    { T::add(std::declval<typename T::Element>(), std::declval<usize>())\
    \ } -> std::same_as<typename T::Element>;\n};\n\n} // namespace ahocorasickinternal\n\
    \ntemplate <ahocorasickinternal::HasValueType Container>\nclass AhoCorasick {\n\
    public:\n\n    using V = Container::value_type;\n\nprivate:\n\n    class Trie\
    \ {\n    public:\n\n        struct Node {\n            usize fail = 0;\n     \
    \       std::unordered_map<V, usize> ch{};\n            std::pair<usize, V> par{};\n\
    \        };\n\n        Trie(std::vector<Node>&& nodes, std::vector<usize>&& match)\
    \ \n            : m_nodes{std::move(nodes)}, m_match{std::move(match)} {}\n\n\
    \        static constexpr usize Root() {\n            return 0;\n        }\n\n\
    \        usize size() const {\n            return m_nodes.size();\n        }\n\
    \n        usize trace(usize cur, V v) {\n            assert(cur < size());\n \
    \           while (cur and !m_nodes[cur].ch.contains(v))\n                cur\
    \ = m_nodes[cur].fail;\n            if (auto it = m_nodes[cur].ch.find(v) ; it\
    \ != m_nodes[cur].ch.end())\n                return it->second;\n            else\n\
    \                return cur;\n        }\n\n        usize match(usize i) const\
    \ {\n            assert(i < m_match.size());\n            return m_match[i];\n\
    \        }\n\n        usize trace(usize cur, const Container& S) {\n         \
    \   assert(cur < size());\n            for (V v : S)\n                cur = trace(cur,\
    \ v);\n            return cur;\n        }\n\n        const std::vector<Node>&\
    \ nodes() const& {\n            return m_nodes;\n        }\n\n    private:\n\n\
    \        std::vector<Node> m_nodes;\n\n        std::vector<usize> m_match;\n \
    \   };\n\npublic:\n\n    AhoCorasick() = default;\n\n    usize insert(Container\
    \ s) {\n        usize res = m_seq.size();\n        m_seq.push_back(s);\n     \
    \   return res;\n    }\n\n    Trie build() const {\n        std::vector<typename\
    \ Trie::Node> nodes(1);  \n        std::vector<usize> match;\n        match.reserve(m_seq.size());\n\
    \        for (const Container& s : m_seq) {\n            usize cur = 0, idx =\
    \ 0;\n            for ( ; idx < s.size() ; idx++) {\n                auto it =\
    \ nodes[cur].ch.find(s[idx]);\n                if (it == nodes[cur].ch.end())\n\
    \                    break;\n                cur = it->second;\n            }\n\
    \            for ( ; idx < s.size() ; idx++) {\n                usize nxt = nodes[cur].ch[s[idx]]\
    \ = nodes.size();\n                nodes.emplace_back();\n                nodes.back().par\
    \ = {cur, s[idx]};\n                cur = nxt;\n            }\n            match.push_back(cur);\n\
    \        }\n        std::vector<usize> que;\n        for (const usize x : nodes[0].ch\
    \ | std::views::values)\n            que.emplace_back(x);\n        for (usize\
    \ qt = 0 ; qt < que.size() ; qt++) {\n            const usize v = que[qt];\n \
    \           for (const usize x : nodes[v].ch | std::views::values)\n         \
    \       que.emplace_back(x);\n            auto [x, ed] = nodes[v].par;\n     \
    \       if (!x) \n                continue;\n            x = nodes[x].fail;\n\
    \            while (x and !nodes[x].ch.contains(ed))\n                x = nodes[x].fail;\n\
    \            if (auto it = nodes[x].ch.find(ed) ; it == nodes[x].ch.end() or it->second\
    \ == v) \n                nodes[v].fail = 0;\n            else\n             \
    \   nodes[v].fail = it->second;\n        }\n        return Trie{std::move(nodes),\
    \ std::move(match)};\n    }\n\n    template <ahocorasickinternal::AuxiliaryData\
    \ T>\n    Trie build(std::vector<typename T::Element>& data) const {\n       \
    \ data.clear();\n        data.resize(1, T::identity());\n        std::vector<typename\
    \ Trie::Node> nodes(1);  \n        std::vector<usize> match(m_seq.size());\n \
    \       for (usize i = 0 ; const Container& s : m_seq) {\n            usize cur\
    \ = 0, idx = 0;\n            for ( ; idx < s.size() ; idx++) {\n             \
    \   auto it = nodes[cur].ch.find(s[idx]);\n                if (it == nodes[cur].ch.end())\n\
    \                    break;\n                cur = it->second;\n            }\n\
    \            for ( ; idx < s.size() ; idx++) {\n                usize nxt = nodes[cur].ch[s[idx]]\
    \ = nodes.size();\n                nodes.emplace_back();\n                nodes.back().par\
    \ = {cur, s[idx]};\n                data.push_back(data[cur]);\n             \
    \   cur = nxt;\n            }\n            match[i] = cur;\n            data[cur]\
    \ = T::add(data[cur], i++);\n        }\n        std::vector<usize> que;\n    \
    \    for (const usize x : nodes[0].ch | std::views::values)\n            que.emplace_back(x);\n\
    \        for (usize qt = 0 ; qt < que.size() ; qt++) {\n            const usize\
    \ v = que[qt];\n            for (const usize x : nodes[v].ch | std::views::values)\n\
    \                que.emplace_back(x);\n            auto [x, ed] = nodes[v].par;\n\
    \            if (!x) \n                continue;\n            x = nodes[x].fail;\n\
    \            while (x and !nodes[x].ch.contains(ed))\n                x = nodes[x].fail;\n\
    \            if (auto it = nodes[x].ch.find(ed) ; it == nodes[x].ch.end() or it->second\
    \ == v) \n                nodes[v].fail = 0;\n            else\n             \
    \   nodes[v].fail = it->second;\n            data[v] = T::merge(data[nodes[v].fail],\
    \ data[v]);\n        }\n        return Trie{std::move(nodes), std::move(match)};\n\
    \    }\n\nprivate:\n\n    std::vector<Container> m_seq;\n\n};\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <cassert>\n\
    #include <concepts>\n#include <ranges>\n#include <unordered_map>\n#include <vector>\n\
    \nnamespace zawa {\n\nnamespace ahocorasickinternal {\n\ntemplate <class T>\n\
    concept HasValueType = requires {\n    typename T::value_type;\n};\n\ntemplate\
    \ <class T>\nconcept AuxiliaryData = requires {\n    typename T::Element;\n  \
    \  { T::identity() } -> std::same_as<typename T::Element>;\n    { T::merge(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n    { T::add(std::declval<typename T::Element>(), std::declval<usize>())\
    \ } -> std::same_as<typename T::Element>;\n};\n\n} // namespace ahocorasickinternal\n\
    \ntemplate <ahocorasickinternal::HasValueType Container>\nclass AhoCorasick {\n\
    public:\n\n    using V = Container::value_type;\n\nprivate:\n\n    class Trie\
    \ {\n    public:\n\n        struct Node {\n            usize fail = 0;\n     \
    \       std::unordered_map<V, usize> ch{};\n            std::pair<usize, V> par{};\n\
    \        };\n\n        Trie(std::vector<Node>&& nodes, std::vector<usize>&& match)\
    \ \n            : m_nodes{std::move(nodes)}, m_match{std::move(match)} {}\n\n\
    \        static constexpr usize Root() {\n            return 0;\n        }\n\n\
    \        usize size() const {\n            return m_nodes.size();\n        }\n\
    \n        usize trace(usize cur, V v) {\n            assert(cur < size());\n \
    \           while (cur and !m_nodes[cur].ch.contains(v))\n                cur\
    \ = m_nodes[cur].fail;\n            if (auto it = m_nodes[cur].ch.find(v) ; it\
    \ != m_nodes[cur].ch.end())\n                return it->second;\n            else\n\
    \                return cur;\n        }\n\n        usize match(usize i) const\
    \ {\n            assert(i < m_match.size());\n            return m_match[i];\n\
    \        }\n\n        usize trace(usize cur, const Container& S) {\n         \
    \   assert(cur < size());\n            for (V v : S)\n                cur = trace(cur,\
    \ v);\n            return cur;\n        }\n\n        const std::vector<Node>&\
    \ nodes() const& {\n            return m_nodes;\n        }\n\n    private:\n\n\
    \        std::vector<Node> m_nodes;\n\n        std::vector<usize> m_match;\n \
    \   };\n\npublic:\n\n    AhoCorasick() = default;\n\n    usize insert(Container\
    \ s) {\n        usize res = m_seq.size();\n        m_seq.push_back(s);\n     \
    \   return res;\n    }\n\n    Trie build() const {\n        std::vector<typename\
    \ Trie::Node> nodes(1);  \n        std::vector<usize> match;\n        match.reserve(m_seq.size());\n\
    \        for (const Container& s : m_seq) {\n            usize cur = 0, idx =\
    \ 0;\n            for ( ; idx < s.size() ; idx++) {\n                auto it =\
    \ nodes[cur].ch.find(s[idx]);\n                if (it == nodes[cur].ch.end())\n\
    \                    break;\n                cur = it->second;\n            }\n\
    \            for ( ; idx < s.size() ; idx++) {\n                usize nxt = nodes[cur].ch[s[idx]]\
    \ = nodes.size();\n                nodes.emplace_back();\n                nodes.back().par\
    \ = {cur, s[idx]};\n                cur = nxt;\n            }\n            match.push_back(cur);\n\
    \        }\n        std::vector<usize> que;\n        for (const usize x : nodes[0].ch\
    \ | std::views::values)\n            que.emplace_back(x);\n        for (usize\
    \ qt = 0 ; qt < que.size() ; qt++) {\n            const usize v = que[qt];\n \
    \           for (const usize x : nodes[v].ch | std::views::values)\n         \
    \       que.emplace_back(x);\n            auto [x, ed] = nodes[v].par;\n     \
    \       if (!x) \n                continue;\n            x = nodes[x].fail;\n\
    \            while (x and !nodes[x].ch.contains(ed))\n                x = nodes[x].fail;\n\
    \            if (auto it = nodes[x].ch.find(ed) ; it == nodes[x].ch.end() or it->second\
    \ == v) \n                nodes[v].fail = 0;\n            else\n             \
    \   nodes[v].fail = it->second;\n        }\n        return Trie{std::move(nodes),\
    \ std::move(match)};\n    }\n\n    template <ahocorasickinternal::AuxiliaryData\
    \ T>\n    Trie build(std::vector<typename T::Element>& data) const {\n       \
    \ data.clear();\n        data.resize(1, T::identity());\n        std::vector<typename\
    \ Trie::Node> nodes(1);  \n        std::vector<usize> match(m_seq.size());\n \
    \       for (usize i = 0 ; const Container& s : m_seq) {\n            usize cur\
    \ = 0, idx = 0;\n            for ( ; idx < s.size() ; idx++) {\n             \
    \   auto it = nodes[cur].ch.find(s[idx]);\n                if (it == nodes[cur].ch.end())\n\
    \                    break;\n                cur = it->second;\n            }\n\
    \            for ( ; idx < s.size() ; idx++) {\n                usize nxt = nodes[cur].ch[s[idx]]\
    \ = nodes.size();\n                nodes.emplace_back();\n                nodes.back().par\
    \ = {cur, s[idx]};\n                data.push_back(data[cur]);\n             \
    \   cur = nxt;\n            }\n            match[i] = cur;\n            data[cur]\
    \ = T::add(data[cur], i++);\n        }\n        std::vector<usize> que;\n    \
    \    for (const usize x : nodes[0].ch | std::views::values)\n            que.emplace_back(x);\n\
    \        for (usize qt = 0 ; qt < que.size() ; qt++) {\n            const usize\
    \ v = que[qt];\n            for (const usize x : nodes[v].ch | std::views::values)\n\
    \                que.emplace_back(x);\n            auto [x, ed] = nodes[v].par;\n\
    \            if (!x) \n                continue;\n            x = nodes[x].fail;\n\
    \            while (x and !nodes[x].ch.contains(ed))\n                x = nodes[x].fail;\n\
    \            if (auto it = nodes[x].ch.find(ed) ; it == nodes[x].ch.end() or it->second\
    \ == v) \n                nodes[v].fail = 0;\n            else\n             \
    \   nodes[v].fail = it->second;\n            data[v] = T::merge(data[nodes[v].fail],\
    \ data[v]);\n        }\n        return Trie{std::move(nodes), std::move(match)};\n\
    \    }\n\nprivate:\n\n    std::vector<Container> m_seq;\n\n};\n\n} // namespace\
    \ zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Sequence/AhoCorasick.hpp
  requiredBy: []
  timestamp: '2025-08-17 19:11:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc419_f.test.cpp
  - Test/AtCoder/abc268_h.test.cpp
  - Test/LC/aho_corasick.test.cpp
documentation_of: Src/Sequence/AhoCorasick.hpp
layout: document
title: Aho-Corasick
---

## 概要

辞書 $T = \\{S_1, S_2, \dots, S_N\\}$ に関するパターンマッチングに秀でたデータ構造。トライ木の各ノードにFailure Linkなるものを張ったものであり、オートマトンをなしている。

競プロの文脈では、このトライ木のノードをキーとしたdpが典型的なテクニックとなっている。

## ライブラリの使い方

### コンストラクタ

```cpp
template <ahocorasickinternal::HasValueType Container>
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

template <ahocorasickinternal::AuxiliaryData T>
Trie build(std::vector<typename T::Element>& data) const (2)
```

現在の $T$ をもとにオートマトンを構築する。構築されたオートマトンを返す。

各ノードは $T$ に属するいずれかの列のprefixに対応している。

(2)ではオートマトンのノードに関係する補助的なデータを計算する。具体的には、ノード $v$ に対応している文字列のsuffixとして $S_i$ が出現するような $i$ の集合を $U_{v}$ とする。 

可換モノイド $M = (P, \oplus)$ に対する $\bigoplus_{i\in U_{v}} f(i)$ を計算する。ただし、 $f(i)$ は $i$ をある $P$ の要素に対応させる関数とする。

`T`は以下のconceptを満たす必要がある。

```cpp
typename T::Element;
{ T::identity() } -> std::same_as<typename T::Element>;
{ T::merge(std::declval<typename T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename T::Element>;
{ T::add(std::declval<typename T::Element>(), std::declval<usize>()) } -> std::same_as<typename T::Element>;
```

`Element`が $P$ の型、`identity`が $M$ の単位元、`merge`は $\oplus$ 、`add`は $p\oplus f(i)$ を計算する関数である。

例えば以下のように定義すると、オートマトンの各状態が $S_i$ とマッチしているかという意味で受理状態か否かが計算できる。

```cpp
truct M {
    using Element = bool;
    static Element identity() {
        return false;
    }
    static Element add(Element, int) {
        return true;
    }
    static Element merge(Element l, Element r) {
        return l or r;
    }
};
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
