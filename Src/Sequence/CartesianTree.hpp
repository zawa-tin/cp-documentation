#pragma once

#include "../Template/TypeAlias.hpp"

#include <concepts>
#include <cassert>
#include <type_traits>
#include <vector>

namespace zawa {

template <class T>
class CartesianTree {
public:

    static constexpr usize Invalid{static_cast<usize>(-1)};

    struct Node {
        usize left{Invalid}, right{Invalid}, par{Invalid}, idx{Invalid};
        T value{};
        std::vector<usize> childs() const noexcept {
            std::vector<usize> res;
            res.reserve(2);
            if (left != Invalid) res.push_back(left);
            if (right != Invalid) res.push_back(right);
            return res;
        }
        usize countChilds() const noexcept {
            return (left != Invalid) + (right != Invalid);
        }
    };

    CartesianTree() = default;

    template <class F>
    requires std::strict_weak_order<F, T, T>
    CartesianTree(const std::vector<T>& A, F comp) 
        : m_size{A.size()}, m_nodes(A.size()) {

        std::vector<usize> stack(A.size());
        usize top{};
        for (usize i{} ; i < size() ; i++) {
            if (top and comp(A[i], A[stack[top - 1]])) {
                while (top and comp(A[i], A[stack[top - 1]])) top--;
                m_nodes[i].left = stack[top];
                m_nodes[stack[top]].par = i;
            }
            if (top) {
                m_nodes[i].par = stack[top - 1];
                m_nodes[stack[top - 1]].right = i;
            }
            else {
                m_root = i;
            }
            m_nodes[i].value = A[i];
            m_nodes[i].idx = i;
            stack[top++] = i;
        }
    }

    inline usize size() const noexcept {
        return m_size;
    }

    inline usize root() const noexcept {
        return m_root;
    }

    inline T value(usize i) const noexcept {
        assert(i < size());
        return m_nodes[i].value;
    }

    inline usize parent(usize i) const noexcept {
        assert(i < size());
        return m_nodes[i].par;
    }

    inline usize left(usize i) const noexcept {
        assert(i < size());
        return m_nodes[i].left;
    }

    inline usize right(usize i) const noexcept {
        assert(i < size());
        return m_nodes[i].right;
    }

    template <class F>
    void treeDP(F func) {
        static_assert(std::is_invocable_v<F, const Node&>, "F must be invocable f(const Node&)");
        dfs(m_root, func);
    }

private:

    template <class F>
    void dfs(usize v, F func) {
        if (m_nodes[v].left != Invalid) dfs(m_nodes[v].left, func);
        if (m_nodes[v].right != Invalid) dfs(m_nodes[v].right, func);
        func(m_nodes[v]);
    }

    usize m_size{}, m_root{Invalid};
    std::vector<Node> m_nodes;
};

} // namespace zawa
