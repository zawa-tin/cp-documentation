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
    \    using Value = typename Monoid::Element;\nprivate:\n    constexpr u32 left(u32\
    \ v) const {\n        return v << 1;\n    }\n    constexpr u32 right(u32 v) const\
    \ {\n        return v << 1 | 1;\n    }\n    constexpr u32 parent(u32 v) const\
    \ {\n        return v >> 1;\n    }\n\n    usize n_;\n    std::vector<Value> dat_;\n\
    \npublic:\n    SegmentTree() = default;\n    SegmentTree(u32 n) : n_{ n }, dat_(n\
    \ << 1, Monoid::identity()) {\n        assert(n_);\n    }\n    SegmentTree(const\
    \ std::vector<Value>& dat) : n_{ dat.size() }, dat_(dat.size() << 1, Monoid::identity())\
    \ {\n        assert(n_);\n        for (u32 i{} ; i < n_ ; i++) {\n           \
    \ dat_[i + n_] = dat[i];\n        }\n        for (u32 i{static_cast<u32>(n_) -\
    \ 1} ; i ; i--) {\n            dat_[i] = Monoid::operation(dat_[left(i)], dat_[right(i)]);\n\
    \        }\n    }\n\n    Value get(u32 i) const {\n        assert(i < n_);\n \
    \       return dat_[i + n_];\n    }\n\n    void operation(u32 i, const Value&\
    \ value) {\n        assert(i < n_);\n        i += n_;\n        dat_[i] = Monoid::operation(dat_[i],\
    \ value);\n        while (i = parent(i), i) {\n            dat_[i] = Monoid::operation(dat_[left(i)],\
    \ dat_[right(i)]);\n        }\n    }\n\n    void set(u32 i, const Value& value)\
    \ {\n        assert(i < n_);\n        i += n_;\n        dat_[i] = value;\n   \
    \     while (i = parent(i), i) {\n            dat_[i] = Monoid::operation(dat_[left(i)],\
    \ dat_[right(i)]);\n        }\n    }\n\n    Value product(u32 l, u32 r) const\
    \ {\n        assert(l <= r and r <= n_);\n        Value leftValue{ Monoid::identity()\
    \ }, rightValue{ Monoid::identity() };\n        for (l += n_, r += n_ ; l < r\
    \ ; l = parent(l), r = parent(r)) {\n            if (l & 1) {\n              \
    \  leftValue = Monoid::operation(leftValue, dat_[l++]);\n            }\n     \
    \       if (r & 1) {\n                rightValue = Monoid::operation(dat_[--r],\
    \ rightValue);\n            }\n        }\n        return Monoid::operation(leftValue,\
    \ rightValue);\n    }\n\n    template <class Function>\n    u32 maxRight(u32 l,\
    \ const Function& f) {\n        assert(l < n_);\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(Value)>>, \"maxRight's argument f must be function bool(T)\"\
    );\n        assert(f(Monoid::identity()));\n        u32 res{l}, width{1};\n  \
    \      Value prod{ Monoid::identity() };\n        // \u73FE\u5728\u306E\u898B\u3066\
    \u3044\u308B\u9802\u70B9\u306E\u5E45\u3092width\u3067\u6301\u3064\n        //\
    \ \u5883\u754C\u304C\u3042\u308B\u9802\u70B9\u3092\u542B\u3080\u90E8\u5206\u6728\
    \u306E\u6839\u3092\u63A2\u3059\n        // (\u6298\u308A\u8FD4\u3059\u6642\u306F\
    \u5FC5\u8981\u4EE5\u4E0A\u306E\u5E45\u3092\u6301\u3064\u6839\u306B\u306A\u308B\
    \u304C\u3001width\u3092\u6301\u3063\u3066\u3044\u308B\u306E\u3067\u30AA\u30FC\u30D0\
    \u30FC\u3057\u306A\u3044)\n        for (l += n_ ; res + width <= n_ ; l = parent(l),\
    \ width <<= 1) if (l & 1) {\n            if (not f(Monoid::operation(prod, dat_[l])))\
    \ break; \n            res += width;\n            prod = Monoid::operation(prod,\
    \ dat_[l++]);\n        }\n        // \u6839\u304B\u3089\u4E0B\u3063\u3066\u3001\
    \u5883\u754C\u3092\u767A\u898B\u3059\u308B\n        while (l = left(l), width\
    \ >>= 1) {\n            if (res + width <= n_ and f(Monoid::operation(prod, dat_[l])))\
    \ {\n                res += width;\n                prod = Monoid::operation(prod,\
    \ dat_[l++]);\n            } \n        }\n        return res;\n    }\n\n    template\
    \ <class Function>\n    u32 minLeft(u32 r, const Function& f) const {\n      \
    \  assert(r <= n_);\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(Value)>>, \"minLeft's argument f must be function bool(T)\"\
    );\n        assert(f(Monoid::identity()));\n        u32 res{r}, width{1};\n  \
    \      Value prod{ Monoid::identity() };\n        for (r += n_ ; res >= width\
    \ ; r = parent(r), width <<= 1) if (r & 1) {\n            if (not f(Monoid::operation(dat_[r\
    \ - 1], prod))) break;\n            res -= width;\n            prod = Monoid::operation(prod,\
    \ dat_[--r]);\n        }\n        while (r = left(r), width >>= 1) {\n       \
    \     if (res >= width and f(Monoid::operation(dat_[r - 1], prod))) {\n      \
    \          res -= width;\n                prod = Monoid::operation(dat_[--r],\
    \ prod);\n            }\n        }\n        return res;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const SegmentTree& st) {\n        for (u32 i{1}\
    \ ; i < 2 * st.n_ ; i++) {\n            os << st.dat_[i] << (i + 1 == 2 * st.n_\
    \ ? \"\" : \" \");\n        }\n        return os;\n    }\n};\n\n} // namespace\
    \ zawa\n#line 7 \"Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp\"\n\n\
    #line 10 \"Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp\"\n\nnamespace\
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
  timestamp: '2025-06-16 14:43:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/point_add_rectangle_sum/OfflineSegmentTree2D.test.cpp
  - Test/AtCoder/tdpc_target.test.cpp
documentation_of: Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp
- /library/Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp.html
title: Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp
---
