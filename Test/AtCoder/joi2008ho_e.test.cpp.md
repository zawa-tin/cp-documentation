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
    path: Src/DataStructure/PrefixSum/Imos2D.hpp
    title: Src/DataStructure/PrefixSum/Imos2D.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/CompressedSequence.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
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
    - https://atcoder.jp/contests/joi2008ho/submissions/71931671
    - https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_e
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/joi2008ho_e.test.cpp\"\n// #define PROBLEM\
    \ \"https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_e\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\n\n/*\n\
    \ * \u7B2C7\u56DE\u65E5\u672C\u60C5\u5831\u30AA\u30EA\u30F3\u30D4\u30C3\u30AF\u672C\
    \u9078 (\u904E\u53BB\u554F) E - \u30DA\u30F3\u30AD\u306E\u8272\n * https://atcoder.jp/contests/joi2008ho/submissions/71931671\n\
    \ */\n\n#line 2 \"Src/Sequence/CompressedSequence.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Sequence/CompressedSequence.hpp\"\n\n#include\
    \ <vector>\n#include <algorithm>\n#include <cassert>\n#include <iterator>\n#include\
    \ <limits>\n\nnamespace zawa {\n\ntemplate <class T>\nclass CompressedSequence\
    \ {\npublic:\n\n    static constexpr u32 NotFound = std::numeric_limits<u32>::max();\n\
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
    } // namespace zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace\
    \ zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n    using Element\
    \ = T;\n    static constexpr T identity() noexcept {\n        return T{};\n  \
    \  }\n    static constexpr T operation(const T& l, const T& r) noexcept {\n  \
    \      return l + r;\n    }\n    static constexpr T inverse(const T& v) noexcept\
    \ {\n        return -v;\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/PrefixSum/Imos2D.hpp\"\
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
    \n} // namespace zawa\n#line 5 \"Src/DataStructure/PrefixSum/Imos2D.hpp\"\n\n\
    #line 7 \"Src/DataStructure/PrefixSum/Imos2D.hpp\"\n#include <utility>\n#line\
    \ 9 \"Src/DataStructure/PrefixSum/Imos2D.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ internal {\n\ntemplate <concepts::Group G>\nclass StaticRectAddSolver {\npublic:\n\
    \    \n    using T = typename G::Element;\n\n    using const_iterator = typename\
    \ std::vector<std::vector<T>>::const_iterator;\n\n    explicit StaticRectAddSolver(const\
    \ std::vector<std::vector<T>>& imos) : m_H{imos.size() - 1}, m_W{imos[0].size()\
    \ - 1}, m_a(imos) {\n        build();\n    }\n\n    explicit StaticRectAddSolver(std::vector<std::vector<T>>&&\
    \ imos) : m_H{imos.size() - 1}, m_W{imos[0].size() - 1}, m_a{std::move(imos)}\
    \ {\n        build();\n    }\n\n    inline usize size() const {\n        return\
    \ m_H;\n    }\n\n    inline usize height() const {\n        return m_H;\n    }\n\
    \n    inline usize width() const {\n        return m_W;\n    }\n\n    const_iterator\
    \ begin() const {\n        return m_a.begin();\n    }\n\n    const_iterator end()\
    \ const {\n        return m_a.end();\n    }\n\n    const std::vector<T>& operator[](usize\
    \ i) const {\n        assert(i < height() and \"invalid access m_sum[i]: StaticRectSumSolver::operator[]\"\
    );\n        return m_a[i];\n    }\n\nprivate:\n\n    usize m_H, m_W;\n\n    std::vector<std::vector<T>>\
    \ m_a;\n\n    void build() {\n        for (usize i = 0 ; i < m_H ; i++)\n    \
    \        for (usize j = 1 ; j <= m_W ; j++)\n                m_a[i][j] = G::operation(m_a[i][j],\
    \ m_a[i][j - 1]);\n        for (usize i = 1 ; i <= m_H ; i++)\n            for\
    \ (usize j = 0 ; j < m_W ; j++)\n                m_a[i][j] = G::operation(m_a[i][j],\
    \ m_a[i - 1][j]);\n    }\n};\n\n} // namespace internal\n\ntemplate <concepts::Group\
    \ G>\nclass Imos2D {\npublic:\n    \n    using T = typename G::Element;\n\n  \
    \  Imos2D(usize H, usize W) : m_H{H}, m_W{W}, m_imos(H + 1, std::vector<T>(W +\
    \ 1, G::identity())) {}\n\n    inline usize height() const {\n        return m_H;\n\
    \    }\n\n    inline usize width() const {\n        return m_W;\n    }\n\n   \
    \ // [l, r) x [d, u)\n    void operation(usize l, usize d, usize r, usize u, T\
    \ v) {\n        assert((l <= r and r <= height()) and \"invalid i range: Imos2D::add\"\
    );\n        assert((d <= u and u <= width()) and \"invalid j range: Imos2D::add\"\
    );\n        assert(m_moved == false and \"data is already builded: Imos2D::add\"\
    );\n        T inv = G::inverse(v);\n        m_imos[l][d] = G::operation(m_imos[l][d],\
    \ v);\n        m_imos[l][u] = G::operation(m_imos[l][u], inv);\n        m_imos[r][d]\
    \ = G::operation(m_imos[r][d], inv);\n        m_imos[r][u] = G::operation(m_imos[r][u],\
    \ v);\n    }\n\n    const std::vector<T>& operator[](const usize i) const {\n\
    \        assert(m_moved == false and \"data is already builded: Imos2D::operator[]\"\
    );\n        assert(i < height() and \"invalid range: Imos2D::operator[]\");\n\
    \        return m_imos[i];\n    }\n\n    internal::StaticRectAddSolver<G> build()\
    \ const {\n        assert(m_moved == false and \"data is already builded: Imos2D::build\"\
    );\n        return internal::StaticRectAddSolver<G>{m_imos};\n    }\n\n    internal::StaticRectAddSolver<G>\
    \ destructiveBuild() {\n        assert(m_moved == false and \"data is already\
    \ builded: Imos2D::build\");\n        m_moved = true;\n        return internal::StaticRectAddSolver<G>{std::move(m_imos)};\n\
    \    }\n\nprivate:\n\n    usize m_H = 0, m_W = 0;\n\n    std::vector<std::vector<T>>\
    \ m_imos;\n\n    bool m_moved = false;\n};\n\n} // namespace zawa\n#line 12 \"\
    Test/AtCoder/joi2008ho_e.test.cpp\"\n\n#include <iostream>\n#line 15 \"Test/AtCoder/joi2008ho_e.test.cpp\"\
    \n\nnamespace zawa {}\nusing namespace zawa;\nusing namespace std;\nint main()\
    \ {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int W, H, N;\n    cin >> W >> H >> N;\n    vector<int> xs{0, W - 1}, ys{0,\
    \ H - 1};\n    vector<tuple<int, int, int, int>> ita(N);\n    for (auto& [l, d,\
    \ r, u] : ita) {\n        cin >> l >> d >> r >> u;\n        xs.push_back(l);\n\
    \        if (r < W)\n            xs.push_back(r);\n        ys.push_back(d);\n\
    \        if (u < H)\n            ys.push_back(u);\n    }\n    CompressedSequence\
    \ cx{xs}, cy{ys};\n    Imos2D<AdditiveGroup<int>> imos(cx.size(), cy.size());\
    \ \n    for (auto [l, d, r, u] : ita) {\n        imos.operation(cx[l], cy[d],\
    \ cx[r], cy[u], 1);\n    }\n    auto solver = imos.destructiveBuild();\n    vector\
    \ id(cx.size(), vector<int>(cy.size(), -1));\n    int ans = 0;\n    for (int i\
    \ = 0 ; i < ssize(cx) and cx.inverse(i) < W ; i++) \n        for (int j = 0 ;\
    \ j < ssize(cy) and cy.inverse(j) < H ; j++) \n            if (id[i][j] == -1\
    \ and solver[i][j] == 0) {\n                vector<pair<int, int>> que;\n    \
    \            que.emplace_back(i, j);\n                ans++;\n               \
    \ for (int t = 0 ; t < ssize(que) ; t++) {\n                    auto [x, y] =\
    \ que[t];\n                    if (x - 1 >= 0 and id[x - 1][y] == -1 and solver[x\
    \ - 1][y] == 0) {\n                        id[x - 1][y] = 1;\n               \
    \         que.emplace_back(x - 1, y);\n                    }\n               \
    \     if (x + 1 < ssize(cx) and cx.inverse(x + 1) < W and id[x + 1][y] == -1 and\
    \ solver[x + 1][y] == 0) {\n                        id[x + 1][y] = 1;\n      \
    \                  que.emplace_back(x + 1, y);\n                    }\n      \
    \              if (y - 1 >= 0 and id[x][y - 1] == -1 and solver[x][y - 1] == 0)\
    \ {\n                        id[x][y - 1] = 1;\n                        que.emplace_back(x,\
    \ y - 1);\n                    }\n                    if (y + 1 < ssize(cy) and\
    \ cy.inverse(y + 1) < H and id[x][y + 1] == -1 and solver[x][y + 1] == 0) {\n\
    \                        id[x][y + 1] = 1;\n                        que.emplace_back(x,\
    \ y + 1);\n                    }\n                }\n            }\n    cout <<\
    \ ans << '\\n';\n#else\n    cout << \"Hello World\\n\";\n#endif\n}\n\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_e\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * \u7B2C7\u56DE\u65E5\u672C\u60C5\u5831\u30AA\u30EA\u30F3\u30D4\u30C3\
    \u30AF\u672C\u9078 (\u904E\u53BB\u554F) E - \u30DA\u30F3\u30AD\u306E\u8272\n *\
    \ https://atcoder.jp/contests/joi2008ho/submissions/71931671\n */\n\n#include\
    \ \"../../Src/Sequence/CompressedSequence.hpp\"\n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\
    \n#include \"../../Src/DataStructure/PrefixSum/Imos2D.hpp\"\n\n#include <iostream>\n\
    #include <cassert>\n\nnamespace zawa {}\nusing namespace zawa;\nusing namespace\
    \ std;\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int W, H, N;\n    cin >> W >> H >> N;\n    vector<int> xs{0, W - 1}, ys{0,\
    \ H - 1};\n    vector<tuple<int, int, int, int>> ita(N);\n    for (auto& [l, d,\
    \ r, u] : ita) {\n        cin >> l >> d >> r >> u;\n        xs.push_back(l);\n\
    \        if (r < W)\n            xs.push_back(r);\n        ys.push_back(d);\n\
    \        if (u < H)\n            ys.push_back(u);\n    }\n    CompressedSequence\
    \ cx{xs}, cy{ys};\n    Imos2D<AdditiveGroup<int>> imos(cx.size(), cy.size());\
    \ \n    for (auto [l, d, r, u] : ita) {\n        imos.operation(cx[l], cy[d],\
    \ cx[r], cy[u], 1);\n    }\n    auto solver = imos.destructiveBuild();\n    vector\
    \ id(cx.size(), vector<int>(cy.size(), -1));\n    int ans = 0;\n    for (int i\
    \ = 0 ; i < ssize(cx) and cx.inverse(i) < W ; i++) \n        for (int j = 0 ;\
    \ j < ssize(cy) and cy.inverse(j) < H ; j++) \n            if (id[i][j] == -1\
    \ and solver[i][j] == 0) {\n                vector<pair<int, int>> que;\n    \
    \            que.emplace_back(i, j);\n                ans++;\n               \
    \ for (int t = 0 ; t < ssize(que) ; t++) {\n                    auto [x, y] =\
    \ que[t];\n                    if (x - 1 >= 0 and id[x - 1][y] == -1 and solver[x\
    \ - 1][y] == 0) {\n                        id[x - 1][y] = 1;\n               \
    \         que.emplace_back(x - 1, y);\n                    }\n               \
    \     if (x + 1 < ssize(cx) and cx.inverse(x + 1) < W and id[x + 1][y] == -1 and\
    \ solver[x + 1][y] == 0) {\n                        id[x + 1][y] = 1;\n      \
    \                  que.emplace_back(x + 1, y);\n                    }\n      \
    \              if (y - 1 >= 0 and id[x][y - 1] == -1 and solver[x][y - 1] == 0)\
    \ {\n                        id[x][y - 1] = 1;\n                        que.emplace_back(x,\
    \ y - 1);\n                    }\n                    if (y + 1 < ssize(cy) and\
    \ cy.inverse(y + 1) < H and id[x][y + 1] == -1 and solver[x][y + 1] == 0) {\n\
    \                        id[x][y + 1] = 1;\n                        que.emplace_back(x,\
    \ y + 1);\n                    }\n                }\n            }\n    cout <<\
    \ ans << '\\n';\n#else\n    cout << \"Hello World\\n\";\n#endif\n}\n\n"
  dependsOn:
  - Src/Sequence/CompressedSequence.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/DataStructure/PrefixSum/Imos2D.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: true
  path: Test/AtCoder/joi2008ho_e.test.cpp
  requiredBy: []
  timestamp: '2025-12-23 17:18:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/joi2008ho_e.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/joi2008ho_e.test.cpp
- /verify/Test/AtCoder/joi2008ho_e.test.cpp.html
title: Test/AtCoder/joi2008ho_e.test.cpp
---
