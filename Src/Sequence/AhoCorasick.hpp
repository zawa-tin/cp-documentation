#pragma once

#include "../Template/TypeAlias.hpp"
#include "../Algebra/Monoid/MonoidConcept.hpp"
#include "../Algebra/Action/ActionConcept.hpp"

#include <cassert>
#include <concepts>
#include <ranges>
#include <unordered_map>
#include <utility>
#include <vector>

namespace zawa {

namespace ahocorasick_internal {

template <class T>
concept HasValueType = requires {
    typename T::value_type;
};

template <class T, class S>
concept AuxiliaryData = concepts::Monoid<T> and concepts::Acted<T, S>;

} // namespace ahocorasick_internal

template <ahocorasick_internal::HasValueType Container>
class AhoCorasick {
public:

    using V = Container::value_type;

private:

    class Trie {
    public:

        struct Node {
            usize fail = 0;
            std::unordered_map<V, usize> ch{};
            std::pair<usize, V> par{};
        };

        Trie(std::vector<Node>&& nodes, std::vector<usize>&& match) 
            : m_nodes{std::move(nodes)}, m_match{std::move(match)} {}

        static constexpr usize Root() {
            return 0;
        }

        usize size() const {
            return m_nodes.size();
        }

        usize trace(usize cur, V v) {
            assert(cur < size());
            while (cur and !m_nodes[cur].ch.contains(v))
                cur = m_nodes[cur].fail;
            if (auto it = m_nodes[cur].ch.find(v) ; it != m_nodes[cur].ch.end())
                return it->second;
            else
                return cur;
        }

        usize match(usize i) const {
            assert(i < m_match.size());
            return m_match[i];
        }

        usize trace(usize cur, const Container& S) {
            assert(cur < size());
            for (V v : S)
                cur = trace(cur, v);
            return cur;
        }

        const std::vector<Node>& nodes() const& {
            return m_nodes;
        }

    private:

        std::vector<Node> m_nodes;

        std::vector<usize> m_match;
    };

public:

    AhoCorasick() = default;

    usize insert(Container s) {
        usize res = m_seq.size();
        m_seq.push_back(s);
        return res;
    }

    Trie build() const {
        std::vector<typename Trie::Node> nodes(1);  
        std::vector<usize> match;
        match.reserve(m_seq.size());
        for (const Container& s : m_seq) {
            usize cur = 0, idx = 0;
            for ( ; idx < s.size() ; idx++) {
                auto it = nodes[cur].ch.find(s[idx]);
                if (it == nodes[cur].ch.end())
                    break;
                cur = it->second;
            }
            for ( ; idx < s.size() ; idx++) {
                usize nxt = nodes[cur].ch[s[idx]] = nodes.size();
                nodes.emplace_back();
                nodes.back().par = {cur, s[idx]};
                cur = nxt;
            }
            match.push_back(cur);
        }
        std::vector<usize> que;
        for (const usize x : nodes[0].ch | std::views::values)
            que.emplace_back(x);
        for (usize qt = 0 ; qt < que.size() ; qt++) {
            const usize v = que[qt];
            for (const usize x : nodes[v].ch | std::views::values)
                que.emplace_back(x);
            auto [x, ed] = nodes[v].par;
            if (!x) 
                continue;
            x = nodes[x].fail;
            while (x and !nodes[x].ch.contains(ed))
                x = nodes[x].fail;
            if (auto it = nodes[x].ch.find(ed) ; it == nodes[x].ch.end() or it->second == v) 
                nodes[v].fail = 0;
            else
                nodes[v].fail = it->second;
        }
        return Trie{std::move(nodes), std::move(match)};
    }

    template <class T, class S>
    requires ahocorasick_internal::AuxiliaryData<T, S>
    std::pair<Trie, std::vector<typename T::Element>> build(const std::vector<S>& values) const {
        assert(values.size() == m_seq.size());
        std::vector<typename T::Element> data(1, T::identity());
        std::vector<typename Trie::Node> nodes(1);  
        std::vector<usize> match(m_seq.size());
        for (usize i = 0 ; const Container& s : m_seq) {
            usize cur = 0, idx = 0;
            for ( ; idx < s.size() ; idx++) {
                auto it = nodes[cur].ch.find(s[idx]);
                if (it == nodes[cur].ch.end())
                    break;
                cur = it->second;
            }
            for ( ; idx < s.size() ; idx++) {
                usize nxt = nodes[cur].ch[s[idx]] = nodes.size();
                nodes.emplace_back();
                nodes.back().par = {cur, s[idx]};
                data.push_back(data[cur]);
                cur = nxt;
            }
            match[i] = cur;
            data[cur] = T::acted(data[cur], values[i++]);
        }
        std::vector<usize> que;
        for (const usize x : nodes[0].ch | std::views::values)
            que.emplace_back(x);
        for (usize qt = 0 ; qt < que.size() ; qt++) {
            const usize v = que[qt];
            for (const usize x : nodes[v].ch | std::views::values)
                que.emplace_back(x);
            auto [x, ed] = nodes[v].par;
            if (!x) 
                continue;
            x = nodes[x].fail;
            while (x and !nodes[x].ch.contains(ed))
                x = nodes[x].fail;
            if (auto it = nodes[x].ch.find(ed) ; it == nodes[x].ch.end() or it->second == v) 
                nodes[v].fail = 0;
            else
                nodes[v].fail = it->second;
            data[v] = T::operation(data[nodes[v].fail], data[v]);
        }
        return std::pair{Trie{std::move(nodes), std::move(match)}, data};
    }

private:

    std::vector<Container> m_seq;

};

} // namespace zawa
