---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/PrefixSum/BitVector.hpp
    title: Src/DataStructure/PrefixSum/BitVector.hpp
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
    path: Test/My/DataStructure/Wavelet/WaveletMatrix.test.cpp
    title: Test/My/DataStructure/Wavelet/WaveletMatrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/Wavelet/WaveletMatrix.hpp\"\n\n#line 2\
    \ \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\n\
    namespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/PrefixSum/BitVector.hpp\"\
    \n\n#line 4 \"Src/DataStructure/PrefixSum/BitVector.hpp\"\n\n#include <array>\n\
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
    \ : 0u);\n    }\n\n};\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/Wavelet/WaveletMatrix.hpp\"\
    \n\n#include <algorithm>\n#line 10 \"Src/DataStructure/Wavelet/WaveletMatrix.hpp\"\
    \n#include <tuple>\n#line 12 \"Src/DataStructure/Wavelet/WaveletMatrix.hpp\"\n\
    \nnamespace zawa {\n\ntemplate <std::integral T>\nclass WaveletMatrix {\npublic:\n\
    \n    WaveletMatrix() = default;\n\n    explicit WaveletMatrix(std::vector<T>\
    \ A) : m_n{A.size()}, m_h{1} {\n        for (T a : A) {\n            assert(a\
    \ >= 0);\n            m_h = std::max<usize>(m_h,std::bit_width<usize>(a));\n \
    \       }\n        m_sum.resize(height());\n        for (usize i = height() ;\
    \ i-- ; ) {\n            std::vector<T> left,right;\n            std::vector<u8>\
    \ dat(size());\n            for (usize j = 0 ; j < size() ; j++) {\n         \
    \       dat[j] = (A[j] >> i) & 1;\n                (dat[j] ? right : left).push_back(A[j]);\n\
    \            }\n            m_sum[i] = BitVector(std::move(dat));\n          \
    \  for (usize j = 0 ; T v : left)\n                A[j++] = v;\n            for\
    \ (usize j = left.size() ; T v : right)\n                A[j++] = v;\n       \
    \ }\n    }\n    \n    inline usize height() const {\n        return m_h;\n   \
    \ }\n\n    inline usize size() const {\n        return m_n;\n    }\n\n    T access(usize\
    \ i) const {\n        assert(i < size());\n        T res = 0;\n        for (usize\
    \ h = height() ; h-- ; ) {\n            res |= m_sum[h].access<T>(i) << h;\n \
    \           if (h) {\n                if (m_sum[h].access<bool>(i))\n        \
    \            i = m_sum[h].rank0(0,size())+m_sum[h].rank1(0,i);\n             \
    \   else\n                    i = m_sum[h].rank0(0,i);\n            }\n      \
    \  }\n        return res;\n    }\n\n    T get(usize i) const {\n        assert(i\
    \ < size());\n        return access(i);\n    }\n\n    T operator[](usize i) const\
    \ {\n        assert(i < size());\n        return access(i);\n    }\n\n    T quantile(usize\
    \ l,usize r,usize k) const {\n        assert(l <= r and r <= size());\n      \
    \  assert(k < r - l);\n        T res = 0;\n        for (usize h = height() ; h--\
    \ ; ) {\n            const u32 z = m_sum[h].rank0(l,r);\n            if (k < z)\
    \ {\n                if (h) {\n                    l = m_sum[h].rank0(0,l);\n\
    \                    r = l + z;\n                }\n            }\n          \
    \  else {\n                res |= T{1} << h;\n                k -= z;\n      \
    \          if (h) {\n                    usize ll = m_sum[h].rank0(0,size())+m_sum[h].rank1(0,l);\n\
    \                    r = ll + r - l - z;\n                    l = ll;\n      \
    \          }\n            }\n        }\n        return res;\n    }\n\n    T kthSmallest(usize\
    \ l,usize r,usize k) const {\n        assert(l <= r and r <= size());\n      \
    \  assert(k < r - l);\n        return quantile(l,r,k);\n    }\n\n    u32 frequency(usize\
    \ l,T d,usize r,T u) const {\n        assert(l <= r and r <= size());\n      \
    \  assert(0 <= d and d <= u);\n        return frequency(l,r,u)-frequency(l,r,d);\
    \ \n    }\n\nprotected:\n\n   usize m_n, m_h; \n\n   std::vector<BitVector> m_sum;\n\
    \n   u32 frequency(usize l,usize r,T d) const {\n        if (d >= (T{1} << height()))\n\
    \            return r - l;\n        u32 res = 0;\n        for (usize h = height()\
    \ ; h-- ; ) {\n            const u32 z = m_sum[h].rank0(l,r);\n            if\
    \ ((d >> h) & 1) {\n                res += z;\n                if (h) {\n    \
    \                usize ll = m_sum[h].rank0(0,size())+m_sum[h].rank1(0,l);\n  \
    \                  r = ll+r-l-z;\n                    l = ll;\n              \
    \  }\n            }\n            else if (h) {\n                l = m_sum[h].rank0(0,l);\n\
    \                r = l + z;\n            }\n        }\n        return res;\n \
    \  }\n\n};\n\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../PrefixSum/BitVector.hpp\"\
    \n\n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <concepts>\n\
    #include <tuple>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <std::integral\
    \ T>\nclass WaveletMatrix {\npublic:\n\n    WaveletMatrix() = default;\n\n   \
    \ explicit WaveletMatrix(std::vector<T> A) : m_n{A.size()}, m_h{1} {\n       \
    \ for (T a : A) {\n            assert(a >= 0);\n            m_h = std::max<usize>(m_h,std::bit_width<usize>(a));\n\
    \        }\n        m_sum.resize(height());\n        for (usize i = height() ;\
    \ i-- ; ) {\n            std::vector<T> left,right;\n            std::vector<u8>\
    \ dat(size());\n            for (usize j = 0 ; j < size() ; j++) {\n         \
    \       dat[j] = (A[j] >> i) & 1;\n                (dat[j] ? right : left).push_back(A[j]);\n\
    \            }\n            m_sum[i] = BitVector(std::move(dat));\n          \
    \  for (usize j = 0 ; T v : left)\n                A[j++] = v;\n            for\
    \ (usize j = left.size() ; T v : right)\n                A[j++] = v;\n       \
    \ }\n    }\n    \n    inline usize height() const {\n        return m_h;\n   \
    \ }\n\n    inline usize size() const {\n        return m_n;\n    }\n\n    T access(usize\
    \ i) const {\n        assert(i < size());\n        T res = 0;\n        for (usize\
    \ h = height() ; h-- ; ) {\n            res |= m_sum[h].access<T>(i) << h;\n \
    \           if (h) {\n                if (m_sum[h].access<bool>(i))\n        \
    \            i = m_sum[h].rank0(0,size())+m_sum[h].rank1(0,i);\n             \
    \   else\n                    i = m_sum[h].rank0(0,i);\n            }\n      \
    \  }\n        return res;\n    }\n\n    T get(usize i) const {\n        assert(i\
    \ < size());\n        return access(i);\n    }\n\n    T operator[](usize i) const\
    \ {\n        assert(i < size());\n        return access(i);\n    }\n\n    T quantile(usize\
    \ l,usize r,usize k) const {\n        assert(l <= r and r <= size());\n      \
    \  assert(k < r - l);\n        T res = 0;\n        for (usize h = height() ; h--\
    \ ; ) {\n            const u32 z = m_sum[h].rank0(l,r);\n            if (k < z)\
    \ {\n                if (h) {\n                    l = m_sum[h].rank0(0,l);\n\
    \                    r = l + z;\n                }\n            }\n          \
    \  else {\n                res |= T{1} << h;\n                k -= z;\n      \
    \          if (h) {\n                    usize ll = m_sum[h].rank0(0,size())+m_sum[h].rank1(0,l);\n\
    \                    r = ll + r - l - z;\n                    l = ll;\n      \
    \          }\n            }\n        }\n        return res;\n    }\n\n    T kthSmallest(usize\
    \ l,usize r,usize k) const {\n        assert(l <= r and r <= size());\n      \
    \  assert(k < r - l);\n        return quantile(l,r,k);\n    }\n\n    u32 frequency(usize\
    \ l,T d,usize r,T u) const {\n        assert(l <= r and r <= size());\n      \
    \  assert(0 <= d and d <= u);\n        return frequency(l,r,u)-frequency(l,r,d);\
    \ \n    }\n\nprotected:\n\n   usize m_n, m_h; \n\n   std::vector<BitVector> m_sum;\n\
    \n   u32 frequency(usize l,usize r,T d) const {\n        if (d >= (T{1} << height()))\n\
    \            return r - l;\n        u32 res = 0;\n        for (usize h = height()\
    \ ; h-- ; ) {\n            const u32 z = m_sum[h].rank0(l,r);\n            if\
    \ ((d >> h) & 1) {\n                res += z;\n                if (h) {\n    \
    \                usize ll = m_sum[h].rank0(0,size())+m_sum[h].rank1(0,l);\n  \
    \                  r = ll+r-l-z;\n                    l = ll;\n              \
    \  }\n            }\n            else if (h) {\n                l = m_sum[h].rank0(0,l);\n\
    \                r = l + z;\n            }\n        }\n        return res;\n \
    \  }\n\n};\n\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/PrefixSum/BitVector.hpp
  isVerificationFile: false
  path: Src/DataStructure/Wavelet/WaveletMatrix.hpp
  requiredBy:
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
documentation_of: Src/DataStructure/Wavelet/WaveletMatrix.hpp
layout: document
title: Wavelet Matrix
---

## ライブラリの使い方

```cpp
WaveletMatrix() = default;
explicit WaveletMatrix(std::vector<T> A);
```

`T`は`std::integral`である必要がある。`int`や`unsigned`、`long long`などが該当する

```
inline usize height() const;
inline usize size() const;
```

`size()`は`A`の要素数を返す(=内部の行列の列数)

`height()`は内部の行列の行数を返す

```
T access(usize i) const;
T get(usize i) const;
T operator[](usize i) const;
```

これらは全て`A[i]`を取得するメンバである。 $O(\log \max{A})$

```
T quantile(usize l,usize r,usize k) const
T kthSmallest(usize l,usize r,usize k) const
```

`A[l],A[l+1],...,A[r-1]`の中で`k`番目(0-indexed)に小さい値を返す。 $k\lt r-l$ が必要 $O(\log \max{A})$

```
u32 frequency(usize l,T d,usize r,T u)
```

$i=$ `l,l+1,...,r-1`の中で`A[i]`が $d$ 以上 $u$ 未満である $i$ の数を返す。 $O(\log \max{A})$

## 更新履歴

- 2026/05/16 作成
