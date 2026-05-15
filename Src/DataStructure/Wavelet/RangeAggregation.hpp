#pragma once

#include "WaveletMatrix.hpp"
#include "../../Sequence/CompressedSequence.hpp"

#include <algorithm>
#include <numeric>
#include <ranges>
#include <utility>

namespace zawa {

template <std::integral T>
class RangeAggregation : public WaveletMatrix<u32> {
private:

    using WaveletMatrix<u32>::m_sum;

public:

    using WaveletMatrix<u32>::size;
    using WaveletMatrix<u32>::height;
    using WaveletMatrix<u32>::access;
    using WaveletMatrix<u32>::quantile;
    using WaveletMatrix<u32>::frequency;

    RangeAggregation() = default;

    RangeAggregation(std::vector<T> A) : WaveletMatrix<u32>(compressed(A)), m_comp{std::move(A)} {}

    std::vector<std::pair<usize,usize>> point(usize i) const {
        std::vector<std::pair<usize,usize>> res(height());
        for (usize h = height() ; h-- ; ) {
            if (m_sum[h].template access<bool>(i))
                i = m_sum[h].rank0(0,size())+m_sum[h].rank1(0,i);
            else
                i = m_sum[h].rank0(0,i);
            res[h] = {h,i};
        }
        return res;
    }

    std::vector<std::tuple<usize,usize,usize>> rectangle(usize l,T d,usize r,T u) const {
        assert(l <= r and r <= size());
        assert(d <= u);
        std::vector<std::tuple<usize,usize,usize>> res;       
        dfs(height()-1,l,r,m_comp[d],m_comp[u],T{0},T{1}<<height(),res);
        return res;
    }

    u32 count(usize l,T d,usize r,T u) const {
        assert(l <= r and r <= size());
        assert(d <= u);
        return frequency(l,m_comp[d],r,m_comp[u]);
    }

private:

    static std::vector<u32> compressed(std::vector<T> a) {
        auto b = a;
        std::ranges::sort(b);
        b.erase(std::unique(b.begin(),b.end()),b.end());
        std::vector<u32> res(a.size());
        for (usize i = 0 ; i < a.size() ; i++)
            res[i] = std::ranges::lower_bound(b,a[i])-b.begin();
        return res;
    }

    CompressedSequence<T> m_comp;

    void dfs(usize h,usize l,usize r,T d,T u,T D,T U,std::vector<std::tuple<usize,usize,usize>>& res) const {
        if (u <= D or U <= d or l == r)
            return;
        const T mid = D + (T{1} << h);
        const u32 o = m_sum[h].rank1(l,r),z = r - l - o;
        const usize zeroL = m_sum[h].rank0(0,l),zeroR = zeroL+z;
        const usize oneL = m_sum[h].rank0(0,size())+m_sum[h].rank1(0,l),oneR = oneL+o;
        if (d <= D and mid <= u and zeroL < zeroR)
            res.emplace_back(h,zeroL,zeroR);
        else if (h)
            dfs(h-1,zeroL,zeroR,d,u,D,mid,res);
        if (d <= mid and U <= u and oneL < oneR)
            res.emplace_back(h,oneL,oneR);
        else if (h)
            dfs(h-1,oneL,oneR,d,u,mid,U,res);
    }

};

} // namespace zawa
