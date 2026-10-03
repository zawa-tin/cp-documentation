---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/BMBM.hpp
    title: BMBM
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/find_linear_recurrence.test.cpp
    title: Test/LC/find_linear_recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/3228.test.cpp
    title: Test/yukicoder/3228.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Sequence/FindLinearRecurrence.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Sequence/FindLinearRecurrence.hpp\"\n\n#include\
    \ <iterator>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class T>\nstd::vector<T>\
    \ FindLinearRecurrence(const std::vector<T>& A) {\n    const i32 N=std::ssize(A);\n\
    \    std::vector<T> Q{1};\n    i32 L=0;\n    std::vector<T> B{1};\n    i32 n0=-1;\n\
    \    T b=1;\n    for (i32 n = 0 ; n < N ; n++) {\n        T delta=0;\n       \
    \ for (i32 i = 0 ; i < std::ssize(Q) ; i++) \n            delta+=Q[i]*A[n-i];\n\
    \        if (delta==0)\n            continue;\n        i32 Lnew=(2*L<=n?n+1-L:L);\n\
    \        std::vector<T> Qnew=Q;\n        Qnew.resize(Lnew+1);\n        T c=delta/b;\n\
    \        for (i32 i = 0 ; i < std::ssize(B) ; i++)\n            Qnew[n-n0+i]-=c*B[i];\n\
    \        if (2*L<=n) {\n            std::swap(B,Q);\n            n0=n;\n     \
    \       b=delta;\n        }\n        L=Lnew;\n        Q=std::move(Qnew);\n   \
    \ }\n    std::vector<T> res(std::ssize(Q)-1);\n    for (u32 i = 1 ; i < Q.size()\
    \ ; i++)\n        res[i-1]=-Q[i];\n    return res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <iterator>\n\
    #include <vector>\n\nnamespace zawa {\n\ntemplate <class T>\nstd::vector<T> FindLinearRecurrence(const\
    \ std::vector<T>& A) {\n    const i32 N=std::ssize(A);\n    std::vector<T> Q{1};\n\
    \    i32 L=0;\n    std::vector<T> B{1};\n    i32 n0=-1;\n    T b=1;\n    for (i32\
    \ n = 0 ; n < N ; n++) {\n        T delta=0;\n        for (i32 i = 0 ; i < std::ssize(Q)\
    \ ; i++) \n            delta+=Q[i]*A[n-i];\n        if (delta==0)\n          \
    \  continue;\n        i32 Lnew=(2*L<=n?n+1-L:L);\n        std::vector<T> Qnew=Q;\n\
    \        Qnew.resize(Lnew+1);\n        T c=delta/b;\n        for (i32 i = 0 ;\
    \ i < std::ssize(B) ; i++)\n            Qnew[n-n0+i]-=c*B[i];\n        if (2*L<=n)\
    \ {\n            std::swap(B,Q);\n            n0=n;\n            b=delta;\n  \
    \      }\n        L=Lnew;\n        Q=std::move(Qnew);\n    }\n    std::vector<T>\
    \ res(std::ssize(Q)-1);\n    for (u32 i = 1 ; i < Q.size() ; i++)\n        res[i-1]=-Q[i];\n\
    \    return res;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Sequence/FindLinearRecurrence.hpp
  requiredBy:
  - Src/Sequence/BMBM.hpp
  timestamp: '2026-10-03 17:18:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/find_linear_recurrence.test.cpp
  - Test/yukicoder/3228.test.cpp
documentation_of: Src/Sequence/FindLinearRecurrence.hpp
layout: document
title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u3092\u767A\u898B\u3059\u308B(Berlekamp-Massey)"
---

## 概要

長さ $N$ 数列 $A$ が与えられたときに、 最初の $N$ 項が $A$ に一致する定数係数線形漸化式であって、位数が最小のものを一つ求める。

計算量は $O(N^2)$

## 参考

- [https://info.atcoder.jp/entry/algorithm_lectures/linearly_recurrent_sequence_reconstruction](https://info.atcoder.jp/entry/algorithm_lectures/linearly_recurrent_sequence_reconstruction)

多分初めてかな。中身を理解せずにライブラリを書いてしまった。今まで数々の文献を読んで理解できなくて、今回AALでお膳立てされてさえも理解できなかったので、もうBerlekamp-Masseyを理解できる日は一生来ないのだろう。

- Euclidの互除法での理解はまだ読んでないので、そっちはワンチャンあるかも。まぁ別記事の互除法での解説は理解できなかったんだけど。
