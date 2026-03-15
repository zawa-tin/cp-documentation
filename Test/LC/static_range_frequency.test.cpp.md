---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/CompressedSequence.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/MoRangeQuery.hpp
    title: Mo's algorithm
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/Mo.hpp
    title: Src/Utility/Mo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"Test/LC/static_range_frequency.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_frequency\"\n\n#line 2 \"Src/Template/IOSetting.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\
    \n\n#include <iostream>\n#include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO()\
    \ {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n}\n\nvoid SetPrecision(u32\
    \ dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Sequence/MoRangeQuery.hpp\"\n\n#include <algorithm>\n#include\
    \ <ranges>\n\n#line 2 \"Src/Utility/Mo.hpp\"\n\n#line 4 \"Src/Utility/Mo.hpp\"\
    \n\n#line 6 \"Src/Utility/Mo.hpp\"\n#include <cmath>\n#line 8 \"Src/Utility/Mo.hpp\"\
    \n#include <utility>\n#include <numeric>\n#include <limits>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nstd::vector<usize> Mo(const std::vector<std::pair<T,T>>&\
    \ P) {\n    if (P.empty())\n        return {};\n    T minY = std::numeric_limits<T>::max();\n\
    \    const u64 W = [&]() {\n        T minX = std::numeric_limits<T>::max();\n\
    \        T maxX = std::numeric_limits<T>::min(), maxY = std::numeric_limits<T>::min();\n\
    \        for (auto [x,y] : P) {\n            minX = std::min(minX,x);\n      \
    \      maxX = std::max(maxX,x);\n            minY = std::min(minY,y);\n      \
    \      maxY = std::max(maxY,y);\n        }\n        return std::max<u64>({1,u64(maxX-minX),u64(maxY-minY)});\n\
    \    }();\n    const usize B = [&]() {\n        u64 sq = std::max<u64>(1,sqrt(P.size()));\n\
    \        return (W + sq - 1) / sq;\n    }();\n    std::vector<usize> ord1(P.size()),\
    \ ord2(P.size());\n    std::iota(ord1.begin(),ord1.end(),0);\n    std::iota(ord2.begin(),ord2.end(),0);\n\
    \    T sub = minY;\n    auto comp = [&](usize i, usize j) {\n                auto\
    \ [xi,yi] = P[i];\n                auto [xj,yj] = P[j];\n                yi -=\
    \ sub;\n                yj -= sub;\n                if (yi/B != yj/B)\n      \
    \              return yi/B < yj/B;\n                else if ((yi/B)&1)\n     \
    \               return xi>xj;\n                else\n                    return\
    \ xi<xj;\n    };\n    std::ranges::sort(ord1,comp);\n    sub -= B / 2;\n    std::ranges::sort(ord2,comp);\n\
    \    auto cost = [&](const std::vector<usize>& ord) {\n        u64 res = 0;\n\
    \        for (usize i = 0 ; i + 1 < ord.size() ; i++) {\n            res += abs(P[ord[i+1]].first-P[ord[i]].first);\n\
    \            res += abs(P[ord[i+1]].second-P[ord[i]].second);\n        }\n   \
    \     return res;\n    };\n    return cost(ord1) <= cost(ord2) ? ord1 : ord2;\n\
    }\n\n} // namespace zawa\n#line 7 \"Src/Sequence/MoRangeQuery.hpp\"\n\nnamespace\
    \ zawa {\n\ntemplate <class T, class AddL, class AddR, class DelL, class DelR,\
    \ class Eval>\nstd::vector<typename std::invoke_result_t<Eval, usize>> Mo(const\
    \ std::vector<std::pair<T,T>>& qs, AddL addL, AddR addR, DelL delL, DelR delR,\
    \ Eval eval, bool reset = false) {\n    auto ord = Mo(qs);\n    std::vector<typename\
    \ std::invoke_result_t<Eval, usize>> res(qs.size());\n    T L = 0, R = 0;\n  \
    \  for (usize i : ord) {\n        const auto [l, r] = qs[i];\n        while (R\
    \ < r) \n            addR(R++);\n        while (L > l) \n            addL(--L);\n\
    \        while (R > r) \n            delR(--R);\n        while (L < l) \n    \
    \        delL(L++);\n        res[i] = eval(i);\n    }\n    if (reset) \n     \
    \   while (R > L) \n            delR(--R);\n    return res;\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Sequence/CompressedSequence.hpp\"\n\n#line 4 \"Src/Sequence/CompressedSequence.hpp\"\
    \n\n#line 7 \"Src/Sequence/CompressedSequence.hpp\"\n#include <cassert>\n#include\
    \ <iterator>\n#line 10 \"Src/Sequence/CompressedSequence.hpp\"\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nclass CompressedSequence {\npublic:\n\n    static constexpr\
    \ u32 NotFound = std::numeric_limits<u32>::max();\n\n    CompressedSequence()\
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
    } // namespace zawa\n#line 6 \"Test/LC/static_range_frequency.test.cpp\"\n\n#line\
    \ 9 \"Test/LC/static_range_frequency.test.cpp\"\n\nusing namespace zawa;\n\nint\
    \ N, Q, X[500050];\nint main() {\n    SetFastIO();\n\n    std::cin >> N >> Q;\n\
    \    std::vector<int> A(N);\n    for (int& a : A) std::cin >> a;\n    CompressedSequence\
    \ comp{A};\n    std::vector<std::pair<int,int>> q(Q);\n    for (int i{} ; auto&\
    \ [l, r] : q) {\n        std::cin >> l >> r >> X[i];\n        i++;\n    }\n  \
    \  std::vector<int> cnt(comp.size());\n    auto add{[&](int i) -> void {\n   \
    \     cnt[comp.map(i)]++;\n    }};\n    auto del{[&](int i) -> void {\n      \
    \  cnt[comp.map(i)]--;\n    }};\n    auto eval{[&](int i) -> int {\n        auto\
    \ j = comp.find(X[i]);\n        if (j == decltype(comp)::NotFound) return 0;\n\
    \        else return cnt[j];\n    }};\n    for (int ans : Mo(q, add, add, del,\
    \ del, eval)) std::cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Sequence/MoRangeQuery.hpp\"\
    \n#include \"../../Src/Sequence/CompressedSequence.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nusing namespace zawa;\n\nint N, Q, X[500050];\nint main()\
    \ {\n    SetFastIO();\n\n    std::cin >> N >> Q;\n    std::vector<int> A(N);\n\
    \    for (int& a : A) std::cin >> a;\n    CompressedSequence comp{A};\n    std::vector<std::pair<int,int>>\
    \ q(Q);\n    for (int i{} ; auto& [l, r] : q) {\n        std::cin >> l >> r >>\
    \ X[i];\n        i++;\n    }\n    std::vector<int> cnt(comp.size());\n    auto\
    \ add{[&](int i) -> void {\n        cnt[comp.map(i)]++;\n    }};\n    auto del{[&](int\
    \ i) -> void {\n        cnt[comp.map(i)]--;\n    }};\n    auto eval{[&](int i)\
    \ -> int {\n        auto j = comp.find(X[i]);\n        if (j == decltype(comp)::NotFound)\
    \ return 0;\n        else return cnt[j];\n    }};\n    for (int ans : Mo(q, add,\
    \ add, del, del, eval)) std::cout << ans << '\\n';\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Sequence/MoRangeQuery.hpp
  - Src/Utility/Mo.hpp
  - Src/Sequence/CompressedSequence.hpp
  isVerificationFile: true
  path: Test/LC/static_range_frequency.test.cpp
  requiredBy: []
  timestamp: '2026-03-15 23:24:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/static_range_frequency.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/static_range_frequency.test.cpp
- /verify/Test/LC/static_range_frequency.test.cpp.html
title: Test/LC/static_range_frequency.test.cpp
---
