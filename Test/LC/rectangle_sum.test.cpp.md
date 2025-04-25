---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/RectangleSum/RectangleSumOfPointCloud.hpp
    title: Rectangle Sum of PointCloud
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
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"Test/LC/rectangle_sum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\
    \n\n#line 2 \"Src/DataStructure/RectangleSum/RectangleSumOfPointCloud.hpp\"\n\n\
    #line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/RectangleSum/RectangleSumOfPointCloud.hpp\"\
    \n\n#include <algorithm>\n#include <concepts>\n#include <utility>\n#include <vector>\n\
    #include <type_traits>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T>\nconcept Point = requires (T p) {\n    typename T::P;\n    typename\
    \ T::W;\n    { p.x } -> std::same_as<typename T::P&>;\n    { p.y } -> std::same_as<typename\
    \ T::P&>;\n    { p.w } -> std::same_as<typename T::W&>;\n};\n\ntemplate <class\
    \ T>\nconcept Rectangle = requires (T r) {\n    typename T::P;\n    { r.l } ->\
    \ std::same_as<typename T::P&>;\n    { r.d } -> std::same_as<typename T::P&>;\n\
    \    { r.r } -> std::same_as<typename T::P&>;\n    { r.u } -> std::same_as<typename\
    \ T::P&>;\n};\n\ntemplate <class T, class U>\nconcept RSOPCQuery = Point<T> and\
    \ Rectangle<U> and std::same_as<typename T::P, typename U::P>;\n\n} // namespace\
    \ concepts\n\ntemplate <class T, class U>\nstd::vector<typename T::W> RectangleSumOfPointCloud(std::vector<T>\
    \ ps, std::vector<U> qs) requires concepts::RSOPCQuery<T, U> {\n    using P =\
    \ typename T::P;\n    using W = typename T::W;\n    usize n{ps.size()}, q{qs.size()};\n\
    \    std::vector<P> xs(n);\n    for (usize i{} ; i < n ; i++) xs[i] = ps[i].x;\n\
    \    std::sort(xs.begin(), xs.end());\n    xs.erase(std::unique(xs.begin(), xs.end()),\
    \ xs.end());\n    std::sort(ps.begin(), ps.end(), [&](const auto& L, const auto&\
    \ R) -> bool {\n            return L.y < R.y;\n            });\n    using Q =\
    \ std::pair<P, usize>;\n    std::vector<Q> query(qs.size() << 1);\n    for (usize\
    \ i{} ; i < qs.size() ; i++) {\n        qs[i].l = (P)std::distance(xs.begin(),\
    \ std::lower_bound(xs.begin(), xs.end(), qs[i].l));\n        qs[i].r = (P)std::distance(xs.begin(),\
    \ std::lower_bound(xs.begin(), xs.end(), qs[i].r));\n        query[i] = std::pair{qs[i].d,\
    \ i};\n        query[i + q] = std::pair{qs[i].u, i + q};\n    }\n    std::sort(query.begin(),\
    \ query.end());\n    std::vector<W> fen(xs.size() + 1), res(qs.size());\n    auto\
    \ pref{[&](i32 r) -> W {\n        W sum{};\n        for ( ; r ; r -= r & -r) sum\
    \ += fen[r];\n        return sum;\n    }};\n    for (usize i{}, j{} ; i < query.size()\
    \ ; i++) {\n        while (j < n and ps[j].y < query[i].first) {\n           \
    \ i32 x{(i32)std::distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(),\
    \ ps[j].x))}; \n            for ( x++ ; (usize)x < fen.size() ; x += x & -x) fen[x]\
    \ += ps[j].w;\n            j++;\n        }\n        usize idx{query[i].second};\n\
    \        if (idx < q) {\n            res[idx] += pref(qs[idx].l) - pref(qs[idx].r);\n\
    \        }\n        else {\n            idx -= q;\n            res[idx] += -pref(qs[idx].l)\
    \ + pref(qs[idx].r);\n        }\n    } \n    return res;\n}\n\n} // namespace\
    \ zawa\n#line 4 \"Test/LC/rectangle_sum.test.cpp\"\n\n#include <iostream>\n#line\
    \ 7 \"Test/LC/rectangle_sum.test.cpp\"\n\nusing namespace zawa;\n\nstruct Point\
    \ {\n    using P = int;\n    using W = long long;\n    P x, y;\n    W w;\n};\n\
    \nstruct Rect {\n    using P = int;\n    int l, d, r, u;\n};\n\nint main() {\n\
    \    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<Point> ps(N);\n    for\
    \ (int i{} ; i < N ; i++) {\n        int x, y, w;\n        std::cin >> x >> y\
    \ >> w;\n        ps[i] = {x, y, w};\n    }\n    std::vector<Rect> qs(Q);\n   \
    \ for (int i{} ; i < Q ; i++) {\n        int l, d, r, u;\n        std::cin >>\
    \ l >> d >> r >> u;\n        qs[i] = {l, d, r, u};\n    }\n    for (auto ans :\
    \ RectangleSumOfPointCloud(ps, qs)) {\n        std::cout << ans << '\\n';\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ \"../../Src/DataStructure/RectangleSum/RectangleSumOfPointCloud.hpp\"\n\n#include\
    \ <iostream>\n#include <vector>\n\nusing namespace zawa;\n\nstruct Point {\n \
    \   using P = int;\n    using W = long long;\n    P x, y;\n    W w;\n};\n\nstruct\
    \ Rect {\n    using P = int;\n    int l, d, r, u;\n};\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int N,\
    \ Q;\n    std::cin >> N >> Q;\n    std::vector<Point> ps(N);\n    for (int i{}\
    \ ; i < N ; i++) {\n        int x, y, w;\n        std::cin >> x >> y >> w;\n \
    \       ps[i] = {x, y, w};\n    }\n    std::vector<Rect> qs(Q);\n    for (int\
    \ i{} ; i < Q ; i++) {\n        int l, d, r, u;\n        std::cin >> l >> d >>\
    \ r >> u;\n        qs[i] = {l, d, r, u};\n    }\n    for (auto ans : RectangleSumOfPointCloud(ps,\
    \ qs)) {\n        std::cout << ans << '\\n';\n    }\n}\n"
  dependsOn:
  - Src/DataStructure/RectangleSum/RectangleSumOfPointCloud.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/LC/rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2025-04-25 15:47:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/rectangle_sum.test.cpp
- /verify/Test/LC/rectangle_sum.test.cpp.html
title: Test/LC/rectangle_sum.test.cpp
---
