---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Components/ConnectedComponents.hpp
    title: "\u7121\u5411\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Components/Lowlink.hpp
    title: "Lowlink (\u6A4B\u30FB\u95A2\u7BC0\u70B9)"
  - icon: ':heavy_check_mark:'
    path: Src/Number/ModInt.hpp
    title: Src/Number/ModInt.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc334/tasks/abc334_g
    links:
    - https://atcoder.jp/contests/abc334/tasks/abc334_g
  bundledCode: "#line 1 \"Test/AtCoder/abc334_g.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc334/tasks/abc334_g\"\
    \n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Graph/Components/ConnectedComponents.hpp\"\
    \n\n#line 4 \"Src/Graph/Components/ConnectedComponents.hpp\"\n\n#include <limits>\n\
    #include <vector>\n#include <utility>\n#include <stack>\n#include <algorithm>\n\
    #include <cassert>\n\nnamespace zawa {\n\nclass ConnectedComponents {\npublic:\n\
    \    struct Edge {\n    private:\n        u32 u_, v_, id_;\n    public:\n    \
    \    Edge(u32 u, u32 v, u32 id) : u_{ u }, v_{ v }, id_{ id } {}\n\n        inline\
    \ u32 u() const noexcept {\n            return u_;\n        }\n        inline\
    \ u32 v() const noexcept {\n            return v_;\n        }\n        inline\
    \ u32 id() const noexcept {\n            return id_;\n        }\n    };\n\nprivate:\n\
    \    class Component {\n    private:\n        std::vector<u32> vs_, es_;\n   \
    \ public:\n        Component() = default;\n        Component(const std::vector<u32>&\
    \ vs, const std::vector<u32>& es) : vs_{ vs }, es_{ es } {\n            vs_.shrink_to_fit();\n\
    \            es_.shrink_to_fit();\n        }\n        \n        inline usize n()\
    \ const noexcept {\n            return vs_.size();\n        }\n        inline\
    \ usize m() const noexcept {\n            return es_.size();\n        }\n    \
    \    const std::vector<u32>& vs() const noexcept {\n            return vs_;\n\
    \        }\n        const std::vector<u32>& es() const noexcept {\n          \
    \  return es_;\n        }\n        bool hasCycle() const {\n            return\
    \ not (n() == m() + 1);\n        }\n    };\n\n    constexpr static u32 INVALID_{\
    \ std::numeric_limits<u32>::max() };\n\n    std::vector<std::vector<u32>> graph_;\n\
    \    std::vector<std::pair<u32, u32>> edges_;\n\n    std::vector<u32> indexV_,\
    \ indexE_;\n    std::vector<Component> components_;\n\n    bool isBuilt;\n\n \
    \   void dfs(u32 s) {\n        indexV_[s] = components_.size();\n        std::stack<u32>\
    \ stk{ { s } };\n        while (stk.size()) {\n            u32 v{ stk.top() };\n\
    \            stk.pop();\n            for (auto x : graph_[v]) {\n            \
    \    if (indexV_[x] == INVALID_) {\n                    indexV_[x] = components_.size();\n\
    \                    stk.push(x);\n                }\n            }\n        }\n\
    \    }\n\n    void buildComponents() {\n        std::vector<std::vector<u32>>\
    \ vs(components_.size()), es(components_.size());\n        for (u32 v{} ; v <\
    \ n() ; v++) {\n            vs[indexV_[v]].emplace_back(v);\n        }\n     \
    \   for (u32 e{} ; e < m() ; e++) {\n            es[indexE_[e]].emplace_back(e);\n\
    \        }\n        for (u32 i{} ; i < components_.size() ; i++) {\n         \
    \   components_[i] = Component(vs[i], es[i]);\n        }\n        components_.shrink_to_fit();\n\
    \    }\n\npublic:\n    ConnectedComponents() = default;\n\n    ConnectedComponents(usize\
    \ n) \n        : graph_(n), edges_{}, indexV_(n, INVALID_), indexE_{}, components_{},\
    \ isBuilt{} {\n        graph_.shrink_to_fit();\n    }\n    \n    void addEdge(u32\
    \ u, u32 v) {\n        assert(not isBuilt);\n        graph_[u].emplace_back(v);\n\
    \        graph_[v].emplace_back(u);\n        edges_.emplace_back(u, v);\n    }\n\
    \n    inline usize n() const noexcept {\n        return graph_.size();\n    }\n\
    \n    inline usize m() const noexcept {\n        return edges_.size();\n    }\n\
    \n    Edge edge(u32 e) const {\n        assert(e < m());\n        return Edge{\
    \ edges_[e].first, edges_[e].second, e };\n    }\n\n    void build() {\n     \
    \   assert(not isBuilt);\n        edges_.shrink_to_fit();\n        indexV_.shrink_to_fit();\n\
    \        for (u32 v{} ; v < n() ; v++) {\n            if (indexV_[v] == INVALID_)\
    \ {\n                dfs(v);\n                components_.emplace_back();\n  \
    \          }\n        }\n        indexE_.resize(m());\n        indexE_.shrink_to_fit();\n\
    \        for (u32 e{} ; e < m() ; e++) {\n            indexE_[e] = indexV_[edges_[e].first];\n\
    \        }\n        buildComponents();\n        isBuilt = true;\n    }\n\n   \
    \ inline u32 operator[](const u32 v) const noexcept {\n        assert(isBuilt);\n\
    \        assert(v < n());\n        return indexV_[v];\n    }\n\n    inline u32\
    \ indexV(u32 v) const noexcept {\n        assert(isBuilt);\n        assert(v <\
    \ n());\n        return indexV_[v];\n    }\n\n    inline u32 indexE(u32 e) const\
    \ noexcept {\n        assert(isBuilt);\n        assert(e < m());\n        return\
    \ indexE_[e];\n    }\n\n    inline bool same(u32 u, u32 v) const noexcept {\n\
    \        assert(isBuilt);\n        assert(u < n());\n        assert(v < n());\n\
    \        return indexV_[u] == indexV_[v];\n    }\n\n    inline usize size() const\
    \ noexcept {\n        assert(isBuilt);\n        return components_.size();\n \
    \   }\n\n    inline usize n(u32 c) const noexcept {\n        assert(isBuilt);\n\
    \        assert(c < size());\n        return components_[c].n();\n    }\n\n  \
    \  inline const std::vector<u32>& vs(u32 c) const noexcept {\n        assert(isBuilt);\n\
    \        assert(c < size());\n        return components_[c].vs();\n    }\n\n \
    \   inline usize m(u32 c) const noexcept {\n        assert(isBuilt);\n       \
    \ assert(c < size());\n        return components_[c].m();\n    }\n\n    inline\
    \ const std::vector<u32>& es(u32 c) const noexcept {\n        assert(isBuilt);\n\
    \        assert(c < size());\n        return components_[c].es();\n    }\n\n \
    \   inline bool hasCycle(u32 c) const {\n        assert(isBuilt);\n        assert(c\
    \ < size());\n        return components_[c].hasCycle();\n    }\n\n};\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Graph/Components/Lowlink.hpp\"\n\n#line 4 \"Src/Graph/Components/Lowlink.hpp\"\
    \n\n#line 9 \"Src/Graph/Components/Lowlink.hpp\"\n\nnamespace zawa {\n\nclass\
    \ Lowlink {\nprivate:\n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n\
    \    usize n_{}, m_{};\n    std::vector<std::vector<std::pair<u32, u32>>> g_;\n\
    \    std::vector<std::pair<u32, u32>> e_;\n    std::vector<u32> in_, low_;\n \
    \   std::vector<u32> articulation_;\n    std::vector<bool> bridge_;\n\n    void\
    \ dfs(u32 v, u32 p, u32& t) {\n        low_[v] = in_[v] = t++;\n        u32 deg{};\
    \ \n        for (const auto& [x, i] : g_[v]) {\n            if (in_[x] == INVALID)\
    \ {\n                deg++;\n                dfs(x, v, t);\n                low_[v]\
    \ = std::min(low_[v], low_[x]);\n                if (p != INVALID and low_[x]\
    \ >= in_[v]) {\n                    articulation_[v]++;\n                }\n \
    \               if (low_[x] > in_[v]) {\n                    bridge_[i] = true;\n\
    \                }\n            }\n            else if (x != p) {\n          \
    \      low_[v] = std::min(low_[v], in_[x]);\n            }\n        }\n      \
    \  if (p == INVALID) {\n            articulation_[v] = deg;\n        }\n    }\n\
    \npublic:\n    constexpr usize size() const noexcept {\n        return n_;\n \
    \   }\n    constexpr usize edgeSize() const noexcept {\n        return m_;\n \
    \   }\n\n    Lowlink() = default;\n    Lowlink(usize n) \n        : n_{n}, m_{},\
    \ g_(n), in_(n, INVALID), low_(n), articulation_(n, u32{1}), bridge_{} {\n   \
    \     g_.shrink_to_fit();\n        in_.shrink_to_fit();\n        low_.shrink_to_fit();\n\
    \        articulation_.shrink_to_fit();\n    }\n    \n    usize addEdge(u32 u,\
    \ u32 v) {\n        usize res{m_++};\n        e_.emplace_back(u, v);\n       \
    \ g_[u].emplace_back(v, res);\n        g_[v].emplace_back(u, res);\n        return\
    \ res;\n    }\n\n    const std::vector<std::pair<u32, u32>>& operator[](u32 v)\
    \ const noexcept {\n        assert(v < size());\n        return g_[v];\n    }\n\
    \    const std::pair<u32, u32>& edge(u32 i) const noexcept {\n        assert(i\
    \ < edgeSize());\n        return e_[i];\n    }\n\n    void build() {\n       \
    \ bridge_.resize(edgeSize());\n        u32 t{};\n        for (u32 v{} ; v < size()\
    \ ; v++) if (in_[v] == INVALID) {\n            dfs(v, INVALID, t);\n        }\n\
    \    }\n\n    bool articular(u32 v) const noexcept {\n        assert(v < size());\n\
    \        return articulation_[v] > 1u;\n    }\n    u32 cut(u32 v) const noexcept\
    \ {\n        assert(v < size());\n        return articulation_[v];\n    }\n  \
    \  bool bridge(u32 i) const noexcept {\n        assert(i < edgeSize());\n    \
    \    return bridge_[i];\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/Number/ModInt.hpp\"\
    \n\n#line 4 \"Src/Number/ModInt.hpp\"\n\n#include <type_traits>\n#line 9 \"Src/Number/ModInt.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T, T mod>\nclass StaticModInt {\nprivate:\n\
    \    using mint = StaticModInt;\n\n    T v_{};\n\n    static constexpr void templateTypeAssert()\
    \ {\n        static_assert(std::is_integral_v<T>, \"ModInt template argument must\
    \ be integral\");\n        static_assert(mod > 0, \"mod must be positive\");\n\
    \    }\n\n    i64 extendGCD(i64 a, i64 b, i64& x, i64& y) const {\n       i64\
    \ d{a};\n       if (b) {\n           d = extendGCD(b, a % b, y, x);\n        \
    \   y -= (a / b) * x;\n       }\n       else {\n           x = 1;\n          \
    \ y = 0;\n       }\n       return d;\n    }\n\npublic:\n\n    constexpr StaticModInt()\
    \ {\n        templateTypeAssert();\n    }\n    template <class ArgType>\n    constexpr\
    \ StaticModInt(ArgType v) : v_{ static_cast<T>(((v % mod) + mod) % mod) } {\n\
    \        templateTypeAssert();\n        static_assert(std::is_integral_v<ArgType>,\
    \ \"ModInt constructor Argument Must Be Integral\");\n    }\n\n    friend std::istream&\
    \ operator>>(std::istream& is, mint& value) {\n        is >> value.v_;\n     \
    \   return is;\n    }\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ mint& value) {\n        os << value.v_;\n        return os;\n    }\n\n    T\
    \ v() const {\n        return v_;\n    }\n\n    bool operator==(const mint& rhs)\
    \ const {\n        return v_ == rhs.v_;\n    }\n\n    mint operator+() const {\n\
    \        return *this;\n    }\n    mint& operator+=(const mint& rhs) {\n     \
    \   v_ = (v_ < mod - rhs.v_ ? v_ + rhs.v_ : v_ + rhs.v_ - mod);\n        return\
    \ *this;\n    }\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n\
    \        return mint{lhs} += rhs;\n    }\n    mint& operator++() {\n        v_\
    \ = (v_ + 1 == mod ? 0 : v_ + 1);\n        return *this;\n    }\n    mint operator++(int)\
    \ {\n        mint res{*this};\n        ++*this;\n        return res;\n    }\n\n\
    \    mint operator-() const {\n        return mod - v_;\n    }\n    mint& operator-=(const\
    \ mint& rhs) {\n        v_ = (v_ >= rhs.v_ ? v_ - rhs.v_ : v_ + (mod - rhs.v_));\n\
    \        return *this;\n    }\n    friend mint operator-(const mint& lhs, const\
    \ mint& rhs) {\n        return mint{lhs} -= rhs;\n    }\n    mint& operator--()\
    \ {\n        v_ = (v_ ? v_ - 1 : mod - 1);\n        return *this;\n    }\n   \
    \ mint operator--(int) {\n        mint res{*this};\n        --*this;\n       \
    \ return res;\n    }\n\n    mint& operator*=(const mint& rhs) {\n        u64 mult{\
    \ static_cast<u64>(v_) * static_cast<u64>(rhs.v_) };\n        v_ = static_cast<T>(mult\
    \ % mod);\n        return *this;\n    }\n    friend mint operator*(const mint&\
    \ lhs, const mint& rhs) {\n        return mint{lhs} *= rhs;\n    }\n\n    mint\
    \ inverse() const {\n        i64 res{}, hoge{};\n        assert(extendGCD(static_cast<i64>(v_),\
    \ static_cast<i64>(mod), res, hoge) == 1);\n        return mint{res};\n    }\n\
    \    mint& operator/=(const mint& rhs) {\n        return *this *= rhs.inverse();\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint{lhs} /= rhs;\n    }\n\n    mint pow(u64 k) const {\n        mint\
    \ res{1}, base{k};\n        while (k) {\n            if (k & 1) res *= base;\n\
    \            base *= base; \n            k >>= 1;\n        }\n        return res;\n\
    \    }\n};\n\n} // namespace zawa\n#line 7 \"Test/AtCoder/abc334_g.test.cpp\"\n\
    \n#line 9 \"Test/AtCoder/abc334_g.test.cpp\"\n\nusing namespace zawa;\nusing mint\
    \ = StaticModInt<u32, 998244353>;\n\nint main() {\n    SetFastIO();\n    int h,\
    \ w; std::cin >> h >> w;\n    std::vector s(h, std::string{});\n    for (auto&\
    \ c : s) std::cin >> c;\n    auto f{[w](int x, int y) -> int {\n        return\
    \ x * w + y;\n    }};\n    auto in{[&](int x, int y) -> bool {\n        return\
    \ 0 <= x and x < h and 0 <= y and y < w and s[x][y] == '#';\n    }};\n    const\
    \ int dx[4]{ 1, 0, -1, 0 };\n    const int dy[4]{ 0, 1, 0, -1 };\n    ConnectedComponents\
    \ cc(h * w);\n    Lowlink g(h * w);\n    int red{}, green{};\n    for (int x{}\
    \ ; x < h ; x++) {\n        for (int y{} ; y < w ; y++) {\n            if (!in(x,\
    \ y)) {\n                red++;\n                continue;\n            }\n  \
    \          else {\n                green++;\n            }\n            for (int\
    \ d{} ; d < 4 ; d++) {\n                int nx{x + dx[d]}, ny{y + dy[d]};\n  \
    \              if (!in(nx, ny)) continue;\n                if (f(x, y) > f(nx,\
    \ ny)) continue;\n                cc.addEdge(f(x, y), f(nx, ny));\n          \
    \      g.addEdge(f(x, y), f(nx, ny));\n            }\n        }\n    } \n    cc.build();\n\
    \    g.build();\n    mint res{};\n    for (int x{} ; x < h ; x++) {\n        for\
    \ (int y{} ; y < w ; y++) {\n            if (!in(x, y)) continue;\n          \
    \  int num{(int)cc.size() - red + (int)g.cut(f(x, y)) - 1};\n            int den{green};\n\
    \            res += mint{num} / mint{den};\n        }\n    }\n    std::cout <<\
    \ res << '\\n';\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc334/tasks/abc334_g\"\n\n\
    #include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Graph/Components/ConnectedComponents.hpp\"\
    \n#include \"../../Src/Graph/Components/Lowlink.hpp\"\n#include \"../../Src/Number/ModInt.hpp\"\
    \n\n#include <iostream>\n\nusing namespace zawa;\nusing mint = StaticModInt<u32,\
    \ 998244353>;\n\nint main() {\n    SetFastIO();\n    int h, w; std::cin >> h >>\
    \ w;\n    std::vector s(h, std::string{});\n    for (auto& c : s) std::cin >>\
    \ c;\n    auto f{[w](int x, int y) -> int {\n        return x * w + y;\n    }};\n\
    \    auto in{[&](int x, int y) -> bool {\n        return 0 <= x and x < h and\
    \ 0 <= y and y < w and s[x][y] == '#';\n    }};\n    const int dx[4]{ 1, 0, -1,\
    \ 0 };\n    const int dy[4]{ 0, 1, 0, -1 };\n    ConnectedComponents cc(h * w);\n\
    \    Lowlink g(h * w);\n    int red{}, green{};\n    for (int x{} ; x < h ; x++)\
    \ {\n        for (int y{} ; y < w ; y++) {\n            if (!in(x, y)) {\n   \
    \             red++;\n                continue;\n            }\n            else\
    \ {\n                green++;\n            }\n            for (int d{} ; d < 4\
    \ ; d++) {\n                int nx{x + dx[d]}, ny{y + dy[d]};\n              \
    \  if (!in(nx, ny)) continue;\n                if (f(x, y) > f(nx, ny)) continue;\n\
    \                cc.addEdge(f(x, y), f(nx, ny));\n                g.addEdge(f(x,\
    \ y), f(nx, ny));\n            }\n        }\n    } \n    cc.build();\n    g.build();\n\
    \    mint res{};\n    for (int x{} ; x < h ; x++) {\n        for (int y{} ; y\
    \ < w ; y++) {\n            if (!in(x, y)) continue;\n            int num{(int)cc.size()\
    \ - red + (int)g.cut(f(x, y)) - 1};\n            int den{green};\n           \
    \ res += mint{num} / mint{den};\n        }\n    }\n    std::cout << res << '\\\
    n';\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Components/ConnectedComponents.hpp
  - Src/Graph/Components/Lowlink.hpp
  - Src/Number/ModInt.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc334_g.test.cpp
  requiredBy: []
  timestamp: '2024-02-10 12:22:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc334_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc334_g.test.cpp
- /verify/Test/AtCoder/abc334_g.test.cpp.html
title: Test/AtCoder/abc334_g.test.cpp
---
