#pragma once

#include "../../Template/TypeAlias.hpp"

#include <array>
#include <cassert>
#include <concepts>
#include <numeric>
#include <span>
#include <type_traits>
#include <utility>
#include <vector>

namespace zawa {

template <usize N = std::dynamic_extent,std::integral T = usize>
class SymmetricGroup {
public:

    using Container = std::conditional_t<N==std::dynamic_extent,std::vector<T>,std::array<T,N>>;

    using Element = SymmetricGroup;

    constexpr SymmetricGroup() requires (N!=std::dynamic_extent) {
        std::iota(m_perm.begin(),m_perm.end(),T{0});
        std::iota(m_inv.begin(),m_inv.end(),T{0});
    }

    explicit SymmetricGroup(usize n) requires (N==std::dynamic_extent) : m_perm(n), m_inv(n) {
        std::iota(m_perm.begin(),m_perm.end(),T{0});
        std::iota(m_inv.begin(),m_inv.end(),T{0});
    }

    explicit SymmetricGroup(std::array<T,N> p) requires (N!=std::dynamic_extent) : m_perm{std::move(p)}, m_inv{} {
        for (usize i = 0 ; i < N ; i++)
            m_inv[m_perm[i]]=i;
    }

    explicit SymmetricGroup(std::vector<T> p) requires (N==std::dynamic_extent) : m_perm{std::move(p)}, m_inv(m_perm.size()) {
        for (usize i = 0 ; i < size() ; i++)
            m_inv[m_perm[i]]=i;
    }

    inline constexpr usize size() const noexcept {
        return m_perm.size();
    }

    inline usize operator[](usize i) const noexcept {
        assert(i<size());
        return m_perm[i];
    }

    inline T position(usize i) const noexcept {
        assert(i<size());
        return m_inv[i];
    }

    void swap(usize i,usize j) {
        assert(i < size());
        assert(j < size());
        std::swap(m_inv[m_perm[i]],m_inv[m_perm[j]]);
        std::swap(m_perm[i],m_perm[j]);
    }

    void composite(const SymmetricGroup& sym) {
        assert(size()==sym.size());
        Container perm;
        if constexpr (std::same_as<Container,std::vector<T>>)
            perm.resize(size());
        for (usize i = 0 ; i < size() ; i++) {
            perm[i]=sym[m_perm[i]];
            m_inv[perm[i]]=i;
        }
        m_perm=std::move(perm);
    }

    void invert() {
        std::swap(m_perm,m_inv);
    }

    static SymmetricGroup identity() {
        return SymmetricGroup{};
    }

    static SymmetricGroup operation(SymmetricGroup l,const SymmetricGroup& r) {
        l.composite(r);
        return l;
    }

    static SymmetricGroup inverse(SymmetricGroup sym) {
        sym.invert();
        return sym;
    }

    template <class U,usize M>
    static std::array<U,M> action(const SymmetricGroup& g,const std::array<U,M>& a) requires (N == std::dynamic_extent or N <= M) {
        assert(g.size() <= M);
        std::array<U,M> res;
        for (usize i = 0 ; i < g.size() ; i++)
            res[g[i]]=a[i];
        for (usize i = g.size() ; i < a.size() ; i++)
            res[i]=a[i];
        return res;
    }

    template <class U>
    static std::vector<U> action(const SymmetricGroup& g,const std::vector<U>& a) {
        assert(g.size()<=a.size());
        std::vector<U> res(a.size());
        for (usize i = 0 ; i < g.size() ; i++)
            res[g[i]]=a[i];
        for (usize i = g.size() ; i < a.size() ; i++)
            res[i]=a[i];
        return res;
    }

private:

    Container m_perm, m_inv;

};

} // namespace zawa
