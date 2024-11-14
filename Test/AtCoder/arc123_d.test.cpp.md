---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/SlopeTrick.hpp
    title: Slope Trick
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc123/tasks/arc123_d
    links:
    - https://atcoder.jp/contests/arc123/tasks/arc123_d
  bundledCode: "#line 1 \"Test/AtCoder/arc123_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/arc123/tasks/arc123_d\"\
    \n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Utility/SlopeTrick.hpp\"\n\n#include <queue>\n\
    #include <optional>\n#include <type_traits>\n#include <vector>\n\nnamespace zawa\
    \ {\n\n    // domain, codomain\n    template <class D, class C>\n    class SlopeTrick\
    \ {\n        static_assert(std::is_integral_v<D>, \"zawa::SlopeTrick::D must be\
    \ integral\");\n        static_assert(std::is_integral_v<C>, \"zawa::SlopeTrick::C\
    \ must be integral\");\n    public:\n        using SizeType = usize;\n       \
    \ SlopeTrick() = default;\n        SlopeTrick(const SlopeTrick& st) : L_{st.L_},\
    \ R_{st.R_}, min_{st.min_} {}\n        SlopeTrick(SlopeTrick&& st) : L_{std::move(st.L_)},\
    \ R_{std::move(st.R_)}, min_{st.min_} {}\n        SlopeTrick& operator=(const\
    \ SlopeTrick& st) {\n            L_ = st.L_;\n            R_ = st.R_;\n      \
    \      min_ = st.min_;\n            return *this;\n        }\n        SlopeTrick&\
    \ operator=(SlopeTrick&& st) {\n            L_ = std::move(st.L_);\n         \
    \   R_ = std::move(st.R_);\n            min_ = st.min_;\n            return *this;\n\
    \        }\n        // get min\n        C min() const {\n            return min_;\n\
    \        }\n        // get [l0, r0]\n        std::pair<std::optional<D>, std::optional<D>>\
    \ argmin() const {\n            return {\n                L_.empty() ? std::nullopt\
    \ : std::optional<D>{lvalue(L_.top())},\n                R_.empty() ? std::nullopt\
    \ : std::optional<D>{rvalue(R_.top())}\n            };\n        }\n        //\
    \ add y = c\n        void addConstant(C c) {\n            min_ += c;\n       \
    \ }\n        // add y = max(0, x - a)\n        void addMax0XA(D a) {\n       \
    \     if (L_.empty() or lvalue(L_.top()) <= a) {\n                pushR(a);\n\
    \            }\n            else {\n                pushR(lvalue(L_.top()));\n\
    \                min_ += lvalue(L_.top()) - a;\n                L_.pop();\n  \
    \              pushL(a);\n            }\n        }\n        // add y = max(0,\
    \ a - x)\n        void addMax0AX(D a) {\n            if (R_.empty() or a <= rvalue(R_.top()))\
    \ {\n                pushL(a);\n            }\n            else {\n          \
    \      pushL(rvalue(R_.top()));\n                min_ += a - rvalue(R_.top());\n\
    \                R_.pop();\n                pushR(a);\n            }\n       \
    \ }\n        // add y = |x - a|\n        void addAbsoluteXA(D a) {\n         \
    \   addMax0XA(a);\n            addMax0AX(a);\n        }\n        // \u524D\u304B\
    \u3089\u7D2F\u7A4Dmin\u3092\u3068\u3063\u305F\u95A2\u6570\u306B\u7F6E\u304D\u63DB\
    \u3048\u308B\n        void prefixMin() {\n            R_ = std::move(decltype(R_){});\n\
    \            addR_ = D{0};\n        }\n        // \u5F8C\u308D\u304B\u3089\u7D2F\
    \u7A4Dmin\u3092\u3068\u3063\u305F\u95A2\u6570\u306B\u7F6E\u304D\u63DB\u3048\u308B\
    \n        void suffixMin() {\n            L_ = std::move(decltype(L_){});\n  \
    \          addL_ = D{0};\n        }\n        // g(x) = min f(k) (x - a <= k <=\
    \ x - b)\u306B\u7F6E\u304D\u63DB\u3048\u308B\n        void slidingWindowMin(D\
    \ a, D b) {\n            addR_ += b;\n            addL_ += a;\n        }\n   \
    \     // x\u8EF8\u65B9\u5411\u306Bc\u5E73\u884C\u79FB\u52D5\u3059\u308B\n    \
    \    void translation(D c) {\n            slidingWindowMin(c, c);\n        }\n\
    \        // \u50BE\u304D\u304Ck -> k + 1 (x < 0)\u3068\u306A\u308B\u70B9\u3092\
    \u5217\u6319\u3059\u308B\n        std::vector<D> enumerateL() const {\n      \
    \      decltype(L_) L{L_};\n            std::vector<D> res;\n            while\
    \ (L.size()) {\n                res.emplace_back(lvalue(L.top()));\n         \
    \       L.pop();\n            }\n            return res;\n        }\n        //\
    \ \u50BE\u304D\u304Ck -> k + 1 (x >= 0)\u3068\u306A\u308B\u70B9\u3092\u5217\u6319\
    \u3059\u308B\n        std::vector<D> enumerateR() const {\n            decltype(R_)\
    \ R{R_};\n            std::vector<D> res;\n            while (R.size()) {\n  \
    \              res.emplace_back(rvalue(R.top()));\n                R.pop();\n\
    \            }\n            return res;\n        }\n        // get f(x)\n    \
    \    // \u6CE8\u610F: O(N\\log N)\u304B\u304B\u308B\n        C f(D x) const {\n\
    \            C res{min_};\n            for (auto l : enumerateL()) {\n       \
    \         res += std::max(D{0}, l - x);\n            }\n            for (auto\
    \ r : enumerateR()) {\n                res += std::max(D{0}, x - r);\n       \
    \     }\n            return res;\n        }\n        void clear() {\n        \
    \    L_ = decltype(L_){};\n            R_ = decltype(R_){};\n            min_\
    \ = D{0};\n        }\n        SlopeTrick& operator+=(const SlopeTrick& st) {\n\
    \            min_ += st.min();\n            for (auto l : st.enumerateL()) {\n\
    \                addMax0AX(l);\n            }\n            for (auto r : st.enumerateR())\
    \ {\n                addMax0XA(r);\n            }\n            return *this;\n\
    \        }\n        inline SizeType sizeL() const {\n            return L_.size();\n\
    \        }\n        inline SizeType sizeR() const {\n            return R_.size();\n\
    \        }\n        inline SizeType size() const {\n            return sizeL()\
    \ + sizeR();\n        }\n    private:\n        std::priority_queue<D> L_{};\n\
    \        std::priority_queue<D, std::vector<D>, std::greater<D>> R_{};\n     \
    \   D addL_{}, addR_{};\n        C min_{};\n\n        inline D lvalue(D l) const\
    \ noexcept {\n            return l + addL_;\n        }\n        inline D rvalue(D\
    \ r) const noexcept {\n            return r + addR_;\n        }\n        inline\
    \ void pushL(D v) noexcept {\n            L_.push(v - addL_);\n        }\n   \
    \     inline void pushR(D v) noexcept {\n            R_.push(v - addR_);\n   \
    \     }\n    };\n\n} // namespace zawa\n#line 5 \"Test/AtCoder/arc123_d.test.cpp\"\
    \n\n#line 8 \"Test/AtCoder/arc123_d.test.cpp\"\n\nusing namespace zawa;\n\nint\
    \ main() {\n    SetFastIO();\n    int N;\n    std::cin >> N;\n    std::vector<int>\
    \ A(N);\n    for (auto& a : A) std::cin >> a;\n    SlopeTrick<long long, long\
    \ long> dp;\n    dp.addAbsoluteXA(0);\n    dp.addAbsoluteXA(A[0]);\n    for (int\
    \ i{1} ; i < N ; i++) {\n        dp.translation(std::min(A[i] - A[i - 1], 0));\n\
    \        dp.addAbsoluteXA(0);\n        dp.addAbsoluteXA(A[i]);\n    }\n    std::cout\
    \ << dp.min() << '\\n';\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc123/tasks/arc123_d\"\n\n\
    #include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Utility/SlopeTrick.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nusing namespace zawa;\n\nint main()\
    \ {\n    SetFastIO();\n    int N;\n    std::cin >> N;\n    std::vector<int> A(N);\n\
    \    for (auto& a : A) std::cin >> a;\n    SlopeTrick<long long, long long> dp;\n\
    \    dp.addAbsoluteXA(0);\n    dp.addAbsoluteXA(A[0]);\n    for (int i{1} ; i\
    \ < N ; i++) {\n        dp.translation(std::min(A[i] - A[i - 1], 0));\n      \
    \  dp.addAbsoluteXA(0);\n        dp.addAbsoluteXA(A[i]);\n    }\n    std::cout\
    \ << dp.min() << '\\n';\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Utility/SlopeTrick.hpp
  isVerificationFile: true
  path: Test/AtCoder/arc123_d.test.cpp
  requiredBy: []
  timestamp: '2024-05-02 00:23:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/arc123_d.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/arc123_d.test.cpp
- /verify/Test/AtCoder/arc123_d.test.cpp.html
title: Test/AtCoder/arc123_d.test.cpp
---