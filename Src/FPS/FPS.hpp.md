---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/BostanMori.hpp
    title: "$[x^{N}]\\frac{P(x)}{Q(x)}$ \u306E\u9AD8\u901F\u8A08\u7B97 (Bostan-Mori\
      \ \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0)"
  - icon: ':heavy_check_mark:'
    path: Src/FPS/DivisionOfPolynomials.hpp
    title: Src/FPS/DivisionOfPolynomials.hpp
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPSNTTFriendly.hpp
    title: Src/FPS/FPSNTTFriendly.hpp
  - icon: ':heavy_check_mark:'
    path: Src/FPS/KthTerm.hpp
    title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u306EK\u9805\u76EE\u3092\u8A08\u7B97\u3059\
      \u308B"
  - icon: ':heavy_check_mark:'
    path: Src/FPS/PolynomialTaylorShift.hpp
    title: Polynomial Taylor Shift
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc215_g.test.cpp
    title: ABC215-G Colorful Candies 2
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc436_g.test.cpp
    title: ABC436-G Linear Inequation
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/tdpc_fibonacci.test.cpp
    title: Test/AtCoder/tdpc_fibonacci.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/division_of_polynomials.test.cpp
    title: Test/LC/division_of_polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/exp_of_formal_power_series.test.cpp
    title: Test/LC/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/inv_of_formal_power_series.test.cpp
    title: Test/LC/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/log_of_formal_power_series.test.cpp
    title: Test/LC/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/polynomial_taylor_shift.test.cpp
    title: Test/LC/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/pow_of_formal_power_series.test.cpp
    title: Test/LC/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/3044.test.cpp
    title: Test/yukicoder/3044.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/FPS/FPS.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/FPS/FPS.hpp\"\n\n#include <concepts>\n\n\
    namespace zawa {\n\nnamespace concepts {\n\ntemplate <class FPS>\nconcept IndexedFPS\
    \ = requires(FPS f, usize i) {\n    typename FPS::value_type;\n    { f.size()\
    \ } -> std::convertible_to<usize>;\n    { f[i] } -> std::convertible_to<typename\
    \ FPS::value_type>;\n    f.reserve(0);\n    f.push_back(f[i]);\n};\n\ntemplate\
    \ <class FPS, class Conv>\nconcept Convolution = \n    std::regular_invocable<Conv,\
    \ const FPS&, const FPS&> &&\n    std::same_as<std::invoke_result_t<Conv, const\
    \ FPS&, const FPS&>, FPS>;\n\n} // namespace concepts\n\nstruct FPSMult {\n  \
    \  template <class FPS>\n    requires requires(const FPS& a, const FPS& b) {\n\
    \        { a * b } -> std::same_as<FPS>;\n    }\n    FPS operator()(const FPS&\
    \ a, const FPS& b) const {\n        return a * b;\n    }\n};\n\nstruct NaiveConvolution\
    \ {\n    template <class FPS>\n    FPS operator()(const FPS& a, const FPS& b)\
    \ const {\n        if (a.empty())\n            return b;\n        if (b.empty())\n\
    \            return a;\n        FPS res(a.size() + b.size() - 1);\n        for\
    \ (usize i = 0 ; i < a.size() ; i++)\n            for (usize j = 0 ; j < b.size()\
    \ ; j++)\n                res[i + j] += a[i] * b[j];\n        return res;\n  \
    \  }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class FPS>\nconcept IndexedFPS\
    \ = requires(FPS f, usize i) {\n    typename FPS::value_type;\n    { f.size()\
    \ } -> std::convertible_to<usize>;\n    { f[i] } -> std::convertible_to<typename\
    \ FPS::value_type>;\n    f.reserve(0);\n    f.push_back(f[i]);\n};\n\ntemplate\
    \ <class FPS, class Conv>\nconcept Convolution = \n    std::regular_invocable<Conv,\
    \ const FPS&, const FPS&> &&\n    std::same_as<std::invoke_result_t<Conv, const\
    \ FPS&, const FPS&>, FPS>;\n\n} // namespace concepts\n\nstruct FPSMult {\n  \
    \  template <class FPS>\n    requires requires(const FPS& a, const FPS& b) {\n\
    \        { a * b } -> std::same_as<FPS>;\n    }\n    FPS operator()(const FPS&\
    \ a, const FPS& b) const {\n        return a * b;\n    }\n};\n\nstruct NaiveConvolution\
    \ {\n    template <class FPS>\n    FPS operator()(const FPS& a, const FPS& b)\
    \ const {\n        if (a.empty())\n            return b;\n        if (b.empty())\n\
    \            return a;\n        FPS res(a.size() + b.size() - 1);\n        for\
    \ (usize i = 0 ; i < a.size() ; i++)\n            for (usize j = 0 ; j < b.size()\
    \ ; j++)\n                res[i + j] += a[i] * b[j];\n        return res;\n  \
    \  }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/FPS/FPS.hpp
  requiredBy:
  - Src/FPS/FPSNTTFriendly.hpp
  - Src/FPS/BostanMori.hpp
  - Src/FPS/PolynomialTaylorShift.hpp
  - Src/FPS/DivisionOfPolynomials.hpp
  - Src/FPS/KthTerm.hpp
  timestamp: '2026-01-03 20:52:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc215_g.test.cpp
  - Test/AtCoder/tdpc_fibonacci.test.cpp
  - Test/AtCoder/abc436_g.test.cpp
  - Test/LC/exp_of_formal_power_series.test.cpp
  - Test/LC/log_of_formal_power_series.test.cpp
  - Test/LC/pow_of_formal_power_series.test.cpp
  - Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
  - Test/LC/division_of_polynomials.test.cpp
  - Test/LC/inv_of_formal_power_series.test.cpp
  - Test/LC/polynomial_taylor_shift.test.cpp
  - Test/yukicoder/3044.test.cpp
documentation_of: Src/FPS/FPS.hpp
layout: document
redirect_from:
- /library/Src/FPS/FPS.hpp
- /library/Src/FPS/FPS.hpp.html
title: Src/FPS/FPS.hpp
---
