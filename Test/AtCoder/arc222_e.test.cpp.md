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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/arc222/submissions/80251457
    - https://atcoder.jp/contests/arc222/tasks/arc222_e
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/AtCoder/arc222_e.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/arc222/tasks/arc222_e\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n/*\n * AtCoder Regular Contest 222 E - XOR Matching\n * https://atcoder.jp/contests/arc222/submissions/80251457\n\
    \ */\n#line 2 \"Src/Sequence/BitwiseXORConvolution.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Sequence/BitwiseXORConvolution.hpp\"\n\n\
    #include <bit>\n#include <concepts>\n#include <cassert>\n#include <vector>\n\n\
    namespace zawa {\n\n// note: each values are multed by 2^{k/2} than truth value\n\
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
    \ b[i] = static_cast<T>(std::move(B[i]));\n    return BitwiseXORConvolution<T>(std::move(a),\
    \ std::move(b));\n}\n\ntemplate <class T>\nstd::vector<T> BitwiseXORConvolutionPower(std::vector<T>\
    \ A,usize K) {\n    FastWalshHadamardTransform(A);\n    auto mypow=[K](T x) ->\
    \ T {\n        T res = 1;\n        for (usize k = K ; k ; k >>= 1) {\n       \
    \     if (k & 1)\n                res *= x;\n            if (k > 1)\n        \
    \        x *= x;\n        }\n        return res;\n    };\n    for (usize i = 0\
    \ ; i < A.size() ; i++)\n        A[i] = mypow(A[i]);\n    FastWalshHadamardTransform(A);\n\
    \    if (A.empty()) \n        return A;\n    assert(std::has_single_bit(A.size()));\n\
    \    if constexpr (std::integral<T>) {\n        const usize d = std::bit_width(A.size())\
    \ - 1;\n        for (auto& a : A) \n            a >>= d;\n    }\n    else {\n\
    \        const T d = [&]() {\n            assert(std::has_single_bit(A.size()));\n\
    \            usize exp = std::bit_width(A.size()) - 1;\n            T v = T{1}\
    \ / T{2}, res = T{1};\n            while (exp) {\n                if (exp & 1)\
    \ \n                    res = res * v;\n                v = v * v;\n         \
    \       exp >>= 1;\n            }\n            return res;\n        }();\n   \
    \     for (T& a : A) \n            a *= d;\n    }\n    return A;\n}\n\ntemplate\
    \ <class T,class U>\nrequires (!std::same_as<T, U> and std::convertible_to<U,\
    \ T>)\nstd::vector<T> BitwiseXORConvolutionPower(std::vector<U> A,usize K) {\n\
    \    std::vector<T> a(A.size());\n    for (usize i = 0 ; i < A.size() ; i++)\n\
    \        a[i] = static_cast<T>(A[i]);\n    return BitwiseXORConvolutionPower(a,K);\n\
    }\n\n} // namespace zawa\n#line 8 \"Test/AtCoder/arc222_e.test.cpp\"\nusing namespace\
    \ std;\n#include <iostream>\n#line 11 \"Test/AtCoder/arc222_e.test.cpp\"\nint\
    \ main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N,M;\n    cin >> N >> M;\n    vector<int> A(1<<M);\n    for (int i =\
    \ 0 ; i < N ; i++) {\n        int a;\n        cin >> a;\n        A[a]++;\n   \
    \ }\n    const int B=11;\n    vector<int> ans(1<<M);\n    for (int low = 1 ; low\
    \ <= B ; low++) {\n        vector<long long> cur(1<<M);\n        for (int i =\
    \ 0 ; i < (1<<M) ; i++)\n            if (A[i] >= low)\n                cur[i]\
    \ = 1;\n        auto conv=zawa::BitwiseXORConvolutionPower(cur,2);\n        for\
    \ (int i = 1 ; i < (1<<M) ; i++)\n            ans[i]+=conv[i]/2;\n    }\n    vector<int>\
    \ p;\n    for (int i = 0 ; i < (1<<M) ; i++)\n        if (A[i] > B)\n        \
    \    p.push_back(i);\n    for (int i = 0 ; i < ssize(p) ; i++)\n        for (int\
    \ j = i+1 ; j < ssize(p) ; j++)\n            ans[p[i]^p[j]]+=min(A[p[i]],A[p[j]])-B;\n\
    \    for (int i = 0 ; i < (1<<M) ; i++)\n        ans[0]+=A[i]/2;\n    const long\
    \ long MOD=998244353;\n    long long out=0,base=1;\n    for (int i = 0 ; i < (1<<M)\
    \ ; i++) {\n        out = (out+ans[i]*base)%MOD;\n        base = (base*10)%MOD;\n\
    \    }\n    cout << out << '\\n';\n#else\n    int a,b;\n    cin >> a >> b;\n \
    \   cout << a+b << '\\n';\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/arc222/tasks/arc222_e\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n/*\n * AtCoder Regular\
    \ Contest 222 E - XOR Matching\n * https://atcoder.jp/contests/arc222/submissions/80251457\n\
    \ */\n#include \"../../Src/Sequence/BitwiseXORConvolution.hpp\"\nusing namespace\
    \ std;\n#include <iostream>\n#include <vector>\nint main() {\n#ifdef ATCODER\n\
    \    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N,M;\n\
    \    cin >> N >> M;\n    vector<int> A(1<<M);\n    for (int i = 0 ; i < N ; i++)\
    \ {\n        int a;\n        cin >> a;\n        A[a]++;\n    }\n    const int\
    \ B=11;\n    vector<int> ans(1<<M);\n    for (int low = 1 ; low <= B ; low++)\
    \ {\n        vector<long long> cur(1<<M);\n        for (int i = 0 ; i < (1<<M)\
    \ ; i++)\n            if (A[i] >= low)\n                cur[i] = 1;\n        auto\
    \ conv=zawa::BitwiseXORConvolutionPower(cur,2);\n        for (int i = 1 ; i <\
    \ (1<<M) ; i++)\n            ans[i]+=conv[i]/2;\n    }\n    vector<int> p;\n \
    \   for (int i = 0 ; i < (1<<M) ; i++)\n        if (A[i] > B)\n            p.push_back(i);\n\
    \    for (int i = 0 ; i < ssize(p) ; i++)\n        for (int j = i+1 ; j < ssize(p)\
    \ ; j++)\n            ans[p[i]^p[j]]+=min(A[p[i]],A[p[j]])-B;\n    for (int i\
    \ = 0 ; i < (1<<M) ; i++)\n        ans[0]+=A[i]/2;\n    const long long MOD=998244353;\n\
    \    long long out=0,base=1;\n    for (int i = 0 ; i < (1<<M) ; i++) {\n     \
    \   out = (out+ans[i]*base)%MOD;\n        base = (base*10)%MOD;\n    }\n    cout\
    \ << out << '\\n';\n#else\n    int a,b;\n    cin >> a >> b;\n    cout << a+b <<\
    \ '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Sequence/BitwiseXORConvolution.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/arc222_e.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 16:38:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/arc222_e.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/arc222_e.test.cpp
- /verify/Test/AtCoder/arc222_e.test.cpp.html
title: Test/AtCoder/arc222_e.test.cpp
---
