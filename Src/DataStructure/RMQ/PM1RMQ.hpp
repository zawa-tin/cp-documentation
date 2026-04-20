#pragma once

#include <algorithm>
#include <bit>
#include <cassert>
#include <concepts>
#include <utility>
#include <vector>

#include "../SparseTable/SparseTable.hpp"

namespace zawa {

template <std::totally_ordered T>
class PM1RMQ {
private:

    struct MIN {
        using Element = std::pair<T,usize>;
        static Element operation(const Element& l,const Element& r) {
            return r.first < l.first ? r : l;
        }
    };

public:

    PM1RMQ() = default;

    PM1RMQ(std::vector<T> a) 
        : m_n{a.size()}, m_b{std::max<usize>(std::bit_width(m_n)/2,1)}, m_inner{(size()+bucketSize()-1)/bucketSize()},
        m_a{std::move(a)}, m_look(innerSize()), m_table(1u << (bucketSize()-1))
    {
        std::vector<typename MIN::Element> dat(innerSize());
        for (usize i = 0,idx = 0 ; i < size() ; i += bucketSize(),idx++) {
            typename MIN::Element v{m_a[i],i}; 
            for (usize j = 1 ; j < bucketSize() and i + j < size() ; j++) {
                v = MIN::operation(v,typename MIN::Element{m_a[i+j],i+j});
                if (m_a[i+j] == m_a[i+j-1] + 1)
                    ;
                else if (m_a[i+j] == m_a[i+j-1] - 1)
                    m_look[idx] |= 1u << (j-1);
                else
                    assert(!"init table does not satisfy |a_i-a_{i+1}| = 1");
            }
            registerTable(m_look[idx]);
            dat[idx] = std::move(v);
        }
        m_spt = SparseTable<MIN>(std::move(dat));
    }

    inline usize size() const {
        return m_n;
    }

    // return leftmost index of min{a[l],a[l+1],...,a[r-1]} (min of argmin)
    // empty is not allowed
    usize product(usize l,usize r) const {
        assert(l < r and r <= size());
        usize L = l/bucketSize(), R = (r-1)/bucketSize();
        if (L == R)
            return accessTable(L,l-L*bucketSize(),r-L*bucketSize());
        usize res = accessTable(L,l-L*bucketSize(),bucketSize());
        L++;
        if (L < R) {
            auto pd = m_spt.product(L,R);
            if (m_a[res] > pd.first)
                res = pd.second;
        }
        usize rv = accessTable(R,0u,r-R*bucketSize());
        if (m_a[res] > m_a[rv])
            res = rv;
        return res;
    }

    usize operator()(usize l,usize r) const {
        return product(l,r);
    }

private:

    usize m_n,m_b,m_inner;

    std::vector<T> m_a;

    // 0..+1,1..-1
    std::vector<usize> m_look;

    std::vector<std::vector<usize>> m_table;

    SparseTable<MIN> m_spt;

    inline usize bucketSize() const {
        return m_b;
    }

    inline usize innerSize() const {
        return m_inner;
    }

    static constexpr usize Tri(usize i) {
        return i*(i+1)/2;
    }

    usize encode(usize l,usize r) const {
        assert(l < r and r <= bucketSize());
        return Tri(bucketSize())-Tri(bucketSize()-l)+(r-l-1);
    }

    void registerTable(usize info) {
        if (m_table[info].size())
            return;
        m_table[info].resize(Tri(bucketSize()));
        std::vector<usize> val(bucketSize());
        val[0] = bucketSize();
        for (usize i = 0 ; i + 1 < bucketSize() ; i++) {
            val[i+1] = val[i];
            if (info & (1u << i))
                val[i+1]--;
            else
                val[i+1]++;
        }
        for (usize l = 0 ; l < bucketSize() ; l++) {
            usize mn = l;
            for (usize r = l ; r < bucketSize() ; r++) {
                if (val[mn] > val[r])
                    mn = r;
                m_table[info][encode(l,r+1)] = mn;
            }
        }
    }

    usize accessTable(usize idx,usize l,usize r) const {
        return idx * bucketSize() + m_table[m_look[idx]].at(encode(l,r));
    }

};

} // namespace zawa
