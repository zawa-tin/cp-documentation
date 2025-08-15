#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Number/IntegerDivision.hpp"
#include "../FenwickTree/FenwickTree.hpp"
#include "../../Algebra/Group/AdditiveGroup.hpp"

#include <bit>
#include <cassert>
#include <vector>
#include <optional>

namespace zawa {

class FenwickSet {
public:

    FenwickSet() = default;

    explicit FenwickSet(usize n) 
        : m_n{n}, m_m{DivCeil<usize>(n, 64)}, m_dat(m_m), m_fen(m_m), m_all{} {}

    constexpr usize size() const {
        return m_n;
    }

    void insert(i32 x) {
        assert(0 <= x);
        assert(static_cast<usize>(x) < size());
        if ((m_dat[x / 64] >> (x % 64)) & 1) 
            return;
        m_dat[x / 64] |= u64{1} << (x % 64);
        m_fen.operation(x / 64, 1);
        m_all++;
    }

    void erase(i32 x) {
        assert(static_cast<usize>(x) < size());
        if ((m_dat[x / 64] >> (x % 64)) & 1) {
            m_dat[x / 64] ^= u64{1} << (x % 64);
            m_fen.operation(x / 64, -1);
            m_all--;
        }
    }

    bool contains(i32 x) const {
        assert(static_cast<usize>(x) < size());
        return (m_dat[x / 64] >> (x % 64)) & 1;
    }

    // 1-indexed
    std::optional<usize> kth(i32 k) const {
        assert(k > 0);
        if (static_cast<usize>(k) > m_all) 
            return std::nullopt;
        const usize idx = m_fen.maxRight(0, [&](i32 v) { return v < k; });
        i32 sum = m_fen.prefixProduct(idx);
        assert(sum < k);
        for (usize i = 0 ; i < 64 ; i++)
            if ((m_dat[idx] >> i) & 1) {
                sum++;
                if (sum == k) 
                    return idx * 64 + i;
            }
        assert(!"Fenwick Set library bug");
        return std::nullopt;
    }

    usize countLessEqual(i32 x) const {
        if (x < 0) 
            return 0;
        if (static_cast<usize>(x) >= size()) 
            return m_all;
        usize sum = m_fen.prefixProduct(x / 64);
        for (i32 i = 0 ; i <= x % 64 ; i++) 
            sum += (m_dat[x / 64] >> i) & 1;
        return sum;
    }

    std::optional<usize> prevEqual(i32 x) const {
        if (countLessEqual(x) == 0) 
            return std::nullopt;
        for (usize i = x % 64 + 1 ; i-- ; ) 
            if ((m_dat[x / 64] >> i) & 1) 
                return (x / 64) * 64 + i;
        const usize idx = m_fen.minLeft(x / 64, [](i32 v) { return v <= 0; });
        for (usize i = 64 ; i-- ; ) 
            if ((m_dat[idx] >> i) & 1)
                return idx * 64 + i;
        assert(!"Fenwick Set library bug");
        return std::nullopt;
    }

    std::optional<usize> nextEqual(i32 x) const {
        if (m_all == countLessEqual(x - 1))
            return std::nullopt;
        for (usize i = x % 64 ; i < 64 ; i++)
            if ((m_dat[x / 64] >> i) & 1)
                return (x / 64) * 64 + i;
        const usize idx = m_fen.maxRight(x / 64 + 1, [](i32 v) { return v <= 0; });
        for (usize i = 0 ; i < 64 ; i++)
            if ((m_dat[idx] >> i) & 1)
                return idx * 64 + i;
        assert(!"Fenwick Set library bug");
        return std::nullopt;
    }

private:

    usize m_n{}, m_m{};
    
    std::vector<u64> m_dat;

    FenwickTree<AdditiveGroup<i32>> m_fen;

    usize m_all{0};

};

} // namespace zawa
