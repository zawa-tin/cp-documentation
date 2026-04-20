#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <bit>
#include <cassert>
#include <concepts>
#include <utility>
#include <vector>


namespace zawa {

template <std::totally_ordered T>
class PM1RMQ {
private:

    static constexpr usize B = 8;

    static constexpr usize LOGB = 3;

    static constexpr usize TRI = B*(B+1)/2;

public:

    PM1RMQ() = default;

    PM1RMQ(std::vector<T> a) 
        : m_n{a.size()}, m_inner{(a.size()+B-1)>>LOGB},
        m_a{std::move(a)}, m_look(innerSize()), m_table((1u << (B-1))*TRI), m_spt(std::bit_width(innerSize()))
    {
        std::vector<u32> minIndex(innerSize());
        std::vector<bool> registered(1u << (B-1));
        for (usize i = 0,idx = 0 ; i < size() ; i += B,idx++) {
            minIndex[idx] = i;
            for (usize j = 1 ; j < B and i + j < size() ; j++) {
                if (m_a[i+j] < m_a[minIndex[idx]])
                    minIndex[idx] = i + j;
                if (m_a[i+j] == m_a[i+j-1]+1)
                    ;
                else if (m_a[i+j] == m_a[i+j-1]-1)
                    m_look[idx] |= 1u << (j-1);
                else
                    assert(!"init table does not satisfy |a_i-a_{i+1}| = 1");
            }
            if (!registered[m_look[idx]]) {
                registered[m_look[idx]] = 1;
                registerTable(m_look[idx]);
            }
        }
        m_spt[0] = std::move(minIndex);
        for (usize i = 1,len = 2 ; i < m_spt.size() ; i++,len <<= 1) {
            m_spt[i].resize(innerSize()-len+1);
            for (usize j = 0 ; j < m_spt[i].size() ; j++) {
                usize l = m_spt[i-1][j], r = m_spt[i-1][j+(len>>1)];
                m_spt[i][j] = m_a[r] < m_a[l] ? r : l;
            }
        }
    }

    inline usize size() const {
        return m_n;
    }

    // return leftmost index of min{a[l],a[l+1],...,a[r-1]} (min of argmin)
    // empty is not allowed
    usize min(usize l,usize r) const {
        assert(l < r and r <= size());
        usize L = l>>LOGB, R = (r-1)>>LOGB;
        if (L == R)
            return accessTable(L,l-(L<<LOGB),r-(L<<LOGB));
        usize res = accessTable(L,l-(L<<LOGB),B);
        L++;
        if (L < R) {
            auto pd = sptMin(L,R);
            if (m_a[pd] < m_a[res])
                res = pd;
        }
        usize rv = accessTable(R,0u,r-(R<<LOGB));
        if (m_a[rv] < m_a[res])
            res = rv;
        return res;
    }

    usize operator()(usize l,usize r) const {
        return min(l,r);
    }

private:

    usize m_n,m_inner;

    std::vector<T> m_a;

    // 0..+1,1..-1
    std::vector<usize> m_look;

    std::vector<usize> m_table;

    std::vector<std::vector<u32>> m_spt;

    inline usize innerSize() const {
        return m_inner;
    }

    usize encode(usize l,usize r) const {
        // assert(l < r and r <= B);
        static constexpr uint32_t ROW[8]{0,8,15,21,26,30,33,35};
        return ROW[l]+(r-l-1);
    }

    void registerTable(usize info) {
        const usize offset = TRI*info;
        std::vector<usize> val(B);
        val[0] = B;
        for (usize i = 0 ; i + 1 < B ; i++) {
            val[i+1] = val[i];
            if (info & (1u << i))
                val[i+1]--;
            else
                val[i+1]++;
        }
        for (usize l = 0 ; l < B ; l++) {
            usize mn = l;
            for (usize r = l ; r < B ; r++) {
                if (val[mn] > val[r])
                    mn = r;
                m_table[offset+encode(l,r+1)] = mn;
            }
        }
    }

    usize accessTable(usize idx,usize l,usize r) const {
        return (idx<<LOGB) + m_table[m_look[idx]*TRI+encode(l,r)];
    }

    usize sptMin(usize l,usize r) const {
        usize dep = std::bit_width(r-l)-1, i = m_spt[dep][l], j = m_spt[dep][r-(1u<<dep)];
        return m_a[j] < m_a[i] ? j : i;
    }
};

} // namespace zawa
