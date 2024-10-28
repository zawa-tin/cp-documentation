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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc334/tasks/abc334_g\"\n\n\
    #include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Graph/Components/ConnectedComponents.hpp\"\
    \n#include \"../../Src/Graph/Components/Lowlink.hpp\"\n#include \"atcoder/modint\"\
    \n\n#include <iostream>\n\nusing namespace zawa;\nusing mint = atcoder::modint998244353;\n\
    \nint main() {\n    SetFastIO();\n    int h, w; std::cin >> h >> w;\n    std::vector\
    \ s(h, std::string{});\n    for (auto& c : s) std::cin >> c;\n    auto f{[w](int\
    \ x, int y) -> int {\n        return x * w + y;\n    }};\n    auto in{[&](int\
    \ x, int y) -> bool {\n        return 0 <= x and x < h and 0 <= y and y < w and\
    \ s[x][y] == '#';\n    }};\n    const int dx[4]{ 1, 0, -1, 0 };\n    const int\
    \ dy[4]{ 0, 1, 0, -1 };\n    ConnectedComponents cc(h * w);\n    Lowlink g(h *\
    \ w);\n    int red{}, green{};\n    for (int x{} ; x < h ; x++) {\n        for\
    \ (int y{} ; y < w ; y++) {\n            if (!in(x, y)) {\n                red++;\n\
    \                continue;\n            }\n            else {\n              \
    \  green++;\n            }\n            for (int d{} ; d < 4 ; d++) {\n      \
    \          int nx{x + dx[d]}, ny{y + dy[d]};\n                if (!in(nx, ny))\
    \ continue;\n                if (f(x, y) > f(nx, ny)) continue;\n            \
    \    cc.addEdge(f(x, y), f(nx, ny));\n                g.addEdge(f(x, y), f(nx,\
    \ ny));\n            }\n        }\n    } \n    cc.build();\n    auto info{g.build()};\n\
    \    mint res{};\n    for (int x{} ; x < h ; x++) {\n        for (int y{} ; y\
    \ < w ; y++) {\n            if (!in(x, y)) continue;\n            int num{(int)cc.size()\
    \ - red + (int)info.cut(f(x, y)) - 1};\n            int den{green};\n        \
    \    res += mint{num} / mint{den};\n        }\n    }\n    std::cout << res.val()\
    \ << '\\n';\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Components/ConnectedComponents.hpp
  - Src/Graph/Components/Lowlink.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc334_g.test.cpp
  requiredBy: []
  timestamp: '2024-06-30 15:57:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc334_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc334_g.test.cpp
- /verify/Test/AtCoder/abc334_g.test.cpp.html
title: Test/AtCoder/abc334_g.test.cpp
---
