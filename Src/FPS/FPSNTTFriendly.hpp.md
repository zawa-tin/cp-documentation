---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPS.hpp
    title: Src/FPS/FPS.hpp
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
    path: Src/FPS/KthTerm.hpp
    title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u306EK\u9805\u76EE\u3092\u8A08\u7B97\u3059\
      \u308B"
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"./FPS.hpp\"\n#include \"../Template/TypeAlias.hpp\"\
    \n\n#include \"atcoder/modint\"\n#include \"atcoder/convolution\"\n\n#include\
    \ <cassert>\n#include <iostream>\n#include <ranges>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace zawa {\n\ntemplate <usize MOD = 998244353>\nstruct FPSNTTFriendly\
    \ : public std::vector<atcoder::static_modint<MOD>> {\n\n    using std::vector<atcoder::static_modint<MOD>>::vector;\n\
    \n    using V = atcoder::static_modint<MOD>;\n\n    FPSNTTFriendly(const std::vector<V>&\
    \ f) {\n        this->reserve(f.size());\n        for (V v : f) this->push_back(std::move(v));\n\
    \    }\n\n    [[nodiscard]] FPSNTTFriendly<MOD> resized(usize n) const {\n   \
    \     auto cp = *this;\n        cp.resize(n);\n        return cp;\n    }\n\n \
    \   [[nodiscard]] FPSNTTFriendly<MOD> inv(usize n) const {\n        assert(this->size()\
    \ and (*this)[0] != V{0});\n        FPSNTTFriendly<MOD> g{this->front().inv()};\n\
    \        while (g.size() < n) {\n            auto fgg = [&]() {\n            \
    \    auto res = g;\n                FPSNTTFriendly<MOD> f(resized(g.size() <<\
    \ 1));\n                const usize m = res.size(), k = f.size(), s = (m + m -\
    \ 1) + k - 1;\n                const usize z = atcoder::internal::bit_ceil(s);\n\
    \                res.resize(z);\n                f.resize(z);\n              \
    \  atcoder::internal::butterfly(res);\n                atcoder::internal::butterfly(f);\n\
    \                for (usize i = 0 ; i < z ; i++) res[i] *= res[i] * f[i];\n  \
    \              atcoder::internal::butterfly_inv(res);\n                res.resize(k);\n\
    \                res *= V{z}.inv();\n                return res;\n           \
    \ }();\n            // auto gg = atcoder::convolution(g, g);\n            // std::vector<T>\
    \ f(g.size() << 1);\n            // for (usize i = 0 ; i < std::min(f.size(),\
    \ F.size()) ; i++) f[i] = F[i];\n            // auto fgg = atcoder::convolution(f,\
    \ gg);\n            g = V{2} * g - fgg;\n        }\n        g.resize(n);\n   \
    \     return g;\n    }\n\n    [[nodiscard]] FPSNTTFriendly<MOD> inv() const {\n\
    \        return inv(this->size());\n    }\n\n    [[nodiscard]] FPSNTTFriendly<MOD>\
    \ differential() const {\n        if (this->empty()) return FPSNTTFriendly{};\n\
    \        FPSNTTFriendly res(this->size() - 1);\n        for (usize i = 1 ; i <\
    \ this->size() ; i++) {\n            res[i - 1] = (*this)[i] * V{i};\n       \
    \ }\n        return res;\n    }\n\n    // C = 0\n    [[nodiscard]] FPSNTTFriendly<MOD>\
    \ integral() const {\n        FPSNTTFriendly<MOD> res(this->size() + 1);\n   \
    \     for (usize i = 0 ; i < this->size() ; i++) {\n            res[i + 1] = (*this)[i]\
    \ / V{i + 1};\n        }\n        return res;\n    }\n\n    [[nodiscard]] FPSNTTFriendly<MOD>\
    \ log(usize n) const {\n        assert(this->size() and (*this)[0] == V{1});\n\
    \        return FPSNTTFriendly<MOD>{differential() / (*this)}.resized(n - 1).integral();\n\
    \    }\n\n    [[nodiscard]] FPSNTTFriendly<MOD> log() const {\n        return\
    \ log(this->size()); \n    }\n\n    [[nodiscard]] FPSNTTFriendly<MOD> exp(usize\
    \ n) const {\n        assert(this->size() and (*this)[0] == 0);    \n        FPSNTTFriendly<MOD>\
    \ g{V{1}};\n        for (usize sz = 1 ; sz < n ; sz <<= 1) {\n            auto\
    \ f = -g.resized(sz << 1).log() + (*this).resized(sz << 1);\n            f[0]\
    \ += 1;\n            g = g * f;\n            g.resize(sz << 1);\n        }\n \
    \       g.resize(n);\n        return g;\n    }\n\n    [[nodiscard]] FPSNTTFriendly<MOD>\
    \ exp() const {\n        return exp(this->size());\n    }\n\n    [[nodiscard]]\
    \ FPSNTTFriendly<MOD> pow(u64 k, usize n) const {\n        if (k == 0) return\
    \ FPSNTTFriendly<MOD>{V{1}}.resized(n);\n        auto it = std::ranges::find_if(*this,\
    \ [&](const auto& v) { return v != V{0}; });\n        if (it == this->end()) return\
    \ FPSNTTFriendly<MOD>(n);\n        auto sh = it - this->begin();\n        if (sh\
    \ and k > n / sh) return FPSNTTFriendly<MOD>(n);\n        FPSNTTFriendly<MOD>\
    \ f(this->size() - sh);\n        const auto pv = it->pow(k);\n        const auto\
    \ iv = it->inv();\n        for (usize i = 0 ; i < f.size() ; i++) f[i] = (*this)[sh\
    \ + i] * iv;\n        f = (f.log(n) * V{k}).exp(n);\n        FPSNTTFriendly<MOD>\
    \ res(n);\n        for (usize i = 0 ; i + sh * k < n ; i++) res[i + sh * k] =\
    \ f[i] * pv;\n        return res;\n    }\n\n    [[nodiscard]] FPSNTTFriendly<MOD>\
    \ pow(u64 k) const {\n        return pow(k, this->size());\n    }\n\n    FPSNTTFriendly<MOD>\
    \ operator+() const {\n        return *this;\n    }\n\n    FPSNTTFriendly<MOD>\
    \ operator-() const {\n        FPSNTTFriendly<MOD> f = *this;\n        for (usize\
    \ i = 0 ; i < this->size() ; i++) f[i] *= V::raw(MOD - 1);\n        return f;\n\
    \    }\n\n    FPSNTTFriendly<MOD>& operator+=(const FPSNTTFriendly<MOD>& f) {\n\
    \        if (this->size() < f.size()) this->resize(f.size());\n        for (usize\
    \ i = 0 ; i < f.size() ; i++) (*this)[i] += f[i];\n        return *this;\n   \
    \ }\n\n    FPSNTTFriendly<MOD>& operator-=(const FPSNTTFriendly<MOD>& f) {\n \
    \       if (this->size() < f.size()) this->resize(f.size());\n        for (usize\
    \ i = 0 ; i < f.size() ; i++) (*this)[i] -= f[i];\n        return *this;\n   \
    \ }\n\n    FPSNTTFriendly<MOD>& operator*=(const V& v) {\n        for (usize i\
    \ = 0 ; i < this->size() ; i++) (*this)[i] *= v;\n        return *this;\n    }\n\
    \n    friend FPSNTTFriendly<MOD> operator*(const FPSNTTFriendly<MOD>& l, const\
    \ atcoder::static_modint<MOD>& r) {\n        return FPSNTTFriendly<MOD>{l} *=\
    \ r;\n    }\n\n    friend FPSNTTFriendly<MOD> operator*(const atcoder::static_modint<MOD>&\
    \ l, const FPSNTTFriendly<MOD>& r) {\n        return FPSNTTFriendly<MOD>{r} *=\
    \ l;\n    }\n\n    FPSNTTFriendly<MOD>& operator*=(FPSNTTFriendly<MOD> f) {\n\
    \        auto l = *this; \n        auto r = std::move(f);\n        auto conved\
    \ = atcoder::convolution(l, r);\n        return *this = std::move(conved);\n \
    \   }\n\n    FPSNTTFriendly<MOD>& operator/=(const V& v) {\n        return (*this)\
    \ *= v.inv();\n    }\n\n    friend FPSNTTFriendly<MOD> operator/(const FPSNTTFriendly<MOD>&\
    \ l, const atcoder::static_modint<MOD>& r) {\n        return FPSNTTFriendly<MOD>{l}\
    \ /= r;\n    }\n\n    FPSNTTFriendly<MOD>& operator/=(FPSNTTFriendly<MOD> f) {\n\
    \        return (*this) *= f.inv();\n    }\n};\n\ntemplate <usize MOD = 998244353>\n\
    FPSNTTFriendly<MOD> operator+(const FPSNTTFriendly<MOD>& l, const FPSNTTFriendly<MOD>&\
    \ r) {\n    return FPSNTTFriendly<MOD>{l} += r;\n}\n\ntemplate <usize MOD = 998244353>\n\
    FPSNTTFriendly<MOD> operator-(const FPSNTTFriendly<MOD>& l, const FPSNTTFriendly<MOD>&\
    \ r) {\n    return FPSNTTFriendly<MOD>{l} -= r;\n}\n\ntemplate <usize MOD = 998244353>\n\
    FPSNTTFriendly<MOD> operator*(const FPSNTTFriendly<MOD>& l, const FPSNTTFriendly<MOD>&\
    \ r) {\n    return atcoder::convolution(l, r);\n}\n\ntemplate <usize MOD = 998244353>\n\
    FPSNTTFriendly<MOD> operator/(const FPSNTTFriendly<MOD>& l, const FPSNTTFriendly<MOD>&\
    \ r) {\n    return FPSNTTFriendly<MOD>{atcoder::convolution(l, r.inv())};\n}\n\
    \ntemplate <usize MOD = 998244353>\nstd::ostream& operator<<(std::ostream& os,\
    \ const FPSNTTFriendly<MOD>& f) {\n    for (usize i = 0 ; i < f.size() ; i++)\
    \ os << f[i].val() << (i + 1 == f.size() ? \"\" : \" \");\n    return os;\n}\n\
    \ntemplate <usize MOD = 998244353>\nstd::istream& operator>>(std::istream& is,\
    \ FPSNTTFriendly<MOD>& f) {\n    for (auto& v : f) {\n        i64 x;\n       \
    \ is >> x;\n        v = atcoder::static_modint<MOD>{x};\n    }\n    return is;\n\
    }\n\ntemplate <usize MOD = 998244353>\nusing FPS = FPSNTTFriendly<MOD>;\n\n} //\
    \ namespace zawa\n"
  dependsOn:
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/FPS/FPSNTTFriendly.hpp
  requiredBy:
  - Src/FPS/BostanMori.hpp
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
documentation_of: Src/FPS/FPSNTTFriendly.hpp
layout: document
redirect_from:
- /library/Src/FPS/FPSNTTFriendly.hpp
- /library/Src/FPS/FPSNTTFriendly.hpp.html
title: Src/FPS/FPSNTTFriendly.hpp
---
