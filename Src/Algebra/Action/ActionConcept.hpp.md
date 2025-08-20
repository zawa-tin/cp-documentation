---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/OfflineRangeProduct.hpp
    title: "\u9759\u7684\u5217\u306E\u533A\u9593\u30AF\u30A8\u30EA\u3092\u30AA\u30D5\
      \u30E9\u30A4\u30F3\u51E6\u7406\u3059\u308B"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc223_h.test.cpp
    title: Test/AtCoder/abc223_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/staticrmq/OfflineRangeProduct.test.cpp
    title: Test/LC/staticrmq/OfflineRangeProduct.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Action/ActionConcept.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class G, class X>\nconcept\
    \ Action = requires {\n    typename G::Element;\n    { G::action(std::declval<typename\
    \ G::Element>(), std::declval<X>()) } -> std::same_as<X>;\n};\n\n// Is appropriate\
    \ name X-set?\ntemplate <class G, class X>\nconcept Acted = requires {\n    typename\
    \ G::Element;\n    { G::acted(std::declval<typename G::Element>(), std::declval<X>())\
    \ } -> std::same_as<typename G::Element>;\n};\n\n} // namespace concepts\n\n}\
    \ // namespace zawa\n"
  code: "#pragma once\n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts\
    \ {\n\ntemplate <class G, class X>\nconcept Action = requires {\n    typename\
    \ G::Element;\n    { G::action(std::declval<typename G::Element>(), std::declval<X>())\
    \ } -> std::same_as<X>;\n};\n\n// Is appropriate name X-set?\ntemplate <class\
    \ G, class X>\nconcept Acted = requires {\n    typename G::Element;\n    { G::acted(std::declval<typename\
    \ G::Element>(), std::declval<X>()) } -> std::same_as<typename G::Element>;\n\
    };\n\n} // namespace concepts\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Action/ActionConcept.hpp
  requiredBy:
  - Src/Sequence/OfflineRangeProduct.hpp
  timestamp: '2025-08-20 18:56:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc223_h.test.cpp
  - Test/LC/staticrmq/OfflineRangeProduct.test.cpp
documentation_of: Src/Algebra/Action/ActionConcept.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Action/ActionConcept.hpp
- /library/Src/Algebra/Action/ActionConcept.hpp.html
title: Src/Algebra/Action/ActionConcept.hpp
---
