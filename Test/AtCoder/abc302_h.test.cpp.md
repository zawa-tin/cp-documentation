---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/DisjointSetUnion/UndoableDisjointSetUnion.hpp
    title: Src/DataStructure/DisjointSetUnion/UndoableDisjointSetUnion.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Undoable/UndoableValue.hpp
    title: Src/DataStructure/Undoable/UndoableValue.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc302/tasks/abc302_ex
    links:
    - https://atcoder.jp/contests/abc302/tasks/abc302_ex
  bundledCode: "#line 1 \"Test/AtCoder/abc302_h.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc302/tasks/abc302_ex\"\
    \n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/DisjointSetUnion/UndoableDisjointSetUnion.hpp\"\
    \n\n#line 2 \"Src/DataStructure/Undoable/UndoableVector.hpp\"\n\n#line 4 \"Src/DataStructure/Undoable/UndoableVector.hpp\"\
    \n\n#include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nclass UndoableVector {\npublic:\n    using Iterator\
    \ = typename std::vector<T>::const_iterator;\n\n    UndoableVector() = default;\n\
    \n    UndoableVector(usize n) : vec_(n) {}\n\n    UndoableVector(usize n, const\
    \ T& v) : vec_(n, v) {}\n\n    UndoableVector(const std::vector<T>& vec) : vec_{vec}\
    \ {}\n\n    UndoableVector(std::vector<T>&& vec) : vec_{std::move(vec)} {}\n \
    \   \n    inline usize size() const {\n        return vec_.size();\n    }\n\n\
    \    Iterator begin() const {\n        return vec_.begin();\n    }\n\n    Iterator\
    \ end() const {\n        return vec_.end();\n    }\n\n    void assign(usize i,\
    \ const T& v) {\n        assert(i < size());\n        save(i);\n        vec_[i]\
    \ = v;\n    }\n\n    T operator[](usize i) const {\n        assert(i < size());\n\
    \        return vec_[i];\n    }\n\n    void undo() {\n        assert(history_.size());\n\
    \        auto [i, v]{history_.back()};\n        vec_[i] = v;\n        history_.pop_back();\n\
    \    }\n\nprivate:\n    std::vector<T> vec_; \n    std::vector<std::pair<usize,\
    \ T>> history_;\n\n    void save(usize i) {\n        history_.emplace_back(i,\
    \ vec_[i]);\n    }\n};\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/DisjointSetUnion/UndoableDisjointSetUnion.hpp\"\
    \n\n#include <algorithm>\n#line 8 \"Src/DataStructure/DisjointSetUnion/UndoableDisjointSetUnion.hpp\"\
    \n\nnamespace zawa {\n\nclass UndoableDisjointSetUnion {\npublic:\n    UndoableDisjointSetUnion()\
    \ = default;\n\n    UndoableDisjointSetUnion(usize n) : n_{n}, data_(n, -1) {}\n\
    \n    u32 leader(u32 v) const {\n        return data_[v] < 0 ? v : leader(data_[v]);\n\
    \    }\n\n    inline usize size() const {\n        return n_;\n    }\n\n    inline\
    \ usize size(u32 v) const {\n        assert(v < size());\n        return static_cast<usize>(-data_[leader(v)]);\n\
    \    }\n\n    bool same(u32 u, u32 v) const {\n        assert(u < size());\n \
    \       assert(v < size());\n        return leader(u) == leader(v);\n    }\n\n\
    \    bool merge(u32 u, u32 v) {\n        u = leader(u);\n        v = leader(v);\n\
    \        if (u == v) {\n            data_.assign(u, data_[u]);\n            data_.assign(v,\
    \ data_[v]);\n            return false;\n        }\n        else {\n         \
    \   if (data_[u] > data_[v]) std::swap(u, v);\n            data_.assign(u, data_[u]\
    \ + data_[v]);\n            data_.assign(v, u);\n            return true;\n  \
    \      }\n    }\n\n    void undo() {\n        data_.undo();\n        data_.undo();\n\
    \    }\n\n    std::vector<std::vector<u32>> enumerate() const {\n        std::vector<std::vector<u32>>\
    \ res(n_);\n        for (u32 v{} ; v < n_ ; v++) {\n            res[leader(v)].push_back(v);\n\
    \        }\n        res.erase(std::remove_if(res.begin(), res.end(),\n       \
    \             [](const auto& arr) -> bool { return arr.empty(); }), res.end());\n\
    \        return res;\n    }\n\nprivate:\n    usize n_{};\n    UndoableVector<i32>\
    \ data_{};\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/Undoable/UndoableValue.hpp\"\
    \n\n#line 5 \"Src/DataStructure/Undoable/UndoableValue.hpp\"\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nclass UndoableValue {\npublic:\n\n    UndoableValue()\
    \ = default;\n\n    UndoableValue(const T& v) : v_{v} {}\n\n    UndoableValue(T&&\
    \ v) : v_{std::move(v)} {}\n\n    void assign(const T& v) {\n        save();\n\
    \        v_ = v;\n    }\n\n    void assign(T&& v) {\n        save();\n       \
    \ v_ = std::move(v);\n    }\n\n    const T& value() const {\n        return v_;\n\
    \    }\n\n    void undo() {\n        assert(history_.size());\n        v_ = history_.back();\n\
    \        history_.pop_back();\n    }\n\nprivate:\n    T v_{};\n    std::vector<T>\
    \ history_;\n\n    inline void save() {\n        history_.emplace_back(v_);\n\
    \    }\n};\n\n} // namespace zawa\n#line 7 \"Test/AtCoder/abc302_h.test.cpp\"\n\
    \n#line 10 \"Test/AtCoder/abc302_h.test.cpp\"\nusing namespace zawa;\n\nint main()\
    \ {\n    SetFastIO();\n\n    int N;\n    std::cin >> N;\n    std::vector<std::vector<int>>\
    \ g(N);\n    std::vector<int> A(N), B(N);\n    for (int i{} ; i < N ; i++) {\n\
    \        std::cin >> A[i] >> B[i];\n        A[i]--; B[i]--;\n    }\n    for (int\
    \ _{} ; _ < N - 1 ; _++) {\n        int u, v;\n        std::cin >> u >> v;\n \
    \       u--; v--;\n        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n\
    \    }\n    UndoableValue<int> cur{};\n    UndoableVector<int> edge(N);\n    UndoableDisjointSetUnion\
    \ dsu(N);\n    std::vector<int> ans(N);\n    auto dfs{[&](auto dfs, int v, int\
    \ p) -> void {\n        int a{(int)dsu.leader(A[v])}, b{(int)dsu.leader(B[v])};\n\
    \        if (a == b) {\n            int old_val{std::min(edge[a], (int)dsu.size(a))};\n\
    \            edge.assign(a, edge[a] + 1);\n            int new_val{std::min(edge[a],\
    \ (int)dsu.size(a))};\n            cur.assign(cur.value() - old_val + new_val);\n\
    \            dsu.merge(a, b);\n        }\n        else {\n            int old_val{std::min(edge[a],\
    \ (int)dsu.size(a)) + std::min(edge[b], (int)dsu.size(b))};\n            dsu.merge(a,\
    \ b);\n            int led{(int)dsu.leader(a)};\n            edge.assign(led,\
    \ edge[a] + edge[b] + 1);\n            int new_val{std::min(edge[led], (int)dsu.size(led))};\n\
    \            cur.assign(cur.value() - old_val + new_val);\n        }\n       \
    \ ans[v] = cur.value();\n        for (auto x : g[v]) if (x != p) {\n         \
    \   dfs(dfs, x, v);\n        }\n        dsu.undo();\n        cur.undo();\n   \
    \     edge.undo();\n    }};\n    dfs(dfs, 0, -1);\n    for (int i{1} ; i < N ;\
    \ i++) {\n        std::cout << ans[i] << (i + 1 == N ? '\\n' : ' ');\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc302/tasks/abc302_ex\"\n\n\
    #include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/DataStructure/DisjointSetUnion/UndoableDisjointSetUnion.hpp\"\
    \n#include \"../../Src/DataStructure/Undoable/UndoableValue.hpp\"\n#include \"\
    ../../Src/DataStructure/Undoable/UndoableVector.hpp\"\n\n#include <cassert>\n\
    #include <iostream>\nusing namespace zawa;\n\nint main() {\n    SetFastIO();\n\
    \n    int N;\n    std::cin >> N;\n    std::vector<std::vector<int>> g(N);\n  \
    \  std::vector<int> A(N), B(N);\n    for (int i{} ; i < N ; i++) {\n        std::cin\
    \ >> A[i] >> B[i];\n        A[i]--; B[i]--;\n    }\n    for (int _{} ; _ < N -\
    \ 1 ; _++) {\n        int u, v;\n        std::cin >> u >> v;\n        u--; v--;\n\
    \        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n    }\n    UndoableValue<int>\
    \ cur{};\n    UndoableVector<int> edge(N);\n    UndoableDisjointSetUnion dsu(N);\n\
    \    std::vector<int> ans(N);\n    auto dfs{[&](auto dfs, int v, int p) -> void\
    \ {\n        int a{(int)dsu.leader(A[v])}, b{(int)dsu.leader(B[v])};\n       \
    \ if (a == b) {\n            int old_val{std::min(edge[a], (int)dsu.size(a))};\n\
    \            edge.assign(a, edge[a] + 1);\n            int new_val{std::min(edge[a],\
    \ (int)dsu.size(a))};\n            cur.assign(cur.value() - old_val + new_val);\n\
    \            dsu.merge(a, b);\n        }\n        else {\n            int old_val{std::min(edge[a],\
    \ (int)dsu.size(a)) + std::min(edge[b], (int)dsu.size(b))};\n            dsu.merge(a,\
    \ b);\n            int led{(int)dsu.leader(a)};\n            edge.assign(led,\
    \ edge[a] + edge[b] + 1);\n            int new_val{std::min(edge[led], (int)dsu.size(led))};\n\
    \            cur.assign(cur.value() - old_val + new_val);\n        }\n       \
    \ ans[v] = cur.value();\n        for (auto x : g[v]) if (x != p) {\n         \
    \   dfs(dfs, x, v);\n        }\n        dsu.undo();\n        cur.undo();\n   \
    \     edge.undo();\n    }};\n    dfs(dfs, 0, -1);\n    for (int i{1} ; i < N ;\
    \ i++) {\n        std::cout << ans[i] << (i + 1 == N ? '\\n' : ' ');\n    }\n\
    }\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/DisjointSetUnion/UndoableDisjointSetUnion.hpp
  - Src/DataStructure/Undoable/UndoableVector.hpp
  - Src/DataStructure/Undoable/UndoableValue.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc302_h.test.cpp
  requiredBy: []
  timestamp: '2024-07-07 06:07:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc302_h.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc302_h.test.cpp
- /verify/Test/AtCoder/abc302_h.test.cpp.html
title: Test/AtCoder/abc302_h.test.cpp
---
