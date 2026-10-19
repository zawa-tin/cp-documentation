---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/Rerooting.hpp
    title: "\u6728DP/\u5168\u65B9\u4F4D\u6728DP"
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
    - https://atcoder.jp/contests/abc298/submissions/80190158
    - https://atcoder.jp/contests/abc298/tasks/abc298_h
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/AtCoder/abc298_h.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc298/tasks/abc298_h\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n/*\n * AtCoder Beginner Contest 198 Ex - Sum of Min of Length\n * https://atcoder.jp/contests/abc298/submissions/80190158\n\
    \ */\n#line 2 \"Src/Graph/Tree/Rerooting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Tree/Rerooting.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts\
    \ {\n\ntemplate <class T>\nconcept TreeDP = requires {\n    typename T::Tree;\n\
    \    typename T::Cluster;\n    typename T::Edge;\n    typename T::Vertex;\n  \
    \  { T::Convert(std::declval<typename T::Vertex>()) } -> std::same_as<typename\
    \ T::Tree>;\n    { T::AddEdge(std::declval<typename T::Tree>(), std::declval<typename\
    \ T::Edge>()) } -> std::same_as<typename T::Cluster>;\n    { T::Merge(std::declval<typename\
    \ T::Cluster>(), std::declval<typename T::Cluster>()) } -> std::same_as<typename\
    \ T::Cluster>;\n    { T::AddVertex(std::declval<typename T::Cluster>(), std::declval<typename\
    \ T::Vertex>()) } -> std::same_as<typename T::Tree>;\n};\n\n}\n\ntemplate <concepts::TreeDP\
    \ DP,std::integral T>\nclass Rerooting {\npublic:\n\n    using Tree = DP::Tree;\n\
    \n    using Cluster = DP::Cluster;\n\n    using Edge = DP::Edge;\n\n    using\
    \ Vertex = DP::Vertex;\n\n    Rerooting(usize n,std::vector<std::pair<T,T>> ed,std::vector<Vertex>\
    \ vs,std::vector<Edge> es) \n    : m_n{n}, m_edges{std::move(ed)}, m_alls(n),\
    \ m_sides(m_edges.size()) {\n        assert(m_edges.size()+1==n); \n        assert(m_edges.size()==es.size());\n\
    \        assert(n==vs.size());\n        if (n==1) {\n            m_alls[0]=DP::Convert(vs[0]);\n\
    \            return;\n        }\n        std::vector<std::vector<std::pair<T,u32>>>\
    \ g(n);\n        for (usize i = 0 ; auto [u,v] : m_edges) {\n            g[u].push_back({v,i});\n\
    \            g[v].push_back({u,i});\n            i++;\n        }\n        std::vector<Tree>\
    \ dp(n);\n        auto dfs1=[&](auto dfs,T v,T p) -> Tree {\n            if (std::ssize(g[v])==1\
    \ and g[v][0].first==p)\n                return dp[v]=DP::Convert(vs[v]);\n  \
    \          usize idx=g[v][0].first==p?1:0;\n            assignToSides(dfs(dfs,g[v][idx].first,v),g[v][idx].second,g[v][idx].first);\n\
    \            Cluster prod=DP::AddEdge(dp[g[v][idx].first],es[g[v][idx].second]);\n\
    \            for (idx++ ; idx<g[v].size() ; idx++) \n                if (g[v][idx].first!=p)\
    \ {\n                    assignToSides(dfs(dfs,g[v][idx].first,v),g[v][idx].second,g[v][idx].first);\n\
    \                    prod=DP::Merge(prod,DP::AddEdge(dp[g[v][idx].first],es[g[v][idx].second]));\n\
    \                }\n            return dp[v]=DP::AddVertex(std::move(prod),vs[v]);\n\
    \        };\n        dfs1(dfs1,0,static_cast<T>(0));\n        auto dfs2=[&](auto\
    \ dfs,T v,T p,Tree t) -> void {\n            const usize k=g[v].size();\n    \
    \        std::vector<Cluster> clusters(k);\n            for (usize i = 0 ; i <\
    \ k ; i++) {\n                if (g[v][i].first==p) {\n                    assignToSides(t,g[v][i].second,p);\n\
    \                    clusters[i]=DP::AddEdge(t,es[g[v][i].second]);\n        \
    \        }\n                else\n                    clusters[i]=DP::AddEdge(dp[g[v][i].first],es[g[v][i].second]);\n\
    \            }\n            if (k==1) {\n                m_alls[v]=DP::AddVertex(clusters[0],vs[v]);\n\
    \                if (g[v][0].first!=p) {\n                    assert(!v);\n  \
    \                  dfs(dfs,g[v][0].first,v,DP::Convert(vs[v]));\n            \
    \    }\n            }\n            else {\n                std::vector<Cluster>\
    \ pref=clusters,suf=clusters;\n                for (usize i = 1 ; i < k ; i++)\
    \ {\n                    pref[i]=DP::Merge(pref[i-1],clusters[i]);\n         \
    \           suf[k-i-1]=DP::Merge(clusters[k-i-1],suf[k-i]);\n                }\n\
    \                m_alls[v]=DP::AddVertex(pref[k-1],vs[v]);\n                for\
    \ (usize i = 0 ; i < g[v].size() ; i++) \n                    if (g[v][i].first!=p)\
    \ {\n                        Cluster pc=i?(i+1<g[v].size()?DP::Merge(pref[i-1],suf[i+1]):pref[k-2]):suf[1];\n\
    \                        dfs(dfs,g[v][i].first,v,DP::AddVertex(pc,vs[v]));\n \
    \                   }\n            }\n        };\n        dfs2(dfs2,0,static_cast<T>(0),Tree{});\n\
    \    }\n\n    inline usize size() const noexcept {\n        return m_n;\n    }\n\
    \n    const Tree& operator[](usize i) const noexcept {\n        assert(i < size());\n\
    \        return m_alls[i];\n    }\n\n    const Tree& side(usize i,T v) const {\n\
    \        assert(i < m_sides.size()); \n        if (m_edges[i].first==v)\n    \
    \        return m_sides[i].first;\n        else if (m_edges[i].second==v)\n  \
    \          return m_sides[i].second;\n        assert(0);\n        return m_sides[i].first;\n\
    \    }\n\nprivate:\n\n    void assignToSides(Tree t,usize idx,T v) {\n       \
    \ if (m_edges[idx].first==v)\n            m_sides[idx].first=std::move(t);\n \
    \       else\n            m_sides[idx].second=std::move(t);\n    }\n\n    usize\
    \ m_n;\n\n    std::vector<std::pair<T,T>> m_edges;\n\n    std::vector<Tree> m_alls;\n\
    \n    std::vector<std::pair<Tree,Tree>> m_sides;\n\n};\n\n} // namespace zawa\n\
    #line 2 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\n\n#line 4 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \n\n#include <algorithm>\n#line 8 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \n#include <cmath>\n#include <limits>\n#include <optional>\n#include <utility>\n\
    #line 13 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\n\nnamespace zawa {\n\n\
    template <std::integral V>\nclass HeavyLightDecomposition {\npublic:\n\n    HeavyLightDecomposition()\
    \ = default;\n\n    HeavyLightDecomposition(std::vector<std::vector<V>> T, V root\
    \ = 0u) \n        : m_n{T.size()}, m_par(m_n), m_top(m_n), m_idx(m_n), m_out(m_n),\n\
    \        m_inv(m_n), m_bottom(m_n),  m_size(m_n, usize{1}), m_dep(m_n) {\n\n \
    \           auto dfs1 = [&](auto dfs, V v, V p, usize d) -> usize {\n        \
    \        m_par[v] = p;\n                m_dep[v] = d;\n                if (p !=\
    \ INVALID) {\n                    for (usize i = 0 ; i + 1 < T[v].size() ; i++)\
    \ \n                        if (T[v][i] == p) {\n                            std::swap(T[v][i],\
    \ T[v].back());\n                            break;\n                        }\n\
    \                    assert(T[v].back() == p);\n                    T[v].pop_back();\n\
    \                }\n                for (V x : T[v])\n                    m_size[v]\
    \ += dfs(dfs, x, v, d + 1);\n                for (usize i = 1 ; i < T[v].size()\
    \ ; i++) \n                    if (m_size[T[v][0]] < m_size[T[v][i]])\n      \
    \                  std::swap(T[v][0], T[v][i]);\n                return m_size[v];\n\
    \            };\n\n            auto dfs2 = [&](auto dfs, V v, V idx, V top) ->\
    \ V {\n                m_idx[v] = idx++;\n                m_inv[m_idx[v]] = v;\n\
    \                m_top[v] = top;\n                if (T[v].size()) {\n       \
    \             idx = dfs(dfs, T[v][0], idx, top);\n                    for (usize\
    \ i = 1 ; i < T[v].size() ; i++)\n                        idx = dfs(dfs, T[v][i],\
    \ idx, T[v][i]);\n                }\n                return m_out[v] = idx;\n\
    \            };\n\n            dfs1(dfs1, root, INVALID, 0u);\n            dfs2(dfs2,\
    \ root, 0u, root);\n\n            for (usize i = 0 ; i < m_n ; i++)\n        \
    \        if (m_dep[m_bottom[m_top[i]]] < m_dep[i])\n                    m_bottom[m_top[i]]\
    \ = i;\n        }\n\n    inline usize size() const noexcept {\n        return\
    \ m_n;\n    }\n\n    usize size(V v) const noexcept {\n        assert(v < (V)size());\n\
    \        return m_size[v];\n    }\n\n    usize depth(V v) const noexcept {\n \
    \       assert(v < (V)size());\n        return m_dep[v];\n    }\n\n    V parent(V\
    \ v) const noexcept {\n        assert(v < (V)size());\n        return m_par[v];\n\
    \    }\n\n    V index(V v) const noexcept {\n        assert(v < (V)size());\n\
    \        return m_idx[v];\n    }\n\n    V operator[](V v) const noexcept {\n \
    \       assert(v < (V)size());\n        return m_idx[v];\n    }\n\n    V top(V\
    \ v) const noexcept {\n        assert(v < (V)size());\n        return m_top[v];\n\
    \    }\n\n    V bottom(V v) const noexcept {\n        assert(v < (V)size());\n\
    \        return m_bottom[m_top[v]];\n    }\n\n    std::pair<V, V> heavyPath(V\
    \ v) const {\n        assert(v < (V)size());\n        return {top(v), bottom(v)};\n\
    \    }\n\n    std::vector<std::pair<V, V>> decomp(V s, V t) const {\n        assert(s\
    \ < (V)size());\n        assert(t < (V)size());\n        std::vector<std::pair<V,\
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
    \ m_dep{};\n};\n\n} // namespace zawa\n#line 9 \"Test/AtCoder/abc298_h.test.cpp\"\
    \n#include <iostream>\n#line 11 \"Test/AtCoder/abc298_h.test.cpp\"\n#include <unordered_map>\n\
    #line 13 \"Test/AtCoder/abc298_h.test.cpp\"\nusing namespace std;\nusing namespace\
    \ zawa;\nstruct DP {\n    using Tree = pair<long long,int>;\n    using Cluster\
    \ = pair<long long,int>;\n    using Edge = struct {};\n    using Vertex = struct\
    \ {};\n    static Tree Convert(Vertex) {\n        return {0LL,1};\n    }\n   \
    \ static Cluster AddEdge(Tree t,Edge) {\n        return {t.first+t.second,t.second};\n\
    \    }\n    static Cluster Merge(Cluster l,Cluster r) {\n        return {l.first+r.first,l.second+r.second};\n\
    \    }\n    static Tree AddVertex(Cluster c,Vertex) {\n        return {c.first,c.second+1};\n\
    \    }\n};\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n    int N;\n    cin >> N;\n    vector<pair<int,int>>\
    \ E(N-1);\n    vector<vector<int>> G(N);\n    vector<unordered_map<int,int>> id(N);\n\
    \    for (int i = 0 ; auto& [a,b] : E) {\n        cin >> a >> b;\n        a--;\
    \ b--;\n        G[a].push_back(b);\n        G[b].push_back(a);\n        id[a][b]=i;\n\
    \        id[b][a]=i;\n        i++;\n    }\n    Rerooting<DP,int> dp(N,E,vector<DP::Vertex>(N),vector<DP::Edge>(N-1));\n\
    \    HeavyLightDecomposition hld{G};\n    int Q;\n    cin >> Q;\n    while (Q--)\
    \ {\n        int u,v;\n        cin >> u >> v;\n        u--; v--;\n        if (u\
    \ == v) \n            cout << dp[u].first << '\\n';\n        else {\n        \
    \    const int d=hld.distance(u,v);\n            const int p=hld.jump(u,v,d/2).value(),q=hld.jump(p,v,1).value();\n\
    \            long long ans=dp[u].first+dp[v].first;\n            {\n         \
    \       auto side=dp.side(id[p][q],q);\n                ans-=side.first+(long\
    \ long)side.second*(d/2+1);\n            }\n            {\n                auto\
    \ side=dp.side(id[q][p],p);\n                ans-=side.first+(long long)side.second*((d+1)/2);\n\
    \            }\n            cout << ans << '\\n';\n        }\n    }\n#else\n \
    \   int a,b;\n    cin >> a >> b;\n    cout << a+b << '\\n';\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc298/tasks/abc298_h\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n/*\n * AtCoder Beginner\
    \ Contest 198 Ex - Sum of Min of Length\n * https://atcoder.jp/contests/abc298/submissions/80190158\n\
    \ */\n#include \"../../Src/Graph/Tree/Rerooting.hpp\"\n#include \"../../Src/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \n#include <iostream>\n#include <utility>\n#include <unordered_map>\n#include\
    \ <vector>\nusing namespace std;\nusing namespace zawa;\nstruct DP {\n    using\
    \ Tree = pair<long long,int>;\n    using Cluster = pair<long long,int>;\n    using\
    \ Edge = struct {};\n    using Vertex = struct {};\n    static Tree Convert(Vertex)\
    \ {\n        return {0LL,1};\n    }\n    static Cluster AddEdge(Tree t,Edge) {\n\
    \        return {t.first+t.second,t.second};\n    }\n    static Cluster Merge(Cluster\
    \ l,Cluster r) {\n        return {l.first+r.first,l.second+r.second};\n    }\n\
    \    static Tree AddVertex(Cluster c,Vertex) {\n        return {c.first,c.second+1};\n\
    \    }\n};\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n    int N;\n    cin >> N;\n    vector<pair<int,int>>\
    \ E(N-1);\n    vector<vector<int>> G(N);\n    vector<unordered_map<int,int>> id(N);\n\
    \    for (int i = 0 ; auto& [a,b] : E) {\n        cin >> a >> b;\n        a--;\
    \ b--;\n        G[a].push_back(b);\n        G[b].push_back(a);\n        id[a][b]=i;\n\
    \        id[b][a]=i;\n        i++;\n    }\n    Rerooting<DP,int> dp(N,E,vector<DP::Vertex>(N),vector<DP::Edge>(N-1));\n\
    \    HeavyLightDecomposition hld{G};\n    int Q;\n    cin >> Q;\n    while (Q--)\
    \ {\n        int u,v;\n        cin >> u >> v;\n        u--; v--;\n        if (u\
    \ == v) \n            cout << dp[u].first << '\\n';\n        else {\n        \
    \    const int d=hld.distance(u,v);\n            const int p=hld.jump(u,v,d/2).value(),q=hld.jump(p,v,1).value();\n\
    \            long long ans=dp[u].first+dp[v].first;\n            {\n         \
    \       auto side=dp.side(id[p][q],q);\n                ans-=side.first+(long\
    \ long)side.second*(d/2+1);\n            }\n            {\n                auto\
    \ side=dp.side(id[q][p],p);\n                ans-=side.first+(long long)side.second*((d+1)/2);\n\
    \            }\n            cout << ans << '\\n';\n        }\n    }\n#else\n \
    \   int a,b;\n    cin >> a >> b;\n    cout << a+b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Graph/Tree/Rerooting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc298_h.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 15:41:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc298_h.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc298_h.test.cpp
- /verify/Test/AtCoder/abc298_h.test.cpp.html
title: Test/AtCoder/abc298_h.test.cpp
---
