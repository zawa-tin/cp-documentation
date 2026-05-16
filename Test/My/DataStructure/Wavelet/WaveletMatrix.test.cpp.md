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
    path: Src/Random/RandomArray.hpp
    title: Src/Random/RandomArray.hpp
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
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/My/DataStructure/Wavelet/WaveletMatrix.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"Src/DataStructure/Wavelet/WaveletMatrix.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
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
    \  }\n\n};\n\n\n} // namespace zawa\n#line 2 \"Src/Random/RandomArray.hpp\"\n\n\
    #line 4 \"Src/Random/RandomArray.hpp\"\n\n#line 9 \"Src/Random/RandomArray.hpp\"\
    \n#include <random>\n\nnamespace zawa {\n\nnamespace Random {\n\ntemplate <std::integral\
    \ T>\nstd::vector<T> Array(usize n, T min, T max, bool verify = true) {\n    assert(min\
    \ <= max);\n    std::mt19937_64 mt{std::random_device{}()};\n    std::vector<T>\
    \ res(n);\n    for (T& v : res) {\n        v = static_cast<T>(mt() % (max - min\
    \ + 1)) + min;\n    }\n    if (verify)\n        std::ranges::all_of(res, [&](T\
    \ v) { return min <= v and v <= max; });\n    return res;\n}\n\n} // namespace\
    \ Random\n\n} // namespace zawa\n#line 5 \"Test/My/DataStructure/Wavelet/WaveletMatrix.test.cpp\"\
    \nusing namespace zawa;\n\n#line 8 \"Test/My/DataStructure/Wavelet/WaveletMatrix.test.cpp\"\
    \n#include <chrono>\n#include <iostream>\n#line 11 \"Test/My/DataStructure/Wavelet/WaveletMatrix.test.cpp\"\
    \nusing namespace std;\n\nunsigned long long seed = random_device{}();\nmt19937\
    \ mt{seed};\n\ntemplate <class T>\nvoid accessTest(vector<T> A) {\n    WaveletMatrix\
    \ wav(A);\n    bool ok = 1;\n    for (int i = 0 ; i < ssize(A) ; i++)\n      \
    \  ok &= wav[i] == A[i];\n    if (!ok) {\n        cerr << ssize(A) << endl;\n\
    \        for (T a : A)\n            cerr << a << ' ';\n        cerr << endl;\n\
    \        for (int i = 0 ; i < ssize(A) ; i++)\n            cerr << wav[i] << '\
    \ ';\n        cerr << endl;\n        assert(0);\n    }\n}\n\ntemplate <class T,bool\
    \ time=false>\nvoid accessTest(int MAXN,T MAXA) {\n    int N = mt() % MAXN + 1;\n\
    \    vector<T> A = Random::Array<T>(N,0,MAXA);\n    if constexpr (time) {\n  \
    \      T mx = *ranges::max_element(A);\n        auto st = chrono::system_clock::now();\
    \ \n        accessTest(std::move(A));\n        auto en = chrono::system_clock::now();\n\
    \        auto t = chrono::duration_cast<chrono::milliseconds>(en-st).count();\n\
    \        cerr << \"N=\" << N << \",MAXA=\" << mx << \",time=\" << t << endl;\n\
    \    }\n    else\n        accessTest(std::move(A));\n}\n\ntemplate <class T>\n\
    void frequencyTest(std::vector<T> A,T MAXA) {\n    WaveletMatrix wav(A);\n   \
    \ for (int l = 0 ; l < ssize(A) ; l++)\n        for (int r = l ; r <= ssize(A)\
    \ ; r++) {\n            for (int t = 0 ; t < 3 ; t++) {\n                T d =\
    \ mt() % (MAXA + 1);\n                T u = mt() % (MAXA + 1);\n             \
    \   if (d > u)\n                    swap(d,u);\n                int v = wav.frequency(l,d,r,u);\n\
    \                int x = 0;\n                for (int i = l ; i < r ; i++)\n \
    \                   x += d <= A[i] and A[i] < u;\n                if (v != x)\
    \ {\n                    for (T a : A)\n                        cerr << a << '\
    \ ';\n                    cerr << endl;\n                    cerr << l << ' '\
    \ << r << ' ' << d << ' ' << u << endl;\n                    cerr << x << \" but\
    \ you \" << v << endl;\n                    assert(0);\n                }\n  \
    \          }\n        }\n}\n\ntemplate <class T>\nvoid frequencyTest(int MAXN,T\
    \ MAXA) {\n    int N = mt() % MAXN + 1;\n    vector<T> A = Random::Array<T>(N,0,MAXA);\n\
    \    frequencyTest(std::move(A),MAXA);\n}\n\nint main() {\n    cerr << \"seed=\"\
    \ << seed << endl;\n    for (int t = 0 ; t < 100 ; t++) {\n        int n = mt()\
    \ % 10 + 1;\n        int a = mt() % 10 + 1;\n        frequencyTest(n,a);\n   \
    \ }\n    frequencyTest<int>({0,6,0,2,5,6,5,3,1},9);\n    frequencyTest<int>(100,8);\n\
    \    frequencyTest<long long>(100,(long long)1e18);\n    cerr << \"frequencyTest:\
    \ pass\" << endl;\n    accessTest<int>({3,7,2,4});\n    for (int i = 0 ; i < 500\
    \ ; i++)\n        accessTest<int>(10,8);\n    accessTest<long long>({545377511343558464,487284146122142569,542554624957143677});\n\
    \    for (int i = 0 ; i < 500 ; i++)\n        accessTest<long long>(10,(long long)1e18);\n\
    \    accessTest<int>(200000,500000);\n    accessTest<int>(200000,500000);\n  \
    \  accessTest<long long>(200000,(long long)1e18);\n    accessTest<int,true>(200000,(int)1e9);\n\
    \    int a,b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../../Src/DataStructure/Wavelet/WaveletMatrix.hpp\"\n#include \"../../../../Src/Random/RandomArray.hpp\"\
    \nusing namespace zawa;\n\n#include <cassert>\n#include <chrono>\n#include <iostream>\n\
    #include <vector>\nusing namespace std;\n\nunsigned long long seed = random_device{}();\n\
    mt19937 mt{seed};\n\ntemplate <class T>\nvoid accessTest(vector<T> A) {\n    WaveletMatrix\
    \ wav(A);\n    bool ok = 1;\n    for (int i = 0 ; i < ssize(A) ; i++)\n      \
    \  ok &= wav[i] == A[i];\n    if (!ok) {\n        cerr << ssize(A) << endl;\n\
    \        for (T a : A)\n            cerr << a << ' ';\n        cerr << endl;\n\
    \        for (int i = 0 ; i < ssize(A) ; i++)\n            cerr << wav[i] << '\
    \ ';\n        cerr << endl;\n        assert(0);\n    }\n}\n\ntemplate <class T,bool\
    \ time=false>\nvoid accessTest(int MAXN,T MAXA) {\n    int N = mt() % MAXN + 1;\n\
    \    vector<T> A = Random::Array<T>(N,0,MAXA);\n    if constexpr (time) {\n  \
    \      T mx = *ranges::max_element(A);\n        auto st = chrono::system_clock::now();\
    \ \n        accessTest(std::move(A));\n        auto en = chrono::system_clock::now();\n\
    \        auto t = chrono::duration_cast<chrono::milliseconds>(en-st).count();\n\
    \        cerr << \"N=\" << N << \",MAXA=\" << mx << \",time=\" << t << endl;\n\
    \    }\n    else\n        accessTest(std::move(A));\n}\n\ntemplate <class T>\n\
    void frequencyTest(std::vector<T> A,T MAXA) {\n    WaveletMatrix wav(A);\n   \
    \ for (int l = 0 ; l < ssize(A) ; l++)\n        for (int r = l ; r <= ssize(A)\
    \ ; r++) {\n            for (int t = 0 ; t < 3 ; t++) {\n                T d =\
    \ mt() % (MAXA + 1);\n                T u = mt() % (MAXA + 1);\n             \
    \   if (d > u)\n                    swap(d,u);\n                int v = wav.frequency(l,d,r,u);\n\
    \                int x = 0;\n                for (int i = l ; i < r ; i++)\n \
    \                   x += d <= A[i] and A[i] < u;\n                if (v != x)\
    \ {\n                    for (T a : A)\n                        cerr << a << '\
    \ ';\n                    cerr << endl;\n                    cerr << l << ' '\
    \ << r << ' ' << d << ' ' << u << endl;\n                    cerr << x << \" but\
    \ you \" << v << endl;\n                    assert(0);\n                }\n  \
    \          }\n        }\n}\n\ntemplate <class T>\nvoid frequencyTest(int MAXN,T\
    \ MAXA) {\n    int N = mt() % MAXN + 1;\n    vector<T> A = Random::Array<T>(N,0,MAXA);\n\
    \    frequencyTest(std::move(A),MAXA);\n}\n\nint main() {\n    cerr << \"seed=\"\
    \ << seed << endl;\n    for (int t = 0 ; t < 100 ; t++) {\n        int n = mt()\
    \ % 10 + 1;\n        int a = mt() % 10 + 1;\n        frequencyTest(n,a);\n   \
    \ }\n    frequencyTest<int>({0,6,0,2,5,6,5,3,1},9);\n    frequencyTest<int>(100,8);\n\
    \    frequencyTest<long long>(100,(long long)1e18);\n    cerr << \"frequencyTest:\
    \ pass\" << endl;\n    accessTest<int>({3,7,2,4});\n    for (int i = 0 ; i < 500\
    \ ; i++)\n        accessTest<int>(10,8);\n    accessTest<long long>({545377511343558464,487284146122142569,542554624957143677});\n\
    \    for (int i = 0 ; i < 500 ; i++)\n        accessTest<long long>(10,(long long)1e18);\n\
    \    accessTest<int>(200000,500000);\n    accessTest<int>(200000,500000);\n  \
    \  accessTest<long long>(200000,(long long)1e18);\n    accessTest<int,true>(200000,(int)1e9);\n\
    \    int a,b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}\n"
  dependsOn:
  - Src/DataStructure/Wavelet/WaveletMatrix.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/PrefixSum/BitVector.hpp
  - Src/Random/RandomArray.hpp
  isVerificationFile: true
  path: Test/My/DataStructure/Wavelet/WaveletMatrix.test.cpp
  requiredBy: []
  timestamp: '2026-05-16 14:10:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/My/DataStructure/Wavelet/WaveletMatrix.test.cpp
layout: document
redirect_from:
- /verify/Test/My/DataStructure/Wavelet/WaveletMatrix.test.cpp
- /verify/Test/My/DataStructure/Wavelet/WaveletMatrix.test.cpp.html
title: Test/My/DataStructure/Wavelet/WaveletMatrix.test.cpp
---
