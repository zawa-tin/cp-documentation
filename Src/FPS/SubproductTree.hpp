#pragma once

#include "../Template/TypeAlias.hpp"
#include "./FPS.hpp"

#include <cassert>
#include <bit>
#include <utility>
#include <vector>

namespace zawa {

template <concepts::IndexedFPS FPS, class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
class SubproductTree {
public:

    SubproductTree(std::vector<FPS> fs,Conv convolution = {})
        : m_n{fs.size()}, m_sz{std::bit_ceil(m_n)}, m_tree(m_sz<<1,FPS{1}) {
        for (usize i = 0 ; i < m_n ; i++)
            m_tree[m_sz+i]=std::move(fs[i]);
        for (usize i = m_sz ; --i ; ) 
            m_tree[i]=convolution(m_tree[i<<1|0],m_tree[i<<1|1]);
    }

    const FPS& root() const noexcept {
        return m_tree[1];
    }

    const FPS& operator[](usize i) const noexcept {
        assert(i and i < m_tree.size());
        return m_tree[i];
    }

    const FPS& leaf(usize i) const noexcept {
        assert(i < size());
        return m_tree[m_sz+i];
    }

    inline usize size() const noexcept {
        return m_n;
    }

    inline usize innerSize() const noexcept {
        return m_sz;
    }

private:

    usize m_n, m_sz;

    std::vector<FPS> m_tree;

};


} // namespace zawa
