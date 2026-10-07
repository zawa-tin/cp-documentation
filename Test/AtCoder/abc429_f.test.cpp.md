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
    path: Src/Algebra/Monoid/StaticSquareMatrix.hpp
    title: "\u6B63\u65B9\u884C\u5217\u306E\u884C\u5217\u7A4D\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Ring/MinPlusSemiring.hpp
    title: Src/Algebra/Ring/MinPlusSemiring.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/SegmentTree.hpp
    title: Segment Tree
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
    - https://atcoder.jp/contests/abc429/submissions/79844847
    - https://atcoder.jp/contests/abc429/tasks/abc429_f
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/AtCoder/abc429_f.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc429/tasks/abc429_f\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n/*\n * AtCoder Beginner Contest 429 F - Shortest Path Query\n * https://atcoder.jp/contests/abc429/submissions/79844847\n\
    \ */\n#line 2 \"Src/Algebra/Ring/MinPlusSemiring.hpp\"\n\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\
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
    };\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/StaticSquareMatrix.hpp\"\
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
    \ zawa\n#line 2 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\n\n#line 2 \"\
    Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#line 4 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\nnamespace zawa {\n\
    \nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup = requires {\n\
    \    typename T::Element;\n    { T::operation(std::declval<typename T::Element>(),\
    \ std::declval<typename T::Element>()) } -> std::same_as<typename T::Element>;\n\
    };\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ concepts {\n\ntemplate <class T>\nconcept Identitiable = requires {\n    typename\
    \ T::Element;\n    { T::identity() } -> std::same_as<typename T::Element>;\n};\n\
    \ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\n}\
    \ // namespace\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\
    \n\n#include <vector>\n#line 8 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\
    \n#include <functional>\n#include <type_traits>\n#include <ostream>\n\nnamespace\
    \ zawa {\n\ntemplate <concepts::Monoid Monoid>\nclass SegmentTree {\npublic:\n\
    \n    using VM = Monoid;\n\n    using V = typename VM::Element;\n\n    using OM\
    \ = Monoid;\n\n    using O = typename OM::Element;\n\n    SegmentTree() = default;\n\
    \n    explicit SegmentTree(usize n) : m_n{ n }, m_dat(n << 1, VM::identity())\
    \ {}\n\n    explicit SegmentTree(const std::vector<V>& dat) : m_n{ dat.size()\
    \ }, m_dat(dat.size() << 1, VM::identity()) {\n        for (usize i{} ; i < m_n\
    \ ; i++) {\n            m_dat[i + m_n] = dat[i];\n        }\n        for (usize\
    \ i{m_n} ; i-- ; ) {\n            m_dat[i] = VM::operation(m_dat[left(i)], m_dat[right(i)]);\n\
    \        }\n    }\n\n    [[nodiscard]] inline usize size() const noexcept {\n\
    \        return m_n;\n    }\n\n    [[nodiscard]] V get(usize i) const {\n    \
    \    assert(i < size());\n        return m_dat[i + m_n];\n    }\n\n    [[nodiscard]]\
    \ V operator[](usize i) const {\n        assert(i < size());\n        return m_dat[i\
    \ + m_n];\n    }\n\n    void operation(usize i, const O& value) {\n        assert(i\
    \ < size());\n        i += size();\n        m_dat[i] = OM::operation(m_dat[i],\
    \ value);\n        while (i = parent(i), i) {\n            m_dat[i] = VM::operation(m_dat[left(i)],\
    \ m_dat[right(i)]);\n        }\n    }\n\n    void assign(usize i, const V& value)\
    \ {\n        assert(i < size());\n        i += size();\n        m_dat[i] = value;\n\
    \        while (i = parent(i), i) {\n            m_dat[i] = VM::operation(m_dat[left(i)],\
    \ m_dat[right(i)]);\n        }\n    }\n\n    [[nodiscard]] V product(u32 l, u32\
    \ r) const {\n        assert(l <= r and r <= size());\n        V L{ VM::identity()\
    \ }, R{ VM::identity() };\n        for (l += size(), r += size() ; l < r ; l =\
    \ parent(l), r = parent(r)) {\n            if (l & 1) {\n                L = VM::operation(L,\
    \ m_dat[l++]);\n            }\n            if (r & 1) {\n                R = VM::operation(m_dat[--r],\
    \ R);\n            }\n        }\n        return VM::operation(L, R);\n    }\n\n\
    \    template <class F>\n    requires std::predicate<F, V>\n    [[nodiscard]]\
    \ usize maxRight(usize l, const F& f) {\n        assert(l < size());\n       \
    \ static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>, \"\
    maxRight's argument f must be function bool(T)\");\n        assert(f(VM::identity()));\n\
    \        usize res{l}, width{1};\n        V prod{ VM::identity() };\n        for\
    \ (l += size() ; res + width <= size() ; l = parent(l), width <<= 1) if (l & 1)\
    \ {\n            if (not f(VM::operation(prod, m_dat[l]))) break; \n         \
    \   res += width;\n            prod = VM::operation(prod, m_dat[l++]);\n     \
    \   }\n        while (l = left(l), width >>= 1) {\n            if (res + width\
    \ <= size() and f(VM::operation(prod, m_dat[l]))) {\n                res += width;\n\
    \                prod = VM::operation(prod, m_dat[l++]);\n            } \n   \
    \     }\n        return res;\n    }\n\n    template <class F>\n    requires std::predicate<F,\
    \ V>\n    [[nodiscard]] usize minLeft(usize r, const F& f) const {\n        assert(r\
    \ <= size());\n        static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>,\
    \ \"minLeft's argument f must be function bool(T)\");\n        assert(f(VM::identity()));\n\
    \        usize res{r}, width{1};\n        V prod{ VM::identity() };\n        for\
    \ (r += size() ; res >= width ; r = parent(r), width <<= 1) if (r & 1) {\n   \
    \         if (not f(VM::operation(m_dat[r - 1], prod))) break;\n            res\
    \ -= width;\n            prod = VM::operation(prod, m_dat[--r]);\n        }\n\
    \        while (r = left(r), width >>= 1) {\n            if (res >= width and\
    \ f(VM::operation(m_dat[r - 1], prod))) {\n                res -= width;\n   \
    \             prod = VM::operation(m_dat[--r], prod);\n            }\n       \
    \ }\n        return res;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const SegmentTree& st) {\n        for (usize i{1} ; i < 2 * st.size() ;\
    \ i++) {\n            os << st.m_dat[i] << (i + 1 == 2 * st.size() ? \"\" : \"\
    \ \");\n        }\n        return os;\n    }\n\nprivate:\n\n    constexpr u32\
    \ left(u32 v) const {\n        return v << 1;\n    }\n\n    constexpr u32 right(u32\
    \ v) const {\n        return v << 1 | 1;\n    }\n\n    constexpr u32 parent(u32\
    \ v) const {\n        return v >> 1;\n    }\n\n    usize m_n;\n\n    std::vector<V>\
    \ m_dat;\n};\n\n} // namespace zawa\n#line 11 \"Test/AtCoder/abc429_f.test.cpp\"\
    \n#include <iostream>\n#include <string>\nusing namespace std;\nusing namespace\
    \ zawa;\nconst int INF=(int)1e9;\nusing M = SquareMatrix<MinPlusSemiring<int,INF>,3>;\n\
    M convert(string S) {\n    assert(ssize(S)==3);\n    M res = M::zero();\n    res[0][0]=S[0]=='.'?0:INF;\n\
    \    res[1][1]=S[1]=='.'?0:INF;\n    res[2][2]=S[2]=='.'?0:INF;\n    res[0][1]=res[1][0]=(S[0]=='.'\
    \ and S[1]=='.')?1:INF;\n    res[1][2]=res[2][1]=(S[1]=='.' and S[2]=='.')?1:INF;\n\
    \    res[0][2]=res[2][0]=(S[0]=='.' and S[1]=='.' and S[2]=='.') ?2:INF;\n   \
    \ return res;\n}\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n    int N;\n    cin >> N;\n    vector S(N,string(3,'_'));\n\
    \    for (int i = 0 ; i < 3 ; i++)\n        for (int j = 0 ; j < N ; j++)\n  \
    \          cin >> S[j][i];\n    vector<M> A(N);\n    for (int i = 0 ; i < N ;\
    \ i++)\n        A[i]=convert(S[i]);\n    SegmentTree<M> seg(A);\n    int Q;\n\
    \    cin >> Q;\n    while (Q--) {\n        int r,c;\n        cin >> r >> c;\n\
    \        r--; c--;\n        S[c][r]^='.'^'#';\n        A[c]=convert(S[c]);\n \
    \       seg.assign(c,A[c]);\n        auto pd=seg.product(0,N);\n        cout <<\
    \ (pd[0][2]==INF?-1:pd[0][2]+N-1) << '\\n';\n    }\n#else\n    int a,b;\n    cin\
    \ >> a >> b;\n    cout << a+b << '\\n';\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc429/tasks/abc429_f\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n/*\n * AtCoder Beginner\
    \ Contest 429 F - Shortest Path Query\n * https://atcoder.jp/contests/abc429/submissions/79844847\n\
    \ */\n#include \"../../Src/Algebra/Ring/MinPlusSemiring.hpp\"\n#include \"../../Src/Algebra/Monoid/StaticSquareMatrix.hpp\"\
    \n#include \"../../Src/DataStructure/SegmentTree/SegmentTree.hpp\"\n#include <cassert>\n\
    #include <iostream>\n#include <string>\nusing namespace std;\nusing namespace\
    \ zawa;\nconst int INF=(int)1e9;\nusing M = SquareMatrix<MinPlusSemiring<int,INF>,3>;\n\
    M convert(string S) {\n    assert(ssize(S)==3);\n    M res = M::zero();\n    res[0][0]=S[0]=='.'?0:INF;\n\
    \    res[1][1]=S[1]=='.'?0:INF;\n    res[2][2]=S[2]=='.'?0:INF;\n    res[0][1]=res[1][0]=(S[0]=='.'\
    \ and S[1]=='.')?1:INF;\n    res[1][2]=res[2][1]=(S[1]=='.' and S[2]=='.')?1:INF;\n\
    \    res[0][2]=res[2][0]=(S[0]=='.' and S[1]=='.' and S[2]=='.') ?2:INF;\n   \
    \ return res;\n}\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n    int N;\n    cin >> N;\n    vector S(N,string(3,'_'));\n\
    \    for (int i = 0 ; i < 3 ; i++)\n        for (int j = 0 ; j < N ; j++)\n  \
    \          cin >> S[j][i];\n    vector<M> A(N);\n    for (int i = 0 ; i < N ;\
    \ i++)\n        A[i]=convert(S[i]);\n    SegmentTree<M> seg(A);\n    int Q;\n\
    \    cin >> Q;\n    while (Q--) {\n        int r,c;\n        cin >> r >> c;\n\
    \        r--; c--;\n        S[c][r]^='.'^'#';\n        A[c]=convert(S[c]);\n \
    \       seg.assign(c,A[c]);\n        auto pd=seg.product(0,N);\n        cout <<\
    \ (pd[0][2]==INF?-1:pd[0][2]+N-1) << '\\n';\n    }\n#else\n    int a,b;\n    cin\
    \ >> a >> b;\n    cout << a+b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Algebra/Ring/MinPlusSemiring.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/Algebra/Monoid/StaticSquareMatrix.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/SegmentTree/SegmentTree.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc429_f.test.cpp
  requiredBy: []
  timestamp: '2026-10-07 23:31:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc429_f.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc429_f.test.cpp
- /verify/Test/AtCoder/abc429_f.test.cpp.html
title: Test/AtCoder/abc429_f.test.cpp
---
