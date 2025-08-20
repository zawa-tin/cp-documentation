---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Action/ActionConcept.hpp
    title: Src/Algebra/Action/ActionConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/aho_corasick
    links:
    - https://judge.yosupo.jp/problem/aho_corasick
  bundledCode: "#line 1 \"Test/LC/aho_corasick.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aho_corasick\"\
    \n\n#line 2 \"Src/Sequence/AhoCorasick.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line\
    \ 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\n\
    namespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Action/ActionConcept.hpp\"\
    \n\n#line 4 \"Src/Algebra/Action/ActionConcept.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ concepts {\n\ntemplate <class G, class X>\nconcept Action = requires {\n   \
    \ typename G::Element;\n    { G::action(std::declval<typename G::Element>(), std::declval<X>())\
    \ } -> std::same_as<X>;\n};\n\n// Is appropriate name X-set?\ntemplate <class\
    \ G, class X>\nconcept Acted = requires {\n    typename G::Element;\n    { G::acted(std::declval<typename\
    \ G::Element>(), std::declval<X>()) } -> std::same_as<typename G::Element>;\n\
    };\n\n} // namespace concepts\n\n} // namespace zawa\n#line 6 \"Src/Sequence/AhoCorasick.hpp\"\
    \n\n#include <cassert>\n#line 9 \"Src/Sequence/AhoCorasick.hpp\"\n#include <ranges>\n\
    #include <unordered_map>\n#include <utility>\n#include <vector>\n\nnamespace zawa\
    \ {\n\nnamespace ahocorasick_internal {\n\ntemplate <class T>\nconcept HasValueType\
    \ = requires {\n    typename T::value_type;\n};\n\ntemplate <class T, class S>\n\
    concept AuxiliaryData = concepts::Monoid<T> and concepts::Acted<T, S>;\n\n} //\
    \ namespace ahocorasick_internal\n\ntemplate <ahocorasick_internal::HasValueType\
    \ Container>\nclass AhoCorasick {\npublic:\n\n    using V = Container::value_type;\n\
    \nprivate:\n\n    class Trie {\n    public:\n\n        struct Node {\n       \
    \     usize fail = 0;\n            std::unordered_map<V, usize> ch{};\n      \
    \      std::pair<usize, V> par{};\n        };\n\n        Trie(std::vector<Node>&&\
    \ nodes, std::vector<usize>&& match) \n            : m_nodes{std::move(nodes)},\
    \ m_match{std::move(match)} {}\n\n        static constexpr usize Root() {\n  \
    \          return 0;\n        }\n\n        usize size() const {\n            return\
    \ m_nodes.size();\n        }\n\n        usize trace(usize cur, V v) {\n      \
    \      assert(cur < size());\n            while (cur and !m_nodes[cur].ch.contains(v))\n\
    \                cur = m_nodes[cur].fail;\n            if (auto it = m_nodes[cur].ch.find(v)\
    \ ; it != m_nodes[cur].ch.end())\n                return it->second;\n       \
    \     else\n                return cur;\n        }\n\n        usize match(usize\
    \ i) const {\n            assert(i < m_match.size());\n            return m_match[i];\n\
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
    \ std::move(match)};\n    }\n\n    template <class T, class S>\n    requires ahocorasick_internal::AuxiliaryData<T,\
    \ S>\n    std::pair<Trie, std::vector<typename T::Element>> build(const std::vector<S>&\
    \ values) const {\n        assert(values.size() == m_seq.size());\n        std::vector<typename\
    \ T::Element> data(1, T::identity());\n        std::vector<typename Trie::Node>\
    \ nodes(1);  \n        std::vector<usize> match(m_seq.size());\n        for (usize\
    \ i = 0 ; const Container& s : m_seq) {\n            usize cur = 0, idx = 0;\n\
    \            for ( ; idx < s.size() ; idx++) {\n                auto it = nodes[cur].ch.find(s[idx]);\n\
    \                if (it == nodes[cur].ch.end())\n                    break;\n\
    \                cur = it->second;\n            }\n            for ( ; idx < s.size()\
    \ ; idx++) {\n                usize nxt = nodes[cur].ch[s[idx]] = nodes.size();\n\
    \                nodes.emplace_back();\n                nodes.back().par = {cur,\
    \ s[idx]};\n                data.push_back(data[cur]);\n                cur =\
    \ nxt;\n            }\n            match[i] = cur;\n            data[cur] = T::acted(data[cur],\
    \ values[i++]);\n        }\n        std::vector<usize> que;\n        for (const\
    \ usize x : nodes[0].ch | std::views::values)\n            que.emplace_back(x);\n\
    \        for (usize qt = 0 ; qt < que.size() ; qt++) {\n            const usize\
    \ v = que[qt];\n            for (const usize x : nodes[v].ch | std::views::values)\n\
    \                que.emplace_back(x);\n            auto [x, ed] = nodes[v].par;\n\
    \            if (!x) \n                continue;\n            x = nodes[x].fail;\n\
    \            while (x and !nodes[x].ch.contains(ed))\n                x = nodes[x].fail;\n\
    \            if (auto it = nodes[x].ch.find(ed) ; it == nodes[x].ch.end() or it->second\
    \ == v) \n                nodes[v].fail = 0;\n            else\n             \
    \   nodes[v].fail = it->second;\n            data[v] = T::operation(data[nodes[v].fail],\
    \ data[v]);\n        }\n        return std::pair{Trie{std::move(nodes), std::move(match)},\
    \ data};\n    }\n\nprivate:\n\n    std::vector<Container> m_seq;\n\n};\n\n} //\
    \ namespace zawa\n#line 4 \"Test/LC/aho_corasick.test.cpp\"\n\n#include <iostream>\n\
    #include <string>\n#line 8 \"Test/LC/aho_corasick.test.cpp\"\n\nusing namespace\
    \ std;\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N;\n    cin >> N;\n    zawa::AhoCorasick<string> aho;\n    for (int i\
    \ = 0 ; i < N ; i++) {\n        string s;\n        cin >> s;\n        aho.insert(s);\n\
    \    }\n    auto trie = aho.build();\n    const auto& nodes = trie.nodes(); \n\
    \    cout << trie.size() << '\\n';\n    for (int i = 1 ; i < ssize(nodes) ; i++)\n\
    \        cout << nodes[i].par.first << ' ' << nodes[i].fail << '\\n';\n    for\
    \ (int i = 0 ; i < N ; i++)\n        cout << trie.match(i) << (i + 1 == N ? '\\\
    n' : ' ');\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aho_corasick\"\n\n#include\
    \ \"../../Src/Sequence/AhoCorasick.hpp\"\n\n#include <iostream>\n#include <string>\n\
    #include <vector>\n\nusing namespace std;\nint main() {\n    cin.tie(0);\n   \
    \ cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N;\n    cin >> N;\n    zawa::AhoCorasick<string>\
    \ aho;\n    for (int i = 0 ; i < N ; i++) {\n        string s;\n        cin >>\
    \ s;\n        aho.insert(s);\n    }\n    auto trie = aho.build();\n    const auto&\
    \ nodes = trie.nodes(); \n    cout << trie.size() << '\\n';\n    for (int i =\
    \ 1 ; i < ssize(nodes) ; i++)\n        cout << nodes[i].par.first << ' ' << nodes[i].fail\
    \ << '\\n';\n    for (int i = 0 ; i < N ; i++)\n        cout << trie.match(i)\
    \ << (i + 1 == N ? '\\n' : ' ');\n}\n"
  dependsOn:
  - Src/Sequence/AhoCorasick.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Action/ActionConcept.hpp
  isVerificationFile: true
  path: Test/LC/aho_corasick.test.cpp
  requiredBy: []
  timestamp: '2025-08-20 19:47:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/aho_corasick.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/aho_corasick.test.cpp
- /verify/Test/LC/aho_corasick.test.cpp.html
title: Test/LC/aho_corasick.test.cpp
---
