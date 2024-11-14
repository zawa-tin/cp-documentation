---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/CompressedSequence.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/RangeKthSmallest.hpp
    title: Range Kth Smallest
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
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"Test/LC/range_kth_smallest.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#line 2 \"Src/Template/IOSetting.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\
    \n\n#include <iostream>\n#include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO()\
    \ {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n}\n\nvoid SetPrecision(u32\
    \ dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Sequence/RangeKthSmallest.hpp\"\n\n#line 2 \"Src/Sequence/CompressedSequence.hpp\"\
    \n\n#line 4 \"Src/Sequence/CompressedSequence.hpp\"\n\n#include <vector>\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iterator>\n\nnamespace zawa {\n\n\
    template <class T>\nclass CompressedSequence {\nprivate:\n    std::vector<T> comped_;\n\
    \    std::vector<u32> f_;\n    \npublic:\n    CompressedSequence() = default;\n\
    \n    template <class InputIterator>\n    CompressedSequence(InputIterator first,\
    \ InputIterator last) : comped_(first, last), f_{} {\n        std::sort(comped_.begin(),\
    \ comped_.end());\n        comped_.erase(std::unique(comped_.begin(), comped_.end()),\
    \ comped_.end());\n        comped_.shrink_to_fit();\n        f_.reserve(std::distance(first,\
    \ last));\n        for (auto it{first} ; it != last ; it++) {\n            f_.emplace_back(std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), *it)));\n        }\n    }\n\
    \n    CompressedSequence(const std::vector<T>& A) : CompressedSequence(A.begin(),\
    \ A.end()) {}\n\n    inline usize size() const noexcept {\n        return comped_.size();\n\
    \    }\n\n    u32 operator[](const T& v) const {\n        return std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), v));\n    }\n\n    u32 at(const\
    \ T& v) const {\n        u32 res{(*this)[v]};\n        assert(res < size() and\
    \ comped_[res] == v);\n        return res;\n    }\n\n    inline u32 map(u32 i)\
    \ const noexcept {\n        assert(i < f_.size());\n        return f_[i];\n  \
    \  }\n\n    inline T inverse(u32 i) const noexcept {\n        assert(i < size());\n\
    \        return comped_[i];\n    }\n};\n\n} // namespace zawa\n#line 5 \"Src/Sequence/RangeKthSmallest.hpp\"\
    \n\n#line 7 \"Src/Sequence/RangeKthSmallest.hpp\"\n#include <bit>\n#line 9 \"\
    Src/Sequence/RangeKthSmallest.hpp\"\n#include <utility>\n#line 11 \"Src/Sequence/RangeKthSmallest.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T, class U>\nstd::vector<T> RangeKthSmallest(const\
    \ std::vector<T>& A, const std::vector<U>& Q) {\n    assert(A.size());\n    CompressedSequence\
    \ comp{A};\n    std::vector<std::vector<std::pair<usize, bool>>> event(A.size()\
    \ + 1);\n    for (usize i{} ; i < Q.size() ; i++) {\n        const U& q{Q[i]};\n\
    \        assert(q.l < q.r and q.r <= A.size());\n        assert(q.k < q.r - q.l);\n\
    \        event[q.l].emplace_back(i, true);\n        event[q.r].emplace_back(i,\
    \ false);\n    }\n    std::vector<usize> x(Q.size()), cnt(Q.size());\n    const\
    \ usize LOG{(usize)(std::bit_width(comp.size()) -\n            (std::has_single_bit(comp.size())\
    \ ? 1 : 0))};\n    for (usize i{LOG} ; i-- ; ) {\n        std::vector<i32> seg(1\
    \ << (LOG - i));\n        std::vector<i32> add(Q.size());\n        for (usize\
    \ j{1} ; j <= A.size() ; j++) {\n            seg[comp.map(j - 1) >> i]++;\n  \
    \          for (auto [k, s] : event[j]) {\n                add[k] += seg[(x[k]\
    \ >> i)] * (s ? -1 : 1);\n            }\n        }\n        for (u32 j{} ; j <\
    \ Q.size() ; j++) {\n            if (cnt[j] + add[j] <= Q[j].k) {\n          \
    \      x[j] += 1 << i;\n                cnt[j] += add[j];\n            }\n   \
    \     }\n    } \n    std::vector<T> res(Q.size());\n    for (usize i{} ; i < Q.size()\
    \ ; i++) {\n        res[i] = comp.inverse(x[i]);\n    }\n    return res;\n}\n\n\
    } // namespace zawa\n#line 5 \"Test/LC/range_kth_smallest.test.cpp\"\n\n#line\
    \ 8 \"Test/LC/range_kth_smallest.test.cpp\"\n\nusing namespace zawa;\n\nstruct\
    \ query {\n    usize k, l, r;\n};\n\nint main() {\n    SetFastIO();\n    int N,\
    \ Q;\n    std::cin >> N >> Q;\n    std::vector<int> A(N);\n    for (auto& a :\
    \ A) std::cin >> a;\n    std::vector<query> q(Q);\n    for (int i{} ; i < Q ;\
    \ i++) {\n        usize l, r, k;\n        std::cin >> l >> r >> k;\n        q[i]\
    \ = { k, l, r };\n    }\n    for (auto ans : RangeKthSmallest(A, q)) {\n     \
    \   std::cout << ans << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Sequence/RangeKthSmallest.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nusing namespace zawa;\n\nstruct\
    \ query {\n    usize k, l, r;\n};\n\nint main() {\n    SetFastIO();\n    int N,\
    \ Q;\n    std::cin >> N >> Q;\n    std::vector<int> A(N);\n    for (auto& a :\
    \ A) std::cin >> a;\n    std::vector<query> q(Q);\n    for (int i{} ; i < Q ;\
    \ i++) {\n        usize l, r, k;\n        std::cin >> l >> r >> k;\n        q[i]\
    \ = { k, l, r };\n    }\n    for (auto ans : RangeKthSmallest(A, q)) {\n     \
    \   std::cout << ans << '\\n';\n    }\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Sequence/RangeKthSmallest.hpp
  - Src/Sequence/CompressedSequence.hpp
  isVerificationFile: true
  path: Test/LC/range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2024-11-15 02:44:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/range_kth_smallest.test.cpp
- /verify/Test/LC/range_kth_smallest.test.cpp.html
title: Test/LC/range_kth_smallest.test.cpp
---
