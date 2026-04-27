---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/RMQ/PM1RMQ.hpp
    title: Src/DataStructure/RMQ/PM1RMQ.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Components/BridgeTree.hpp
    title: "Bridge tree (+ \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/LowestCommonAncestor.hpp
    title: Lowest Common Ancestor
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
    - https://atcoder.jp/contests/arc039/submissions/75305818
    - https://atcoder.jp/contests/arc039/tasks/arc039_d
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/AtCoder/arc039_d.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/arc039/tasks/arc039_d\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n/*\n * AtCoder Regular Contest 039 D - \u65C5\u884C\u4F1A\u793E\u9AD8\u6A4B\
    \u541B\n * https://atcoder.jp/contests/arc039/submissions/75305818\n */\n\n#line\
    \ 2 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\n\n#line 4\
    \ \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\n\n#include <algorithm>\n#include <array>\n\
    #include <bit>\n#include <cassert>\n#include <concepts>\n#include <utility>\n\
    #include <vector>\n\n\nnamespace zawa {\n\ntemplate <std::totally_ordered T>\n\
    class PM1RMQ {\nprivate:\n\n    static constexpr usize B = 8;\n\n    static constexpr\
    \ usize BMASK = 7;\n\n    static constexpr usize LOGB = 3;\n\n    static constexpr\
    \ usize TRI = B*(B+1)/2;\n\npublic:\n\n    PM1RMQ() = default;\n\n    PM1RMQ(std::vector<T>\
    \ a) \n        : m_n{a.size()}, m_inner{(a.size()+B-1)>>LOGB},\n        m_a{std::move(a)},\
    \ m_look(innerSize()), m_table(), m_spt(std::bit_width(innerSize()))\n    {\n\
    \        std::vector<u32> minIndex(innerSize());\n        std::vector<bool> registered(1u\
    \ << (B-1));\n        for (usize i = 0,idx = 0 ; i < size() ; idx++) {\n     \
    \       minIndex[idx] = i;\n            for (u8 j = 1 ; ++i < size() and j < (u8)B\
    \ ; j++) {\n                if (m_a[i] < m_a[minIndex[idx]])\n               \
    \     minIndex[idx] = i;\n                if (m_a[i] == m_a[i-1]+1)\n        \
    \            ;\n                else if (m_a[i] == m_a[i-1]-1)\n             \
    \       m_look[idx] |= u8{1} << (j-1);\n                else\n               \
    \     assert(!\"init table does not satisfy |a_i-a_{i+1}| = 1\");\n          \
    \  }\n            if (!registered[m_look[idx]]) {\n                registered[m_look[idx]]\
    \ = 1;\n                registerTable(m_look[idx]);\n            }\n        }\n\
    \        m_spt[0] = std::move(minIndex);\n        for (usize i = 1,len = 2 ; i\
    \ < m_spt.size() ; i++,len <<= 1) {\n            m_spt[i].resize(innerSize()-len+1);\n\
    \            for (usize j = 0 ; j < m_spt[i].size() ; j++) {\n               \
    \ u32 l = m_spt[i-1][j], r = m_spt[i-1][j+(len>>1)];\n                m_spt[i][j]\
    \ = m_a[r] < m_a[l] ? r : l;\n            }\n        }\n    }\n\n    inline usize\
    \ size() const {\n        return m_n;\n    }\n\n    // return leftmost index of\
    \ min{a[l],a[l+1],...,a[r-1]} (min of argmin)\n    // empty is not allowed\n \
    \   usize min(usize l,usize r) const {\n        assert(l < r and r <= size());\n\
    \        usize L = l>>LOGB, R = (r-1)>>LOGB;\n        if (L == R)\n          \
    \  return accessTable(L,l&BMASK,r-(L<<LOGB));\n        u32 res = accessTable(L,l&BMASK,B);\n\
    \        L++;\n        if (L < R) {\n            u32 pd = sptMin(L,R);\n     \
    \       if (m_a[pd] < m_a[res])\n                res = pd;\n        }\n      \
    \  u32 rv = accessTable(R,0u,r-(R<<LOGB));\n        if (m_a[rv] < m_a[res])\n\
    \            res = rv;\n        return static_cast<usize>(res);\n    }\n\n   \
    \ usize operator()(usize l,usize r) const {\n        return min(l,r);\n    }\n\
    \nprivate:\n\n    usize m_n,m_inner;\n\n    std::vector<T> m_a;\n\n    // 0..+1,1..-1\n\
    \    std::vector<u8> m_look;\n\n    std::array<u8,(1u << (B-1))*TRI> m_table;\n\
    \n    std::vector<std::vector<u32>> m_spt;\n\n    inline usize innerSize() const\
    \ {\n        return m_inner;\n    }\n\n    usize encode(usize l,usize r) const\
    \ {\n        // assert(l < r and r <= B);\n        static constexpr std::array<uint32_t,8>\
    \ Row{0,8,15,21,26,30,33,35};\n        return Row[l]+(r-l-1);\n    }\n\n    void\
    \ registerTable(usize info) {\n        const usize offset = TRI*info;\n      \
    \  std::vector<usize> val(B);\n        val[0] = B;\n        for (usize i = 0 ;\
    \ i + 1 < B ; i++) {\n            val[i+1] = val[i];\n            if (info & (1u\
    \ << i))\n                val[i+1]--;\n            else\n                val[i+1]++;\n\
    \        }\n        for (u8 l = 0 ; l < B ; l++) {\n            u8 mn = l;\n \
    \           for (u8 r = l ; r < B ; r++) {\n                if (val[mn] > val[r])\n\
    \                    mn = r;\n                m_table[offset+encode(l,r+1)] =\
    \ mn;\n            }\n        }\n    }\n\n    usize accessTable(usize idx,usize\
    \ l,usize r) const {\n        return (idx<<LOGB) + m_table[m_look[idx]*TRI+encode(l,r)];\n\
    \    }\n\n    u32 sptMin(usize l,usize r) const {\n        usize dep = std::bit_width(r-l)-1,\
    \ i = m_spt[dep][l], j = m_spt[dep][r-(1u<<dep)];\n        return m_a[j] < m_a[i]\
    \ ? j : i;\n    }\n};\n\n} // namespace zawa\n#line 5 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\
    \n\n#line 9 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\n\nnamespace zawa {\n\n\
    template <class V>\nclass LowestCommonAncestor {\npublic:\n\n    LowestCommonAncestor()\
    \ = default;\n\n    LowestCommonAncestor(const std::vector<std::vector<V>>& g,V\
    \ r = 0) \n        : m_n{g.size()}, m_inv{}, m_left(size()), m_right(size()),\
    \ m_dep(size())\n    {\n        std::vector<u32> ord;\n        ord.reserve(2*size());\n\
    \        m_inv.reserve(2*size());\n        auto dfs = [&](auto dfs,V v,V p,u32\
    \ d) -> void {\n            m_left[v] = ord.size();\n            ord.push_back(d);\n\
    \            m_inv.push_back(v);\n            m_dep[v] = d;\n            for (V\
    \ x : g[v])\n                if (x != p) {\n                    dfs(dfs,x,v,d+1);\n\
    \                    ord.push_back(d);\n                    m_inv.push_back(v);\n\
    \                }\n            m_right[v] = ord.size();\n        };\n       \
    \ dfs(dfs,r,static_cast<V>(-1),0);\n        m_rmq = PM1RMQ{std::move(ord)};\n\
    \    }\n\n    V lca(V u,V v) const {\n        assert(verify(u));\n        assert(verify(v));\n\
    \        if (u == v)\n            return u;\n        if (m_left[u] > m_left[v])\n\
    \            std::swap(u,v);\n        return m_inv[m_rmq.min(m_left[u],m_right[v])];\n\
    \    }\n\n    V operator()(V u,V v) const {\n        return lca(u,v);\n    }\n\
    \n    inline usize depth(V v) const {\n        assert(verify(v));\n        return\
    \ m_dep[v];\n    }\n\n    usize distance(V u,V v) const {\n        assert(verify(u));\n\
    \        assert(verify(v));\n        return m_dep[u] + m_dep[v] - 2*m_dep[lca(u,v)];\n\
    \    }\n\n    bool isAncestor(V p,V v) const {\n        assert(verify(p));\n \
    \       assert(verify(v));\n        return m_left[p] <= m_left[v] and m_right[v]\
    \ <= m_right[p];\n    }\n\n    std::pair<usize,usize> subtreeRange(V v) const\
    \ {\n        assert(verify(v));\n        return {m_left[v],m_right[v]};\n    }\n\
    \nprotected:\n\n    inline usize size() const {\n        return m_n;\n    }\n\n\
    \    inline bool verify(V v) const {\n        return static_cast<usize>(v) < size();\n\
    \    }\n\n    inline usize left(V v) const {\n        assert(verify(v));\n   \
    \     return m_left[v];\n    }\n\n    inline usize right(V v) const {\n      \
    \  assert(verify(v));\n        return m_right[v];\n    }\n\nprivate:\n\n    usize\
    \ m_n;\n    \n    std::vector<usize> m_inv,m_left,m_right,m_dep;\n\n    PM1RMQ<u32>\
    \ m_rmq;\n};\n\n} // namespace zawa\n#line 2 \"Src/Graph/Components/BridgeTree.hpp\"\
    \n\n#line 4 \"Src/Graph/Components/BridgeTree.hpp\"\n\n#line 7 \"Src/Graph/Components/BridgeTree.hpp\"\
    \n#include <ranges>\n#line 9 \"Src/Graph/Components/BridgeTree.hpp\"\n\nnamespace\
    \ zawa {\n\ntemplate <std::integral T>\nclass BridgeTreeBuilder {\n\n    class\
    \ BridgeTree {\n    public:\n\n        BridgeTree(const std::vector<std::vector<std::pair<T,usize>>>&\
    \ g,const std::vector<std::pair<T,T>>& edge) \n            : m_isBridge(edge.size()),\
    \ m_id(g.size()), m_comps{}, m_g{} {\n            const usize n = g.size();\n\
    \            const usize m = edge.size();\n            std::vector<u32> low(n),ord(n);\n\
    \            std::vector<T> remain;\n            u32 time = 1;\n            auto\
    \ dfs = [&](auto dfs,usize v,usize pe) -> void {\n                ord[v] = low[v]\
    \ = time++;\n                for (auto [x,id] : g[v])\n                    if\
    \ (pe != id) {\n                        if (ord[x]) {\n                      \
    \      low[v] = std::min(low[v],ord[x]);\n                        }\n        \
    \                else {\n                            dfs(dfs,x,id);\n        \
    \                    low[v] = std::min(low[v],low[x]);\n                     \
    \       if (ord[v] < low[x]) {\n                                m_isBridge[id]\
    \ = 1;\n                                std::vector<T> cur;\n                \
    \                const T id = static_cast<T>(m_comps.size());\n              \
    \                  while (remain.size() and ord[v] < low[remain.back()]) {\n \
    \                                   cur.push_back(remain.back());\n          \
    \                          m_id[remain.back()] = id;\n                       \
    \             remain.pop_back();\n                                }\n        \
    \                        m_comps.push_back(std::move(cur));\n                \
    \            }\n                        }\n                    }\n           \
    \     remain.push_back(v);\n            };\n            for (usize i = 0 ; i <\
    \ n ; i++)\n                if (!ord[i]) {\n                    remain.clear();\n\
    \                    dfs(dfs,i,edge.size());\n                    for (T j : remain)\n\
    \                        m_id[j] = static_cast<T>(m_comps.size());\n         \
    \           m_comps.push_back(remain);\n                }\n            m_g.resize(m_comps.size());\n\
    \            for (usize i = 0 ; i < m ; i++) \n                if (m_isBridge[i])\
    \ {\n                    auto [u,v] = edge[i];\n                    m_g[m_id[u]].push_back({m_id[v],i});\n\
    \                    m_g[m_id[v]].push_back({m_id[u],i});\n                }\n\
    \        }\n\n        inline usize size() const {\n            return m_g.size();\n\
    \        }\n\n        T id(T v) const {\n            assert(static_cast<usize>(v)\
    \ < m_id.size());\n            return m_id[v];\n        }\n\n        bool isBridge(usize\
    \ i) const {\n            assert(i < m_isBridge.size());\n            return m_isBridge[i];\n\
    \        }\n\n        const std::vector<T>& component(T i) const {\n         \
    \   assert(static_cast<usize>(i) < size());\n            return m_comps[i];\n\
    \        }\n\n        const std::vector<std::vector<T>>& components() const {\n\
    \            return m_comps;\n        }\n\n        const std::vector<std::pair<T,usize>>&\
    \ operator[](T i) const {\n            assert(static_cast<usize>(i) < size());\n\
    \            return m_g[i];\n        }\n\n    private:\n        \n        std::vector<bool>\
    \ m_isBridge;\n\n        std::vector<T> m_id;\n        \n        std::vector<std::vector<T>>\
    \ m_comps;\n\n        std::vector<std::vector<std::pair<T,usize>>> m_g;\n    };\n\
    \npublic:\n\n    BridgeTreeBuilder() = default;\n\n    explicit BridgeTreeBuilder(usize\
    \ n) : m_n{n}, m_g(n) {}\n\n    inline usize size() const {\n        return m_n;\n\
    \    }\n\n    inline usize edgeSize() const {\n        return m_edge.size();\n\
    \    }\n\n    usize addEdge(T u,T v) {\n        assert(static_cast<usize>(u) <\
    \ size());\n        assert(static_cast<usize>(v) < size());\n        usize res\
    \ = m_edge.size();\n        m_g[u].push_back({v,res});\n        m_g[v].push_back({u,res});\n\
    \        m_edge.push_back({u,v});\n        return res;\n    }\n\n    std::pair<T,T>\
    \ getEdge(usize i) const {\n        assert(i < m_edge.size());\n        return\
    \ m_edge[i];\n    }\n\n    BridgeTree build() const {\n        return BridgeTree{m_g,m_edge};\n\
    \    }\n\nprivate:\n\n    usize m_n;\n\n    std::vector<std::vector<std::pair<T,usize>>>\
    \ m_g;\n\n    std::vector<std::pair<T,T>> m_edge;\n\n};\n\n} // namespace zawa\n\
    #line 11 \"Test/AtCoder/arc039_d.test.cpp\"\n\n#include <iostream>\n#include <iterator>\n\
    #line 16 \"Test/AtCoder/arc039_d.test.cpp\"\nusing namespace std;\n\nint main()\
    \ {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N,M;\n    cin >> N >> M;\n    zawa::BridgeTreeBuilder<int> builder(N);\n\
    \    for (int i = 0 ; i < M ; i++) {\n        int x,y;\n        cin >> x >> y;\n\
    \        builder.addEdge(--x,--y);\n    }\n    auto BT = builder.build();\n  \
    \  vector<vector<int>> g(BT.size());\n    for (int i = 0 ; i < ssize(g) ; i++)\n\
    \        for (int j : BT[i] | views::keys)\n            g[i].push_back(j);\n \
    \   zawa::LowestCommonAncestor lca(g); \n    int Q;\n    cin >> Q;\n    while\
    \ (Q--) {\n        int a,b,c;\n        cin >> a >> b >> c;\n        a--; b--;\
    \ c--;\n        a = BT.id(a);\n        b = BT.id(b);\n        c = BT.id(c);\n\
    \        bool ans = lca.distance(a,b)+lca.distance(b,c)==lca.distance(a,c);\n\
    \        cout << (ans ? \"OK\\n\" : \"NG\\n\");\n    }\n#else\n    int a,b;\n\
    \    cin >> a >> b;\n    cout << a + b << '\\n';\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/arc039/tasks/arc039_d\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n/*\n * AtCoder Regular\
    \ Contest 039 D - \u65C5\u884C\u4F1A\u793E\u9AD8\u6A4B\u541B\n * https://atcoder.jp/contests/arc039/submissions/75305818\n\
    \ */\n\n#include \"../../Src/Graph/Tree/LowestCommonAncestor.hpp\"\n#include \"\
    ../../Src/Graph/Components/BridgeTree.hpp\"\n\n#include <iostream>\n#include <iterator>\n\
    #include <vector>\n#include <ranges>\nusing namespace std;\n\nint main() {\n#ifdef\
    \ ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n \
    \   int N,M;\n    cin >> N >> M;\n    zawa::BridgeTreeBuilder<int> builder(N);\n\
    \    for (int i = 0 ; i < M ; i++) {\n        int x,y;\n        cin >> x >> y;\n\
    \        builder.addEdge(--x,--y);\n    }\n    auto BT = builder.build();\n  \
    \  vector<vector<int>> g(BT.size());\n    for (int i = 0 ; i < ssize(g) ; i++)\n\
    \        for (int j : BT[i] | views::keys)\n            g[i].push_back(j);\n \
    \   zawa::LowestCommonAncestor lca(g); \n    int Q;\n    cin >> Q;\n    while\
    \ (Q--) {\n        int a,b,c;\n        cin >> a >> b >> c;\n        a--; b--;\
    \ c--;\n        a = BT.id(a);\n        b = BT.id(b);\n        c = BT.id(c);\n\
    \        bool ans = lca.distance(a,b)+lca.distance(b,c)==lca.distance(a,c);\n\
    \        cout << (ans ? \"OK\\n\" : \"NG\\n\");\n    }\n#else\n    int a,b;\n\
    \    cin >> a >> b;\n    cout << a + b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Graph/Tree/LowestCommonAncestor.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/RMQ/PM1RMQ.hpp
  - Src/Graph/Components/BridgeTree.hpp
  isVerificationFile: true
  path: Test/AtCoder/arc039_d.test.cpp
  requiredBy: []
  timestamp: '2026-04-27 14:04:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/arc039_d.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/arc039_d.test.cpp
- /verify/Test/AtCoder/arc039_d.test.cpp.html
title: Test/AtCoder/arc039_d.test.cpp
---
