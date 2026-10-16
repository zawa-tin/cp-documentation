---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
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
    - https://atcoder.jp/contests/abc479/submissions/80076471
    - https://atcoder.jp/contests/abc479/tasks/abc479_e
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/AtCoder/abc479_e.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc479/tasks/abc479_e\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n/*\n * AtCoder Beginner Contest 479 E - Cut and Add\n * https://atcoder.jp/contests/abc479/submissions/80076471\n\
    \ */\n#line 2 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\n\
    \n#include <algorithm>\n#include <cassert>\n#include <concepts>\n#include <cmath>\n\
    #include <limits>\n#include <optional>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <std::integral V>\nclass HeavyLightDecomposition\
    \ {\npublic:\n\n    HeavyLightDecomposition() = default;\n\n    HeavyLightDecomposition(std::vector<std::vector<V>>\
    \ T, V root = 0u) \n        : m_n{T.size()}, m_par(m_n), m_top(m_n), m_idx(m_n),\
    \ m_out(m_n),\n        m_inv(m_n), m_bottom(m_n),  m_size(m_n, usize{1}), m_dep(m_n)\
    \ {\n\n            auto dfs1 = [&](auto dfs, V v, V p, usize d) -> usize {\n \
    \               m_par[v] = p;\n                m_dep[v] = d;\n               \
    \ if (p != INVALID) {\n                    for (usize i = 0 ; i + 1 < T[v].size()\
    \ ; i++) \n                        if (T[v][i] == p) {\n                     \
    \       std::swap(T[v][i], T[v].back());\n                            break;\n\
    \                        }\n                    assert(T[v].back() == p);\n  \
    \                  T[v].pop_back();\n                }\n                for (V\
    \ x : T[v])\n                    m_size[v] += dfs(dfs, x, v, d + 1);\n       \
    \         for (usize i = 1 ; i < T[v].size() ; i++) \n                    if (m_size[T[v][0]]\
    \ < m_size[T[v][i]])\n                        std::swap(T[v][0], T[v][i]);\n \
    \               return m_size[v];\n            };\n\n            auto dfs2 = [&](auto\
    \ dfs, V v, V idx, V top) -> V {\n                m_idx[v] = idx++;\n        \
    \        m_inv[m_idx[v]] = v;\n                m_top[v] = top;\n             \
    \   if (T[v].size()) {\n                    idx = dfs(dfs, T[v][0], idx, top);\n\
    \                    for (usize i = 1 ; i < T[v].size() ; i++)\n             \
    \           idx = dfs(dfs, T[v][i], idx, T[v][i]);\n                }\n      \
    \          return m_out[v] = idx;\n            };\n\n            dfs1(dfs1, root,\
    \ INVALID, 0u);\n            dfs2(dfs2, root, 0u, root);\n\n            for (usize\
    \ i = 0 ; i < m_n ; i++)\n                if (m_dep[m_bottom[m_top[i]]] < m_dep[i])\n\
    \                    m_bottom[m_top[i]] = i;\n        }\n\n    inline usize size()\
    \ const noexcept {\n        return m_n;\n    }\n\n    usize size(V v) const noexcept\
    \ {\n        assert(v < (V)size());\n        return m_size[v];\n    }\n\n    usize\
    \ depth(V v) const noexcept {\n        assert(v < (V)size());\n        return\
    \ m_dep[v];\n    }\n\n    V parent(V v) const noexcept {\n        assert(v < (V)size());\n\
    \        return m_par[v];\n    }\n\n    V index(V v) const noexcept {\n      \
    \  assert(v < (V)size());\n        return m_idx[v];\n    }\n\n    V operator[](V\
    \ v) const noexcept {\n        assert(v < (V)size());\n        return m_idx[v];\n\
    \    }\n\n    V top(V v) const noexcept {\n        assert(v < (V)size());\n  \
    \      return m_top[v];\n    }\n\n    V bottom(V v) const noexcept {\n       \
    \ assert(v < (V)size());\n        return m_bottom[m_top[v]];\n    }\n\n    std::pair<V,\
    \ V> heavyPath(V v) const {\n        assert(v < (V)size());\n        return {top(v),\
    \ bottom(v)};\n    }\n\n    std::vector<std::pair<V, V>> decomp(V s, V t) const\
    \ {\n        assert(s < (V)size());\n        assert(t < (V)size());\n        std::vector<std::pair<V,\
    \ V>> res, ser;\n        while (m_top[s] != m_top[t]) {\n            if (m_dep[m_top[s]]\
    \ >= m_dep[m_top[t]]) {\n                res.emplace_back(s, m_top[s]);\n    \
    \            s = m_top[s];\n                if (m_par[s] != INVALID) s = m_par[s];\n\
    \            }\n            else {\n                ser.emplace_back(m_top[t],\
    \ t);\n                t = m_top[t];\n                if (m_par[t] != INVALID)\
    \ t = m_par[t];\n            }\n        }\n        res.emplace_back(s, t);\n \
    \       std::reverse(ser.begin(), ser.end());\n        res.insert(res.end(), ser.begin(),\
    \ ser.end()); \n        return res;\n    }\n\n    std::vector<std::pair<V, V>>\
    \ operator()(V s, V t) const {\n        return decomp(s, t);\n    }\n\n    //\
    \ first > second\u306E\u3068\u304D\u306F\u9006\u5411\u304D\u306E\u30D1\u30B9\n\
    \    // \u9006\u5411\u304D\u306B\u306A\u308B\u53EF\u80FD\u6027\u304C\u3042\u308B\
    \u90FD\u5408\u4E0A\u3001\u9589\u533A\u9593\u3067\u8FD4\u3055\u308C\u308B\u3002\
    \n    std::vector<std::pair<V,V>> pathQuery(V s, V t) const {\n        auto res\
    \ = decomp(s,t);\n        for (auto& [u,v] : res) {\n            u = m_idx[u];\n\
    \            v = m_idx[v];\n        }\n        return res;\n    }\n\n    std::pair<V,V>\
    \ subtreeQuery(V v) const {\n        assert(v < (V)size());\n        return {m_idx[v],m_out[v]};\n\
    \    }\n\n    V lca(V u, V v) const {\n        assert(u < (V)size());\n      \
    \  assert(v < (V)size());\n        while (m_top[u] != m_top[v]) {\n          \
    \  if (m_dep[m_top[u]] >= m_dep[m_top[v]]) {\n                u = m_top[u];\n\
    \                if (m_par[u] != INVALID) u = m_par[u];\n            }\n     \
    \       else {\n                v = m_top[v];\n                if (m_par[v] !=\
    \ INVALID) v = m_par[v];\n            }\n        }\n        return (m_dep[u] <=\
    \ m_dep[v] ? u : v);\n    }\n\n    // is p ancestor of v ?\n    bool isAncestor(V\
    \ v, V p) const {\n        assert(v < (V)size());\n        assert(p < (V)size());\n\
    \        return m_idx[p] <= m_idx[v] and m_out[v] <= m_out[p];\n    }\n\n    std::optional<V>\
    \ levelAncestor(V v, usize step) const {\n        assert(v < (V)size());\n   \
    \     if (step > m_dep[v]) return std::nullopt;\n        while (true) {\n    \
    \        usize dist{m_dep[v] - m_dep[m_top[v]]};\n            if (dist >= step)\
    \ break;\n            step -= dist + 1;\n            v = m_par[m_top[v]];\n  \
    \      }\n        step = (m_dep[v] - m_dep[m_top[v]]) - step;\n        return\
    \ m_inv[m_idx[m_top[v]] + step];\n    }\n\n    std::optional<V> jump(V s, V t,\
    \ usize step) const {\n        assert(s < (V)size());\n        assert(t < (V)size());\n\
    \        V uu{INVALID}, vv{INVALID};\n        usize d{};\n        for (auto [u,\
    \ v] : decomp(s, t)) {\n            usize dist{std::max(m_dep[u], m_dep[v]) -\
    \ std::min(m_dep[u], m_dep[v])};\n            if (dist >= step) {\n          \
    \      uu = u;\n                vv = v;\n                d = dist;\n         \
    \       break;\n            }\n            step -= dist + 1;\n        }\n    \
    \    if (uu == INVALID) \n            return std::nullopt;\n        if (m_dep[uu]\
    \ <= m_dep[vv])\n            return m_inv[m_idx[uu] + step];\n        else\n \
    \           return m_inv[m_idx[vv] + (d - step)];\n    }\n\n    usize distance(V\
    \ s, V t) const {\n        assert(s < (V)size());\n        assert(t < (V)size());\n\
    \        usize res{};\n        for (auto [u, v] : decomp(s, t)) {\n          \
    \  if (m_dep[u] > m_dep[v]) std::swap(u, v);\n            res += m_dep[v] - m_dep[u]\
    \ + 1;\n        }\n        return --res;\n    }\n\nprivate:\n\n    static constexpr\
    \ V INVALID{static_cast<V>(-1)};\n\n    usize m_n{};\n\n    std::vector<V> m_par{},\
    \ m_top{}, m_idx{}, m_out{}, m_inv{}, m_bottom{};\n\n    std::vector<usize> m_size{},\
    \ m_dep{};\n};\n\n} // namespace zawa\n#line 8 \"Test/AtCoder/abc479_e.test.cpp\"\
    \n#include <iostream>\n#line 11 \"Test/AtCoder/abc479_e.test.cpp\"\nusing namespace\
    \ std;\nusing namespace zawa;\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n\
    \    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N;\n    cin >> N;\n \
    \   vector<vector<int>> G(N);\n    vector<pair<int,int>> E(N-1);\n    for (int\
    \ i = 0 ; i < N - 1 ; i++) {\n        int a,b;\n        cin >> a >> b;\n     \
    \   a--; b--;\n        G[a].push_back(b);\n        G[b].push_back(a);\n      \
    \  E[i]={a,b};\n    }\n    HeavyLightDecomposition hld{G}; \n    vector<long long>\
    \ imos(N+1);\n    auto operation=[&](int l,int r,int x) {\n        imos[l]+=x;\n\
    \        imos[r]-=x;\n    };\n    for (int i = 0 ; i < N - 1 ; i++) {\n      \
    \  auto [a,b] = E[i];\n        if (hld.isAncestor(a,b))\n            swap(a,b);\n\
    \        // isAncestor(b,a) .. a\u304Cb\u306E\u7956\u5148\n        auto [l,r]=hld.subtreeQuery(b);\n\
    \        if (hld.size(b) > N-hld.size(b))\n            operation(l,r,i+1);\n \
    \       else {\n            operation(0,l,i+1);\n            operation(r,N,i+1);\n\
    \        }\n    }\n    for (int i = 0 ; i < N ; i++)\n        imos[i+1]+=imos[i];\n\
    \    vector<long long> res(N);\n    for (int i = 0 ; i < N ; i++)\n        res[i]=imos[hld[i]];\n\
    \    for (int i = 0 ; i < N ; i++)\n        cout << res[i] << (i+1==N?'\\n': '\
    \ ');\n#else\n    int a,b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n\
    #endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc479/tasks/abc479_e\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n/*\n * AtCoder Beginner\
    \ Contest 479 E - Cut and Add\n * https://atcoder.jp/contests/abc479/submissions/80076471\n\
    \ */\n#include \"../../Src/Graph/Tree/HeavyLightDecomposition.hpp\"\n#include\
    \ <iostream>\n#include <utility>\n#include <vector>\nusing namespace std;\nusing\
    \ namespace zawa;\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n    int N;\n    cin >> N;\n    vector<vector<int>>\
    \ G(N);\n    vector<pair<int,int>> E(N-1);\n    for (int i = 0 ; i < N - 1 ; i++)\
    \ {\n        int a,b;\n        cin >> a >> b;\n        a--; b--;\n        G[a].push_back(b);\n\
    \        G[b].push_back(a);\n        E[i]={a,b};\n    }\n    HeavyLightDecomposition\
    \ hld{G}; \n    vector<long long> imos(N+1);\n    auto operation=[&](int l,int\
    \ r,int x) {\n        imos[l]+=x;\n        imos[r]-=x;\n    };\n    for (int i\
    \ = 0 ; i < N - 1 ; i++) {\n        auto [a,b] = E[i];\n        if (hld.isAncestor(a,b))\n\
    \            swap(a,b);\n        // isAncestor(b,a) .. a\u304Cb\u306E\u7956\u5148\
    \n        auto [l,r]=hld.subtreeQuery(b);\n        if (hld.size(b) > N-hld.size(b))\n\
    \            operation(l,r,i+1);\n        else {\n            operation(0,l,i+1);\n\
    \            operation(r,N,i+1);\n        }\n    }\n    for (int i = 0 ; i < N\
    \ ; i++)\n        imos[i+1]+=imos[i];\n    vector<long long> res(N);\n    for\
    \ (int i = 0 ; i < N ; i++)\n        res[i]=imos[hld[i]];\n    for (int i = 0\
    \ ; i < N ; i++)\n        cout << res[i] << (i+1==N?'\\n': ' ');\n#else\n    int\
    \ a,b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Graph/Tree/HeavyLightDecomposition.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc479_e.test.cpp
  requiredBy: []
  timestamp: '2026-10-16 19:43:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc479_e.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc479_e.test.cpp
- /verify/Test/AtCoder/abc479_e.test.cpp.html
title: Test/AtCoder/abc479_e.test.cpp
---
