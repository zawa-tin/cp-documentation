---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/EnumeratePrimes.hpp
    title: Enumerate Primes
  - icon: ':heavy_check_mark:'
    path: Src/Number/EratosthenesSieve.hpp
    title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/My/Number/EnumeratePrimes.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\n\n#line\
    \ 2 \"Src/Number/EratosthenesSieve.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Number/EratosthenesSieve.hpp\"\n\n#include\
    \ <vector>\n#include <cassert>\n#include <algorithm>\n\nnamespace zawa {\n\nclass\
    \ EratosthenesSieve {\nprivate:\n    usize tableSize_;\n    std::vector<bool>\
    \ table_;\n\npublic:\n    EratosthenesSieve() = default;\n\n    EratosthenesSieve(usize\
    \ tableSize) : tableSize_{ tableSize + 1 }, table_(tableSize + 1, true) {\n  \
    \      table_.shrink_to_fit();\n        assert(tableSize_ > 0);\n        table_[0]\
    \ = table_[1] = false;\n        for (u64 i = 2 ; i * i < tableSize_ ; i++) {\n\
    \            if (!table_[i]) continue;\n            for (u64 j = i * i ; j < tableSize_\
    \ ; j += i ) {\n                table_[j] = false;\n            }\n        }\n\
    \    }\n\n    inline bool operator[](u32 i) const {\n        assert(i < tableSize_);\n\
    \        return table_[i];\n    }\n\n    inline bool isPrime(u32 i) const {\n\
    \        assert(i < tableSize_);\n        return table_[i];\n    }\n\n    inline\
    \ usize size() const {\n        return tableSize_ - 1;\n    }\n\n    std::vector<u32>\
    \ enumeratePrimes(u32 N) const {\n        assert(N < tableSize_);\n        std::vector<u32>\
    \ primes{};\n        primes.reserve(std::count(table_.begin(), table_.begin()\
    \ + N + 1, true));\n        for (u32 i = 2 ; i <= N ; i++) {\n            if (table_[i])\
    \ {\n                primes.emplace_back(i);\n            }\n        }\n     \
    \   return primes;\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/Number/EnumeratePrimes.hpp\"\
    \n\n#line 4 \"Src/Number/EnumeratePrimes.hpp\"\n\n#include <concepts>\n#line 7\
    \ \"Src/Number/EnumeratePrimes.hpp\"\n#include <bit>\n\nnamespace zawa {\n\ntemplate\
    \ <std::integral T>\nstd::vector<T> EnumeratePrimes(usize N) {\n    static constexpr\
    \ u32 p[]{2,3,5,7,11,13,17,19,23,29,31};\n    u32 w = 1;\n    usize m = 0;\n \
    \   for ( ; m < std::size(p) and static_cast<u64>(w) * w < N ; w *= p[m++]) ;\n\
    \    std::vector<u32> R = [&]() {\n        std::vector<bool> siv(w, true);\n \
    \       for (usize i = 0 ; i < m ; i++) {\n            for (u32 j = p[i] ; j <\
    \ w ; j += p[i]) siv[j] = false;\n        }\n        std::vector<u32> res{1};\n\
    \        for (u32 i = 2 ; i < w ; i++) if (siv[i]) res.push_back(i);\n       \
    \ return res;\n    }();\n    std::vector<T> res;\n    res.reserve(N / (std::bit_width(N)\
    \ + 1));\n    std::vector<u32> S;\n    S.reserve(N / 5u);\n    for (u32 kw = 0\
    \ ; kw <= N ; kw += w) {\n        for (u32 r = 0 ; r < R.size() and kw + R[r]\
    \ <= N ; r++) {\n            S.push_back(kw + R[r]);\n        }\n    }\n    for\
    \ (usize i = 0 ; i < m ; i++) res.push_back(static_cast<T>(p[i]));\n    std::vector<bool>\
    \ siv(N + 1, true);\n    for (usize i = 1 ; i < S.size() ; i++) if (siv[S[i]])\
    \ {\n        res.push_back(static_cast<T>(S[i])); \n        for (u32 j = i ; j\
    \ < S.size() ; j++) {\n            u64 p = static_cast<u64>(S[i]) * S[j];\n  \
    \          if (p > N) break;\n            siv[p] = false;\n        }\n    }\n\
    \    return res;\n}\n\n} // namespace zawa\n#line 5 \"Test/My/Number/EnumeratePrimes.test.cpp\"\
    \n\n#include <random>\n\nstd::vector<int> EratosEnumerate(int N) {\n    std::vector<int>\
    \ ans;\n    for (auto v : zawa::EratosthenesSieve(N).enumeratePrimes(N)) {\n \
    \       ans.push_back(static_cast<int>(v));\n    }\n    return ans;\n}\n\nbool\
    \ test(int N) {\n    return EratosEnumerate(N) == zawa::EnumeratePrimes<int>(N);\n\
    }\n\n#line 21 \"Test/My/Number/EnumeratePrimes.test.cpp\"\n#include <iostream>\n\
    #line 23 \"Test/My/Number/EnumeratePrimes.test.cpp\"\n\nint main() {\n    // small\n\
    \    for (int N = 1 ; N <= 500 ; N++) assert(test(N));\n    std::mt19937 mt{std::random_device{}()};\n\
    \    for (int t = 0 ; t < 15 ; t++) {\n        int N = mt() % (int)1e7 + 1;\n\
    \        assert(test(N));\n    }\n    std::cout << \"Hello World\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../../Src/Number/EratosthenesSieve.hpp\"\n#include \"../../../Src/Number/EnumeratePrimes.hpp\"\
    \n\n#include <random>\n\nstd::vector<int> EratosEnumerate(int N) {\n    std::vector<int>\
    \ ans;\n    for (auto v : zawa::EratosthenesSieve(N).enumeratePrimes(N)) {\n \
    \       ans.push_back(static_cast<int>(v));\n    }\n    return ans;\n}\n\nbool\
    \ test(int N) {\n    return EratosEnumerate(N) == zawa::EnumeratePrimes<int>(N);\n\
    }\n\n#include <cassert>\n#include <iostream>\n#include <random>\n\nint main()\
    \ {\n    // small\n    for (int N = 1 ; N <= 500 ; N++) assert(test(N));\n   \
    \ std::mt19937 mt{std::random_device{}()};\n    for (int t = 0 ; t < 15 ; t++)\
    \ {\n        int N = mt() % (int)1e7 + 1;\n        assert(test(N));\n    }\n \
    \   std::cout << \"Hello World\\n\";\n}\n"
  dependsOn:
  - Src/Number/EratosthenesSieve.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Number/EnumeratePrimes.hpp
  isVerificationFile: true
  path: Test/My/Number/EnumeratePrimes.test.cpp
  requiredBy: []
  timestamp: '2025-05-09 20:26:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/My/Number/EnumeratePrimes.test.cpp
layout: document
redirect_from:
- /verify/Test/My/Number/EnumeratePrimes.test.cpp
- /verify/Test/My/Number/EnumeratePrimes.test.cpp.html
title: Test/My/Number/EnumeratePrimes.test.cpp
---
