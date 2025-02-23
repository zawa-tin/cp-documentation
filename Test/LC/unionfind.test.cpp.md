---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
    title: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"Test/LC/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Template/IOSetting.hpp\"\
    \n\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n#include <iomanip>\n\
    \nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\
    \n\n#line 4 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <numeric>\n#include <vector>\n\nnamespace\
    \ zawa {\n\nclass DisjointSetUnion {\npublic:\n    DisjointSetUnion() = default;\n\
    \n    DisjointSetUnion(usize n) : n_{n}, comps_{n}, data_(n, -1) {\n        data_.shrink_to_fit();\n\
    \    }\n    \n    u32 leader(u32 v) {\n        return data_[v] < 0 ? v : static_cast<u32>(data_[v]\
    \ = leader(data_[v]));\n    }\n\n    bool same(u32 u, u32 v) {\n        return\
    \ leader(u) == leader(v);\n    }\n\n    bool merge(u32 u, u32 v) {\n        assert(u\
    \ < n_);\n        assert(v < n_);\n        u = leader(u);\n        v = leader(v);\n\
    \        if (u == v) return false;\n        comps_--;\n        if (data_[u] >\
    \ data_[v]) std::swap(u, v);\n        data_[u] += data_[v];\n        data_[v]\
    \ = u;\n        return true;\n    }\n\n    inline usize size() const noexcept\
    \ {\n        return n_;\n    }\n\n    usize size(u32 v) {\n        assert(v <\
    \ n_);\n        return static_cast<usize>(-data_[leader(v)]);\n    }\n\n    inline\
    \ usize components() const noexcept {\n        return comps_;\n    }\n\n    std::vector<std::vector<u32>>\
    \ enumerate() {\n        std::vector<std::vector<u32>> res(n_);\n        for (u32\
    \ v{} ; v < n_ ; v++) {\n            res[leader(v)].push_back(v);\n        }\n\
    \        res.erase(std::remove_if(res.begin(), res.end(),\n                  \
    \  [](const auto& arr) -> bool { return arr.empty(); }), res.end());\n       \
    \ return res;\n    }\n\nprivate:\n    usize n_{}, comps_{};\n    std::vector<i32>\
    \ data_;\n};\n\n} // namespace zawa\n#line 6 \"Test/LC/unionfind.test.cpp\"\n\n\
    #line 8 \"Test/LC/unionfind.test.cpp\"\n\nint main() {\n    using namespace zawa;\n\
    \    SetFastIO();\n    u32 n, q; std::cin >> n >> q;\n    DisjointSetUnion dsu(n);\n\
    \    for (u32 _{} ; _ < q ; _++) {\n        u32 t, u, v; std::cin >> t >> u >>\
    \ v;\n        if (t == 0) {\n            dsu.merge(u, v);\n        }\n       \
    \ else {\n            std::cout << dsu.same(u, v) << '\\n';\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Template/IOSetting.hpp\"\
    \n#include \"../../Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\n\
    \n#include <iostream>\n\nint main() {\n    using namespace zawa;\n    SetFastIO();\n\
    \    u32 n, q; std::cin >> n >> q;\n    DisjointSetUnion dsu(n);\n    for (u32\
    \ _{} ; _ < q ; _++) {\n        u32 t, u, v; std::cin >> t >> u >> v;\n      \
    \  if (t == 0) {\n            dsu.merge(u, v);\n        }\n        else {\n  \
    \          std::cout << dsu.same(u, v) << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Template/IOSetting.hpp
  - Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
  isVerificationFile: true
  path: Test/LC/unionfind.test.cpp
  requiredBy: []
  timestamp: '2025-02-23 17:42:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/unionfind.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/unionfind.test.cpp
- /verify/Test/LC/unionfind.test.cpp.html
title: Test/LC/unionfind.test.cpp
---
