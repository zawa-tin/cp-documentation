---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc247_d.test.cpp
    title: Test/AtCoder/abc247_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc299_c.test.cpp
    title: Test/AtCoder/abc299_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc311_b.test.cpp
    title: Test/AtCoder/abc311_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/agc026_a.test.cpp
    title: Test/Manual/agc026_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Sequence/RunLengthEncoding.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
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
    \ res;\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <deque>\n\
    #include <vector>\n#include <cassert>\n\nnamespace zawa {\n\ntemplate <class Value,\
    \ class Number = u64>\nclass RunLengthEncoding {\npublic:\n    class Data {\n\
    \    private:\n        Value value_;\n        Number number_;\n    public:\n \
    \       Data() = default;\n        Data(const Value& value, Number number) : value_{\
    \ value }, number_{ number } {}\n\n        const Value& value() const noexcept\
    \ {\n            return value_;\n        }\n\n        Number number() const noexcept\
    \ {\n            return number_;\n        }\n\n        friend RunLengthEncoding;\n\
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
    \ res;\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Sequence/RunLengthEncoding.hpp
  requiredBy: []
  timestamp: '2023-07-29 13:13:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Manual/agc026_a.test.cpp
  - Test/AtCoder/abc311_b.test.cpp
  - Test/AtCoder/abc299_c.test.cpp
  - Test/AtCoder/abc247_d.test.cpp
documentation_of: Src/Sequence/RunLengthEncoding.hpp
layout: document
title: "\u9023\u9577\u5727\u7E2E"
---

## 概要

長さ $N$ の列 $A$ を連長圧縮して、各要素を管理します。また、先頭と末尾に限り要素の追加、削除に対応しています。

与えられた列の連続した要素を (要素、連続している数) のペアの列で表現することを連長圧縮といいます。

例えば、 $A = (1, 1, 2, 3, 3, 3, 4, 1, 1)$ を連長圧縮した列は $((1, 2), (2, 1), (3, 3), (4, 1), (1, 2))$ です。

以後、入力の列を $A$ 、連長圧縮後の列を $B$ とします。

<br />

## 使い方

#### テンプレート引数

```cpp
template <class Value, class Number = u64>
```

$A$ の要素の型を`Value`に指定します。 「連続している数」の型を`Number`に指定します。`Number`はデフォルトで`zawa::u64 = std::uint64_t`が指定されています。

<br />

#### コンストラクタ

```cpp
(1) RunLengthEncoding() = default;
(2) RunLengthEncoding<InputIterator>(InputIterator first, InputIterator last)
(3) RunLengthEncoding(const std::vector<Value>& a)
```

(1) デフォルトコンストラクタ: 空列で $B$ を構築する

**計算量**: 定数時間

(2) イテレータ範囲コンストラクタ: `[first, last)`の範囲を要素として $B$ を構築する

- `std::string`等に対してはこのコンストラクタを使用してください

**計算量**: `first`から`last`の距離に対して線形時間

(3) `A`から $B$ を構築する

**計算量**: $O(\mid A \mid)$

<br />

#### size

```cpp
constexpr usize size() const noexcept
```

$\mid B\mid$ を返します。

**計算量**: 定数時間

<br />

#### sum

```cpp
constexpr u64 sum() const noexcept
```

$\mid A\mid$ を返します。

**計算量**: 定数時間

<br />

#### operator[]

```cpp
const Data& operator[](u32 i) const noexcept
```

$B_{i}$ を返します。 `Data`は以下のようなクラスです。

```cpp
class Data {
private:
    Value value_;
    Number number_;
public:
    const Value& value() const noexcept // 要素の値
    Number number() const noexcept // 連続している数
};
```

**制約**: $0\ \le\ i\ \le\ \mid B\mid$

**計算量**: 定数時間

<br />

#### value

```cpp
const Value& value(u32 i) const noexcept
```

$B_i$ の保管している要素を返します。

**制約**: $0\ \le\ i\ \le\ \mid B\mid$

**計算量**: 定数時間

<br />

#### number

```cpp
const Number number(u32 i) const noexcept {
```

$B_i$ の連続している数を返します。

**制約**: $0\ \le\ i\ \le\ \mid B\mid$

**計算量**: 定数時間

<br />

#### begin

```cpp
typename decltype(seq_)::const_iterator begin() const noexcept
```

$B$ の先頭要素の`const_iterator`を返します。(要素の変更を想定していないため、`const`でないイテレータは提供していません)

**計算量**: 定数時間

<br />

#### end

```cpp
typename decltype(seq_)::const_iterator end() const noexcept
```

$B$ の末尾の次の要素の`const_iterator`を返します。(要素の変更を想定していないため、`const`でないイテレータは提供していません)

**計算量**: 定数時間

<br />

#### pushBack

```cpp
void pushBack(const Value& value, const Number number = Number{1})
```

$A$ の末尾に`value`を`number`個挿入します。応じて $B$ も変更されます。

- `number`はデフォルトで $1$ になっています。

**計算量**: 定数時間

<br />

#### pushFront

```cpp
void pushFront(const Value& value, const Number number = Number{1}) {
```

$A$ の末尾に`value`を`number`個挿入します。応じて $B$ も変更されます。

- `number`はデフォルトで $1$ になっています。

**計算量**: 定数時間

<br />

#### popBack

```cpp
(1) void popBack()
(2) std::vector<Data> popBack(u64 number)
```

(1) $B$ の末尾要素を除去する。 $A$ も応じて変更される (先頭から末尾要素を連続している分除去する)

**制約**: $B$ が非空であること

**計算量**: 定数時間


(2) $A$ を末尾から`number`要素除去する。除去した要素を連長圧縮した`vector`を返す。

- $B$ も応じて変更される

**制約**: $\text{number}\ \le\ \mid A\mid$

**計算量**: $O(\mid B\mid)$

- `pushBack`や`pushFront`を呼ば出さない場合、`(2)popFront``(2)popBack`を呼び出した全体の計算時間の実行限界が $O(\mid B\mid)$ に抑えられます。

<br />

#### popFront

```cpp
(1) void popFront()
(2) std::vector<Data> popFront(u64 number)
```

(1) $B$ の先頭要素を除去する。 $A$ も応じて変更される (先頭から先頭要素を連続している分除去する)

**制約**: $B$ が非空であること

**計算量**: 定数時間


(2) $A$ を先頭から`number`要素除去する。除去した要素を連長圧縮した`vector`を返す。

- $B$ も応じて変更される

**制約**: $\text{number}\ \le\ \mid A\mid$

**計算量**: $O(\mid B\mid)$

- `pushBack`や`pushFront`を呼ば出さない場合、`(2)popFront``(2)popBack`を呼び出した全体の計算時間の実行限界が $O(\mid B\mid)$ に抑えられます。

<br />

## アルゴリズム

よしなにやっています。 $B$ を`std::deque`で持つことで`pushHoge popHoge`に対応しています。
