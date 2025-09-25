---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Mo/RollbackMo.hpp
    title: Rollback Mo
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/CompressedSequence.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_mode_query
    links:
    - https://judge.yosupo.jp/problem/static_range_mode_query
  bundledCode: "#line 1 \"Test/LC/static_range_mode_query.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_mode_query\"\n\n#line 2 \"Src/DataStructure/Mo/RollbackMo.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/Mo/RollbackMo.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <concepts>\n#include <limits>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class T,\
    \ class RBT, class Add, class Rollback, class Eval>\nstd::vector<typename std::invoke_result_t<Eval,\
    \ usize, const RBT&>> RollbackMo(const std::vector<T>& qs, Add addL, Add addR,\
    \ Rollback rollback, Eval eval) {\n    const usize n = [&]() {\n        usize\
    \ mx = 0;\n        for (usize i = 0 ; i < qs.size() ; i++) {\n            assert(qs[i].l\
    \ <= qs[i].r);\n            mx = std::max<usize>(mx, qs[i].r);\n        }\n  \
    \      return mx;\n    }();\n    const usize SQ = [&]() {\n        usize i = 1;\n\
    \        while (i * i < n)\n            i++;\n        return i;\n    }();\n  \
    \  std::vector<std::vector<std::pair<usize, usize>>> rs((n + SQ - 1) / SQ);\n\
    \    std::vector<typename std::invoke_result_t<Eval, usize, const RBT&>> res(qs.size());\n\
    \    std::vector<RBT> history;\n    history.emplace_back();\n    for (usize i\
    \ = 0 ; i < qs.size() ; i++) {\n        if (qs[i].r - qs[i].l <= SQ) {\n     \
    \       for (usize j = qs[i].l ; j < qs[i].r ; j++)\n                history.push_back(addR(j,\
    \ history.back()));\n            res[i] = eval(i, history.back());\n         \
    \   for (usize j = qs[i].l ; j < qs[i].r ; j++) {\n                rollback(history.back());\n\
    \                history.pop_back();\n            }\n        }\n        else\n\
    \            rs[qs[i].l / SQ].emplace_back(qs[i].r, i);\n    }\n    for (usize\
    \ i = 0 ; i < rs.size() ; i++)\n        if (rs[i].size()) {\n            std::sort(rs[i].begin(),\
    \ rs[i].end());\n            const usize L = (i + 1) * SQ;\n            usize\
    \ R = L;\n            for (auto [r, idx] : rs[i]) {\n                while (R\
    \ < r)\n                    history.push_back(addR(R++, history.back()));\n  \
    \              for (usize j = L ; j > qs[idx].l ; )\n                    history.push_back(addL(--j,\
    \ history.back()));\n                res[idx] = eval(i, history.back());\n   \
    \             for (usize j = L ; j > qs[idx].l ; j--) {\n                    rollback(history.back());\n\
    \                    history.pop_back();\n                }\n            }\n \
    \           for (usize j = L ; j < R ; j++) {\n                rollback(history.back());\n\
    \                history.pop_back();\n            }\n        }\n    return res;\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Sequence/CompressedSequence.hpp\"\n\n\
    #line 4 \"Src/Sequence/CompressedSequence.hpp\"\n\n#line 8 \"Src/Sequence/CompressedSequence.hpp\"\
    \n#include <iterator>\n#line 10 \"Src/Sequence/CompressedSequence.hpp\"\n\nnamespace\
    \ zawa {\n\ntemplate <class T>\nclass CompressedSequence {\npublic:\n\n    static\
    \ constexpr u32 NotFound = std::numeric_limits<u32>::max();\n\n    CompressedSequence()\
    \ = default;\n\n    template <class InputIterator>\n    CompressedSequence(InputIterator\
    \ first, InputIterator last) : comped_(first, last), f_{} {\n        std::sort(comped_.begin(),\
    \ comped_.end());\n        comped_.erase(std::unique(comped_.begin(), comped_.end()),\
    \ comped_.end());\n        comped_.shrink_to_fit();\n        f_.reserve(std::distance(first,\
    \ last));\n        for (auto it{first} ; it != last ; it++) {\n            f_.emplace_back(std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), *it)));\n        }\n    }\n\
    \n    CompressedSequence(const std::vector<T>& A) : CompressedSequence(A.begin(),\
    \ A.end()) {}\n\n    inline usize size() const noexcept {\n        return comped_.size();\n\
    \    }\n\n    u32 operator[](const T& v) const {\n        return std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), v));\n    }\n\n    u32 upper_bound(const\
    \ T& v) const {\n        return std::distance(comped_.begin(), std::upper_bound(comped_.begin(),\
    \ comped_.end(), v));\n    }\n\n    u32 find(const T& v) const {\n        u32\
    \ i = std::distance(comped_.begin(), std::lower_bound(comped_.begin(), comped_.end(),\
    \ v));\n        return i == comped_.size() or comped_[i] != v ? NotFound : i;\n\
    \    }\n\n    bool contains(const T& v) const {\n        u32 i = std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), v));\n        return i < comped_.size()\
    \ and comped_[i] == v;\n    }\n\n    u32 at(const T& v) const {\n        u32 res\
    \ = find(v);\n        assert(res != NotFound);\n        return res;\n    }\n\n\
    \    inline u32 map(u32 i) const noexcept {\n        assert(i < f_.size());\n\
    \        return f_[i];\n    }\n\n    inline T inverse(u32 i) const noexcept {\n\
    \        assert(i < size());\n        return comped_[i];\n    }\n\n    inline\
    \ std::vector<T> comped() const noexcept {\n        return comped_;\n    }\n\n\
    private:\n\n    std::vector<T> comped_;\n\n    std::vector<u32> f_;\n\n};\n\n\
    } // namespace zawa\n#line 5 \"Test/LC/static_range_mode_query.test.cpp\"\n\n\
    #include <iostream>\n#line 9 \"Test/LC/static_range_mode_query.test.cpp\"\nusing\
    \ namespace std;\nusing namespace zawa;\nstruct Query {\n    usize l, r;\n};\n\
    struct Data {\n    int top = -1, last = -1;\n};\nint main() {\n    cin.tie(0);\n\
    \    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N, Q;\n    cin >> N >>\
    \ Q;\n    vector<int> A(N);\n    for (int i = 0 ; i < N ; i++)\n        cin >>\
    \ A[i];\n    CompressedSequence<int> comp{A};\n    for (int i = 0 ; i < N ; i++)\n\
    \        A[i] = comp.map(i);\n    vector<Query> q(Q);\n    for (auto& [l, r] :\
    \ q)\n        cin >> l >> r;\n    vector<int> cnt(ssize(comp));\n    auto add\
    \ = [&](int i, Data d) {\n        cnt[A[i]]++;\n        if (d.top == -1 or cnt[A[i]]\
    \ > cnt[d.top])\n            d.top = A[i];\n        d.last = A[i];\n        return\
    \ d;\n    };\n    auto rollback = [&](const Data& d) {\n        cnt[d.last]--;\n\
    \    };\n    auto eval = [&](int, const Data& d) -> pair<int, int> {\n       \
    \ return {comp.inverse(d.top), cnt[d.top]};\n    };\n    for (auto [a, b] : RollbackMo<Query,\
    \ Data, decltype(add), decltype(rollback), decltype(eval)>(q, add, add, rollback,\
    \ eval))\n        cout << a << ' ' << b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_mode_query\"\
    \n\n#include \"../../Src/DataStructure/Mo/RollbackMo.hpp\"\n#include \"../../Src/Sequence/CompressedSequence.hpp\"\
    \n\n#include <iostream>\n#include <utility>\n#include <vector>\nusing namespace\
    \ std;\nusing namespace zawa;\nstruct Query {\n    usize l, r;\n};\nstruct Data\
    \ {\n    int top = -1, last = -1;\n};\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n    int N, Q;\n    cin >> N >> Q;\n    vector<int>\
    \ A(N);\n    for (int i = 0 ; i < N ; i++)\n        cin >> A[i];\n    CompressedSequence<int>\
    \ comp{A};\n    for (int i = 0 ; i < N ; i++)\n        A[i] = comp.map(i);\n \
    \   vector<Query> q(Q);\n    for (auto& [l, r] : q)\n        cin >> l >> r;\n\
    \    vector<int> cnt(ssize(comp));\n    auto add = [&](int i, Data d) {\n    \
    \    cnt[A[i]]++;\n        if (d.top == -1 or cnt[A[i]] > cnt[d.top])\n      \
    \      d.top = A[i];\n        d.last = A[i];\n        return d;\n    };\n    auto\
    \ rollback = [&](const Data& d) {\n        cnt[d.last]--;\n    };\n    auto eval\
    \ = [&](int, const Data& d) -> pair<int, int> {\n        return {comp.inverse(d.top),\
    \ cnt[d.top]};\n    };\n    for (auto [a, b] : RollbackMo<Query, Data, decltype(add),\
    \ decltype(rollback), decltype(eval)>(q, add, add, rollback, eval))\n        cout\
    \ << a << ' ' << b << '\\n';\n}\n"
  dependsOn:
  - Src/DataStructure/Mo/RollbackMo.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Sequence/CompressedSequence.hpp
  isVerificationFile: true
  path: Test/LC/static_range_mode_query.test.cpp
  requiredBy: []
  timestamp: '2025-09-26 03:53:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/static_range_mode_query.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/static_range_mode_query.test.cpp
- /verify/Test/LC/static_range_mode_query.test.cpp.html
title: Test/LC/static_range_mode_query.test.cpp
---
