---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/AhoCorasick.hpp
    title: Aho-Corasick
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
    - https://atcoder.jp/contests/abc268/submissions/68594582
    - https://atcoder.jp/contests/abc268/tasks/abc268_ex
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc268_h.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc268/tasks/abc268_ex\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/Sequence/AhoCorasick.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Sequence/AhoCorasick.hpp\"\n\n#include <cassert>\n\
    #include <concepts>\n#include <ranges>\n#include <unordered_map>\n#include <vector>\n\
    \nnamespace zawa {\n\nnamespace ahocorasickinternal {\n\ntemplate <class T>\n\
    concept HasValueType = requires {\n    typename T::value_type;\n};\n\ntemplate\
    \ <class T>\nconcept AuxiliaryData = requires {\n    typename T::Element;\n  \
    \  { T::identity() } -> std::same_as<typename T::Element>;\n    { T::merge(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n    { T::add(std::declval<typename T::Element>(), std::declval<usize>())\
    \ } -> std::same_as<typename T::Element>;\n};\n\n} // namespace ahocorasickinternal\n\
    \ntemplate <ahocorasickinternal::HasValueType Container>\nclass AhoCorasick {\n\
    public:\n\n    using V = Container::value_type;\n\nprivate:\n\n    class Trie\
    \ {\n    public:\n\n        struct Node {\n            usize fail = 0;\n     \
    \       std::unordered_map<V, usize> ch{};\n            std::pair<usize, V> par{};\n\
    \        };\n\n        Trie(std::vector<Node>&& nodes, std::vector<usize>&& match)\
    \ \n            : m_nodes{std::move(nodes)}, m_match{std::move(match)} {}\n\n\
    \        static constexpr usize Root() {\n            return 0;\n        }\n\n\
    \        usize size() const {\n            return m_nodes.size();\n        }\n\
    \n        usize trace(usize cur, V v) {\n            assert(cur < size());\n \
    \           while (cur and !m_nodes[cur].ch.contains(v))\n                cur\
    \ = m_nodes[cur].fail;\n            if (auto it = m_nodes[cur].ch.find(v) ; it\
    \ != m_nodes[cur].ch.end())\n                return it->second;\n            else\n\
    \                return cur;\n        }\n\n        usize match(usize i) const\
    \ {\n            assert(i < m_match.size());\n            return m_match[i];\n\
    \        }\n\n        usize trace(usize cur, const Container& S) {\n         \
    \   assert(cur < size());\n            for (V v : S)\n                cur = trace(cur,\
    \ v);\n            return cur;\n        }\n\n        const std::vector<Node>&\
    \ nodes() const& {\n            return m_nodes;\n        }\n\n    private:\n\n\
    \        std::vector<Node> m_nodes;\n\n        std::vector<usize> m_match;\n \
    \   };\n\npublic:\n\n    AhoCorasick() = default;\n\n    usize insert(Container\
    \ s) {\n        usize res = m_seq.size();\n        m_seq.push_back(s);\n     \
    \   return res;\n    }\n\n    Trie build() const {\n        std::vector<typename\
    \ Trie::Node> nodes(1);  \n        std::vector<usize> match;\n        match.reserve(m_seq.size());\n\
    \        for (const Container& s : m_seq) {\n            usize cur = 0, idx =\
    \ 0;\n            for ( ; idx < s.size() ; idx++) {\n                auto it =\
    \ nodes[cur].ch.find(s[idx]);\n                if (it == nodes[cur].ch.end())\n\
    \                    break;\n                cur = it->second;\n            }\n\
    \            for ( ; idx < s.size() ; idx++) {\n                usize nxt = nodes[cur].ch[s[idx]]\
    \ = nodes.size();\n                nodes.emplace_back();\n                nodes.back().par\
    \ = {cur, s[idx]};\n                cur = nxt;\n            }\n            match.push_back(cur);\n\
    \        }\n        std::vector<usize> que;\n        for (const usize x : nodes[0].ch\
    \ | std::views::values)\n            que.emplace_back(x);\n        for (usize\
    \ qt = 0 ; qt < que.size() ; qt++) {\n            const usize v = que[qt];\n \
    \           for (const usize x : nodes[v].ch | std::views::values)\n         \
    \       que.emplace_back(x);\n            auto [x, ed] = nodes[v].par;\n     \
    \       if (!x) \n                continue;\n            x = nodes[x].fail;\n\
    \            while (x and !nodes[x].ch.contains(ed))\n                x = nodes[x].fail;\n\
    \            if (auto it = nodes[x].ch.find(ed) ; it == nodes[x].ch.end() or it->second\
    \ == v) \n                nodes[v].fail = 0;\n            else\n             \
    \   nodes[v].fail = it->second;\n        }\n        return Trie{std::move(nodes),\
    \ std::move(match)};\n    }\n\n    template <ahocorasickinternal::AuxiliaryData\
    \ T>\n    Trie build(std::vector<typename T::Element>& data) const {\n       \
    \ data.clear();\n        data.resize(1, T::identity());\n        std::vector<typename\
    \ Trie::Node> nodes(1);  \n        std::vector<usize> match(m_seq.size());\n \
    \       for (usize i = 0 ; const Container& s : m_seq) {\n            usize cur\
    \ = 0, idx = 0;\n            for ( ; idx < s.size() ; idx++) {\n             \
    \   auto it = nodes[cur].ch.find(s[idx]);\n                if (it == nodes[cur].ch.end())\n\
    \                    break;\n                cur = it->second;\n            }\n\
    \            for ( ; idx < s.size() ; idx++) {\n                usize nxt = nodes[cur].ch[s[idx]]\
    \ = nodes.size();\n                nodes.emplace_back();\n                nodes.back().par\
    \ = {cur, s[idx]};\n                data.push_back(data[cur]);\n             \
    \   cur = nxt;\n            }\n            match[i] = cur;\n            data[cur]\
    \ = T::add(data[cur], i++);\n        }\n        std::vector<usize> que;\n    \
    \    for (const usize x : nodes[0].ch | std::views::values)\n            que.emplace_back(x);\n\
    \        for (usize qt = 0 ; qt < que.size() ; qt++) {\n            const usize\
    \ v = que[qt];\n            for (const usize x : nodes[v].ch | std::views::values)\n\
    \                que.emplace_back(x);\n            auto [x, ed] = nodes[v].par;\n\
    \            if (!x) \n                continue;\n            x = nodes[x].fail;\n\
    \            while (x and !nodes[x].ch.contains(ed))\n                x = nodes[x].fail;\n\
    \            if (auto it = nodes[x].ch.find(ed) ; it == nodes[x].ch.end() or it->second\
    \ == v) \n                nodes[v].fail = 0;\n            else\n             \
    \   nodes[v].fail = it->second;\n            data[v] = T::merge(data[nodes[v].fail],\
    \ data[v]);\n        }\n        return Trie{std::move(nodes), std::move(match)};\n\
    \    }\n\nprivate:\n\n    std::vector<Container> m_seq;\n\n};\n\n} // namespace\
    \ zawa\n#line 5 \"Test/AtCoder/abc268_h.test.cpp\"\n\n/*\n * AtCoder Beginner\
    \ Contest 268 Ex - Taboo\n * https://atcoder.jp/contests/abc268/submissions/68594582\n\
    \ */\n\n#include <iostream>\n#include <string>\n#line 14 \"Test/AtCoder/abc268_h.test.cpp\"\
    \nusing namespace std;\nusing namespace zawa;\nstruct M {\n    using Element =\
    \ bool;\n    static Element identity() {\n        return false;\n    }\n    static\
    \ Element add(Element, int) {\n        return true;\n    }\n    static Element\
    \ merge(Element l, Element r) {\n        return l or r;\n    }\n};\nint main()\
    \ {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    string S;\n    int N;\n    cin >> S >> N;\n    AhoCorasick<string> aho;\n\
    \    for (int i = 0 ; i < N ; i++) {\n        string T;\n        cin >> T;\n \
    \       aho.insert(T);\n    }\n    vector<bool> ban;\n    auto trie = aho.build<M>(ban);\n\
    \    int ans = 0, cur = 0;\n    for (char c : S) {\n        cur = trie.trace(cur,\
    \ c);\n        if (ban[cur]) {\n            ans++;\n            cur = decltype(trie)::Root();\n\
    \        }\n    }\n    cout << ans << '\\n';\n#else\n    cout << \"Hello World\\\
    n\";\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc268/tasks/abc268_ex\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/Sequence/AhoCorasick.hpp\"\n\n/*\n * AtCoder Beginner\
    \ Contest 268 Ex - Taboo\n * https://atcoder.jp/contests/abc268/submissions/68594582\n\
    \ */\n\n#include <iostream>\n#include <string>\n#include <vector>\nusing namespace\
    \ std;\nusing namespace zawa;\nstruct M {\n    using Element = bool;\n    static\
    \ Element identity() {\n        return false;\n    }\n    static Element add(Element,\
    \ int) {\n        return true;\n    }\n    static Element merge(Element l, Element\
    \ r) {\n        return l or r;\n    }\n};\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n\
    \    cout.tie(0);\n    ios::sync_with_stdio(0);\n    string S;\n    int N;\n \
    \   cin >> S >> N;\n    AhoCorasick<string> aho;\n    for (int i = 0 ; i < N ;\
    \ i++) {\n        string T;\n        cin >> T;\n        aho.insert(T);\n    }\n\
    \    vector<bool> ban;\n    auto trie = aho.build<M>(ban);\n    int ans = 0, cur\
    \ = 0;\n    for (char c : S) {\n        cur = trie.trace(cur, c);\n        if\
    \ (ban[cur]) {\n            ans++;\n            cur = decltype(trie)::Root();\n\
    \        }\n    }\n    cout << ans << '\\n';\n#else\n    cout << \"Hello World\\\
    n\";\n#endif\n}\n"
  dependsOn:
  - Src/Sequence/AhoCorasick.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc268_h.test.cpp
  requiredBy: []
  timestamp: '2025-08-17 19:11:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc268_h.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc268_h.test.cpp
- /verify/Test/AtCoder/abc268_h.test.cpp.html
title: Test/AtCoder/abc268_h.test.cpp
---
