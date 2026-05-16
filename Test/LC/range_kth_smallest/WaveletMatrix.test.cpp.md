---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/PrefixSum/BitVector.hpp
    title: Src/DataStructure/PrefixSum/BitVector.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Wavelet/WaveletMatrix.hpp
    title: Wavelet Matrix
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
  bundledCode: "#line 1 \"Test/LC/range_kth_smallest/WaveletMatrix.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#line 2 \"\
    Src/DataStructure/Wavelet/WaveletMatrix.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/DataStructure/PrefixSum/BitVector.hpp\"\n\
    \n#line 4 \"Src/DataStructure/PrefixSum/BitVector.hpp\"\n\n#include <array>\n\
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
    \  }\n\n};\n\n\n} // namespace zawa\n#line 4 \"Test/LC/range_kth_smallest/WaveletMatrix.test.cpp\"\
    \nusing namespace zawa;\n\n#include <iostream>\n#line 8 \"Test/LC/range_kth_smallest/WaveletMatrix.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n  \
    \  ios::sync_with_stdio(0);\n    int N,Q;\n    cin >> N >> Q;\n    vector<int>\
    \ A(N);\n    for (int& a : A)\n        cin >> a;\n    WaveletMatrix wav{move(A)};\n\
    \    while (Q--) {\n        int l,r,k;\n        cin >> l >> r >> k;\n        cout\
    \ << wav.kthSmallest(l,r,k) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../../../Src/DataStructure/Wavelet/WaveletMatrix.hpp\"\nusing namespace\
    \ zawa;\n\n#include <iostream>\n#include <vector>\nusing namespace std;\n\nint\
    \ main() {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N,Q;\n    cin >> N >> Q;\n    vector<int> A(N);\n    for (int& a : A)\n\
    \        cin >> a;\n    WaveletMatrix wav{move(A)};\n    while (Q--) {\n     \
    \   int l,r,k;\n        cin >> l >> r >> k;\n        cout << wav.kthSmallest(l,r,k)\
    \ << '\\n';\n    }\n}\n"
  dependsOn:
  - Src/DataStructure/Wavelet/WaveletMatrix.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/PrefixSum/BitVector.hpp
  isVerificationFile: true
  path: Test/LC/range_kth_smallest/WaveletMatrix.test.cpp
  requiredBy: []
  timestamp: '2026-05-16 14:10:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/range_kth_smallest/WaveletMatrix.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/range_kth_smallest/WaveletMatrix.test.cpp
- /verify/Test/LC/range_kth_smallest/WaveletMatrix.test.cpp.html
title: Test/LC/range_kth_smallest/WaveletMatrix.test.cpp
---
