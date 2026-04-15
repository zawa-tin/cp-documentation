#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Monoid/MonoidConcept.hpp"

#include <bit>
#include <cassert>
#include <deque>
#include <numeric>
#include <vector>

namespace zawa {

template <concepts::Monoid M>
class PersistentSegmentTree {
public:

    using V = typename M::Element;

    struct Node {

        V value = M::identity();

        Node* left = nullptr;

        Node* right = nullptr;

        Node() = default;

        explicit Node(V v) : value{std::move(v)} {}

        Node(V v,Node* l,Node* r) : value{std::move(v)},left{l},right{r} {}
    };

    PersistentSegmentTree() = default;

    explicit PersistentSegmentTree(std::vector<V> a) : m_n{a.size()}, m_m{bit_ceil(a.size())}, m_dat{} {
        // m_pool.reserve(2*innerSize());
        m_dat.push_back(construct(std::move(a)));
    }

    explicit PersistentSegmentTree(usize n) : m_n{n}, m_m{std::bit_ceil(n)}, m_dat{} {
        // m_pool.reserve(2*innerSize());
        m_dat.push_back(construct(std::vector(m_n,M::identity())));
    }

    inline usize size() const {
        return m_n;
    }

    inline usize versionSize() const {
        return m_dat.size();
    }

    V get(usize ver,usize i) const {
        assert(ver < versionSize());
        assert(i < size());
        return get(m_dat[ver],i,0u,innerSize());
    }

    V get(usize i) const {
        assert(m_dat.size());
        return get(m_dat.back(),i,0u,innerSize());
    }

    V product(usize ver,usize l,usize r) const {
        assert(ver < versionSize());
        assert(l <= r and r <= size());
        return product(m_dat[ver],l,r,0u,innerSize());
    }

    V product(usize l,usize r) const {
        assert(m_dat.size());
        return product(m_dat.back(),l,r,0u,innerSize());
    }

    usize assign(usize ver,usize i,V v) {
        assert(ver < versionSize());
        assert(i < size());
        const usize res = m_dat.size();
        m_dat.push_back(assign(m_dat[ver],i,std::move(v),0u,innerSize()));
        return res;
    }

    usize assign(usize i,V v) {
        return assign(m_dat.size()-1,i,std::move(v));
    }

    usize operation(usize ver,usize i,V v) {
        assert(ver < versionSize());
        assert(i < size());
        const usize res = m_dat.size();
        m_dat.push_back(operation(m_dat[ver],i,std::move(v),0u,innerSize()));
        return res;
    }

    usize operation(usize i,V v) {
        return operation(m_dat.size()-1,i,std::move(v));
    }

private:

    usize m_n, m_m;

    std::vector<Node*> m_dat;

    std::deque<Node> m_pool;

    inline usize innerSize() const {
        return m_m;
    }

    inline Node* makeNode(V v) {
        m_pool.emplace_back(std::move(v));
        return &m_pool.back();
    }

    inline Node* merge(Node* l,Node* r) {
        m_pool.emplace_back(M::operation(l->value,r->value),l,r);
        return &m_pool.back();
    }

    Node* construct(std::vector<V> a) {
        a.resize(innerSize(),M::identity());
        auto rec = [&](auto rec,usize l,usize r) -> Node* {
            if (l + 1 == r)
                return makeNode(a[l]);
            const usize m = std::midpoint(l,r); 
            return merge(rec(rec,l,m),rec(rec,m,r));
        };
        return rec(rec,0u,innerSize());
    }

    V get(const Node* node,usize i,usize l,usize r) const {
        if (l + 1 == r)
            return node->value;
        const usize m = std::midpoint(l,r);
        if (i < m)
            return get(node->left,i,l,m);
        else
            return get(node->right,i,m,r);
    }

    V product(const Node* node,usize l,usize r,usize nl,usize nr) const {
        if (nr <= l or r <= nl)
            return M::identity();
        if (l <= nl and nr <= r)
            return node->value;
        const usize m = std::midpoint(nl,nr);
        return M::operation(product(node->left,l,r,nl,m),product(node->right,l,r,m,nr));
    }

    Node* assign(const Node* node,usize i,V v,usize l,usize r) {
        if (l + 1 == r)
            return makeNode(std::move(v));
        const usize m = std::midpoint(l,r);
        if (i < m)
            return merge(assign(node->left,i,std::move(v),l,m),node->right);
        else
            return merge(node->left,assign(node->right,i,std::move(v),m,r));
    }

    Node* operation(const Node* node,usize i,V v,usize l,usize r) {
        if (l + 1 == r)
            return makeNode(M::operation(node->value,std::move(v)));
        const usize m = std::midpoint(l,r);
        if (i < m)
            return merge(operation(node->left,i,std::move(v),l,m),node->right);
        else
            return merge(node->left,operation(node->right,i,std::move(v),m,r));
    }
};


} // namespace zawa
