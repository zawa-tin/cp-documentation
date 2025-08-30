---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SWAG/FoldableDeque.hpp
    title: Foldable Deque
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SWAG/FoldableQueue.hpp
    title: Foldable Queue
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/EnumerateStaticLengthProduct.hpp
    title: Src/Sequence/EnumerateStaticLengthProduct.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/3548.test.cpp
    title: AOJ3548 String Puzzle
  - icon: ':heavy_check_mark:'
    path: Test/CF/EC171-F.test.cpp
    title: Test/CF/EC171-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/deque_operate_all_composite.test.cpp
    title: Test/LC/deque_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/queue_operate_all_composite.test.cpp
    title: Test/LC/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/SWAG/SWAGable.hpp\"\n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SWAG/SWAGable.hpp\"\
    \n\n#line 7 \"Src/DataStructure/SWAG/SWAGable.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ concepts {\n\ntemplate <class T>\nconcept SWAGable = requires {\n    typename\
    \ T::Element;\n    typename T::Fold;\n    typename T::Fold::Element;\n    { T::convert(std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Fold::Element>;\n    { T::pushBack(std::declval<typename\
    \ T::Fold::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Fold::Element>;\n    { T::pushFront(std::declval<typename T::Fold::Element>(),\
    \ std::declval<typename T::Element>()) } -> std::same_as<typename T::Fold::Element>;\n\
    };\n\n} // namespace concepts\n\ntemplate <concepts::Semigroup S>\nclass SemigroupSWAGable\
    \ {\npublic:\n    using Element = typename S::Element;\n    using Fold = S;\n\
    \    using F = Fold::Element;\n    static F convert(Element v) {\n        return\
    \ v;\n    }\n    static F pushBack(F f, Element v) {\n        return S::operation(f,\
    \ v);\n    }\n    static F pushFront(F f, Element v) {\n        return S::operation(v,\
    \ f);\n    }\n    static F operation(F l, F r) {\n        return S::operation(l,\
    \ r);\n    }\n};\n\ntemplate <concepts::Monoid S>\nclass MonoidSWAGable {\npublic:\n\
    \    using Element = typename S::Element;\n    using Fold = S;\n    using F =\
    \ Fold::Element;\n    static F convert(Element v) {\n        return v;\n    }\n\
    \    static F pushBack(F f, Element v) {\n        return S::operation(f, v);\n\
    \    }\n    static F pushFront(F f, Element v) {\n        return S::operation(v,\
    \ f);\n    }\n    static F identity() {\n        return S::identity();\n    }\n\
    \    static F operation(F l, F r) {\n        return S::operation(l, r);\n    }\n\
    };\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Algebra/Monoid/MonoidConcept.hpp\"\n#include\
    \ \"../../Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\n\
    namespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept SWAGable\
    \ = requires {\n    typename T::Element;\n    typename T::Fold;\n    typename\
    \ T::Fold::Element;\n    { T::convert(std::declval<typename T::Element>()) } ->\
    \ std::same_as<typename T::Fold::Element>;\n    { T::pushBack(std::declval<typename\
    \ T::Fold::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Fold::Element>;\n    { T::pushFront(std::declval<typename T::Fold::Element>(),\
    \ std::declval<typename T::Element>()) } -> std::same_as<typename T::Fold::Element>;\n\
    };\n\n} // namespace concepts\n\ntemplate <concepts::Semigroup S>\nclass SemigroupSWAGable\
    \ {\npublic:\n    using Element = typename S::Element;\n    using Fold = S;\n\
    \    using F = Fold::Element;\n    static F convert(Element v) {\n        return\
    \ v;\n    }\n    static F pushBack(F f, Element v) {\n        return S::operation(f,\
    \ v);\n    }\n    static F pushFront(F f, Element v) {\n        return S::operation(v,\
    \ f);\n    }\n    static F operation(F l, F r) {\n        return S::operation(l,\
    \ r);\n    }\n};\n\ntemplate <concepts::Monoid S>\nclass MonoidSWAGable {\npublic:\n\
    \    using Element = typename S::Element;\n    using Fold = S;\n    using F =\
    \ Fold::Element;\n    static F convert(Element v) {\n        return v;\n    }\n\
    \    static F pushBack(F f, Element v) {\n        return S::operation(f, v);\n\
    \    }\n    static F pushFront(F f, Element v) {\n        return S::operation(v,\
    \ f);\n    }\n    static F identity() {\n        return S::identity();\n    }\n\
    \    static F operation(F l, F r) {\n        return S::operation(l, r);\n    }\n\
    };\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: false
  path: Src/DataStructure/SWAG/SWAGable.hpp
  requiredBy:
  - Src/Sequence/EnumerateStaticLengthProduct.hpp
  - Src/DataStructure/SWAG/FoldableQueue.hpp
  - Src/DataStructure/SWAG/FoldableDeque.hpp
  timestamp: '2025-04-17 19:44:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/EC171-F.test.cpp
  - Test/LC/queue_operate_all_composite.test.cpp
  - Test/LC/deque_operate_all_composite.test.cpp
  - Test/AOJ/3548.test.cpp
documentation_of: Src/DataStructure/SWAG/SWAGable.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/SWAG/SWAGable.hpp
- /library/Src/DataStructure/SWAG/SWAGable.hpp.html
title: Src/DataStructure/SWAG/SWAGable.hpp
---
