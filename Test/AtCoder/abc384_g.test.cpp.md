---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/GroupConcept.hpp
    title: Src/Algebra/Group/GroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/FenwickTree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Mo/Mo.hpp
    title: Mo's algorithm
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/CompressedSequence.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc384/submissions/67045346
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc384_g.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/Mo/Mo.hpp\"\n\n#line 4 \"\
    Src/DataStructure/Mo/Mo.hpp\"\n\n#include <algorithm>\n#include <bit>\n#include\
    \ <cassert>\n#include <vector>\n#include <type_traits>\n\nnamespace zawa {\n\n\
    namespace internal {\n\n// reference: https://codeforces.com/blog/entry/61203?#comment-1064868\n\
    u64 hilbertOrder(u64 x, u64 y, usize dim) {\n    const u64 max{(1ull << dim) -\
    \ 1};\n    assert(x <= max);\n    assert(y <= max);\n    u64 res{};\n    for (u64\
    \ s{1ull << (dim - 1)} ; s ; s >>= 1) {\n        bool rx{static_cast<bool>(x &\
    \ s)}, ry{static_cast<bool>(y & s)};\n        res = (res << 2) | (rx ? ry ? 2\
    \ : 1 : ry ? 3 : 0);\n        if (!rx) {\n            if (ry) x ^= max, y ^= max;\n\
    \            std::swap(x, y);\n        }\n    }\n    return res;\n}\n\n} // namespace\
    \ internal\n\ntemplate <class T, class AddL, class AddR, class DelL, class DelR,\
    \ class Eval>\nstd::vector<typename std::invoke_result_t<Eval, usize>> Mo(std::vector<T>\
    \ qs, AddL addL, AddR addR, DelL delL, DelR delR, Eval eval, bool reset = false)\
    \ {\n    usize log{};\n    for (const T& lr : qs) log = std::max<usize>(log, std::bit_width(lr.r));\n\
    \    std::vector<std::pair<T, usize>> ord(qs.size());\n    std::vector<u64> h(qs.size());\n\
    \    for (usize i{} ; i < qs.size() ; i++) {\n        ord[i] = {qs[i], i};\n \
    \       h[i] = internal::hilbertOrder(qs[i].l, qs[i].r, log);\n    }\n    std::sort(ord.begin(),\
    \ ord.end(), [&](const auto& L, const auto& R) -> bool {\n            return h[L.second]\
    \ < h[R.second];\n            });\n    std::vector<typename std::invoke_result_t<Eval,\
    \ usize>> res(qs.size());\n    usize L{}, R{};\n    for (const auto& [lr, id]\
    \ : ord) {\n        while (R < lr.r) addR(R++);\n        while (L > lr.l) addL(--L);\n\
    \        while (R > lr.r) delR(--R);\n        while (L < lr.l) delL(L++);\n  \
    \      res[id] = eval(id);\n    }\n    if (reset) while (R > L) delR(--R);\n \
    \   return res;\n}\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\n#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Inversible\
    \ = requires {\n    typename T::Element;\n    { T::inverse(std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\ntemplate <class\
    \ T>\nconcept Group = Monoid<T> and Inversible<T>;\n\n} // namespace Concept\n\
    \n} // namespace zawa\n#line 5 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\n#line 8 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n#include <ostream>\n\
    #include <functional>\n#line 11 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <concepts::Group Group>\nclass FenwickTree {\n\
    public:\n\n    using VM = Group;\n    \n    using V = typename VM::Element;\n\n\
    \    FenwickTree() = default;\n\n    explicit FenwickTree(usize n) : m_n{ n },\
    \ m_bitwidth{ std::__lg(n) + 1 }, m_a(n), m_dat(n + 1, VM::identity()) {\n   \
    \     m_dat.shrink_to_fit();\n        m_a.shrink_to_fit();\n    }\n\n    explicit\
    \ FenwickTree(const std::vector<V>& a) : m_n{ a.size() }, m_bitwidth{ std::__lg(a.size())\
    \ + 1 }, m_a(a), m_dat(a.size() + 1, VM::identity()) {\n        m_dat.shrink_to_fit();\
    \  \n        m_a.shrink_to_fit();\n        for (i32 i{} ; i < static_cast<i32>(m_n)\
    \ ; i++) {\n            addDat(i, a[i]);\n        }\n    }\n\n    inline usize\
    \ size() const noexcept {\n        return m_n;\n    }\n\n    // return a[i]\n\
    \    const V& get(usize i) const noexcept {\n        assert(i < size());\n   \
    \     return m_a[i];\n    }\n\n    // return a[i]\n    const V& operator[](usize\
    \ i) const noexcept {\n        assert(i < size());\n        return m_a[i];\n \
    \   }\n\n    // a[i] <- a[i] + v\n    void operation(usize i, const V& v) {\n\
    \        assert(i < size());\n        addDat(i, v);\n        m_a[i] = VM::operation(m_a[i],\
    \ v);\n    }\n\n    // a[i] <- v\n    void assign(usize i, const V& v) {\n   \
    \     assert(i < size());\n        addDat(i, VM::operation(VM::inverse(m_a[i]),\
    \ v));\n        m_a[i] = v;\n    }\n\n    // return a[0] + a[1] + ... + a[r -\
    \ 1]\n    V prefixProduct(usize r) const {\n        assert(r <= size());\n   \
    \     return product(r);\n    }\n\n    // return a[l] + a[l + 1] ... + a[r - 1]\n\
    \    V product(usize l, usize r) const {\n        assert(l <= r and r <= size());\n\
    \        return VM::operation(VM::inverse(product(l)), product(r));\n    }\n\n\
    \    template <class Function>\n    usize maxRight(usize l, const Function& f)\
    \ const {\n        static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>,\
    \ \"maxRight's argument f must be function bool(T)\");\n        assert(l <= size());\n\
    \        assert(f(VM::identity()));\n        V sum{ VM::inverse(product(l)) };\
    \ \n        usize r{};\n        for (usize bit{ m_bitwidth } ; bit ; ) {\n   \
    \         bit--;\n            usize nxt{ r | (1u << bit) };\n            if (nxt\
    \ < m_dat.size() and (nxt <= l or f(VM::operation(sum, m_dat[nxt])))) {\n    \
    \            sum = VM::operation(sum, m_dat[nxt]);\n                r = std::move(nxt);\n\
    \            }\n        }\n        assert(l <= r);\n        return r;\n    }\n\
    \n    template <class Function>\n    usize minLeft(usize r, const Function& f)\
    \ const {\n        static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>,\
    \ \"minLeft's argument f must be function bool(T)\");\n        assert(r <= size());\n\
    \        assert(f(VM::identity()));\n        V sum{ product(r) };\n        usize\
    \ l{};\n        for (usize bit{ m_bitwidth } ; bit ; ) {\n            bit--;\n\
    \            usize nxt{ l | (1u << bit) };\n            if (nxt <= r and not f(VM::operation(VM::inverse(m_dat[nxt]),\
    \ sum))) {\n                sum = VM::operation(VM::inverse(m_dat[nxt]), sum);\n\
    \                l = std::move(nxt);\n            }\n        }\n        assert(l\
    \ <= r);\n        return l;\n    }\n\n    // debug print\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const FenwickTree& ft) {\n        for (usize i{}\
    \ ; i <= ft.size() ; i++) {\n            os << ft.prefixProduct(i) << (i == ft.size()\
    \ ? \"\" : \" \");\n        }\n        return os;\n    }\n\nprivate:\n\n    usize\
    \ m_n{};\n\n    usize m_bitwidth{};\n\n    std::vector<V> m_a, m_dat;\n\n    constexpr\
    \ i32 lsb(i32 x) const noexcept {\n        return x & -x;\n    }\n    \n    //\
    \ a[i] <- a[i] + v\n    void addDat(i32 i, const V& v) {\n        assert(0 <=\
    \ i and i < static_cast<i32>(m_n));\n        for ( i++ ; i < static_cast<i32>(m_dat.size())\
    \ ; i += lsb(i)) {\n            m_dat[i] = VM::operation(m_dat[i], v);\n     \
    \   }\n    }\n\n    // return a[0] + a[1] + .. + a[i - 1]\n    V product(i32 i)\
    \ const {\n        assert(0 <= i and i <= static_cast<i32>(m_n));\n        V res{\
    \ VM::identity() };\n        for ( ; i > 0 ; i -= lsb(i)) {\n            res =\
    \ VM::operation(res, m_dat[i]);\n        }\n        return res;\n    }\n\n};\n\
    \n} // namespace zawa\n#line 2 \"Src/Sequence/CompressedSequence.hpp\"\n\n#line\
    \ 4 \"Src/Sequence/CompressedSequence.hpp\"\n\n#line 8 \"Src/Sequence/CompressedSequence.hpp\"\
    \n#include <iterator>\n#include <limits>\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nclass CompressedSequence {\npublic:\n\n    static constexpr u32 NotFound\
    \ = std::numeric_limits<u32>::max();\n\n    CompressedSequence() = default;\n\n\
    \    template <class InputIterator>\n    CompressedSequence(InputIterator first,\
    \ InputIterator last) : comped_(first, last), f_{} {\n        std::sort(comped_.begin(),\
    \ comped_.end());\n        comped_.erase(std::unique(comped_.begin(), comped_.end()),\
    \ comped_.end());\n        comped_.shrink_to_fit();\n        f_.reserve(std::distance(first,\
    \ last));\n        for (auto it{first} ; it != last ; it++) {\n            f_.emplace_back(std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), *it)));\n        }\n    }\n\
    \n    CompressedSequence(const std::vector<T>& A) : CompressedSequence(A.begin(),\
    \ A.end()) {}\n\n    inline usize size() const noexcept {\n        return comped_.size();\n\
    \    }\n\n    u32 operator[](const T& v) const {\n        return std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), v));\n    }\n\n    u32 upper_bound(const\
    \ T& v) const {\n        return std::distance(comped_.begin(), std::upper_bound(comped_.begin(),\
    \ comped_.end(), v));\n    }\n\n    u32 find(const T& v) const {\n        u32\
    \ i = std::distance(comped_.begin(), std::lower_bound(comped_.begin(), comped_.end(),\
    \ v));\n        return i == comped_.size() or comped_[i] != v ? NotFound : i;\n\
    \    }\n\n    bool contains(const T& v) const {\n        u32 i = std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), v));\n        return i < comped_.size()\
    \ and comped_[i] == v;\n    }\n\n    u32 at(const T& v) const {\n        u32 res\
    \ = find(v);\n        assert(res != NotFound);\n        return res;\n    }\n\n\
    \    inline u32 map(u32 i) const noexcept {\n        assert(i < f_.size());\n\
    \        return f_[i];\n    }\n\n    inline T inverse(u32 i) const noexcept {\n\
    \        assert(i < size());\n        return comped_[i];\n    }\n\n    inline\
    \ std::vector<T> comped() const noexcept {\n        return comped_;\n    }\n\n\
    private:\n\n    std::vector<T> comped_;\n\n    std::vector<u32> f_;\n\n};\n\n\
    } // namespace zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace\
    \ zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n    using Element\
    \ = T;\n    static constexpr T identity() noexcept {\n        return T{};\n  \
    \  }\n    static constexpr T operation(const T& l, const T& r) noexcept {\n  \
    \      return l + r;\n    }\n    static constexpr T inverse(const T& v) noexcept\
    \ {\n        return -v;\n    }\n};\n\n} // namespace zawa\n#line 8 \"Test/AtCoder/abc384_g.test.cpp\"\
    \n\n/*\n * AtCoder Beginner Contest 384 G - Abs Sum\n * https://atcoder.jp/contests/abc384/submissions/67045346\n\
    \ */\n\nusing namespace zawa;\n\nint N, K, A[100000], B[100000];\nstruct query\
    \ {\n    usize l, r;\n};\nquery Q[10000];\n\nvoid solve() {\n    CompressedSequence\
    \ a{std::vector(A, A + N)}, b{std::vector(B, B + N)};\n    FenwickTree<AdditiveGroup<int>>\
    \ ca(a.size()), cb(b.size());\n    FenwickTree<AdditiveGroup<long long>> sa(a.size()),\
    \ sb(b.size());\n    long long ans = 0;\n    auto addA = [&](int i) -> void {\n\
    \        // std::cout << \"addA \" << i << std::endl;\n        int sm = cb.prefixProduct(b[A[i]]);\
    \ \n        ans += (long long)A[i] * sm;\n        ans += (long long)-A[i] * (cb.prefixProduct(b.size())\
    \ - sm);\n        ans += sb.prefixProduct(b.size()) - 2LL * sb.prefixProduct(b[A[i]]);\n\
    \        sa.operation(a.map(i), A[i]);\n        ca.operation(a.map(i), 1);\n \
    \   };\n    auto addB = [&](int i) -> void {\n        // std::cout << \"addB \"\
    \ << i << std::endl;\n        int sm = ca.prefixProduct(a[B[i]]);\n        ans\
    \ += (long long)B[i] * sm;\n        ans += (long long)-B[i] * (ca.prefixProduct(a.size())\
    \ - sm);\n        ans += sa.prefixProduct(a.size()) - 2LL * sa.prefixProduct(a[B[i]]);\n\
    \        sb.operation(b.map(i), B[i]);\n        cb.operation(b.map(i), 1);\n \
    \   };\n    auto delA = [&](int i) -> void {\n        // std::cout << \"delA \"\
    \ << i << std::endl;\n        int sm = cb.prefixProduct(b[A[i]]); \n        ans\
    \ -= (long long)A[i] * sm;\n        ans -= (long long)-A[i] * (cb.prefixProduct(b.size())\
    \ - sm);\n        ans -= sb.prefixProduct(b.size()) - 2LL * sb.prefixProduct(b[A[i]]);\n\
    \        sa.operation(a.map(i), -A[i]);\n        ca.operation(a.map(i), -1);\n\
    \    };\n    auto delB = [&](int i) -> void {\n        // std::cout << \"delB\
    \ \" << i << std::endl;\n        int sm = ca.prefixProduct(a[B[i]]);\n       \
    \ ans -= (long long)B[i] * sm;\n        ans -= (long long)-B[i] * (ca.prefixProduct(a.size())\
    \ - sm);\n        ans -= sa.prefixProduct(a.size()) - 2LL * sa.prefixProduct(a[B[i]]);\n\
    \        sb.operation(b.map(i), -B[i]);\n        cb.operation(b.map(i), -1);\n\
    \    };\n    auto eval = [&](int) -> long long {\n        // std::cout << \"eval\
    \ \" << i << std::endl;\n        return ans;\n    };\n    for (long long a : Mo(std::vector<query>(Q,\
    \ Q + K), addA, addB, delA, delB, eval)) {\n        std::cout << -a << '\\n';\n\
    \    }\n}\n\nint main() {\n#ifdef ATCODER\n    SetFastIO();\n    std::cin >> N;\n\
    \    for (int i = 0 ; i < N ; i++) std::cin >> A[i];\n    for (int i = 0 ; i <\
    \ N ; i++) std::cin >> B[i];\n    std::cin >> K;\n    for (int i = 0 ; i < K ;\
    \ i++) {\n        std::cin >> Q[i].l >> Q[i].r;\n    }\n    solve();\n#else\n\
    \    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/DataStructure/Mo/Mo.hpp\"\
    \n#include \"../../Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n#include \"\
    ../../Src/Sequence/CompressedSequence.hpp\"\n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\
    \n\n/*\n * AtCoder Beginner Contest 384 G - Abs Sum\n * https://atcoder.jp/contests/abc384/submissions/67045346\n\
    \ */\n\nusing namespace zawa;\n\nint N, K, A[100000], B[100000];\nstruct query\
    \ {\n    usize l, r;\n};\nquery Q[10000];\n\nvoid solve() {\n    CompressedSequence\
    \ a{std::vector(A, A + N)}, b{std::vector(B, B + N)};\n    FenwickTree<AdditiveGroup<int>>\
    \ ca(a.size()), cb(b.size());\n    FenwickTree<AdditiveGroup<long long>> sa(a.size()),\
    \ sb(b.size());\n    long long ans = 0;\n    auto addA = [&](int i) -> void {\n\
    \        // std::cout << \"addA \" << i << std::endl;\n        int sm = cb.prefixProduct(b[A[i]]);\
    \ \n        ans += (long long)A[i] * sm;\n        ans += (long long)-A[i] * (cb.prefixProduct(b.size())\
    \ - sm);\n        ans += sb.prefixProduct(b.size()) - 2LL * sb.prefixProduct(b[A[i]]);\n\
    \        sa.operation(a.map(i), A[i]);\n        ca.operation(a.map(i), 1);\n \
    \   };\n    auto addB = [&](int i) -> void {\n        // std::cout << \"addB \"\
    \ << i << std::endl;\n        int sm = ca.prefixProduct(a[B[i]]);\n        ans\
    \ += (long long)B[i] * sm;\n        ans += (long long)-B[i] * (ca.prefixProduct(a.size())\
    \ - sm);\n        ans += sa.prefixProduct(a.size()) - 2LL * sa.prefixProduct(a[B[i]]);\n\
    \        sb.operation(b.map(i), B[i]);\n        cb.operation(b.map(i), 1);\n \
    \   };\n    auto delA = [&](int i) -> void {\n        // std::cout << \"delA \"\
    \ << i << std::endl;\n        int sm = cb.prefixProduct(b[A[i]]); \n        ans\
    \ -= (long long)A[i] * sm;\n        ans -= (long long)-A[i] * (cb.prefixProduct(b.size())\
    \ - sm);\n        ans -= sb.prefixProduct(b.size()) - 2LL * sb.prefixProduct(b[A[i]]);\n\
    \        sa.operation(a.map(i), -A[i]);\n        ca.operation(a.map(i), -1);\n\
    \    };\n    auto delB = [&](int i) -> void {\n        // std::cout << \"delB\
    \ \" << i << std::endl;\n        int sm = ca.prefixProduct(a[B[i]]);\n       \
    \ ans -= (long long)B[i] * sm;\n        ans -= (long long)-B[i] * (ca.prefixProduct(a.size())\
    \ - sm);\n        ans -= sa.prefixProduct(a.size()) - 2LL * sa.prefixProduct(a[B[i]]);\n\
    \        sb.operation(b.map(i), -B[i]);\n        cb.operation(b.map(i), -1);\n\
    \    };\n    auto eval = [&](int) -> long long {\n        // std::cout << \"eval\
    \ \" << i << std::endl;\n        return ans;\n    };\n    for (long long a : Mo(std::vector<query>(Q,\
    \ Q + K), addA, addB, delA, delB, eval)) {\n        std::cout << -a << '\\n';\n\
    \    }\n}\n\nint main() {\n#ifdef ATCODER\n    SetFastIO();\n    std::cin >> N;\n\
    \    for (int i = 0 ; i < N ; i++) std::cin >> A[i];\n    for (int i = 0 ; i <\
    \ N ; i++) std::cin >> B[i];\n    std::cin >> K;\n    for (int i = 0 ; i < K ;\
    \ i++) {\n        std::cin >> Q[i].l >> Q[i].r;\n    }\n    solve();\n#else\n\
    \    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/Mo/Mo.hpp
  - Src/DataStructure/FenwickTree/FenwickTree.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Sequence/CompressedSequence.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc384_g.test.cpp
  requiredBy: []
  timestamp: '2025-08-15 19:19:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc384_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc384_g.test.cpp
- /verify/Test/AtCoder/abc384_g.test.cpp.html
title: Test/AtCoder/abc384_g.test.cpp
---
