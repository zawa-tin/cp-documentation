---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/RunLengthEncoding.hpp
    title: "\u9023\u9577\u5727\u7E2E"
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
    PROBLEM: https://atcoder.jp/contests/abc299/tasks/abc299_c
    links:
    - https://atcoder.jp/contests/abc299/tasks/abc299_c
  bundledCode: "#line 1 \"Test/AtCoder/abc299_c.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc299/tasks/abc299_c\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Sequence/RunLengthEncoding.hpp\"\
    \n\n#line 4 \"Src/Sequence/RunLengthEncoding.hpp\"\n\n#include <deque>\n#include\
    \ <vector>\n#include <cassert>\n\nnamespace zawa {\n\ntemplate <class Value, class\
    \ Number = u64>\nclass RunLengthEncoding {\npublic:\n    class Data {\n    private:\n\
    \        Value value_;\n        Number number_;\n    public:\n        Data() =\
    \ default;\n        Data(const Value& value, Number number) : value_{ value },\
    \ number_{ number } {}\n\n        const Value& value() const noexcept {\n    \
    \        return value_;\n        }\n\n        Number number() const noexcept {\n\
    \            return number_;\n        }\n\n        friend RunLengthEncoding;\n\
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
    \ res;\n    }\n};\n\n} // namespace zawa\n#line 5 \"Test/AtCoder/abc299_c.test.cpp\"\
    \n\n#include <iostream>\n#include <string>\n#include <algorithm>\n\nusing namespace\
    \ zawa;\n\ni32 solve(const std::string& S) {\n    RunLengthEncoding<u8> rle(S.begin(),\
    \ S.end());\n    i32 res{-1};\n    for (u32 i{1} ; i < rle.size() ; i++) {\n \
    \       if (rle[i].value() == 'o') {\n            res = std::max<i32>(res, rle[i].number());\n\
    \        }\n    }\n    return res;\n}\n\nint main() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    \n    u32 N; std::cin >> N;\n    std::string S; std::cin >> S;\n\n    i32 ans{-1};\n\
    \    ans = std::max(ans, solve(S));\n    std::reverse(S.begin(), S.end());\n \
    \   ans = std::max(ans, solve(S));\n\n    std::cout << ans << std::endl;\n   \
    \ \n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc299/tasks/abc299_c\"\n\n\
    #include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Sequence/RunLengthEncoding.hpp\"\
    \n\n#include <iostream>\n#include <string>\n#include <algorithm>\n\nusing namespace\
    \ zawa;\n\ni32 solve(const std::string& S) {\n    RunLengthEncoding<u8> rle(S.begin(),\
    \ S.end());\n    i32 res{-1};\n    for (u32 i{1} ; i < rle.size() ; i++) {\n \
    \       if (rle[i].value() == 'o') {\n            res = std::max<i32>(res, rle[i].number());\n\
    \        }\n    }\n    return res;\n}\n\nint main() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    \n    u32 N; std::cin >> N;\n    std::string S; std::cin >> S;\n\n    i32 ans{-1};\n\
    \    ans = std::max(ans, solve(S));\n    std::reverse(S.begin(), S.end());\n \
    \   ans = std::max(ans, solve(S));\n\n    std::cout << ans << std::endl;\n   \
    \ \n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Sequence/RunLengthEncoding.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc299_c.test.cpp
  requiredBy: []
  timestamp: '2023-07-29 13:13:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc299_c.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc299_c.test.cpp
- /verify/Test/AtCoder/abc299_c.test.cpp.html
title: Test/AtCoder/abc299_c.test.cpp
---
