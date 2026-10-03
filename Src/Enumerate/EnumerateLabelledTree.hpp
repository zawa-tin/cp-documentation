#pragma once

#include "../DataStructure/Heap/BinaryHeap.hpp"

#include <concepts>
#include <iterator>
#include <utility>
#include <vector>

namespace zawa {

namespace enumerate {

template <class T>
class LabelledTree {
public:

    using Tree = std::vector<std::pair<T,T>>;

    explicit LabelledTree(T n) : m_n(n) {
        assert(n >= 0);
    }

    class Iterator {
    public:

        using iterator_concept = std::input_iterator_tag;

        using value_type = Tree;

        using difference_type = std::ptrdiff_t;

        Iterator() = default;

        explicit Iterator(T n) : m_n(n),m_code(n >= 2 ? n - 2 : 0),m_fin(n == 0) {
            assert(n >= 0);
        }

        Tree operator*() const {
            if (m_n == 1) 
                return {};
            std::vector<T> deg(m_n,1);
            for (T v : m_code)
                deg[v]++;
            BinaryHeap<T> que;
            for (T v = 0; v < m_n; v++)
                if (deg[v] == 1)
                    que.push(v);
            Tree edges;
            edges.reserve(m_n - 1);
            for (T v : m_code) {
                T u = que.top();
                que.pop();
                edges.emplace_back(u,v);
                deg[u]--;
                if (--deg[v] == 1)
                    que.push(v);
            }
            T u = que.top();
            que.pop();
            T v = que.top();
            edges.emplace_back(u,v);
            return edges;
        }

        Iterator& operator++() {
            for (T i = static_cast<T>(std::ssize(m_code)) ; i-- ; ) {
                if (++m_code[i] < m_n)
                    return *this;
                m_code[i] = 0;
            }
            m_fin = true;
            return *this;
        }

        void operator++(int) {
            ++*this;
        }

        friend bool operator==(const Iterator& it,std::default_sentinel_t) {
            return it.m_fin;
        }

    private:

        T m_n = 0;

        std::vector<T> m_code;

        bool m_fin = true;

    };

    Iterator begin() const {
        return Iterator(m_n);
    }

    std::default_sentinel_t end() const {
        return {};
    }

private:

    T m_n;
};

} // namespace enumerate

} // namespace zawa
