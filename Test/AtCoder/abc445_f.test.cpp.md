---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidPower.hpp
    title: Src/Algebra/Monoid/MonoidPower.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/StaticSquareMatrix.hpp
    title: "\u6B63\u65B9\u884C\u5217\u306E\u884C\u5217\u7A4D\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/PowerableConcept.hpp
    title: Src/Algebra/PowerableConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Ring/MinPlusSemiring.hpp
    title: Src/Algebra/Ring/MinPlusSemiring.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
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
    - https://atcoder.jp/contests/abc445/submissions/79856158
    - https://atcoder.jp/contests/abc445/tasks/abc445_f
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/AtCoder/abc445_f.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc445/tasks/abc445_f\"\n/*\n * AtCoder Beginner Contest\
    \ 445 F - Exactly K Steps 2\n * https://atcoder.jp/contests/abc445/submissions/79856158\n\
    \ */\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 2 \"Src/Algebra/Monoid/StaticSquareMatrix.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Monoid/StaticSquareMatrix.hpp\"\
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
    \ zawa\n#line 2 \"Src/Algebra/Ring/MinPlusSemiring.hpp\"\n\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n \
    \   using Element = T;\n    static constexpr T identity() noexcept {\n       \
    \ return T{};\n    }\n    static constexpr T operation(T l,T r) noexcept {\n \
    \       return l + r;\n    }\n    static constexpr T inverse(T v) noexcept {\n\
    \        return -v;\n    }\n    template <class U>\n    static constexpr T power(T\
    \ v,U exp) noexcept {\n        return v * static_cast<T>(exp);\n    }\n};\n\n\
    } // namespace zawa\n#line 4 \"Src/Algebra/Ring/MinPlusSemiring.hpp\"\n\n#include\
    \ <algorithm>\n#include <concepts>\n\nnamespace zawa {\n\nnamespace internal {\n\
    \ntemplate <std::totally_ordered T, T INF>\nstruct Min {\n\n    using Element\
    \ = T; \n\n    static Element identity() {\n        return INF;\n    }\n\n   \
    \ static Element operation(Element L,Element R) {\n        return std::min(L,R);\n\
    \    }\n    \n};\n\n} // namespace internal\n\ntemplate <std::totally_ordered\
    \ T,T INF>\nstruct MinPlusSemiring {\n\n    using Element = T;\n\n    using Addition\
    \ = internal::Min<T,INF>;\n\n    using Multiplication = AdditiveGroup<T>;\n\n\
    };\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MonoidPower.hpp\"\n\n\
    #line 2 \"Src/Algebra/PowerableConcept.hpp\"\n\n#line 4 \"Src/Algebra/PowerableConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T,class U>\nconcept\
    \ Powerable = requires {\n    typename T::Element;\n    { T::power(std::declval<typename\
    \ T::Element>(), std::declval<U>()) }\n        -> std::same_as<typename T::Element>;\n\
    };\n\n} // namespace concepts\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#line 4 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 5 \"Src/Algebra/Monoid/MonoidPower.hpp\"\
    \n\n#line 7 \"Src/Algebra/Monoid/MonoidPower.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <concepts::Monoid M,std::unsigned_integral U>\ntypename M::Element MonoidPower(const\
    \ typename M::Element& x,U exp) {\n    if constexpr (concepts::Powerable<M,U>)\
    \ \n        return M::power(x,exp);\n    else {\n        auto a = x;\n       \
    \ auto res = M::identity();\n        while (exp) {\n            if (exp & 1)\n\
    \                res = M::operation(res,a);\n            a = M::operation(a,a);\n\
    \            exp >>= 1;\n        }\n        return res;\n    }\n}\n\n} // namespace\
    \ zawa\n#line 10 \"Test/AtCoder/abc445_f.test.cpp\"\n#include <iostream>\nusing\
    \ namespace zawa;\nusing namespace std;\nconst int MAX=100;\nint main() {\n#ifdef\
    \ ATCODER\n    int N,K;\n    cin >> N >> K;\n    using M=SquareMatrix<MinPlusSemiring<long\
    \ long,(long long)1e18>,MAX>;\n    M C=M::zero();\n    for (int i = 0 ; i < N\
    \ ; i++)\n        for (int j = 0 ; j < N ; j++)\n            cin >> C[i][j];\n\
    \    auto mat=MonoidPower<M,unsigned>(C,K);\n    for (int i = 0 ; i < N ; i++)\n\
    \        cout << mat[i][i] << '\\n';\n#else\n    int a,b;\n    cin >> a >> b;\n\
    \    cout << a+b << '\\n';\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc445/tasks/abc445_f\"\n\
    /*\n * AtCoder Beginner Contest 445 F - Exactly K Steps 2\n * https://atcoder.jp/contests/abc445/submissions/79856158\n\
    \ */\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"\
    ../../Src/Algebra/Monoid/StaticSquareMatrix.hpp\"\n#include \"../../Src/Algebra/Ring/MinPlusSemiring.hpp\"\
    \n#include \"../../Src/Algebra/Monoid/MonoidPower.hpp\"\n#include <iostream>\n\
    using namespace zawa;\nusing namespace std;\nconst int MAX=100;\nint main() {\n\
    #ifdef ATCODER\n    int N,K;\n    cin >> N >> K;\n    using M=SquareMatrix<MinPlusSemiring<long\
    \ long,(long long)1e18>,MAX>;\n    M C=M::zero();\n    for (int i = 0 ; i < N\
    \ ; i++)\n        for (int j = 0 ; j < N ; j++)\n            cin >> C[i][j];\n\
    \    auto mat=MonoidPower<M,unsigned>(C,K);\n    for (int i = 0 ; i < N ; i++)\n\
    \        cout << mat[i][i] << '\\n';\n#else\n    int a,b;\n    cin >> a >> b;\n\
    \    cout << a+b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Algebra/Monoid/StaticSquareMatrix.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Ring/MinPlusSemiring.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/Algebra/Monoid/MonoidPower.hpp
  - Src/Algebra/PowerableConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc445_f.test.cpp
  requiredBy: []
  timestamp: '2026-10-08 17:04:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc445_f.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc445_f.test.cpp
- /verify/Test/AtCoder/abc445_f.test.cpp.html
title: Test/AtCoder/abc445_f.test.cpp
---
