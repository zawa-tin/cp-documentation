---
data:
  _extendedDependsOn:
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
    - https://atcoder.jp/contests/arc179/submissions/80190724
    - https://atcoder.jp/contests/arc179/tasks/arc179_d
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/AtCoder/arc179_d.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/arc179/tasks/arc179_d\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n/*\n * AtCoder Regular Contest 179 D - Portable Gate \n * https://atcoder.jp/contests/arc179/submissions/80190724\n\
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
    #line 8 \"Test/AtCoder/arc179_d.test.cpp\"\n#include <algorithm>\n#include <array>\n\
    #include <iostream>\n#include <utility>\n#line 13 \"Test/AtCoder/arc179_d.test.cpp\"\
    \nusing namespace std;\nusing namespace zawa;\nstruct Item {\n    array<int,2>\
    \ aru{0,0}; // \u6839\u306B\u30B2\u30FC\u30C8\u304C\u3042\u308B\u72B6\u614B\u3067\
    \u306E\u6700\u5C0F\u30B3\u30B9\u30C8\n    int ed=0; // \u8FBA\u6570\n    int far=0;\
    \ // \u6700\u9060\u70B9\u307E\u3067\u306E\u8DDD\u96E2\n    int nai() const { //\
    \ \u6839\u306B\u30B2\u30FC\u30C8\u304C\u306A\u3044\u72B6\u614B\u3067\u306E\u6700\
    \u5C0F\u30B3\u30B9\u30C8\n        return 2*ed-far;\n    }\n};\nstruct DP {\n \
    \   using Tree = Item;\n    using Cluster = Item;\n    using Edge = struct {};\n\
    \    using Vertex = struct {};\n    static Tree Convert(Vertex) {\n        return\
    \ {array<int,2>{0,0},0,0};\n    }\n    static Cluster AddEdge(Tree t,Edge) {\n\
    \        int ed=t.ed+1;\n        int far=t.far+1;\n        array<int,2> aru{min(t.aru[0]+2,t.nai()+1),min(t.aru[1]+1,t.nai()+1)};\n\
    \        return {aru,ed,far};\n    }\n    static Cluster Merge(Cluster l,Cluster\
    \ r) {\n        int ed=l.ed+r.ed;\n        int far=max(l.far,r.far);\n       \
    \ array<int,2> aru{l.aru[0]+r.aru[0],min(l.aru[0]+r.aru[1],l.aru[1]+r.aru[0])};\n\
    \        return {aru,ed,far};\n    }\n    static Tree AddVertex(Cluster c,Vertex)\
    \ {\n        return c;\n    }\n};\nint main() {\n#ifdef ATCODER\n    int N;\n\
    \    cin >> N;\n    vector<pair<int,int>> E(N-1);\n    for (auto& [u,v] : E) {\n\
    \        cin >> u >> v;\n        u--; v--;\n    }\n    Rerooting<DP,int> dp(N,E,vector<DP::Vertex>(N),vector<DP::Edge>(N-1));\n\
    \    int ans=(int)1e9;\n    for (int i = 0 ; i < N ; i++)\n        ans=min(ans,dp[i].aru[1]);\n\
    \    cout << ans << '\\n';\n#else\n    int a,b;\n    cin >> a >> b;\n    cout\
    \ << a+b << '\\n';\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/arc179/tasks/arc179_d\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n/*\n * AtCoder Regular\
    \ Contest 179 D - Portable Gate \n * https://atcoder.jp/contests/arc179/submissions/80190724\n\
    \ */\n#include \"../../Src/Graph/Tree/Rerooting.hpp\"\n#include <algorithm>\n\
    #include <array>\n#include <iostream>\n#include <utility>\n#include <vector>\n\
    using namespace std;\nusing namespace zawa;\nstruct Item {\n    array<int,2> aru{0,0};\
    \ // \u6839\u306B\u30B2\u30FC\u30C8\u304C\u3042\u308B\u72B6\u614B\u3067\u306E\u6700\
    \u5C0F\u30B3\u30B9\u30C8\n    int ed=0; // \u8FBA\u6570\n    int far=0; // \u6700\
    \u9060\u70B9\u307E\u3067\u306E\u8DDD\u96E2\n    int nai() const { // \u6839\u306B\
    \u30B2\u30FC\u30C8\u304C\u306A\u3044\u72B6\u614B\u3067\u306E\u6700\u5C0F\u30B3\
    \u30B9\u30C8\n        return 2*ed-far;\n    }\n};\nstruct DP {\n    using Tree\
    \ = Item;\n    using Cluster = Item;\n    using Edge = struct {};\n    using Vertex\
    \ = struct {};\n    static Tree Convert(Vertex) {\n        return {array<int,2>{0,0},0,0};\n\
    \    }\n    static Cluster AddEdge(Tree t,Edge) {\n        int ed=t.ed+1;\n  \
    \      int far=t.far+1;\n        array<int,2> aru{min(t.aru[0]+2,t.nai()+1),min(t.aru[1]+1,t.nai()+1)};\n\
    \        return {aru,ed,far};\n    }\n    static Cluster Merge(Cluster l,Cluster\
    \ r) {\n        int ed=l.ed+r.ed;\n        int far=max(l.far,r.far);\n       \
    \ array<int,2> aru{l.aru[0]+r.aru[0],min(l.aru[0]+r.aru[1],l.aru[1]+r.aru[0])};\n\
    \        return {aru,ed,far};\n    }\n    static Tree AddVertex(Cluster c,Vertex)\
    \ {\n        return c;\n    }\n};\nint main() {\n#ifdef ATCODER\n    int N;\n\
    \    cin >> N;\n    vector<pair<int,int>> E(N-1);\n    for (auto& [u,v] : E) {\n\
    \        cin >> u >> v;\n        u--; v--;\n    }\n    Rerooting<DP,int> dp(N,E,vector<DP::Vertex>(N),vector<DP::Edge>(N-1));\n\
    \    int ans=(int)1e9;\n    for (int i = 0 ; i < N ; i++)\n        ans=min(ans,dp[i].aru[1]);\n\
    \    cout << ans << '\\n';\n#else\n    int a,b;\n    cin >> a >> b;\n    cout\
    \ << a+b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Graph/Tree/Rerooting.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/arc179_d.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 15:41:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/arc179_d.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/arc179_d.test.cpp
- /verify/Test/AtCoder/arc179_d.test.cpp.html
title: Test/AtCoder/arc179_d.test.cpp
---
