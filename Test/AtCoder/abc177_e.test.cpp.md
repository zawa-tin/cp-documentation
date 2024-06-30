---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/LinearSieve.hpp
    title: "\u7DDA\u5F62\u7BE9 (osa-k\u7D20\u56E0\u6570\u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: Src/Number/PrimeFactor.hpp
    title: Src/Number/PrimeFactor.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc177/tasks/abc177_e
    links:
    - https://atcoder.jp/contests/abc177/tasks/abc177_e
  bundledCode: "#line 1 \"Test/AtCoder/abc177_e.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc177/tasks/abc177_e\"\
    \n\n#line 2 \"Src/Number/LinearSieve.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/Number/PrimeFactor.hpp\"\n\n#line 4 \"Src/Number/PrimeFactor.hpp\"\
    \n\n#include <type_traits>\n\nnamespace zawa {\n\ntemplate <class T>\nclass PrimeFactor\
    \ {\n    static_assert(std::is_unsigned_v<T>, \"T must be unsigned integer\");\n\
    private:\n    T factor_{};\n    u32 exponent_{};\n\npublic: \n    PrimeFactor()\
    \ = default;\n\n    PrimeFactor(T factor, u32 exponent) : factor_{factor}, exponent_{exponent}\
    \ {}\n\n    inline T factor() const noexcept {\n        return factor_;\n    }\n\
    \n    inline u32 exponent() const noexcept {\n        return exponent_;\n    }\n\
    \n    friend bool operator<(const PrimeFactor<T>& lhs, const PrimeFactor<T>& rhs)\
    \ {\n        return lhs.factor() != rhs.factor() ?\n            lhs.factor() <\
    \ rhs.factor() :\n            lhs.exponent() < rhs.exponent();\n    }\n\n    friend\
    \ bool operator>(const PrimeFactor<T>& lhs, const PrimeFactor<T>& rhs) {\n   \
    \     return lhs.factor() != rhs.factor() ?\n            lhs.factor() > rhs.factor()\
    \ :\n            lhs.exponent() > rhs.exponent();\n    }\n};\n\n} // namespace\
    \ zawa\n#line 5 \"Src/Number/LinearSieve.hpp\"\n\n#include <vector>\n#include\
    \ <utility>\n#include <cassert>\n\nnamespace zawa {\n\nclass LinearSieve {\npublic:\n\
    \    using V = u32;\n    using F = PrimeFactor<V>;\nprivate:\n    std::vector<V>\
    \ primes_;\n    std::vector<V> lpf_;\npublic:\n    LinearSieve(V n) : primes_{},\
    \ lpf_(n + 1) {\n        for (V i{2} ; i <= n ; i++) {\n            if (!lpf_[i])\
    \ {\n                lpf_[i] = i;\n                primes_.emplace_back(i);\n\
    \            }\n            for (V p : primes_) {\n                if (static_cast<u64>(p)\
    \ * i > n) break;\n                lpf_[p * i] = p;\n            }\n        }\n\
    \    }\n\n    V size() const noexcept {\n        return static_cast<V>(lpf_.size())\
    \ - 1;\n    }\n\n    bool isPrime(V x) const noexcept {\n        assert(x < lpf_.size());\n\
    \        return lpf_[x] == x;\n    }\n\n    bool operator[](V x) const noexcept\
    \ {\n        assert(x < lpf_.size());\n        return lpf_[x] == x;\n    }\n\n\
    \    std::vector<V> primes() const {\n        return primes_;\n    }\n\n    //\
    \ @note: response array is not sorted.\n    std::vector<u32> divisor(V x) const\
    \ {\n        assert(0u < x and x < lpf_.size());\n        std::vector<V> res(1,\
    \ 1u);\n        while (x > 1) {\n            V factor{lpf_[x]};\n            u32\
    \ exponent{};\n            while (lpf_[x] == factor) {\n                exponent++;\n\
    \                x /= lpf_[x];\n            }\n            usize line{res.size()};\n\
    \            V now{1};\n            for (u32 i{} ; i < exponent ; i++) {\n   \
    \             now *= factor;\n                for (usize j{} ; j < line ; j++)\
    \ {\n                    res.emplace_back(res[j] * now);\n                }\n\
    \            }\n        }\n        return res;\n    }\n\n    std::vector<F> factorize(V\
    \ x) const {\n        assert(0u < x and x < lpf_.size());\n        std::vector<F>\
    \ res;\n        while (x > 1) {\n            V factor{lpf_[x]};\n            u32\
    \ exponent{};\n            while (lpf_[x] == factor) {\n                exponent++;\n\
    \                x /= lpf_[x];\n            }\n            res.emplace_back(factor,\
    \ exponent);\n        }\n        return res;\n    }\n};\n\n} // namespace zawa\n\
    #line 4 \"Test/AtCoder/abc177_e.test.cpp\"\n\n#include <iostream>\n#include <numeric>\n\
    #include <unordered_set>\n\nconst int N{ 1000100 };\n\nint main() {\n    int n;\
    \ std::cin >> n;\n    zawa::LinearSieve siv(N);\n    int setGCD{};\n    std::unordered_set<int>\
    \ divisors;\n    bool pairwise{true};\n    for (int _{} ; _ < n ; _++) {\n   \
    \     int a; std::cin >> a;\n        setGCD = std::gcd(setGCD, a);\n        for\
    \ (auto p : siv.factorize(a)) if (p.factor() > 1) {\n            pairwise &= divisors.find(p.factor())\
    \ == divisors.end();\n            divisors.emplace(p.factor());\n        }\n \
    \   }\n    if (pairwise) {\n        std::cout << \"pairwise coprime\" << std::endl;\n\
    \    }\n    else if (setGCD == 1) {\n        std::cout << \"setwise coprime\"\
    \ << std::endl;\n    }\n    else {\n        std::cout << \"not coprime\" << std::endl;\n\
    \    }\n\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc177/tasks/abc177_e\"\n\n\
    #include \"../../Src/Number/LinearSieve.hpp\"\n\n#include <iostream>\n#include\
    \ <numeric>\n#include <unordered_set>\n\nconst int N{ 1000100 };\n\nint main()\
    \ {\n    int n; std::cin >> n;\n    zawa::LinearSieve siv(N);\n    int setGCD{};\n\
    \    std::unordered_set<int> divisors;\n    bool pairwise{true};\n    for (int\
    \ _{} ; _ < n ; _++) {\n        int a; std::cin >> a;\n        setGCD = std::gcd(setGCD,\
    \ a);\n        for (auto p : siv.factorize(a)) if (p.factor() > 1) {\n       \
    \     pairwise &= divisors.find(p.factor()) == divisors.end();\n            divisors.emplace(p.factor());\n\
    \        }\n    }\n    if (pairwise) {\n        std::cout << \"pairwise coprime\"\
    \ << std::endl;\n    }\n    else if (setGCD == 1) {\n        std::cout << \"setwise\
    \ coprime\" << std::endl;\n    }\n    else {\n        std::cout << \"not coprime\"\
    \ << std::endl;\n    }\n\n}\n"
  dependsOn:
  - Src/Number/LinearSieve.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Number/PrimeFactor.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc177_e.test.cpp
  requiredBy: []
  timestamp: '2024-06-30 19:07:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc177_e.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc177_e.test.cpp
- /verify/Test/AtCoder/abc177_e.test.cpp.html
title: Test/AtCoder/abc177_e.test.cpp
---
