---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/DisjointSetUnion/PotentializedDisjointSetUnion.hpp
    title: Src/DataStructure/DisjointSetUnion/PotentializedDisjointSetUnion.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
  bundledCode: "#line 1 \"Test/AOJ/DSL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Template/IOSetting.hpp\"\
    \n\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n#include <iomanip>\n\
    \nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\n\
    namespace zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n    using\
    \ Element = T;\n    static constexpr T identity() noexcept {\n        return T{};\n\
    \    }\n    static constexpr T operation(const T& l, const T& r) noexcept {\n\
    \        return l + r;\n    }\n    static constexpr T inverse(const T& v) noexcept\
    \ {\n        return -v;\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/DisjointSetUnion/PotentializedDisjointSetUnion.hpp\"\
    \n\n#line 4 \"Src/DataStructure/DisjointSetUnion/PotentializedDisjointSetUnion.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class Group>\nclass PotentializedDisjointSetUnion\
    \ {\npublic:\n    using Value = typename Group::Element;\nprivate:\n    usize\
    \ n_{}, comps_{};\n    std::vector<u32> parent_{};\n    std::vector<u32> size_{};\n\
    \    std::vector<Value> potential_{};\n\n    u32 leader(u32 v) {\n        if (parent_[v]\
    \ == v) {\n            return v;\n        }\n        else {\n            u32 res{leader(parent_[v])};\n\
    \            potential_[v] = Group::operation(potential_[parent_[v]], potential_[v]);\n\
    \            return parent_[v] = res;\n        }\n    }\n    Value potential(u32\
    \ v) {\n        leader(v);\n        return potential_[v];\n    }\n\npublic:\n\n\
    \    PotentializedDisjointSetUnion() = default;\n\n    PotentializedDisjointSetUnion(u32\
    \ n) \n        : n_{n}, comps_{n}, parent_(n), size_(n, u32{1}), potential_(n,\
    \ Group::identity()) {\n        std::iota(parent_.begin(), parent_.end(), u32{});\n\
    \    }\n\n    constexpr u32 size() const noexcept {\n        return n_;\n    }\n\
    \n    u32 size(u32 v) {\n        leader(v);\n        return size_[v];\n    }\n\
    \n    inline u32 components() const noexcept {\n        return comps_;\n    }\n\
    \n    bool isDefined(u32 u, u32 v) {\n        return leader(u) == leader(v);\n\
    \    }\n\n    Value distance(u32 u, u32 v) {\n        assert(u < size());\n  \
    \      assert(v < size());\n        return Group::operation(Group::inverse(potential(u)),\
    \ potential(v));\n    }\n\n    bool merge(u32 u, u32 v, Value value) {\n     \
    \   if (isDefined(u, v)) {\n            return distance(u, v) == value;\n    \
    \    }\n        comps_--;\n        value = Group::operation(potential(u), value);\n\
    \        value = Group::operation(Group::inverse(potential(v)), value);\n    \
    \    u = leader(u);\n        v = leader(v);\n        if (size_[u] > size_[v])\
    \ {\n            value = Group::inverse(value);\n            std::swap(u, v);\n\
    \        }\n        size_[u] += size_[v];\n        parent_[v] = u;\n        potential_[v]\
    \ = value;\n        return true;\n    }\n};\n\n} // namespace zawa\n#line 7 \"\
    Test/AOJ/DSL_1_B.test.cpp\"\n\n#line 10 \"Test/AOJ/DSL_1_B.test.cpp\"\n\nint main()\
    \ {\n    using namespace zawa;\n    SetFastIO();\n    u32 n, q; std::cin >> n\
    \ >> q;\n    PotentializedDisjointSetUnion<AdditiveGroup<i32>> dsu(n);\n    for\
    \ (u32 _{} ; _ < q ; _++) {\n        u32 t; std::cin >> t;\n        if (t == 0)\
    \ {\n            u32 x, y; std::cin >> x >> y;\n            i32 z; std::cin >>\
    \ z;\n            assert(dsu.merge(x, y, z));\n        }\n        else if (t ==\
    \ 1) {\n            u32 x, y; std::cin >> x >> y;\n            if (dsu.isDefined(x,\
    \ y)) {\n                std::cout << dsu.distance(x, y) << '\\n';\n         \
    \   }\n            else {\n                std::cout << '?' << '\\n';\n      \
    \      }\n        }\n        else {\n            assert(false);\n        }\n \
    \   }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\
    \n\n#include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Template/IOSetting.hpp\"\
    \n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\n#include \"../../Src/DataStructure/DisjointSetUnion/PotentializedDisjointSetUnion.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n\nint main() {\n    using namespace\
    \ zawa;\n    SetFastIO();\n    u32 n, q; std::cin >> n >> q;\n    PotentializedDisjointSetUnion<AdditiveGroup<i32>>\
    \ dsu(n);\n    for (u32 _{} ; _ < q ; _++) {\n        u32 t; std::cin >> t;\n\
    \        if (t == 0) {\n            u32 x, y; std::cin >> x >> y;\n          \
    \  i32 z; std::cin >> z;\n            assert(dsu.merge(x, y, z));\n        }\n\
    \        else if (t == 1) {\n            u32 x, y; std::cin >> x >> y;\n     \
    \       if (dsu.isDefined(x, y)) {\n                std::cout << dsu.distance(x,\
    \ y) << '\\n';\n            }\n            else {\n                std::cout <<\
    \ '?' << '\\n';\n            }\n        }\n        else {\n            assert(false);\n\
    \        }\n    }\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Template/IOSetting.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/DataStructure/DisjointSetUnion/PotentializedDisjointSetUnion.hpp
  isVerificationFile: true
  path: Test/AOJ/DSL_1_B.test.cpp
  requiredBy: []
  timestamp: '2025-02-23 17:42:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/DSL_1_B.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/DSL_1_B.test.cpp
- /verify/Test/AOJ/DSL_1_B.test.cpp.html
title: Test/AOJ/DSL_1_B.test.cpp
---
