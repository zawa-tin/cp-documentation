---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Undoable/UndoableVector.hpp
    title: Src/DataStructure/Undoable/UndoableVector.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc165/tasks/abc165_f
    links:
    - https://atcoder.jp/contests/abc165/tasks/abc165_f
  bundledCode: "#line 1 \"Test/AtCoder/abc165_f.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc165/tasks/abc165_f\"\
    \n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/Undoable/UndoableVector.hpp\"\
    \n\n#line 4 \"Src/DataStructure/Undoable/UndoableVector.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class T>\n\
    class UndoableVector {\npublic:\n    using Iterator = typename std::vector<T>::const_iterator;\n\
    \n    UndoableVector() = default;\n\n    UndoableVector(usize n) : vec_(n) {}\n\
    \n    UndoableVector(usize n, const T& v) : vec_(n, v) {}\n\n    UndoableVector(const\
    \ std::vector<T>& vec) : vec_{vec} {}\n\n    UndoableVector(std::vector<T>&& vec)\
    \ : vec_{std::move(vec)} {}\n    \n    inline usize size() const {\n        return\
    \ vec_.size();\n    }\n\n    Iterator begin() const {\n        return vec_.begin();\n\
    \    }\n\n    Iterator end() const {\n        return vec_.end();\n    }\n\n  \
    \  void assign(usize i, const T& v) {\n        assert(i < size());\n        save(i);\n\
    \        vec_[i] = v;\n    }\n\n    T operator[](usize i) const {\n        assert(i\
    \ < size());\n        return vec_[i];\n    }\n\n    void undo() {\n        assert(history_.size());\n\
    \        auto [i, v]{history_.back()};\n        vec_[i] = v;\n        history_.pop_back();\n\
    \    }\n\nprivate:\n    std::vector<T> vec_; \n    std::vector<std::pair<usize,\
    \ T>> history_;\n\n    void save(usize i) {\n        history_.emplace_back(i,\
    \ vec_[i]);\n    }\n};\n\n} // namespace zawa\n#line 5 \"Test/AtCoder/abc165_f.test.cpp\"\
    \n\n#include <algorithm>\n#line 8 \"Test/AtCoder/abc165_f.test.cpp\"\n#include\
    \ <iterator>\n#line 10 \"Test/AtCoder/abc165_f.test.cpp\"\nusing namespace zawa;\n\
    \n\nint main() {\n    SetFastIO();\n    int N;\n    std::cin >> N;\n    std::vector<int>\
    \ A(N);\n    for (auto& a : A) std::cin >> a;\n    std::vector<std::vector<int>>\
    \ g(N);\n    for (int i{} ; i < N - 1 ; i++) {\n        int u, v;\n        std::cin\
    \ >> u >> v;\n        u--; v--;\n        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n\
    \    }\n\n    const int INF{(int)2e9};\n    UndoableVector<int> dp(N, INF);\n\
    \    std::vector<int> ans(N);\n    auto dfs{[&](auto dfs, int v, int p) -> void\
    \ {\n        int pos{(int)std::distance(dp.begin(), std::lower_bound(dp.begin(),\
    \ dp.end(), A[v]))};\n        dp.assign(pos, A[v]);\n        ans[v] = (int)std::distance(dp.begin(),\
    \ std::lower_bound(dp.begin(), dp.end(), INF));\n        for (auto x : g[v]) if\
    \ (x != p) {\n            dfs(dfs, x, v);\n        }\n        dp.undo();\n   \
    \ }};\n    dfs(dfs, 0, -1);\n    for (int i{} ; i < N ; i++) {\n        std::cout\
    \ << ans[i] << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc165/tasks/abc165_f\"\n\n\
    #include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/DataStructure/Undoable/UndoableVector.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <iterator>\n#include <vector>\n\
    using namespace zawa;\n\n\nint main() {\n    SetFastIO();\n    int N;\n    std::cin\
    \ >> N;\n    std::vector<int> A(N);\n    for (auto& a : A) std::cin >> a;\n  \
    \  std::vector<std::vector<int>> g(N);\n    for (int i{} ; i < N - 1 ; i++) {\n\
    \        int u, v;\n        std::cin >> u >> v;\n        u--; v--;\n        g[u].emplace_back(v);\n\
    \        g[v].emplace_back(u);\n    }\n\n    const int INF{(int)2e9};\n    UndoableVector<int>\
    \ dp(N, INF);\n    std::vector<int> ans(N);\n    auto dfs{[&](auto dfs, int v,\
    \ int p) -> void {\n        int pos{(int)std::distance(dp.begin(), std::lower_bound(dp.begin(),\
    \ dp.end(), A[v]))};\n        dp.assign(pos, A[v]);\n        ans[v] = (int)std::distance(dp.begin(),\
    \ std::lower_bound(dp.begin(), dp.end(), INF));\n        for (auto x : g[v]) if\
    \ (x != p) {\n            dfs(dfs, x, v);\n        }\n        dp.undo();\n   \
    \ }};\n    dfs(dfs, 0, -1);\n    for (int i{} ; i < N ; i++) {\n        std::cout\
    \ << ans[i] << '\\n';\n    }\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/Undoable/UndoableVector.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc165_f.test.cpp
  requiredBy: []
  timestamp: '2024-07-07 06:05:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc165_f.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc165_f.test.cpp
- /verify/Test/AtCoder/abc165_f.test.cpp.html
title: Test/AtCoder/abc165_f.test.cpp
---
