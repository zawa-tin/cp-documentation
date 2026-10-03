---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/BostanMori.hpp
    title: "$[x^{N}]\\frac{P(x)}{Q(x)}$ \u306E\u9AD8\u901F\u8A08\u7B97 (Bostan-Mori\
      \ \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0)"
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPS.hpp
    title: Src/FPS/FPS.hpp
  - icon: ':heavy_check_mark:'
    path: Src/FPS/KthTerm.hpp
    title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u306EK\u9805\u76EE\u3092\u8A08\u7B97\u3059\
      \u308B"
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/FindLinearRecurrence.hpp
    title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u3092\u767A\u898B\u3059\u308B(Berlekamp-Massey)"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/3228.test.cpp
    title: Test/yukicoder/3228.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Sequence/BMBM.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/Sequence/FindLinearRecurrence.hpp\"\n\n#line\
    \ 4 \"Src/Sequence/FindLinearRecurrence.hpp\"\n\n#include <iterator>\n#include\
    \ <vector>\n\nnamespace zawa {\n\ntemplate <class T>\nstd::vector<T> FindLinearRecurrence(const\
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
    \    return res;\n}\n\n} // namespace zawa\n#line 2 \"Src/FPS/KthTerm.hpp\"\n\n\
    #include <cassert>\n#line 5 \"Src/FPS/KthTerm.hpp\"\n\n#line 2 \"Src/FPS/FPS.hpp\"\
    \n\n#line 4 \"Src/FPS/FPS.hpp\"\n\n#include <concepts>\n\nnamespace zawa {\n\n\
    namespace concepts {\n\ntemplate <class FPS>\nconcept IndexedFPS = requires(FPS\
    \ f, usize i) {\n    typename FPS::value_type;\n    { f.size() } -> std::convertible_to<usize>;\n\
    \    { f[i] } -> std::convertible_to<typename FPS::value_type>;\n    f.reserve(0);\n\
    \    f.push_back(f[i]);\n};\n\ntemplate <class FPS, class Conv>\nconcept Convolution\
    \ = \n    std::regular_invocable<Conv, const FPS&, const FPS&> &&\n    std::same_as<std::invoke_result_t<Conv,\
    \ const FPS&, const FPS&>, FPS>;\n\n} // namespace concepts\n\nstruct FPSMult\
    \ {\n    template <class FPS>\n    requires requires(const FPS& a, const FPS&\
    \ b) {\n        { a * b } -> std::same_as<FPS>;\n    }\n    FPS operator()(const\
    \ FPS& a, const FPS& b) const {\n        return a * b;\n    }\n};\n\nstruct NaiveConvolution\
    \ {\n    template <class FPS>\n    FPS operator()(const FPS& a, const FPS& b)\
    \ const {\n        if (a.empty())\n            return b;\n        if (b.empty())\n\
    \            return a;\n        FPS res(a.size() + b.size() - 1);\n        for\
    \ (usize i = 0 ; i < a.size() ; i++)\n            for (usize j = 0 ; j < b.size()\
    \ ; j++)\n                res[i + j] += a[i] * b[j];\n        return res;\n  \
    \  }\n};\n\n} // namespace zawa\n#line 2 \"Src/FPS/BostanMori.hpp\"\n\n#line 4\
    \ \"Src/FPS/BostanMori.hpp\"\n\nnamespace zawa {\n\ntemplate <concepts::IndexedFPS\
    \ FPS, class Conv = FPSMult>\nrequires concepts::Convolution<FPS, Conv>\ntypename\
    \ FPS::value_type BostanMori(usize N, FPS P, FPS Q, Conv conv = {}) {\n    assert(P.size());\n\
    \    assert(Q.size() and Q[0] != 0); \n    auto takeParity = [&](const FPS& f,\
    \ usize p) {\n        FPS res;\n        res.reserve(f.size() / 2);\n        for\
    \ (usize i = p ; i < f.size() ; i += 2)\n            res.push_back(f[i]);\n  \
    \      return res;\n    };\n    while (N) {\n        FPS Qm(Q.size());\n     \
    \   for (usize i = 0 ; i < Q.size() ; i++)\n            Qm[i] = i % 2 ? -Q[i]\
    \ : Q[i];\n        P = takeParity(conv(P, Qm), N % 2);\n        Q = takeParity(conv(Q,\
    \ Qm), 0);\n        N >>= 1;\n    }\n    return P[0] / Q[0];\n}\n\n} // namespace\
    \ zawa\n#line 8 \"Src/FPS/KthTerm.hpp\"\n\nnamespace zawa {\n\ntemplate <concepts::IndexedFPS\
    \ FPS, class Conv = FPSMult>\ntypename FPS::value_type KthTerm(u64 K, FPS A, FPS\
    \ C, Conv conv = {}) {\n    if (K < A.size()) \n        return A[K];\n    assert(C.size()\
    \ >= 2 and C[0] == 0);\n    assert(A.size() >= C.size() - 1);\n    for (auto&\
    \ v : C)\n        v = -v;\n    C[0] = 1;\n    FPS multed = conv(A, C);\n    multed.resize(C.size()\
    \ - 1);\n    return BostanMori(K, multed, C, conv);\n}\n\n} // namespace zawa\n\
    #line 6 \"Src/Sequence/BMBM.hpp\"\n\nnamespace zawa {\n\ntemplate <class T>\n\
    T BMBM(std::vector<T> A,u64 N) {\n    auto C=FindLinearRecurrence(A);\n    C.insert(C.begin(),T{0});\n\
    \    return KthTerm(N,A,C,NaiveConvolution{});\n}\n\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"./FindLinearRecurrence.hpp\"\
    \n#include \"../FPS/KthTerm.hpp\"\n\nnamespace zawa {\n\ntemplate <class T>\n\
    T BMBM(std::vector<T> A,u64 N) {\n    auto C=FindLinearRecurrence(A);\n    C.insert(C.begin(),T{0});\n\
    \    return KthTerm(N,A,C,NaiveConvolution{});\n}\n\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Sequence/FindLinearRecurrence.hpp
  - Src/FPS/KthTerm.hpp
  - Src/FPS/FPS.hpp
  - Src/FPS/BostanMori.hpp
  isVerificationFile: false
  path: Src/Sequence/BMBM.hpp
  requiredBy: []
  timestamp: '2026-10-03 17:18:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yukicoder/3228.test.cpp
documentation_of: Src/Sequence/BMBM.hpp
layout: document
title: BMBM
---

BMBMパンチ。計算量は入力の長さの二乗log

求めたいものが位数 $d$ の定数係数線形漸化式の $N$ 項目であるならば、BMBMの入力には長さ $2d$ 以上になる。

- 内部で使っている`FindLinearReccurences`が入力の長さの半分の列を返したからOK!...というわけではない。

例えば、答えが $n$ 次行列の $k$ 乗の成分ですよーってことがわかっているときは、長さ $2n$ 以上の列を入力に与える。
