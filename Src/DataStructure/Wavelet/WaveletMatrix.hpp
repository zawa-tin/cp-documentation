#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../PrefixSum/BitVector.hpp"

#include <algorithm>
#include <bit>
#include <cassert>
#include <concepts>
#include <tuple>
#include <vector>

namespace zawa {

template <std::integral T>
class WaveletMatrix {
public:

    WaveletMatrix() = default;

    explicit WaveletMatrix(std::vector<T> A) : m_n{A.size()}, m_h{1} {
        for (T a : A) {
            assert(a >= 0);
            m_h = std::max<usize>(m_h,std::bit_width<usize>(a));
        }
        m_sum.resize(height());
        for (usize i = height() ; i-- ; ) {
            std::vector<T> left,right;
            std::vector<u8> dat(size());
            for (usize j = 0 ; j < size() ; j++) {
                dat[j] = (A[j] >> i) & 1;
                (dat[j] ? right : left).push_back(A[j]);
            }
            m_sum[i] = BitVector(std::move(dat));
            for (usize j = 0 ; T v : left)
                A[j++] = v;
            for (usize j = left.size() ; T v : right)
                A[j++] = v;
        }
    }
    
    inline usize height() const {
        return m_h;
    }

    inline usize size() const {
        return m_n;
    }

    T access(usize i) const {
        assert(i < size());
        T res = 0;
        for (usize h = height() ; h-- ; ) {
            res |= m_sum[h].access<T>(i) << h;
            if (h) {
                if (m_sum[h].access<bool>(i))
                    i = m_sum[h].rank0(0,size())+m_sum[h].rank1(0,i);
                else
                    i = m_sum[h].rank0(0,i);
            }
        }
        return res;
    }

    T get(usize i) const {
        assert(i < size());
        return access(i);
    }

    T operator[](usize i) const {
        assert(i < size());
        return access(i);
    }

    T quantile(usize l,usize r,usize k) const {
        assert(l <= r and r <= size());
        assert(k < r - l);
        T res = 0;
        for (usize h = height() ; h-- ; ) {
            const u32 z = m_sum[h].rank0(l,r);
            if (k < z) {
                if (h) {
                    l = m_sum[h].rank0(0,l);
                    r = l + z;
                }
            }
            else {
                res |= T{1} << h;
                k -= z;
                if (h) {
                    usize ll = m_sum[h].rank0(0,size())+m_sum[h].rank1(0,l);
                    r = ll + r - l - z;
                    l = ll;
                }
            }
        }
        return res;
    }

    T kthSmallest(usize l,usize r,usize k) const {
        assert(l <= r and r <= size());
        assert(k < r - l);
        return quantile(l,r,k);
    }

    u32 frequency(usize l,T d,usize r,T u) const {
        assert(l <= r and r <= size());
        assert(0 <= d and d <= u);
        return frequency(l,r,u)-frequency(l,r,d); 
    }

protected:

   usize m_n, m_h; 

   std::vector<BitVector> m_sum;

   u32 frequency(usize l,usize r,T d) const {
        if (d >= (T{1} << height()))
            return r - l;
        u32 res = 0;
        for (usize h = height() ; h-- ; ) {
            const u32 z = m_sum[h].rank0(l,r);
            if ((d >> h) & 1) {
                res += z;
                if (h) {
                    usize ll = m_sum[h].rank0(0,size())+m_sum[h].rank1(0,l);
                    r = ll+r-l-z;
                    l = ll;
                }
            }
            else if (h) {
                l = m_sum[h].rank0(0,l);
                r = l + z;
            }
        }
        return res;
   }

};


} // namespace zawa
