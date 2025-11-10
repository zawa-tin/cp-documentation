---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Src/Random/RandomBalancedParenthesis.hpp
    title: Src/Random/RandomBalancedParenthesis.hpp
  - icon: ':warning:'
    path: Src/Random/RandomDistinctArray.hpp
    title: Src/Random/RandomDistinctArray.hpp
  - icon: ':warning:'
    path: Src/Random/RandomPermutation.hpp
    title: Src/Random/RandomPermutation.hpp
  - icon: ':warning:'
    path: Src/Random/RandomTree.hpp
    title: Src/Random/RandomTree.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Random/RandomConnectedGraph.hpp\"\n\n#line 2 \"Src/Random/RandomTree.hpp\"\
    \n\n#line 2 \"Src/Random/RandomPermutation.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Random/RandomPermutation.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <concepts>\n#include <numeric>\n#include\
    \ <vector>\n#include <random>\n\nnamespace zawa {\n\nnamespace Random {\n\n//\
    \ [0 .. n)\ntemplate <std::integral T>\nstd::vector<T> Permutation(usize n) {\n\
    \    std::mt19937_64 mt{std::random_device{}()};\n    std::vector<T> res(n);\n\
    \    std::iota(res.begin(), res.end(), T{0});\n    std::ranges::shuffle(res, mt);\n\
    \    return res;\n}\n\n} // namespace Random\n\n} // namespace zawa\n#line 2 \"\
    Src/Random/RandomBalancedParenthesis.hpp\"\n\n#line 2 \"Src/Random/RandomDistinctArray.hpp\"\
    \n\n#line 4 \"Src/Random/RandomDistinctArray.hpp\"\n\n#line 10 \"Src/Random/RandomDistinctArray.hpp\"\
    \n#include <unordered_map>\n#include <unordered_set>\n\n#include <iostream>\n\n\
    namespace zawa {\n\nnamespace Random {\n\ntemplate <std::integral T>\nstd::vector<T>\
    \ DistinctArray(usize n, T min, T max, bool verify = true) {\n    assert(min <=\
    \ max);\n    assert(n <= static_cast<usize>(max - min + 1));\n    std::mt19937_64\
    \ mt{std::random_device{}()};\n    std::vector<T> res(n);\n    std::unordered_map<T,\
    \ T> mp;\n    for (T& v : res) {\n        T val = static_cast<T>(mt() % (max -\
    \ min + 1)) + min;\n        T replace = [&]() {\n            auto it = mp.find(max);\n\
    \            return it == mp.end() ? max : it->second;\n        }();\n       \
    \ auto it = mp.find(val);\n        if (it == mp.end()) {\n            v = val;\n\
    \            mp[val] = replace;\n        }\n        else {\n            v = it->second;\n\
    \            it->second = replace;\n        }\n        max--;\n    }\n    if (verify)\
    \ {\n        assert(std::ranges::all_of(res, [&](T v) { return min <= v and v\
    \ <= static_cast<T>(max + n); }));\n        assert(std::unordered_set<T>(res.begin(),\
    \ res.end()).size() == n);\n    }\n    return res;\n}\n\n} // namespace Random\n\
    \n} // namespace zawa\n#line 4 \"Src/Random/RandomBalancedParenthesis.hpp\"\n\n\
    #line 9 \"Src/Random/RandomBalancedParenthesis.hpp\"\n#include <string>\n\nnamespace\
    \ zawa {\n\nnamespace Random {\n\n// https://codeforces.com/blog/entry/103245\n\
    std::string BalancedParenthesis(usize n, bool verify = true) {\n    if (n == 0)\n\
    \        return \"\";\n    auto left = DistinctArray<usize>(n, 0, 2 * n, verify);\n\
    \    std::string gen(2 * n + 1, ')');\n    for (usize i : left)\n        gen[i]\
    \ = '(';\n    std::vector<i32> pref(gen.size());\n    pref[0] = gen[0] == '('\
    \ ? +1 : -1;\n    for (usize i = 1 ; i < pref.size() ; i++)\n        pref[i] =\
    \ pref[i - 1] + (gen[i] == '(' ? +1 : -1);\n    auto sp = std::ranges::min_element(pref)\
    \ - pref.begin();\n    std::string res(2 * n, '(');\n    for (usize i = 0 ; i\
    \ < 2 * n ; i++)\n        res[i] = gen[(sp + 1 + i) % gen.size()];\n    if (verify)\
    \ {\n        i32 bal = 0;\n        for (u8 c : res) {\n            assert(c ==\
    \ '(' or c == ')');\n            bal += c == '(' ? +1 : -1;\n            assert(bal\
    \ >= 0);\n        }\n        assert(bal == 0);\n    }\n    return res;\n}\n\n\
    } // namespace Random\n\n} // namespace zawa\n#line 5 \"Src/Random/RandomTree.hpp\"\
    \n\n#line 8 \"Src/Random/RandomTree.hpp\"\n#include <utility>\n#line 12 \"Src/Random/RandomTree.hpp\"\
    \n\nnamespace zawa {\n\nnamespace Random {\n\ntemplate <std::integral T>\nstd::vector<std::pair<T,\
    \ T>> Tree(usize n, bool verify = true) {\n    if (n == 0)\n        return {};\n\
    \    const std::string gen = BalancedParenthesis(n - 1, verify);\n    std::vector<T>\
    \ stk{0};\n    usize cur = 1;\n    std::vector<std::pair<T, T>> res;\n    for\
    \ (u8 c : gen) {\n        if (c == '(') {\n            const usize v = cur++;\n\
    \            res.push_back({stk.back(), v});\n            stk.push_back(v);\n\
    \        }\n        else {\n            stk.pop_back();\n        }\n    }\n  \
    \  auto perm = Permutation<usize>(n);\n    for (auto& [u, v] : res) {\n      \
    \  u = perm[u];\n        v = perm[v];\n    }\n    if (verify) {\n        assert(res.size()\
    \ == n - 1);\n        std::vector<bool> vis(n);\n        std::vector<std::vector<T>>\
    \ g(n);\n        for (auto [u, v] : res) {\n            g[u].push_back(v);\n \
    \           g[v].push_back(u);\n        }\n        std::vector<std::pair<T, T>>\
    \ que{std::pair{0, n + 1}};\n        for (usize t = 0 ; t < que.size() ; t++)\
    \ {\n            auto [v, p] = que[t];\n            for (T x : g[v])\n       \
    \         if (x != p) {\n                    assert(!vis[x]);\n              \
    \      vis[x] = 1;\n                    que.push_back({x, v});\n             \
    \   }\n        } \n    }\n    return res;\n}\n\n} // namespace Random\n\n} //\
    \ namespace zawa\n#line 4 \"Src/Random/RandomConnectedGraph.hpp\"\n\n#line 11\
    \ \"Src/Random/RandomConnectedGraph.hpp\"\n#include <set>\n\nnamespace zawa {\n\
    \nnamespace Random {\n\ntemplate <std::integral T>\nstd::vector<std::pair<T, T>>\
    \ ConnectedGraph(usize n, usize m, bool verify = true) {\n    if (n == 0)\n  \
    \      return {};\n    assert(n - 1 <= m and (u64)m <= (u64)n * (n - 1) / 2);\n\
    \    std::vector<std::pair<T, T>> res = Tree<T>(n, verify);\n    std::set<std::pair<T,\
    \ T>> st;\n    for (auto [u, v] : res)\n        st.insert(std::minmax({u, v}));\n\
    \    std::mt19937 mt{std::random_device{}()};\n    while (res.size() < m) {\n\
    \        T u = mt() % n, v = mt() % n;\n        if (u == v)\n            continue;\n\
    \        if (st.contains(std::minmax({u, v})))\n            continue;\n      \
    \  st.insert(std::minmax({u, v}));\n        res.push_back({u, v});\n    }\n  \
    \  if (verify) {\n        std::set<std::pair<T, T>> used;\n        for (auto [u,\
    \ v] : res) {\n            assert(0 <= u and u < static_cast<T>(n));\n       \
    \     assert(0 <= v and v < static_cast<T>(n));\n            assert(u != v);\n\
    \            used.insert(std::minmax({u, v}));\n        }\n        assert(used.size()\
    \ == m);\n    }\n    return res;\n}\n\n} // namespace Random\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include \"./RandomTree.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <concepts>\n#include <utility>\n#include <vector>\n#include\
    \ <random>\n#include <set>\n\nnamespace zawa {\n\nnamespace Random {\n\ntemplate\
    \ <std::integral T>\nstd::vector<std::pair<T, T>> ConnectedGraph(usize n, usize\
    \ m, bool verify = true) {\n    if (n == 0)\n        return {};\n    assert(n\
    \ - 1 <= m and (u64)m <= (u64)n * (n - 1) / 2);\n    std::vector<std::pair<T,\
    \ T>> res = Tree<T>(n, verify);\n    std::set<std::pair<T, T>> st;\n    for (auto\
    \ [u, v] : res)\n        st.insert(std::minmax({u, v}));\n    std::mt19937 mt{std::random_device{}()};\n\
    \    while (res.size() < m) {\n        T u = mt() % n, v = mt() % n;\n       \
    \ if (u == v)\n            continue;\n        if (st.contains(std::minmax({u,\
    \ v})))\n            continue;\n        st.insert(std::minmax({u, v}));\n    \
    \    res.push_back({u, v});\n    }\n    if (verify) {\n        std::set<std::pair<T,\
    \ T>> used;\n        for (auto [u, v] : res) {\n            assert(0 <= u and\
    \ u < static_cast<T>(n));\n            assert(0 <= v and v < static_cast<T>(n));\n\
    \            assert(u != v);\n            used.insert(std::minmax({u, v}));\n\
    \        }\n        assert(used.size() == m);\n    }\n    return res;\n}\n\n}\
    \ // namespace Random\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Random/RandomTree.hpp
  - Src/Random/RandomPermutation.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Random/RandomBalancedParenthesis.hpp
  - Src/Random/RandomDistinctArray.hpp
  isVerificationFile: false
  path: Src/Random/RandomConnectedGraph.hpp
  requiredBy: []
  timestamp: '2025-11-10 22:14:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Src/Random/RandomConnectedGraph.hpp
layout: document
redirect_from:
- /library/Src/Random/RandomConnectedGraph.hpp
- /library/Src/Random/RandomConnectedGraph.hpp.html
title: Src/Random/RandomConnectedGraph.hpp
---
