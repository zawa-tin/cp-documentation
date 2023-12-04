---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/Mersenne61ModInt.hpp
    title: Src/Number/Mersenne61ModInt.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/ALDS1_14_B.test.cpp
    title: Test/AOJ/ALDS1_14_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc141_e.test.cpp
    title: Test/AtCoder/abc141_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc284_f.test.cpp
    title: Test/AtCoder/abc284_f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Sequence/RollingHash.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/Number/Mersenne61ModInt.hpp\"\n\n#line 4\
    \ \"Src/Number/Mersenne61ModInt.hpp\"\n\nnamespace zawa {\n\n// @reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    class Mersenne61ModInt {\npublic:\n    using Value = u64;\nprivate:\n    static\
    \ constexpr Value MOD{(1ull << 61) - 1}; // == MASK61\n    static constexpr Value\
    \ MASK30{(1ull << 30) - 1};\n    static constexpr Value MASK31{(1ull << 31) -\
    \ 1};\n    Value v_{};\npublic:\n    constexpr Mersenne61ModInt() {}\n\n    static\
    \ constexpr Value Mod() noexcept {\n        return MOD;\n    }\n    static constexpr\
    \ Value Modulo(const Value& v) noexcept {\n        Value res{(v >> 61) + (v &\
    \ MOD)};\n        res = (res >= MOD ? res - MOD : res);\n        return res;\n\
    \    }\n    static constexpr Value UnsafeMul(const Value& a, const Value& b) noexcept\
    \ {\n        Value fa{a >> 31}, fb{b >> 31};\n        Value ba{a & MASK31}, bb{b\
    \ & MASK31};\n        Value mid{fa * bb + fb * ba};\n        return Value{2}*fa*fb\
    \ + (mid >> 30) + ((mid & MASK30) << 31) + ba*bb;\n    }\n    static constexpr\
    \ Value Mul(const Value& a, const Value& b) noexcept {\n        return Modulo(UnsafeMul(a,\
    \ b));\n    }\n};\n\n};\n#line 5 \"Src/Sequence/RollingHash.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iterator>\n#include <memory>\n#include\
    \ <random>\n#include <string>\n#include <type_traits>\n#include <vector>\n\nnamespace\
    \ zawa {\n\nclass RollingHashFactory {\npublic:\n    using Modulo = Mersenne61ModInt;\n\
    \    using Value = Modulo::Value;\n    using Size = usize;\n    class Hash {\n\
    \    private:\n        Value hash_{};        \n        Size len_{};\n    public:\n\
    \        Hash() {}\n        Hash(Value hash, usize len) : hash_{hash}, len_{len}\
    \ {}\n        Value hash() const noexcept {\n            return hash_;\n     \
    \   }\n        Size len() const noexcept {\n            return len_;\n       \
    \ }\n        friend bool operator==(const Hash& lhs, const Hash& rhs) {\n    \
    \        return lhs.hash() == rhs.hash() and lhs.len() == rhs.len();\n       \
    \ }\n        friend bool operator!=(const Hash& lhs, const Hash& rhs) {\n    \
    \        return lhs.hash() != rhs.hash() or lhs.len() != rhs.len();\n        }\n\
    \    };\n    static constexpr Value mod{Modulo::Mod()};\nprivate:\n    std::mt19937\
    \ mt{std::random_device{}()};\n    std::vector<Value> pows{};\n    Value base{};\n\
    \n    void expand(Size len) {\n        Size now{pows.size()};\n        if (len\
    \ + 1 <= now) return;\n        pows.resize(len + 1);\n        for (Size i{now}\
    \ ; i < pows.size() ; i++) {\n            pows[i] = Modulo::Mul(pows[i - 1], base);\n\
    \        }\n    }\n\npublic:\n    RollingHashFactory() = default;\n    RollingHashFactory(Size\
    \ initLength, Value maxSigma = 127) \n        : pows(1, Value{1}), base{(mt()\
    \ % (mod - maxSigma)) + maxSigma + 1} {\n        pows.reserve(initLength + 1);\n\
    \        expand(initLength);\n    }\n\n    class RollingHash {\n    public:\n\
    \        using Value = RollingHashFactory::Value;\n        using Size = RollingHashFactory::Size;\n\
    \        using Hash = RollingHashFactory::Hash;\n    private:\n        using Modulo\
    \ = RollingHashFactory::Modulo;\n        Size n_{};\n        std::vector<Hash>\
    \ prefix_{};\n        std::shared_ptr<std::vector<Value>> pows_{};\n    public:\n\
    \        RollingHash() = default;\n        RollingHash(const std::vector<Hash>&\
    \ prefix, const std::vector<Value>& pows) \n            : n_{prefix.size() - 1},\
    \ prefix_{prefix}, pows_{std::make_shared<std::vector<Value>>(pows)} {}\n\n  \
    \      constexpr Size size() const noexcept {\n            return n_;\n      \
    \  }\n\n        Hash prefix(Size r) const {\n            assert(r <= size());\n\
    \            return prefix_[r];\n        }\n\n        Hash range(Size l, Size\
    \ r) const {\n            assert(l <= size());\n            assert(l <= r);\n\
    \            assert(r <= size());\n            static constexpr Value positiver{4ull\
    \ * Modulo::Mod()};\n            return Hash{\n                Modulo::Modulo(prefix_[r].hash()\
    \ + positiver - Modulo::UnsafeMul(prefix_[l].hash(), (*pows_)[r - l])),\n    \
    \            r - l\n            };\n        }\n\n        Size lcp(Size l1, Size\
    \ r1, Size l2, Size r2) {\n            assert(l1 <= size());\n            assert(r1\
    \ <= size());\n            assert(l2 <= size());\n            assert(r2 <= size());\n\
    \            assert(l1 <= r1);\n            assert(l2 <= r2);\n            Size\
    \ L{}, R{std::min(r1 - l1, r2 - l2) + 1};\n            while (R - L > 1) {\n \
    \               Size mid{(L + R) >> 1};\n                (range(l1, l1 + mid)\
    \ == range(l2, l2 + mid) ? L : R) = mid;\n            }\n            return L;\n\
    \        }\n    };\n\n    template <class RandomAccessIterator>\n    RollingHash\
    \ create(RandomAccessIterator first, RandomAccessIterator last) {\n        static_assert(std::is_convertible_v<decltype(*first),\
    \ Value>, \"value must be convertible to unsigned integer\");\n        Size n{static_cast<Size>(std::distance(first,\
    \ last))};\n        expand(n);\n        std::vector<Hash> roll(1);\n        roll.reserve(n\
    \ + 1);\n        for (auto it{first} ; it != last ; it++) {\n            roll.emplace_back(\n\
    \                Modulo::Modulo(Modulo::UnsafeMul(roll.back().hash(), base) +\
    \ *it),\n                roll.back().len() + 1\n            );\n        }\n  \
    \      return RollingHash(roll, pows);\n    }\n\n    template <class T>\n    RollingHash\
    \ create(const std::vector<T>& a) {\n        return create(a.begin(), a.end());\
    \ \n    }\n\n    template <class T>\n    Hash hash(const std::vector<T>& a) {\n\
    \        static_assert(std::is_convertible_v<T, Value>, \"value must be convertible\
    \ to unsigned integer\");\n        expand(a.size());\n        Value value{};\n\
    \        for (const T& x : a) {\n            value = Modulo::Modulo(Modulo::UnsafeMul(value,\
    \ base) + x);\n        }\n        return Hash{value, a.size()};\n    }\n\n   \
    \ RollingHash create(const std::string& s) {\n        return create(s.begin(),\
    \ s.end());\n    }\n\n    Hash hash(const std::string& s) {\n        expand(s.size());\n\
    \        Value value{};\n        for (const char& c : s) {\n            value\
    \ = Modulo::Modulo(Modulo::UnsafeMul(value, base) + c);\n        }\n        return\
    \ Hash{value, s.size()};\n    }\n\n    Hash concate(const Hash& lhs, const Hash&\
    \ rhs) {\n        return Hash{\n            Modulo::Modulo(Modulo::UnsafeMul(lhs.hash(),\
    \ pows[rhs.len()]) + rhs.hash()),\n            lhs.len() + rhs.len()\n       \
    \ };\n    }\n};\n\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"../Number/Mersenne61ModInt.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <iterator>\n#include <memory>\n\
    #include <random>\n#include <string>\n#include <type_traits>\n#include <vector>\n\
    \nnamespace zawa {\n\nclass RollingHashFactory {\npublic:\n    using Modulo =\
    \ Mersenne61ModInt;\n    using Value = Modulo::Value;\n    using Size = usize;\n\
    \    class Hash {\n    private:\n        Value hash_{};        \n        Size\
    \ len_{};\n    public:\n        Hash() {}\n        Hash(Value hash, usize len)\
    \ : hash_{hash}, len_{len} {}\n        Value hash() const noexcept {\n       \
    \     return hash_;\n        }\n        Size len() const noexcept {\n        \
    \    return len_;\n        }\n        friend bool operator==(const Hash& lhs,\
    \ const Hash& rhs) {\n            return lhs.hash() == rhs.hash() and lhs.len()\
    \ == rhs.len();\n        }\n        friend bool operator!=(const Hash& lhs, const\
    \ Hash& rhs) {\n            return lhs.hash() != rhs.hash() or lhs.len() != rhs.len();\n\
    \        }\n    };\n    static constexpr Value mod{Modulo::Mod()};\nprivate:\n\
    \    std::mt19937 mt{std::random_device{}()};\n    std::vector<Value> pows{};\n\
    \    Value base{};\n\n    void expand(Size len) {\n        Size now{pows.size()};\n\
    \        if (len + 1 <= now) return;\n        pows.resize(len + 1);\n        for\
    \ (Size i{now} ; i < pows.size() ; i++) {\n            pows[i] = Modulo::Mul(pows[i\
    \ - 1], base);\n        }\n    }\n\npublic:\n    RollingHashFactory() = default;\n\
    \    RollingHashFactory(Size initLength, Value maxSigma = 127) \n        : pows(1,\
    \ Value{1}), base{(mt() % (mod - maxSigma)) + maxSigma + 1} {\n        pows.reserve(initLength\
    \ + 1);\n        expand(initLength);\n    }\n\n    class RollingHash {\n    public:\n\
    \        using Value = RollingHashFactory::Value;\n        using Size = RollingHashFactory::Size;\n\
    \        using Hash = RollingHashFactory::Hash;\n    private:\n        using Modulo\
    \ = RollingHashFactory::Modulo;\n        Size n_{};\n        std::vector<Hash>\
    \ prefix_{};\n        std::shared_ptr<std::vector<Value>> pows_{};\n    public:\n\
    \        RollingHash() = default;\n        RollingHash(const std::vector<Hash>&\
    \ prefix, const std::vector<Value>& pows) \n            : n_{prefix.size() - 1},\
    \ prefix_{prefix}, pows_{std::make_shared<std::vector<Value>>(pows)} {}\n\n  \
    \      constexpr Size size() const noexcept {\n            return n_;\n      \
    \  }\n\n        Hash prefix(Size r) const {\n            assert(r <= size());\n\
    \            return prefix_[r];\n        }\n\n        Hash range(Size l, Size\
    \ r) const {\n            assert(l <= size());\n            assert(l <= r);\n\
    \            assert(r <= size());\n            static constexpr Value positiver{4ull\
    \ * Modulo::Mod()};\n            return Hash{\n                Modulo::Modulo(prefix_[r].hash()\
    \ + positiver - Modulo::UnsafeMul(prefix_[l].hash(), (*pows_)[r - l])),\n    \
    \            r - l\n            };\n        }\n\n        Size lcp(Size l1, Size\
    \ r1, Size l2, Size r2) {\n            assert(l1 <= size());\n            assert(r1\
    \ <= size());\n            assert(l2 <= size());\n            assert(r2 <= size());\n\
    \            assert(l1 <= r1);\n            assert(l2 <= r2);\n            Size\
    \ L{}, R{std::min(r1 - l1, r2 - l2) + 1};\n            while (R - L > 1) {\n \
    \               Size mid{(L + R) >> 1};\n                (range(l1, l1 + mid)\
    \ == range(l2, l2 + mid) ? L : R) = mid;\n            }\n            return L;\n\
    \        }\n    };\n\n    template <class RandomAccessIterator>\n    RollingHash\
    \ create(RandomAccessIterator first, RandomAccessIterator last) {\n        static_assert(std::is_convertible_v<decltype(*first),\
    \ Value>, \"value must be convertible to unsigned integer\");\n        Size n{static_cast<Size>(std::distance(first,\
    \ last))};\n        expand(n);\n        std::vector<Hash> roll(1);\n        roll.reserve(n\
    \ + 1);\n        for (auto it{first} ; it != last ; it++) {\n            roll.emplace_back(\n\
    \                Modulo::Modulo(Modulo::UnsafeMul(roll.back().hash(), base) +\
    \ *it),\n                roll.back().len() + 1\n            );\n        }\n  \
    \      return RollingHash(roll, pows);\n    }\n\n    template <class T>\n    RollingHash\
    \ create(const std::vector<T>& a) {\n        return create(a.begin(), a.end());\
    \ \n    }\n\n    template <class T>\n    Hash hash(const std::vector<T>& a) {\n\
    \        static_assert(std::is_convertible_v<T, Value>, \"value must be convertible\
    \ to unsigned integer\");\n        expand(a.size());\n        Value value{};\n\
    \        for (const T& x : a) {\n            value = Modulo::Modulo(Modulo::UnsafeMul(value,\
    \ base) + x);\n        }\n        return Hash{value, a.size()};\n    }\n\n   \
    \ RollingHash create(const std::string& s) {\n        return create(s.begin(),\
    \ s.end());\n    }\n\n    Hash hash(const std::string& s) {\n        expand(s.size());\n\
    \        Value value{};\n        for (const char& c : s) {\n            value\
    \ = Modulo::Modulo(Modulo::UnsafeMul(value, base) + c);\n        }\n        return\
    \ Hash{value, s.size()};\n    }\n\n    Hash concate(const Hash& lhs, const Hash&\
    \ rhs) {\n        return Hash{\n            Modulo::Modulo(Modulo::UnsafeMul(lhs.hash(),\
    \ pows[rhs.len()]) + rhs.hash()),\n            lhs.len() + rhs.len()\n       \
    \ };\n    }\n};\n\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Number/Mersenne61ModInt.hpp
  isVerificationFile: false
  path: Src/Sequence/RollingHash.hpp
  requiredBy: []
  timestamp: '2023-12-04 20:18:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/ALDS1_14_B.test.cpp
  - Test/AtCoder/abc284_f.test.cpp
  - Test/AtCoder/abc141_e.test.cpp
documentation_of: Src/Sequence/RollingHash.hpp
layout: document
title: "\u30ED\u30EA\u30CF"
---

## 概要

`RollingHashFactory`のコンストラクタで、ハッシュ化したい列の取りうる最大長と $\mid \sigma \mid$ をこの順に与えてください。

`RollingHashFactory::create(hogeee)`でロリハ(区間ハッシュが取れるやつ)を作成します。

- `prefix`
- `range`
- `lcp` (こいつ未テスト)
- 型は`auto`で受け取るのが一番楽。真面目に書くなら`RollingHashFactory::RollingHash`

`RollingHashFactory::hash(hogee)`で単に引数の列のハッシュ値を返します。

- 型は`auto`で受け取るのが一番楽。真面目に書くなら`RollingHashFactory::Hash`

ハッシュは`{ hash(), len() }`の構造体となっています。

`RollingHashFactory::concate`でハッシュ値の連結を行うことができます。

ドキュメントを書く気力がないんじゃ

## 参考

- https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
- https://twitter.com/0x3b800001/status/1612589603973914624?s=46

## update