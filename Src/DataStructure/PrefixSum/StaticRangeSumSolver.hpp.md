---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/PrefixSum/PrefixSum1D.hpp
    title: "1\u6B21\u5143\u7D2F\u7A4D\u548C"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc172_c.test.cpp
    title: ABC172-C Tsundoku
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc229_d.test.cpp
    title: ABC229-D Longest X
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/agc023_a.test.cpp
    title: AGC023-A Zero-Sum Ranges
  - icon: ':heavy_check_mark:'
    path: Test/CF/EC162-D.test.cpp
    title: Test/CF/EC162-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/static_range_sum.test.cpp
    title: Test/LC/static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/PrefixSum/StaticRangeSumSolver.hpp\"\n\
    \n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nclass AdditiveGroup {\npublic:\n    using Element = T;\n    static\
    \ constexpr T identity() noexcept {\n        return T{};\n    }\n    static constexpr\
    \ T operation(const T& l, const T& r) noexcept {\n        return l + r;\n    }\n\
    \    static constexpr T inverse(const T& v) noexcept {\n        return -v;\n \
    \   }\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/PrefixSum/PrefixSum1D.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/PrefixSum/PrefixSum1D.hpp\"\
    \n\n#include <cmath>\n#include <vector>\n#include <cassert>\n#include <algorithm>\n\
    #include <type_traits>\n#include <functional>\n\nnamespace zawa {\n\ntemplate\
    \ <class Group>\nclass PrefixSum1D {\nprivate:\n    using T = typename Group::Element;\n\
    \    std::vector<T> dat_;\n\n    constexpr bool rangeCheck(u32 l, u32 r) const\
    \ {\n        return (l <= r and r < dat_.size());\n    }\n\npublic:\n    PrefixSum1D()\
    \ = default; \n    PrefixSum1D(const std::vector<T>& A) : dat_(A.size() + 1, Group::identity())\
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
    \        return dat_.end();\n    }\n};\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/PrefixSum/StaticRangeSumSolver.hpp\"\
    \n\nnamespace zawa {\n\n    template <class T>\n    using StaticRangeSumSolver\
    \ = PrefixSum1D<AdditiveGroup<T>>;\n\n    template <class T>\n    using Ruisekiwa\
    \ = PrefixSum1D<AdditiveGroup<T>>;\n\n};\n"
  code: "#pragma once\n\n#include \"../../Algebra/Group/AdditiveGroup.hpp\"\n#include\
    \ \"./PrefixSum1D.hpp\"\n\nnamespace zawa {\n\n    template <class T>\n    using\
    \ StaticRangeSumSolver = PrefixSum1D<AdditiveGroup<T>>;\n\n    template <class\
    \ T>\n    using Ruisekiwa = PrefixSum1D<AdditiveGroup<T>>;\n\n};\n"
  dependsOn:
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/DataStructure/PrefixSum/PrefixSum1D.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/PrefixSum/StaticRangeSumSolver.hpp
  requiredBy: []
  timestamp: '2025-11-30 16:55:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/agc023_a.test.cpp
  - Test/AtCoder/abc172_c.test.cpp
  - Test/AtCoder/abc229_d.test.cpp
  - Test/LC/static_range_sum.test.cpp
  - Test/CF/EC162-D.test.cpp
documentation_of: Src/DataStructure/PrefixSum/StaticRangeSumSolver.hpp
layout: document
title: "\u9759\u7684\u306A\u5217\u4E0A\u306E\u533A\u9593\u548C\u30AF\u30A8\u30EA"
---

## 概要

値の変更が無い長さ $N$ の数列 $A$ 上で区間和クエリを処理します。

詳細は1次元累積和のドキュメントを確認お願いします。

## ライブラリの使い方

```cpp
(1) using StaticRangeSumSolver = PrefixSum1D<AdditiveGroup<T>>;
(2) using Ruisekiwa = PrefixSum1D<AdditiveGroup<T>>;
```

構造体を生やす必要は無く、`T`をテンプレート引数で指定するだけです。

(1)、(2)共に同様です。好きな名前の方をお使いください。
