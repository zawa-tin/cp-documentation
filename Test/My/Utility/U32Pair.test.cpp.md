---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/U32Pair.hpp
    title: Src/Utility/U32Pair.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/My/Utility/U32Pair.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/Utility/U32Pair.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Utility/U32Pair.hpp\"\n\n#include <functional>\n\
    #include <iostream>\n\nnamespace zawa {\n\nclass U32Pair {\nprivate:\n    static\
    \ constexpr u32 SHIFT{32};\n    static constexpr u32 MASK{static_cast<u32>((1LL\
    \ << SHIFT) - 1)};\n    u64 value_{};\npublic:\n    constexpr U32Pair() {}\n \
    \   constexpr U32Pair(u32 first, u32 second) {\n        value_ = (static_cast<u64>(first)\
    \ << SHIFT) | second;\n    }\n    constexpr u32 first() const noexcept {\n   \
    \     return static_cast<u32>(value_ >> SHIFT);\n    }\n    constexpr u32 second()\
    \ const noexcept {\n        return static_cast<u32>(value_ & MASK);\n    }\n \
    \   constexpr u64 combined() const noexcept {\n        return value_;\n    }\n\
    \    constexpr U32Pair& operator=(const U32Pair& rhs) {\n        value_ = rhs.value_;\n\
    \        return *this;\n    }\n    friend constexpr bool operator==(const U32Pair&\
    \ lhs, const U32Pair& rhs) {\n        return lhs.value_ == rhs.value_;\n    }\n\
    \    friend constexpr bool operator!=(const U32Pair& lhs, const U32Pair& rhs)\
    \ {\n        return lhs.value_ != rhs.value_;\n    }\n    friend constexpr bool\
    \ operator<(const U32Pair& lhs, const U32Pair& rhs) {\n        return lhs.value_\
    \ < rhs.value_;\n    }\n    friend constexpr bool operator<=(const U32Pair& lhs,\
    \ const U32Pair& rhs) {\n        return lhs.value_ <= rhs.value_;\n    }\n   \
    \ friend constexpr bool operator>(const U32Pair& lhs, const U32Pair& rhs) {\n\
    \        return lhs.value_ > rhs.value_;\n    }\n    friend constexpr bool operator>=(const\
    \ U32Pair& lhs, const U32Pair& rhs) {\n        return lhs.value_ >= rhs.value_;\n\
    \    }\n    friend std::ostream& operator<<(std::ostream& os, const U32Pair& pair)\
    \ {\n        os << '(' << pair.first() << ',' << pair.second() << ')';\n     \
    \   return os;\n    }\n};\n\nstruct U32PairHash {\n    usize operator()(const\
    \ U32Pair& pair) const noexcept {\n        return std::hash<u64>{}(pair.combined());\n\
    \    }\n};\n\n} // namespace zawa\n#line 4 \"Test/My/Utility/U32Pair.test.cpp\"\
    \n\n#include <cassert>\n#line 7 \"Test/My/Utility/U32Pair.test.cpp\"\n#include\
    \ <unordered_set>\n#include <limits>\n\nint main() {\n    using namespace zawa;\n\
    \    std::unordered_set<U32Pair, U32PairHash> set;\n    U32Pair a{ 1, 1 }, b{\
    \ 2, 0 }, c{ 0, 1 };\n    assert(a.first() == 1);\n    assert(a.second() == 1);\n\
    \    assert(b.first() == 2);\n    assert(b.second() == 0);\n    assert(c.first()\
    \ == 0);\n    assert(c.second() == 1);\n    set.insert(a);\n    set.insert(b);\n\
    \    set.insert(c);\n    assert(set.find(a) != set.end());\n    assert(set.find(b)\
    \ != set.end());\n    assert(set.find(c) != set.end());\n    assert(set.find(U32Pair{\
    \ 99, 99 }) == set.end());\n    u32 max{std::numeric_limits<u32>::max()};\n  \
    \  U32Pair maxPair{max, max};\n    assert(maxPair.first() == max);\n    assert(maxPair.second()\
    \ == max);\n    std::cout << \"Hello World\" << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../../Src/Utility/U32Pair.hpp\"\n\n#include <cassert>\n#include\
    \ <iostream>\n#include <unordered_set>\n#include <limits>\n\nint main() {\n  \
    \  using namespace zawa;\n    std::unordered_set<U32Pair, U32PairHash> set;\n\
    \    U32Pair a{ 1, 1 }, b{ 2, 0 }, c{ 0, 1 };\n    assert(a.first() == 1);\n \
    \   assert(a.second() == 1);\n    assert(b.first() == 2);\n    assert(b.second()\
    \ == 0);\n    assert(c.first() == 0);\n    assert(c.second() == 1);\n    set.insert(a);\n\
    \    set.insert(b);\n    set.insert(c);\n    assert(set.find(a) != set.end());\n\
    \    assert(set.find(b) != set.end());\n    assert(set.find(c) != set.end());\n\
    \    assert(set.find(U32Pair{ 99, 99 }) == set.end());\n    u32 max{std::numeric_limits<u32>::max()};\n\
    \    U32Pair maxPair{max, max};\n    assert(maxPair.first() == max);\n    assert(maxPair.second()\
    \ == max);\n    std::cout << \"Hello World\" << '\\n';\n}\n"
  dependsOn:
  - Src/Utility/U32Pair.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/My/Utility/U32Pair.test.cpp
  requiredBy: []
  timestamp: '2023-12-16 19:11:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/My/Utility/U32Pair.test.cpp
layout: document
redirect_from:
- /verify/Test/My/Utility/U32Pair.test.cpp
- /verify/Test/My/Utility/U32Pair.test.cpp.html
title: Test/My/Utility/U32Pair.test.cpp
---
