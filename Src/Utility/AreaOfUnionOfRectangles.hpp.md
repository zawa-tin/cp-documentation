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
    path: Src/DataStructure/SegmentTree/LazySegmentTree.hpp
    title: Lazy Segment Tree
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
    \ 2 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\n\n#line 4 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\
    \n\n#include <vector>\n#include <iterator>\n#include <cassert>\n#include <ostream>\n\
    \n#include <iostream>\n\nnamespace zawa {\n\ntemplate <class Structure>\nclass\
    \ LazySegmentTree {\npublic:\n    using VM = typename Structure::ValueMonoid;\n\
    \    using OM = typename Structure::OperatorMonoid;\n    using Value = typename\
    \ VM::Element;\n    using Operator = typename OM::Element;\n\nprivate:\n    static\
    \ constexpr u32 parent(u32 v) noexcept {\n        return v >> 1;\n    }\n    static\
    \ constexpr u32 left(u32 v) noexcept {\n        return v << 1;\n    }\n    static\
    \ constexpr u32 right(u32 v) noexcept {\n        return v << 1 | 1;\n    }\n \
    \   static constexpr u32 depth(u32 v) noexcept {\n        return 31u - __builtin_clz(v);\n\
    \    }\n    static constexpr u32 trailingZeros(u32 v) noexcept {\n        return\
    \ __builtin_ctz(v);\n    }\n\n    struct Node {\n        Value v_{ VM::identity()\
    \ };\n        Operator o_{ OM::identity() };\n        Node() = default;\n    \
    \    Node(const Value& v, const Operator& o) : v_{v}, o_{o} {}\n    };\n\n   \
    \ usize n_{};\n    std::vector<Node> dat_;\n\n    static Value action(const Node&\
    \ node) {\n        return Structure::mapping(node.v_, node.o_);\n    }\n\n   \
    \ // \u30CE\u30FC\u30C9v\u306E\u5B50\u306B\u4F5C\u7528\u3092\u4F1D\u64AD\u3055\
    \u305B\u308B\n    void propagate(u32 v) {\n        dat_[left(v)].o_ = OM::operation(dat_[left(v)].o_,\
    \ dat_[v].o_);\n        dat_[right(v)].o_ = OM::operation(dat_[right(v)].o_, dat_[v].o_);\n\
    \        dat_[v].o_ = OM::identity();\n    }\n\n    // \u30CE\u30FC\u30C9v\u306E\
    \u7956\u5148\u306E\u30CE\u30FC\u30C9\u306E\u4F5C\u7528\u7D20\u3092\u5168\u3066\
    \u9069\u7528\u3059\u308B\n    void propagateAncestor(u32 v) {\n        u32 dep{depth(v)};\n\
    \        u32 zeros{trailingZeros(v)};\n        for (u32 d{dep} ; d != zeros ;\
    \ d--) {\n            propagate(v >> d);\n        }\n    }\n\n    // \u30CE\u30FC\
    \u30C9v\u306E\u5024\u3092\u518D\u8A08\u7B97\u3059\u308B\n    void recalc(u32 v)\
    \ {\n        dat_[v].v_ = VM::operation(action(dat_[left(v)]), action(dat_[right(v)]));\n\
    \    }\n\n    // \u8981\u7D20v\u3092\u6301\u3064\u30CE\u30FC\u30C9\u306E\u7956\
    \u5148\u3092\u518D\u8A08\u7B97\u3059\u308B\n    void recalcAncestor(u32 v) {\n\
    \        v >>= trailingZeros(v);\n        for (v = parent(v) ; v ; v = parent(v))\
    \ {\n            recalc(v);\n        }\n    }\n\n    template <class InputIterator>\n\
    \    void datInit(InputIterator first) {\n        auto it{first};\n        for\
    \ (u32 i{} ; i < n_ ; i++) {\n            dat_[i + n_].v_ = *it;\n           \
    \ it++;\n        }\n        for (u32 i{static_cast<u32>(n_)} ; --i ; ) {\n   \
    \         dat_[i].v_ = VM::operation(dat_[left(i)].v_, dat_[right(i)].v_);\n \
    \       }\n    }\n\npublic:\n    \n    LazySegmentTree() = default;\n    LazySegmentTree(usize\
    \ n) : n_{n}, dat_((n << 1)) {\n        assert(n_);\n    }\n    LazySegmentTree(const\
    \ std::vector<Value>& a) : n_{a.size()}, dat_((a.size() << 1)) {\n        assert(!a.empty());\n\
    \        datInit(a.begin());\n    }\n    template <class InputIterator>\n    LazySegmentTree(InputIterator\
    \ first, InputIterator last) \n        : n_{static_cast<usize>(std::distance(first,\
    \ last))}, dat_(std::distance(first, last) << 1) {\n        assert(n_);\n    \
    \    datInit(first);\n    }\n\n    usize size() const noexcept {\n        return\
    \ n_;\n    }\n\n    void operation(u32 i, const Operator& o) {\n        assert(i\
    \ < n_);\n        i += size();\n        propagateAncestor(i);\n        dat_[i].o_\
    \ = OM::operation(dat_[i].o_, o);\n        recalcAncestor(i);\n    }\n\n    void\
    \ operation(u32 L, u32 R, const Operator& o) {\n        assert(L <= R and R <=\
    \ n_);\n        L += size();\n        R += size();\n        propagateAncestor(L);\n\
    \        propagateAncestor(R);\n        for (u32 l = L, r = R ; l < r ; l = parent(l),\
    \ r = parent(r)) {\n            if (l & 1) {\n                dat_[l].o_ = OM::operation(dat_[l].o_,\
    \ o);\n                l++;\n            }\n            if (r & 1) {\n       \
    \         r--;\n                dat_[r].o_ = OM::operation(dat_[r].o_, o);\n \
    \           }\n        }\n        recalcAncestor(L);\n        recalcAncestor(R);\n\
    \    }\n\n    void set(u32 i, const Value& v) {\n        assert(i < n_);\n   \
    \     i += size();\n        for (u32 d{depth(i)} ; d ; d--) {\n            propagate(i\
    \ >> d);\n        }\n        dat_[i] = Node{ v, OM::identity() };\n        for\
    \ (i = parent(i) ; i ; i = parent(i)) {\n            recalc(i);\n        }\n \
    \   }\n\n    Value operator[](u32 i) {\n        assert(i < n_);\n        i +=\
    \ size();\n        for (u32 d{depth(i)} ; d ; d--) {\n            propagate(i\
    \ >> d);\n        }\n        return action(dat_[i]);\n    }\n\n    Value product(u32\
    \ L, u32 R) {\n        assert(L <= R and R <= n_);\n        L += size();\n   \
    \     R += size();\n        propagateAncestor(L);\n        propagateAncestor(R);\n\
    \        recalcAncestor(L);\n        recalcAncestor(R);\n        Value l{VM::identity()},\
    \ r{VM::identity()};\n        for ( ; L < R ; L = parent(L), R = parent(R)) {\n\
    \            if (L & 1) {\n                l = VM::operation(l, action(dat_[L]));\n\
    \                L++;\n            }\n            if (R & 1) {\n             \
    \   R--;\n                r = VM::operation(action(dat_[R]), r);\n           \
    \ }\n        }\n        return VM::operation(l, r);\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const LazySegmentTree& seg) {\n        usize size{seg.dat_.size()};\n\
    \        os << \"Value :\\n\";\n        for (u32 i{1} ; i < size ; i++) {\n  \
    \          os << seg.dat_[i].v_ << (i + 1 == size ? \"\\n\" : \" \");\n      \
    \  }\n        os << \"Operator :\\n\";\n        for (u32 i{1} ; i < size ; i++)\
    \ {\n            os << seg.dat_[i].o_ << (i + 1 == size ? \"\\n\" : \" \");\n\
    \        }\n        os << \"Action :\\n\";\n        for (u32 i{1} ; i < size ;\
    \ i++) {\n            os << action(seg.dat_[i]) << (i + 1 == size ? \"\\n\" :\
    \ \" \");\n        }\n        return os;\n    }\n\n/*\n    template <class F>\n\
    \    u32 maxRight(u32 l, const F& f) {\n\n    }\n\n    template <class F>\n  \
    \  u32 minLeft(u32 r, const F& f) {\n\n    }\n*/\n};\n\n} // namespace zawa\n\
    #line 7 \"Src/Utility/AreaOfUnionOfRectangles.hpp\"\n\n#include <algorithm>\n\
    #line 10 \"Src/Utility/AreaOfUnionOfRectangles.hpp\"\n#include <type_traits>\n\
    #line 12 \"Src/Utility/AreaOfUnionOfRectangles.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nclass Rectangle {\npublic:\n\n    Rectangle() = default;\n     \n\
    \    Rectangle(T l, T d, T r, T u)\n        : l_{l}, d_{d}, r_{r}, u_{u} {\n \
    \       assert(l <= r);\n        assert(d <= u);\n    }\n\n    Rectangle(const\
    \ std::pair<T, T>& ld, const std::pair<T, T>& ru)\n        : l_{ld.first}, d_{ld.second},\
    \ r_{ru.first}, u_{ru.second} {}\n\n    Rectangle(const std::pair<T, T>& ld, T\
    \ w, T h)\n        : l_{ld.first}, d_{ld.second}, r_{l_ + w}, u_{d_ + h} {}\n\n\
    \    inline T left() const noexcept {\n        return l_;\n    }\n\n    inline\
    \ T right() const noexcept {\n        return r_;\n    }\n\n    inline T down()\
    \ const noexcept {\n        return d_;\n    }\n\n    inline T up() const noexcept\
    \ {\n        return u_;\n    }\n\nprivate:\n    // \u5DE6\u4E0B\u3001\u53F3\u4E0A\
    \n    T l_{}, d_{}, r_{}, u_{};\n};\n\nnamespace internal {\n\nstruct AreaOfUnionOfRectanglesStructure\
    \ {\n    using ValueMonoid = MinCountMonoid<i32, u64>;\n    using OperatorMonoid\
    \ = AdditionMonoid<i32>;\n    static ValueMonoid::Element mapping(const ValueMonoid::Element&\
    \ V, const OperatorMonoid::Element& R) {\n        return ValueMonoid::Element{\
    \ V.first + R, V.second };\n    }\n    static ValueMonoid::Element generate(u64\
    \ v) {\n        return ValueMonoid::Element{ 0, v };\n    }\n};\n\n} // namespace\
    \ internal\n\ntemplate <class T, class InputIterator>\nu64 AreaOfUnionOfRectangles(InputIterator\
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
  isVerificationFile: false
  path: Src/Utility/AreaOfUnionOfRectangles.hpp
  requiredBy: []
  timestamp: '2024-11-05 03:06:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc346_g.test.cpp
  - Test/LC/area_of_union_of_rectangles.test.cpp
documentation_of: Src/Utility/AreaOfUnionOfRectangles.hpp
layout: document
redirect_from:
- /library/Src/Utility/AreaOfUnionOfRectangles.hpp
- /library/Src/Utility/AreaOfUnionOfRectangles.hpp.html
title: Src/Utility/AreaOfUnionOfRectangles.hpp
---
