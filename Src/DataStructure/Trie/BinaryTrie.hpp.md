---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc451_g.test.cpp
    title: Test/AtCoder/abc451_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/set_xor_min.test.cpp
    title: Test/LC/set_xor_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/Trie/BinaryTrie.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/DataStructure/Trie/BinaryTrie.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <usize Height>\n\
    class BinaryTrie {\nprivate:\n\n    static_assert(usize{1} <= Height and Height\
    \ <= usize{64});\n\n    struct Node {\n        usize cnt=0;\n        usize ch[2]{0,0};\n\
    \    };\n\npublic:\n\n    BinaryTrie() : m_trie(2) {}\n\n    void insert(u64 v,u64\
    \ k = 1) {\n        assert(check(v));\n        usize nd = 1;\n        for (usize\
    \ i = Height ; i-- ; ) {\n            m_trie[nd].cnt += k;\n            const\
    \ usize b = (v >> i) & 1;\n            if (!m_trie[nd].ch[b])\n              \
    \  m_trie[nd].ch[b] = makeNode();\n            nd = m_trie[nd].ch[b];\n      \
    \  }\n        m_trie[nd].cnt += k;\n    }\n\n    usize count(u64 v) const {\n\
    \        assert(check(v));\n        usize nd = 1;\n        for (usize i = Height\
    \ ; i-- ; ) {\n            const usize b = (v >> i) & 1;\n            nd = m_trie[nd].ch[b];\n\
    \            if (!nd)\n                return 0;\n        }\n        return m_trie[nd].cnt;\n\
    \    }\n\n    usize erase(u64 v,u64 k = 1) {\n        usize nd = 1;\n        std::vector<usize>\
    \ nds{nd};\n        nds.reserve(Height+1);\n        for (usize i = Height ; i--\
    \ ; ) {\n            const usize b = (v >> i) & 1;\n            nd = m_trie[nd].ch[b];\n\
    \            if (!nd)\n                return 0;\n            nds.push_back(nd);\n\
    \        }\n        k = std::min(k,m_trie[nd].cnt);\n        if (k) {\n      \
    \      for (usize i : nds)\n                m_trie[i].cnt -= k;\n        }\n \
    \       return k;\n    }\n    \n    bool empty() const {\n        return m_trie[1].cnt\
    \ == 0;\n    }\n\n    usize size() const {\n        return m_trie[1].cnt;\n  \
    \  }\n\n    usize setmin(u64 mask) const {\n        assert(size());\n        usize\
    \ nd = 1;\n        u64 res = 0;\n        for (usize i = Height ; i < 64u ; i++)\n\
    \            if ((mask >> i) & 1)\n                res |= u64{1} << i;\n     \
    \   for (usize i = Height ; i-- ; ) {\n            assert(m_trie[nd].cnt);\n \
    \           const usize b = (mask >> i) & 1;\n            if (m_trie[nd].ch[b]\
    \ and m_trie[m_trie[nd].ch[b]].cnt) {\n                nd = m_trie[nd].ch[b];\n\
    \                continue;\n            }\n            res |= u64{1} << i;\n \
    \           nd = m_trie[nd].ch[b^1];\n        }\n        return res;\n    }\n\n\
    \    usize setmax(u64 mask) const {\n        assert(size());\n        usize nd\
    \ = 1;\n        u64 res = 0;\n        for (usize i = Height ; i < 64u ; i++)\n\
    \            if ((mask >> i) & 1)\n                res |= u64{1} << i;\n     \
    \   for (usize i = Height ; i-- ; ) {\n            assert(m_trie[nd].cnt);\n \
    \           const usize b = (mask >> i) & 1;\n            if (m_trie[nd].ch[b^1]\
    \ and m_trie[m_trie[nd].ch[b^1]].cnt) {\n                res |= u64{1} << i;\n\
    \                nd = m_trie[nd].ch[b^1];\n                continue;\n       \
    \     }\n            nd = m_trie[nd].ch[b^1];\n        }\n        return res;\n\
    \    }\n\n    const Node& operator[](usize i) const {\n        assert(i < m_trie.size());\n\
    \        return m_trie[i];\n    }\n\nprivate:\n\n    std::vector<Node> m_trie;\n\
    \n    usize makeNode() {\n        usize res = m_trie.size();\n        m_trie.emplace_back();\n\
    \        return res;\n    }\n\n    inline bool check(u64 v) const {\n        return\
    \ Height == 64 or v < (u64{1} << Height);\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace zawa {\n\ntemplate <usize Height>\nclass BinaryTrie\
    \ {\nprivate:\n\n    static_assert(usize{1} <= Height and Height <= usize{64});\n\
    \n    struct Node {\n        usize cnt=0;\n        usize ch[2]{0,0};\n    };\n\
    \npublic:\n\n    BinaryTrie() : m_trie(2) {}\n\n    void insert(u64 v,u64 k =\
    \ 1) {\n        assert(check(v));\n        usize nd = 1;\n        for (usize i\
    \ = Height ; i-- ; ) {\n            m_trie[nd].cnt += k;\n            const usize\
    \ b = (v >> i) & 1;\n            if (!m_trie[nd].ch[b])\n                m_trie[nd].ch[b]\
    \ = makeNode();\n            nd = m_trie[nd].ch[b];\n        }\n        m_trie[nd].cnt\
    \ += k;\n    }\n\n    usize count(u64 v) const {\n        assert(check(v));\n\
    \        usize nd = 1;\n        for (usize i = Height ; i-- ; ) {\n          \
    \  const usize b = (v >> i) & 1;\n            nd = m_trie[nd].ch[b];\n       \
    \     if (!nd)\n                return 0;\n        }\n        return m_trie[nd].cnt;\n\
    \    }\n\n    usize erase(u64 v,u64 k = 1) {\n        usize nd = 1;\n        std::vector<usize>\
    \ nds{nd};\n        nds.reserve(Height+1);\n        for (usize i = Height ; i--\
    \ ; ) {\n            const usize b = (v >> i) & 1;\n            nd = m_trie[nd].ch[b];\n\
    \            if (!nd)\n                return 0;\n            nds.push_back(nd);\n\
    \        }\n        k = std::min(k,m_trie[nd].cnt);\n        if (k) {\n      \
    \      for (usize i : nds)\n                m_trie[i].cnt -= k;\n        }\n \
    \       return k;\n    }\n    \n    bool empty() const {\n        return m_trie[1].cnt\
    \ == 0;\n    }\n\n    usize size() const {\n        return m_trie[1].cnt;\n  \
    \  }\n\n    usize setmin(u64 mask) const {\n        assert(size());\n        usize\
    \ nd = 1;\n        u64 res = 0;\n        for (usize i = Height ; i < 64u ; i++)\n\
    \            if ((mask >> i) & 1)\n                res |= u64{1} << i;\n     \
    \   for (usize i = Height ; i-- ; ) {\n            assert(m_trie[nd].cnt);\n \
    \           const usize b = (mask >> i) & 1;\n            if (m_trie[nd].ch[b]\
    \ and m_trie[m_trie[nd].ch[b]].cnt) {\n                nd = m_trie[nd].ch[b];\n\
    \                continue;\n            }\n            res |= u64{1} << i;\n \
    \           nd = m_trie[nd].ch[b^1];\n        }\n        return res;\n    }\n\n\
    \    usize setmax(u64 mask) const {\n        assert(size());\n        usize nd\
    \ = 1;\n        u64 res = 0;\n        for (usize i = Height ; i < 64u ; i++)\n\
    \            if ((mask >> i) & 1)\n                res |= u64{1} << i;\n     \
    \   for (usize i = Height ; i-- ; ) {\n            assert(m_trie[nd].cnt);\n \
    \           const usize b = (mask >> i) & 1;\n            if (m_trie[nd].ch[b^1]\
    \ and m_trie[m_trie[nd].ch[b^1]].cnt) {\n                res |= u64{1} << i;\n\
    \                nd = m_trie[nd].ch[b^1];\n                continue;\n       \
    \     }\n            nd = m_trie[nd].ch[b^1];\n        }\n        return res;\n\
    \    }\n\n    const Node& operator[](usize i) const {\n        assert(i < m_trie.size());\n\
    \        return m_trie[i];\n    }\n\nprivate:\n\n    std::vector<Node> m_trie;\n\
    \n    usize makeNode() {\n        usize res = m_trie.size();\n        m_trie.emplace_back();\n\
    \        return res;\n    }\n\n    inline bool check(u64 v) const {\n        return\
    \ Height == 64 or v < (u64{1} << Height);\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/Trie/BinaryTrie.hpp
  requiredBy: []
  timestamp: '2026-04-02 19:07:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc451_g.test.cpp
  - Test/LC/set_xor_min.test.cpp
documentation_of: Src/DataStructure/Trie/BinaryTrie.hpp
layout: document
title: Binary Trie
---

遅延伝搬はまだ実装していない。

### テンプレート引数

```cpp
template <usize Height>
```

Binary Trieの高さ。挿入・削除する整数が $0$ 以上 $2^{\text{Height}}$ 未満であることを保証しなければならない。

Heightは $1$ 以上 $64$ 以下である必要がある。

### コンストラクタ

```cpp
BinaryTrie() = default;
```

デフォルトコンストラクタのみ。

### insert

```cpp
void insert(u64 v,u64 k = 1)
```

$v$ を $k$ 個挿入する。

### count

```cpp
void count(u64 v) const
```

$v$ が存在する個数を返す。

### erase

```cpp
usize erase(u64 v,u64 k = 1)
```

$v$ を $k$ 個消そうとする。実際に消すことができた数を返す。

### empty

```cpp
bool empty() const
```

現在空か判定

### size

```cpp
usize size() const
```

現在何要素あるか


### setmin

```cpp
usize setmin(u64 mask) const
```

トライの中にある要素 $x$ 全体に渡る $x \oplus \text{mask}$ の最小値を返す。

### setmax

```cpp
usize setmin(u64 mask) const
```

トライの中にある要素 $x$ 全体に渡る $x \oplus \text{mask}$ の最大値を返す。

**未verify**

### operator[]

```cpp
const Node& operator[](usize i) const
```

トライ木の内部のノードを取得する。 $0$ のとき空であることを意味する。

根ノードは常に存在し、 $1$ を引数に与えるとアクセスすることができる。

```cpp
struct Node {
    usize cnt=0;
    usize ch[2]{0,0};
};
```

`cnt`がそのノードの部分木にある要素数、`ch`が子のノード番号を意味する。`ch`が $0$ ならば、子が存在しないことを示す。
