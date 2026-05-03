---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/CycleDetection.hpp
    title: "\u30B0\u30E9\u30D5\u306E\u30B5\u30A4\u30AF\u30EB\u691C\u51FA"
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
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection_undirected
    links:
    - https://judge.yosupo.jp/problem/cycle_detection_undirected
  bundledCode: "#line 1 \"Test/LC/cycle_detection_undirected.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/cycle_detection_undirected\"\n\n#line 2 \"\
    Src/Graph/CycleDetection.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include\
    \ <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 = std::int16_t;\n\
    using i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128 = __int128_t;\n\
    \nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\n} // namespace zawa\n\
    #line 4 \"Src/Graph/CycleDetection.hpp\"\n\n#include <algorithm>\n#include <concepts>\n\
    #include <iterator>\n#include <optional>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <std::integral T,std::integral U>\nstd::optional<std::pair<std::vector<T>,std::vector<U>>>\
    \ CycleDetection(const std::vector<std::vector<std::pair<T,U>>>& G) {\n    const\
    \ usize N = G.size();\n    std::vector<u8> col(N);\n    std::vector<T> vs;\n \
    \   std::vector<U> es;\n    auto dfs = [&](auto dfs,T v,U id) -> std::optional<T>\
    \ {\n        vs.push_back(v);\n        col[v] = 1;\n        for (auto [x,i] :\
    \ G[v])\n            if (i != id and col[x] < u8{2}) {\n                es.push_back(i);\n\
    \                if (col[x])\n                    return x;\n                else\
    \ if (auto ret = dfs(dfs,x,i) ; ret.has_value())\n                    return ret;\n\
    \                es.pop_back();\n            }\n        vs.pop_back(); \n    \
    \    col[v] = 2;\n        return std::nullopt;\n    };\n    for (usize i = 0 ;\
    \ i < N ; i++)\n        if (col[i] == 0) {\n            auto ret = dfs(dfs,i,static_cast<U>(-1));\n\
    \            if (ret.has_value()) {\n                auto it = std::ranges::find(vs,*ret);\n\
    \                auto d = std::distance(vs.begin(),it);\n                es.erase(es.begin(),es.begin()+d);\n\
    \                vs.erase(vs.begin(),vs.begin()+d);\n                return std::pair{std::move(vs),std::move(es)};\n\
    \            }\n        }\n    return std::nullopt;\n}\n\n// \u3053\u3063\u3061\
    \u306F\u591A\u91CD\u8FBA\u30C0\u30E1\ntemplate <std::integral T, bool directed>\n\
    std::optional<std::vector<T>> CycleDetection(const std::vector<std::vector<T>>&\
    \ G) {\n    const usize N = G.size();\n    std::vector<u8> col(N);\n    std::vector<T>\
    \ vs;\n    auto dfs = [&](auto dfs,T v,T p) -> std::optional<T> {\n        col[v]\
    \ = 1;\n        vs.push_back(v);\n        if constexpr (directed) {\n        \
    \    for (T x : G[v])\n                if (col[x] < u8{2}) {\n               \
    \     if (col[x])\n                        return x;\n                    else\
    \ if (auto ret = dfs(dfs,x,v) ; ret.has_value())\n                        return\
    \ ret;\n                }\n        }\n        else {\n            for (T x : G[v])\n\
    \                if (x != p) {\n                    if (col[x])\n            \
    \            return x;\n                    else if (auto ret = dfs(dfs,x,v) ;\
    \ ret.has_value())\n                        return ret;\n                }\n \
    \       }\n        vs.pop_back();\n        col[v] = 2;\n        return std::nullopt;\n\
    \    };\n    for (usize i = 0 ; i < N ; i++)\n        if (col[i] == 0) {\n   \
    \         auto ret = dfs(dfs,i,static_cast<T>(-1));\n            if (ret.has_value())\
    \ {\n                auto it = std::ranges::find(vs,*ret);\n                vs.erase(vs.begin(),it);\n\
    \                return vs;\n            }\n        }\n    return std::nullopt;\n\
    }\n\n} // namespace zawa\n#line 4 \"Test/LC/cycle_detection_undirected.test.cpp\"\
    \n\n#include <iostream>\n#line 7 \"Test/LC/cycle_detection_undirected.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n  \
    \  ios::sync_with_stdio(0);\n    int N,M;\n    cin >> N >> M;\n    vector<vector<pair<int,int>>>\
    \ G(N);\n    for (int i = 0 ; i < M ; i++) {\n        int u,v;\n        cin >>\
    \ u >> v;\n        G[u].push_back({v,i});\n        G[v].push_back({u,i});\n  \
    \  }\n    auto ret = zawa::CycleDetection(G);\n    if (ret) {\n        auto [vs,es]\
    \ = std::move(*ret);\n        cout << ssize(vs) << '\\n';\n        for (int i\
    \ = 0 ; i < ssize(vs) ; i++)\n            cout << vs[i] << (i + 1 == ssize(vs)\
    \ ? '\\n' : ' ');\n        for (int i = 0 ; i < ssize(es) ; i++)\n           \
    \ cout << es[i] << (i + 1 == ssize(es) ? '\\n' : ' ');\n    }\n    else\n    \
    \    cout << -1 << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection_undirected\"\
    \n\n#include \"../../Src/Graph/CycleDetection.hpp\"\n\n#include <iostream>\n#include\
    \ <vector>\nusing namespace std;\n\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n    int N,M;\n    cin >> N >> M;\n    vector<vector<pair<int,int>>>\
    \ G(N);\n    for (int i = 0 ; i < M ; i++) {\n        int u,v;\n        cin >>\
    \ u >> v;\n        G[u].push_back({v,i});\n        G[v].push_back({u,i});\n  \
    \  }\n    auto ret = zawa::CycleDetection(G);\n    if (ret) {\n        auto [vs,es]\
    \ = std::move(*ret);\n        cout << ssize(vs) << '\\n';\n        for (int i\
    \ = 0 ; i < ssize(vs) ; i++)\n            cout << vs[i] << (i + 1 == ssize(vs)\
    \ ? '\\n' : ' ');\n        for (int i = 0 ; i < ssize(es) ; i++)\n           \
    \ cout << es[i] << (i + 1 == ssize(es) ? '\\n' : ' ');\n    }\n    else\n    \
    \    cout << -1 << '\\n';\n}\n"
  dependsOn:
  - Src/Graph/CycleDetection.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/LC/cycle_detection_undirected.test.cpp
  requiredBy: []
  timestamp: '2026-05-03 11:27:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/cycle_detection_undirected.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/cycle_detection_undirected.test.cpp
- /verify/Test/LC/cycle_detection_undirected.test.cpp.html
title: Test/LC/cycle_detection_undirected.test.cpp
---
