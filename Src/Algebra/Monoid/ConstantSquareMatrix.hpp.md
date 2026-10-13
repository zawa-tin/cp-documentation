---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/aalc001_o.test.cpp
    title: "\u30BB\u30B0\u6728\u30B3\u30F3 O - \u6700\u5C0F\u5024 (\u5C65\u6B74\u548C\
      \u306E\u30C6\u30AF\u30CB\u30C3\u30AF)"
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc429_f.test.cpp
    title: Test/AtCoder/abc429_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc445_f.test.cpp
    title: Test/AtCoder/abc445_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/CF/EC172-F.test.cpp
    title: Test/CF/EC172-F.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/ConstantSquareMatrix.hpp\"\n\n#line 2\
    \ \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\n\
    namespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Monoid/ConstantSquareMatrix.hpp\"\
    \n\n#include <array>\n#include <cassert>\n#include <initializer_list>\n#include\
    \ <span>\n\nnamespace zawa {\n\ntemplate <class Semiring,usize N>\nclass ConstantSquareMatrix\
    \ {\n\n    static_assert(N > 0,\"ConstantSquareMatrix::N must be positive\");\n\
    \npublic:\n\n    using T = typename Semiring::Element;\n\n    using A = typename\
    \ Semiring::Addition;\n\n    using M = typename Semiring::Multiplication;\n\n\
    \    using Element = ConstantSquareMatrix;\n\n    constexpr ConstantSquareMatrix()\
    \ {\n        m_data.fill(A::identity());\n    }\n\n    constexpr explicit ConstantSquareMatrix(const\
    \ std::array<T,N*N>& data) : m_data{data} {}\n\n    constexpr explicit ConstantSquareMatrix(const\
    \ std::array<std::array<T,N>,N>& data) {\n        for (usize i = 0 ; i < N ; i++)\n\
    \            for (usize j = 0 ; j < N ; j++)\n                m_data[i*N+j] =\
    \ data[i][j];\n    }\n\n    constexpr explicit ConstantSquareMatrix(std::initializer_list<std::initializer_list<T>>\
    \ data) {\n        assert(data.size() == N);\n        for (usize i = 0 ; const\
    \ auto& row : data) {\n            assert(row.size() == N);\n            for (usize\
    \ j = 0 ; const auto& x : row)\n                m_data[i*N+j++]=x;\n         \
    \   i++;\n        }\n    }\n\n    constexpr std::span<T,N> operator[](usize i)\
    \ & {\n        return std::span<T,N>{m_data.data()+i*N,N};\n    }\n\n    constexpr\
    \ std::span<const T,N> operator[](usize i) const& {\n        return std::span<const\
    \ T,N>{m_data.data()+i*N,N};\n    }\n\n    constexpr usize size() const noexcept\
    \ {\n        return N;\n    }\n\n    static constexpr Element zero() {\n     \
    \   return ConstantSquareMatrix();\n    }\n\n    static constexpr Element identity()\
    \ {\n        auto res = ConstantSquareMatrix();\n        for (usize i = 0 ; i\
    \ < N ; i++)\n            res[i][i] = M::identity();\n        return res;\n  \
    \  }\n\n    static constexpr Element operation(const Element& lhs,const Element&\
    \ rhs) {\n        Element res = zero();\n        for (usize i = 0 ; i < N ; i++)\
    \ {\n            for (usize k = 0 ; k < N ; k++) {\n                const T& x\
    \ = lhs[i][k];\n                for (usize j = 0 ; j < N ; j++)\n            \
    \        res[i][j] = A::operation(res[i][j],M::operation(x,rhs[k][j]));\n    \
    \        }\n        }\n        return res;\n    }\n\n    static constexpr std::array<T,N>\
    \ leftAction(const Element& mat,const std::array<T,N>& vec) {\n        std::array<T,N>\
    \ res;\n        for (usize i = 0 ; i < N ; i++) {\n            res[i] = A::identity();\n\
    \            for (usize j = 0 ; j < N ; j++)\n                res[i] = A::operation(res[i],M::operation(mat[i][j],vec[j]));\n\
    \        }\n        return res;\n    }\n\nprivate:\n\n    std::array<T,N*N> m_data;\n\
    };\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <array>\n\
    #include <cassert>\n#include <initializer_list>\n#include <span>\n\nnamespace\
    \ zawa {\n\ntemplate <class Semiring,usize N>\nclass ConstantSquareMatrix {\n\n\
    \    static_assert(N > 0,\"ConstantSquareMatrix::N must be positive\");\n\npublic:\n\
    \n    using T = typename Semiring::Element;\n\n    using A = typename Semiring::Addition;\n\
    \n    using M = typename Semiring::Multiplication;\n\n    using Element = ConstantSquareMatrix;\n\
    \n    constexpr ConstantSquareMatrix() {\n        m_data.fill(A::identity());\n\
    \    }\n\n    constexpr explicit ConstantSquareMatrix(const std::array<T,N*N>&\
    \ data) : m_data{data} {}\n\n    constexpr explicit ConstantSquareMatrix(const\
    \ std::array<std::array<T,N>,N>& data) {\n        for (usize i = 0 ; i < N ; i++)\n\
    \            for (usize j = 0 ; j < N ; j++)\n                m_data[i*N+j] =\
    \ data[i][j];\n    }\n\n    constexpr explicit ConstantSquareMatrix(std::initializer_list<std::initializer_list<T>>\
    \ data) {\n        assert(data.size() == N);\n        for (usize i = 0 ; const\
    \ auto& row : data) {\n            assert(row.size() == N);\n            for (usize\
    \ j = 0 ; const auto& x : row)\n                m_data[i*N+j++]=x;\n         \
    \   i++;\n        }\n    }\n\n    constexpr std::span<T,N> operator[](usize i)\
    \ & {\n        return std::span<T,N>{m_data.data()+i*N,N};\n    }\n\n    constexpr\
    \ std::span<const T,N> operator[](usize i) const& {\n        return std::span<const\
    \ T,N>{m_data.data()+i*N,N};\n    }\n\n    constexpr usize size() const noexcept\
    \ {\n        return N;\n    }\n\n    static constexpr Element zero() {\n     \
    \   return ConstantSquareMatrix();\n    }\n\n    static constexpr Element identity()\
    \ {\n        auto res = ConstantSquareMatrix();\n        for (usize i = 0 ; i\
    \ < N ; i++)\n            res[i][i] = M::identity();\n        return res;\n  \
    \  }\n\n    static constexpr Element operation(const Element& lhs,const Element&\
    \ rhs) {\n        Element res = zero();\n        for (usize i = 0 ; i < N ; i++)\
    \ {\n            for (usize k = 0 ; k < N ; k++) {\n                const T& x\
    \ = lhs[i][k];\n                for (usize j = 0 ; j < N ; j++)\n            \
    \        res[i][j] = A::operation(res[i][j],M::operation(x,rhs[k][j]));\n    \
    \        }\n        }\n        return res;\n    }\n\n    static constexpr std::array<T,N>\
    \ leftAction(const Element& mat,const std::array<T,N>& vec) {\n        std::array<T,N>\
    \ res;\n        for (usize i = 0 ; i < N ; i++) {\n            res[i] = A::identity();\n\
    \            for (usize j = 0 ; j < N ; j++)\n                res[i] = A::operation(res[i],M::operation(mat[i][j],vec[j]));\n\
    \        }\n        return res;\n    }\n\nprivate:\n\n    std::array<T,N*N> m_data;\n\
    };\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Algebra/Monoid/ConstantSquareMatrix.hpp
  requiredBy: []
  timestamp: '2026-10-13 21:13:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/EC172-F.test.cpp
  - Test/AtCoder/aalc001_o.test.cpp
  - Test/AtCoder/abc429_f.test.cpp
  - Test/AtCoder/abc445_f.test.cpp
documentation_of: Src/Algebra/Monoid/ConstantSquareMatrix.hpp
layout: document
title: "\u5B9A\u6570\u30B5\u30A4\u30BA\u306E\u6B63\u65B9\u884C\u5217(\u30E2\u30CE\u30A4\
  \u30C9\u7BA1\u7406)"
---

## 概要

```
template <class Semiring,usize N>
class ConstantSquareMatrix
```

`Semiring`は行列の各成分が属する半環を表します。

$N$ は行列の一辺のサイズを表し、 $N\gt 0$ が必要です。

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

また、 $N$ 行 $1$ 列のベクトルを表す`std::array<T,N>`に行列を左から掛けるstaticメンバ関数`leftAction`が提供されています。

## 更新履歴

- 2026/10/07: 作成
- 2026/10/13: `leftAction`を追加、AALC001-Oによるverifyを追加した
