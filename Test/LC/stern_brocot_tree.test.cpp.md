---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/SternBrocotTree.hpp
    title: Stern-Brocot Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/stern_brocot_tree
    links:
    - https://judge.yosupo.jp/problem/stern_brocot_tree
  bundledCode: "#line 1 \"Test/LC/stern_brocot_tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/stern_brocot_tree\"\n\n#line 2 \"Src/Number/SternBrocotTree.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Number/SternBrocotTree.hpp\"\
    \n\n#include <algorithm>\n#include <concepts>\n#include <optional>\n#include <utility>\n\
    #include <vector>\n#include <tuple>\n\nnamespace zawa {\n\nnamespace SternBrocotTree\
    \ {\n\nnamespace sbt_internal {\n\ntemplate <class T>\nconcept Integer = std::integral<T>\
    \ or std::same_as<T, __int128_t> or std::same_as<T, __uint128_t>;\n\n} // namespace\
    \ sbt_internal\n\nenum Direction {\n    Left,\n    Right\n};\n\ntemplate <sbt_internal::Integer\
    \ T>\nusing Path = std::vector<std::pair<Direction, T>>;\n\ntemplate <sbt_internal::Integer\
    \ T>\nusing Node = std::pair<T, T>;\n\ntemplate <sbt_internal::Integer T>\nPath<T>\
    \ Encode(Node<T> node) {\n    auto [a, b] = node;\n    u32 d = [&]() {\n     \
    \   if (a < b) {\n            std::swap(a, b);\n            return 0;\n      \
    \  }\n        else {\n            return 1;\n        }\n    }();\n    std::vector<T>\
    \ quos;\n    while (b) {\n        quos.push_back(a / b);\n        T r = a % b;\n\
    \        a = b;\n        b = r;\n    }\n    if (quos.size()) {\n        quos.back()--;\n\
    \        if (quos.back() == 0)\n            quos.pop_back();\n    }\n    Path<T>\
    \ res;\n    for (T q : quos) {\n        res.push_back({static_cast<Direction>(d),\
    \ q});\n        d ^= 1;\n    }\n    return res;\n}\n\nnamespace sbt_internal {\n\
    \ntemplate <Integer T>\nstd::tuple<Node<T>, Node<T>, Node<T>> Decode(const Path<T>&\
    \ path) {\n    T a = 0, b = 1, c = 1, d = 1, e = 1, f = 0;\n    for (auto [direction,\
    \ step] : path) {\n        if (direction == Left) {\n            e = c + (step\
    \ - 1) * a;\n            f = d + (step - 1) * b;\n            c += step * a;\n\
    \            d += step * b;\n        }\n        else if (direction == Right) {\n\
    \            a = c + (step - 1) * e;\n            b = d + (step - 1) * f;\n  \
    \          c += step * e;\n            d += step * f;\n        } \n    }\n   \
    \ return {Node<T>{a, b}, Node<T>{c, d}, Node<T>{e, f}};\n}\n\n} // namespace sbt_internal\n\
    \ntemplate <sbt_internal::Integer T>\nNode<T> Decode(const Path<T>& path) {\n\
    \    return std::get<1>(sbt_internal::Decode(path));\n}\n\ntemplate <sbt_internal::Integer\
    \ T>\nNode<T> LCA(Node<T> p, Node<T> q) {\n    auto a = Encode(p), b = Encode(q);\n\
    \    Path<T> path;\n    for (usize i = 0 ; i < std::min(a.size(), b.size()) ;\
    \ i++) {\n        if (a[i].first != b[i].first)\n            break;\n        path.push_back({a[i].first,\
    \ std::min(a[i].second, b[i].second)});\n        if (a[i].second != b[i].second)\n\
    \            break;\n    }\n    return Decode(path);\n}\n\n// depth is 0-indexed\n\
    template <sbt_internal::Integer T>\nstd::optional<Node<T>> Ancestor(u64 dep, Node<T>\
    \ n) {\n    Path<T> path;\n    for (auto [direction, step] : Encode(n)) {\n  \
    \      if (dep == 0)\n           break;\n        u64 s = std::min<u64>(dep, step);\n\
    \        path.push_back({direction, s});\n        dep -= s;\n    }\n    if (dep)\n\
    \        return std::nullopt;\n    else\n        return Decode(path);\n}\n\ntemplate\
    \ <sbt_internal::Integer T>\nstd::pair<Node<T>, Node<T>> Range(Node<T> n) {\n\
    \    Node<T> l, r;\n    std::tie(l, std::ignore, r) = sbt_internal::Decode(Encode(n));\n\
    \    return {l, r};\n}\n\n} // namespace SternBrocotTree\n\n\n} // namespace zawa\n\
    #line 4 \"Test/LC/stern_brocot_tree.test.cpp\"\n\n#include <cassert>\n#include\
    \ <iostream>\n#line 8 \"Test/LC/stern_brocot_tree.test.cpp\"\n#include <string>\n\
    using namespace std;\nusing namespace zawa;\nusing Node = SternBrocotTree::Node<int>;\n\
    using Path = SternBrocotTree::Path<int>;\nchar from(SternBrocotTree::Direction\
    \ d) {\n    return d == SternBrocotTree::Left ? 'L' : 'R';\n}\nSternBrocotTree::Direction\
    \ to(char c) {\n    assert(c == 'L' or c == 'R');\n    return c == 'L' ? SternBrocotTree::Left\
    \ : SternBrocotTree::Right;\n}\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n    int Q;\n    cin >> Q;\n    while (Q--) {\n\
    \        string T;\n        cin >> T;\n        if (T == \"ENCODE_PATH\") {\n \
    \           int a, b;\n            cin >> a >> b;\n            Path ans = SternBrocotTree::Encode(Node{a,\
    \ b});\n            cout << ssize(ans);\n            for (auto [d, s] : ans)\n\
    \                cout << ' ' << from(d) << ' ' << s;\n            cout << '\\\
    n';\n        }\n        else if (T == \"DECODE_PATH\") {\n            int k;\n\
    \            cin >> k;\n            Path path(k);\n            for (int i = 0\
    \ ; i < k ; i++) {\n                char c;\n                int s;\n        \
    \        cin >> c >> s;\n                path[i] = {to(c), s};\n            }\n\
    \            auto [a, b] = SternBrocotTree::Decode(path);\n            cout <<\
    \ a << ' ' << b << '\\n';\n        }\n        else if (T == \"LCA\") {\n     \
    \       int a, b, c, d;\n            std::cin >> a >> b >> c >> d;\n         \
    \   auto [p, q] = SternBrocotTree::LCA(Node{a, b}, Node{c, d});\n            cout\
    \ << p << ' ' << q << '\\n';\n        }\n        else if (T == \"ANCESTOR\") {\n\
    \            int k, a, b;\n            cin >> k >> a >> b;\n            auto ans\
    \ = SternBrocotTree::Ancestor(k, Node{a, b});\n            if (ans.has_value())\n\
    \                cout << ans->first << ' ' << ans->second << '\\n';\n        \
    \    else\n                cout << -1 << '\\n';\n        }\n        else if (T\
    \ == \"RANGE\") {\n            int a, b;\n            cin >> a >> b;\n       \
    \     auto [l, r] = SternBrocotTree::Range(Node{a, b});\n            cout << l.first\
    \ << ' ' << l.second << ' ' << r.first << ' ' << r.second << '\\n';\n        }\n\
    \        else\n            assert(0);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\n\n\
    #include \"../../Src/Number/SternBrocotTree.hpp\"\n\n#include <cassert>\n#include\
    \ <iostream>\n#include <vector>\n#include <string>\nusing namespace std;\nusing\
    \ namespace zawa;\nusing Node = SternBrocotTree::Node<int>;\nusing Path = SternBrocotTree::Path<int>;\n\
    char from(SternBrocotTree::Direction d) {\n    return d == SternBrocotTree::Left\
    \ ? 'L' : 'R';\n}\nSternBrocotTree::Direction to(char c) {\n    assert(c == 'L'\
    \ or c == 'R');\n    return c == 'L' ? SternBrocotTree::Left : SternBrocotTree::Right;\n\
    }\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int Q;\n    cin >> Q;\n    while (Q--) {\n        string T;\n        cin\
    \ >> T;\n        if (T == \"ENCODE_PATH\") {\n            int a, b;\n        \
    \    cin >> a >> b;\n            Path ans = SternBrocotTree::Encode(Node{a, b});\n\
    \            cout << ssize(ans);\n            for (auto [d, s] : ans)\n      \
    \          cout << ' ' << from(d) << ' ' << s;\n            cout << '\\n';\n \
    \       }\n        else if (T == \"DECODE_PATH\") {\n            int k;\n    \
    \        cin >> k;\n            Path path(k);\n            for (int i = 0 ; i\
    \ < k ; i++) {\n                char c;\n                int s;\n            \
    \    cin >> c >> s;\n                path[i] = {to(c), s};\n            }\n  \
    \          auto [a, b] = SternBrocotTree::Decode(path);\n            cout << a\
    \ << ' ' << b << '\\n';\n        }\n        else if (T == \"LCA\") {\n       \
    \     int a, b, c, d;\n            std::cin >> a >> b >> c >> d;\n           \
    \ auto [p, q] = SternBrocotTree::LCA(Node{a, b}, Node{c, d});\n            cout\
    \ << p << ' ' << q << '\\n';\n        }\n        else if (T == \"ANCESTOR\") {\n\
    \            int k, a, b;\n            cin >> k >> a >> b;\n            auto ans\
    \ = SternBrocotTree::Ancestor(k, Node{a, b});\n            if (ans.has_value())\n\
    \                cout << ans->first << ' ' << ans->second << '\\n';\n        \
    \    else\n                cout << -1 << '\\n';\n        }\n        else if (T\
    \ == \"RANGE\") {\n            int a, b;\n            cin >> a >> b;\n       \
    \     auto [l, r] = SternBrocotTree::Range(Node{a, b});\n            cout << l.first\
    \ << ' ' << l.second << ' ' << r.first << ' ' << r.second << '\\n';\n        }\n\
    \        else\n            assert(0);\n    }\n}\n"
  dependsOn:
  - Src/Number/SternBrocotTree.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/LC/stern_brocot_tree.test.cpp
  requiredBy: []
  timestamp: '2025-08-23 22:47:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/stern_brocot_tree.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/stern_brocot_tree.test.cpp
- /verify/Test/LC/stern_brocot_tree.test.cpp.html
title: Test/LC/stern_brocot_tree.test.cpp
---
