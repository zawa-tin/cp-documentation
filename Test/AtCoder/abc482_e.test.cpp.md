---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/TreeCenters.hpp
    title: "\u6728\u306E\u76F4\u5F84\u306B\u307E\u3064\u308F\u308BUtility\u30AF\u30E9\
      \u30B9"
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
    - https://atcoder.jp/contests/abc482/submissions/80544207
    - https://atcoder.jp/contests/abc482/tasks/abc482_e
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/AtCoder/abc482_e.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc482/tasks/abc482_e\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n/*\n * AtCoder Beginner Contest 482 E - Diameter Endpoint Colors\n * https://atcoder.jp/contests/abc482/submissions/80544207\n\
    \ */\n#line 2 \"Src/Graph/Tree/TreeCenters.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Tree/TreeCenters.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <concepts>\n#include <optional>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <std::integral\
    \ T,class U>\nclass TreeCenters {\npublic:\n\n    explicit TreeCenters(std::vector<std::vector<std::pair<T,U>>>\
    \ g) \n        : m_g{std::move(g)},m_path{},m_root{} {\n        assert(size()\
    \ and \"TreeCenters: empty graph is not a tree\");\n        auto d0=bfs(0).first;\n\
    \        const T p=std::ranges::max_element(d0)-d0.begin();\n        auto [dp,prev]=bfs(p);\n\
    \        const T q=std::ranges::max_element(dp)-dp.begin();\n        auto dq=bfs(q).first;\n\
    \        for (i32 v = static_cast<i32>(q) ; ; v = prev[v]) {\n            m_path.push_back(v);\n\
    \            if (static_cast<T>(v)==p)\n                break;\n        }\n  \
    \      const auto [u,v]=[&]() -> std::pair<T,T> {\n            for (usize i =\
    \ 0 ; i < m_path.size() ; i++)\n                if (dq[m_path[i]]==dp[m_path[i]])\n\
    \                    return {m_path[i],m_path[i]};\n            for (usize i =\
    \ 0 ; i + 1 < m_path.size() ; i++) {\n                T u=m_path[i],v=m_path[i+1];\n\
    \                if (dq[u]<dp[u] and dq[v]>dp[v])\n                    return\
    \ {u,v};\n            }\n            // std::unreachable();\n            assert(0);\n\
    \            return {0,0};\n        }();\n        if (u==v)\n            m_root=v;\n\
    \        else {\n            U w=0;\n            for (auto it=m_g[u].begin() ;\
    \ it != m_g[u].end() ; it++)\n                if (it->first==v) {\n          \
    \          w=it->second;\n                    it=m_g[u].erase(it);\n         \
    \           break;\n                }\n            for (auto it=m_g[v].begin()\
    \ ; it != m_g[v].end() ; it++)\n                if (it->first==u) {\n        \
    \            it=m_g[v].erase(it);\n                    break;\n              \
    \  }\n            assert(w>0);\n            std::vector<std::pair<T,U>> adj;\n\
    \            adj.push_back({u,w/2});\n            adj.push_back({v,w/2+w%2});\n\
    \            dp.push_back(dp[v]+w/2+w%2);\n            dq.push_back(dq[u]+w/2);\n\
    \            m_root=size();\n            m_g.push_back(std::move(adj));\n    \
    \    }\n        m_farthest.resize(size());\n        for (usize i = 0 ; i < size()\
    \ ; i++)\n            m_farthest[i]=dp[i]<dq[i]?std::pair{q,dq[i]}:std::pair{p,dp[i]};\n\
    \        m_par.resize(size(),-1);\n        dfs(m_root,-1);\n    }\n\n    explicit\
    \ TreeCenters(std::vector<std::vector<T>> g) : TreeCenters(convert(std::move(g)))\
    \ {}\n\n    inline usize size() const noexcept {\n        return m_g.size();\n\
    \    }\n\n    inline const std::vector<T>& diameterPath() const {\n        return\
    \ m_path;\n    }\n\n    U diameterLength() const {\n        return m_farthest[m_path[0]].second;\n\
    \    }\n\n    inline T root() const noexcept {\n        return m_root;\n    }\n\
    \n    inline const std::vector<std::pair<T,U>>& operator[](usize v) const noexcept\
    \ {\n        assert(v<size());\n        return m_g[v];\n    }\n\n    inline i32\
    \ parent(usize v) const noexcept {\n        assert(v<size());\n        return\
    \ m_par[v];\n    }\n    \n    inline const std::pair<T,U>& farthest(usize v) const\
    \ noexcept {\n        assert(v<size());\n        return m_farthest[v];\n    }\n\
    \nprivate:\n\n    std::pair<std::vector<U>,std::vector<i32>> bfs(T s) const {\n\
    \        std::vector<T> que{s};\n        std::vector<U> dist(size(),static_cast<U>(-1));\n\
    \        dist[s]=0;\n        std::vector<i32> prev(size(),-1);\n        for (usize\
    \ t = 0 ; t < que.size() ; t++) {\n            const T v=que[t];\n           \
    \ for (auto [x,w] : m_g[v]) {\n                assert(w > 0 and \"TreeCenters:\
    \ edge weight must be positive\");\n                if (dist[x]==-1) {\n     \
    \               dist[x]=dist[v]+w;\n                    prev[x]=v;\n         \
    \           que.push_back(x);\n                }\n            }\n        }\n \
    \       return {std::move(dist),std::move(prev)};\n    }\n\n    void dfs(T v,T\
    \ p) {\n        m_par[v]=p;\n        for (auto it=m_g[v].begin() ; it!=m_g[v].end()\
    \ ; ) {\n            if (it->first==p)\n                it=m_g[v].erase(it);\n\
    \            else {\n                dfs(it->first,v);\n                it++;\n\
    \            }\n        }\n    }\n\n    static std::vector<std::vector<std::pair<T,U>>>\
    \ convert(std::vector<std::vector<T>> g) {\n        std::vector<std::vector<std::pair<T,U>>>\
    \ res(g.size());\n        for (usize i = 0 ; i < g.size() ; i++)\n           \
    \ for (T x : g[i])\n                res[i].push_back({x,U{1}});\n        return\
    \ res;\n    }\n\n    std::vector<std::vector<std::pair<T,U>>> m_g;\n\n    std::vector<T>\
    \ m_path;\n\n    T m_root;\n\n    std::vector<i32> m_par;\n\n    std::vector<std::pair<T,U>>\
    \ m_farthest;\n\n};\n\n} // namespace zawa\n#line 9 \"Test/AtCoder/abc482_e.test.cpp\"\
    \n#include <ranges>\n#include <iostream>\nusing namespace std;\nint main() {\n\
    #ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N;\n    cin >> N;\n    vector<vector<int>> G(N);\n    for (int i = 0\
    \ ; i < N - 1 ; i++) {\n        int u,v;\n        cin >> u >> v;\n        u--;\
    \ v--;\n        G[u].push_back(v);\n        G[v].push_back(u);\n    }\n    vector<int>\
    \ C(N);\n    for (auto& x : C) {\n        cin >> x;\n        x--;\n    }\n   \
    \ zawa::TreeCenters<int,int> cent{move(G)};\n    const int diam=cent.diameterLength();\
    \ \n    auto dfs=[&](auto dfs,int v,vector<int>& upd)->void{\n        if (cent.farthest(v).second==diam)\n\
    \            upd.push_back(C[v]);\n        for (int x : cent[v]|views::keys)\n\
    \            dfs(dfs,x,upd);\n    };\n    vector dp(N,vector<long long>{1,0,0});\n\
    \    for (int v : cent[cent.root()]|views::keys) {\n        vector<int> upd;\n\
    \        dfs(dfs,v,upd);\n        ranges::sort(upd);\n        for (int i = 0,\
    \ j = 0 ; i < ssize(upd) ; i = j) {\n            while (j < ssize(upd) and upd[i]==upd[j])\n\
    \                j++;\n            dp[upd[i]][2]+=dp[upd[i]][1]*(j-i);\n     \
    \       dp[upd[i]][1]+=dp[upd[i]][0]*(j-i);\n        }\n    }\n    long long ans=0;\n\
    \    for (auto d : dp)\n        ans += d[2];\n    cout << ans << '\\n';\n#else\n\
    \    int a,b;\n    cin >> a >> b;\n    cout << a+b << '\\n';\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc482/tasks/abc482_e\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n/*\n * AtCoder Beginner\
    \ Contest 482 E - Diameter Endpoint Colors\n * https://atcoder.jp/contests/abc482/submissions/80544207\n\
    \ */\n#include \"../../Src/Graph/Tree/TreeCenters.hpp\"\n#include <algorithm>\n\
    #include <ranges>\n#include <iostream>\nusing namespace std;\nint main() {\n#ifdef\
    \ ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n \
    \   int N;\n    cin >> N;\n    vector<vector<int>> G(N);\n    for (int i = 0 ;\
    \ i < N - 1 ; i++) {\n        int u,v;\n        cin >> u >> v;\n        u--; v--;\n\
    \        G[u].push_back(v);\n        G[v].push_back(u);\n    }\n    vector<int>\
    \ C(N);\n    for (auto& x : C) {\n        cin >> x;\n        x--;\n    }\n   \
    \ zawa::TreeCenters<int,int> cent{move(G)};\n    const int diam=cent.diameterLength();\
    \ \n    auto dfs=[&](auto dfs,int v,vector<int>& upd)->void{\n        if (cent.farthest(v).second==diam)\n\
    \            upd.push_back(C[v]);\n        for (int x : cent[v]|views::keys)\n\
    \            dfs(dfs,x,upd);\n    };\n    vector dp(N,vector<long long>{1,0,0});\n\
    \    for (int v : cent[cent.root()]|views::keys) {\n        vector<int> upd;\n\
    \        dfs(dfs,v,upd);\n        ranges::sort(upd);\n        for (int i = 0,\
    \ j = 0 ; i < ssize(upd) ; i = j) {\n            while (j < ssize(upd) and upd[i]==upd[j])\n\
    \                j++;\n            dp[upd[i]][2]+=dp[upd[i]][1]*(j-i);\n     \
    \       dp[upd[i]][1]+=dp[upd[i]][0]*(j-i);\n        }\n    }\n    long long ans=0;\n\
    \    for (auto d : dp)\n        ans += d[2];\n    cout << ans << '\\n';\n#else\n\
    \    int a,b;\n    cin >> a >> b;\n    cout << a+b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Graph/Tree/TreeCenters.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc482_e.test.cpp
  requiredBy: []
  timestamp: '2026-11-01 20:19:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc482_e.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc482_e.test.cpp
- /verify/Test/AtCoder/abc482_e.test.cpp.html
title: Test/AtCoder/abc482_e.test.cpp
---
