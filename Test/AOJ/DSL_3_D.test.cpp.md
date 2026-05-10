---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SWAG/SlindingPriority.hpp
    title: "\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D
  bundledCode: "#line 1 \"Test/AOJ/DSL_3_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D\"\
    \n\n#line 2 \"Src/DataStructure/SWAG/SlindingPriority.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/DataStructure/SWAG/SlindingPriority.hpp\"\
    \n\n#include <cassert>\n#include <concepts>\n#include <functional>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class T,class F = std::less<T>>\nrequires std::predicate<F,T,T>\n\
    class SlidingPriority {\npublic:\n\n    SlidingPriority() : m_comp{F{}} {}\n\n\
    \    explicit SlidingPriority(F comp) : m_comp{std::move(comp)} {}\n\n    inline\
    \ usize size() const {\n        return m_container.size() - m_fr;\n    }\n\n \
    \   inline bool empty() const {\n        return m_fr == m_container.size();\n\
    \    }\n\n    void push(T x) {\n        while (size() and m_comp(x,m_container.back()))\n\
    \            m_container.pop_back();\n        m_container.push_back(std::move(x));\n\
    \    }\n\n    void pop() {\n        assert(!empty());\n        m_fr++;\n    }\n\
    \n    const T& top() const {\n        assert(!empty());\n        return m_container[m_fr];\n\
    \    }\n\n    const T& operator()() const {\n        assert(!empty());\n     \
    \   return m_container[m_fr];\n    }\n\nprivate:\n\n    F m_comp;\n\n    std::vector<T>\
    \ m_container;\n\n    usize m_fr = 0;\n\n};\n\ntemplate <class T,class F>\nrequires\
    \ std::predicate<F,T,T>\nstd::vector<T> StaticLengthPriority(const std::vector<T>&\
    \ A,usize K,F comp) {\n    assert(0u < K and K <= A.size());\n    using Item =\
    \ std::pair<T,usize>;\n    auto f = [&](const Item& i,const Item& j) {\n     \
    \   return comp(i.first,j.first);\n    };\n    SlidingPriority<Item,decltype(f)>\
    \ deq{f};\n    std::vector<T> res(A.size()-K+1);\n    for (usize i = 0 ; i < K\
    \ ; i++)\n        deq.push({A[i],i});\n    for (usize i = K ; i <= A.size() ;\
    \ i++) {\n        const auto& [v,idx] = deq.top();\n        res[i-K] = v;\n  \
    \      if (idx == i-K)\n            deq.pop();\n        if (i < A.size())\n  \
    \          deq.push({A[i],i});\n    }\n    return res;\n}\n\ntemplate <class T>\n\
    requires std::totally_ordered<T>\nstd::vector<T> StaticLengthPriority(const std::vector<T>&\
    \ A,usize K) {\n    return StaticLengthPriority(A,K,std::less<T>{});\n}\n\n} //\
    \ namespace zawa\n#line 4 \"Test/AOJ/DSL_3_D.test.cpp\"\nusing namespace zawa;\n\
    \n#include <iostream>\n#line 8 \"Test/AOJ/DSL_3_D.test.cpp\"\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N,L;\n    cin >> N >> L;\n    vector<int> A(N);\n    for (auto& x : A)\n\
    \        cin >> x;\n    auto ans = StaticLengthPriority(A,L); \n    for (int i\
    \ = 0 ; i < ssize(ans) ; i++)\n        cout << ans[i] << (i + 1 == ssize(ans)\
    \ ? '\\n' : ' ');\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D\"\
    \n\n#include \"../../Src/DataStructure/SWAG/SlindingPriority.hpp\"\nusing namespace\
    \ zawa;\n\n#include <iostream>\n#include <vector>\nusing namespace std;\n\nint\
    \ main() {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N,L;\n    cin >> N >> L;\n    vector<int> A(N);\n    for (auto& x : A)\n\
    \        cin >> x;\n    auto ans = StaticLengthPriority(A,L); \n    for (int i\
    \ = 0 ; i < ssize(ans) ; i++)\n        cout << ans[i] << (i + 1 == ssize(ans)\
    \ ? '\\n' : ' ');\n}\n"
  dependsOn:
  - Src/DataStructure/SWAG/SlindingPriority.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AOJ/DSL_3_D.test.cpp
  requiredBy: []
  timestamp: '2026-05-10 18:29:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/DSL_3_D.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/DSL_3_D.test.cpp
- /verify/Test/AOJ/DSL_3_D.test.cpp.html
title: Test/AOJ/DSL_3_D.test.cpp
---
