---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/BinarySearch.hpp
    title: "\u4E8C\u5206\u63A2\u7D22"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc165/tasks/arc165_c
    links:
    - https://atcoder.jp/contests/arc165/tasks/arc165_c
  bundledCode: "#line 1 \"Test/AtCoder/arc165_c.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/arc165/tasks/arc165_c\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Utility/BinarySearch.hpp\"\
    \n\n#line 4 \"Src/Utility/BinarySearch.hpp\"\n\n#include <cmath>\n#include <functional>\n\
    #include <type_traits>\n#include <utility>\n\nnamespace zawa {\n\nnamespace internal\
    \ {\n\ntemplate <class T>\nT MidPoint(T a, T b) {\n    if (a > b) std::swap(a,\
    \ b);\n    return a + ((b - a) >> 1);\n}\n\ntemplate <class T>\nT Abs(T a, T b)\
    \ {\n    return (a >= b ? a - b : b - a);\n}\n\n} // namespace zawa::internal\n\
    \ntemplate <class T, class Function>\nT BinarySearch(T ok, T ng, const Function&\
    \ f) {\n    static_assert(std::is_integral_v<T>, \"T must be integral type\");\n\
    \    static_assert(std::is_convertible_v<Function, std::function<bool(T)>>, \"\
    f must be function bool(T)\");\n    while (internal::Abs(ok, ng) > 1) {\n    \
    \    T mid{ internal::MidPoint(ok, ng) };\n        (f(mid) ? ok : ng) = mid;\n\
    \    }\n    return ok;\n}\n\ntemplate <class T, class Function>\nT BinarySearch(T\
    \ ok, T ng, const Function& f, u32 upperLimit) {\n    static_assert(std::is_signed_v<T>,\
    \ \"T must be signed arithmetic type\");\n    static_assert(std::is_convertible_v<Function,\
    \ std::function<bool(T)>>, \"f must be function bool(T)\");\n    for (u32 _{}\
    \ ; _ < upperLimit ; _++) {\n        T mid{ (ok + ng) / (T)2 };\n        (f(mid)\
    \ ? ok : ng) = mid;\n    }\n    return ok;\n}\n\n} // namespace zawa\n#line 5\
    \ \"Test/AtCoder/arc165_c.test.cpp\"\n\n#include <iostream>\n\nint main() {\n\
    \    using namespace zawa;\n    u32 n, m; std::cin >> n >> m;\n    std::vector\
    \ g(n, std::vector<std::pair<u32, u32>>{});\n    for (u32 _{} ; _ < m ; _++) {\n\
    \        u32 a, b, w; std::cin >> a >> b >> w;\n        a--; b--;\n        g[a].emplace_back(w,\
    \ b);\n        g[b].emplace_back(w, a);\n    }\n    for (auto& adj : g) std::sort(adj.begin(),\
    \ adj.end());\n\n    auto f{[&](u32 X) -> bool {\n        std::vector<i32> col(n,\
    \ -1);\n        auto rec{[&](auto rec, u32 v, u32 c) -> bool {\n            col[v]\
    \ = c;\n            for (auto [w, x] : g[v]) {\n                if (w >= X) break;\n\
    \                if (col[x] == -1 and !rec(rec, x, c ^ 1)) return false;\n   \
    \             if (col[x] == (i32)c) return false;\n            }\n           \
    \ return true;\n        }};\n        for (u32 i{} ; i < n ; i++) if (col[i] ==\
    \ -1 and !rec(rec, i, 0))\n            return false;\n        for (u32 i{} ; i\
    \ < n ; i++) if (g[i].size() > 1) {\n            if (g[i][0].first + g[i][1].first\
    \ < X) return false;\n        }\n        return true;\n    }};\n\n    u32 ans{\
    \ BinarySearch(u32{}, (u32)2e9 + 1, f) };\n    std::cout << ans << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc165/tasks/arc165_c\"\n\n\
    #include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Utility/BinarySearch.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n    using namespace zawa;\n    u32 n,\
    \ m; std::cin >> n >> m;\n    std::vector g(n, std::vector<std::pair<u32, u32>>{});\n\
    \    for (u32 _{} ; _ < m ; _++) {\n        u32 a, b, w; std::cin >> a >> b >>\
    \ w;\n        a--; b--;\n        g[a].emplace_back(w, b);\n        g[b].emplace_back(w,\
    \ a);\n    }\n    for (auto& adj : g) std::sort(adj.begin(), adj.end());\n\n \
    \   auto f{[&](u32 X) -> bool {\n        std::vector<i32> col(n, -1);\n      \
    \  auto rec{[&](auto rec, u32 v, u32 c) -> bool {\n            col[v] = c;\n \
    \           for (auto [w, x] : g[v]) {\n                if (w >= X) break;\n \
    \               if (col[x] == -1 and !rec(rec, x, c ^ 1)) return false;\n    \
    \            if (col[x] == (i32)c) return false;\n            }\n            return\
    \ true;\n        }};\n        for (u32 i{} ; i < n ; i++) if (col[i] == -1 and\
    \ !rec(rec, i, 0))\n            return false;\n        for (u32 i{} ; i < n ;\
    \ i++) if (g[i].size() > 1) {\n            if (g[i][0].first + g[i][1].first <\
    \ X) return false;\n        }\n        return true;\n    }};\n\n    u32 ans{ BinarySearch(u32{},\
    \ (u32)2e9 + 1, f) };\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Utility/BinarySearch.hpp
  isVerificationFile: true
  path: Test/AtCoder/arc165_c.test.cpp
  requiredBy: []
  timestamp: '2023-09-24 02:53:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/arc165_c.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/arc165_c.test.cpp
- /verify/Test/AtCoder/arc165_c.test.cpp.html
title: Test/AtCoder/arc165_c.test.cpp
---
