---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Action/ActionConcept.hpp
    title: Src/Algebra/Action/ActionConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidAction.hpp
    title: Src/Algebra/Monoid/MonoidAction.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/OfflineRangeProduct.hpp
    title: "\u9759\u7684\u5217\u306E\u533A\u9593\u30AF\u30A8\u30EA\u3092\u30AA\u30D5\
      \u30E9\u30A4\u30F3\u51E6\u7406\u3059\u308B"
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Test/LC/staticrmq/OfflineRangeProduct.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 2 \"Src/Sequence/OfflineRangeProduct.hpp\"\
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
    \n} // namespace\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Action/ActionConcept.hpp\"\
    \n\n#line 4 \"Src/Algebra/Action/ActionConcept.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ concepts {\n\ntemplate <class G, class X>\nconcept Action = requires {\n   \
    \ typename G::Element;\n    { G::action(std::declval<typename G::Element>(), std::declval<X>())\
    \ } -> std::same_as<X>;\n};\n\n// Is appropriate name X-set?\ntemplate <class\
    \ G, class X>\nconcept Acted = requires {\n    typename G::Element;\n    { G::acted(std::declval<typename\
    \ G::Element>(), std::declval<X>()) } -> std::same_as<typename G::Element>;\n\
    };\n\n} // namespace concepts\n\n} // namespace zawa\n#line 6 \"Src/Sequence/OfflineRangeProduct.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#line 10 \"Src/Sequence/OfflineRangeProduct.hpp\"\
    \n#include <numeric>\n#include <vector>\n\nnamespace zawa {\n\nnamespace offline_range_product_internal\
    \ {\n\ntemplate <class R>\nconcept Range = requires (R lr) {\n    { lr.l } ->\
    \ std::convertible_to<usize>;\n    { lr.r } -> std::convertible_to<usize>;\n};\n\
    \n} // namespace offline_range_product_internal\n\ntemplate <class M, class S,\
    \ class Range>\nrequires concepts::Monoid<M> and concepts::Acted<M, S> and offline_range_product_internal::Range<Range>\n\
    std::vector<typename M::Element> OfflineRangeProduct(const std::vector<S>& as,\
    \ const std::vector<Range>& qs) {\n    std::vector<typename M::Element> sum(as.size()\
    \ + 1), res(qs.size(), M::identity());\n    auto f = [&](usize l, usize m, usize\
    \ r, const std::vector<usize>& idx) -> void {\n        sum[m] = M::identity();\n\
    \        usize L = m, R = m;\n        for (usize i : idx) {\n            L = std::min<usize>(L,\
    \ qs[i].l);\n            R = std::max<usize>(R, qs[i].r);\n        }\n       \
    \ for (usize i = m ; i-- > L ; )\n            sum[i] = M::acted(sum[i + 1], as[i]);\n\
    \        for (usize i = m ; i < R ; i++)\n            sum[i + 1] = M::acted(sum[i],\
    \ as[i]);\n        for (usize i : idx)\n            res[i] = M::operation(sum[qs[i].l],\
    \ sum[qs[i].r]);\n    };\n    auto rec = [&](auto rec, usize L, usize R, std::vector<usize>\
    \ idx) -> void {\n        if (L >= R)\n            return;\n        if (L + 1\
    \ == R) {\n            f(L, L, R, idx);\n            return;\n        }\n    \
    \    const usize mid = (L + R) / 2;\n        std::vector<usize> toL, toR, cur;\n\
    \        for (usize i : idx) {\n            assert(qs[i].l <= qs[i].r and qs[i].r\
    \ <= as.size());\n            if (qs[i].r <= mid)\n                toL.push_back(i);\n\
    \            else if (mid <= qs[i].l)\n                toR.push_back(i);\n   \
    \         else\n                cur.push_back(i);\n        }\n        if (cur.size())\n\
    \            f(L, mid, R, cur);\n        if (toL.size())\n            rec(rec,\
    \ L, mid, toL);\n        if (toR.size())\n            rec(rec, mid, R, toR);\n\
    \    };\n    std::vector<usize> idx(qs.size());\n    std::iota(idx.begin(), idx.end(),\
    \ 0);\n    rec(rec, 0, as.size(), idx);\n    return res;\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Algebra/Monoid/MonoidAction.hpp\"\n\n#line 4 \"Src/Algebra/Monoid/MonoidAction.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <concepts::Monoid M>\nstruct AddSelfAction :\
    \ public M {\n    static M::Element action(M::Element a, M::Element b) {\n   \
    \     return M::operation(a, b);\n    }\n    static M::Element acted(M::Element\
    \ a, M::Element b) {\n        return M::operation(a, b);\n    }\n};\n\n} // namespace\
    \ zawa\n#line 5 \"Test/LC/staticrmq/OfflineRangeProduct.test.cpp\"\n\n#line 8\
    \ \"Test/LC/staticrmq/OfflineRangeProduct.test.cpp\"\n#include <iostream>\n\n\
    using namespace zawa;\nusing namespace std;\nstruct M {\n    using Element = int;\n\
    \    static Element identity() {\n        return 2000000000;\n    }\n    static\
    \ Element operation(Element L, Element R) {\n        return min(L, R);\n    }\n\
    };\nusing Monoid = AddSelfAction<M>;\nstruct query {\n    int l, r;\n};\nint main()\
    \ {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n    for (int i = 0 ; i < N\
    \ ; i++)\n        cin >> a[i];\n    vector<query> q(Q);\n    for (int i = 0 ;\
    \ i < Q ; i++) {\n        int l, r;\n        cin >> l >> r;\n        q[i] = {l,\
    \ r};\n    }\n    for (int ans : OfflineRangeProduct<Monoid>(a, q))\n        cout\
    \ << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../../Src/Sequence/OfflineRangeProduct.hpp\"\n#include \"../../../Src/Algebra/Monoid/MonoidAction.hpp\"\
    \n\n#include <algorithm>\n#include <vector>\n#include <iostream>\n\nusing namespace\
    \ zawa;\nusing namespace std;\nstruct M {\n    using Element = int;\n    static\
    \ Element identity() {\n        return 2000000000;\n    }\n    static Element\
    \ operation(Element L, Element R) {\n        return min(L, R);\n    }\n};\nusing\
    \ Monoid = AddSelfAction<M>;\nstruct query {\n    int l, r;\n};\nint main() {\n\
    \    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N, Q;\n\
    \    cin >> N >> Q;\n    vector<int> a(N);\n    for (int i = 0 ; i < N ; i++)\n\
    \        cin >> a[i];\n    vector<query> q(Q);\n    for (int i = 0 ; i < Q ; i++)\
    \ {\n        int l, r;\n        cin >> l >> r;\n        q[i] = {l, r};\n    }\n\
    \    for (int ans : OfflineRangeProduct<Monoid>(a, q))\n        cout << ans <<\
    \ '\\n';\n}\n"
  dependsOn:
  - Src/Sequence/OfflineRangeProduct.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Action/ActionConcept.hpp
  - Src/Algebra/Monoid/MonoidAction.hpp
  isVerificationFile: true
  path: Test/LC/staticrmq/OfflineRangeProduct.test.cpp
  requiredBy: []
  timestamp: '2025-08-20 18:56:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/staticrmq/OfflineRangeProduct.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/staticrmq/OfflineRangeProduct.test.cpp
- /verify/Test/LC/staticrmq/OfflineRangeProduct.test.cpp.html
title: Test/LC/staticrmq/OfflineRangeProduct.test.cpp
---
