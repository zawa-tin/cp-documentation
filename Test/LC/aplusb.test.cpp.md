---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':question:'
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
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/LC/aplusb.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n \
    \   using Element = T;\n    static constexpr T identity() noexcept {\n       \
    \ return T{};\n    }\n    static constexpr T operation(const T& l, const T& r)\
    \ noexcept {\n        return l + r;\n    }\n    static constexpr T inverse(const\
    \ T& v) noexcept {\n        return -v;\n    }\n};\n\n} // namespace zawa\n#line\
    \ 5 \"Test/LC/aplusb.test.cpp\"\n\n#include <iostream>\n\nusing namespace zawa;\n\
    \nint main() {\n    i32 A, B;\n    std::cin >> A >> B;\n    i32 ans = AdditiveGroup<i32>::operation(A,\
    \ B);\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\
    \n\n#include <iostream>\n\nusing namespace zawa;\n\nint main() {\n    i32 A, B;\n\
    \    std::cin >> A >> B;\n    i32 ans = AdditiveGroup<i32>::operation(A, B);\n\
    \    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  isVerificationFile: true
  path: Test/LC/aplusb.test.cpp
  requiredBy: []
  timestamp: '2023-07-17 03:16:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/aplusb.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/aplusb.test.cpp
- /verify/Test/LC/aplusb.test.cpp.html
title: Test/LC/aplusb.test.cpp
---
