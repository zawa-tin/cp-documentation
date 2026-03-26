---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/SegmentTree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/CompressedSequence.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/tdpc_target.test.cpp
    title: Test/AtCoder/tdpc_target.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_add_rectangle_sum/OfflineSegmentTree2D.test.cpp
    title: Test/LC/point_add_rectangle_sum/OfflineSegmentTree2D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 2 \"Src/Sequence/CompressedSequence.hpp\"\
    \n\n#line 4 \"Src/Sequence/CompressedSequence.hpp\"\n\n#include <vector>\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iterator>\n#include <limits>\n\n\
    namespace zawa {\n\ntemplate <class T>\nclass CompressedSequence {\npublic:\n\n\
    \    static constexpr u32 NotFound = std::numeric_limits<u32>::max();\n\n    CompressedSequence()\
    \ = default;\n\n    template <class InputIterator>\n    CompressedSequence(InputIterator\
    \ first, InputIterator last) : comped_(first, last), f_{} {\n        std::sort(comped_.begin(),\
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
    } // namespace zawa\n#line 2 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\
    \n\n#line 5 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\n\n#line 8 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\
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
    \ m_dat;\n};\n\n} // namespace zawa\n#line 7 \"Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp\"\
    \n\n#line 10 \"Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp\"\n\nnamespace\
    \ zawa {\n\nnamespace internal {\n\ntemplate <class T, concepts::Monoid M>\nclass\
    \ SegmentTree2D {\npublic:\n\n    using V = M::Element;\n\n    SegmentTree2D(const\
    \ std::vector<T>& xs, const std::vector<T>& ys)\n        : m_compx{xs}, m_compy(2\
    \ * m_compx.size()), m_seg(2 * m_compx.size()) {\n        std::vector<std::vector<T>>\
    \ app(2 * m_compx.size());\n        for (usize i = 0 ; i < xs.size() ; i++) {\n\
    \            T y = ys[i];\n            for (usize j = m_compx.map(i) + m_compx.size()\
    \ ; j ; j >>= 1) {\n                app[j].push_back(y);\n            }\n    \
    \    }\n        for (usize i = 1 ; i < app.size() ; i++) {\n           m_compy[i]\
    \ = CompressedSequence<T>(app[i]);\n           m_seg[i] = SegmentTree<M>(m_compy[i].size());\n\
    \        }\n    }\n\n    void set(const T& x, const T& y, const V& v) {\n    \
    \    auto i = m_compx.at(x);\n        for (i += m_compx.size() ; i ; i >>= 1)\
    \ {\n            m_seg[i].set(m_compy[i].at(y), v);\n        }\n    }\n\n    void\
    \ operation(const T& x, const T& y, const V& v) {\n        auto i = m_compx.at(x);\n\
    \        for (i += m_compx.size() ; i ; i >>= 1) {\n            m_seg[i].operation(m_compy[i].at(y),\
    \ v);\n        }\n    }\n\n    [[nodiscard]] V product(const T& l, const T& d,\
    \ const T& r, const T& u) const {\n        assert(l <= r and d <= u);\n      \
    \  V L = M::identity(), R = M::identity();\n        for (usize lidx = m_compx[l]\
    \ + m_compx.size(), ridx = m_compx[r] + m_compx.size() ; lidx < ridx ; lidx >>=\
    \ 1, ridx >>= 1) {\n            if (lidx & 1) {\n                L = M::operation(L,\
    \ m_seg[lidx].product(m_compy[lidx][d], m_compy[lidx][u]));\n                lidx++;\n\
    \            }\n            if (ridx & 1) {\n                ridx--;\n       \
    \         R = M::operation(m_seg[ridx].product(m_compy[ridx][d], m_compy[ridx][u]),\
    \ R);\n            }\n        }\n        return M::operation(L, R);\n    }\n\n\
    private:\n\n    CompressedSequence<T> m_compx;\n\n    std::vector<CompressedSequence<T>>\
    \ m_compy;\n\n    std::vector<SegmentTree<M>> m_seg;\n};\n\n} // namespace internal\n\
    \ntemplate <class T, concepts::Monoid M>\nclass OfflineSegmentTree2D {\npublic:\n\
    \n    OfflineSegmentTree2D(usize q = 0) {\n        m_xs.reserve(q);\n        m_ys.reserve(q);\n\
    \    }\n\n    void operation(const T& x, const T& y) {\n        m_xs.push_back(x);\n\
    \        m_ys.push_back(y);\n    }\n\n    void operation(T&& x, T&& y) {\n   \
    \     m_xs.push_back(std::move(x));\n        m_ys.push_back(std::move(y));\n \
    \   }\n\n    [[nodiscard]] internal::SegmentTree2D<T, M> build() const {\n   \
    \     return internal::SegmentTree2D<T, M>{m_xs, m_ys};\n    }\n\nprivate:\n\n\
    \    std::vector<T> m_xs{}, m_ys{};\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Algebra/Monoid/MonoidConcept.hpp\"\
    \n#include \"../../Sequence/CompressedSequence.hpp\"\n#include \"./SegmentTree.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\nnamespace zawa {\n\nnamespace internal\
    \ {\n\ntemplate <class T, concepts::Monoid M>\nclass SegmentTree2D {\npublic:\n\
    \n    using V = M::Element;\n\n    SegmentTree2D(const std::vector<T>& xs, const\
    \ std::vector<T>& ys)\n        : m_compx{xs}, m_compy(2 * m_compx.size()), m_seg(2\
    \ * m_compx.size()) {\n        std::vector<std::vector<T>> app(2 * m_compx.size());\n\
    \        for (usize i = 0 ; i < xs.size() ; i++) {\n            T y = ys[i];\n\
    \            for (usize j = m_compx.map(i) + m_compx.size() ; j ; j >>= 1) {\n\
    \                app[j].push_back(y);\n            }\n        }\n        for (usize\
    \ i = 1 ; i < app.size() ; i++) {\n           m_compy[i] = CompressedSequence<T>(app[i]);\n\
    \           m_seg[i] = SegmentTree<M>(m_compy[i].size());\n        }\n    }\n\n\
    \    void set(const T& x, const T& y, const V& v) {\n        auto i = m_compx.at(x);\n\
    \        for (i += m_compx.size() ; i ; i >>= 1) {\n            m_seg[i].set(m_compy[i].at(y),\
    \ v);\n        }\n    }\n\n    void operation(const T& x, const T& y, const V&\
    \ v) {\n        auto i = m_compx.at(x);\n        for (i += m_compx.size() ; i\
    \ ; i >>= 1) {\n            m_seg[i].operation(m_compy[i].at(y), v);\n       \
    \ }\n    }\n\n    [[nodiscard]] V product(const T& l, const T& d, const T& r,\
    \ const T& u) const {\n        assert(l <= r and d <= u);\n        V L = M::identity(),\
    \ R = M::identity();\n        for (usize lidx = m_compx[l] + m_compx.size(), ridx\
    \ = m_compx[r] + m_compx.size() ; lidx < ridx ; lidx >>= 1, ridx >>= 1) {\n  \
    \          if (lidx & 1) {\n                L = M::operation(L, m_seg[lidx].product(m_compy[lidx][d],\
    \ m_compy[lidx][u]));\n                lidx++;\n            }\n            if\
    \ (ridx & 1) {\n                ridx--;\n                R = M::operation(m_seg[ridx].product(m_compy[ridx][d],\
    \ m_compy[ridx][u]), R);\n            }\n        }\n        return M::operation(L,\
    \ R);\n    }\n\nprivate:\n\n    CompressedSequence<T> m_compx;\n\n    std::vector<CompressedSequence<T>>\
    \ m_compy;\n\n    std::vector<SegmentTree<M>> m_seg;\n};\n\n} // namespace internal\n\
    \ntemplate <class T, concepts::Monoid M>\nclass OfflineSegmentTree2D {\npublic:\n\
    \n    OfflineSegmentTree2D(usize q = 0) {\n        m_xs.reserve(q);\n        m_ys.reserve(q);\n\
    \    }\n\n    void operation(const T& x, const T& y) {\n        m_xs.push_back(x);\n\
    \        m_ys.push_back(y);\n    }\n\n    void operation(T&& x, T&& y) {\n   \
    \     m_xs.push_back(std::move(x));\n        m_ys.push_back(std::move(y));\n \
    \   }\n\n    [[nodiscard]] internal::SegmentTree2D<T, M> build() const {\n   \
    \     return internal::SegmentTree2D<T, M>{m_xs, m_ys};\n    }\n\nprivate:\n\n\
    \    std::vector<T> m_xs{}, m_ys{};\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Sequence/CompressedSequence.hpp
  - Src/DataStructure/SegmentTree/SegmentTree.hpp
  isVerificationFile: false
  path: Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp
  requiredBy: []
  timestamp: '2025-10-17 20:47:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/tdpc_target.test.cpp
  - Test/LC/point_add_rectangle_sum/OfflineSegmentTree2D.test.cpp
documentation_of: Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp
- /library/Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp.html
title: Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp
---
