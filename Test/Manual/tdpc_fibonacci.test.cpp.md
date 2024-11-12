---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/KthTerm.hpp
    title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u306EK\u9805\u76EE\u3092\u8A08\u7B97\u3059\
      \u308B"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/tdpc/submissions/59717471
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
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
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * Typical DP Contest T - \u30D5\u30A3\u30DC\u30CA\u30C3\u30C1\n * https://atcoder.jp/contests/tdpc/submissions/59717471\n\
    \ */\n\n#include \"../../Src/FPS/KthTerm.hpp\"\n#include \"./atcoder/modint\"\n\
    \n#include <iostream>\n#include <vector>\n\nusing namespace zawa;\n\nusing mint\
    \ = atcoder::modint1000000007;\n\nmint solve() {\n    int K, N;\n    std::cin\
    \ >> K >> N;\n    return KthTerm(N - 1, std::vector<mint>(K, 1), std::vector<mint>(K,\
    \ 1), [](const std::vector<mint>& L, const std::vector<mint>& R) -> std::vector<mint>\
    \ {\n                if (L.empty() or R.empty()) return {};\n                std::vector<mint>\
    \ res(L.size() + R.size() - 1);\n                for (int i{} ; i < (int)L.size()\
    \ ; i++) for (int j{} ; j < (int)R.size() ; j++) {\n                    res[i\
    \ + j] += L[i] * R[j];\n                }\n                return res;\n     \
    \       });\n}\n\nint main() {\n#ifdef ATCODER\n    std::cout << solve().val()\
    \ << '\\n';\n#else\n    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/FPS/KthTerm.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/Manual/tdpc_fibonacci.test.cpp
  requiredBy: []
  timestamp: '2024-11-13 00:58:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Manual/tdpc_fibonacci.test.cpp
layout: document
redirect_from:
- /verify/Test/Manual/tdpc_fibonacci.test.cpp
- /verify/Test/Manual/tdpc_fibonacci.test.cpp.html
title: Test/Manual/tdpc_fibonacci.test.cpp
---
