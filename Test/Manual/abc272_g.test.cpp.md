---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/Divisor.hpp
    title: "\u7D04\u6570\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/MajorityVote.hpp
    title: "Boyer-Moore\u306EMajority vote algorithm"
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
    - https://atcoder.jp/contests/abc272/submissions/50049939
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/Manual/abc272_g.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 272-G Yer Another mod M\n * https://atcoder.jp/contests/abc272/submissions/50049939\n\
    \ */\n\n#line 2 \"Src/Number/Divisor.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Number/Divisor.hpp\"\n\n#include <cassert>\n\
    #include <type_traits>\n#include <vector>\n\nnamespace zawa {\n\n// @remark: \u7D04\
    \u6570\u306F\u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\u306A\u3044\ntemplate <class\
    \ T>\nstd::vector<T> Divisor(T v) {\n    assert(v > static_cast<T>(0));\n    std::vector<T>\
    \ res;\n    for (T i{1} ; i * i <= v ; i++) {\n        if (v % i) continue;\n\
    \        res.emplace_back(i);\n        if (i * i != v) {\n            res.emplace_back(v\
    \ / i);\n        }\n    }\n    return res;\n}\n\n} // namespace zawa\n#line 2\
    \ \"Src/Sequence/MajorityVote.hpp\"\n\n#line 4 \"Src/Sequence/MajorityVote.hpp\"\
    \n\n#include <algorithm>\n#line 7 \"Src/Sequence/MajorityVote.hpp\"\n#include\
    \ <optional>\n#line 9 \"Src/Sequence/MajorityVote.hpp\"\n\nnamespace zawa {\n\n\
    template <class T, class InputIterator>\nstd::optional<T> MajorityVote(InputIterator\
    \ first, InputIterator last) {\n    static_assert(std::is_convertible_v<decltype(*first),\
    \ T>, \"InputIterator must be convertible T\");\n    assert(first != last);\n\
    \    std::optional<T> remain{}; \n    usize number{};\n    for (auto it{first}\
    \ ; it != last ; it++) {\n        if (number) {\n            if (remain.value()\
    \ == *it) {\n                number++;\n            }\n            else {\n  \
    \              number--;\n            }\n        }\n        else {\n         \
    \   remain = *it;\n            number++;\n        }\n    }\n    if (number and\
    \ 2u * std::count(first, last, remain.value()) > std::distance(first, last)) {\n\
    \        return remain;\n    }\n    else {\n        return std::nullopt;\n   \
    \ }\n}\n\n} // namespace zawa\n#line 10 \"Test/Manual/abc272_g.test.cpp\"\n\n\
    #line 12 \"Test/Manual/abc272_g.test.cpp\"\n#include <iostream>\n#include <iterator>\n\
    #line 15 \"Test/Manual/abc272_g.test.cpp\"\n\nint solve() {\n    using namespace\
    \ zawa;\n    int n; std::cin >> n;\n    std::vector<int> a(n);\n    for (auto&\
    \ x : a) std::cin >> x;\n    std::sort(a.begin(), a.end());\n    std::vector<int>\
    \ mod;\n    for (int i{} ; i < n ; i++) {\n        for (int x : Divisor(std::abs(a[i]\
    \ - a[(i + 1) % n]))) {\n            if (x < 3) continue;\n            mod.push_back(x);\n\
    \        }\n    }\n    std::sort(mod.begin(), mod.end());\n    auto m{std::distance(mod.begin(),\
    \ std::unique(mod.begin(), mod.end()))};\n    for (std::ptrdiff_t i{} ; i < m\
    \ ; i++) {\n        std::vector<int> b(n);\n        for (int j{} ; j < n ; j++)\
    \ b[j] = a[j] % mod[i];\n        if (MajorityVote<int>(b.begin(), b.end())) {\n\
    \            return mod[i];\n        }\n    }\n    return -1;\n}\n\nint main()\
    \ {\n#ifdef ATCODER\n    std::cout << solve() << '\\n';\n#else\n    std::cout\
    \ << \"Hello World\" << '\\n';\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 272-G Yer Another mod M\n * https://atcoder.jp/contests/abc272/submissions/50049939\n\
    \ */\n\n#include \"../../Src/Number/Divisor.hpp\"\n#include \"../../Src/Sequence/MajorityVote.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <iterator>\n#include <vector>\n\
    \nint solve() {\n    using namespace zawa;\n    int n; std::cin >> n;\n    std::vector<int>\
    \ a(n);\n    for (auto& x : a) std::cin >> x;\n    std::sort(a.begin(), a.end());\n\
    \    std::vector<int> mod;\n    for (int i{} ; i < n ; i++) {\n        for (int\
    \ x : Divisor(std::abs(a[i] - a[(i + 1) % n]))) {\n            if (x < 3) continue;\n\
    \            mod.push_back(x);\n        }\n    }\n    std::sort(mod.begin(), mod.end());\n\
    \    auto m{std::distance(mod.begin(), std::unique(mod.begin(), mod.end()))};\n\
    \    for (std::ptrdiff_t i{} ; i < m ; i++) {\n        std::vector<int> b(n);\n\
    \        for (int j{} ; j < n ; j++) b[j] = a[j] % mod[i];\n        if (MajorityVote<int>(b.begin(),\
    \ b.end())) {\n            return mod[i];\n        }\n    }\n    return -1;\n\
    }\n\nint main() {\n#ifdef ATCODER\n    std::cout << solve() << '\\n';\n#else\n\
    \    std::cout << \"Hello World\" << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Number/Divisor.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Sequence/MajorityVote.hpp
  isVerificationFile: true
  path: Test/Manual/abc272_g.test.cpp
  requiredBy: []
  timestamp: '2024-02-06 11:57:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Manual/abc272_g.test.cpp
layout: document
title: ABC172-G Yet Another mod M
---

$A$ にもともと過半数を占める要素が存在する場合、任意の $3$ 以上の整数が条件を満たす。

そうで無いとき、適切に $M$ を取ることで $A$ 内の相異なる $2$ 要素以上を操作によって等しくする必要がある。

そのような $M$ は $|A_{i} - A_{j}|$ の約数に限られる。 ( $A_{i}$ と $A_{j}$ は相異なるとする )

なぜなら $A_{i} \equiv A_{j} \pmod{M}\ \to\ A_{i} - A_{j} \equiv 0\pmod{M}$ だからである。

このような $M$ の候補は $O(N^{2}\log (\max A))$ 個ある。この候補をさらに絞ることを考える。

列を円環とみなす。すなわち $i$ 番目の要素と $(i + 1)\pmod{N}$ 番目の要素が隣り合っているとする。

この円環に過半数を占める要素が存在する場合、隣合う $2$ つの要素がその過半数を占める要素であるような位置が必ず存在する。 <- これ天才

以上より、 $|A_{i} - A_{i + 1}|$ の約数のみを調べればよく、 $M$ の候補は $O(N\log (\max A))$ 個となった。

Boyer-Moore majority vote algorithmのverifyの為にライブラリに収録したが、解法の方が興味深い...
