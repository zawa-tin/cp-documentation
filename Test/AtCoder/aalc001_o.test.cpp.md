---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/ConstantSquareMatrix.hpp
    title: "\u5B9A\u6570\u30B5\u30A4\u30BA\u306E\u6B63\u65B9\u884C\u5217(\u30E2\u30CE\
      \u30A4\u30C9\u7BA1\u7406)"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/ReverseOrder.hpp
    title: Src/Algebra/Monoid/ReverseOrder.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/PowerableConcept.hpp
    title: Src/Algebra/PowerableConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Ring/UsualRing.hpp
    title: Src/Algebra/Ring/UsualRing.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/LazySegmentTree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
    title: Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
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
    - https://atcoder.jp/contests/aalc001/submissions/80016999
    - https://atcoder.jp/contests/aalc001/tasks/aalc001_o
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/AtCoder/aalc001_o.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/aalc001/tasks/aalc001_o\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n/*\n * AAL Contest 001: Let's use segtree! O - \u6700\u5C0F\u5024\n * https://atcoder.jp/contests/aalc001/submissions/80016999\n\
    \ */\n#line 2 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\n\n#line 2\
    \ \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\n\
    namespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T>\nconcept Semigroup = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept MonoidWithAction\
    \ = requires {\n    requires Monoid<typename T::ValueMonoid>;\n    requires Monoid<typename\
    \ T::OperatorMonoid>;\n    { T::mapping(\n            std::declval<typename T::ValueMonoid::Element>(),\n\
    \            std::declval<typename T::OperatorMonoid::Element>()\n           \
    \ ) } -> std::same_as<typename T::ValueMonoid::Element>; \n};\n\n} // namespace\
    \ concepts\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\
    \n\n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <ranges>\n\
    #include <tuple>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <concepts::MonoidWithAction\
    \ S>\nclass LazySegmentTree {\npublic:\n\n    using VM = S::ValueMonoid;\n\n \
    \   using V = typename VM::Element;\n\n    using OM = S::OperatorMonoid;\n\n \
    \   using O = typename OM::Element;\n\n    LazySegmentTree() = default;\n\n  \
    \  explicit LazySegmentTree(usize n) \n        : m_n{n}, m_sz{1u << (std::bit_width(n))},\
    \ m_dat(m_sz << 1, VM::identity()), m_lazy(m_sz << 1, OM::identity()) {}\n\n \
    \   explicit LazySegmentTree(const std::vector<V>& a)\n        : m_n{a.size()},\
    \ m_sz{1u << (std::bit_width(a.size()))}, m_dat(m_sz << 1, VM::identity()), m_lazy(m_sz\
    \ << 1, OM::identity()) {\n        std::ranges::copy(a, m_dat.begin() + inner_size());\n\
    \        for (usize i = inner_size() ; --i ; ) recalc(i);\n    }\n\n    [[nodiscard]]\
    \ inline usize size() const noexcept {\n        return m_n;\n    }\n\n    [[nodiscard]]\
    \ V operator[](usize i) {\n        assert(i < size());\n        return get(i,\
    \ 1, 0, inner_size());\n    }\n\n    [[nodiscard]] V get(usize i) {\n        return\
    \ (*this)[i];\n    }\n\n    [[nodiscard]] V product(usize l, usize r) {\n    \
    \    assert(l <= r and r <= size());\n        return product(l, r, 1, 0, inner_size());\n\
    \    }\n\n    void operation(usize l, usize r, const O& o) {\n        assert(l\
    \ <= r and r <= size());\n        return operation(l, r, o, 1, 0, inner_size());\n\
    \    }\n\n    void assign(usize i, const V& v) {\n        assert(i < size());\n\
    \        assign(i, v, 1, 0, inner_size());\n    }\n\n    void operation(usize\
    \ i, const O& o) {\n        assert(i < size());\n        operation(i, o, 1, 0,\
    \ inner_size());\n    }\n\nprivate:\n\n    using NodeInfo = std::tuple<usize,\
    \ usize, usize>;\n\npublic:\n\n    template <class F>\n    requires std::predicate<F,\
    \ V>\n    usize maxRight(usize l, F f) {\n        assert(l <= size());\n     \
    \   if (!f(VM::identity())) return l;\n        if (l == size()) return size();\n\
    \        std::vector<NodeInfo> ranges;\n        partition_range(l, size(), ranges,\
    \ 1, 0, inner_size());\n        V prod = VM::identity();\n        for (auto [nd,\
    \ nl, nr] : ranges) {\n            if (!f(VM::operation(prod, m_dat[nd]))) {\n\
    \                return maxRight(f, prod, nd, nl, nr);\n            }\n      \
    \      else {\n                prod = VM::operation(prod, m_dat[nd]);\n      \
    \      }\n        }\n        return size();\n    }\n\n    template <class F>\n\
    \    requires std::predicate<F, V>\n    usize minLeft(usize r, F f) {\n      \
    \  assert(r <= size());\n        if (!f(VM::identity())) return r;\n        if\
    \ (!r) return 0;\n        std::vector<NodeInfo> ranges;\n        partition_range(0,\
    \ r, ranges, 1, 0, inner_size());\n        V prod = VM::identity();\n        for\
    \ (auto [nd, nl, nr] : ranges | std::views::reverse) {\n            if (!f(VM::operation(m_dat[nd],\
    \ prod))) {\n                return minLeft(f, prod, nd, nl, nr);\n          \
    \  }\n            else {\n                prod = VM::operation(m_dat[nd],prod);\n\
    \            }\n        }\n        return 0;\n    }\n\nprivate:\n\n    usize m_n{},\
    \ m_sz{};\n\n    std::vector<V> m_dat;\n\n    std::vector<O> m_lazy;\n\n    inline\
    \ usize inner_size() const noexcept {\n        return m_sz;\n    }\n    \n   \
    \ void recalc(usize nd) {\n        // assert(nd < inner_size());\n        m_dat[nd]\
    \ = VM::operation(m_dat[nd << 1 | 0], m_dat[nd << 1 | 1]);\n    }\n\n    void\
    \ propagate(usize nd) {\n        // assert(nd < inner_size());\n        for (usize\
    \ ch : {nd << 1 | 0, nd << 1 | 1}) {\n            m_dat[ch] = S::mapping(m_dat[ch],\
    \ m_lazy[nd]);\n            m_lazy[ch] = OM::operation(m_lazy[ch], m_lazy[nd]);\n\
    \        }\n        m_lazy[nd] = OM::identity();\n    }\n\n    V product(usize\
    \ ql, usize qr, usize nd, usize nl, usize nr) {\n        if (qr <= nl or nr <=\
    \ ql) return VM::identity();\n        if (ql <= nl and nr <= qr) return m_dat[nd];\n\
    \        propagate(nd);\n        const usize m = (nl + nr) >> 1;\n        return\
    \ VM::operation(\n                product(ql, qr, nd << 1 | 0, nl, m),\n     \
    \           product(ql, qr, nd << 1 | 1, m, nr)\n                );\n    }\n\n\
    \    V get(usize i, usize nd, usize nl, usize nr) {\n        if (nd >= inner_size())\
    \ return m_dat[nd];\n        propagate(nd);\n        const usize m = (nl + nr)\
    \ >> 1;\n        return i < m ? get(i, nd << 1 | 0, nl, m) : get(i, nd << 1 |\
    \ 1, m, nr);\n    }\n\n    void operation(usize ql, usize qr, const O& o, usize\
    \ nd, usize nl, usize nr) {\n        if (qr <= nl or nr <= ql) return;\n     \
    \   if (ql <= nl and nr <= qr) {\n            m_dat[nd] = S::mapping(m_dat[nd],\
    \ o);\n            m_lazy[nd] = OM::operation(m_lazy[nd], o);\n            return;\n\
    \        }\n        propagate(nd);\n        const usize m = (nl + nr) >> 1;\n\
    \        operation(ql, qr, o, nd << 1 | 0, nl, m);\n        operation(ql, qr,\
    \ o, nd << 1 | 1, m, nr);\n        recalc(nd);\n    }\n\n    void operation(usize\
    \ i, const O& o, usize nd, usize nl, usize nr) {\n        if (nl == i and i +\
    \ 1 == nr) {\n            m_dat[nd] = S::mapping(m_dat[nd], o);\n            return;\n\
    \        }\n        propagate(nd); \n        const usize m = (nl + nr) >> 1;\n\
    \        i < m ? operation(i, o, nd << 1 | 0, nl, m) : operation(i, o, nd << 1\
    \ | 1, m, nr);\n        recalc(nd);\n    }\n\n    void assign(usize i, const V&\
    \ v, usize nd, usize nl, usize nr) {\n        if (nl == i and i + 1 == nr) {\n\
    \            m_dat[nd] = v;\n            return;\n        }\n        propagate(nd);\
    \ \n        const usize m = (nl + nr) >> 1;\n        i < m ? assign(i, v, nd <<\
    \ 1 | 0, nl, m) : assign(i, v, nd << 1 | 1, m, nr);\n        recalc(nd);\n   \
    \ }\n\n    void partition_range(usize ql, usize qr, std::vector<NodeInfo>& res,\
    \ usize nd, usize nl, usize nr) {\n        if (qr <= nl or nr <= ql) return;\n\
    \        if (ql <= nl and nr <= qr) {\n            res.emplace_back(nd, nl, nr);\n\
    \            return;\n        }\n        propagate(nd);\n        const usize m\
    \ = (nl + nr) >> 1;\n        partition_range(ql, qr, res, nd << 1 | 0, nl, m);\n\
    \        partition_range(ql, qr, res, nd << 1 | 1, m, nr);\n    }\n\n    template\
    \ <class F>\n    requires std::predicate<F, V>\n    usize maxRight(F f, const\
    \ V& prod, usize nd, usize nl, usize nr) {\n        if (nd >= inner_size()) return\
    \ nl;\n        propagate(nd);\n        const usize m = (nl + nr) >> 1, lch = nd\
    \ << 1 | 0, rch = nd << 1 | 1;\n        return f(VM::operation(prod, m_dat[lch]))\
    \ ? \n            maxRight(f, VM::operation(prod, m_dat[lch]), rch, m, nr) : maxRight(f,\
    \ prod, lch, nl, m);\n    }\n\n    template <class F>\n    requires std::predicate<F,\
    \ V>\n    usize minLeft(F f, const V& prod, usize nd, usize nl, usize nr) {\n\
    \        if (nd >= inner_size()) return nr;\n        propagate(nd);\n        const\
    \ usize m = (nl + nr) >> 1, lch = nd << 1 | 0, rch = nd << 1 | 1;\n        return\
    \ f(VM::operation(m_dat[rch], prod)) ? \n            minLeft(f, VM::operation(m_dat[rch],\
    \ prod), lch, nl, m) : minLeft(f, prod, rch, m, nr);\n    }\n};\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Algebra/Monoid/ConstantSquareMatrix.hpp\"\n\n#line 4 \"\
    Src/Algebra/Monoid/ConstantSquareMatrix.hpp\"\n\n#include <array>\n#line 7 \"\
    Src/Algebra/Monoid/ConstantSquareMatrix.hpp\"\n#include <initializer_list>\n#include\
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
    };\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/ReverseOrder.hpp\"\n\n\
    #line 2 \"Src/Algebra/PowerableConcept.hpp\"\n\n#line 4 \"Src/Algebra/PowerableConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T,class U>\nconcept\
    \ Powerable = requires {\n    typename T::Element;\n    { T::power(std::declval<typename\
    \ T::Element>(), std::declval<U>()) }\n        -> std::same_as<typename T::Element>;\n\
    };\n\n} // namespace concepts\n\n} // namespace zawa\n#line 5 \"Src/Algebra/Monoid/ReverseOrder.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <concepts::Monoid M>\nstruct ReverseOrder {\n\
    \n    using Element = M::Element;\n    \n    static Element identity() {\n   \
    \     return M::identity();\n    }\n\n    static Element operation(const Element&\
    \ L, const Element& R) {\n        return M::operation(R, L);\n    }\n\n    template\
    \ <class U>\n    static Element power(const Element& x,U exp) requires concepts::Powerable<M,U>\
    \ {\n        return M::power(x,exp);\n    }\n\n};\n\n} // namespace zawa\n#line\
    \ 2 \"Src/Algebra/Ring/UsualRing.hpp\"\n\n#include <type_traits>\n\n#line 2 \"\
    Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace zawa {\n\ntemplate <class T>\n\
    class AdditiveGroup {\npublic:\n    using Element = T;\n    static constexpr T\
    \ identity() noexcept {\n        return T{};\n    }\n    static constexpr T operation(T\
    \ l,T r) noexcept {\n        return l + r;\n    }\n    static constexpr T inverse(T\
    \ v) noexcept {\n        return -v;\n    }\n    template <class U>\n    static\
    \ constexpr T power(T v,U exp) noexcept {\n        return v * static_cast<T>(exp);\n\
    \    }\n};\n\n} // namespace zawa\n#line 6 \"Src/Algebra/Ring/UsualRing.hpp\"\n\
    \nnamespace zawa {\n\nnamespace internal {\n\ntemplate <class T>\nstruct Multiplication\
    \ {\n\n    using Element = T;\n\n    static constexpr Element identity() {\n \
    \       return static_cast<Element>(1);\n    }\n\n    static constexpr Element\
    \ operation(const Element& lhs, const Element& rhs) {\n        return lhs * rhs;\n\
    \    }\n\n    static constexpr Element inverse(const Element& value) {\n     \
    \   return identity() / value;\n    }\n};\n\n} // namespace internal\n\ntemplate\
    \ <class T>\nstruct UsualRing {\n\n    using Element = T;\n\n    using Addition\
    \ = AdditiveGroup<T>;\n\n    using Multiplication = typename internal::Multiplication<T>;\n\
    \n};\n\n} // namespace zawa\n#line 13 \"Test/AtCoder/aalc001_o.test.cpp\"\n#include\
    \ <iostream>\nusing namespace std;\nusing namespace zawa;\nstruct VM {\n   using\
    \ Element = array<long long,3>;\n   static Element identity() {\n       return\
    \ {0,0,0};\n   }\n   static Element operation(Element L, Element R) {\n      \
    \ for (int i = 0 ; i < 3 ; i++)\n           L[i]+=R[i];\n       return L;\n  \
    \ }\n};\nusing OM=ConstantSquareMatrix<UsualRing<long long>,3>;\nstruct ACT {\n\
    \   using ValueMonoid = VM;\n   using OperatorMonoid = ReverseOrder<OM>;\n   static\
    \ ValueMonoid::Element mapping(const ValueMonoid::Element& v, const OperatorMonoid::Element&\
    \ o) {\n        return OM::leftAction(o,v);\n   }\n};\nint main() {\n#ifdef ATCODER\n\
    \    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N,Q;\n\
    \    cin >> N >> Q;\n    vector<int> A(N);\n    for (auto& x : A)\n        cin\
    \ >> x;\n    vector<vector<pair<int,int>>> query(N);\n    for (int i = 0 ; i <\
    \ Q ; i++) {\n        int l,r;\n        cin >> l >> r;\n        l--; r--;\n  \
    \      query[r].push_back({l,i});\n    }\n    LazySegmentTree<ACT> seg(vector(N,VM::Element{0,0,1}));\n\
    \    vector<long long> ans(Q);\n    vector<int> stk;\n    for (int i = 0 ; i <\
    \ N ; i++) {\n        while (stk.size() and A[stk.back()] >= A[i])\n         \
    \   stk.pop_back();\n        {\n            int l=stk.empty()?0:(stk.back()+1);\n\
    \            OM::Element op=OM::Element{\n                {0,0,A[i]},\n      \
    \          {0,1,0},\n                {0,0,1}\n            };\n            seg.operation(l,i+1,op);\n\
    \        }\n        {\n            OM::Element op=OM::Element{\n             \
    \   {1,0,0},\n                {1,1,0},\n                {0,0,1}\n            };\n\
    \            seg.operation(0,i+1,op);\n        }\n        for (auto [l,idx] :\
    \ query[i]) \n            ans[idx]=seg.product(l,i+1)[1];\n        stk.push_back(i);\n\
    \    }\n    for (auto i : ans)\n        cout << i << '\\n';\n#else\n    int a,b;\n\
    \    cin >> a >> b;\n    cout << a+b << '\\n';\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/aalc001/tasks/aalc001_o\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n/*\n * AAL Contest\
    \ 001: Let's use segtree! O - \u6700\u5C0F\u5024\n * https://atcoder.jp/contests/aalc001/submissions/80016999\n\
    \ */\n#include \"../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\n#include\
    \ \"../../Src/Algebra/Monoid/ConstantSquareMatrix.hpp\"\n#include \"../../Src/Algebra/Monoid/ReverseOrder.hpp\"\
    \n#include \"../../Src/Algebra/Ring/UsualRing.hpp\"\n#include <array>\n#include\
    \ <vector>\n#include <iostream>\nusing namespace std;\nusing namespace zawa;\n\
    struct VM {\n   using Element = array<long long,3>;\n   static Element identity()\
    \ {\n       return {0,0,0};\n   }\n   static Element operation(Element L, Element\
    \ R) {\n       for (int i = 0 ; i < 3 ; i++)\n           L[i]+=R[i];\n       return\
    \ L;\n   }\n};\nusing OM=ConstantSquareMatrix<UsualRing<long long>,3>;\nstruct\
    \ ACT {\n   using ValueMonoid = VM;\n   using OperatorMonoid = ReverseOrder<OM>;\n\
    \   static ValueMonoid::Element mapping(const ValueMonoid::Element& v, const OperatorMonoid::Element&\
    \ o) {\n        return OM::leftAction(o,v);\n   }\n};\nint main() {\n#ifdef ATCODER\n\
    \    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N,Q;\n\
    \    cin >> N >> Q;\n    vector<int> A(N);\n    for (auto& x : A)\n        cin\
    \ >> x;\n    vector<vector<pair<int,int>>> query(N);\n    for (int i = 0 ; i <\
    \ Q ; i++) {\n        int l,r;\n        cin >> l >> r;\n        l--; r--;\n  \
    \      query[r].push_back({l,i});\n    }\n    LazySegmentTree<ACT> seg(vector(N,VM::Element{0,0,1}));\n\
    \    vector<long long> ans(Q);\n    vector<int> stk;\n    for (int i = 0 ; i <\
    \ N ; i++) {\n        while (stk.size() and A[stk.back()] >= A[i])\n         \
    \   stk.pop_back();\n        {\n            int l=stk.empty()?0:(stk.back()+1);\n\
    \            OM::Element op=OM::Element{\n                {0,0,A[i]},\n      \
    \          {0,1,0},\n                {0,0,1}\n            };\n            seg.operation(l,i+1,op);\n\
    \        }\n        {\n            OM::Element op=OM::Element{\n             \
    \   {1,0,0},\n                {1,1,0},\n                {0,0,1}\n            };\n\
    \            seg.operation(0,i+1,op);\n        }\n        for (auto [l,idx] :\
    \ query[i]) \n            ans[idx]=seg.product(l,i+1)[1];\n        stk.push_back(i);\n\
    \    }\n    for (auto i : ans)\n        cout << i << '\\n';\n#else\n    int a,b;\n\
    \    cin >> a >> b;\n    cout << a+b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/DataStructure/SegmentTree/LazySegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Monoid/ConstantSquareMatrix.hpp
  - Src/Algebra/Monoid/ReverseOrder.hpp
  - Src/Algebra/PowerableConcept.hpp
  - Src/Algebra/Ring/UsualRing.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  isVerificationFile: true
  path: Test/AtCoder/aalc001_o.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 21:13:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/aalc001_o.test.cpp
layout: document
title: "\u30BB\u30B0\u6728\u30B3\u30F3 O - \u6700\u5C0F\u5024 (\u5C65\u6B74\u548C\u306E\
  \u30C6\u30AF\u30CB\u30C3\u30AF)"
---

履歴和(Historic Sum)のテクニック自体はこの問題の[公式解説](https://atcoder.jp/contests/aalc001/editorial/27089)が詳しい。

自分のライブラリで実装する場合、ちょっと工夫が必要。`LazySegmentTree`は既存の作用素 $L$ と新しい作用素 $R$ を`operation(L,R)`で合成する。通常の行列積を用いると合成結果は $LR$ になるが、列ベクトルに $L,R$ の順で作用させるために必要な行列は $RL$ である。

よって`ReverseOrder`で行列積の順序を逆転させる必要がある。
