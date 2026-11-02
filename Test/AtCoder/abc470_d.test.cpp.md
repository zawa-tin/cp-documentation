---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/SymmetricGroup.hpp
    title: "\u5BFE\u79F0\u7FA4"
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
    - https://atcoder.jp/contests/abc470/submissions/80553925
    - https://atcoder.jp/contests/abc470/tasks/abc470_d
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/AtCoder/abc470_d.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc470/tasks/abc470_d\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n/*\n * AtCoder Beginner Contest 470 D - Inverse and Swap\n * https://atcoder.jp/contests/abc470/submissions/80553925\n\
    \ */\n#line 2 \"Src/Algebra/Group/SymmetricGroup.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Algebra/Group/SymmetricGroup.hpp\"\n\n#include\
    \ <array>\n#include <cassert>\n#include <concepts>\n#include <numeric>\n#include\
    \ <span>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ zawa {\n\ntemplate <usize N = std::dynamic_extent,std::integral T = usize>\n\
    class SymmetricGroup {\npublic:\n\n    using Container = std::conditional_t<N==std::dynamic_extent,std::vector<T>,std::array<T,N>>;\n\
    \n    using Element = SymmetricGroup;\n\n    constexpr SymmetricGroup() requires\
    \ (N!=std::dynamic_extent) {\n        std::iota(m_perm.begin(),m_perm.end(),T{0});\n\
    \        std::iota(m_inv.begin(),m_inv.end(),T{0});\n    }\n\n    explicit SymmetricGroup(usize\
    \ n) requires (N==std::dynamic_extent) : m_perm(n), m_inv(n) {\n        std::iota(m_perm.begin(),m_perm.end(),T{0});\n\
    \        std::iota(m_inv.begin(),m_inv.end(),T{0});\n    }\n\n    explicit SymmetricGroup(std::array<T,N>\
    \ p) requires (N!=std::dynamic_extent) : m_perm{std::move(p)}, m_inv{} {\n   \
    \     for (usize i = 0 ; i < N ; i++)\n            m_inv[m_perm[i]]=i;\n    }\n\
    \n    explicit SymmetricGroup(std::vector<T> p) requires (N==std::dynamic_extent)\
    \ : m_perm{std::move(p)}, m_inv(m_perm.size()) {\n        for (usize i = 0 ; i\
    \ < size() ; i++)\n            m_inv[m_perm[i]]=i;\n    }\n\n    inline constexpr\
    \ usize size() const noexcept {\n        return m_perm.size();\n    }\n\n    inline\
    \ usize operator[](usize i) const noexcept {\n        assert(i<size());\n    \
    \    return m_perm[i];\n    }\n\n    inline T position(usize i) const noexcept\
    \ {\n        assert(i<size());\n        return m_inv[i];\n    }\n\n    void swap(usize\
    \ i,usize j) {\n        assert(i < size());\n        assert(j < size());\n   \
    \     std::swap(m_inv[m_perm[i]],m_inv[m_perm[j]]);\n        std::swap(m_perm[i],m_perm[j]);\n\
    \    }\n\n    void composite(const SymmetricGroup& sym) {\n        assert(size()==sym.size());\n\
    \        Container perm;\n        if constexpr (std::same_as<Container,std::vector<T>>)\n\
    \            perm.resize(size());\n        for (usize i = 0 ; i < size() ; i++)\
    \ {\n            perm[i]=sym[m_perm[i]];\n            m_inv[perm[i]]=i;\n    \
    \    }\n        m_perm=std::move(perm);\n    }\n\n    void invert() {\n      \
    \  std::swap(m_perm,m_inv);\n    }\n\n    static SymmetricGroup identity() {\n\
    \        return SymmetricGroup{};\n    }\n\n    static SymmetricGroup operation(SymmetricGroup\
    \ l,const SymmetricGroup& r) {\n        l.composite(r);\n        return l;\n \
    \   }\n\n    static SymmetricGroup inverse(SymmetricGroup sym) {\n        sym.invert();\n\
    \        return sym;\n    }\n\n    template <class U,usize M>\n    static std::array<U,M>\
    \ action(const SymmetricGroup& g,const std::array<U,M>& a) requires (N == std::dynamic_extent\
    \ or N <= M) {\n        assert(g.size() <= M);\n        std::array<U,M> res;\n\
    \        for (usize i = 0 ; i < g.size() ; i++)\n            res[g[i]]=a[i];\n\
    \        for (usize i = g.size() ; i < a.size() ; i++)\n            res[i]=a[i];\n\
    \        return res;\n    }\n\n    template <class U>\n    static std::vector<U>\
    \ action(const SymmetricGroup& g,const std::vector<U>& a) {\n        assert(g.size()<=a.size());\n\
    \        std::vector<U> res(a.size());\n        for (usize i = 0 ; i < g.size()\
    \ ; i++)\n            res[g[i]]=a[i];\n        for (usize i = g.size() ; i < a.size()\
    \ ; i++)\n            res[i]=a[i];\n        return res;\n    }\n\nprivate:\n\n\
    \    Container m_perm, m_inv;\n\n};\n\n} // namespace zawa\n#line 8 \"Test/AtCoder/abc470_d.test.cpp\"\
    \n#include <iostream>\n#line 10 \"Test/AtCoder/abc470_d.test.cpp\"\nusing namespace\
    \ std;\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N,Q;\n    cin >> N >> Q;\n    vector<int> P(N);\n    for (int& p : P)\
    \ {\n        cin >> p;\n        p--;\n    }\n    zawa::SymmetricGroup sym{P};\n\
    \    while (Q--) {\n        int t;\n        cin >> t;\n        if (t == 1) {\n\
    \            int x,y;\n            cin >> x >> y;\n            sym.swap(--x,--y);\n\
    \        }\n        else if (t == 2)\n            sym.invert();\n        else\n\
    \            assert(0);\n    }\n    for (int i = 0 ; i < N ; i++)\n        cout\
    \ << sym[i]+1 << (i+1==N?'\\n':' ');\n#else\n    int a,b;\n    cin >> a >> b;\n\
    \    cout << a+b << '\\n';\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc470/tasks/abc470_d\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n/*\n * AtCoder Beginner\
    \ Contest 470 D - Inverse and Swap\n * https://atcoder.jp/contests/abc470/submissions/80553925\n\
    \ */\n#include \"../../Src/Algebra/Group/SymmetricGroup.hpp\"\n#include <iostream>\n\
    #include <vector>\nusing namespace std;\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n\
    \    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N,Q;\n    cin >> N >>\
    \ Q;\n    vector<int> P(N);\n    for (int& p : P) {\n        cin >> p;\n     \
    \   p--;\n    }\n    zawa::SymmetricGroup sym{P};\n    while (Q--) {\n       \
    \ int t;\n        cin >> t;\n        if (t == 1) {\n            int x,y;\n   \
    \         cin >> x >> y;\n            sym.swap(--x,--y);\n        }\n        else\
    \ if (t == 2)\n            sym.invert();\n        else\n            assert(0);\n\
    \    }\n    for (int i = 0 ; i < N ; i++)\n        cout << sym[i]+1 << (i+1==N?'\\\
    n':' ');\n#else\n    int a,b;\n    cin >> a >> b;\n    cout << a+b << '\\n';\n\
    #endif\n}\n"
  dependsOn:
  - Src/Algebra/Group/SymmetricGroup.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc470_d.test.cpp
  requiredBy: []
  timestamp: '2026-11-02 13:53:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc470_d.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc470_d.test.cpp
- /verify/Test/AtCoder/abc470_d.test.cpp.html
title: Test/AtCoder/abc470_d.test.cpp
---
