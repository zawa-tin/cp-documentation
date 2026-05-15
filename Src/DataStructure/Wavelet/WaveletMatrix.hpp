#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <bit>
#include <cassert>
#include <concepts>
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
        m_dat.resize(height(),std::vector<bool>(size()));
        m_sum.resize(height(),std::vector<u32>(size()+1));
        for (usize i = height() ; i-- ; ) {
            std::vector<T> left,right;
            for (usize j = 0 ; j < size() ; j++) {
                m_dat[i][j] = (A[j] & (T{1} << i)) > 0;
                (m_dat[i][j] ? right : left).push_back(A[j]);
                m_sum[i][j+1] = m_sum[i][j]+m_dat[i][j];
            }
            for (usize j = 0 ; T v : left)
                A[j++] = v;
            for (usize j = left.size() ; T v : right)
                A[j++] = v;
        }
    }

    inline usize size() const {
        return m_n;
    }

    T access(usize i) const {
        assert(i < size());
        T res = 0;
        for (usize h = height() ; h-- ; ) {
            res |= (T)m_dat[h][i] << h;
            if (h) {
                if (m_dat[h][i])
                    i = rank0(h,0,size())+rank1(h,0,i);
                else
                    i = rank0(h,0,i);
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
            const u32 z = rank0(h,l,r);
            if (k < z) {
                if (h) {
                    l = rank0(h,0,l);
                    r = l + z;
                }
            }
            else {
                res |= T{1} << h;
                k -= z;
                if (h) {
                    usize ll = rank0(h,0,size())+rank1(h,0,l);
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

    u32 frequency(usize l,usize r,T d,T u) const {
        assert(l <= r and r <= size());
        assert(0 <= d and d <= u);
        return frequency(l,r,u)-frequency(l,r,d); 
    }

private:

   usize m_n, m_h; 

   std::vector<std::vector<bool>> m_dat;

   std::vector<std::vector<u32>> m_sum;
    
   inline usize height() const {
       return m_h;
   }

   inline u32 rank0(usize h,usize l,usize r) const {
        return r-l-m_sum[h][r]+m_sum[h][l];
   }

   inline u32 rank1(usize h,usize l,usize r) const {
        return m_sum[h][r]-m_sum[h][l];
   }

   u32 frequency(usize l,usize r,T d) const {
        if (d >= (T{1} << height()))
            return r - l;
        u32 res = 0;
        for (usize h = height() ; h-- ; ) {
            const u32 z = rank0(h,l,r);
            if ((d >> h) & 1) {
                res += z;
                if (h) {
                    usize ll = rank0(h,0,size())+rank1(h,0,l);
                    r = ll+r-l-z;
                    l = ll;
                }
            }
            else if (h) {
                l = rank0(h,0,l);
                r = l + z;
            }
        }
        return res;
   }

};


} // namespace zawa
