---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/PrefixSum/BitVector.hpp
    title: Src/DataStructure/PrefixSum/BitVector.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Wavelet/RangeAggregation.hpp
    title: Range Aggregation
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Wavelet/WaveletMatrix.hpp
    title: Wavelet Matrix
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/CompressedSequence.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/abc339/submissions/75815845
    - https://atcoder.jp/contests/abc339/tasks/abc339_g
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/AtCoder/abc339_g.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc339/tasks/abc339_g\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n/*\n * AtCoder Beginner Contest 339 G - Smaller Sum\n * https://atcoder.jp/contests/abc339/submissions/75815845\n\
    \ */\n\n#line 2 \"Src/DataStructure/Wavelet/RangeAggregation.hpp\"\n\n#line 2\
    \ \"Src/DataStructure/Wavelet/WaveletMatrix.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
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
    \  }\n\n};\n\n\n} // namespace zawa\n#line 2 \"Src/Sequence/CompressedSequence.hpp\"\
    \n\n#line 4 \"Src/Sequence/CompressedSequence.hpp\"\n\n#line 8 \"Src/Sequence/CompressedSequence.hpp\"\
    \n#include <iterator>\n#include <limits>\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nclass CompressedSequence {\npublic:\n\n    static constexpr u32 NotFound\
    \ = std::numeric_limits<u32>::max();\n\n    CompressedSequence() = default;\n\n\
    \    template <class InputIterator>\n    CompressedSequence(InputIterator first,\
    \ InputIterator last) : comped_(first, last), f_{} {\n        std::sort(comped_.begin(),\
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
    \    template <std::integral Z>\n    std::vector<Z> mapped() const {\n       \
    \ if constexpr (std::same_as<u32,Z>)\n            return f_;\n        else {\n\
    \            std::vector<Z> res(f_.size());\n            for (usize i = 0 ; i\
    \ < f_.size() ; i++)\n                res[i] = static_cast<Z>(f_[i]);\n      \
    \      return res;\n        }\n    }\n\nprivate:\n\n    std::vector<T> comped_;\n\
    \n    std::vector<u32> f_;\n\n};\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/Wavelet/RangeAggregation.hpp\"\
    \n\n#line 7 \"Src/DataStructure/Wavelet/RangeAggregation.hpp\"\n#include <numeric>\n\
    #include <ranges>\n#include <utility>\n\nnamespace zawa {\n\ntemplate <std::integral\
    \ T>\nclass RangeAggregation : public WaveletMatrix<u32> {\nprivate:\n\n    using\
    \ WaveletMatrix<u32>::m_sum;\n\npublic:\n\n    using WaveletMatrix<u32>::size;\n\
    \    using WaveletMatrix<u32>::height;\n    using WaveletMatrix<u32>::access;\n\
    \    using WaveletMatrix<u32>::quantile;\n    using WaveletMatrix<u32>::frequency;\n\
    \n    RangeAggregation() = default;\n\n    explicit RangeAggregation(std::vector<T>\
    \ A) : WaveletMatrix<u32>(compressed(A)), m_comp{std::move(A)} {}\n\n    std::vector<std::pair<usize,usize>>\
    \ point(usize i) const {\n        std::vector<std::pair<usize,usize>> res(height());\n\
    \        for (usize h = height() ; h-- ; ) {\n            if (m_sum[h].template\
    \ access<bool>(i))\n                i = m_sum[h].rank0(0,size())+m_sum[h].rank1(0,i);\n\
    \            else\n                i = m_sum[h].rank0(0,i);\n            res[h]\
    \ = {h,i};\n        }\n        return res;\n    }\n\n    std::vector<std::tuple<usize,usize,usize>>\
    \ rectangle(usize l,T d,usize r,T u) const {\n        assert(l <= r and r <= size());\n\
    \        assert(d <= u);\n        std::vector<std::tuple<usize,usize,usize>> res;\
    \       \n        dfs(height()-1,l,r,m_comp[d],m_comp[u],T{0},T{1}<<height(),res);\n\
    \        return res;\n    }\n\n    u32 count(usize l,T d,usize r,T u) const {\n\
    \        assert(l <= r and r <= size());\n        assert(d <= u);\n        return\
    \ frequency(l,m_comp[d],r,m_comp[u]);\n    }\n\nprivate:\n\n    static std::vector<u32>\
    \ compressed(std::vector<T> a) {\n        auto b = a;\n        std::ranges::sort(b);\n\
    \        b.erase(std::unique(b.begin(),b.end()),b.end());\n        std::vector<u32>\
    \ res(a.size());\n        for (usize i = 0 ; i < a.size() ; i++)\n           \
    \ res[i] = std::ranges::lower_bound(b,a[i])-b.begin();\n        return res;\n\
    \    }\n\n    CompressedSequence<T> m_comp;\n\n    void dfs(usize h,usize l,usize\
    \ r,T d,T u,T D,T U,std::vector<std::tuple<usize,usize,usize>>& res) const {\n\
    \        if (u <= D or U <= d or l == r)\n            return;\n        const T\
    \ mid = D + (T{1} << h);\n        const u32 o = m_sum[h].rank1(l,r),z = r - l\
    \ - o;\n        const usize zeroL = m_sum[h].rank0(0,l),zeroR = zeroL+z;\n   \
    \     const usize oneL = m_sum[h].rank0(0,size())+m_sum[h].rank1(0,l),oneR = oneL+o;\n\
    \        if (d <= D and mid <= u and zeroL < zeroR)\n            res.emplace_back(h,zeroL,zeroR);\n\
    \        else if (h)\n            dfs(h-1,zeroL,zeroR,d,u,D,mid,res);\n      \
    \  if (d <= mid and U <= u and oneL < oneR)\n            res.emplace_back(h,oneL,oneR);\n\
    \        else if (h)\n            dfs(h-1,oneL,oneR,d,u,mid,U,res);\n    }\n\n\
    };\n\n} // namespace zawa\n#line 9 \"Test/AtCoder/abc339_g.test.cpp\"\nusing namespace\
    \ zawa;\n#include <iostream>\nusing namespace std;\nint main() {\n#ifdef ATCODER\n\
    \    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N;\n\
    \    cin >> N;\n    vector<int> A(N);\n    for (auto& x : A)\n        cin >> x;\n\
    \    RangeAggregation<int> RA{A}; \n    vector sum(RA.height(),vector<long long>(N+1));\n\
    \    for (int i = 0 ; i < N ; i++) {\n        for (auto [x,y] : RA.point(i))\n\
    \            sum[x][y+1] += A[i];\n    }\n    for (int i = 0 ; i < (int)RA.height()\
    \ ; i++)\n        for (int j = 0 ; j < N ; j++)\n            sum[i][j+1] += sum[i][j];\n\
    \    int Q;\n    cin >> Q;\n    long long B = 0;\n    while (Q--) {\n        long\
    \ long al,be,ga;\n        cin >> al >> be >> ga;\n        al ^= B;\n        be\
    \ ^= B;\n        ga ^= B;\n        al--;\n        long long ans = 0;\n       \
    \ for (auto [h,l,r] : RA.rectangle(al,0,be,ga+1))\n            ans += sum[h][r]-sum[h][l];\n\
    \        cout << ans << '\\n';\n        B = ans;\n    }\n#else\n    int a,b;\n\
    \    cin >> a >> b;\n    cout << a+b << '\\n';\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc339/tasks/abc339_g\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n/*\n * AtCoder Beginner\
    \ Contest 339 G - Smaller Sum\n * https://atcoder.jp/contests/abc339/submissions/75815845\n\
    \ */\n\n#include \"../../Src/DataStructure/Wavelet/RangeAggregation.hpp\"\nusing\
    \ namespace zawa;\n#include <iostream>\nusing namespace std;\nint main() {\n#ifdef\
    \ ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n \
    \   int N;\n    cin >> N;\n    vector<int> A(N);\n    for (auto& x : A)\n    \
    \    cin >> x;\n    RangeAggregation<int> RA{A}; \n    vector sum(RA.height(),vector<long\
    \ long>(N+1));\n    for (int i = 0 ; i < N ; i++) {\n        for (auto [x,y] :\
    \ RA.point(i))\n            sum[x][y+1] += A[i];\n    }\n    for (int i = 0 ;\
    \ i < (int)RA.height() ; i++)\n        for (int j = 0 ; j < N ; j++)\n       \
    \     sum[i][j+1] += sum[i][j];\n    int Q;\n    cin >> Q;\n    long long B =\
    \ 0;\n    while (Q--) {\n        long long al,be,ga;\n        cin >> al >> be\
    \ >> ga;\n        al ^= B;\n        be ^= B;\n        ga ^= B;\n        al--;\n\
    \        long long ans = 0;\n        for (auto [h,l,r] : RA.rectangle(al,0,be,ga+1))\n\
    \            ans += sum[h][r]-sum[h][l];\n        cout << ans << '\\n';\n    \
    \    B = ans;\n    }\n#else\n    int a,b;\n    cin >> a >> b;\n    cout << a+b\
    \ << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/DataStructure/Wavelet/RangeAggregation.hpp
  - Src/DataStructure/Wavelet/WaveletMatrix.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/PrefixSum/BitVector.hpp
  - Src/Sequence/CompressedSequence.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc339_g.test.cpp
  requiredBy: []
  timestamp: '2026-05-16 14:53:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc339_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc339_g.test.cpp
- /verify/Test/AtCoder/abc339_g.test.cpp.html
title: Test/AtCoder/abc339_g.test.cpp
---
