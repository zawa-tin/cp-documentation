---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/CF/ECR157-F.test.cpp
    title: Test/CF/ECR157-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/matrix_det.test.cpp
    title: Test/LC/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/aoj3369.test.cpp
    title: "AOJ3369 Namori Counting (\u884C\u5217\u6728\u5B9A\u7406)"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/LinearAlgebra/Matrix.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/LinearAlgebra/Matrix.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class Semiring>\nclass Matrix {\npublic:\n   \
    \ using E = typename Semiring::Element;\n    using A = typename Semiring::Addition;\n\
    \    using M = typename Semiring::Multiplication;\n\n    Matrix() = default;\n\
    \    Matrix(usize n) : dat_(n, std::vector<E>(n, Zero())) {}\n    Matrix(usize\
    \ h, usize w) : dat_(h, std::vector<E>(w, Zero())) {}\n    Matrix(const Matrix&\
    \ mat) : dat_{mat.dat_} {}\n    Matrix(Matrix&& mat) : dat_{std::move(mat.dat_)}\
    \ {}\n\n    static E Zero() {\n        return A::identity();\n    }\n    static\
    \ E One() {\n        return M::identity();\n    }\n    static Matrix O(usize h,\
    \ usize w) {\n        return Matrix(h, w);\n    }\n    static Matrix I(usize n)\
    \ {\n        Matrix res(n);\n        for (usize i{} ; i < n ; i++) {\n       \
    \     res[i][i] = One();\n        }\n        return res;\n    }\n\n    inline\
    \ bool empty() const {\n        return dat_.empty();\n    }\n    inline usize\
    \ height() const {\n        return dat_.size();\n    }\n    inline usize width()\
    \ const {\n        assert(not empty());\n        return dat_[0].size();\n    }\n\
    \    void fill(const E& v) {\n        for (usize i{} ; i < height() ; i++) {\n\
    \            std::fill(dat_[i].begin(), dat_[i].end(), v);\n        }\n    } \n\
    \    Matrix rotated() const {\n        Matrix res(width(), height());\n      \
    \  for (usize i{} ; i < height() ; i++) {\n            for (usize j{} ; j < width()\
    \ ; j++) {\n                res[j][i] = dat_[i][j];\n            }\n        }\n\
    \        return res;\n    }\n    Matrix pow(u64 exp) const {\n        assert(height()\
    \ == width());\n        Matrix res{I(height())}, base{*this};\n        while (exp)\
    \ {\n            if (exp & 1) {\n                res = res * base;\n         \
    \   }\n            base = base * base;\n            exp >>= 1;\n        }\n  \
    \      return res;\n    }\n\n    const std::vector<E>& operator[](usize i) const\
    \ {\n        assert(i < height());\n        return dat_[i];\n    }\n    std::vector<E>&\
    \ operator[](usize i) {\n        assert(i < height());\n        return dat_[i];\n\
    \    }\n    Matrix& operator=(const Matrix& mat) {\n        dat_ = mat.dat_;\n\
    \        return *this;\n    }\n    Matrix& operator=(Matrix&& mat) {\n       \
    \ dat_ = std::move(mat.dat_);\n        return *this;\n    }\n    Matrix& operator+=(const\
    \ Matrix& mat) {\n        assert(height() == mat.height());\n        assert(width()\
    \ == mat.width());\n        for (usize i{} ; i < height() ; i++) {\n         \
    \   for (usize j{} ; j < width() ; j++) {\n                dat_[i][j] = A::operation(dat_[i][j],\
    \ mat[i][j]);\n            }\n        }\n        return *this;\n    }\n    friend\
    \ Matrix operator+(const Matrix& lhs, const Matrix& rhs) {\n        return Matrix{lhs}\
    \ += rhs;\n    }\n    friend Matrix operator*(const Matrix& lhs, const Matrix&\
    \ rhs) {\n        assert(lhs.height() == rhs.width());\n        assert(lhs.width()\
    \ == rhs.height());\n        Matrix res(lhs.height(), rhs.width());\n        for\
    \ (usize i{} ; i < lhs.height() ; i++) {\n            for (usize j{} ; j < rhs.width()\
    \ ; j++) {\n                for (usize k{} ; k < lhs.width() ; k++) {\n      \
    \              res[i][j] = A::operation(res[i][j], M::operation(lhs[i][k], rhs[k][j]));\n\
    \                }\n            }\n        }\n        return res;\n    }\n\n \
    \   // \u884C\u5217\u5F0F\n    E determinant() const {\n        assert(height()\
    \ == width());\n        usize n{height()};\n        Matrix<Semiring> dat{*this};\n\
    \        E res{M::identity()};\n        const E m1{A::inverse(M::identity())};\
    \ // -1\n        for (usize i{} ; i < n ; i++) {\n            for (usize j{i}\
    \ ; j < n ; j++) {\n                if (dat[j][i] == A::identity()) {\n      \
    \              continue; \n                }\n                if (i != j) {\n\
    \                    std::swap(dat[i], dat[j]);\n                    res = M::operation(res,\
    \ m1);\n                }\n                break;\n            }\n           \
    \ res = M::operation(res, dat[i][i]);\n            if (dat[i][i] == A::identity())\
    \ continue;\n            for (usize j{i + 1} ; j < n ; j++) {\n              \
    \  if (dat[j][i] == A::identity()) {\n                    continue;\n        \
    \        }\n                E coef{M::operation(m1, M::operation(dat[j][i], M::inverse(dat[i][i])))};\n\
    \                for (usize k{i} ; k < n ; k++) {\n                    dat[j][k]\
    \ = A::operation(dat[j][k], M::operation(coef, dat[i][k]));\n                }\n\
    \            }\n        }\n        return res;\n    }\n    // \u4F59\u56E0\u5B50\
    \n    E cofactor(usize r, usize c) const {\n        assert(height() == width());\n\
    \        usize n{height()};\n        assert(n >= usize{2});\n        Matrix tmp(n\
    \ - 1, n - 1);\n        for (usize i{} ; i < n ; i++) {\n            if (i ==\
    \ r) {\n                continue;\n            }\n            for (usize j{} ;\
    \ j < n ; j++) {\n                if (j == c) {\n                    continue;\n\
    \                }\n                tmp[i > r ? i - 1 : i][j > c ? j - 1 : j]\
    \ = dat_[i][j];\n            }\n        }\n        return tmp.determinant();\n\
    \    }\n\nprivate:\n    std::vector<std::vector<E>> dat_;\n};\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class Semiring>\nclass Matrix {\npublic:\n   \
    \ using E = typename Semiring::Element;\n    using A = typename Semiring::Addition;\n\
    \    using M = typename Semiring::Multiplication;\n\n    Matrix() = default;\n\
    \    Matrix(usize n) : dat_(n, std::vector<E>(n, Zero())) {}\n    Matrix(usize\
    \ h, usize w) : dat_(h, std::vector<E>(w, Zero())) {}\n    Matrix(const Matrix&\
    \ mat) : dat_{mat.dat_} {}\n    Matrix(Matrix&& mat) : dat_{std::move(mat.dat_)}\
    \ {}\n\n    static E Zero() {\n        return A::identity();\n    }\n    static\
    \ E One() {\n        return M::identity();\n    }\n    static Matrix O(usize h,\
    \ usize w) {\n        return Matrix(h, w);\n    }\n    static Matrix I(usize n)\
    \ {\n        Matrix res(n);\n        for (usize i{} ; i < n ; i++) {\n       \
    \     res[i][i] = One();\n        }\n        return res;\n    }\n\n    inline\
    \ bool empty() const {\n        return dat_.empty();\n    }\n    inline usize\
    \ height() const {\n        return dat_.size();\n    }\n    inline usize width()\
    \ const {\n        assert(not empty());\n        return dat_[0].size();\n    }\n\
    \    void fill(const E& v) {\n        for (usize i{} ; i < height() ; i++) {\n\
    \            std::fill(dat_[i].begin(), dat_[i].end(), v);\n        }\n    } \n\
    \    Matrix rotated() const {\n        Matrix res(width(), height());\n      \
    \  for (usize i{} ; i < height() ; i++) {\n            for (usize j{} ; j < width()\
    \ ; j++) {\n                res[j][i] = dat_[i][j];\n            }\n        }\n\
    \        return res;\n    }\n    Matrix pow(u64 exp) const {\n        assert(height()\
    \ == width());\n        Matrix res{I(height())}, base{*this};\n        while (exp)\
    \ {\n            if (exp & 1) {\n                res = res * base;\n         \
    \   }\n            base = base * base;\n            exp >>= 1;\n        }\n  \
    \      return res;\n    }\n\n    const std::vector<E>& operator[](usize i) const\
    \ {\n        assert(i < height());\n        return dat_[i];\n    }\n    std::vector<E>&\
    \ operator[](usize i) {\n        assert(i < height());\n        return dat_[i];\n\
    \    }\n    Matrix& operator=(const Matrix& mat) {\n        dat_ = mat.dat_;\n\
    \        return *this;\n    }\n    Matrix& operator=(Matrix&& mat) {\n       \
    \ dat_ = std::move(mat.dat_);\n        return *this;\n    }\n    Matrix& operator+=(const\
    \ Matrix& mat) {\n        assert(height() == mat.height());\n        assert(width()\
    \ == mat.width());\n        for (usize i{} ; i < height() ; i++) {\n         \
    \   for (usize j{} ; j < width() ; j++) {\n                dat_[i][j] = A::operation(dat_[i][j],\
    \ mat[i][j]);\n            }\n        }\n        return *this;\n    }\n    friend\
    \ Matrix operator+(const Matrix& lhs, const Matrix& rhs) {\n        return Matrix{lhs}\
    \ += rhs;\n    }\n    friend Matrix operator*(const Matrix& lhs, const Matrix&\
    \ rhs) {\n        assert(lhs.height() == rhs.width());\n        assert(lhs.width()\
    \ == rhs.height());\n        Matrix res(lhs.height(), rhs.width());\n        for\
    \ (usize i{} ; i < lhs.height() ; i++) {\n            for (usize j{} ; j < rhs.width()\
    \ ; j++) {\n                for (usize k{} ; k < lhs.width() ; k++) {\n      \
    \              res[i][j] = A::operation(res[i][j], M::operation(lhs[i][k], rhs[k][j]));\n\
    \                }\n            }\n        }\n        return res;\n    }\n\n \
    \   // \u884C\u5217\u5F0F\n    E determinant() const {\n        assert(height()\
    \ == width());\n        usize n{height()};\n        Matrix<Semiring> dat{*this};\n\
    \        E res{M::identity()};\n        const E m1{A::inverse(M::identity())};\
    \ // -1\n        for (usize i{} ; i < n ; i++) {\n            for (usize j{i}\
    \ ; j < n ; j++) {\n                if (dat[j][i] == A::identity()) {\n      \
    \              continue; \n                }\n                if (i != j) {\n\
    \                    std::swap(dat[i], dat[j]);\n                    res = M::operation(res,\
    \ m1);\n                }\n                break;\n            }\n           \
    \ res = M::operation(res, dat[i][i]);\n            if (dat[i][i] == A::identity())\
    \ continue;\n            for (usize j{i + 1} ; j < n ; j++) {\n              \
    \  if (dat[j][i] == A::identity()) {\n                    continue;\n        \
    \        }\n                E coef{M::operation(m1, M::operation(dat[j][i], M::inverse(dat[i][i])))};\n\
    \                for (usize k{i} ; k < n ; k++) {\n                    dat[j][k]\
    \ = A::operation(dat[j][k], M::operation(coef, dat[i][k]));\n                }\n\
    \            }\n        }\n        return res;\n    }\n    // \u4F59\u56E0\u5B50\
    \n    E cofactor(usize r, usize c) const {\n        assert(height() == width());\n\
    \        usize n{height()};\n        assert(n >= usize{2});\n        Matrix tmp(n\
    \ - 1, n - 1);\n        for (usize i{} ; i < n ; i++) {\n            if (i ==\
    \ r) {\n                continue;\n            }\n            for (usize j{} ;\
    \ j < n ; j++) {\n                if (j == c) {\n                    continue;\n\
    \                }\n                tmp[i > r ? i - 1 : i][j > c ? j - 1 : j]\
    \ = dat_[i][j];\n            }\n        }\n        return tmp.determinant();\n\
    \    }\n\nprivate:\n    std::vector<std::vector<E>> dat_;\n};\n\n} // namespace\
    \ zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/LinearAlgebra/Matrix.hpp
  requiredBy: []
  timestamp: '2024-06-25 21:03:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/ECR157-F.test.cpp
  - Test/Manual/aoj3369.test.cpp
  - Test/LC/matrix_det.test.cpp
documentation_of: Src/LinearAlgebra/Matrix.hpp
layout: document
redirect_from:
- /library/Src/LinearAlgebra/Matrix.hpp
- /library/Src/LinearAlgebra/Matrix.hpp.html
title: Src/LinearAlgebra/Matrix.hpp
---
