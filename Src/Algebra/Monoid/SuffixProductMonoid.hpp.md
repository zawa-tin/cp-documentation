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
  bundledCode: "#line 2 \"Src/Algebra/Monoid/SuffixProductMonoid.hpp\"\n\n#include\
    \ <type_traits>\n\nnamespace zawa {\n\ntemplate <class Value>\nclass SuffixProductMonoidData\
    \ {\n    Value product_{}, suffix_{};\npublic:\n    SuffixProductMonoidData()\
    \ = default;\n    SuffixProductMonoidData(const Value& product, const Value& suffix)\n\
    \        : product_{product}, suffix_{suffix} {}\n\n    inline const Value& product()\
    \ const noexcept {\n        return product_;\n    }\n    inline const Value& suffix()\
    \ const noexcept {\n        return suffix_;\n    }\n};\n\ntemplate <class O, class\
    \ F>\nclass SuffixProductMonoid {\n    static_assert(std::is_same_v<typename O::Element,\
    \ typename F::Element>);\npublic:\n    using Element = SuffixProductMonoidData<typename\
    \ O::Element>;\n    static Element identity() noexcept {\n        return SuffixProductMonoidData{O::identity(),\
    \ F::identity()};\n    }\n    static Element operation(const Element& l, const\
    \ Element& r) noexcept {\n        return SuffixProductMonoidData{\n          \
    \  O::operation(l.product(), r.product()),\n            F::operation(O::operation(l.suffix(),\
    \ r.product()), r.suffix())\n        };\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <type_traits>\n\nnamespace zawa {\n\ntemplate <class\
    \ Value>\nclass SuffixProductMonoidData {\n    Value product_{}, suffix_{};\n\
    public:\n    SuffixProductMonoidData() = default;\n    SuffixProductMonoidData(const\
    \ Value& product, const Value& suffix)\n        : product_{product}, suffix_{suffix}\
    \ {}\n\n    inline const Value& product() const noexcept {\n        return product_;\n\
    \    }\n    inline const Value& suffix() const noexcept {\n        return suffix_;\n\
    \    }\n};\n\ntemplate <class O, class F>\nclass SuffixProductMonoid {\n    static_assert(std::is_same_v<typename\
    \ O::Element, typename F::Element>);\npublic:\n    using Element = SuffixProductMonoidData<typename\
    \ O::Element>;\n    static Element identity() noexcept {\n        return SuffixProductMonoidData{O::identity(),\
    \ F::identity()};\n    }\n    static Element operation(const Element& l, const\
    \ Element& r) noexcept {\n        return SuffixProductMonoidData{\n          \
    \  O::operation(l.product(), r.product()),\n            F::operation(O::operation(l.suffix(),\
    \ r.product()), r.suffix())\n        };\n    }\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Monoid/SuffixProductMonoid.hpp
  requiredBy: []
  timestamp: '2024-02-06 13:31:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Src/Algebra/Monoid/SuffixProductMonoid.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Monoid/SuffixProductMonoid.hpp
- /library/Src/Algebra/Monoid/SuffixProductMonoid.hpp.html
title: Src/Algebra/Monoid/SuffixProductMonoid.hpp
---
