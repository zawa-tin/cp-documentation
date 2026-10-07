---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc429_f.test.cpp
    title: Test/AtCoder/abc429_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/CF/EC172-F.test.cpp
    title: Test/CF/EC172-F.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/StaticSquareMatrix.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Monoid/StaticSquareMatrix.hpp\"\
    \n\n#include <array>\n#include <cassert>\n#include <span>\n\nnamespace zawa {\n\
    \ntemplate <class Semiring,usize N>\nclass SquareMatrix {\npublic:\n\n    using\
    \ T = typename Semiring::Element;\n\n    using A = typename Semiring::Addition;\n\
    \n    using M = typename Semiring::Multiplication;\n\n    using Element = SquareMatrix;\n\
    \n    constexpr SquareMatrix() {\n        m_data.fill(A::identity());\n    }\n\
    \n    constexpr explicit SquareMatrix(const std::array<T,N*N>& data) : m_data{data}\
    \ {}\n\n    constexpr explicit SquareMatrix(const std::array<std::array<T,N>,N>&\
    \ data) {\n        for (usize i = 0 ; i < N ; i++)\n            for (usize j =\
    \ 0 ; j < N ; j++)\n                m_data[i*N+j] = data[i][j];\n    }\n\n   \
    \ constexpr explicit SquareMatrix(std::initializer_list<std::initializer_list<T>>\
    \ data) {\n        assert(data.size() == N);\n        for (usize i = 0 ; const\
    \ auto& row : data) {\n            assert(row.size() == N);\n            for (usize\
    \ j = 0 ; const auto& x : row)\n                m_data[i*N+j++]=x;\n         \
    \   i++;\n        }\n    }\n\n    constexpr std::span<T,N> operator[](usize i)\
    \ & {\n        return std::span<T,N>{m_data.data()+i*N,N};\n    }\n\n    constexpr\
    \ std::span<const T,N> operator[](usize i) const& {\n        return std::span<const\
    \ T,N>{m_data.data()+i*N,N};\n    }\n\n    constexpr usize size() const noexcept\
    \ {\n        return N;\n    }\n\n    static constexpr Element zero() {\n     \
    \   return SquareMatrix();\n    }\n\n    static constexpr Element identity() {\n\
    \        auto res = SquareMatrix();\n        for (usize i = 0 ; i < N ; i++)\n\
    \            res[i][i] = M::identity();\n        return res;\n    }\n\n    static\
    \ constexpr Element operation(const Element& lhs,const Element& rhs) {\n     \
    \   auto res = zero();\n        for (usize i = 0 ; i < N ; i++)\n            for\
    \ (usize k = 0 ; k < N ; k++) {\n                const T x = lhs[i][k];\n    \
    \            for (usize j = 0 ; j < N ; j++)\n                    res[i][j] =\
    \ A::operation(res[i][j],M::operation(x,rhs[k][j]));\n            }\n        return\
    \ res;\n    }\n\nprivate:\n\n    std::array<T,N*N> m_data;\n};\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <array>\n\
    #include <cassert>\n#include <span>\n\nnamespace zawa {\n\ntemplate <class Semiring,usize\
    \ N>\nclass SquareMatrix {\npublic:\n\n    using T = typename Semiring::Element;\n\
    \n    using A = typename Semiring::Addition;\n\n    using M = typename Semiring::Multiplication;\n\
    \n    using Element = SquareMatrix;\n\n    constexpr SquareMatrix() {\n      \
    \  m_data.fill(A::identity());\n    }\n\n    constexpr explicit SquareMatrix(const\
    \ std::array<T,N*N>& data) : m_data{data} {}\n\n    constexpr explicit SquareMatrix(const\
    \ std::array<std::array<T,N>,N>& data) {\n        for (usize i = 0 ; i < N ; i++)\n\
    \            for (usize j = 0 ; j < N ; j++)\n                m_data[i*N+j] =\
    \ data[i][j];\n    }\n\n    constexpr explicit SquareMatrix(std::initializer_list<std::initializer_list<T>>\
    \ data) {\n        assert(data.size() == N);\n        for (usize i = 0 ; const\
    \ auto& row : data) {\n            assert(row.size() == N);\n            for (usize\
    \ j = 0 ; const auto& x : row)\n                m_data[i*N+j++]=x;\n         \
    \   i++;\n        }\n    }\n\n    constexpr std::span<T,N> operator[](usize i)\
    \ & {\n        return std::span<T,N>{m_data.data()+i*N,N};\n    }\n\n    constexpr\
    \ std::span<const T,N> operator[](usize i) const& {\n        return std::span<const\
    \ T,N>{m_data.data()+i*N,N};\n    }\n\n    constexpr usize size() const noexcept\
    \ {\n        return N;\n    }\n\n    static constexpr Element zero() {\n     \
    \   return SquareMatrix();\n    }\n\n    static constexpr Element identity() {\n\
    \        auto res = SquareMatrix();\n        for (usize i = 0 ; i < N ; i++)\n\
    \            res[i][i] = M::identity();\n        return res;\n    }\n\n    static\
    \ constexpr Element operation(const Element& lhs,const Element& rhs) {\n     \
    \   auto res = zero();\n        for (usize i = 0 ; i < N ; i++)\n            for\
    \ (usize k = 0 ; k < N ; k++) {\n                const T x = lhs[i][k];\n    \
    \            for (usize j = 0 ; j < N ; j++)\n                    res[i][j] =\
    \ A::operation(res[i][j],M::operation(x,rhs[k][j]));\n            }\n        return\
    \ res;\n    }\n\nprivate:\n\n    std::array<T,N*N> m_data;\n};\n\n} // namespace\
    \ zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Algebra/Monoid/StaticSquareMatrix.hpp
  requiredBy: []
  timestamp: '2026-10-07 23:31:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/EC172-F.test.cpp
  - Test/AtCoder/abc429_f.test.cpp
documentation_of: Src/Algebra/Monoid/StaticSquareMatrix.hpp
layout: document
title: "\u6B63\u65B9\u884C\u5217\u306E\u884C\u5217\u7A4D\u30E2\u30CE\u30A4\u30C9"
---

# 概要

```
template <class Semiring,usize N>
class SquareMatrix
```

`Semiring`の雛形は↓↓。各種staticメンバには`constexpr`がついていることが望ましい。

```
struct Addition {
    using Element = ;
    static constexpr Element identity() {
    }
    static constexpr Element operation(const Element&, const Element&) {
    }
};

struct Multiplication {
    using Element = ;
    static constexpr Element identity() {
    }
    static constexpr Element operation(const Element&, const Element&) {
    }
};

template <class T>
struct UsualRing {
    using Element = T;
    using Addition = Addition;
    using Multiplication = Multiplication;
};
```
