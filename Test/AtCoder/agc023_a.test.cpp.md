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
    PROBLEM: https://atcoder.jp/contests/agc023/tasks/agc023_a
    links:
    - https://atcoder.jp/contests/agc023/tasks/agc023_a
  bundledCode: "#line 1 \"Test/AtCoder/agc023_a.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/agc023/tasks/agc023_a\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp\"\
    \n\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nclass AdditiveGroup {\npublic:\n    using ValueType = T;\n    static\
    \ constexpr T identity() noexcept {\n        return T{};\n    }\n    static constexpr\
    \ T operation(const T& l, const T& r) noexcept {\n        return l + r;\n    }\n\
    \    static constexpr T inverse(const T& v) noexcept {\n        return -v;\n \
    \   }\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/PrefixSum1D/PrefixSum1D.hpp\"\
    \n\n#line 4 \"Src/DataStructure/PrefixSum1D/PrefixSum1D.hpp\"\n\n#include <cmath>\n\
    #include <vector>\n#include <cassert>\n#include <algorithm>\n#include <type_traits>\n\
    \nnamespace zawa {\n\ntemplate <class Group>\nclass PrefixSum1D {\nprivate:\n\
    \    using T = typename Group::ValueType;\n    std::vector<T> dat;\n\n    constexpr\
    \ bool rangeCheck(u32 l, u32 r) const {\n        return (l <= r and r < dat.size());\n\
    \    }\n\npublic:\n    PrefixSum1D() = default; \n    PrefixSum1D(const std::vector<T>&\
    \ A) : dat(A.size() + 1, Group::identity()) {\n        dat.shrink_to_fit();\n\
    \        for (u32 i = 0 ; i < A.size() ; i++) {\n            dat[i + 1] = Group::operation(dat[i],\
    \ A[i]);\n        }\n    }\n\n    inline T operator[](u32 i) const {\n       \
    \ assert(i < dat.size());\n        return dat[i];\n    }\n\n    inline usize size()\
    \ const {\n        return dat.size();\n    }\n\n    T product(u32 l, u32 r) const\
    \ {\n        assert(rangeCheck(l, r));\n        return Group::operation(Group::inverse(dat[l]),\
    \ dat[r]);\n    }\n\n    u32 lowerBound(u32 l, u32 r, const T& v) const {\n  \
    \      assert(rangeCheck(l, r));\n        T value = Group::operation(v, dat[l]);\n\
    \        return std::lower_bound(dat.begin() + l, dat.begin() + r, value) - dat.begin();\n\
    \    }\n\n    u32 upperBound(u32 l, u32 r, const T& v) const {\n        assert(rangeCheck(l,\
    \ r));\n        T value = Group::operation(v, dat[l]);\n        return std::upper_bound(dat.begin()\
    \ + l, dat.begin() + r, value) - dat.begin();\n    }\n\n    template <class F>\n\
    \    u32 maxRight(u32 l, const F& f) const {\n        static_assert(std::is_same_v<bool,\
    \ std::invoke_result_t<decltype(f), T>> == true, \"result type must be bool\"\
    );\n        assert(l < dat.size());\n        assert(f(Group::identity()));\n \
    \       auto f_ = [&](const T& v) -> bool {\n            return f(Group::operation(v,\
    \ Group::inverse(dat[l])));\n        };\n        return std::partition_point(dat.begin()\
    \ + l, dat.end(), f_) - dat.begin();\n    }\n\n    template <class F>\n    u32\
    \ minLeft(u32 r, const F& f) const {\n        static_assert(std::is_same_v<bool,\
    \ std::invoke_result_t<decltype(f), T>> == true, \"result type must be bool\"\
    );\n        assert(r < dat.size());\n        assert(f(Group::identity()));\n \
    \       auto f_ = [&](const T& v) -> bool {\n            return f(Group::operation(Group::inverse(v),\
    \ dat[r]));\n        };\n        return dat.rend() - std::partition_point(dat.rbegin()\
    \ + (dat.size() - r - 1), dat.rend(), f_) - 1;\n    }\n};\n\n} // namespace zawa\n\
    #line 5 \"Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp\"\n\nnamespace\
    \ zawa {\n\n    template <class T>\n    using StaticRangeSumSolver = PrefixSum1D<AdditiveGroup<T>>;\n\
    \n    template <class T>\n    using Ruisekiwa = PrefixSum1D<AdditiveGroup<T>>;\n\
    \n};\n#line 5 \"Test/AtCoder/agc023_a.test.cpp\"\n\n#include <iostream>\n#line\
    \ 8 \"Test/AtCoder/agc023_a.test.cpp\"\n#include <map>\n\nusing namespace zawa;\n\
    \ni32 main() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\n    u32\
    \ N; std::cin >> N;\n    std::vector<i64> A(N);\n    for (auto& a : A) std::cin\
    \ >> a;\n\n    Ruisekiwa<i64> S(A);\n    std::map<i64, i32> mp{};\n    u64 ans\
    \ = 0;\n    for (u32 i = 0 ; i < S.size() ; i++) {\n        ans += mp[S[i]];\n\
    \        mp[S[i]]++;\n    } \n\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/agc023/tasks/agc023_a\"\n\n\
    #include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n#include <map>\n\nusing namespace\
    \ zawa;\n\ni32 main() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\n\
    \    u32 N; std::cin >> N;\n    std::vector<i64> A(N);\n    for (auto& a : A)\
    \ std::cin >> a;\n\n    Ruisekiwa<i64> S(A);\n    std::map<i64, i32> mp{};\n \
    \   u64 ans = 0;\n    for (u32 i = 0 ; i < S.size() ; i++) {\n        ans += mp[S[i]];\n\
    \        mp[S[i]]++;\n    } \n\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/DataStructure/PrefixSum1D/PrefixSum1D.hpp
  isVerificationFile: true
  path: Test/AtCoder/agc023_a.test.cpp
  requiredBy: []
  timestamp: '2023-06-23 03:23:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/agc023_a.test.cpp
layout: document
title: AGC023-A Zero-Sum Ranges
---

「空でない連続する $A$ の部分列」を「非空な区間」と言い換える。 非空な区間 $[l, r)$ であって $\displaystyle \sum_{i = l}^{r - 1} A_i = 0$ を満たすものの数を数える問題となる。

これは、 $A$ の累積和 $S$ をとることで $S_{r} - S_{l} = 0$ となる区間の数を数える問題に言い換えることができる。式変形して $S_{r} = S_{l}$ と解釈する。

ここで、 $S_{i} = x$ を満たす $i$ の数が $k$ 個存在する時、 $S_{l} = x, S_{r} = x$ となるように $l, r$ を選択する通り数は $\binom{k}{2} = \frac{k \times (k - 1)}{2}$ である。

よって連想配列等を利用して $S_{i}$ を値の種類と数にまとめ上げることでこの問題を解くことができた。

<br />

この問題を部分問題に含む問題が現在まで沢山出題されているので、解法を残した。
