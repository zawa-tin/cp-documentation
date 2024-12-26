---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/InversionNumber.hpp
    title: Src/Sequence/InversionNumber.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
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
    PROBLEM: https://atcoder.jp/contests/abc296/tasks/abc296_f
    links:
    - https://atcoder.jp/contests/abc296/tasks/abc296_f
  bundledCode: "#line 1 \"Test/AtCoder/abc296_f.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc296/tasks/abc296_f\"\
    \n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Sequence/InversionNumber.hpp\"\n\n#line\
    \ 4 \"Src/Sequence/InversionNumber.hpp\"\n\n#include <cassert>\n#include <iterator>\n\
    #include <type_traits>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class\
    \ InputIterator>\nu64 InversionNumber(InputIterator first, InputIterator last)\
    \ {\n    assert((usize)std::distance(first, last) >= usize{0});\n    std::vector<std::remove_reference_t<decltype(*first)>>\
    \ A(first, last);\n    auto rec{[&](auto rec, usize L, usize R) -> u64 {\n   \
    \     if (R - L <= usize{1}) return 0; \n        usize M{(L + R) >> 1};\n    \
    \    u64 res{rec(rec, L, M) + rec(rec, M, R)};\n        std::vector<u64> tmp(R\
    \ - L);\n        usize i{L}, j{M}, k{};\n        while (i < M and j < R) {\n \
    \           if (A[i] <= A[j]) {\n                tmp[k++] = A[i++];\n        \
    \    }\n            else {\n                res += M - i;\n                tmp[k++]\
    \ = A[j++];\n            }\n        }\n        while (i < M) tmp[k++] = A[i++];\n\
    \        while (j < R) tmp[k++] = A[j++];\n        for (usize l{L} ; l < R ; l++)\
    \ {\n            A[l] = tmp[l - L];\n        }\n        return res;\n    }};\n\
    \    return rec(rec, usize{0}, usize{A.size()});\n}\n\ntemplate <class InputIterator>\n\
    bool InversionParity(InputIterator first, InputIterator last) {\n    assert((usize)std::distance(first,\
    \ last) >= usize{0});\n    std::vector<std::remove_reference_t<decltype(*first)>>\
    \ A(first, last);\n    auto rec{[&](auto rec, usize L, usize R) -> bool {\n  \
    \      if (R - L <= usize{1}) return 0; \n        usize M{(L + R) >> 1};\n   \
    \     bool res{rec(rec, L, M) != rec(rec, M, R)};\n        std::vector<u64> tmp(R\
    \ - L);\n        usize i{L}, j{M}, k{};\n        while (i < M and j < R) {\n \
    \           if (A[i] <= A[j]) {\n                tmp[k++] = A[i++];\n        \
    \    }\n            else {\n                res ^= (M - i) & 1;\n            \
    \    tmp[k++] = A[j++];\n            }\n        }\n        while (i < M) tmp[k++]\
    \ = A[i++];\n        while (j < R) tmp[k++] = A[j++];\n        for (usize l{L}\
    \ ; l < R ; l++) {\n            A[l] = tmp[l - L];\n        }\n        return\
    \ res;\n    }};\n    return rec(rec, usize{0}, usize{A.size()});\n}\n\n} // namespace\
    \ zawa\n#line 5 \"Test/AtCoder/abc296_f.test.cpp\"\n\n#line 8 \"Test/AtCoder/abc296_f.test.cpp\"\
    \n\nusing namespace zawa;\n\nint main() {\n    SetFastIO();\n    int N;\n    std::cin\
    \ >> N;\n    std::vector<int> A(N), B(N);\n    for (auto& x : A) {\n        std::cin\
    \ >> x;\n        x--;\n    }\n    for (auto& x : B) {\n        std::cin >> x;\n\
    \        x--;\n    }\n    // \u591A\u91CD\u96C6\u5408\u3068\u3057\u3066\u4E00\u81F4\
    \u3057\u3066\u3044\u308B\u304B\uFF1F\n    std::vector<int> cnt(N);\n    for (auto\
    \ x : A) cnt[x]++;\n    for (auto x : B) cnt[x]--;\n    for (int i{} ; i < N ;\
    \ i++) if (cnt[i]) {\n        std::cout << \"No\" << '\\n';\n        return 0;\n\
    \    }\n    // \u540C\u3058\u8981\u7D20\u304C\u542B\u307E\u308C\u3066\u3044\u308B\
    \u304B\uFF1F\n    for (auto x : A) cnt[x]++;\n    for (int i{} ; i < N ; i++)\
    \ if (cnt[i] > 1) {\n        std::cout << \"Yes\" << '\\n';\n        return 0;\n\
    \    }\n    // \u8EE2\u5012\u6570\u306E\u5076\u5947\n    bool ans{InversionParity(A.begin(),\
    \ A.end()) == InversionParity(B.begin(), B.end())};\n    std::cout << (ans ? \"\
    Yes\" : \"No\") << '\\n';\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc296/tasks/abc296_f\"\n\n\
    #include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Sequence/InversionNumber.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nusing namespace zawa;\n\nint main()\
    \ {\n    SetFastIO();\n    int N;\n    std::cin >> N;\n    std::vector<int> A(N),\
    \ B(N);\n    for (auto& x : A) {\n        std::cin >> x;\n        x--;\n    }\n\
    \    for (auto& x : B) {\n        std::cin >> x;\n        x--;\n    }\n    //\
    \ \u591A\u91CD\u96C6\u5408\u3068\u3057\u3066\u4E00\u81F4\u3057\u3066\u3044\u308B\
    \u304B\uFF1F\n    std::vector<int> cnt(N);\n    for (auto x : A) cnt[x]++;\n \
    \   for (auto x : B) cnt[x]--;\n    for (int i{} ; i < N ; i++) if (cnt[i]) {\n\
    \        std::cout << \"No\" << '\\n';\n        return 0;\n    }\n    // \u540C\
    \u3058\u8981\u7D20\u304C\u542B\u307E\u308C\u3066\u3044\u308B\u304B\uFF1F\n   \
    \ for (auto x : A) cnt[x]++;\n    for (int i{} ; i < N ; i++) if (cnt[i] > 1)\
    \ {\n        std::cout << \"Yes\" << '\\n';\n        return 0;\n    }\n    //\
    \ \u8EE2\u5012\u6570\u306E\u5076\u5947\n    bool ans{InversionParity(A.begin(),\
    \ A.end()) == InversionParity(B.begin(), B.end())};\n    std::cout << (ans ? \"\
    Yes\" : \"No\") << '\\n';\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Sequence/InversionNumber.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc296_f.test.cpp
  requiredBy: []
  timestamp: '2024-07-09 03:03:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc296_f.test.cpp
layout: document
title: "ABC296-F Simultaneous Swap (\u4E92\u63DB\u306F\u5947\u6570\u56DE\u306E\u96A3\
  \u63A5swap)"
---

長さ $N$ の数列 $A = (A_{1}, A_{2}, \dots, A_{N})$ の $L$ 番目の要素と $R$ 番目の要素をswapすることを考える。

これは $2(R - L - 1) + 1$ 回の隣接要素のswapで実現できる。

$A_{L}$ の要素を $A_{R}$ のところに運ぶのに $R - L$ 回のswap、現在 $A_{R}$ は $R - 1$ 番目にいて、これを $L$ 番目に運ぶのに $R - L - 1$ 回のswapを要する。

$2\times$ 整数 $+1$ の形で表現できる整数は奇数であることを思い出すと、以下が成り立つことがわかる。

**順列は互換( $L$ 番目の要素と $R$ 番目の要素をswapする)によって転倒数の偶奇が必ず入れ替わる**

<br />

この事実を利用してこの問題を解くことができる。 

$A, B$ が多重集合として一致していることを仮定する。

### $A$ がdistinctのとき

操作によって $A$ の転倒数の偶奇、 $B$ の転倒数の偶奇は必ず入れ替わる。すなわち $A$ の転倒数 - $B$ の転倒数の偶奇は不変である。

よって $A$ の転倒数の偶奇と $B$ の転倒数の偶奇が一致していることが必要だが、実は十分条件にもなっている。実際に操作列を構築することで示せるようだ。

### $A$ がdistinctでないとき

うまく $(i, j, k)$ を選ぶことで転倒数の偶奇すらずらせる。常にYes