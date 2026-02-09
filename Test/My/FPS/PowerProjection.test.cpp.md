---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPS.hpp
    title: Src/FPS/FPS.hpp
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPSNTTFriendly.hpp
    title: Src/FPS/FPSNTTFriendly.hpp
  - icon: ':heavy_check_mark:'
    path: Src/FPS/PowerProjection.hpp
    title: FPS Power Projection
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../Src/FPS/FPSNTTFriendly.hpp\"\n#include \"../../../Src/FPS/PowerProjection.hpp\"\
    \n#include \"atcoder/modint\"\nusing namespace zawa;\nusing mint = atcoder::modint998244353;\n\
    using fps = FPSNTTFriendly<mint::mod()>;\n\n#include <iostream>\n#include <random>\n\
    using namespace std;\nmt19937 mt{random_device{}()};\nvector<mint> naive(int M,\
    \ const fps& W, const fps& F) {\n    vector<mint> res(M);\n    fps cur{1};\n \
    \   for (int i = 0 ; i < M ; i++) {\n        cur.resize(W.size());\n        for\
    \ (int j = 0 ; j < ssize(W) ; j++)\n            res[i] += W[j] * cur[j];\n   \
    \     cur *= F;\n    }\n    return res;\n}\nvoid test(int MAXN, int MAXM, int\
    \ MAXVAL, bool verify = true) {\n    int N = mt() % MAXN + 1;\n    int M = mt()\
    \ % MAXM + 1;\n    fps W(N), F(mt() % MAXN + 1);\n    for (int i = 0 ; i < N ;\
    \ i++)\n        W[i] = mt() % MAXVAL;\n    for (int i = 0 ; i < ssize(F) ; i++)\n\
    \        F[i] = mt() % MAXVAL;\n    auto ans = PowerProjection(M, W, F);\n   \
    \ if (verify) {\n        auto nv = naive(M, W, F);\n        if (ans != nv) {\n\
    \            cerr << \"fail\" << endl;\n            cerr << \"W -> \" << W <<\
    \ endl;\n            cerr << \"F -> \" << F << endl;\n            cerr << \"ans:\
    \ \";\n            for (auto i : nv)\n                cerr << i.val() << ' ';\n\
    \            cerr << endl;\n            cerr << \"you: \";\n            for (auto\
    \ i : ans)\n                cerr << i.val() << ' ';\n            cerr << endl;\n\
    \            exit(0);\n        }\n    }\n}\nvoid test2(int N, int M, int MAXVAL)\
    \ {\n    fps W(N), F(N);\n    for (int i = 0 ; i < N ; i++) {\n        W[i] =\
    \ mt() % MAXVAL;\n        F[i] = mt() % MAXVAL;\n    }\n    auto ans = PowerProjection(M,\
    \ W, F);\n    std::cerr << ans.size() << \"fin\" << std::endl;\n}\nint main()\
    \ {\n    for (int i = (1 << 15) ; i-- ; )\n        test(4, 10, 10);\n    cerr\
    \ << \"tiny end\" << endl;\n    for (int i = (1 << 10) ; i-- ; )\n        test(50,\
    \ 50, mint::mod());\n    cerr << \"small end\" << endl;\n    for (int i = 0 ;\
    \ i < (1 << 3) ; i++)\n        test(3000, 1000, mint::mod());\n    cerr << \"\
    med end\" << endl;\n    test2(250000, 250000, mint::mod());\n    cerr << \"large\
    \ end\" << endl;\n    int A, B;\n    cin >> A >> B;\n    cout << A + B << '\\\
    n';\n}\n"
  dependsOn:
  - Src/FPS/FPSNTTFriendly.hpp
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  - Src/FPS/PowerProjection.hpp
  isVerificationFile: true
  path: Test/My/FPS/PowerProjection.test.cpp
  requiredBy: []
  timestamp: '2026-01-12 16:27:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/My/FPS/PowerProjection.test.cpp
layout: document
redirect_from:
- /verify/Test/My/FPS/PowerProjection.test.cpp
- /verify/Test/My/FPS/PowerProjection.test.cpp.html
title: Test/My/FPS/PowerProjection.test.cpp
---
