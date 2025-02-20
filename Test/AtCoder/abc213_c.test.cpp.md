---
data:
  _extendedDependsOn:
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
    - https://atcoder.jp/contests/abc213/submissions/62949125
    - https://atcoder.jp/contests/abc213/tasks/abc213_c
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc213_c.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc213/tasks/abc213_c\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/Sequence/CompressedSequence.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Sequence/CompressedSequence.hpp\"\n\n#include\
    \ <vector>\n#include <algorithm>\n#include <cassert>\n#include <iterator>\n#include\
    \ <limits>\n\nnamespace zawa {\n\ntemplate <class T>\nclass CompressedSequence\
    \ {\nprivate:\n    std::vector<T> comped_;\n    std::vector<u32> f_;\n    \npublic:\n\
    \n    static constexpr u32 NotFound = std::numeric_limits<u32>::max();\n\n   \
    \ CompressedSequence() = default;\n\n    template <class InputIterator>\n    CompressedSequence(InputIterator\
    \ first, InputIterator last) : comped_(first, last), f_{} {\n        std::sort(comped_.begin(),\
    \ comped_.end());\n        comped_.erase(std::unique(comped_.begin(), comped_.end()),\
    \ comped_.end());\n        comped_.shrink_to_fit();\n        f_.reserve(std::distance(first,\
    \ last));\n        for (auto it{first} ; it != last ; it++) {\n            f_.emplace_back(std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), *it)));\n        }\n    }\n\
    \n    CompressedSequence(const std::vector<T>& A) : CompressedSequence(A.begin(),\
    \ A.end()) {}\n\n    inline usize size() const noexcept {\n        return comped_.size();\n\
    \    }\n\n    u32 operator[](const T& v) const {\n        return std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), v));\n    }\n\n    u32 find(const\
    \ T& v) const {\n        u32 i = std::distance(comped_.begin(), std::lower_bound(comped_.begin(),\
    \ comped_.end(), v));\n        return i == comped_.size() or comped_[i] != v ?\
    \ NotFound : i;\n    }\n\n    bool contains(const T& v) const {\n        u32 i\
    \ = std::distance(comped_.begin(), std::lower_bound(comped_.begin(), comped_.end(),\
    \ v));\n        return i < comped_.size() and comped_[i] == v;\n    }\n\n    u32\
    \ at(const T& v) const {\n        u32 res{(*this)[v]};\n        assert(res < size()\
    \ and comped_[res] == v);\n        return res;\n    }\n\n    inline u32 map(u32\
    \ i) const noexcept {\n        assert(i < f_.size());\n        return f_[i];\n\
    \    }\n\n    inline T inverse(u32 i) const noexcept {\n        assert(i < size());\n\
    \        return comped_[i];\n    }\n};\n\n} // namespace zawa\n#line 6 \"Test/AtCoder/abc213_c.test.cpp\"\
    \n\n// https://atcoder.jp/contests/abc213/submissions/62949125\n\n#include <iostream>\n\
    #line 11 \"Test/AtCoder/abc213_c.test.cpp\"\n\nusing namespace zawa;\n\ni32 main()\
    \ {\n#ifdef ATCODER\n    usize H, W, N;\n    std::cin >> H >> W >> N; \n    std::vector<u32>\
    \ A(N), B(N);\n    for (u32 i = 0 ; i < N ; i++) {\n        std::cin >> A[i] >>\
    \ B[i];\n    }\n\n    CompressedSequence compY(A);\n    CompressedSequence<u32>\
    \ compX(B.begin(), B.end());\n    for (u32 i = 0 ; i < N ; i++) {\n        std::cout\
    \ << compY.map(i) + 1 << ' ' << compX.map(i) + 1 << std::endl;\n    }\n#else\n\
    \    std::cout << \"Hello World\" << '\\n';\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc213/tasks/abc213_c\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/Sequence/CompressedSequence.hpp\"\n#include \"../../Src/Template/TypeAlias.hpp\"\
    \n\n// https://atcoder.jp/contests/abc213/submissions/62949125\n\n#include <iostream>\n\
    #include <vector>\n\nusing namespace zawa;\n\ni32 main() {\n#ifdef ATCODER\n \
    \   usize H, W, N;\n    std::cin >> H >> W >> N; \n    std::vector<u32> A(N),\
    \ B(N);\n    for (u32 i = 0 ; i < N ; i++) {\n        std::cin >> A[i] >> B[i];\n\
    \    }\n\n    CompressedSequence compY(A);\n    CompressedSequence<u32> compX(B.begin(),\
    \ B.end());\n    for (u32 i = 0 ; i < N ; i++) {\n        std::cout << compY.map(i)\
    \ + 1 << ' ' << compX.map(i) + 1 << std::endl;\n    }\n#else\n    std::cout <<\
    \ \"Hello World\" << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Sequence/CompressedSequence.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc213_c.test.cpp
  requiredBy: []
  timestamp: '2025-02-20 23:00:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc213_c.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc213_c.test.cpp
- /verify/Test/AtCoder/abc213_c.test.cpp.html
title: Test/AtCoder/abc213_c.test.cpp
---
