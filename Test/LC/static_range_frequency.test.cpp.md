---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Mo/Mo.hpp
    title: Mo's algorithm
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/CompressedSequence.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
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
    \ zawa\n#line 2 \"Src/DataStructure/Mo/Mo.hpp\"\n\n#line 4 \"Src/DataStructure/Mo/Mo.hpp\"\
    \n\n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <vector>\n\
    #include <type_traits>\n\nnamespace zawa {\n\nnamespace internal {\n\n// reference:\
    \ https://codeforces.com/blog/entry/61203?#comment-1064868\nu64 hilbertOrder(u64\
    \ x, u64 y, usize dim) {\n    const u64 max{(1ull << dim) - 1};\n    assert(x\
    \ <= max);\n    assert(y <= max);\n    u64 res{};\n    for (u64 s{1ull << (dim\
    \ - 1)} ; s ; s >>= 1) {\n        bool rx{static_cast<bool>(x & s)}, ry{static_cast<bool>(y\
    \ & s)};\n        res = (res << 2) | (rx ? ry ? 2 : 1 : ry ? 3 : 0);\n       \
    \ if (!rx) {\n            if (ry) x ^= max, y ^= max;\n            std::swap(x,\
    \ y);\n        }\n    }\n    return res;\n}\n\n} // namespace internal\n\ntemplate\
    \ <class T, class AddL, class AddR, class DelL, class DelR, class Eval>\nstd::vector<typename\
    \ std::invoke_result_t<Eval, usize>> Mo(std::vector<T> qs, AddL addL, AddR addR,\
    \ DelL delL, DelR delR, Eval eval) {\n    usize log{};\n    for (const T& lr :\
    \ qs) log = std::max<usize>(log, std::bit_width(lr.r));\n    std::vector<std::pair<T,\
    \ usize>> ord(qs.size());\n    std::vector<u64> h(qs.size());\n    for (usize\
    \ i{} ; i < qs.size() ; i++) {\n        ord[i] = {qs[i], i};\n        h[i] = internal::hilbertOrder(qs[i].l,\
    \ qs[i].r, log);\n    }\n    std::sort(ord.begin(), ord.end(), [&](const auto&\
    \ L, const auto& R) -> bool {\n            return h[L.second] < h[R.second];\n\
    \            });\n    std::vector<typename std::invoke_result_t<Eval, usize>>\
    \ res(qs.size());\n    usize L{}, R{};\n    for (const auto& [lr, id] : ord) {\n\
    \        while (R < lr.r) addR(R++);\n        while (L > lr.l) addL(--L);\n  \
    \      while (R > lr.r) delR(--R);\n        while (L < lr.l) delL(L++);\n    \
    \    res[id] = eval(id);\n    }\n    return res;\n}\n\n} // namespace zawa\n#line\
    \ 2 \"Src/Sequence/CompressedSequence.hpp\"\n\n#line 4 \"Src/Sequence/CompressedSequence.hpp\"\
    \n\n#line 8 \"Src/Sequence/CompressedSequence.hpp\"\n#include <iterator>\n\nnamespace\
    \ zawa {\n\ntemplate <class T>\nclass CompressedSequence {\nprivate:\n    std::vector<T>\
    \ comped_;\n    std::vector<u32> f_;\n    \npublic:\n    CompressedSequence()\
    \ = default;\n\n    template <class InputIterator>\n    CompressedSequence(InputIterator\
    \ first, InputIterator last) : comped_(first, last), f_{} {\n        std::sort(comped_.begin(),\
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
    \        return comped_[i];\n    }\n};\n\n} // namespace zawa\n#line 6 \"Test/LC/static_range_frequency.test.cpp\"\
    \n\n#line 9 \"Test/LC/static_range_frequency.test.cpp\"\n\nusing namespace zawa;\n\
    \nint N, Q, X[500050];\nstruct query {\n    usize l, r;\n};\nint main() {\n  \
    \  SetFastIO();\n\n    std::cin >> N >> Q;\n    std::vector<int> A(N);\n    for\
    \ (int& a : A) std::cin >> a;\n    CompressedSequence comp{A};\n    std::vector<query>\
    \ q(Q);\n    for (int i{} ; auto& [l, r] : q) {\n        std::cin >> l >> r >>\
    \ X[i];\n        i++;\n    }\n    std::vector<int> cnt(comp.size());\n    auto\
    \ add{[&](int i) -> void {\n        cnt[comp.map(i)]++;\n    }};\n    auto del{[&](int\
    \ i) -> void {\n        cnt[comp.map(i)]--;\n    }};\n    auto eval{[&](int i)\
    \ -> int {\n        auto j{comp[X[i]]};\n        if (j == comp.size() or comp.inverse(j)\
    \ != X[i]) return 0;\n        else return cnt[j];\n    }};\n    for (int ans :\
    \ Mo(q, add, add, del, del, eval)) std::cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/DataStructure/Mo/Mo.hpp\"\
    \n#include \"../../Src/Sequence/CompressedSequence.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nusing namespace zawa;\n\nint N, Q, X[500050];\nstruct query\
    \ {\n    usize l, r;\n};\nint main() {\n    SetFastIO();\n\n    std::cin >> N\
    \ >> Q;\n    std::vector<int> A(N);\n    for (int& a : A) std::cin >> a;\n   \
    \ CompressedSequence comp{A};\n    std::vector<query> q(Q);\n    for (int i{}\
    \ ; auto& [l, r] : q) {\n        std::cin >> l >> r >> X[i];\n        i++;\n \
    \   }\n    std::vector<int> cnt(comp.size());\n    auto add{[&](int i) -> void\
    \ {\n        cnt[comp.map(i)]++;\n    }};\n    auto del{[&](int i) -> void {\n\
    \        cnt[comp.map(i)]--;\n    }};\n    auto eval{[&](int i) -> int {\n   \
    \     auto j{comp[X[i]]};\n        if (j == comp.size() or comp.inverse(j) !=\
    \ X[i]) return 0;\n        else return cnt[j];\n    }};\n    for (int ans : Mo(q,\
    \ add, add, del, del, eval)) std::cout << ans << '\\n';\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/Mo/Mo.hpp
  - Src/Sequence/CompressedSequence.hpp
  isVerificationFile: true
  path: Test/LC/static_range_frequency.test.cpp
  requiredBy: []
  timestamp: '2024-12-27 00:38:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/static_range_frequency.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/static_range_frequency.test.cpp
- /verify/Test/LC/static_range_frequency.test.cpp.html
title: Test/LC/static_range_frequency.test.cpp
---
