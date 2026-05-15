#pragma once

#include "../../Template/TypeAlias.hpp"

#include <array>
#include <bit>
#include <cassert>
#include <concepts>
#include <vector>

namespace zawa {

class BitVector {
private:

    static constexpr u32 B = 64;

    static constexpr u32 LOGB = 6;

    static constexpr std::array<u64,B> MASK = []() {
        std::array<u64,B> res;
        res.fill(0);
        for (usize i = 1 ; i < B ; i++)
            res[i] = res[i-1]|(1ull<<(i-1));
        return res;
    }();

public:

    BitVector() = default;

    template <class T>
    BitVector(std::vector<T> a) : m_n{a.size()}, m_dat((m_n+B-1)>>LOGB), m_pref(m_dat.size()+1) {
        for (usize i = 0 ; i < size() ; i++) {
            u64 v = a[i]>0;
            m_dat[i>>LOGB] |= v << (i & (B-1));
            m_pref[(i>>LOGB)+1] += v;
        }
        for (usize i = 0 ; i < m_dat.size() ; i++)
            m_pref[i+1] += m_pref[i];
    }

    inline usize size() const {
        return m_n;
    }

    u32 rank1(usize l,usize r) const {
        return pref(r)-pref(l);
    }

    u32 rank0(usize l,usize r) const {
        return r-l-pref(r)+pref(l);
    }

    template<class T>
    T access(usize i) const {
        return (m_dat[i>>LOGB] >> (i&(B-1))) & 1;
    }

private:

    usize m_n;

    std::vector<u64> m_dat;

    std::vector<u32> m_pref;

    u32 pref(usize r) const {
        const usize q = r>>LOGB, b = r&(B-1);
        return m_pref[r>>LOGB]+(b ? std::popcount<u64>(m_dat[r>>LOGB]&MASK[r&(B-1)]) : 0u);
    }

};

} // namespace zawa
