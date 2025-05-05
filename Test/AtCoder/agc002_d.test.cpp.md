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
  - icon: ':heavy_check_mark:'
    path: Src/Utility/ParallelBinarySearch.hpp
    title: "\u4E26\u5217\u4E8C\u5206\u63A2\u7D22"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/agc002/submissions/63106870
    - https://atcoder.jp/contests/agc002/tasks/agc002_d
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/agc002_d.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/agc002/tasks/agc002_d\"\n\n\
    #line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Utility/ParallelBinarySearch.hpp\"\n\n\
    #include <cassert>\n#include <concepts>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <std::integral T, class F>\nstd::vector<T> ParallelBinarySearch(std::vector<T>\
    \ oks, std::vector<T> ngs, F f) {\n    assert(oks.size() == ngs.size());\n   \
    \ while (true) {\n        std::vector<std::pair<T, usize>> remains; \n       \
    \ std::vector<usize> inv(oks.size(), static_cast<usize>(-1));\n        for (usize\
    \ i = 0 ; i < oks.size() ; i++) if ((oks[i] >= ngs[i] ? oks[i] - ngs[i] : ngs[i]\
    \ - oks[i]) > T{1}) {\n            T mid = (oks[i]&ngs[i]) + ((oks[i]^ngs[i])>>1);\n\
    \            inv[i] = remains.size();\n            remains.push_back({mid, i});\n\
    \        }\n        if (remains.empty()) break;\n        auto res = f(remains);\n\
    \        assert(res.size() == remains.size());\n        for (usize i = 0 ; i <\
    \ res.size() ; i++) {\n            T mid = remains[inv[res[i].second]].first;\n\
    \            if (res[i].first) oks[res[i].second] = mid;\n            else ngs[res[i].second]\
    \ = mid;\n            i++;\n        }\n    } \n    return oks;\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\n\n\
    #line 4 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\n\n#include\
    \ <algorithm>\n#line 7 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\
    \n#include <numeric>\n#line 10 \"Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\
    \n\nnamespace zawa {\n\nclass DisjointSetUnion {\npublic:\n    DisjointSetUnion()\
    \ = default;\n\n    DisjointSetUnion(usize n) : n_{n}, comps_{n}, data_(n, -1)\
    \ {\n        data_.shrink_to_fit();\n    }\n    \n    u32 leader(u32 v) {\n  \
    \      return data_[v] < 0 ? v : static_cast<u32>(data_[v] = leader(data_[v]));\n\
    \    }\n\n    bool same(u32 u, u32 v) {\n        return leader(u) == leader(v);\n\
    \    }\n\n    bool merge(u32 u, u32 v) {\n        assert(u < n_);\n        assert(v\
    \ < n_);\n        u = leader(u);\n        v = leader(v);\n        if (u == v)\
    \ return false;\n        comps_--;\n        if (data_[u] > data_[v]) std::swap(u,\
    \ v);\n        data_[u] += data_[v];\n        data_[v] = u;\n        return true;\n\
    \    }\n\n    inline usize size() const noexcept {\n        return n_;\n    }\n\
    \n    usize size(u32 v) {\n        assert(v < n_);\n        return static_cast<usize>(-data_[leader(v)]);\n\
    \    }\n\n    inline usize components() const noexcept {\n        return comps_;\n\
    \    }\n\n    template <class T = usize>\n    std::vector<std::vector<T>> enumerate()\
    \ requires std::convertible_to<usize, T> {\n        std::vector<std::vector<T>>\
    \ res(n_);\n        for (usize v{} ; v < n_ ; v++) {\n            res[leader(v)].push_back(static_cast<T>(v));\n\
    \        }\n        std::erase_if(res, [](const auto& arr) -> bool { return arr.empty();\
    \ });\n        return res;\n    }\n\nprivate:\n    usize n_{}, comps_{};\n   \
    \ std::vector<i32> data_;\n};\n\n} // namespace zawa\n#line 7 \"Test/AtCoder/agc002_d.test.cpp\"\
    \n\n/*\n * AGC002-D Stampl Rally\n * https://atcoder.jp/contests/agc002/submissions/63106870\n\
    \ */\n\n#line 15 \"Test/AtCoder/agc002_d.test.cpp\"\n\nusing namespace zawa;\n\
    int N, M, A[100010], B[100010], Q, X[100010], Y[100010], Z[100010];\nvoid solve()\
    \ {\n    auto f = [&](auto a) {\n        std::sort(a.begin(), a.end());\n    \
    \    std::vector<std::pair<bool, int>> res(a.size());\n        DisjointSetUnion\
    \ dsu(N);\n        for (int i = 1, j = 0 ; i <= M ; i++) {\n            dsu.merge(A[i],\
    \ B[i]);\n            assert(j == (int)a.size() or a[j].first >= i);\n       \
    \     while (j < (int)a.size() and a[j].first == i) {\n                int id\
    \ = a[j].second;\n                int num = (int)dsu.size(X[id]) + (dsu.same(X[id],\
    \ Y[id]) ? 0 : (int)dsu.size(Y[id]));\n                bool ans = num >= Z[id];\n\
    \                res[j++] = {ans, id};\n            }\n        }\n        return\
    \ res;\n    };\n    auto ans = ParallelBinarySearch(std::vector<int>(Q, M), std::vector<int>(Q,\
    \ 0), f);\n    for (int i = 0 ; i < Q ; i++) std::cout << ans[i] << '\\n';\n}\n\
    int main() {\n#ifdef ATCODER\n    SetFastIO();\n    std::cin >> N >> M;\n    for\
    \ (int i = 1 ; i <= M ; i++) {\n        std::cin >> A[i] >> B[i];\n        A[i]--;\
    \ B[i]--;\n    }\n    std::cin >> Q;\n    for (int i = 0 ; i < Q ; i++) {\n  \
    \      std::cin >> X[i] >> Y[i] >> Z[i];\n        X[i]--; Y[i]--;\n    }\n   \
    \ solve();\n#else\n    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/agc002/tasks/agc002_d\"\n\n\
    #include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Utility/ParallelBinarySearch.hpp\"\
    \n#include \"../../Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\n\
    \n/*\n * AGC002-D Stampl Rally\n * https://atcoder.jp/contests/agc002/submissions/63106870\n\
    \ */\n\n#include <algorithm>\n#include <vector>\n\nusing namespace zawa;\nint\
    \ N, M, A[100010], B[100010], Q, X[100010], Y[100010], Z[100010];\nvoid solve()\
    \ {\n    auto f = [&](auto a) {\n        std::sort(a.begin(), a.end());\n    \
    \    std::vector<std::pair<bool, int>> res(a.size());\n        DisjointSetUnion\
    \ dsu(N);\n        for (int i = 1, j = 0 ; i <= M ; i++) {\n            dsu.merge(A[i],\
    \ B[i]);\n            assert(j == (int)a.size() or a[j].first >= i);\n       \
    \     while (j < (int)a.size() and a[j].first == i) {\n                int id\
    \ = a[j].second;\n                int num = (int)dsu.size(X[id]) + (dsu.same(X[id],\
    \ Y[id]) ? 0 : (int)dsu.size(Y[id]));\n                bool ans = num >= Z[id];\n\
    \                res[j++] = {ans, id};\n            }\n        }\n        return\
    \ res;\n    };\n    auto ans = ParallelBinarySearch(std::vector<int>(Q, M), std::vector<int>(Q,\
    \ 0), f);\n    for (int i = 0 ; i < Q ; i++) std::cout << ans[i] << '\\n';\n}\n\
    int main() {\n#ifdef ATCODER\n    SetFastIO();\n    std::cin >> N >> M;\n    for\
    \ (int i = 1 ; i <= M ; i++) {\n        std::cin >> A[i] >> B[i];\n        A[i]--;\
    \ B[i]--;\n    }\n    std::cin >> Q;\n    for (int i = 0 ; i < Q ; i++) {\n  \
    \      std::cin >> X[i] >> Y[i] >> Z[i];\n        X[i]--; Y[i]--;\n    }\n   \
    \ solve();\n#else\n    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Utility/ParallelBinarySearch.hpp
  - Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
  isVerificationFile: true
  path: Test/AtCoder/agc002_d.test.cpp
  requiredBy: []
  timestamp: '2025-05-05 21:42:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/agc002_d.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/agc002_d.test.cpp
- /verify/Test/AtCoder/agc002_d.test.cpp.html
title: Test/AtCoder/agc002_d.test.cpp
---
