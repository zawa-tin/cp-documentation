---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SWAG/FoldableQueue.hpp
    title: Foldable Queue
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SWAG/SWAGable.hpp
    title: Src/DataStructure/SWAG/SWAGable.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/EnumerateStaticLengthProduct.hpp
    title: Src/Sequence/EnumerateStaticLengthProduct.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/awc0001/submissions/73160986
    - https://atcoder.jp/contests/awc0001/tasks/awc0001_e
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/AtCoder/awc001_e.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/awc0001/tasks/awc0001_e\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n/*\n * AtCoder Weekday Contest 0001 Beta E\n * https://atcoder.jp/contests/awc0001/submissions/73160986\n\
    \ */\n\n#line 2 \"Src/Sequence/EnumerateStaticLengthProduct.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T>\nconcept Semigroup = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 2\
    \ \"Src/DataStructure/SWAG/FoldableQueue.hpp\"\n\n#line 2 \"Src/DataStructure/SWAG/SWAGable.hpp\"\
    \n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 4 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ concepts {\n\ntemplate <class T>\nconcept Identitiable = requires {\n    typename\
    \ T::Element;\n    { T::identity() } -> std::same_as<typename T::Element>;\n};\n\
    \ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\n}\
    \ // namespace\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SWAG/SWAGable.hpp\"\
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
    };\n\n} // namespace zawa\n#line 7 \"Src/DataStructure/SWAG/FoldableQueue.hpp\"\
    \n\n#include <cassert>\n#include <optional>\n#include <vector>\n\nnamespace zawa\
    \ {\n\ntemplate <concepts::SWAGable S>\nclass FoldableQueue {\npublic:\n\n   \
    \ using V = typename S::Element;\n    using Fold = typename S::Fold;\n    using\
    \ F = typename Fold::Element;\n\n    FoldableQueue() = default;\n\n    usize size()\
    \ const noexcept {\n        return m_front.size() + m_back.size();\n    }\n\n\
    \    bool empty() const noexcept {\n        return size() == 0u;\n    }\n\n  \
    \  void push(const V& v) {\n        m_raw.push_back(v);\n        m_back.push_back(m_back.size()\
    \ ? S::pushBack(m_back.back(), v) : S::convert(v));\n    }\n\n    void pop() {\n\
    \        assert(size());\n        move();\n        m_front.pop_back();\n    }\n\
    \n    std::pair<F, F> get() const requires concepts::Identitiable<typename S::Fold>\
    \ {\n        return {\n            m_front.empty() ? Fold::identity() : m_front.back(),\n\
    \            m_back.empty() ? Fold::identity() : m_back.back()\n        };\n \
    \   }\n\n    std::pair<std::optional<F>, std::optional<F>> get() const {\n   \
    \     return {\n            m_front.empty() ? std::nullopt : std::optional<F>{m_front.back()},\n\
    \            m_back.empty() ? std::nullopt : std::optional<F>{m_back.back()}\n\
    \        };\n    }\n\n    F product() const requires concepts::Monoid<typename\
    \ S::Fold> {\n        auto [f, b] = get();\n        return Fold::operation(f,\
    \ b);\n    }\n\n    F product() const requires concepts::Semigroup<typename S::Fold>\
    \ {\n        assert(m_front.size() or m_back.size());\n        if (m_front.empty())\
    \ return m_back.back();\n        if (m_back.empty()) return m_front.back();\n\
    \        return S::Fold::operation(m_front.back(), m_back.back());\n    }\n  \
    \  \nprivate:\n    std::vector<F> m_front{}, m_back{};\n    std::vector<V> m_raw{};\n\
    \n    void move() {\n        if (m_front.size()) return;\n        while (m_back.size())\
    \ {\n            m_back.pop_back();\n            V v{m_raw.back()};\n        \
    \    m_raw.pop_back();\n            m_front.push_back(m_front.size() ? S::pushFront(m_front.back(),\
    \ v) : S::convert(v));\n        }\n    }\n};\n\n} // namespace zawa\n#line 6 \"\
    Src/Sequence/EnumerateStaticLengthProduct.hpp\"\n\n#line 8 \"Src/Sequence/EnumerateStaticLengthProduct.hpp\"\
    \n#include <iterator>\n#include <type_traits>\n#line 11 \"Src/Sequence/EnumerateStaticLengthProduct.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <concepts::Semigroup S>\nstd::vector<typename\
    \ S::Element> EnumerateStaticLengthProduct(const std::vector<typename S::Element>&\
    \ A, usize K) {\n    assert(K > 0);\n    if (A.size() < K) return {};\n    std::vector<typename\
    \ S::Element> res(A.size() - K + 1);\n    FoldableQueue<SemigroupSWAGable<S>>\
    \ que{};\n    for (usize i{} ; i < K ; i++) {\n        que.push(A[i]);\n    }\n\
    \    for (usize i{} ; i < A.size() - K ; i++) {\n        res[i] = que.product();\n\
    \        que.pop();\n        que.push(A[i + K]);\n    }\n    res[A.size() - K]\
    \ = que.product();\n    return res;\n}\n\n} // namespace zawa\n#line 10 \"Test/AtCoder/awc001_e.test.cpp\"\
    \nusing namespace zawa;\n#include <iostream>\n#include <algorithm>\n#line 14 \"\
    Test/AtCoder/awc001_e.test.cpp\"\nusing namespace std;\nstruct M {\n   using Element\
    \ = pair<int,int>;\n   static Element operation(Element l, Element r) {\n    \
    \   return {max(l.first,r.first),min(l.second,r.second)};\n   }\n};\nint main()\
    \ {\n#ifdef ATCODER\n    int N, K;\n    cin >> N >> K;\n    vector<pair<int,int>>\
    \ A(N);\n    for (auto& x : A) {\n        cin >> x.first;\n        x.second =\
    \ x.first;\n    }\n    int ans = 0;\n    for (auto [a, b] : EnumerateStaticLengthProduct<M>(A,\
    \ K))\n        ans = max(ans, a - b);\n    cout << ans << '\\n';\n#else\n    int\
    \ a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/awc0001/tasks/awc0001_e\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n/*\n * AtCoder\
    \ Weekday Contest 0001 Beta E\n * https://atcoder.jp/contests/awc0001/submissions/73160986\n\
    \ */\n\n#include \"../../Src/Sequence/EnumerateStaticLengthProduct.hpp\"\nusing\
    \ namespace zawa;\n#include <iostream>\n#include <algorithm>\n#include <vector>\n\
    using namespace std;\nstruct M {\n   using Element = pair<int,int>;\n   static\
    \ Element operation(Element l, Element r) {\n       return {max(l.first,r.first),min(l.second,r.second)};\n\
    \   }\n};\nint main() {\n#ifdef ATCODER\n    int N, K;\n    cin >> N >> K;\n \
    \   vector<pair<int,int>> A(N);\n    for (auto& x : A) {\n        cin >> x.first;\n\
    \        x.second = x.first;\n    }\n    int ans = 0;\n    for (auto [a, b] :\
    \ EnumerateStaticLengthProduct<M>(A, K))\n        ans = max(ans, a - b);\n   \
    \ cout << ans << '\\n';\n#else\n    int a, b;\n    cin >> a >> b;\n    cout <<\
    \ a + b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Sequence/EnumerateStaticLengthProduct.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/DataStructure/SWAG/FoldableQueue.hpp
  - Src/DataStructure/SWAG/SWAGable.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  isVerificationFile: true
  path: Test/AtCoder/awc001_e.test.cpp
  requiredBy: []
  timestamp: '2026-02-09 20:31:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/awc001_e.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/awc001_e.test.cpp
- /verify/Test/AtCoder/awc001_e.test.cpp.html
title: Test/AtCoder/awc001_e.test.cpp
---
