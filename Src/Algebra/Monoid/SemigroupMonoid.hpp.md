---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/SemigroupMonoid.hpp\"\n\n#include <optional>\n\
    \nnamespace zawa {\n\ntemplate <class Semigroup>\nstruct SemigroupMonoid {\n \
    \   using Element = std::optional<typename Semigroup::Element>;\n    static Element\
    \ identity() noexcept {\n        return std::nullopt;\n    }\n    static Element\
    \ operation(const Element& a, const Element& b) noexcept {\n        if (!a) return\
    \ b;\n        else if (!b) return a;\n        else return Semigroup::operation(a.value(),\
    \ b.value());\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <optional>\n\nnamespace zawa {\n\ntemplate <class\
    \ Semigroup>\nstruct SemigroupMonoid {\n    using Element = std::optional<typename\
    \ Semigroup::Element>;\n    static Element identity() noexcept {\n        return\
    \ std::nullopt;\n    }\n    static Element operation(const Element& a, const Element&\
    \ b) noexcept {\n        if (!a) return b;\n        else if (!b) return a;\n \
    \       else return Semigroup::operation(a.value(), b.value());\n    }\n};\n\n\
    } // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Monoid/SemigroupMonoid.hpp
  requiredBy: []
  timestamp: '2024-10-29 23:39:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Src/Algebra/Monoid/SemigroupMonoid.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Monoid/SemigroupMonoid.hpp
- /library/Src/Algebra/Monoid/SemigroupMonoid.hpp.html
title: Src/Algebra/Monoid/SemigroupMonoid.hpp
---
