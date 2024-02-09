---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MinMonoid.hpp
    title: "min\u6F14\u7B97\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SparseTable/SparseTable.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Test/LC/staticrmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#line 2 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n#include <ostream>\n\nnamespace zawa\
    \ {\n\ntemplate <class Structure>\nclass SparseTable {\nprivate:\n    using Value\
    \ = typename Structure::Element;\n    std::vector<u32> L;\n    std::vector<std::vector<Value>>\
    \ dat;\npublic:\n\n    SparseTable() : L{}, dat{} {}\n    SparseTable(const std::vector<Value>&\
    \ a) : L(a.size() + 1), dat{} {\n        for (u32 i{1} ; i < L.size() ; i++) {\n\
    \            L[i] = L[i - 1] + (i >> (L[i - 1] + 1));\n        }\n        dat.resize(L.back()\
    \ + 1);\n        dat[0] = a;\n        for (u32 i{1}, len{2} ; i < dat.size() ;\
    \ i++, len <<= 1) {\n            dat[i] = dat[i - 1];\n            for (u32 j{}\
    \ ; j + len - 1 < dat[i].size() ; j++) {\n                dat[i][j] = Structure::operation(dat[i\
    \ - 1][j], dat[i - 1][j + (len >> 1)]);\n            }\n        }\n    }\n\n \
    \   Value product(u32 l, u32 r) const {\n        assert(l <= r);\n        assert(l\
    \ < dat[0].size());\n        assert(r <= dat[0].size());\n        u32 now{L[r\
    \ - l]};\n        return Structure::operation(dat[now][l], dat[now][r - (1 <<\
    \ now)]);\n    }\n\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ SparseTable<Structure>& spt) {\n        for (u32 i{}, len{1} ; i < spt.dat.size()\
    \ ; i++, len <<= 1) {\n            os << \"length = \" << len << '\\n';\n    \
    \        for (u32 j{} ; j + len - 1 < spt.dat[i].size() ; j++) {\n           \
    \     os << spt.dat[i][j] << (j + len == spt.dat[i].size() ? '\\n' : ' ');\n \
    \           }\n        }\n        return os;\n    }\n};\n\n} // namespace zawa\n\
    #line 2 \"Src/Algebra/Monoid/MinMonoid.hpp\"\n\n#include <algorithm>\n#include\
    \ <optional>\n\nnamespace zawa {\n\ntemplate <class T>\nclass MinMonoid {\npublic:\n\
    \    using Element = std::optional<T>;\n    static constexpr Element identity()\
    \ noexcept {\n        return std::nullopt;\n    }\n    static constexpr Element\
    \ operation(const Element& l, const Element& r) noexcept {\n        if (l and\
    \ r) {\n            return std::min(l, r);\n        }\n        else if (l) {\n\
    \            return l;\n        }\n        else if (r) {\n            return r;\n\
    \        }\n        else {\n            return std::nullopt;\n        }\n    }\n\
    };\n\n} // namespace zawa\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 4 \"\
    Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n#include <iomanip>\n\nnamespace\
    \ zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 6 \"Test/LC/staticrmq.test.cpp\"\n\n#line 9 \"\
    Test/LC/staticrmq.test.cpp\"\n\nint main() {\n    using namespace zawa;\n    SetFastIO();\n\
    \    using M = MinMonoid<int>;\n    using MD = M::Element;\n    int n, q; std::cin\
    \ >> n >> q;\n    std::vector<MD> a(n);\n    for (auto& x : a) {\n        int\
    \ v; std::cin >> v;\n        x = v;\n    }\n    SparseTable<M> spt(a);\n    for\
    \ (int _{} ; _ < q ; _++) {\n        int l, r; std::cin >> l >> r;\n        MD\
    \ ans{spt.product(l, r)};\n        std::cout << ans.value() << '\\n';\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../Src/DataStructure/SparseTable/SparseTable.hpp\"\n#include \"../../Src/Algebra/Monoid/MinMonoid.hpp\"\
    \n#include \"../../Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n#include\
    \ <vector>\n\nint main() {\n    using namespace zawa;\n    SetFastIO();\n    using\
    \ M = MinMonoid<int>;\n    using MD = M::Element;\n    int n, q; std::cin >> n\
    \ >> q;\n    std::vector<MD> a(n);\n    for (auto& x : a) {\n        int v; std::cin\
    \ >> v;\n        x = v;\n    }\n    SparseTable<M> spt(a);\n    for (int _{} ;\
    \ _ < q ; _++) {\n        int l, r; std::cin >> l >> r;\n        MD ans{spt.product(l,\
    \ r)};\n        std::cout << ans.value() << '\\n';\n    }\n}\n"
  dependsOn:
  - Src/DataStructure/SparseTable/SparseTable.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MinMonoid.hpp
  - Src/Template/IOSetting.hpp
  isVerificationFile: true
  path: Test/LC/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2024-02-09 19:34:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/staticrmq.test.cpp
- /verify/Test/LC/staticrmq.test.cpp.html
title: Test/LC/staticrmq.test.cpp
---
