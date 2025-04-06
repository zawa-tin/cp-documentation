---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/PermutationSwapSort.hpp
    title: "Permutation\u3092 $N-1$ \u56DE\u4EE5\u4E0B\u306Eswap\u3067\u30BD\u30FC\
      \u30C8\u3059\u308B"
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
    - https://atcoder.jp/contests/abc350/submissions/64587344
    - https://atcoder.jp/contests/abc350/tasks/abc350_c
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc350_c.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/abc350/tasks/abc350_c\"\n\n\
    /*\n * AtCoder Beginner Contest 350 C - Sort\n * https://atcoder.jp/contests/abc350/submissions/64587344\n\
    \ */\n\n#line 2 \"Src/Sequence/PermutationSwapSort.hpp\"\n\n#include <cassert>\n\
    #include <concepts>\n#include <iterator>\n#include <utility>\n#include <vector>\n\
    \n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 10 \"Src/Sequence/PermutationSwapSort.hpp\"\
    \n\nnamespace zawa {\n\nnamespace internal {\n\n// Is A permutation of (0,1,...,|A|-1)\
    \ ?\ntemplate <std::integral T>\nbool IsPermutation(const std::vector<T>& A) {\n\
    \    std::vector<bool> app(A.size());\n    for (T v : A) {\n        if (v < 0\
    \ or v >= (T)A.size()) return false;\n        if (app[v]) return false;\n    \
    \    app[v] = true;\n    }\n    return true;\n}\n\n} // namespace internal\n\n\
    template <std::input_iterator It>\nstd::vector<std::pair<usize, usize>> PermutationSwapSort(It\
    \ first, It last) {\n    std::vector P(first, last);\n    assert(internal::IsPermutation(P));\n\
    \    std::vector<std::pair<usize, usize>> res;\n    for (usize i = 0 ; i < P.size()\
    \ ; i++) while ((usize)P[i] != i) {\n        res.push_back({i, P[i]});\n     \
    \   std::swap(P[i], P[P[i]]);\n    }\n    return res;\n}\n\n} // namespace zawa\n\
    #line 10 \"Test/AtCoder/abc350_c.test.cpp\"\n\n#include <iostream>\n#line 13 \"\
    Test/AtCoder/abc350_c.test.cpp\"\nint N, A[200020];\nint main() {\n#ifdef ATCODER\n\
    \    std::cin >> N;\n    for (int i = 0 ; i < N ; i++) {\n        std::cin >>\
    \ A[i];\n        A[i]--;\n    }\n    auto ans = zawa::PermutationSwapSort(A, A\
    \ + N);\n    std::cout << ans.size() << '\\n';\n    for (auto [i, j] : ans) std::cout\
    \ << i + 1 << ' ' << j + 1 << '\\n';\n#else\n    std::cout << \"Hello World\\\
    n\";\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/abc350/tasks/abc350_c\"\n\n\
    /*\n * AtCoder Beginner Contest 350 C - Sort\n * https://atcoder.jp/contests/abc350/submissions/64587344\n\
    \ */\n\n#include \"../../Src/Sequence/PermutationSwapSort.hpp\"\n\n#include <iostream>\n\
    #include <vector>\nint N, A[200020];\nint main() {\n#ifdef ATCODER\n    std::cin\
    \ >> N;\n    for (int i = 0 ; i < N ; i++) {\n        std::cin >> A[i];\n    \
    \    A[i]--;\n    }\n    auto ans = zawa::PermutationSwapSort(A, A + N);\n   \
    \ std::cout << ans.size() << '\\n';\n    for (auto [i, j] : ans) std::cout <<\
    \ i + 1 << ' ' << j + 1 << '\\n';\n#else\n    std::cout << \"Hello World\\n\"\
    ;\n#endif\n}\n"
  dependsOn:
  - Src/Sequence/PermutationSwapSort.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc350_c.test.cpp
  requiredBy: []
  timestamp: '2025-04-06 19:32:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc350_c.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc350_c.test.cpp
- /verify/Test/AtCoder/abc350_c.test.cpp.html
title: Test/AtCoder/abc350_c.test.cpp
---
