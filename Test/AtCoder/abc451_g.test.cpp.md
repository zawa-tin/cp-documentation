---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
    title: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/abc451/submissions/74601108
    - https://atcoder.jp/contests/abc451/tasks/abc451_g
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/AtCoder/abc451_g.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc451/tasks/abc451_g\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n/*\n * AtCoder Beginner Contest 451 G - Minimum XOR Walk\n * https://atcoder.jp/contests/abc451/submissions/74601108\n\
    \ */\n\n#line 2 \"Src/DataStructure/Trie/BinaryTrie.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
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
    #line 2 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\n\n#line 4\
    \ \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\n\n#include <algorithm>\n\
    #line 7 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\n#include\
    \ <numeric>\n#line 9 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\
    \n#include <concepts>\n\nnamespace zawa {\n\nclass DisjointSetUnion {\npublic:\n\
    \    DisjointSetUnion() = default;\n\n    DisjointSetUnion(usize n) : n_{n}, comps_{n},\
    \ data_(n, -1) {\n        data_.shrink_to_fit();\n    }\n    \n    u32 leader(u32\
    \ v) {\n        return data_[v] < 0 ? v : static_cast<u32>(data_[v] = leader(data_[v]));\n\
    \    }\n\n    bool same(u32 u, u32 v) {\n        return leader(u) == leader(v);\n\
    \    }\n\n    bool merge(u32 u, u32 v) {\n        assert(u < n_);\n        assert(v\
    \ < n_);\n        u = leader(u);\n        v = leader(v);\n        if (u == v)\
    \ return false;\n        comps_--;\n        if (data_[u] > data_[v]) std::swap(u,\
    \ v);\n        data_[u] += data_[v];\n        data_[v] = u;\n        return true;\n\
    \    }\n\n    inline usize size() const noexcept {\n        return n_;\n    }\n\
    \n    usize size(u32 v) {\n        assert(v < n_);\n        return static_cast<usize>(-data_[leader(v)]);\n\
    \    }\n\n    inline usize components() const noexcept {\n        return comps_;\n\
    \    }\n\n    template <class T = usize>\n    std::vector<std::vector<T>> enumerate()\
    \ requires std::convertible_to<usize, T> {\n        std::vector<std::vector<T>>\
    \ res(n_);\n        for (usize v{} ; v < n_ ; v++) {\n            res[leader(v)].push_back(static_cast<T>(v));\n\
    \        }\n        std::erase_if(res, [](const auto& arr) -> bool { return arr.empty();\
    \ });\n        return res;\n    }\n\nprivate:\n    usize n_{}, comps_{};\n   \
    \ std::vector<i32> data_;\n};\n\n} // namespace zawa\n#line 11 \"Test/AtCoder/abc451_g.test.cpp\"\
    \nusing namespace zawa;\n\n#include <array>\n#include <bit>\n#include <iostream>\n\
    #line 17 \"Test/AtCoder/abc451_g.test.cpp\"\n#include <utility>\nusing namespace\
    \ std;\nusing item = array<int,30>;\nlong long solve() {\n    int N,M,K;\n   \
    \ cin >> N >> M >> K;\n    vector<vector<pair<int,int>>> G(N);\n    DisjointSetUnion\
    \ dsu(N);\n    vector<tuple<int,int,int>> remain;\n    for (int i = 0 ; i < M\
    \ ; i++) {\n        int u,v,w;\n        cin >> u >> v >> w;\n        u--; v--;\n\
    \        if (!dsu.same(u,v)) {\n            G[u].push_back({v,w});\n         \
    \   G[v].push_back({u,w});\n            dsu.merge(u,v);\n        }\n        else\n\
    \            remain.push_back({u,v,w});\n    }\n    vector<int> A(N);\n    auto\
    \ dfs = [&](auto dfs,int v,int p,int k) -> void {\n        A[v] = k;\n       \
    \ for (auto [x,w] : G[v])\n            if (x != p)\n                dfs(dfs,x,v,k^w);\n\
    \    };\n    dfs(dfs,0,-1,0);\n    item base;\n    base.fill(0);\n    auto reduce\
    \ = [&](int& v) {\n        for (int i = 29 ; i >= 0 ; i--)\n            if (v\
    \ & (1 << i))\n                v ^= base[i];\n    };\n    for (auto [u,v,w] :\
    \ remain) {\n        int val = A[u] ^ A[v] ^ w;\n        reduce(val);\n      \
    \  if (val)\n            base[bit_width<unsigned>(val)-1] = val;\n    } \n   \
    \ vector<int> P(N);\n    BinaryTrie<30> trie;\n    for (int i = 0 ; i < N ; i++)\
    \ {\n        P[i] = A[i];\n        reduce(P[i]);\n        trie.insert(P[i]);\n\
    \    }\n    long long ans = 0;\n    const int top = bit_width<unsigned>(K)-1;\n\
    \    for (int i = 0 ; i < N ; i++) {\n        trie.erase(P[i]);\n        int nd\
    \ = 1;\n        for (int j = 29 ; nd > 0 and j >= 0 ; j--) {\n            const\
    \ int b = (P[i] >> j) & 1;\n            if (j > top)\n                nd = trie[nd].ch[b];\n\
    \            else if ((K >> j) & 1) {\n                ans += trie[trie[nd].ch[b]].cnt;\n\
    \                nd = trie[nd].ch[b^1];\n            }\n            else\n   \
    \             nd = trie[nd].ch[b];\n        }\n        ans += trie[nd].cnt;\n\
    \        trie.insert(P[i]);\n    }\n    ans /= 2;\n    return ans;\n}\nint main()\
    \ {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int T;\n    cin >> T;\n    while (T--)\n        cout << solve() << '\\n';\n\
    #else\n    int a,b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n#endif\n\
    }\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc451/tasks/abc451_g\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n/*\n * AtCoder Beginner\
    \ Contest 451 G - Minimum XOR Walk\n * https://atcoder.jp/contests/abc451/submissions/74601108\n\
    \ */\n\n#include \"../../Src/DataStructure/Trie/BinaryTrie.hpp\"\n#include \"\
    ../../Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\nusing namespace\
    \ zawa;\n\n#include <array>\n#include <bit>\n#include <iostream>\n#include <vector>\n\
    #include <utility>\nusing namespace std;\nusing item = array<int,30>;\nlong long\
    \ solve() {\n    int N,M,K;\n    cin >> N >> M >> K;\n    vector<vector<pair<int,int>>>\
    \ G(N);\n    DisjointSetUnion dsu(N);\n    vector<tuple<int,int,int>> remain;\n\
    \    for (int i = 0 ; i < M ; i++) {\n        int u,v,w;\n        cin >> u >>\
    \ v >> w;\n        u--; v--;\n        if (!dsu.same(u,v)) {\n            G[u].push_back({v,w});\n\
    \            G[v].push_back({u,w});\n            dsu.merge(u,v);\n        }\n\
    \        else\n            remain.push_back({u,v,w});\n    }\n    vector<int>\
    \ A(N);\n    auto dfs = [&](auto dfs,int v,int p,int k) -> void {\n        A[v]\
    \ = k;\n        for (auto [x,w] : G[v])\n            if (x != p)\n           \
    \     dfs(dfs,x,v,k^w);\n    };\n    dfs(dfs,0,-1,0);\n    item base;\n    base.fill(0);\n\
    \    auto reduce = [&](int& v) {\n        for (int i = 29 ; i >= 0 ; i--)\n  \
    \          if (v & (1 << i))\n                v ^= base[i];\n    };\n    for (auto\
    \ [u,v,w] : remain) {\n        int val = A[u] ^ A[v] ^ w;\n        reduce(val);\n\
    \        if (val)\n            base[bit_width<unsigned>(val)-1] = val;\n    }\
    \ \n    vector<int> P(N);\n    BinaryTrie<30> trie;\n    for (int i = 0 ; i <\
    \ N ; i++) {\n        P[i] = A[i];\n        reduce(P[i]);\n        trie.insert(P[i]);\n\
    \    }\n    long long ans = 0;\n    const int top = bit_width<unsigned>(K)-1;\n\
    \    for (int i = 0 ; i < N ; i++) {\n        trie.erase(P[i]);\n        int nd\
    \ = 1;\n        for (int j = 29 ; nd > 0 and j >= 0 ; j--) {\n            const\
    \ int b = (P[i] >> j) & 1;\n            if (j > top)\n                nd = trie[nd].ch[b];\n\
    \            else if ((K >> j) & 1) {\n                ans += trie[trie[nd].ch[b]].cnt;\n\
    \                nd = trie[nd].ch[b^1];\n            }\n            else\n   \
    \             nd = trie[nd].ch[b];\n        }\n        ans += trie[nd].cnt;\n\
    \        trie.insert(P[i]);\n    }\n    ans /= 2;\n    return ans;\n}\nint main()\
    \ {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int T;\n    cin >> T;\n    while (T--)\n        cout << solve() << '\\n';\n\
    #else\n    int a,b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n#endif\n\
    }\n"
  dependsOn:
  - Src/DataStructure/Trie/BinaryTrie.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc451_g.test.cpp
  requiredBy: []
  timestamp: '2026-04-02 19:07:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc451_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc451_g.test.cpp
- /verify/Test/AtCoder/abc451_g.test.cpp.html
title: Test/AtCoder/abc451_g.test.cpp
---
