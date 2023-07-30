---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Components/ConnectedComponents.hpp
    title: "\u7121\u5411\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':question:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc293/tasks/abc293_d
    links:
    - https://atcoder.jp/contests/abc293/tasks/abc293_d
  bundledCode: "#line 1 \"Test/AtCoder/abc293_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc293/tasks/abc293_d\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Graph/Components/ConnectedComponents.hpp\"\
    \n\n#line 4 \"Src/Graph/Components/ConnectedComponents.hpp\"\n\n#include <limits>\n\
    #include <vector>\n#include <utility>\n#include <stack>\n#include <algorithm>\n\
    #include <cassert>\n\nnamespace zawa {\n\nclass ConnectedComponents {\npublic:\n\
    \    struct Edge {\n    private:\n        u32 u_, v_, id_;\n    public:\n    \
    \    Edge(u32 u, u32 v, u32 id) : u_{ u }, v_{ v }, id_{ id } {}\n\n        inline\
    \ u32 u() const noexcept {\n            return u_;\n        }\n        inline\
    \ u32 v() const noexcept {\n            return v_;\n        }\n        inline\
    \ u32 id() const noexcept {\n            return id_;\n        }\n    };\n\nprivate:\n\
    \    class Component {\n    private:\n        std::vector<u32> vs_, es_;\n   \
    \ public:\n        Component() = default;\n        Component(const std::vector<u32>&\
    \ vs, const std::vector<u32>& es) : vs_{ vs }, es_{ es } {\n            vs_.shrink_to_fit();\n\
    \            es_.shrink_to_fit();\n        }\n        \n        inline usize n()\
    \ const noexcept {\n            return vs_.size();\n        }\n        inline\
    \ usize m() const noexcept {\n            return es_.size();\n        }\n    \
    \    const std::vector<u32>& vs() const noexcept {\n            return vs_;\n\
    \        }\n        const std::vector<u32>& es() const noexcept {\n          \
    \  return es_;\n        }\n        bool hasCycle() const {\n            return\
    \ not (n() == m() + 1);\n        }\n    };\n\n    constexpr static u32 INVALID_{\
    \ std::numeric_limits<u32>::max() };\n\n    std::vector<std::vector<u32>> graph_;\n\
    \    std::vector<std::pair<u32, u32>> edges_;\n\n    std::vector<u32> indexV_,\
    \ indexE_;\n    std::vector<Component> components_;\n\n    bool isBuilt;\n\n \
    \   void dfs(u32 s) {\n        indexV_[s] = components_.size();\n        std::stack<u32>\
    \ stk{ { s } };\n        while (stk.size()) {\n            u32 v{ stk.top() };\n\
    \            stk.pop();\n            for (auto x : graph_[v]) {\n            \
    \    if (indexV_[x] == INVALID_) {\n                    indexV_[x] = components_.size();\n\
    \                    stk.push(x);\n                }\n            }\n        }\n\
    \    }\n\n    void buildComponents() {\n        std::vector<std::vector<u32>>\
    \ vs(components_.size()), es(components_.size());\n        for (u32 v{} ; v <\
    \ n() ; v++) {\n            vs[indexV_[v]].emplace_back(v);\n        }\n     \
    \   for (u32 e{} ; e < m() ; e++) {\n            es[indexE_[e]].emplace_back(e);\n\
    \        }\n        for (u32 i{} ; i < components_.size() ; i++) {\n         \
    \   components_[i] = Component(vs[i], es[i]);\n        }\n        components_.shrink_to_fit();\n\
    \    }\n\npublic:\n    ConnectedComponents() = default;\n\n    ConnectedComponents(usize\
    \ n) \n        : graph_(n), edges_{}, indexV_(n, INVALID_), indexE_{}, components_{},\
    \ isBuilt{} {\n        graph_.shrink_to_fit();\n    }\n    \n    void addEdge(u32\
    \ u, u32 v) {\n        assert(not isBuilt);\n        graph_[u].emplace_back(v);\n\
    \        graph_[v].emplace_back(u);\n        edges_.emplace_back(u, v);\n    }\n\
    \n    inline usize n() const noexcept {\n        return graph_.size();\n    }\n\
    \n    inline usize m() const noexcept {\n        return edges_.size();\n    }\n\
    \n    Edge edge(u32 e) const {\n        assert(e < m());\n        return Edge{\
    \ edges_[e].first, edges_[e].second, e };\n    }\n\n    void build() {\n     \
    \   assert(not isBuilt);\n        edges_.shrink_to_fit();\n        indexV_.shrink_to_fit();\n\
    \        for (u32 v{} ; v < n() ; v++) {\n            if (indexV_[v] == INVALID_)\
    \ {\n                dfs(v);\n                components_.emplace_back();\n  \
    \          }\n        }\n        indexE_.resize(m());\n        indexE_.shrink_to_fit();\n\
    \        for (u32 e{} ; e < m() ; e++) {\n            indexE_[e] = indexV_[edges_[e].first];\n\
    \        }\n        buildComponents();\n        isBuilt = true;\n    }\n\n   \
    \ inline u32 operator[](const u32 v) const noexcept {\n        assert(isBuilt);\n\
    \        assert(v < n());\n        return indexV_[v];\n    }\n\n    inline u32\
    \ indexV(u32 v) const noexcept {\n        assert(isBuilt);\n        assert(v <\
    \ n());\n        return indexV_[v];\n    }\n\n    inline u32 indexE(u32 e) const\
    \ noexcept {\n        assert(isBuilt);\n        assert(e < m());\n        return\
    \ indexE_[e];\n    }\n\n    inline bool same(u32 u, u32 v) const noexcept {\n\
    \        assert(isBuilt);\n        assert(u < n());\n        assert(v < n());\n\
    \        return indexV_[u] == indexV_[v];\n    }\n\n    inline usize size() const\
    \ noexcept {\n        assert(isBuilt);\n        return components_.size();\n \
    \   }\n\n    inline usize n(u32 c) const noexcept {\n        assert(isBuilt);\n\
    \        assert(c < size());\n        return components_[c].n();\n    }\n\n  \
    \  inline const std::vector<u32>& vs(u32 c) const noexcept {\n        assert(isBuilt);\n\
    \        assert(c < size());\n        return components_[c].vs();\n    }\n\n \
    \   inline usize m(u32 c) const noexcept {\n        assert(isBuilt);\n       \
    \ assert(c < size());\n        return components_[c].m();\n    }\n\n    inline\
    \ const std::vector<u32>& es(u32 c) const noexcept {\n        assert(isBuilt);\n\
    \        assert(c < size());\n        return components_[c].es();\n    }\n\n \
    \   inline bool hasCycle(u32 c) const {\n        assert(isBuilt);\n        assert(c\
    \ < size());\n        return components_[c].hasCycle();\n    }\n\n};\n\n} // namespace\
    \ zawa\n#line 5 \"Test/AtCoder/abc293_d.test.cpp\"\n\n#include <iostream>\n\n\
    using namespace zawa;\n\nint main() {\n    u32 N, M;\n    std::cin >> N >> M;\n\
    \n    ConnectedComponents cc(N);\n    for (u32 _{} ; _ < M ; _++) {\n        u32\
    \ A, C;\n        u8 B, D;\n        std::cin >> A >> B >> C >> D;\n        cc.addEdge(A\
    \ - 1, C - 1);\n    }\n\n    cc.build();\n\n    u32 X{}, Y{};\n    for (u32 i{}\
    \ ; i < cc.size() ; i++) {\n        if (cc.hasCycle(i)) {\n            X++;\n\
    \        }\n        else {\n            Y++;\n        }\n    }\n\n    std::cout\
    \ << X << ' ' << Y << std::endl;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc293/tasks/abc293_d\"\n\n\
    #include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Graph/Components/ConnectedComponents.hpp\"\
    \n\n#include <iostream>\n\nusing namespace zawa;\n\nint main() {\n    u32 N, M;\n\
    \    std::cin >> N >> M;\n\n    ConnectedComponents cc(N);\n    for (u32 _{} ;\
    \ _ < M ; _++) {\n        u32 A, C;\n        u8 B, D;\n        std::cin >> A >>\
    \ B >> C >> D;\n        cc.addEdge(A - 1, C - 1);\n    }\n\n    cc.build();\n\n\
    \    u32 X{}, Y{};\n    for (u32 i{} ; i < cc.size() ; i++) {\n        if (cc.hasCycle(i))\
    \ {\n            X++;\n        }\n        else {\n            Y++;\n        }\n\
    \    }\n\n    std::cout << X << ' ' << Y << std::endl;\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Components/ConnectedComponents.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc293_d.test.cpp
  requiredBy: []
  timestamp: '2023-07-19 15:15:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc293_d.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc293_d.test.cpp
- /verify/Test/AtCoder/abc293_d.test.cpp.html
title: Test/AtCoder/abc293_d.test.cpp
---
