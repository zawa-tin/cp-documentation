---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/BitwiseXORConvolution.hpp
    title: Bitwise XOR Convolution
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
    - https://atcoder.jp/contests/abc396/submissions/66400307
    - https://atcoder.jp/contests/abc396/tasks/abc396_g
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc396_g.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc396/tasks/abc396_g\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 396 - G Flip Row or Col\n * https://atcoder.jp/contests/abc396/submissions/66400307\n\
    \ */\n\n#line 2 \"Src/Sequence/BitwiseXORConvolution.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Sequence/BitwiseXORConvolution.hpp\"\n\n\
    #include <bit>\n#include <concepts>\n#include <cassert>\n#include <vector>\n\n\
    namespace zawa {\n\n// note: \u8FD4\u308A\u5024\u306E\u5404\u70B9\u306E\u5024\u306F\
    \u771F\u306E\u5024\u3088\u308A(2^{k/2})\u500D\u3055\u308C\u3066\u3044\u308B\n\
    template <class T>\nvoid FastWalshHadamardTransform(std::vector<T>& A) {\n   \
    \ if (A.empty()) return;\n    while (!std::has_single_bit(A.size())) A.push_back(T{0});\n\
    \    const usize k = std::bit_width(A.size()) - 1, n = A.size();\n    for (usize\
    \ i = 0 ; i < k ; i++) {\n        const usize bit = 1 << i;\n        for (usize\
    \ j = 0 ; j < n ; j += bit << 1) {\n            for (usize k = 0 ; k < bit ; k++)\
    \ {\n                const T p = A[j + k], q = A[j + k + bit];\n             \
    \   A[j + k] = p + q;\n                A[j + k + bit] = p - q;\n            }\n\
    \        }\n    }\n}\n\ntemplate <class T>\nstd::vector<T> BitwiseXORConvolution(std::vector<T>\
    \ A, std::vector<T> B) {\n    FastWalshHadamardTransform(A);\n    FastWalshHadamardTransform(B);\n\
    \    if (A.size() > B.size()) std::swap(A, B);\n    for (usize i = 0 ; i < A.size()\
    \ ; i++) A[i] *= B[i];\n    FastWalshHadamardTransform(A);\n    if (A.empty())\
    \ return A;\n    assert(std::has_single_bit(A.size()));\n    if constexpr (std::integral<T>)\
    \ {\n        const usize d = std::bit_width(A.size()) - 1;\n        for (auto&\
    \ a : A) a >>= d;\n    }\n    else {\n        const T d = [&]() {\n          \
    \  assert(std::has_single_bit(A.size()));\n            usize exp = std::bit_width(A.size())\
    \ - 1;\n            T v = T{1} / T{2}, res = T{1};\n            while (exp) {\n\
    \                if (exp & 1) res = res * v;\n                v = v * v;\n   \
    \             exp >>= 1;\n            }\n            return res;\n        }();\n\
    \        for (T& a : A) a *= d;\n    }\n    return A;\n}\n\ntemplate <class T,\
    \ class U>\nrequires (!std::same_as<T, U> and std::convertible_to<U, T>)\nstd::vector<T>\
    \ BitwiseXORConvolution(std::vector<U> A, std::vector<U> B) {\n    std::vector<T>\
    \ a(A.size()), b(B.size());\n    for (usize i = 0 ; i < A.size() ; i++) a[i] =\
    \ static_cast<T>(std::move(A[i]));\n    for (usize i = 0 ; i < B.size() ; i++)\
    \ b[i] = static_cast<T>(std::move(B[i]));\n    return BitwiseXORConvolution<T>(a,\
    \ b);\n}\n\n} // namespace zawa\n#line 10 \"Test/AtCoder/abc396_g.test.cpp\"\n\
    \n#include <algorithm>\n#line 13 \"Test/AtCoder/abc396_g.test.cpp\"\n#include\
    \ <iostream>\n#include <string>\n#line 16 \"Test/AtCoder/abc396_g.test.cpp\"\n\
    #include <ranges>\n\nint main() {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n\
    \    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int H,\
    \ W;\n    std::cin >> H >> W;\n    std::vector<int> A(1 << W), B(1 << W);\n  \
    \  for (int i = 0 ; i < H ; i++) {\n        std::string S;\n        std::cin >>\
    \ S;\n        int v = 0;\n        for (int j = 0 ; j < W ; j++) if (S[j] == '1')\
    \ v |= 1 << j;\n        A[v]++;\n    }\n    for (int i = 0 ; i < (1 << W) ; i++)\
    \ {\n        const int cnt = std::popcount((unsigned)i);\n        B[i] = std::min(cnt,\
    \ W - cnt);\n    }\n    auto C = zawa::BitwiseXORConvolution<long long>(A, B);\n\
    \    std::cout << *std::ranges::min_element(C) << '\\n';\n#else\n    std::cout\
    \ << \"Hello World\\n\";\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc396/tasks/abc396_g\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 396 - G Flip Row or Col\n * https://atcoder.jp/contests/abc396/submissions/66400307\n\
    \ */\n\n#include \"../../Src/Sequence/BitwiseXORConvolution.hpp\"\n\n#include\
    \ <algorithm>\n#include <bit>\n#include <iostream>\n#include <string>\n#include\
    \ <vector>\n#include <ranges>\n\nint main() {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n\
    \    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int H,\
    \ W;\n    std::cin >> H >> W;\n    std::vector<int> A(1 << W), B(1 << W);\n  \
    \  for (int i = 0 ; i < H ; i++) {\n        std::string S;\n        std::cin >>\
    \ S;\n        int v = 0;\n        for (int j = 0 ; j < W ; j++) if (S[j] == '1')\
    \ v |= 1 << j;\n        A[v]++;\n    }\n    for (int i = 0 ; i < (1 << W) ; i++)\
    \ {\n        const int cnt = std::popcount((unsigned)i);\n        B[i] = std::min(cnt,\
    \ W - cnt);\n    }\n    auto C = zawa::BitwiseXORConvolution<long long>(A, B);\n\
    \    std::cout << *std::ranges::min_element(C) << '\\n';\n#else\n    std::cout\
    \ << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/Sequence/BitwiseXORConvolution.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc396_g.test.cpp
  requiredBy: []
  timestamp: '2025-06-02 16:41:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc396_g.test.cpp
layout: document
title: ABC396-G Flip Row or Col
---

$A_{i}$ の $i$ 行目を二進表記の整数だと思うことにする。この整数を $a_{i}$ とする。

解は $\min_{i=0}^{2^W-1}\\{\sum_{j = 1}^{H} \min\\{\text{popcnt}(a_j \oplus i), W - \text{popcnt}(a_j\oplus i)\\}\\}$ であるため、これを頑張って早く求めたい。

$a_{j}$ の頻度列を取り $c$ とする。目的の式は $c$ を用いて $\min_{i=0}^{2^W-1}\\{\sum_{j = 0}^{2^{W}-1} c_{j}\times \min\\{\text{popcnt}(j \oplus i), W - \text{popcnt}(j\oplus i)\\}\\}$ と表せる。

xor畳み込みの形になっているので、OK
