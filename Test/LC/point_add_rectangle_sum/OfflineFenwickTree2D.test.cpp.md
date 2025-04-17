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
    path: Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp
    title: Fenwick Tree 2D (Offline Query)
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
    \n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\n\
    namespace zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n    using\
    \ Element = T;\n    static constexpr T identity() noexcept {\n        return T{};\n\
    \    }\n    static constexpr T operation(const T& l, const T& r) noexcept {\n\
    \        return l + r;\n    }\n    static constexpr T inverse(const T& v) noexcept\
    \ {\n        return -v;\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp\"\
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
    \n} // namespace zawa\n#line 2 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\n#line 5 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n#include <ostream>\n#include <functional>\n#include <type_traits>\n\
    \nnamespace zawa {\n\ntemplate <concepts::Group Group>\nclass FenwickTree {\n\
    private:\n    using Value = typename Group::Element;\n\n    usize n_;\n    u32\
    \ bitWidth_;\n    std::vector<Value> a_, dat_;\n\n    constexpr i32 lsb(i32 x)\
    \ const noexcept {\n        return x & -x;\n    }\n    \n    // a[i] <- a[i] +\
    \ v\n    void addDat(i32 i, const Value& v) {\n        assert(0 <= i and i < static_cast<i32>(n_));\n\
    \        for ( i++ ; i < static_cast<i32>(dat_.size()) ; i += lsb(i)) {\n    \
    \        dat_[i] = Group::operation(dat_[i], v);\n        }\n    }\n\n    // return\
    \ a[0] + a[1] + .. + a[i - 1]\n    Value product(i32 i) const {\n        assert(0\
    \ <= i and i <= static_cast<i32>(n_));\n        Value res{ Group::identity() };\n\
    \        for ( ; i > 0 ; i -= lsb(i)) {\n            res = Group::operation(res,\
    \ dat_[i]);\n        }\n        return res;\n    }\n\npublic:\n    FenwickTree()\
    \ : n_{}, bitWidth_{}, a_{}, dat_{} {}\n\n    FenwickTree(usize n) : n_{ n },\
    \ bitWidth_{ std::__lg(static_cast<u32>(n)) + 1 }, a_(n), dat_(n + 1, Group::identity())\
    \ {\n        dat_.shrink_to_fit();\n    }\n\n    FenwickTree(const std::vector<Value>&\
    \ a) : n_{ a.size() }, bitWidth_{ std::__lg(static_cast<u32>(a.size())) + 1 },\
    \ a_(a), dat_(a.size() + 1, Group::identity()) {\n        dat_.shrink_to_fit();\
    \  \n        for (i32 i{} ; i < static_cast<i32>(n_) ; i++) {\n            addDat(i,\
    \ a[i]);\n        }\n    }\n\n    // return a[i]\n    const Value& get(usize i)\
    \ const noexcept {\n        assert(i < n_);\n        return a_[i];\n    }\n\n\
    \    // return a[i]\n    const Value& operator[](usize i) const noexcept {\n \
    \       assert(i < n_);\n        return a_[i];\n    }\n\n    usize size() const\
    \ noexcept {\n        return n_;\n    }\n\n    // a[i] <- a[i] + v\n    void operation(usize\
    \ i, const Value& v) {\n        assert(i < n_);\n        addDat(i, v);\n     \
    \   a_[i] = Group::operation(a_[i], v);\n    }\n\n    // a[i] <- v\n    void set(usize\
    \ i, const Value& v) {\n        assert(i < n_);\n        addDat(i, Group::operation(Group::inverse(a_[i]),\
    \ v));\n        a_[i] = v;\n    }\n\n    // return a[0] + a[1] + ... + a[r - 1]\n\
    \    Value prefixProduct(usize r) const {\n        assert(r <= n_);\n        return\
    \ product(r);\n    }\n\n    // return a[l] + a[l + 1] ... + a[r - 1]\n    Value\
    \ product(usize l, usize r) const {\n        assert(l <= r and r <= n_);\n   \
    \     return Group::operation(Group::inverse(product(l)), product(r));\n    }\n\
    \n    template <class Function>\n    u32 maxRight(usize l, const Function& f)\
    \ const {\n        static_assert(std::is_convertible_v<decltype(f), std::function<bool(Value)>>,\
    \ \"maxRight's argument f must be function bool(T)\");\n        assert(l < n_);\n\
    \        Value sum{ Group::inverse(product(l)) }; \n        u32 r{};\n       \
    \ for (u32 bit{ bitWidth_ } ; bit ; ) {\n            bit--;\n            u32 nxt{\
    \ r | (1u << bit) };\n            if (nxt < dat_.size() and f(Group::operation(sum,\
    \ dat_[nxt]))) {\n                sum = Group::operation(sum, dat_[nxt]);\n  \
    \              r = std::move(nxt);\n            }\n        }\n        assert(l\
    \ <= r);\n        return r;\n    }\n\n    template <class Function>\n    u32 minLeft(usize\
    \ r, const Function& f) const {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(Value)>>, \"minLeft's argument f must be function bool(T)\"\
    );\n        assert(r <= n_);\n        Value sum{ product(r) };\n        u32 l{};\n\
    \        for (u32 bit{ bitWidth_ } ; bit ; ) {\n            bit--;\n         \
    \   u32 nxt{ l | (1u << bit) };\n            if (nxt <= r and not f(Group::operation(Group::inverse(dat_[nxt]),\
    \ sum))) {\n                sum = Group::operation(Group::inverse(dat_[nxt]),\
    \ sum);\n                l = std::move(nxt);\n            }\n        }\n     \
    \   assert(l <= r);\n        return l;\n    }\n\n    // debug print\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const FenwickTree& ft) {\n      \
    \  for (u32 i{} ; i <= ft.size() ; i++) {\n            os << ft.prefixProduct(i)\
    \ << (i == ft.size() ? \"\" : \" \");\n        }\n        return os;\n    }\n\
    };\n\n\n} // namespace zawa\n#line 2 \"Src/Sequence/CompressedSequence.hpp\"\n\
    \n#line 4 \"Src/Sequence/CompressedSequence.hpp\"\n\n#line 6 \"Src/Sequence/CompressedSequence.hpp\"\
    \n#include <algorithm>\n#line 8 \"Src/Sequence/CompressedSequence.hpp\"\n#include\
    \ <iterator>\n#include <limits>\n\nnamespace zawa {\n\ntemplate <class T>\nclass\
    \ CompressedSequence {\npublic:\n\n    static constexpr u32 NotFound = std::numeric_limits<u32>::max();\n\
    \n    CompressedSequence() = default;\n\n    template <class InputIterator>\n\
    \    CompressedSequence(InputIterator first, InputIterator last) : comped_(first,\
    \ last), f_{} {\n        std::sort(comped_.begin(), comped_.end());\n        comped_.erase(std::unique(comped_.begin(),\
    \ comped_.end()), comped_.end());\n        comped_.shrink_to_fit();\n        f_.reserve(std::distance(first,\
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
    } // namespace zawa\n#line 7 \"Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp\"\
    \n\n#line 9 \"Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp\"\n#include\
    \ <utility>\n#line 11 \"Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp\"\
    \n#include <tuple>\n\nnamespace zawa {\n\nnamespace internal {\n\ntemplate <class\
    \ T, concepts::Group G>\nclass FenwickTree2D {\npublic:\n\n    using V = G::Element;\n\
    \n    FenwickTree2D() = default;\n\n    FenwickTree2D(const std::vector<T>& px,\
    \ const std::vector<T>& py) \n        : xs_{px}, ys_(xs_.size() + 1), fen_(xs_.size()\
    \ + 1) {\n        assert(px.size());\n        assert(px.size() == py.size());\n\
    \        std::vector<std::vector<T>> appy(xs_.size() + 1);\n        for (usize\
    \ i = 0 ; i < px.size() ; i++) {\n            auto x = xs_[px[i]];\n         \
    \   for (x++ ; x < appy.size() ; x += lsb(x)) {\n                appy[x].push_back(py[i]);\n\
    \            }\n        }\n        for (usize i = 1 ; i < fen_.size() ; i++) {\n\
    \            ys_[i] = CompressedSequence{appy[i]};\n            fen_[i] = FenwickTree<G>{ys_[i].size()};\n\
    \        }\n    }\n\n    void operation(const T& x, const T& y, const V& v) {\n\
    \        auto i = xs_.find(x);\n        assert(i != CompressedSequence<T>::NotFound);\n\
    \        for ( i++ ; i < fen_.size() ; i += lsb(i)) {\n            auto j = ys_[i].find(y);\n\
    \            assert(j != CompressedSequence<T>::NotFound);\n            fen_[i].operation(j,\
    \ v);\n        }\n    }\n\n    [[nodiscard]] V prefixProduct(const T& x, const\
    \ T& y) const {\n        V res = G::identity();\n        for (u32 i = xs_[x] ;\
    \ i ; i &= i - 1) {\n            res = G::operation(res, fen_[i].prefixProduct(ys_[i][y]));\
    \ \n        }\n        return res;\n    }\n\n    [[nodiscard]] V product(const\
    \ T& lx, const T& ly, const T& rx, const T& ry) const {\n        assert(lx <=\
    \ rx);\n        assert(ly <= ry);\n        V add = G::operation(prefixProduct(rx,\
    \ ry), prefixProduct(lx, ly));\n        V sub = G::operation(prefixProduct(rx,\
    \ ly), prefixProduct(lx, ry));\n        return G::operation(add, G::inverse(sub));\n\
    \    }\n\nprivate:\n\n    CompressedSequence<T> xs_;\n\n    std::vector<CompressedSequence<T>>\
    \ ys_;\n\n    std::vector<FenwickTree<G>> fen_;\n\n    static constexpr i32 lsb(i32\
    \ v) {\n        return v & -v;\n    }\n};\n\n} // namespace internal\n\ntemplate\
    \ <class T, concepts::Group G>\nclass OfflineFenwickTree2D {\npublic:\n\n    OfflineFenwickTree2D(usize\
    \ q = 0) {\n        xs_.reserve(q);\n        ys_.reserve(q);\n    }\n\n    void\
    \ operation(const T& x, const T& y) {\n        xs_.push_back(x);\n        ys_.push_back(y);\n\
    \    }\n\n    void operation(T&& x, T&& y) {\n        xs_.push_back(std::move(x));\n\
    \        ys_.push_back(std::move(y));\n    }\n\n    [[nodiscard]] internal::FenwickTree2D<T,\
    \ G> build() const {\n        return internal::FenwickTree2D<T, G>{xs_, ys_};\n\
    \    }\n\nprivate:\n\n    std::vector<T> xs_{}, ys_{};\n};\n\n} // namespace zawa\n\
    #line 6 \"Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp\"\n\n\
    using namespace zawa;\nint N, Q, X[100010], Y[100010], W[100010], T[100010], A[100010],\
    \ B[100010], C[100010], D[100010];\nint main() {\n    SetFastIO();\n    int N,\
    \ Q;\n    std::cin >> N >> Q;\n    for (int i = 0 ; i < N ; i++) std::cin >> X[i]\
    \ >> Y[i] >> W[i];\n    for (int i = 0 ; i < Q ; i++) {\n        std::cin >> T[i];\n\
    \        if (T[i] == 0) std::cin >> A[i] >> B[i] >> C[i];\n        else if (T[i]\
    \ == 1) std::cin >> A[i] >> B[i] >> C[i] >> D[i];\n    }\n    OfflineFenwickTree2D<int,\
    \ AdditiveGroup<long long>> fen{};\n    for (int i = 0 ; i < N ; i++) fen.operation(X[i],\
    \ Y[i]);\n    for (int i = 0 ; i < Q ; i++) if (T[i] == 0) fen.operation(A[i],\
    \ B[i]);\n    auto exe = fen.build();\n    for (int i = 0 ; i < N ; i++) exe.operation(X[i],\
    \ Y[i], W[i]);\n    for (int i = 0 ; i < Q ; i++) {\n        if (T[i] == 0) exe.operation(A[i],\
    \ B[i], C[i]);\n        else std::cout << exe.product(A[i], B[i], C[i], D[i])\
    \ << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../../../Src/Template/IOSetting.hpp\"\n#include \"../../../Src/Algebra/Group/AdditiveGroup.hpp\"\
    \n#include \"../../../Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp\"\
    \n\nusing namespace zawa;\nint N, Q, X[100010], Y[100010], W[100010], T[100010],\
    \ A[100010], B[100010], C[100010], D[100010];\nint main() {\n    SetFastIO();\n\
    \    int N, Q;\n    std::cin >> N >> Q;\n    for (int i = 0 ; i < N ; i++) std::cin\
    \ >> X[i] >> Y[i] >> W[i];\n    for (int i = 0 ; i < Q ; i++) {\n        std::cin\
    \ >> T[i];\n        if (T[i] == 0) std::cin >> A[i] >> B[i] >> C[i];\n       \
    \ else if (T[i] == 1) std::cin >> A[i] >> B[i] >> C[i] >> D[i];\n    }\n    OfflineFenwickTree2D<int,\
    \ AdditiveGroup<long long>> fen{};\n    for (int i = 0 ; i < N ; i++) fen.operation(X[i],\
    \ Y[i]);\n    for (int i = 0 ; i < Q ; i++) if (T[i] == 0) fen.operation(A[i],\
    \ B[i]);\n    auto exe = fen.build();\n    for (int i = 0 ; i < N ; i++) exe.operation(X[i],\
    \ Y[i], W[i]);\n    for (int i = 0 ; i < Q ; i++) {\n        if (T[i] == 0) exe.operation(A[i],\
    \ B[i], C[i]);\n        else std::cout << exe.product(A[i], B[i], C[i], D[i])\
    \ << '\\n';\n    }\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/DataStructure/FenwickTree/FenwickTree.hpp
  - Src/Sequence/CompressedSequence.hpp
  isVerificationFile: true
  path: Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp
  requiredBy: []
  timestamp: '2025-04-17 19:44:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp
- /verify/Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp.html
title: Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp
---
