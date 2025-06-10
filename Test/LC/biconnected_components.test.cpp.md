---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Components/BlockCutTree.hpp
    title: "Block-Cut tree (+ \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\
      \u89E3)"
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
    PROBLEM: https://judge.yosupo.jp/problem/biconnected_components
    links:
    - https://judge.yosupo.jp/problem/biconnected_components
  bundledCode: "#line 1 \"Test/LC/biconnected_components.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/biconnected_components\"\n\n#line 2 \"Src/Graph/Components/BlockCutTree.hpp\"\
    \n\n#include <cassert>\n#include <concepts>\n#include <vector>\n#include <optional>\n\
    \n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 9 \"Src/Graph/Components/BlockCutTree.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <std::integral T>\nclass BlockCutTree {\npublic:\n\
    \n    BlockCutTree() = default;\n\n    explicit BlockCutTree(const std::vector<std::vector<T>>&\
    \ g) : inv_(g.size()) {\n        const usize n = g.size();\n        std::vector<usize>\
    \ low(n), ord(n), vs;\n        usize time = 1;\n        const T INVALID = static_cast<T>(-1);\n\
    \        auto dfs = [&](auto dfs, T v, T p) -> void {\n            low[v] = ord[v]\
    \ = time++;\n            if (g[v].empty()) {\n                blocks_.push_back({T{v}});\n\
    \                return;\n            }\n            usize deg = 0;\n        \
    \    bool cut = false;\n            for (T x : g[v]) {\n                if (ord[x])\
    \ {\n                    low[v] = std::min(low[v], ord[x]);\n                }\n\
    \                else {\n                    deg++;\n                    dfs(dfs,\
    \ x, v);\n                    low[v] = std::min(low[v], low[x]);\n           \
    \         if (low[x] >= ord[v]) {\n                        std::vector<T> cur{v};\n\
    \                        cut |= p != INVALID;\n                        while (vs.size()\
    \ and ord[vs.back()] >= ord[x]) {\n                            cur.push_back(vs.back());\n\
    \                            vs.pop_back();\n                        }\n     \
    \                   blocks_.push_back(std::move(cur));\n                    }\n\
    \                }\n            }\n            cut |= p == INVALID and deg >=\
    \ 2;\n            if (cut) cuts_.push_back(v);\n            vs.push_back(v);\n\
    \        };\n        for (T i = 0 ; i < static_cast<T>(n) ; i++) if (!ord[i])\
    \ \n            dfs(dfs, i, INVALID);\n        const usize m = blocks_.size(),\
    \ k = cuts_.size();\n        for (usize i = 0 ; i < k ; i++) inv_[cuts_[i]] =\
    \ m + i;\n        g_.resize(m + k);\n        for (usize i = 0 ; i < m ; i++) {\n\
    \            for (T v : blocks_[i]) if (inv_[v] >= m) {\n                g_[i].push_back(inv_[v]);\n\
    \                g_[inv_[v]].push_back(i);\n            }\n        }\n    }\n\n\
    \    inline usize size() const noexcept {\n        return g_.size();\n    }\n\n\
    \    const std::vector<T>& operator[](usize i) const {\n        assert(i < size());\n\
    \        return g_[i];\n    }\n\n    enum class Type {\n        BLOCK,\n     \
    \   CUT\n    };\n\n    Type type(usize i) const {\n        assert(i < size());\n\
    \        return i < blocks_.size() ? Type::BLOCK : Type::CUT;\n    }\n\n    const\
    \ std::vector<std::vector<T>>& blocks() const {\n        return blocks_;\n   \
    \ }\n\n    const std::vector<T>& block(usize i) const {\n        assert(i < size()\
    \ and type(i) == Type::BLOCK);\n        return blocks_[i];\n    }\n\n    const\
    \ std::vector<T>& cuts() const {\n        return cuts_;\n    }\n\n    const T\
    \ cut(usize i) const {\n        assert(i < size() and type(i) == Type::CUT);\n\
    \        return cuts_[i - blocks_.size()];\n    }\n\n    std::vector<T> vertices(usize\
    \ i) const {\n        assert(i < size());\n        return i < blocks_.size() ?\
    \ \n            blocks_[i] : std::vector<T>{cuts_[i - blocks_.size()]};\n    }\n\
    \n    bool isCut(T v) const {\n        assert(v < static_cast<T>(inv_.size()));\n\
    \        return inv_[v] >= blocks_.size();\n    }\n\n    std::optional<usize>\
    \ cutId(usize i) const {\n        assert(i < size());\n        return isCut(i)\
    \ ? std::optional<usize>{inv_[i]} : std::nullopt;\n    }\n\nprivate:\n\n    std::vector<std::vector<T>>\
    \ blocks_;\n\n    std::vector<T> cuts_;\n\n    std::vector<std::vector<T>> g_;\n\
    \n    std::vector<usize> inv_;\n};\n\n} // namespace zawa\n#line 4 \"Test/LC/biconnected_components.test.cpp\"\
    \nusing namespace zawa;\n\n#include <iostream>\n#line 8 \"Test/LC/biconnected_components.test.cpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n  \
    \  std::ios::sync_with_stdio(false);\n    int N, M;\n    std::cin >> N >> M;\n\
    \    std::vector<std::vector<int>> g(N);\n    for (int i = 0 ; i < M ; i++) {\n\
    \        int u, v;\n        std::cin >> u >> v;\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n    BlockCutTree bct{g};\n    auto& ans =\
    \ bct.blocks();\n    std::cout << ans.size() << '\\n';\n    for (const std::vector<int>&\
    \ blk : ans) {\n        std::cout << blk.size();\n        for (int v : blk) std::cout\
    \ << ' ' << v;\n        std::cout << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\
    \n\n#include \"../../Src/Graph/Components/BlockCutTree.hpp\"\nusing namespace\
    \ zawa;\n\n#include <iostream>\n#include <vector>\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int N,\
    \ M;\n    std::cin >> N >> M;\n    std::vector<std::vector<int>> g(N);\n    for\
    \ (int i = 0 ; i < M ; i++) {\n        int u, v;\n        std::cin >> u >> v;\n\
    \        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n    BlockCutTree\
    \ bct{g};\n    auto& ans = bct.blocks();\n    std::cout << ans.size() << '\\n';\n\
    \    for (const std::vector<int>& blk : ans) {\n        std::cout << blk.size();\n\
    \        for (int v : blk) std::cout << ' ' << v;\n        std::cout << '\\n';\n\
    \    }\n}\n"
  dependsOn:
  - Src/Graph/Components/BlockCutTree.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/LC/biconnected_components.test.cpp
  requiredBy: []
  timestamp: '2025-06-10 18:57:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/biconnected_components.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/biconnected_components.test.cpp
- /verify/Test/LC/biconnected_components.test.cpp.html
title: Test/LC/biconnected_components.test.cpp
---
