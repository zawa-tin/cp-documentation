---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/SubtreesHash.hpp
    title: "\u6839\u4ED8\u304D\u6728\u306E\u5404\u90E8\u5206\u6728\u3092\u30CF\u30C3\
      \u30B7\u30E5\u5024\u306B\u5909\u63DB\u3057\u305F\u5217"
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
    PROBLEM: https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
    links:
    - https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
  bundledCode: "#line 1 \"Test/LC/rooted_tree_isomorphism_classification.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#line 2 \"Src/Graph/Tree/SubtreesHash.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Tree/SubtreesHash.hpp\"\n\n#include\
    \ <algorithm>\n#include <limits>\n#include <vector>\n#include <map>\n\nnamespace\
    \ zawa {\n\nclass SubtreesHasher {\npublic:\n\n    SubtreesHasher() = default;\n\
    \n    template <class G>\n    std::vector<usize> operator()(const G& g, usize\
    \ r = 0u) {\n        std::vector<usize> res(g.size());\n        auto dfs = [&](auto\
    \ dfs, usize v, usize p) -> usize {\n            std::vector<usize> ch;\n    \
    \        ch.reserve(g[v].size());\n            for (usize x : g[v]) if (x != p)\
    \ {\n                ch.push_back(dfs(dfs, x, v));\n            }\n          \
    \  std::sort(ch.begin(), ch.end());\n            return res[v] = mapping(std::move(ch));\n\
    \        };\n        dfs(dfs, r, std::numeric_limits<u32>::max());\n        return\
    \ res;\n    }\n\nprivate:\n\n    std::map<std::vector<usize>, usize> map;\n\n\
    \    usize mapping(std::vector<usize>&& A) {\n        usize cur = map.size();\n\
    \        return map.try_emplace(std::move(A), cur).first->second;\n    }\n};\n\
    \n} // namespace zawa\n#line 4 \"Test/LC/rooted_tree_isomorphism_classification.test.cpp\"\
    \n\n#line 6 \"Test/LC/rooted_tree_isomorphism_classification.test.cpp\"\n#include\
    \ <iostream>\n#line 8 \"Test/LC/rooted_tree_isomorphism_classification.test.cpp\"\
    \n\nusing namespace zawa;\n\nint main() {\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int N;\n    std::cin >> N;\n    std::vector<std::vector<int>>\
    \ g(N);\n    for (int i = 1 ; i < N ; i++) {\n        int p;\n        std::cin\
    \ >> p;\n        g[p].push_back(i);\n    }\n    auto ans = SubtreesHasher{}(g);\n\
    \    auto K = *std::max_element(ans.begin(), ans.end()) + 1;\n    std::cout <<\
    \ K << '\\n';\n    for (int i = 0 ; i < N ; i++) std::cout << ans[i] << (i + 1\
    \ == N ? '\\n' : ' ');\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#include \"../../Src/Graph/Tree/SubtreesHash.hpp\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <vector>\n\nusing namespace zawa;\n\nint main()\
    \ {\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int N;\n    std::cin >> N;\n    std::vector<std::vector<int>> g(N);\n   \
    \ for (int i = 1 ; i < N ; i++) {\n        int p;\n        std::cin >> p;\n  \
    \      g[p].push_back(i);\n    }\n    auto ans = SubtreesHasher{}(g);\n    auto\
    \ K = *std::max_element(ans.begin(), ans.end()) + 1;\n    std::cout << K << '\\\
    n';\n    for (int i = 0 ; i < N ; i++) std::cout << ans[i] << (i + 1 == N ? '\\\
    n' : ' ');\n}\n"
  dependsOn:
  - Src/Graph/Tree/SubtreesHash.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/LC/rooted_tree_isomorphism_classification.test.cpp
  requiredBy: []
  timestamp: '2025-04-09 18:54:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/rooted_tree_isomorphism_classification.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/rooted_tree_isomorphism_classification.test.cpp
- /verify/Test/LC/rooted_tree_isomorphism_classification.test.cpp.html
title: Test/LC/rooted_tree_isomorphism_classification.test.cpp
---
