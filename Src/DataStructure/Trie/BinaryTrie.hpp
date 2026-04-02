#pragma once

#include "../../Template/TypeAlias.hpp"

#include <cassert>
#include <vector>

namespace zawa {

template <usize Height>
class BinaryTrie {
private:

    static_assert(usize{1} <= Height and Height <= usize{64});

    struct Node {
        usize cnt=0;
        usize ch[2]{0,0};
    };

public:

    BinaryTrie() : m_trie(2) {}

    void insert(u64 v,u64 k = 1) {
        assert(check(v));
        usize nd = 1;
        for (usize i = Height ; i-- ; ) {
            m_trie[nd].cnt += k;
            const usize b = (v >> i) & 1;
            if (!m_trie[nd].ch[b])
                m_trie[nd].ch[b] = makeNode();
            nd = m_trie[nd].ch[b];
        }
        m_trie[nd].cnt += k;
    }

    usize count(u64 v) const {
        assert(check(v));
        usize nd = 1;
        for (usize i = Height ; i-- ; ) {
            const usize b = (v >> i) & 1;
            nd = m_trie[nd].ch[b];
            if (!nd)
                return 0;
        }
        return m_trie[nd].cnt;
    }

    usize erase(u64 v,u64 k = 1) {
        usize nd = 1;
        std::vector<usize> nds{nd};
        nds.reserve(Height+1);
        for (usize i = Height ; i-- ; ) {
            const usize b = (v >> i) & 1;
            nd = m_trie[nd].ch[b];
            if (!nd)
                return 0;
            nds.push_back(nd);
        }
        k = std::min(k,m_trie[nd].cnt);
        if (k) {
            for (usize i : nds)
                m_trie[i].cnt -= k;
        }
        return k;
    }
    
    bool empty() const {
        return m_trie[1].cnt == 0;
    }

    usize size() const {
        return m_trie[1].cnt;
    }

    usize setmin(u64 mask) const {
        assert(size());
        usize nd = 1;
        u64 res = 0;
        for (usize i = Height ; i < 64u ; i++)
            if ((mask >> i) & 1)
                res |= u64{1} << i;
        for (usize i = Height ; i-- ; ) {
            assert(m_trie[nd].cnt);
            const usize b = (mask >> i) & 1;
            if (m_trie[nd].ch[b] and m_trie[m_trie[nd].ch[b]].cnt) {
                nd = m_trie[nd].ch[b];
                continue;
            }
            res |= u64{1} << i;
            nd = m_trie[nd].ch[b^1];
        }
        return res;
    }

    usize setmax(u64 mask) const {
        assert(size());
        usize nd = 1;
        u64 res = 0;
        for (usize i = Height ; i < 64u ; i++)
            if ((mask >> i) & 1)
                res |= u64{1} << i;
        for (usize i = Height ; i-- ; ) {
            assert(m_trie[nd].cnt);
            const usize b = (mask >> i) & 1;
            if (m_trie[nd].ch[b^1] and m_trie[m_trie[nd].ch[b^1]].cnt) {
                res |= u64{1} << i;
                nd = m_trie[nd].ch[b^1];
                continue;
            }
            nd = m_trie[nd].ch[b^1];
        }
        return res;
    }

    const Node& operator[](usize i) const {
        assert(i < m_trie.size());
        return m_trie[i];
    }

private:

    std::vector<Node> m_trie;

    usize makeNode() {
        usize res = m_trie.size();
        m_trie.emplace_back();
        return res;
    }

    inline bool check(u64 v) const {
        return Height == 64 or v < (u64{1} << Height);
    }
};

} // namespace zawa
