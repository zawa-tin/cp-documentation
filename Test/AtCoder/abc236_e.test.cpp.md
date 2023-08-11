---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/ArrayIO.hpp
    title: "std::array\u306E\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/FloatingNumberAlias.hpp
    title: "\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\
      \u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
  - icon: ':heavy_check_mark:'
    path: Src/Template/Input.hpp
    title: "\u6A19\u6E96\u5165\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/Output.hpp
    title: "\u6A19\u6E96\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/PairIO.hpp
    title: "std::pair\u306E\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Template/VectorIO.hpp
    title: "std::vector\u306E\u5165\u51FA\u529B"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/BinarySearch.hpp
    title: "\u4E8C\u5206\u63A2\u7D22"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.001'
    PROBLEM: https://atcoder.jp/contests/abc236/tasks/abc236_e
    links:
    - https://atcoder.jp/contests/abc236/tasks/abc236_e
  bundledCode: "#line 1 \"Test/AtCoder/abc236_e.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc236/tasks/abc236_e\"\
    \n#define ERROR 0.001\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n\
    #include <cstddef>\n\nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32\
    \ = std::int32_t;\nusing i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing\
    \ u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\n} // namespace zawa\n\
    #line 2 \"Src/Template/FloatingNumberAlias.hpp\"\n\nnamespace zawa {\n\nusing\
    \ ld = long double;\n\n} // namespace zawa\n#line 2 \"Src/Template/Input.hpp\"\
    \n\n#line 2 \"Src/Template/ArrayIO.hpp\"\n\n#line 4 \"Src/Template/ArrayIO.hpp\"\
    \n\n#include <iostream>\n#include <array>\n\nnamespace zawa {\n\ntemplate <class\
    \ T, usize N>\nstd::istream &operator>>(std::istream& is, std::array<T, N>& A)\
    \ {\n    for (T& a : A) {\n        is >> a;\n    }\n    return is;\n}\n\ntemplate\
    \ <class T, usize N>\nstd::ostream &operator<<(std::ostream& os, const std::array<T,\
    \ N>& A) {\n    for (u32 i{} ; i < A.size() ; i++) {\n        os << A[i] << (i\
    \ + 1 == A.size() ? \"\" : \" \");\n    }\n    return os;\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Template/VectorIO.hpp\"\n\n#line 4 \"Src/Template/VectorIO.hpp\"\
    \n\n#line 6 \"Src/Template/VectorIO.hpp\"\n#include <vector>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nstd::istream &operator>>(std::istream& is, std::vector<T>&\
    \ A) {\n    for (T& a : A) {\n        is >> a;\n    }\n    return is;\n}\n\ntemplate\
    \ <class T>\nstd::ostream &operator<<(std::ostream& os, const std::vector<T>&\
    \ A) {\n    for (u32 i{} ; i < A.size() ; i++) {\n        os << A[i] << (i + 1\
    \ == A.size() ? \"\" : \" \");\n    }\n    return os;\n}\n\n} // namespace zawa\n\
    #line 2 \"Src/Template/PairIO.hpp\"\n\n#line 4 \"Src/Template/PairIO.hpp\"\n\n\
    #line 6 \"Src/Template/PairIO.hpp\"\n#include <utility>\n\nnamespace zawa {\n\n\
    template <class T1, class T2>\nstd::istream &operator>>(std::istream& is, std::pair<T1,\
    \ T2>& P) {\n    is >> P.first >> P.second;\n    return is;\n}\n\ntemplate <class\
    \ T1, class T2>\nstd::ostream &operator<<(std::ostream& os, const std::pair<T1,\
    \ T2>& P) {\n    os << '(' << P.first << ',' << P.second << ')';\n    return os;\n\
    }\n\n} // namespace zawa\n#line 6 \"Src/Template/Input.hpp\"\n\n#line 8 \"Src/Template/Input.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T>\nvoid input(T& value) {\n    std::cin\
    \ >> value;\n}\n\ntemplate <class Head, class... Tail>\nvoid input(Head& head,\
    \ Tail&... tail) {\n    input(head);\n    input(tail...);\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Template/Output.hpp\"\n\n#line 6 \"Src/Template/Output.hpp\"\
    \n\n#line 8 \"Src/Template/Output.hpp\"\n\nnamespace zawa {\n\nvoid out() {\n\
    \    std::cout << std::endl;\n}\n\ntemplate <class T>\nvoid out(const T& value)\
    \ {\n    std::cout << value << std::endl;\n}\n\ntemplate <class Head, class...\
    \ Tail>\nvoid out(const Head& head, const Tail&... tail) {\n    std::cout << head;\n\
    \    if (sizeof...(tail)) {\n        std::cout << ' ';\n    }\n    out(tail...);\n\
    }\n\nvoid eout() {\n    std::cerr << std::endl;\n}\n\ntemplate <class T>\nvoid\
    \ eout(const T& value) {\n    std::cerr << value << std::endl;\n}\n\ntemplate\
    \ <class Head, class... Tail>\nvoid eout(const Head& head, const Tail&... tail)\
    \ {\n    std::cerr << head;\n    if (sizeof...(tail)) {\n        std::cerr <<\
    \ ' ';\n    }\n    eout(tail...);\n}\n\n} // namespace zawa\n#line 2 \"Src/Template/IOSetting.hpp\"\
    \n\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#line 6 \"Src/Template/IOSetting.hpp\"\
    \n#include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Utility/BinarySearch.hpp\"\n\n#line 4\
    \ \"Src/Utility/BinarySearch.hpp\"\n\n#include <cmath>\n#include <functional>\n\
    #include <type_traits>\n\nnamespace zawa {\n\ntemplate <class T, class Function>\n\
    T BinarySearch(T ok, T ng, const Function& f) {\n    static_assert(std::is_integral_v<T>,\
    \ \"T must be integral type\");\n    static_assert(std::is_signed_v<T>, \"T must\
    \ be signed arithmetic type\");\n    static_assert(std::is_convertible_v<Function,\
    \ std::function<bool(T)>>, \"f must be function bool(T)\");\n    while (std::abs(ok\
    \ - ng) > 1) {\n        T mid{ (ok + ng) >> 1 };\n        (f(mid) ? ok : ng) =\
    \ mid;\n    }\n    return ok;\n}\n\ntemplate <class T, class Function>\nT BinarySearch(T\
    \ ok, T ng, const Function& f, u32 upperLimit) {\n    static_assert(std::is_signed_v<T>,\
    \ \"T must be signed arithmetic type\");\n    static_assert(std::is_convertible_v<Function,\
    \ std::function<bool(T)>>, \"f must be function bool(T)\");\n    for (u32 _{}\
    \ ; _ < upperLimit ; _++) {\n        T mid{ (ok + ng) / (T)2 };\n        (f(mid)\
    \ ? ok : ng) = mid;\n    }\n    return ok;\n}\n\n} // namespace zawa\n#line 10\
    \ \"Test/AtCoder/abc236_e.test.cpp\"\n\n#line 14 \"Test/AtCoder/abc236_e.test.cpp\"\
    \n#include <algorithm>\n\nusing namespace zawa;\n\ntemplate <class T>\nT eval(const\
    \ std::vector<T>& A) {\n    std::array<T, 2> dp{ T{}, T{} };\n    for (auto a\
    \ : A) {\n        std::array<T, 2> nxt{ T{}, T{} };\n        nxt[0] = std::max(dp[0]\
    \ + a, dp[1] + a);\n        nxt[1] = dp[0];\n        dp = std::move(nxt);\n  \
    \  }\n    return std::max(dp[0], dp[1]);\n}\n\nint main() {\n    SetPrecision(5);\n\
    \    usize N; input(N);\n    std::vector<i32> A(N); input(A);\n\n    auto ave{[&](ld\
    \ v) -> bool {\n        std::vector<ld> B(N);\n        for (u32 i{} ; i < N ;\
    \ i++) B[i] = (ld)A[i] - v;\n        return eval(B) >= 0.0l;\n    }};\n\n    auto\
    \ med{[&](i32 v) -> bool {\n        std::vector<i32> B(N);\n        for (u32 i{}\
    \ ; i < N ; i++) B[i] = (A[i] >= v ? 1 : -1);\n        return eval(B) > 0;\n \
    \   }};\n\n    out(BinarySearch(0.0l, 1e9 + 1.0l, ave, 50));\n    out(BinarySearch(0,\
    \ (i32)1e9 + 1, med));\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc236/tasks/abc236_e\"\n#define\
    \ ERROR 0.001\n\n#include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Template/FloatingNumberAlias.hpp\"\
    \n#include \"../../Src/Template/Input.hpp\"\n#include \"../../Src/Template/Output.hpp\"\
    \n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Utility/BinarySearch.hpp\"\
    \n\n#include <vector>\n#include <array>\n#include <utility>\n#include <algorithm>\n\
    \nusing namespace zawa;\n\ntemplate <class T>\nT eval(const std::vector<T>& A)\
    \ {\n    std::array<T, 2> dp{ T{}, T{} };\n    for (auto a : A) {\n        std::array<T,\
    \ 2> nxt{ T{}, T{} };\n        nxt[0] = std::max(dp[0] + a, dp[1] + a);\n    \
    \    nxt[1] = dp[0];\n        dp = std::move(nxt);\n    }\n    return std::max(dp[0],\
    \ dp[1]);\n}\n\nint main() {\n    SetPrecision(5);\n    usize N; input(N);\n \
    \   std::vector<i32> A(N); input(A);\n\n    auto ave{[&](ld v) -> bool {\n   \
    \     std::vector<ld> B(N);\n        for (u32 i{} ; i < N ; i++) B[i] = (ld)A[i]\
    \ - v;\n        return eval(B) >= 0.0l;\n    }};\n\n    auto med{[&](i32 v) ->\
    \ bool {\n        std::vector<i32> B(N);\n        for (u32 i{} ; i < N ; i++)\
    \ B[i] = (A[i] >= v ? 1 : -1);\n        return eval(B) > 0;\n    }};\n\n    out(BinarySearch(0.0l,\
    \ 1e9 + 1.0l, ave, 50));\n    out(BinarySearch(0, (i32)1e9 + 1, med));\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Template/FloatingNumberAlias.hpp
  - Src/Template/Input.hpp
  - Src/Template/ArrayIO.hpp
  - Src/Template/VectorIO.hpp
  - Src/Template/PairIO.hpp
  - Src/Template/Output.hpp
  - Src/Template/IOSetting.hpp
  - Src/Utility/BinarySearch.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc236_e.test.cpp
  requiredBy: []
  timestamp: '2023-08-11 13:17:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc236_e.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc236_e.test.cpp
- /verify/Test/AtCoder/abc236_e.test.cpp.html
title: Test/AtCoder/abc236_e.test.cpp
---
