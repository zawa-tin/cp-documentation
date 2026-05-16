---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/PrefixSum/BitVector.hpp
    title: Src/DataStructure/PrefixSum/BitVector.hpp
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
  bundledCode: "#line 1 \"Test/My/DataStructure/PrefixSum/BitVector.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"Src/DataStructure/PrefixSum/BitVector.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/PrefixSum/BitVector.hpp\"\
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
    \ : 0u);\n    }\n\n};\n\n} // namespace zawa\n#line 4 \"Test/My/DataStructure/PrefixSum/BitVector.test.cpp\"\
    \nusing namespace zawa;\n\n#include <iostream>\n#include <random>\nusing namespace\
    \ std;\n\nvoid test(vector<int> a) {\n    vector<int> sum(ssize(a)+1);\n    for\
    \ (int i = 0 ; i < ssize(a) ; i++)\n        sum[i+1] = sum[i]+a[i];\n    // cerr\
    \ << \"start: a=\";\n    // for (int i : a)\n    //     cerr << i << ' ';\n  \
    \  // cerr << endl;\n    BitVector pref(a);\n    for (int i = 0 ; i < ssize(a)\
    \ ; i++) \n        assert(a[i] == pref.access<int>(i));\n    for (int l = 0 ;\
    \ l < ssize(a) ; l++)\n        for (int r = l ; r <= ssize(a) ; r++) {\n     \
    \       // cerr << \"query: \" << l << ' ' << r << endl;\n            assert((int)pref.rank1(l,r)\
    \ == sum[r]-sum[l]);\n            assert((int)pref.rank0(l,r) == r-l-sum[r]+sum[l]);\n\
    \        }\n}\n\nint main() {\n    mt19937 mt{random_device{}()};\n    for (int\
    \ n = 1 ; n <= 300 ; n++) {\n        for (int t = 0 ; t < 5 ; t++) {\n       \
    \     vector<int> a(n);\n            for (int i = 0 ; i < n ; i++)\n         \
    \       a[i] = mt() % 2;\n            test(a);\n        }\n    }\n    int a,b;\n\
    \    cin >> a >> b;\n    cout << a+b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../../Src/DataStructure/PrefixSum/BitVector.hpp\"\nusing namespace zawa;\n\
    \n#include <iostream>\n#include <random>\nusing namespace std;\n\nvoid test(vector<int>\
    \ a) {\n    vector<int> sum(ssize(a)+1);\n    for (int i = 0 ; i < ssize(a) ;\
    \ i++)\n        sum[i+1] = sum[i]+a[i];\n    // cerr << \"start: a=\";\n    //\
    \ for (int i : a)\n    //     cerr << i << ' ';\n    // cerr << endl;\n    BitVector\
    \ pref(a);\n    for (int i = 0 ; i < ssize(a) ; i++) \n        assert(a[i] ==\
    \ pref.access<int>(i));\n    for (int l = 0 ; l < ssize(a) ; l++)\n        for\
    \ (int r = l ; r <= ssize(a) ; r++) {\n            // cerr << \"query: \" << l\
    \ << ' ' << r << endl;\n            assert((int)pref.rank1(l,r) == sum[r]-sum[l]);\n\
    \            assert((int)pref.rank0(l,r) == r-l-sum[r]+sum[l]);\n        }\n}\n\
    \nint main() {\n    mt19937 mt{random_device{}()};\n    for (int n = 1 ; n <=\
    \ 300 ; n++) {\n        for (int t = 0 ; t < 5 ; t++) {\n            vector<int>\
    \ a(n);\n            for (int i = 0 ; i < n ; i++)\n                a[i] = mt()\
    \ % 2;\n            test(a);\n        }\n    }\n    int a,b;\n    cin >> a >>\
    \ b;\n    cout << a+b << '\\n';\n}\n"
  dependsOn:
  - Src/DataStructure/PrefixSum/BitVector.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/My/DataStructure/PrefixSum/BitVector.test.cpp
  requiredBy: []
  timestamp: '2026-05-16 14:10:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/My/DataStructure/PrefixSum/BitVector.test.cpp
layout: document
redirect_from:
- /verify/Test/My/DataStructure/PrefixSum/BitVector.test.cpp
- /verify/Test/My/DataStructure/PrefixSum/BitVector.test.cpp.html
title: Test/My/DataStructure/PrefixSum/BitVector.test.cpp
---
