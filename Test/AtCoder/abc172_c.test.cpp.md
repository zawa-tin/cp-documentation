---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/PrefixSum1D/PrefixSum1D.hpp
    title: "1\u6B21\u5143\u7D2F\u7A4D\u548C"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp
    title: "\u9759\u7684\u306A\u5217\u4E0A\u306E\u533A\u9593\u548C\u30AF\u30A8\u30EA"
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
    PROBLEM: https://atcoder.jp/contests/abc172/tasks/abc172_c
    links:
    - https://atcoder.jp/contests/abc172/tasks/abc172_c
  bundledCode: "#line 1 \"Test/AtCoder/abc172_c.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc172/tasks/abc172_c\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp\"\
    \n\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nclass AdditiveGroup {\npublic:\n    using Element = T;\n    static\
    \ constexpr T identity() noexcept {\n        return T{};\n    }\n    static constexpr\
    \ T operation(const T& l, const T& r) noexcept {\n        return l + r;\n    }\n\
    \    static constexpr T inverse(const T& v) noexcept {\n        return -v;\n \
    \   }\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/PrefixSum1D/PrefixSum1D.hpp\"\
    \n\n#line 4 \"Src/DataStructure/PrefixSum1D/PrefixSum1D.hpp\"\n\n#include <cmath>\n\
    #include <vector>\n#include <cassert>\n#include <algorithm>\n#include <type_traits>\n\
    #include <functional>\n\nnamespace zawa {\n\ntemplate <class Group>\nclass PrefixSum1D\
    \ {\nprivate:\n    using T = typename Group::Element;\n    std::vector<T> dat_;\n\
    \n    constexpr bool rangeCheck(u32 l, u32 r) const {\n        return (l <= r\
    \ and r < dat_.size());\n    }\n\npublic:\n    PrefixSum1D() = default; \n   \
    \ PrefixSum1D(const std::vector<T>& A) : dat_(A.size() + 1, Group::identity())\
    \ {\n        dat_.shrink_to_fit();\n        for (u32 i = 0 ; i < A.size() ; i++)\
    \ {\n            dat_[i + 1] = Group::operation(dat_[i], A[i]);\n        }\n \
    \   }\n\n    inline T operator[](u32 i) const {\n        assert(i < dat_.size());\n\
    \        return dat_[i];\n    }\n\n    inline usize size() const {\n        return\
    \ dat_.size();\n    }\n\n    T product(u32 l, u32 r) const {\n        assert(rangeCheck(l,\
    \ r));\n        return Group::operation(Group::inverse(dat_[l]), dat_[r]);\n \
    \   }\n\n    u32 lowerBound(u32 l, u32 r, const T& v) const {\n        assert(rangeCheck(l,\
    \ r));\n        T value = Group::operation(v, dat_[l]);\n        return std::lower_bound(dat_.begin()\
    \ + l, dat_.begin() + r, value) - dat_.begin();\n    }\n\n    u32 upperBound(u32\
    \ l, u32 r, const T& v) const {\n        assert(rangeCheck(l, r));\n        T\
    \ value = Group::operation(v, dat_[l]);\n        return std::upper_bound(dat_.begin()\
    \ + l, dat_.begin() + r, value) - dat_.begin();\n    }\n\n    template <class\
    \ F>\n    u32 maxRight(u32 l, const F& f) const {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(T)>>, \"f must be function bool(T)\");\n        assert(l\
    \ < dat_.size());\n        assert(f(Group::identity()));\n        auto f_ = [&](const\
    \ T& v) -> bool {\n            return f(Group::operation(v, Group::inverse(dat_[l])));\n\
    \        };\n        return std::partition_point(dat_.begin() + l, dat_.end(),\
    \ f_) - dat_.begin();\n    }\n\n    template <class F>\n    u32 minLeft(u32 r,\
    \ const F& f) const {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(T)>>, \"f must be function bool(T)\");\n        assert(r\
    \ < dat_.size());\n        assert(f(Group::identity()));\n        auto f_ = [&](const\
    \ T& v) -> bool {\n            return f(Group::operation(Group::inverse(v), dat_[r]));\n\
    \        };\n        return dat_.rend() - std::partition_point(dat_.rbegin() +\
    \ (dat_.size() - r - 1), dat_.rend(), f_) - 1;\n    }\n\n    const auto begin()\
    \ const {\n        return dat_.begin();\n    }\n\n    const auto end() const {\n\
    \        return dat_.end();\n    }\n};\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp\"\
    \n\nnamespace zawa {\n\n    template <class T>\n    using StaticRangeSumSolver\
    \ = PrefixSum1D<AdditiveGroup<T>>;\n\n    template <class T>\n    using Ruisekiwa\
    \ = PrefixSum1D<AdditiveGroup<T>>;\n\n};\n#line 5 \"Test/AtCoder/abc172_c.test.cpp\"\
    \n\n#include <iostream>\n#line 9 \"Test/AtCoder/abc172_c.test.cpp\"\n\nusing namespace\
    \ zawa;\n\ni32 main() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\n\
    \    usize N, M; std::cin >> N >> M;\n    i64 K; std::cin >> K;\n\n    std::vector<i64>\
    \ A(N), B(M);\n    for (auto& a : A) std::cin >> a;\n    for (auto& b : B) std::cin\
    \ >> b;\n\n    A.push_back((i64)1e15);\n    B.push_back((i64)1e15);\n    N++;\
    \ M++;\n\n    Ruisekiwa<i64> SA(A), SB(B);\n\n    u32 ans1{}, ans2{};\n\n    {\n\
    \        for (u32 a = 0 ; a <= N ; a++) {\n            if (SA[a] > K) break;\n\
    \            u32 v = a + SB.upperBound(0, M, K - SA[a]) - 1;\n            ans1\
    \ = std::max(ans1, v);\n        }\n    }\n\n    {\n        for (u32 a = 0 ; a\
    \ <= N ; a++) {\n            if (SA[a] > K) break;\n            auto f = [&](i64\
    \ v) -> bool {\n                return SA[a] + v <= K;\n            };\n     \
    \       u32 v = a + SB.maxRight(0, f) - 1;\n            ans2 = std::max(ans2,\
    \ v);\n        }\n    }\n\n    assert(ans1 == ans2);\n\n    std::cout << ans1\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc172/tasks/abc172_c\"\n\n\
    #include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n#include <algorithm>\n\nusing namespace\
    \ zawa;\n\ni32 main() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\n\
    \    usize N, M; std::cin >> N >> M;\n    i64 K; std::cin >> K;\n\n    std::vector<i64>\
    \ A(N), B(M);\n    for (auto& a : A) std::cin >> a;\n    for (auto& b : B) std::cin\
    \ >> b;\n\n    A.push_back((i64)1e15);\n    B.push_back((i64)1e15);\n    N++;\
    \ M++;\n\n    Ruisekiwa<i64> SA(A), SB(B);\n\n    u32 ans1{}, ans2{};\n\n    {\n\
    \        for (u32 a = 0 ; a <= N ; a++) {\n            if (SA[a] > K) break;\n\
    \            u32 v = a + SB.upperBound(0, M, K - SA[a]) - 1;\n            ans1\
    \ = std::max(ans1, v);\n        }\n    }\n\n    {\n        for (u32 a = 0 ; a\
    \ <= N ; a++) {\n            if (SA[a] > K) break;\n            auto f = [&](i64\
    \ v) -> bool {\n                return SA[a] + v <= K;\n            };\n     \
    \       u32 v = a + SB.maxRight(0, f) - 1;\n            ans2 = std::max(ans2,\
    \ v);\n        }\n    }\n\n    assert(ans1 == ans2);\n\n    std::cout << ans1\
    \ << std::endl;\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/DataStructure/PrefixSum1D/PrefixSum1D.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc172_c.test.cpp
  requiredBy: []
  timestamp: '2023-07-22 13:55:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc172_c.test.cpp
layout: document
title: ABC172-C Tsundoku
---

読んだ本の集合が等しいなら本を読んだ合計時間は等しい -> 本を読む順番は考慮しなくて良い。

ここで、 机Aから読む本の冊数を $a$ 冊に固定したとする。机Aから $a$ 冊の本を読むのにかかる時間は $\displaystyle S_{a} = \sum_{i = 1}^{a} A_i$ 分であり、残りの $K - S_{a}$ 分で机Bから何冊よむことができるかを高速に判定できれば良い。

これは $B$ の累積和上で二分探索すれば良い。
