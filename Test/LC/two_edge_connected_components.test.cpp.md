---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Components/BridgeTree.hpp
    title: "Bridge tree (+ \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3)"
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
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"Test/LC/two_edge_connected_components.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n\n\
    #line 2 \"Src/Graph/Components/BridgeTree.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Components/BridgeTree.hpp\"\n\n#include\
    \ <concepts>\n#include <vector>\n#include <unordered_map>\n\nnamespace zawa {\n\
    \ntemplate <std::integral T>\nclass BridgeTree {\npublic:\n\n    using V = usize;\n\
    \n    BridgeTree() = default;\n\n    explicit BridgeTree(const std::vector<std::vector<T>>&\
    \ g) : m_id(g.size()) {\n        const usize n = g.size();\n        std::vector<usize>\
    \ low(n), ord(n);\n        std::vector<T> vs;\n        std::vector<std::pair<T,\
    \ T>> bridge;\n        usize time = 1, id = 0;\n        auto dfs = [&](auto dfs,\
    \ T v, T p) -> void {\n            low[v] = ord[v] = time++;\n            std::unordered_map<T,\
    \ usize> cnt;\n            for (T x : g[v]) cnt[x]++;\n            for (auto [x,\
    \ c] : cnt) if (x != p) {\n                if (ord[x]) {\n                   \
    \ low[v] = std::min(low[v], ord[x]);\n                }\n                else\
    \ {\n                    dfs(dfs, x, v);\n                    low[v] = std::min(low[v],\
    \ low[x]);\n                    if (c == 1u and ord[v] < low[x]) {\n         \
    \               std::vector<T> cur; \n                        while (vs.size()\
    \ and low[x] <= low[vs.back()]) {\n                            cur.push_back(vs.back());\n\
    \                            m_id[vs.back()] = m_comp.size();\n              \
    \              vs.pop_back();\n                        }\n                   \
    \     bridge.emplace_back(x, v);\n                        m_comp.push_back(std::move(cur));\n\
    \                    }\n                }\n            }\n            vs.push_back(v);\n\
    \        };\n        for (usize v = 0 ; v < n ; v++) if (!ord[v]) {\n        \
    \    dfs(dfs, v, static_cast<T>(-1));\n            if (vs.size()) {\n        \
    \        std::vector<T> cur;\n                while (vs.size()) {\n          \
    \          m_id[vs.back()] = m_comp.size();\n                    cur.push_back(vs.back());\n\
    \                    vs.pop_back();\n                }\n                m_comp.push_back(std::move(cur));\n\
    \            }\n        }\n        m_g.resize(m_comp.size());\n        for (auto\
    \ [u, v] : bridge) {\n            const V p = m_id[u], q = m_id[v];\n        \
    \    m_g[p].push_back(q);\n            m_g[q].push_back(p);\n        }\n    }\n\
    \n    inline usize size() const noexcept {\n        return m_g.size();\n    }\n\
    \n    const std::vector<V>& operator[](V v) const {\n        assert(v < size());\n\
    \        return m_g[v];\n    }\n\n    const std::vector<std::vector<T>>& components()\
    \ const {\n        return m_comp;\n    }\n\n    const std::vector<T>& component(V\
    \ v) const {\n        assert(v < size());\n        return m_comp[v];\n    }\n\n\
    private:\n\n    std::vector<V> m_id;\n\n    std::vector<std::vector<T>> m_comp;\n\
    \n    std::vector<std::vector<V>> m_g;\n};\n\n} // namespace zawa\n#line 4 \"\
    Test/LC/two_edge_connected_components.test.cpp\"\nusing namespace zawa;\n\n#include\
    \ <iostream>\n#line 8 \"Test/LC/two_edge_connected_components.test.cpp\"\n\nint\
    \ main() {\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int N, M;\n    std::cin >> N >> M;\n    std::vector<std::vector<int>> g(N);\n\
    \    for (int i = 0 ; i < M ; i++) {\n        int u, v;\n        std::cin >> u\
    \ >> v;\n        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n    BridgeTree\
    \ bt(g);\n    auto& ans = bt.components();\n    std::cout << ans.size() << '\\\
    n';\n    for (const std::vector<int>& comp : ans) {\n        std::cout << comp.size();\n\
    \        for (int v : comp) std::cout << ' ' << v;\n        std::cout << '\\n';\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include \"../../Src/Graph/Components/BridgeTree.hpp\"\nusing namespace zawa;\n\
    \n#include <iostream>\n#include <vector>\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int N,\
    \ M;\n    std::cin >> N >> M;\n    std::vector<std::vector<int>> g(N);\n    for\
    \ (int i = 0 ; i < M ; i++) {\n        int u, v;\n        std::cin >> u >> v;\n\
    \        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n    BridgeTree\
    \ bt(g);\n    auto& ans = bt.components();\n    std::cout << ans.size() << '\\\
    n';\n    for (const std::vector<int>& comp : ans) {\n        std::cout << comp.size();\n\
    \        for (int v : comp) std::cout << ' ' << v;\n        std::cout << '\\n';\n\
    \    }\n}\n"
  dependsOn:
  - Src/Graph/Components/BridgeTree.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/LC/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2025-06-12 16:53:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/two_edge_connected_components.test.cpp
- /verify/Test/LC/two_edge_connected_components.test.cpp.html
title: Test/LC/two_edge_connected_components.test.cpp
---
