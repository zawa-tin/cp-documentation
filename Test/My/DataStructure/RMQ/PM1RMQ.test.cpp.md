---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/RMQ/PM1RMQ.hpp
    title: Src/DataStructure/RMQ/PM1RMQ.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SparseTable/SparseTable.hpp
    title: Sparse Table
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
  bundledCode: "#line 1 \"Test/My/DataStructure/RMQ/PM1RMQ.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n#include <ostream>\n\nnamespace zawa\
    \ {\n\ntemplate <class Structure>\nclass SparseTable {\nprivate:\n    using Value\
    \ = typename Structure::Element;\n    std::vector<u32> L;\n    std::vector<std::vector<Value>>\
    \ dat;\npublic:\n\n    SparseTable() : L{}, dat{} {}\n    SparseTable(const std::vector<Value>&\
    \ a) : L(a.size() + 1), dat{} {\n        for (u32 i{1} ; i < L.size() ; i++) {\n\
    \            L[i] = L[i - 1] + (i >> (L[i - 1] + 1));\n        }\n        dat.resize(L.back()\
    \ + 1);\n        dat[0] = a;\n        for (u32 i{1}, len{2} ; i < dat.size() ;\
    \ i++, len <<= 1) {\n            dat[i] = dat[i - 1];\n            for (u32 j{}\
    \ ; j + len - 1 < dat[i].size() ; j++) {\n                dat[i][j] = Structure::operation(dat[i\
    \ - 1][j], dat[i - 1][j + (len >> 1)]);\n            }\n        }\n    }\n\n \
    \   Value product(u32 l, u32 r) const {\n        assert(l <= r);\n        assert(l\
    \ < dat[0].size());\n        assert(r <= dat[0].size());\n        u32 now{L[r\
    \ - l]};\n        return Structure::operation(dat[now][l], dat[now][r - (1 <<\
    \ now)]);\n    }\n\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ SparseTable<Structure>& spt) {\n        for (u32 i{}, len{1} ; i < spt.dat.size()\
    \ ; i++, len <<= 1) {\n            os << \"length = \" << len << '\\n';\n    \
    \        for (u32 j{} ; j + len - 1 < spt.dat[i].size() ; j++) {\n           \
    \     os << spt.dat[i][j] << (j + len == spt.dat[i].size() ? '\\n' : ' ');\n \
    \           }\n        }\n        return os;\n    }\n};\n\n} // namespace zawa\n\
    #line 2 \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\n\n#line 4 \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bit>\n#line 9 \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\
    \n#include <concepts>\n#include <utility>\n#line 12 \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\
    \n\n\nnamespace zawa {\n\ntemplate <std::totally_ordered T>\nclass PM1RMQ {\n\
    private:\n\n    static constexpr usize B = 8;\n\n    static constexpr usize BMASK\
    \ = 7;\n\n    static constexpr usize LOGB = 3;\n\n    static constexpr usize TRI\
    \ = B*(B+1)/2;\n\npublic:\n\n    PM1RMQ() = default;\n\n    PM1RMQ(std::vector<T>\
    \ a) \n        : m_n{a.size()}, m_inner{(a.size()+B-1)>>LOGB},\n        m_a{std::move(a)},\
    \ m_look(innerSize()), m_table(), m_spt(std::bit_width(innerSize()))\n    {\n\
    \        std::vector<u32> minIndex(innerSize());\n        std::vector<bool> registered(1u\
    \ << (B-1));\n        for (usize i = 0,idx = 0 ; i < size() ; idx++) {\n     \
    \       minIndex[idx] = i;\n            for (u8 j = 1 ; ++i < size() and j < (u8)B\
    \ ; j++) {\n                if (m_a[i] < m_a[minIndex[idx]])\n               \
    \     minIndex[idx] = i;\n                if (m_a[i] == m_a[i-1]+1)\n        \
    \            ;\n                else if (m_a[i] == m_a[i-1]-1)\n             \
    \       m_look[idx] |= u8{1} << (j-1);\n                else\n               \
    \     assert(!\"init table does not satisfy |a_i-a_{i+1}| = 1\");\n          \
    \  }\n            if (!registered[m_look[idx]]) {\n                registered[m_look[idx]]\
    \ = 1;\n                registerTable(m_look[idx]);\n            }\n        }\n\
    \        m_spt[0] = std::move(minIndex);\n        for (usize i = 1,len = 2 ; i\
    \ < m_spt.size() ; i++,len <<= 1) {\n            m_spt[i].resize(innerSize()-len+1);\n\
    \            for (usize j = 0 ; j < m_spt[i].size() ; j++) {\n               \
    \ u32 l = m_spt[i-1][j], r = m_spt[i-1][j+(len>>1)];\n                m_spt[i][j]\
    \ = m_a[r] < m_a[l] ? r : l;\n            }\n        }\n    }\n\n    inline usize\
    \ size() const {\n        return m_n;\n    }\n\n    // return leftmost index of\
    \ min{a[l],a[l+1],...,a[r-1]} (min of argmin)\n    // empty is not allowed\n \
    \   usize min(usize l,usize r) const {\n        assert(l < r and r <= size());\n\
    \        usize L = l>>LOGB, R = (r-1)>>LOGB;\n        if (L == R)\n          \
    \  return accessTable(L,l&BMASK,r-(L<<LOGB));\n        u32 res = accessTable(L,l&BMASK,B);\n\
    \        L++;\n        if (L < R) {\n            u32 pd = sptMin(L,R);\n     \
    \       if (m_a[pd] < m_a[res])\n                res = pd;\n        }\n      \
    \  u32 rv = accessTable(R,0u,r-(R<<LOGB));\n        if (m_a[rv] < m_a[res])\n\
    \            res = rv;\n        return static_cast<usize>(res);\n    }\n\n   \
    \ usize operator()(usize l,usize r) const {\n        return min(l,r);\n    }\n\
    \nprivate:\n\n    usize m_n,m_inner;\n\n    std::vector<T> m_a;\n\n    // 0..+1,1..-1\n\
    \    std::vector<u8> m_look;\n\n    std::array<u8,(1u << (B-1))*TRI> m_table;\n\
    \n    std::vector<std::vector<u32>> m_spt;\n\n    inline usize innerSize() const\
    \ {\n        return m_inner;\n    }\n\n    usize encode(usize l,usize r) const\
    \ {\n        // assert(l < r and r <= B);\n        static constexpr std::array<uint32_t,8>\
    \ Row{0,8,15,21,26,30,33,35};\n        return Row[l]+(r-l-1);\n    }\n\n    void\
    \ registerTable(usize info) {\n        const usize offset = TRI*info;\n      \
    \  std::vector<usize> val(B);\n        val[0] = B;\n        for (usize i = 0 ;\
    \ i + 1 < B ; i++) {\n            val[i+1] = val[i];\n            if (info & (1u\
    \ << i))\n                val[i+1]--;\n            else\n                val[i+1]++;\n\
    \        }\n        for (u8 l = 0 ; l < B ; l++) {\n            u8 mn = l;\n \
    \           for (u8 r = l ; r < B ; r++) {\n                if (val[mn] > val[r])\n\
    \                    mn = r;\n                m_table[offset+encode(l,r+1)] =\
    \ mn;\n            }\n        }\n    }\n\n    usize accessTable(usize idx,usize\
    \ l,usize r) const {\n        return (idx<<LOGB) + m_table[m_look[idx]*TRI+encode(l,r)];\n\
    \    }\n\n    u32 sptMin(usize l,usize r) const {\n        usize dep = std::bit_width(r-l)-1,\
    \ i = m_spt[dep][l], j = m_spt[dep][r-(1u<<dep)];\n        return m_a[j] < m_a[i]\
    \ ? j : i;\n    }\n};\n\n} // namespace zawa\n#line 5 \"Test/My/DataStructure/RMQ/PM1RMQ.test.cpp\"\
    \nusing namespace zawa;\n\n#line 8 \"Test/My/DataStructure/RMQ/PM1RMQ.test.cpp\"\
    \n#include <iostream>\n#include <random>\nusing namespace std;\nstruct MIN {\n\
    \    using Element = pair<int,int>;\n    static Element operation(const Element\
    \ l,const Element r) {\n        return r.first < l.first ? r : l;\n    }\n};\n\
    mt19937 mt{random_device{}()};\nvoid test(int N,int Q) {\n    cerr << \"test:\
    \ \" << N << ' ' << Q << endl;\n    vector<int> A(N);\n    vector<MIN::Element>\
    \ B(N);\n    A[0] = mt() % (int)1e9+1 + 1;\n    for (int i = 1 ; i < N ; i++)\n\
    \        A[i] = A[i-1] + (mt() % 2 ? 1 : -1);\n    for (int i = 0 ; i < N ; i++)\n\
    \        B[i] = {A[i],i};\n    PM1RMQ RMQ(A);\n    SparseTable<MIN> spt(B);\n\
    \    while (Q--) {\n        int l = mt() % N;\n        int r = mt() % N;\n   \
    \     if (l > r)\n            swap(l,r);\n        r++;\n        int you = RMQ(l,r);\n\
    \        int ans = spt.product(l,r).second;\n        assert(you == ans);\n   \
    \ }\n}\nint main() {\n    for (int n = 1 ; n <= 10 ; n++)\n        test(n,10);\n\
    \    test(100,200);\n    test(1000,2000);\n    test(200000,300000);\n    int a,b;\n\
    \    cin >> a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../../Src/DataStructure/SparseTable/SparseTable.hpp\"\n#include \"../../../../Src/DataStructure/RMQ/PM1RMQ.hpp\"\
    \nusing namespace zawa;\n\n#include <vector>\n#include <iostream>\n#include <random>\n\
    using namespace std;\nstruct MIN {\n    using Element = pair<int,int>;\n    static\
    \ Element operation(const Element l,const Element r) {\n        return r.first\
    \ < l.first ? r : l;\n    }\n};\nmt19937 mt{random_device{}()};\nvoid test(int\
    \ N,int Q) {\n    cerr << \"test: \" << N << ' ' << Q << endl;\n    vector<int>\
    \ A(N);\n    vector<MIN::Element> B(N);\n    A[0] = mt() % (int)1e9+1 + 1;\n \
    \   for (int i = 1 ; i < N ; i++)\n        A[i] = A[i-1] + (mt() % 2 ? 1 : -1);\n\
    \    for (int i = 0 ; i < N ; i++)\n        B[i] = {A[i],i};\n    PM1RMQ RMQ(A);\n\
    \    SparseTable<MIN> spt(B);\n    while (Q--) {\n        int l = mt() % N;\n\
    \        int r = mt() % N;\n        if (l > r)\n            swap(l,r);\n     \
    \   r++;\n        int you = RMQ(l,r);\n        int ans = spt.product(l,r).second;\n\
    \        assert(you == ans);\n    }\n}\nint main() {\n    for (int n = 1 ; n <=\
    \ 10 ; n++)\n        test(n,10);\n    test(100,200);\n    test(1000,2000);\n \
    \   test(200000,300000);\n    int a,b;\n    cin >> a >> b;\n    cout << a + b\
    \ << '\\n';\n}\n"
  dependsOn:
  - Src/DataStructure/SparseTable/SparseTable.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/RMQ/PM1RMQ.hpp
  isVerificationFile: true
  path: Test/My/DataStructure/RMQ/PM1RMQ.test.cpp
  requiredBy: []
  timestamp: '2026-04-20 16:41:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/My/DataStructure/RMQ/PM1RMQ.test.cpp
layout: document
redirect_from:
- /verify/Test/My/DataStructure/RMQ/PM1RMQ.test.cpp
- /verify/Test/My/DataStructure/RMQ/PM1RMQ.test.cpp.html
title: Test/My/DataStructure/RMQ/PM1RMQ.test.cpp
---
