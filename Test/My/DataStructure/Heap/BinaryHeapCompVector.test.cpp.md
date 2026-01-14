---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Heap/BinaryHeap.hpp
    title: "Binary Heap (\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC)"
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/My/DataStructure/Heap/BinaryHeapCompVector.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"Src/DataStructure/Heap/BinaryHeap.hpp\"\
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
    \            i = j;\n        }\n    }\n};\n\n} // namespace zawa\n#line 4 \"Test/My/DataStructure/Heap/BinaryHeapCompVector.test.cpp\"\
    \nusing namespace zawa;\n\n#include <queue>\n#include <random>\n#line 10 \"Test/My/DataStructure/Heap/BinaryHeapCompVector.test.cpp\"\
    \n#include <iostream>\n#include <chrono>\nusing namespace std;\n\ntemplate <class\
    \ T, class U>\nostream& operator<<(ostream& os, pair<T, U> p) {\n    os << '('\
    \ << p.first << ',' << p.second << ')';\n    return os;\n}\n\ntemplate <class\
    \ T>\nostream& operator<<(ostream& os, vector<T> a) {\n    for (int i = 0 ; i\
    \ < ssize(a) ; i++)\n        os << a[i] << (i + 1 == ssize(a) ? \"\" : \" \");\n\
    \    return os;\n}\n\ntemplate <class Queue>\nint test(const vector<pair<int,\
    \ vector<long long>>>& query) {\n    Queue q;\n    chrono::system_clock::time_point\
    \ start = chrono::system_clock::now();\n    int res = 0;\n    for (auto [t, v]\
    \ : query) {\n        if (t == 0) {\n            q.push(v);\n            res +=\
    \ 1;\n        }\n        else if (t == 1) {\n            if (q.size())\n     \
    \           q.pop();\n            res += 2;\n        }\n    }\n    chrono::system_clock::time_point\
    \ end = chrono::system_clock::now();\n    cerr << chrono::duration_cast<chrono::milliseconds>(end\
    \ - start).count() << endl;\n    return res;\n}\n\nint main() {\n    const int\
    \ Q = 3000000;\n    const int K = 10;\n    mt19937_64 mt{random_device{}()};\n\
    \    const long long V = mt() % (long long)1e18;\n    vector<pair<int, vector<long\
    \ long>>> q(Q);\n    for (int i = 0 ; i < Q / 2 ; i++) {\n        q[i].first =\
    \ 0;\n        q[i].second = vector<long long>(K, V);\n    }\n    for (int i =\
    \ Q / 2 ; i < Q ; i++) {\n        q[i].first = mt() % 2;\n        q[i].second\
    \ = vector<long long>(K, V);\n    }\n    cerr << test<BinaryHeap<vector<long long>>>(q)\
    \ << endl;\n    int A, B;\n    cin >> A >> B;\n    cout << A + B << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../../Src/DataStructure/Heap/BinaryHeap.hpp\"\nusing namespace zawa;\n\n\
    #include <queue>\n#include <random>\n#include <utility>\n#include <vector>\n#include\
    \ <iostream>\n#include <chrono>\nusing namespace std;\n\ntemplate <class T, class\
    \ U>\nostream& operator<<(ostream& os, pair<T, U> p) {\n    os << '(' << p.first\
    \ << ',' << p.second << ')';\n    return os;\n}\n\ntemplate <class T>\nostream&\
    \ operator<<(ostream& os, vector<T> a) {\n    for (int i = 0 ; i < ssize(a) ;\
    \ i++)\n        os << a[i] << (i + 1 == ssize(a) ? \"\" : \" \");\n    return\
    \ os;\n}\n\ntemplate <class Queue>\nint test(const vector<pair<int, vector<long\
    \ long>>>& query) {\n    Queue q;\n    chrono::system_clock::time_point start\
    \ = chrono::system_clock::now();\n    int res = 0;\n    for (auto [t, v] : query)\
    \ {\n        if (t == 0) {\n            q.push(v);\n            res += 1;\n  \
    \      }\n        else if (t == 1) {\n            if (q.size())\n            \
    \    q.pop();\n            res += 2;\n        }\n    }\n    chrono::system_clock::time_point\
    \ end = chrono::system_clock::now();\n    cerr << chrono::duration_cast<chrono::milliseconds>(end\
    \ - start).count() << endl;\n    return res;\n}\n\nint main() {\n    const int\
    \ Q = 3000000;\n    const int K = 10;\n    mt19937_64 mt{random_device{}()};\n\
    \    const long long V = mt() % (long long)1e18;\n    vector<pair<int, vector<long\
    \ long>>> q(Q);\n    for (int i = 0 ; i < Q / 2 ; i++) {\n        q[i].first =\
    \ 0;\n        q[i].second = vector<long long>(K, V);\n    }\n    for (int i =\
    \ Q / 2 ; i < Q ; i++) {\n        q[i].first = mt() % 2;\n        q[i].second\
    \ = vector<long long>(K, V);\n    }\n    cerr << test<BinaryHeap<vector<long long>>>(q)\
    \ << endl;\n    int A, B;\n    cin >> A >> B;\n    cout << A + B << '\\n';\n}\n"
  dependsOn:
  - Src/DataStructure/Heap/BinaryHeap.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/My/DataStructure/Heap/BinaryHeapCompVector.test.cpp
  requiredBy: []
  timestamp: '2026-01-14 16:33:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/My/DataStructure/Heap/BinaryHeapCompVector.test.cpp
layout: document
redirect_from:
- /verify/Test/My/DataStructure/Heap/BinaryHeapCompVector.test.cpp
- /verify/Test/My/DataStructure/Heap/BinaryHeapCompVector.test.cpp.html
title: Test/My/DataStructure/Heap/BinaryHeapCompVector.test.cpp
---
