---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Trie/BinaryTrie.hpp
    title: Binary Trie
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"Test/LC/set_xor_min.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
    \n\n#line 2 \"Src/DataStructure/Trie/BinaryTrie.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
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
    \ Height == 64 or v < (u64{1} << Height);\n    }\n};\n\n} // namespace zawa\n\
    #line 4 \"Test/LC/set_xor_min.test.cpp\"\nusing namespace zawa;\n\n#line 7 \"\
    Test/LC/set_xor_min.test.cpp\"\n#include <iostream>\nusing namespace std;\n\n\
    int main() {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int Q;\n    cin >> Q;\n    BinaryTrie<30> trie;\n    while (Q--) {\n    \
    \    int T, X;\n        cin >> T >> X;\n        if (T == 0)\n            trie.insert(X);\n\
    \        else if (T == 1) \n            trie.erase(X,trie.count(X));\n       \
    \ else if (T == 2)\n            cout << trie.setmin(X) << '\\n';\n        else\n\
    \            assert(0);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ \"../../Src/DataStructure/Trie/BinaryTrie.hpp\"\nusing namespace zawa;\n\n#include\
    \ <cassert>\n#include <iostream>\nusing namespace std;\n\nint main() {\n    cin.tie(0);\n\
    \    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int Q;\n    cin >> Q;\n \
    \   BinaryTrie<30> trie;\n    while (Q--) {\n        int T, X;\n        cin >>\
    \ T >> X;\n        if (T == 0)\n            trie.insert(X);\n        else if (T\
    \ == 1) \n            trie.erase(X,trie.count(X));\n        else if (T == 2)\n\
    \            cout << trie.setmin(X) << '\\n';\n        else\n            assert(0);\n\
    \    }\n}\n"
  dependsOn:
  - Src/DataStructure/Trie/BinaryTrie.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/LC/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2026-04-02 19:07:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/set_xor_min.test.cpp
- /verify/Test/LC/set_xor_min.test.cpp.html
title: Test/LC/set_xor_min.test.cpp
---
