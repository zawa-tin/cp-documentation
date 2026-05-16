---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Wavelet/RangeAggregation.hpp
    title: Range Aggregation
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Wavelet/RectangleAggregation.hpp
    title: Rectangle Aggregation
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Wavelet/WaveletMatrix.hpp
    title: Wavelet Matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/3518.test.cpp
    title: Test/AOJ/3518.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc266_h.test.cpp
    title: Test/AtCoder/abc266_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc339_g.test.cpp
    title: Test/AtCoder/abc339_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_add_rectangle_sum/RectangleAggregation.test.cpp
    title: Test/LC/point_add_rectangle_sum/RectangleAggregation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/range_kth_smallest/WaveletMatrix.test.cpp
    title: Test/LC/range_kth_smallest/WaveletMatrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/rectangle_sum/RectangleAggregation.test.cpp
    title: Test/LC/rectangle_sum/RectangleAggregation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/My/DataStructure/PrefixSum/BitVector.test.cpp
    title: Test/My/DataStructure/PrefixSum/BitVector.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/My/DataStructure/Wavelet/WaveletMatrix.test.cpp
    title: Test/My/DataStructure/Wavelet/WaveletMatrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/PrefixSum/BitVector.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/PrefixSum/BitVector.hpp\"\
    \n\n#include <array>\n#include <bit>\n#include <cassert>\n#include <concepts>\n\
    #include <vector>\n\nnamespace zawa {\n\nclass BitVector {\nprivate:\n\n    static\
    \ constexpr u32 B = 64;\n\n    static constexpr u32 LOGB = 6;\n\n    static constexpr\
    \ std::array<u64,B> MASK = []() {\n        std::array<u64,B> res;\n        res.fill(0);\n\
    \        for (usize i = 1 ; i < B ; i++)\n            res[i] = res[i-1]|(1ull<<(i-1));\n\
    \        return res;\n    }();\n\npublic:\n\n    BitVector() = default;\n\n  \
    \  template <class T>\n    BitVector(std::vector<T> a) : m_n{a.size()}, m_dat((m_n+B-1)>>LOGB),\
    \ m_pref(m_dat.size()+1) {\n        for (usize i = 0 ; i < size() ; i++) {\n \
    \           u64 v = a[i]>0;\n            m_dat[i>>LOGB] |= v << (i & (B-1));\n\
    \            m_pref[(i>>LOGB)+1] += v;\n        }\n        for (usize i = 0 ;\
    \ i < m_dat.size() ; i++)\n            m_pref[i+1] += m_pref[i];\n    }\n\n  \
    \  inline usize size() const {\n        return m_n;\n    }\n\n    u32 rank1(usize\
    \ l,usize r) const {\n        return pref(r)-pref(l);\n    }\n\n    u32 rank0(usize\
    \ l,usize r) const {\n        return r-l-pref(r)+pref(l);\n    }\n\n    template<class\
    \ T>\n    T access(usize i) const {\n        return (m_dat[i>>LOGB] >> (i&(B-1)))\
    \ & 1;\n    }\n\nprivate:\n\n    usize m_n;\n\n    std::vector<u64> m_dat;\n\n\
    \    std::vector<u32> m_pref;\n\n    u32 pref(usize r) const {\n        const\
    \ usize q = r>>LOGB, b = r&(B-1);\n        return m_pref[q]+(b ? std::popcount<u64>(m_dat[q]&MASK[r&(B-1)])\
    \ : 0u);\n    }\n\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <array>\n\
    #include <bit>\n#include <cassert>\n#include <concepts>\n#include <vector>\n\n\
    namespace zawa {\n\nclass BitVector {\nprivate:\n\n    static constexpr u32 B\
    \ = 64;\n\n    static constexpr u32 LOGB = 6;\n\n    static constexpr std::array<u64,B>\
    \ MASK = []() {\n        std::array<u64,B> res;\n        res.fill(0);\n      \
    \  for (usize i = 1 ; i < B ; i++)\n            res[i] = res[i-1]|(1ull<<(i-1));\n\
    \        return res;\n    }();\n\npublic:\n\n    BitVector() = default;\n\n  \
    \  template <class T>\n    BitVector(std::vector<T> a) : m_n{a.size()}, m_dat((m_n+B-1)>>LOGB),\
    \ m_pref(m_dat.size()+1) {\n        for (usize i = 0 ; i < size() ; i++) {\n \
    \           u64 v = a[i]>0;\n            m_dat[i>>LOGB] |= v << (i & (B-1));\n\
    \            m_pref[(i>>LOGB)+1] += v;\n        }\n        for (usize i = 0 ;\
    \ i < m_dat.size() ; i++)\n            m_pref[i+1] += m_pref[i];\n    }\n\n  \
    \  inline usize size() const {\n        return m_n;\n    }\n\n    u32 rank1(usize\
    \ l,usize r) const {\n        return pref(r)-pref(l);\n    }\n\n    u32 rank0(usize\
    \ l,usize r) const {\n        return r-l-pref(r)+pref(l);\n    }\n\n    template<class\
    \ T>\n    T access(usize i) const {\n        return (m_dat[i>>LOGB] >> (i&(B-1)))\
    \ & 1;\n    }\n\nprivate:\n\n    usize m_n;\n\n    std::vector<u64> m_dat;\n\n\
    \    std::vector<u32> m_pref;\n\n    u32 pref(usize r) const {\n        const\
    \ usize q = r>>LOGB, b = r&(B-1);\n        return m_pref[q]+(b ? std::popcount<u64>(m_dat[q]&MASK[r&(B-1)])\
    \ : 0u);\n    }\n\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/PrefixSum/BitVector.hpp
  requiredBy:
  - Src/DataStructure/Wavelet/WaveletMatrix.hpp
  - Src/DataStructure/Wavelet/RectangleAggregation.hpp
  - Src/DataStructure/Wavelet/RangeAggregation.hpp
  timestamp: '2026-05-16 14:10:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc266_h.test.cpp
  - Test/AtCoder/abc339_g.test.cpp
  - Test/AOJ/3518.test.cpp
  - Test/LC/point_add_rectangle_sum/RectangleAggregation.test.cpp
  - Test/LC/range_kth_smallest/WaveletMatrix.test.cpp
  - Test/LC/rectangle_sum/RectangleAggregation.test.cpp
  - Test/My/DataStructure/Wavelet/WaveletMatrix.test.cpp
  - Test/My/DataStructure/PrefixSum/BitVector.test.cpp
documentation_of: Src/DataStructure/PrefixSum/BitVector.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/PrefixSum/BitVector.hpp
- /library/Src/DataStructure/PrefixSum/BitVector.hpp.html
title: Src/DataStructure/PrefixSum/BitVector.hpp
---
