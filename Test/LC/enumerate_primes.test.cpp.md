---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"Test/LC/enumerate_primes.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/Number/EratosthenesSieve.hpp\"\n\n#line 4\
    \ \"Src/Number/EratosthenesSieve.hpp\"\n\n#include <vector>\n#include <cassert>\n\
    #include <algorithm>\n\nnamespace zawa {\n\nclass EratosthenesSieve {\nprivate:\n\
    \    usize tableSize;\n    std::vector<bool> table;\n\npublic:\n    EratosthenesSieve()\
    \ = default;\n\n    EratosthenesSieve(usize tableSize_) : tableSize{ tableSize_\
    \ + 1 }, table(tableSize_ + 1, true) {\n        assert(tableSize > 0);\n     \
    \   table[0] = table[1] = false;\n        for (u64 i = 2 ; i * i < tableSize ;\
    \ i++) {\n            if (!table[i]) continue;\n            for (u64 j = i * i\
    \ ; j < tableSize ; j += i ) {\n                table[j] = false;\n          \
    \  }\n        }\n    }\n\n    inline bool operator[](u32 i) const {\n        assert(i\
    \ < tableSize);\n        return table[i];\n    }\n\n    inline bool isPrime(u32\
    \ i) const {\n        assert(i < tableSize);\n        return table[i];\n    }\n\
    \n    inline usize size() const {\n        return tableSize - 1;\n    }\n\n  \
    \  std::vector<u32> enumeratePrimes(u32 N) const {\n        assert(N < tableSize);\n\
    \        std::vector<u32> primes{};\n        primes.reserve(std::count(table.begin(),\
    \ table.begin() + N + 1, true));\n        for (u32 i = 2 ; i <= N ; i++) {\n \
    \           if (table[i]) {\n                primes.emplace_back(i);\n       \
    \     }\n        }\n        return primes;\n    }\n};\n\n} // namespace zawa\n\
    #line 5 \"Test/LC/enumerate_primes.test.cpp\"\n\n#include <iostream>\n\nusing\
    \ namespace zawa;\n\nint main() {\n\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \n    u32 N, A, B;\n    std::cin >> N >> A >> B;\n\n    std::vector<u32> P = \n\
    \        EratosthenesSieve(N).enumeratePrimes(N);\n\n    std::vector<i32> ans{};\n\
    \    for (u32 i = B ; i < P.size() ; i += A) {\n        ans.push_back(P[i]);\n\
    \    }\n\n    std::cout << P.size() << ' ' << ans.size() << std::endl;\n    for\
    \ (u32 i = 0 ; i < ans.size() ; i++) {\n        std::cout << ans[i] << (i + 1\
    \ == ans.size() ? '\\n' : ' ');\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Number/EratosthenesSieve.hpp\"\
    \n\n#include <iostream>\n\nusing namespace zawa;\n\nint main() {\n\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n\n    u32 N, A, B;\n    std::cin >> N\
    \ >> A >> B;\n\n    std::vector<u32> P = \n        EratosthenesSieve(N).enumeratePrimes(N);\n\
    \n    std::vector<i32> ans{};\n    for (u32 i = B ; i < P.size() ; i += A) {\n\
    \        ans.push_back(P[i]);\n    }\n\n    std::cout << P.size() << ' ' << ans.size()\
    \ << std::endl;\n    for (u32 i = 0 ; i < ans.size() ; i++) {\n        std::cout\
    \ << ans[i] << (i + 1 == ans.size() ? '\\n' : ' ');\n    }\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Number/EratosthenesSieve.hpp
  isVerificationFile: true
  path: Test/LC/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2023-06-04 03:33:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/enumerate_primes.test.cpp
- /verify/Test/LC/enumerate_primes.test.cpp.html
title: Test/LC/enumerate_primes.test.cpp
---
