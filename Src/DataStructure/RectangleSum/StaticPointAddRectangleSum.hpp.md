---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/RectangleSum/RSType.hpp
    title: Src/DataStructure/RectangleSum/RSType.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/rectangle_sum.test.cpp
    title: Test/LC/rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp\"\
    \n\n#line 2 \"Src/DataStructure/RectangleSum/RSType.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/DataStructure/RectangleSum/RSType.hpp\"\n\
    \n#include <cassert>\n#include <type_traits>\n\nnamespace zawa {\n\ntemplate <class\
    \ P, class W>\nstruct RSPoint {\n    static_assert(std::is_integral_v<P>, \"RSPoint\
    \ P must be integer\");\n    P x, y;\n    W w;\n    RSPoint() = default;\n   \
    \ RSPoint(P x_, P y_) \n        : x{x_}, y{y_}, w{static_cast<W>(1)} {}\n    RSPoint(P\
    \ x_, P y_, W w_)\n        : x{x_}, y{y_}, w{w_} {}\n};\n\n// \u6C42\u5024\u3067\
    \u4F7F\u3046\n// \u534A\u958B\u533A\u9593\ntemplate <class P>\nstruct RSQuery\
    \ {\n    static_assert(std::is_integral_v<P>, \"RSPoint P must be integer\");\n\
    \    P l, d, r, u;\n    RSQuery() = default;\n    RSQuery(P l_, P d_, P r_, P\
    \ u_)\n        : l{l_}, d{d_}, r{r_}, u{u_} {\n        assert(l < r);\n      \
    \  assert(d < u);\n    }\n};\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp\"\
    \n\n#include <algorithm>\n#include <utility>\n#include <vector>\n#line 9 \"Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp\"\
    \n\nnamespace zawa {\n\n// P...\u5EA7\u6A19\u306E\u578B\n// W...\u91CD\u307F\u306E\
    \u578B\ntemplate <class P, class W>\nstd::vector<W> StaticPointAddRectangleSum(std::vector<RSPoint<P,\
    \ W>> ps, std::vector<RSQuery<P>> qs) {\n    static_assert(std::is_integral_v<W>,\
    \ \"W must be signed\");\n    usize n{ps.size()}, q{qs.size()};\n    std::vector<P>\
    \ xs(n);\n    for (usize i{} ; i < n ; i++) xs[i] = ps[i].x;\n    std::sort(xs.begin(),\
    \ xs.end());\n    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n   \
    \ std::sort(ps.begin(), ps.end(), [&](const auto& L, const auto& R) -> bool {\n\
    \            return L.y < R.y;\n            });\n    using Q = std::pair<P, usize>;\n\
    \    std::vector<Q> query(2 * qs.size());\n    for (usize i{} ; i < qs.size()\
    \ ; i++) {\n        qs[i].l = (P)std::distance(xs.begin(), std::lower_bound(xs.begin(),\
    \ xs.end(), qs[i].l));\n        qs[i].r = (P)std::distance(xs.begin(), std::lower_bound(xs.begin(),\
    \ xs.end(), qs[i].r));\n        query[i] = std::pair{qs[i].d, i};\n        query[i\
    \ + q] = std::pair{qs[i].u, i + q};\n    }\n    std::sort(query.begin(), query.end());\n\
    \    std::vector<W> fen(xs.size() + 1), res(qs.size());\n    auto pref{[&](i32\
    \ r) -> W {\n        W sum{};\n        for ( ; r ; r -= r & -r) sum += fen[r];\n\
    \        return sum;\n    }};\n    for (usize i{}, j{} ; i < query.size() ; i++)\
    \ {\n        while (j < n and ps[j].y < query[i].first) {\n            i32 x{(i32)std::distance(xs.begin(),\
    \ std::lower_bound(xs.begin(), xs.end(), ps[j].x))}; \n            for ( x++ ;\
    \ (usize)x < fen.size() ; x += x & -x) fen[x] += ps[j].w;\n            j++;\n\
    \        }\n        usize idx{query[i].second};\n        if (idx < q) {\n    \
    \        res[idx] += pref(qs[idx].l) - pref(qs[idx].r);\n        }\n        else\
    \ {\n            idx -= q;\n            res[idx] += -pref(qs[idx].l) + pref(qs[idx].r);\n\
    \        }\n    } \n    return res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"./RSType.hpp\"\n\n#include <algorithm>\n#include\
    \ <utility>\n#include <vector>\n#include <type_traits>\n\nnamespace zawa {\n\n\
    // P...\u5EA7\u6A19\u306E\u578B\n// W...\u91CD\u307F\u306E\u578B\ntemplate <class\
    \ P, class W>\nstd::vector<W> StaticPointAddRectangleSum(std::vector<RSPoint<P,\
    \ W>> ps, std::vector<RSQuery<P>> qs) {\n    static_assert(std::is_integral_v<W>,\
    \ \"W must be signed\");\n    usize n{ps.size()}, q{qs.size()};\n    std::vector<P>\
    \ xs(n);\n    for (usize i{} ; i < n ; i++) xs[i] = ps[i].x;\n    std::sort(xs.begin(),\
    \ xs.end());\n    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n   \
    \ std::sort(ps.begin(), ps.end(), [&](const auto& L, const auto& R) -> bool {\n\
    \            return L.y < R.y;\n            });\n    using Q = std::pair<P, usize>;\n\
    \    std::vector<Q> query(2 * qs.size());\n    for (usize i{} ; i < qs.size()\
    \ ; i++) {\n        qs[i].l = (P)std::distance(xs.begin(), std::lower_bound(xs.begin(),\
    \ xs.end(), qs[i].l));\n        qs[i].r = (P)std::distance(xs.begin(), std::lower_bound(xs.begin(),\
    \ xs.end(), qs[i].r));\n        query[i] = std::pair{qs[i].d, i};\n        query[i\
    \ + q] = std::pair{qs[i].u, i + q};\n    }\n    std::sort(query.begin(), query.end());\n\
    \    std::vector<W> fen(xs.size() + 1), res(qs.size());\n    auto pref{[&](i32\
    \ r) -> W {\n        W sum{};\n        for ( ; r ; r -= r & -r) sum += fen[r];\n\
    \        return sum;\n    }};\n    for (usize i{}, j{} ; i < query.size() ; i++)\
    \ {\n        while (j < n and ps[j].y < query[i].first) {\n            i32 x{(i32)std::distance(xs.begin(),\
    \ std::lower_bound(xs.begin(), xs.end(), ps[j].x))}; \n            for ( x++ ;\
    \ (usize)x < fen.size() ; x += x & -x) fen[x] += ps[j].w;\n            j++;\n\
    \        }\n        usize idx{query[i].second};\n        if (idx < q) {\n    \
    \        res[idx] += pref(qs[idx].l) - pref(qs[idx].r);\n        }\n        else\
    \ {\n            idx -= q;\n            res[idx] += -pref(qs[idx].l) + pref(qs[idx].r);\n\
    \        }\n    } \n    return res;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/DataStructure/RectangleSum/RSType.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp
  requiredBy: []
  timestamp: '2024-11-09 02:34:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/rectangle_sum.test.cpp
documentation_of: Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp
- /library/Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp.html
title: Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp
---
