---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Flow/BurnBury.hpp
    title: Src/Graph/Flow/BurnBury.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Flow/Dinic.hpp
    title: "Dinic (\u6700\u5927\u6D41\u30FB\u6700\u5C0F\u30AB\u30C3\u30C8)"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Flow/SuccessiveShortestPath.hpp
    title: "SuccessiveShortestPath (\u6700\u5C0F\u8CBB\u7528\u6D41\u3001\u6700\u77ED\
      \u8DEF\u53CD\u5FA9\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/HeavyLightDecomposition.hpp
    title: Src/Graph/Tree/HeavyLightDecomposition.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/1163.test.cpp
    title: Test/AOJ/1163.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2828.test.cpp
    title: "AOJ2828 \u30DE\u30C8\u30EA\u30E7\u30FC\u30B7\u30AB"
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2872.test.cpp
    title: "AOJ2872 \u6700\u77ED\u8DDD\u96E2\u3092\u4F38\u3070\u3059\u3048\u3073\u3061\
      \u3083\u3093"
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2943.test.cpp
    title: "AOJ2943 \u30A4\u30EB\u30DF\u30CD\u30FC\u30B7\u30E7\u30F3"
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/3168.test.cpp
    title: Test/AOJ/3168.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/GRL_6_A.test.cpp
    title: Test/AOJ/GRL_6_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/GRL_6_B.test.cpp
    title: Test/AOJ/GRL_6_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/GRL_7_A.test.cpp
    title: Test/AOJ/GRL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc193_f.test.cpp
    title: ABC193-F Zebraness
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc205_f.test.cpp
    title: ABC205-F Grid and Tokens
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc247_g.test.cpp
    title: ABC247-G Dream Team
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc263_g.test.cpp
    title: ABC263-G Erasing Prime Pairs
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc318_g.test.cpp
    title: ABC318-G Typical Path Problem
  - icon: ':heavy_check_mark:'
    path: Test/LC/bipartitematching.test.cpp
    title: Test/LC/bipartitematching.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/vertex_add_path_sum.test.cpp
    title: Test/LC/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc004_d.test.cpp
    title: Test/Manual/abc004_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc239_g.test.cpp
    title: ABC239-G Builder Takahashi
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc317_g.test.cpp
    title: ABC317-G Rearranging
  - icon: ':heavy_check_mark:'
    path: Test/Manual/kupc2016_e.test.cpp
    title: "Kyoto University Programming Contest 2016-E \u67F5"
  - icon: ':heavy_check_mark:'
    path: Test/Manual/practice2_d.test.cpp
    title: AtCoder Library Practice Contest - D Maxflow
  - icon: ':heavy_check_mark:'
    path: Test/Manual/practice2_e.test.cpp
    title: AtCoder Library Practice Contest - E MinCostFlow
  - icon: ':heavy_check_mark:'
    path: Test/Manual/typical90_an.test.cpp
    title: "\u7AF6\u30D7\u30ED\u5178\u578B90\u554F-040 Get More Money"
  - icon: ':heavy_check_mark:'
    path: Test/Manual/typical90_by.test.cpp
    title: Test/Manual/typical90_by.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/My/Utility/U32Pair.test.cpp
    title: Test/My/Utility/U32Pair.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Utility/U32Pair.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Utility/U32Pair.hpp\"\n\n#include <functional>\n\
    #include <iostream>\n\nnamespace zawa {\n\nclass U32Pair {\nprivate:\n    static\
    \ constexpr u32 SHIFT{32};\n    static constexpr u32 MASK{static_cast<u32>((1LL\
    \ << SHIFT) - 1)};\n    u64 value_{};\npublic:\n    constexpr U32Pair() {}\n \
    \   constexpr U32Pair(u32 first, u32 second) {\n        value_ = (static_cast<u64>(first)\
    \ << SHIFT) | second;\n    }\n    constexpr u32 first() const noexcept {\n   \
    \     return static_cast<u32>(value_ >> SHIFT);\n    }\n    constexpr u32 second()\
    \ const noexcept {\n        return static_cast<u32>(value_ & MASK);\n    }\n \
    \   constexpr u64 combined() const noexcept {\n        return value_;\n    }\n\
    \    constexpr U32Pair& operator=(const U32Pair& rhs) {\n        value_ = rhs.value_;\n\
    \        return *this;\n    }\n    friend constexpr bool operator==(const U32Pair&\
    \ lhs, const U32Pair& rhs) {\n        return lhs.value_ == rhs.value_;\n    }\n\
    \    friend constexpr bool operator!=(const U32Pair& lhs, const U32Pair& rhs)\
    \ {\n        return lhs.value_ != rhs.value_;\n    }\n    friend constexpr bool\
    \ operator<(const U32Pair& lhs, const U32Pair& rhs) {\n        return lhs.value_\
    \ < rhs.value_;\n    }\n    friend constexpr bool operator<=(const U32Pair& lhs,\
    \ const U32Pair& rhs) {\n        return lhs.value_ <= rhs.value_;\n    }\n   \
    \ friend constexpr bool operator>(const U32Pair& lhs, const U32Pair& rhs) {\n\
    \        return lhs.value_ > rhs.value_;\n    }\n    friend constexpr bool operator>=(const\
    \ U32Pair& lhs, const U32Pair& rhs) {\n        return lhs.value_ >= rhs.value_;\n\
    \    }\n    friend std::ostream& operator<<(std::ostream& os, const U32Pair& pair)\
    \ {\n        os << '(' << pair.first() << ',' << pair.second() << ')';\n     \
    \   return os;\n    }\n};\n\nstruct U32PairHash {\n    usize operator()(const\
    \ U32Pair& pair) const noexcept {\n        return std::hash<u64>{}(pair.combined());\n\
    \    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <functional>\n\
    #include <iostream>\n\nnamespace zawa {\n\nclass U32Pair {\nprivate:\n    static\
    \ constexpr u32 SHIFT{32};\n    static constexpr u32 MASK{static_cast<u32>((1LL\
    \ << SHIFT) - 1)};\n    u64 value_{};\npublic:\n    constexpr U32Pair() {}\n \
    \   constexpr U32Pair(u32 first, u32 second) {\n        value_ = (static_cast<u64>(first)\
    \ << SHIFT) | second;\n    }\n    constexpr u32 first() const noexcept {\n   \
    \     return static_cast<u32>(value_ >> SHIFT);\n    }\n    constexpr u32 second()\
    \ const noexcept {\n        return static_cast<u32>(value_ & MASK);\n    }\n \
    \   constexpr u64 combined() const noexcept {\n        return value_;\n    }\n\
    \    constexpr U32Pair& operator=(const U32Pair& rhs) {\n        value_ = rhs.value_;\n\
    \        return *this;\n    }\n    friend constexpr bool operator==(const U32Pair&\
    \ lhs, const U32Pair& rhs) {\n        return lhs.value_ == rhs.value_;\n    }\n\
    \    friend constexpr bool operator!=(const U32Pair& lhs, const U32Pair& rhs)\
    \ {\n        return lhs.value_ != rhs.value_;\n    }\n    friend constexpr bool\
    \ operator<(const U32Pair& lhs, const U32Pair& rhs) {\n        return lhs.value_\
    \ < rhs.value_;\n    }\n    friend constexpr bool operator<=(const U32Pair& lhs,\
    \ const U32Pair& rhs) {\n        return lhs.value_ <= rhs.value_;\n    }\n   \
    \ friend constexpr bool operator>(const U32Pair& lhs, const U32Pair& rhs) {\n\
    \        return lhs.value_ > rhs.value_;\n    }\n    friend constexpr bool operator>=(const\
    \ U32Pair& lhs, const U32Pair& rhs) {\n        return lhs.value_ >= rhs.value_;\n\
    \    }\n    friend std::ostream& operator<<(std::ostream& os, const U32Pair& pair)\
    \ {\n        os << '(' << pair.first() << ',' << pair.second() << ')';\n     \
    \   return os;\n    }\n};\n\nstruct U32PairHash {\n    usize operator()(const\
    \ U32Pair& pair) const noexcept {\n        return std::hash<u64>{}(pair.combined());\n\
    \    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Utility/U32Pair.hpp
  requiredBy:
  - Src/Graph/Tree/HeavyLightDecomposition.hpp
  - Src/Graph/Flow/BurnBury.hpp
  - Src/Graph/Flow/Dinic.hpp
  - Src/Graph/Flow/SuccessiveShortestPath.hpp
  timestamp: '2023-12-16 19:11:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/My/Utility/U32Pair.test.cpp
  - Test/Manual/typical90_an.test.cpp
  - Test/Manual/abc004_d.test.cpp
  - Test/Manual/practice2_e.test.cpp
  - Test/Manual/practice2_d.test.cpp
  - Test/Manual/abc317_g.test.cpp
  - Test/Manual/kupc2016_e.test.cpp
  - Test/Manual/abc239_g.test.cpp
  - Test/Manual/typical90_by.test.cpp
  - Test/AOJ/GRL_6_B.test.cpp
  - Test/AOJ/GRL_6_A.test.cpp
  - Test/AOJ/2943.test.cpp
  - Test/AOJ/3168.test.cpp
  - Test/AOJ/2828.test.cpp
  - Test/AOJ/1163.test.cpp
  - Test/AOJ/GRL_7_A.test.cpp
  - Test/AOJ/2872.test.cpp
  - Test/AtCoder/abc193_f.test.cpp
  - Test/AtCoder/abc263_g.test.cpp
  - Test/AtCoder/abc318_g.test.cpp
  - Test/AtCoder/abc205_f.test.cpp
  - Test/AtCoder/abc247_g.test.cpp
  - Test/LC/vertex_add_path_sum.test.cpp
  - Test/LC/bipartitematching.test.cpp
documentation_of: Src/Utility/U32Pair.hpp
layout: document
redirect_from:
- /library/Src/Utility/U32Pair.hpp
- /library/Src/Utility/U32Pair.hpp.html
title: Src/Utility/U32Pair.hpp
---
