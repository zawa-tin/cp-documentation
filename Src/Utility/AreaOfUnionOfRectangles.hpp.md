---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/AdditionMonoid.hpp
    title: Src/Algebra/Monoid/AdditionMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MinCountMonoid.hpp
    title: Src/Algebra/Monoid/MinCountMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc346_g.test.cpp
    title: Test/AtCoder/abc346_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/area_of_union_of_rectangles.test.cpp
    title: Test/LC/area_of_union_of_rectangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Utility/AreaOfUnionOfRectangles.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/AdditionMonoid.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T>\nstruct AdditionMonoid {\n    using\
    \ Element = T;\n    static T identity() noexcept {\n        return T{};\n    }\n\
    \    static T operation(const T& a, const T& b) noexcept {\n        return a +\
    \ b;\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MinCountMonoid.hpp\"\
    \n\n#include <limits>\n#include <utility>\n\nnamespace zawa {\n\ntemplate <class\
    \ T, class U>\nstruct MinCountMonoid {\n    // min, count\u306E\u9806\n    using\
    \ Element = std::pair<T, U>;\n\n    static Element identity() noexcept {\n   \
    \     return { std::numeric_limits<T>::max(), U{} };\n    }\n\n    static Element\
    \ operation(const Element& L, const Element& R) {\n        if (L.first < R.first)\
    \ return L;\n        else if (L.first > R.first) return R;\n        else return\
    \ Element{ L.first, L.second + R.second };\n    }\n\n};\n\n} // namespace \n#line\
    \ 2 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\n\n#line 2 \"Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp\"\
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
    \  }\n            else {\n                prod = VM::operation(prod, m_dat[nd]);\n\
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
    \ 1 == nr) {\n            m_dat[nd] = S::mapping(m_dat[nd], o);\n            //\
    \ \u8449\u9802\u70B9\u306A\u306E\u3067\u3001lazy\u3078\u306Eop\u306F\u4E0D\u8981\
    \n            return;\n        }\n        propagate(nd); \n        const usize\
    \ m = (nl + nr) >> 1;\n        i < m ? operation(i, o, nd << 1 | 0, nl, m) : operation(i,\
    \ o, nd << 1 | 1, m, nr);\n        recalc(nd);\n    }\n\n    void assign(usize\
    \ i, const V& v, usize nd, usize nl, usize nr) {\n        if (nl == i and i +\
    \ 1 == nr) {\n            m_dat[nd] = v;\n            return;\n        }\n   \
    \     propagate(nd); \n        const usize m = (nl + nr) >> 1;\n        i < m\
    \ ? assign(i, v, nd << 1 | 0, nl, m) : assign(i, v, nd << 1 | 1, m, nr);\n   \
    \     recalc(nd);\n    }\n\n    void partition_range(usize ql, usize qr, std::vector<NodeInfo>&\
    \ res, usize nd, usize nl, usize nr) {\n        if (qr <= nl or nr <= ql) return;\n\
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
    \ zawa\n#line 7 \"Src/Utility/AreaOfUnionOfRectangles.hpp\"\n\n#line 10 \"Src/Utility/AreaOfUnionOfRectangles.hpp\"\
    \n#include <type_traits>\n#line 12 \"Src/Utility/AreaOfUnionOfRectangles.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T>\nclass Rectangle {\npublic:\n\n   \
    \ Rectangle() = default;\n     \n    Rectangle(T l, T d, T r, T u)\n        :\
    \ l_{l}, d_{d}, r_{r}, u_{u} {\n        assert(l <= r);\n        assert(d <= u);\n\
    \    }\n\n    Rectangle(const std::pair<T, T>& ld, const std::pair<T, T>& ru)\n\
    \        : l_{ld.first}, d_{ld.second}, r_{ru.first}, u_{ru.second} {}\n\n   \
    \ Rectangle(const std::pair<T, T>& ld, T w, T h)\n        : l_{ld.first}, d_{ld.second},\
    \ r_{l_ + w}, u_{d_ + h} {}\n\n    inline T left() const noexcept {\n        return\
    \ l_;\n    }\n\n    inline T right() const noexcept {\n        return r_;\n  \
    \  }\n\n    inline T down() const noexcept {\n        return d_;\n    }\n\n  \
    \  inline T up() const noexcept {\n        return u_;\n    }\n\nprivate:\n   \
    \ // \u5DE6\u4E0B\u3001\u53F3\u4E0A\n    T l_{}, d_{}, r_{}, u_{};\n};\n\nnamespace\
    \ internal {\n\nstruct AreaOfUnionOfRectanglesStructure {\n    using ValueMonoid\
    \ = MinCountMonoid<i32, u64>;\n    using OperatorMonoid = AdditionMonoid<i32>;\n\
    \    static ValueMonoid::Element mapping(const ValueMonoid::Element& V, const\
    \ OperatorMonoid::Element& R) {\n        return ValueMonoid::Element{ V.first\
    \ + R, V.second };\n    }\n    static ValueMonoid::Element generate(u64 v) {\n\
    \        return ValueMonoid::Element{ 0, v };\n    }\n};\n\n} // namespace internal\n\
    \ntemplate <class T, class InputIterator>\nu64 AreaOfUnionOfRectangles(InputIterator\
    \ first, InputIterator last) {\n    static_assert(std::is_same_v<std::remove_reference_t<decltype(*first)>,\
    \ Rectangle<T>>, \"*iterator 's type must be T\");\n    usize n{static_cast<usize>(std::distance(first,\
    \ last))};\n    if (n == 0u) return u64{};\n    std::vector<T> xs, ys;\n    xs.reserve(2u\
    \ * n);\n    ys.reserve(2u * n);\n    for (auto it{first} ; it != last ; it++)\
    \ {\n       xs.push_back(it->left()); \n       xs.push_back(it->right());\n  \
    \     ys.push_back(it->down()); \n       ys.push_back(it->up());\n    }\n    std::sort(ys.begin(),\
    \ ys.end());\n    ys.erase(std::unique(ys.begin(), ys.end()), ys.end());\n   \
    \ std::sort(xs.begin(), xs.end());\n    xs.erase(std::unique(xs.begin(), xs.end()),\
    \ xs.end());\n    std::vector<std::vector<std::pair<std::pair<u32, u32>, bool>>>\
    \ event(xs.size());\n    for (auto it{first} ; it != last ; it++) {\n        u32\
    \ l{static_cast<u32>(std::distance(ys.begin(), std::lower_bound(ys.begin(), ys.end(),\
    \ it->down())))};\n        u32 r{static_cast<u32>(std::distance(ys.begin(), std::lower_bound(ys.begin(),\
    \ ys.end(), it->up())))};\n        event[static_cast<u32>(std::distance(xs.begin(),\
    \ std::lower_bound(xs.begin(), xs.end(), it->left())))]\n            .emplace_back(std::pair<u32,\
    \ u32>{ l, r }, true);\n        event[static_cast<u32>(std::distance(xs.begin(),\
    \ std::lower_bound(xs.begin(), xs.end(), it->right())))]\n            .emplace_back(std::pair<u32,\
    \ u32>{ l, r }, false);\n    } \n    using S = internal::AreaOfUnionOfRectanglesStructure;\n\
    \    std::vector<S::ValueMonoid::Element> init(ys.size() - 1);\n    for (usize\
    \ i{} ; i + 1 < ys.size() ; i++) {\n        init[i] = S::generate(static_cast<u64>(ys[i\
    \ + 1] - ys[i]));\n    } \n    u64 all{static_cast<u64>(ys.back() - ys.front())};\n\
    \    LazySegmentTree<S> seg{init};\n    u64 res{};\n    for (u32 x{} ; x < xs.size()\
    \ ; x++) {\n        if (x >= 1u) {\n            auto [min, count]{seg.product(0,\
    \ init.size())};\n            res += (all - (min == 0 ? count : u64{})) * (xs[x]\
    \ - xs[x - 1]);\n        }\n        for (const auto& [lr, v] : event[x]) {\n \
    \           seg.operation(lr.first, lr.second, (v ? +1 : -1));\n        }\n  \
    \  }\n    return res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"../Algebra/Monoid/AdditionMonoid.hpp\"\
    \n#include \"../Algebra/Monoid/MinCountMonoid.hpp\"\n#include \"../DataStructure/SegmentTree/LazySegmentTree.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <type_traits>\n#include\
    \ <utility>\n\nnamespace zawa {\n\ntemplate <class T>\nclass Rectangle {\npublic:\n\
    \n    Rectangle() = default;\n     \n    Rectangle(T l, T d, T r, T u)\n     \
    \   : l_{l}, d_{d}, r_{r}, u_{u} {\n        assert(l <= r);\n        assert(d\
    \ <= u);\n    }\n\n    Rectangle(const std::pair<T, T>& ld, const std::pair<T,\
    \ T>& ru)\n        : l_{ld.first}, d_{ld.second}, r_{ru.first}, u_{ru.second}\
    \ {}\n\n    Rectangle(const std::pair<T, T>& ld, T w, T h)\n        : l_{ld.first},\
    \ d_{ld.second}, r_{l_ + w}, u_{d_ + h} {}\n\n    inline T left() const noexcept\
    \ {\n        return l_;\n    }\n\n    inline T right() const noexcept {\n    \
    \    return r_;\n    }\n\n    inline T down() const noexcept {\n        return\
    \ d_;\n    }\n\n    inline T up() const noexcept {\n        return u_;\n    }\n\
    \nprivate:\n    // \u5DE6\u4E0B\u3001\u53F3\u4E0A\n    T l_{}, d_{}, r_{}, u_{};\n\
    };\n\nnamespace internal {\n\nstruct AreaOfUnionOfRectanglesStructure {\n    using\
    \ ValueMonoid = MinCountMonoid<i32, u64>;\n    using OperatorMonoid = AdditionMonoid<i32>;\n\
    \    static ValueMonoid::Element mapping(const ValueMonoid::Element& V, const\
    \ OperatorMonoid::Element& R) {\n        return ValueMonoid::Element{ V.first\
    \ + R, V.second };\n    }\n    static ValueMonoid::Element generate(u64 v) {\n\
    \        return ValueMonoid::Element{ 0, v };\n    }\n};\n\n} // namespace internal\n\
    \ntemplate <class T, class InputIterator>\nu64 AreaOfUnionOfRectangles(InputIterator\
    \ first, InputIterator last) {\n    static_assert(std::is_same_v<std::remove_reference_t<decltype(*first)>,\
    \ Rectangle<T>>, \"*iterator 's type must be T\");\n    usize n{static_cast<usize>(std::distance(first,\
    \ last))};\n    if (n == 0u) return u64{};\n    std::vector<T> xs, ys;\n    xs.reserve(2u\
    \ * n);\n    ys.reserve(2u * n);\n    for (auto it{first} ; it != last ; it++)\
    \ {\n       xs.push_back(it->left()); \n       xs.push_back(it->right());\n  \
    \     ys.push_back(it->down()); \n       ys.push_back(it->up());\n    }\n    std::sort(ys.begin(),\
    \ ys.end());\n    ys.erase(std::unique(ys.begin(), ys.end()), ys.end());\n   \
    \ std::sort(xs.begin(), xs.end());\n    xs.erase(std::unique(xs.begin(), xs.end()),\
    \ xs.end());\n    std::vector<std::vector<std::pair<std::pair<u32, u32>, bool>>>\
    \ event(xs.size());\n    for (auto it{first} ; it != last ; it++) {\n        u32\
    \ l{static_cast<u32>(std::distance(ys.begin(), std::lower_bound(ys.begin(), ys.end(),\
    \ it->down())))};\n        u32 r{static_cast<u32>(std::distance(ys.begin(), std::lower_bound(ys.begin(),\
    \ ys.end(), it->up())))};\n        event[static_cast<u32>(std::distance(xs.begin(),\
    \ std::lower_bound(xs.begin(), xs.end(), it->left())))]\n            .emplace_back(std::pair<u32,\
    \ u32>{ l, r }, true);\n        event[static_cast<u32>(std::distance(xs.begin(),\
    \ std::lower_bound(xs.begin(), xs.end(), it->right())))]\n            .emplace_back(std::pair<u32,\
    \ u32>{ l, r }, false);\n    } \n    using S = internal::AreaOfUnionOfRectanglesStructure;\n\
    \    std::vector<S::ValueMonoid::Element> init(ys.size() - 1);\n    for (usize\
    \ i{} ; i + 1 < ys.size() ; i++) {\n        init[i] = S::generate(static_cast<u64>(ys[i\
    \ + 1] - ys[i]));\n    } \n    u64 all{static_cast<u64>(ys.back() - ys.front())};\n\
    \    LazySegmentTree<S> seg{init};\n    u64 res{};\n    for (u32 x{} ; x < xs.size()\
    \ ; x++) {\n        if (x >= 1u) {\n            auto [min, count]{seg.product(0,\
    \ init.size())};\n            res += (all - (min == 0 ? count : u64{})) * (xs[x]\
    \ - xs[x - 1]);\n        }\n        for (const auto& [lr, v] : event[x]) {\n \
    \           seg.operation(lr.first, lr.second, (v ? +1 : -1));\n        }\n  \
    \  }\n    return res;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/AdditionMonoid.hpp
  - Src/Algebra/Monoid/MinCountMonoid.hpp
  - Src/DataStructure/SegmentTree/LazySegmentTree.hpp
  - Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: false
  path: Src/Utility/AreaOfUnionOfRectangles.hpp
  requiredBy: []
  timestamp: '2025-06-25 16:48:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/area_of_union_of_rectangles.test.cpp
  - Test/AtCoder/abc346_g.test.cpp
documentation_of: Src/Utility/AreaOfUnionOfRectangles.hpp
layout: document
redirect_from:
- /library/Src/Utility/AreaOfUnionOfRectangles.hpp
- /library/Src/Utility/AreaOfUnionOfRectangles.hpp.html
title: Src/Utility/AreaOfUnionOfRectangles.hpp
---
