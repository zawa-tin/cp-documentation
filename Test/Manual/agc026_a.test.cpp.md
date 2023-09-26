---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/RunLengthEncoding.hpp
    title: "\u9023\u9577\u5727\u7E2E"
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
    - https://atcoder.jp/contests/agc026/submissions/45973756
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/Manual/agc026_a.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/Sequence/RunLengthEncoding.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Sequence/RunLengthEncoding.hpp\"\n\n#include\
    \ <deque>\n#include <vector>\n#include <cassert>\n\nnamespace zawa {\n\ntemplate\
    \ <class Value, class Number = u64>\nclass RunLengthEncoding {\npublic:\n    class\
    \ Data {\n    private:\n        Value value_;\n        Number number_;\n    public:\n\
    \        Data() = default;\n        Data(const Value& value, Number number) :\
    \ value_{ value }, number_{ number } {}\n\n        const Value& value() const\
    \ noexcept {\n            return value_;\n        }\n\n        Number number()\
    \ const noexcept {\n            return number_;\n        }\n\n        friend RunLengthEncoding;\n\
    \    };\n\nprivate:\n    std::deque<Data> seq_;\n    u64 sum_{};\n\n    template\
    \ <class InputIterator>\n    inline void build(InputIterator first, InputIterator\
    \ last) {\n        for (auto it{ first } ; it != last ; it++) {\n            if\
    \ (seq_.empty() or seq_.back().value() != *it) {\n                seq_.emplace_back(*it,\
    \ Number{1});\n            }\n            else {\n                seq_.back().number_++;\n\
    \            }\n            sum_++;\n        }\n    }\n\npublic:\n    RunLengthEncoding()\
    \ = default;\n\n    template <class InputIterator>\n    RunLengthEncoding(InputIterator\
    \ first, InputIterator last) {\n        build(first, last);\n    }\n\n    RunLengthEncoding(const\
    \ std::vector<Value>& a) {\n        build(a.begin(), a.end());\n    }\n\n    constexpr\
    \ usize size() const noexcept {\n        return seq_.size();\n    }\n\n    constexpr\
    \ u64 sum() const noexcept {\n        return sum_;\n    }\n\n    const Data& operator[](u32\
    \ i) const noexcept {\n        assert(i < size());\n        return seq_[i];\n\
    \    }\n\n    const Value& value(u32 i) const noexcept {\n        assert(i < size());\n\
    \        return seq_[i].value();\n    }\n\n    const Number number(u32 i) const\
    \ noexcept {\n        assert(i < size());\n        return seq_[i].number();\n\
    \    }\n\n    typename decltype(seq_)::const_iterator begin() const noexcept {\n\
    \        return seq_.begin();\n    }\n\n    typename decltype(seq_)::const_iterator\
    \ end() const noexcept {\n        return seq_.end();\n    }\n\n    const Data&\
    \ front() const noexcept {\n        assert(size());\n        return seq_.front();\n\
    \    }\n\n    const Data& back() const noexcept {\n        assert(size());\n \
    \       return seq_.back();\n    }\n\n    void pushBack(const Value& value, const\
    \ Number number = Number{1}) {\n        sum_ += number;\n        if (seq_.empty()\
    \ or seq_.back().value() != value) {\n            seq_.emplace_back(value, number);\n\
    \        }\n        else {\n            seq_.back().number_ += number;\n     \
    \   }\n    }\n\n    void pushFront(const Value& value, const Number number = Number{1})\
    \ {\n        sum_ += number;\n        if (seq_.empty() or seq_.front().value()\
    \ != value) {\n            seq_.emplace_front(value, number);\n        }\n   \
    \     else {\n            seq_.front().number_ += number;\n        }\n    }\n\n\
    \    void popBack() {\n        assert(size());\n        sum_ -= seq_.back().number();\n\
    \        seq_.pop_back();\n    }\n\n    void popFront() {\n        assert(size());\n\
    \        sum_ -= seq_.front().number();\n        seq_.pop_front();\n    }\n\n\
    \    std::vector<Data> popBack(u64 number) {\n        assert(number <= sum());\n\
    \        sum_ -= number;\n        std::vector<Data> res;\n        while (number\
    \ and number >= seq_.back().number()) {\n            res.push_back(seq_.back());\n\
    \            number -= seq_.back().number();\n            seq_.pop_back();\n \
    \       }\n        if (number) {\n            res.emplace_back(seq_.back().value(),\
    \ number);\n            seq_.back().number_ -= number;\n        }\n        return\
    \ res;\n    }\n\n    std::vector<Data> popFront(u64 number) {\n        assert(number\
    \ <= sum());\n        sum_ -= number;\n        std::vector<Data> res;\n      \
    \  while (number and number >= seq_.front().number()) {\n            res.push_back(seq_.front());\n\
    \            number -= seq_.front().number();\n            seq_.pop_front();\n\
    \        }\n        if (number) {\n            res.emplace_back(seq_.front().value(),\
    \ number);\n            seq_.front().number_ -= number;\n        }\n        return\
    \ res;\n    }\n};\n\n} // namespace zawa\n#line 4 \"Test/Manual/agc026_a.test.cpp\"\
    \n\n#line 6 \"Test/Manual/agc026_a.test.cpp\"\n#include <iostream>\n\n/*\n * AGC026-A\
    \ Colorful Slimes 2\n * https://atcoder.jp/contests/agc026/submissions/45973756\n\
    \ */\n\nvoid solve() {\n    int n; std::cin >> n;\n    std::vector<int> a(n);\n\
    \    for (auto& x : a) std::cin >> x;\n    zawa::RunLengthEncoding rle(a);\n \
    \   int ans{};\n    for (const auto& x : rle) ans += x.number() / 2;\n    std::cout\
    \ << ans << std::endl;\n}\n\nint main() {\n#ifdef ATCODER\n    solve();\n#else\n\
    \    std::cout << \"Hello World\" << std::endl;\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/Sequence/RunLengthEncoding.hpp\"\n\n#include <vector>\n\
    #include <iostream>\n\n/*\n * AGC026-A Colorful Slimes 2\n * https://atcoder.jp/contests/agc026/submissions/45973756\n\
    \ */\n\nvoid solve() {\n    int n; std::cin >> n;\n    std::vector<int> a(n);\n\
    \    for (auto& x : a) std::cin >> x;\n    zawa::RunLengthEncoding rle(a);\n \
    \   int ans{};\n    for (const auto& x : rle) ans += x.number() / 2;\n    std::cout\
    \ << ans << std::endl;\n}\n\nint main() {\n#ifdef ATCODER\n    solve();\n#else\n\
    \    std::cout << \"Hello World\" << std::endl;\n#endif\n}\n"
  dependsOn:
  - Src/Sequence/RunLengthEncoding.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/Manual/agc026_a.test.cpp
  requiredBy: []
  timestamp: '2023-09-27 05:17:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Manual/agc026_a.test.cpp
layout: document
redirect_from:
- /verify/Test/Manual/agc026_a.test.cpp
- /verify/Test/Manual/agc026_a.test.cpp.html
title: Test/Manual/agc026_a.test.cpp
---
