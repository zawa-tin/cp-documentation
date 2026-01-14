---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Action/SetOperator.hpp
    title: Src/Algebra/Action/SetOperator.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Heap/BinaryHeap.hpp
    title: "Binary Heap (\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC)"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Heap/EraseablePriorityQueue.hpp
    title: Src/DataStructure/Heap/EraseablePriorityQueue.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc306_e.test.cpp
    title: Test/AtCoder/abc306_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc440_f.test.cpp
    title: Test/AtCoder/abc440_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/arc196_a.test.cpp
    title: Test/AtCoder/arc196_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/Heap/PartitionedProducts.hpp\"\n\n#line\
    \ 2 \"Src/DataStructure/Heap/EraseablePriorityQueue.hpp\"\n\n#line 2 \"Src/DataStructure/Heap/BinaryHeap.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/Heap/BinaryHeap.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <concepts>\n#include <utility>\n\
    #include <vector>\n#include <functional>\n\nnamespace zawa {\n\ntemplate <class\
    \ T, class Comp = std::less<T>>\nrequires std::strict_weak_order<Comp, const T&,\
    \ const T&>\nclass BinaryHeap {\nprivate:\n\n    Comp m_comp;\n\n    std::vector<T>\
    \ m_dat;\n\npublic:\n\n    inline usize size() const {\n        return m_dat.size()\
    \ - 1;\n    }\n\n    inline bool empty() const {\n        return m_dat.size()\
    \ == 1;\n    }\n\n    inline const Comp& comp() const {\n        return m_comp;\n\
    \    }\n\n    using const_iterator = typename decltype(m_dat)::const_iterator;\n\
    \n    const_iterator begin() const {\n        return m_dat.begin() + 1;\n    }\n\
    \n    const_iterator end() const {\n        return m_dat.end();\n    }\n\n   \
    \ BinaryHeap(Comp comp = {}) \n        : m_comp{comp}, m_dat(1) {}\n\n    template\
    \ <std::forward_iterator It>\n    requires std::same_as<std::iter_value_t<It>,\
    \ T>\n    BinaryHeap(It first, It last, Comp comp = {}) \n        : m_comp{comp},\
    \ m_dat(1) {\n        m_dat.insert(m_dat.end(), first, last);\n        build();\n\
    \    }\n\n    BinaryHeap(std::vector<T>&& a, Comp comp = {}) \n        : m_comp{comp},\
    \ m_dat(a.size() + 1) {\n        std::ranges::copy(std::make_move_iterator(a.begin()),\
    \ std::make_move_iterator(a.end()), m_dat.begin() + 1);\n        build();\n  \
    \  }\n\n    BinaryHeap(const std::vector<T>& a, Comp comp = {}) \n        : m_comp{comp},\
    \ m_dat(a.size() + 1) {\n        std::ranges::copy(a.begin(), a.end(), m_dat.begin()\
    \ + 1);\n        build();\n    }\n\n    const T& top() const {\n        assert(size()\
    \ and \"HeapUnderFlow\");\n        return m_dat[1];\n    }\n\n    void push(T&&\
    \ v) {\n        m_dat.push_back(std::move(v));\n        upHeap(size());\n    }\n\
    \n    void push(const T& v) {\n        m_dat.push_back(v);\n        upHeap(size());\n\
    \    }\n\n    void pop() {\n        assert(size() and \"HeapUnderFlow\");\n  \
    \      if (size() > 1)\n            std::swap(m_dat[1], m_dat.back());\n     \
    \   m_dat.pop_back();\n        if (size() > 1)\n            downHeap(1, size());\n\
    \    }\n\nprivate:\n\n    void build() {\n        const usize n = size();\n  \
    \      for (usize i = (n >> 1) ; i ; i--) \n            downHeap(i, n);\n    }\n\
    \n    void upHeap(usize i) {\n        while (i >> 1 and m_comp(m_dat[i], m_dat[i\
    \ >> 1])) {\n            std::swap(m_dat[i], m_dat[i >> 1]);\n            i >>=\
    \ 1;\n        }\n    }\n\n    void downHeap(usize i, usize n) {\n        while\
    \ ((i << 1) <= n) {\n            usize j = i << 1;\n            if (j + 1 <= n\
    \ and m_comp(m_dat[j + 1], m_dat[j]))\n                j++;\n            if (!m_comp(m_dat[j],\
    \ m_dat[i]))\n                break;\n            std::swap(m_dat[i], m_dat[j]);\n\
    \            i = j;\n        }\n    }\n};\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/Heap/EraseablePriorityQueue.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T, class Comp = std::less<T>>\nrequires\
    \ std::strict_weak_order<Comp, const T&, const T&>\nclass EraseablePriorityQueue\
    \ {\nprivate:\n\n    BinaryHeap<T, Comp> m_que, m_rm;\n\n    usize m_cnt = 0;\n\
    \npublic:\n\n    inline usize size() const {\n        return m_cnt;\n    }\n\n\
    \    inline bool empty() const {\n        return m_cnt == 0;\n    }\n\n    EraseablePriorityQueue(Comp\
    \ comp = {}) \n        : m_que{comp}, m_rm{comp}, m_cnt{0} {}\n\n    template\
    \ <std::forward_iterator It>\n    requires std::same_as<std::iter_value_t<It>,\
    \ T>\n    EraseablePriorityQueue(It first, It last, Comp comp = {})\n        :\
    \ m_que{first, last, comp}, m_rm{comp}, m_cnt{m_que.size()} {}\n\n    EraseablePriorityQueue(std::vector<T>\
    \ a, Comp comp = {}) \n        : m_que{a, comp}, m_rm{comp}, m_cnt{m_que.size()}\
    \ {}\n\n    template <class U>\n    requires std::same_as<std::remove_cvref_t<U>,\
    \ T>\n    void push(U&& v) {\n        m_que.push(std::forward<U>(v));\n      \
    \  m_cnt++;\n    }\n\n    template <class U>\n    requires std::same_as<std::remove_cvref_t<U>,\
    \ T>\n    void erase(U&& v) {\n        assert(size() and \"HeapUnderFlow\");\n\
    \        m_rm.push(std::forward<U>(v));\n        m_cnt--;\n    }\n\n    const\
    \ T& top() {\n        assert(size() and \"HeapUnderFlow\");\n        normalize();\n\
    \        return m_que.top();\n    }\n\n    T pop() {\n        assert(size() and\
    \ \"HeapUnderFlow\");\n        normalize();\n        T res = m_que.top();\n  \
    \      m_que.pop();\n        m_cnt--;\n        return res;\n    }\n\n    std::vector<T>\
    \ container() const {\n        BinaryHeap que = m_que, rm = m_rm;  \n        std::vector<T>\
    \ res;\n        while (que.size()) {\n            if (rm.empty() or que.comp()(que.top(),\
    \ rm.top())) {\n                res.push_back(que.top());\n                que.pop();\n\
    \            }\n            else if (que.top() == rm.top())\n                que.pop(),\
    \ rm.pop();\n            else\n                rm.pop();\n        }\n        return\
    \ res;\n    }\n\nprivate:\n\n    void normalize() {\n        while (m_rm.size()\
    \ and m_que.size()) {\n            if (m_que.top() == m_rm.top())\n          \
    \      m_que.pop(), m_rm.pop();\n            else if (m_que.comp()(m_rm.top(),\
    \ m_que.top()))\n                m_rm.pop();\n            else\n             \
    \   break;\n        }\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Action/SetOperator.hpp\"\
    \n\n#line 4 \"Src/Algebra/Action/SetOperator.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ concepts {\n\ntemplate <class S, class T>\nconcept SetOperator = requires {\n\
    \    typename S::Element;\n    { S::identity() } -> std::same_as<typename S::Element>;\n\
    \    { S::add(std::declval<typename S::Element&>(), std::declval<T>()) } -> std::same_as<void>;\n\
    \    { S::remove(std::declval<typename S::Element&>(), std::declval<T>()) } ->\
    \ std::same_as<void>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n\
    #line 5 \"Src/DataStructure/Heap/PartitionedProducts.hpp\"\n\n#line 7 \"Src/DataStructure/Heap/PartitionedProducts.hpp\"\
    \n\nnamespace zawa {\n\nnamespace internal {\n\ntemplate <class Comp>\nstruct\
    \ ReverseComp {\n\n    [[no_unique_address]] Comp comp;\n\n    ReverseComp() =\
    \ default;\n\n    explicit ReverseComp(Comp c) : comp(std::move(c)) {}\n\n   \
    \ template <class T, class U>\n    bool operator()(T&& a, U&& b) const noexcept(noexcept(std::invoke(comp,\
    \ std::forward<U>(b), std::forward<T>(a)))) {\n        return std::invoke(comp,\
    \ std::forward<U>(b), std::forward<T>(a));\n    }\n};\n\n} // namespace internal\n\
    \ntemplate <class S, class T, class Comp = std::less<T>>\nrequires concepts::SetOperator<S,\
    \ T> and std::strict_weak_order<Comp, const T&, const T&>\nclass PartitionedProducts\
    \ {\npublic:\n\n    PartitionedProducts(Comp comp = {}) \n        : m_sm{internal::ReverseComp{comp}},\
    \ m_bg{comp}, m_comp{comp} {}\n\n    PartitionedProducts(std::vector<T> a, Comp\
    \ comp = {}) \n        : m_sm{}, m_bg{comp}, m_comp{comp} {\n        for (const\
    \ T& x : a)\n            S::add(m_prodS, x);\n        m_sm = EraseablePriorityQueue{std::move(a),\
    \ internal::ReverseComp{comp}};\n    }\n\n    inline usize size() const {\n  \
    \      return m_sm.size() + m_bg.size();\n    }\n\n    inline usize smallSize()\
    \ const {\n        return m_sm.size();\n    }\n\n    inline usize bigSize() const\
    \ {\n        return m_bg.size();\n    }\n\n    inline bool empty() const {\n \
    \       return m_sm.empty() and m_bg.empty();\n    }\n\n    template <class U>\n\
    \    requires std::same_as<std::remove_cvref_t<U>, T>\n    void insert(U&& v)\
    \ {\n        if (m_sm.empty())\n            addBig(std::forward<U>(v));\n    \
    \    else if (m_bg.empty() or m_comp(v, m_bg.top()))\n            addSmall(std::forward<U>(v));\n\
    \        else\n            addBig(std::forward<U>(v));\n    }\n\n    template\
    \ <class U>\n    requires std::same_as<std::remove_cvref_t<U>, T>\n    void erase(U&&\
    \ v) {\n        if (m_sm.empty())\n            eraseBig(std::forward<U>(v));\n\
    \        else if (m_bg.empty() or m_comp(v, m_bg.top()))\n            eraseSmall(std::forward<U>(v));\n\
    \        else\n            eraseBig(std::forward<U>(v));\n    }\n\n    bool adjustSmall(usize\
    \ K) {\n        if (size() < K)\n            return false;\n        adjust(K);\n\
    \        return true;\n    }\n\n    bool adjustBig(usize K) {\n        if (size()\
    \ < K)\n            return false;\n        adjust(size() - K);\n        return\
    \ true;\n    }\n\n    const T& smallTop() {\n        assert(smallSize() and \"\
    HeapUnderFlow: small\");\n        return m_sm.top();\n    }\n\n    const S::Element&\
    \ smallProd() const {\n        return m_prodS;\n    }\n\n    const T& bigTop()\
    \ {\n        assert(bigSize() and \"HeapUnderFlow: big\");\n        return m_bg.top();\n\
    \    }\n\n    const S::Element& bigProd() const {\n        return m_prodB;\n \
    \   }\n\n    std::pair<std::vector<T>, std::vector<T>> container() const {\n \
    \       return {m_sm.container(), m_bg.container()};\n    }\n\nprivate:\n\n  \
    \  EraseablePriorityQueue<T, internal::ReverseComp<Comp>> m_sm;\n\n    EraseablePriorityQueue<T,\
    \ Comp> m_bg;\n\n    Comp m_comp;\n\n    S::Element m_prodS = S::identity(), m_prodB\
    \ = S::identity();\n\n    template <class U>\n    requires std::same_as<std::remove_cvref_t<U>,\
    \ T>\n    void addSmall(U&& v) {\n        S::add(m_prodS, v);\n        m_sm.push(std::forward<U>(v));\n\
    \    }\n\n    template <class U>\n    requires std::same_as<std::remove_cvref_t<U>,\
    \ T>\n    void addBig(U&& v) {\n        S::add(m_prodB, v);\n        m_bg.push(std::forward<U>(v));\n\
    \    }\n\n    template <class U>\n    requires std::same_as<std::remove_cvref_t<U>,\
    \ T>\n    void eraseSmall(U&& v) {\n        S::remove(m_prodS, v);\n        m_sm.erase(std::forward<U>(v));\n\
    \    }\n\n    template <class U>\n    requires std::same_as<std::remove_cvref_t<U>,\
    \ T>\n    void eraseBig(U&& v) {\n        S::remove(m_prodB, v);\n        m_bg.erase(std::forward<U>(v));\n\
    \    }\n\n    void adjust(usize K) {\n        while (smallSize() > K) {\n    \
    \        addBig(m_sm.top());\n            S::remove(m_prodS, m_sm.top());\n  \
    \          m_sm.pop();\n        }\n        while (smallSize() < K) {\n       \
    \     addSmall(m_bg.top());\n            S::remove(m_prodB, m_bg.top());\n   \
    \         m_bg.pop();\n        }\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"EraseablePriorityQueue.hpp\"\n#include \"../../Algebra/Action/SetOperator.hpp\"\
    \n\n#include <utility>\n\nnamespace zawa {\n\nnamespace internal {\n\ntemplate\
    \ <class Comp>\nstruct ReverseComp {\n\n    [[no_unique_address]] Comp comp;\n\
    \n    ReverseComp() = default;\n\n    explicit ReverseComp(Comp c) : comp(std::move(c))\
    \ {}\n\n    template <class T, class U>\n    bool operator()(T&& a, U&& b) const\
    \ noexcept(noexcept(std::invoke(comp, std::forward<U>(b), std::forward<T>(a))))\
    \ {\n        return std::invoke(comp, std::forward<U>(b), std::forward<T>(a));\n\
    \    }\n};\n\n} // namespace internal\n\ntemplate <class S, class T, class Comp\
    \ = std::less<T>>\nrequires concepts::SetOperator<S, T> and std::strict_weak_order<Comp,\
    \ const T&, const T&>\nclass PartitionedProducts {\npublic:\n\n    PartitionedProducts(Comp\
    \ comp = {}) \n        : m_sm{internal::ReverseComp{comp}}, m_bg{comp}, m_comp{comp}\
    \ {}\n\n    PartitionedProducts(std::vector<T> a, Comp comp = {}) \n        :\
    \ m_sm{}, m_bg{comp}, m_comp{comp} {\n        for (const T& x : a)\n         \
    \   S::add(m_prodS, x);\n        m_sm = EraseablePriorityQueue{std::move(a), internal::ReverseComp{comp}};\n\
    \    }\n\n    inline usize size() const {\n        return m_sm.size() + m_bg.size();\n\
    \    }\n\n    inline usize smallSize() const {\n        return m_sm.size();\n\
    \    }\n\n    inline usize bigSize() const {\n        return m_bg.size();\n  \
    \  }\n\n    inline bool empty() const {\n        return m_sm.empty() and m_bg.empty();\n\
    \    }\n\n    template <class U>\n    requires std::same_as<std::remove_cvref_t<U>,\
    \ T>\n    void insert(U&& v) {\n        if (m_sm.empty())\n            addBig(std::forward<U>(v));\n\
    \        else if (m_bg.empty() or m_comp(v, m_bg.top()))\n            addSmall(std::forward<U>(v));\n\
    \        else\n            addBig(std::forward<U>(v));\n    }\n\n    template\
    \ <class U>\n    requires std::same_as<std::remove_cvref_t<U>, T>\n    void erase(U&&\
    \ v) {\n        if (m_sm.empty())\n            eraseBig(std::forward<U>(v));\n\
    \        else if (m_bg.empty() or m_comp(v, m_bg.top()))\n            eraseSmall(std::forward<U>(v));\n\
    \        else\n            eraseBig(std::forward<U>(v));\n    }\n\n    bool adjustSmall(usize\
    \ K) {\n        if (size() < K)\n            return false;\n        adjust(K);\n\
    \        return true;\n    }\n\n    bool adjustBig(usize K) {\n        if (size()\
    \ < K)\n            return false;\n        adjust(size() - K);\n        return\
    \ true;\n    }\n\n    const T& smallTop() {\n        assert(smallSize() and \"\
    HeapUnderFlow: small\");\n        return m_sm.top();\n    }\n\n    const S::Element&\
    \ smallProd() const {\n        return m_prodS;\n    }\n\n    const T& bigTop()\
    \ {\n        assert(bigSize() and \"HeapUnderFlow: big\");\n        return m_bg.top();\n\
    \    }\n\n    const S::Element& bigProd() const {\n        return m_prodB;\n \
    \   }\n\n    std::pair<std::vector<T>, std::vector<T>> container() const {\n \
    \       return {m_sm.container(), m_bg.container()};\n    }\n\nprivate:\n\n  \
    \  EraseablePriorityQueue<T, internal::ReverseComp<Comp>> m_sm;\n\n    EraseablePriorityQueue<T,\
    \ Comp> m_bg;\n\n    Comp m_comp;\n\n    S::Element m_prodS = S::identity(), m_prodB\
    \ = S::identity();\n\n    template <class U>\n    requires std::same_as<std::remove_cvref_t<U>,\
    \ T>\n    void addSmall(U&& v) {\n        S::add(m_prodS, v);\n        m_sm.push(std::forward<U>(v));\n\
    \    }\n\n    template <class U>\n    requires std::same_as<std::remove_cvref_t<U>,\
    \ T>\n    void addBig(U&& v) {\n        S::add(m_prodB, v);\n        m_bg.push(std::forward<U>(v));\n\
    \    }\n\n    template <class U>\n    requires std::same_as<std::remove_cvref_t<U>,\
    \ T>\n    void eraseSmall(U&& v) {\n        S::remove(m_prodS, v);\n        m_sm.erase(std::forward<U>(v));\n\
    \    }\n\n    template <class U>\n    requires std::same_as<std::remove_cvref_t<U>,\
    \ T>\n    void eraseBig(U&& v) {\n        S::remove(m_prodB, v);\n        m_bg.erase(std::forward<U>(v));\n\
    \    }\n\n    void adjust(usize K) {\n        while (smallSize() > K) {\n    \
    \        addBig(m_sm.top());\n            S::remove(m_prodS, m_sm.top());\n  \
    \          m_sm.pop();\n        }\n        while (smallSize() < K) {\n       \
    \     addSmall(m_bg.top());\n            S::remove(m_prodB, m_bg.top());\n   \
    \         m_bg.pop();\n        }\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/DataStructure/Heap/EraseablePriorityQueue.hpp
  - Src/DataStructure/Heap/BinaryHeap.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Action/SetOperator.hpp
  isVerificationFile: false
  path: Src/DataStructure/Heap/PartitionedProducts.hpp
  requiredBy: []
  timestamp: '2026-01-14 16:33:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/arc196_a.test.cpp
  - Test/AtCoder/abc306_e.test.cpp
  - Test/AtCoder/abc440_f.test.cpp
documentation_of: Src/DataStructure/Heap/PartitionedProducts.hpp
layout: document
title: "\u8981\u7D20\u6607\u9806 $K$ \u500B\u3001\u964D\u9806 $N - K$ \u500B\u306E\
  \u7DCF\u7A4D\u3092\u7BA1\u7406"
---

いわゆる「Priority Queue二つ持ってガチャガチャやるやつ」。海外だとSmartSetなんて呼ばれているやつかも

## ライブラリの使い方

内部で二つの削除可能Priority Queueを管理していて、昇順 $K$ 個を管理している方を`small`、他方を`big`と呼ぶことにする。

### テンプレート引数

```cpp
template <class S, class T, class Comp = std::less<T>>
requires concepts::SetOperator<S, T> and std::strict_weak_order<Comp, const T&, const T&>
class PartitionedProducts
```

`S`が総積の取り方を決める代数的構造。`T`が各要素を意味する。
- `S::Element`の単位元
- `S::Element`に`T`の要素を追加する
- `S::Element`に追加されていた`T`の要素を取り除く

のみっつが定義されていれば良い。例えばかけざんならば、

```
struct OP {
    using Element = long long;
    static Element identity() {
        return 1;
    }
    static void add(Element& a, int x) {
        a *= x;
    }
    static void remove(Element& a, int x) {
        assert(a % x == 0);
        return a / x;
    }
};
```
で良い。このように`S::Element`と`T`は必ずしも同じ要素である必要は無い。

### コンストラクタ

```cpp
(1) PartitionedProducts(Comp comp = {}) 
(2) PartitionedProducts(std::vector<T> a, Comp comp = {}) 
```

`comp`は指定しなければ`std::less<T>`になる。(`std::less<T>`以外のケースverifyしてないけど、ばぐってなければよいが...)

(2)において`a`は全部`small`側に入る。

**計算量:** (2)は $O(N)$

###  size(), empty()

```
inline usize size() const
inline usize smallSize() const
inline usize bigSize() const
inline bool empty() const
```

### insert

```cpp
template <class U>
requires std::same_as<std::remove_cvref_t<U>, T>
void insert(U&& v)
```

なにやらややこしいが、`T, const T&, T&&`以外で使用することは基本的に想定されていない

**計算量:** $O(\log N)$

### erase

```cpp
template <class U>
requires std::same_as<std::remove_cvref_t<U>, T>
void erase(U&& v)
```

なにやらややこしいが、`T, const T&, T&&`以外で使用することは基本的に想定されていない

**queに存在しない要素をeraseに呼んでもassertなどにはひっかからないが、後々のクエリでassert:Heap Underflowを発生させる。**

- これを咎めようとするとハッシュセットを別途持つ必要などがでてきて、諦めることにした。ユーザー側の責任とする。

**計算量:** $O(\log N)$


### adjust

```cpp
bool adjustSmall(usize K)
bool adjustBig(usize K)
```

それぞれ、`small`、`big`の個数が $K$ になるように調節し、trueを返す。`size() < K`のときは`false`を返し、何もしない。

### top

```cpp
const T& smallTop()
const T& bigTop()
```

呼び出す前に`smallSize(), bigSize()`を確認しておくと良い。

**計算量:** ならし $O(1)$

### prod

```cpp
const S::Element& smallProd() const;
const S::Element& bigProd() const
```

**計算量:** $O(1)$

### container

```cpp
std::pair<std::vector<T>, std::vector<T>> container() const
```

デバッグ目的。`first`にsmall, `second`にbigがある。
