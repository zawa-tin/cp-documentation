#pragma once

#include <algorithm>
#include <cassert>
#include <concepts>
#include <utility>
#include <map>
#include <vector>

namespace zawa {

template <std::integral Z, class T>
class RangeAssigner {
public:

    RangeAssigner() = default;

    RangeAssigner(Z n, T init)
        : m_min{0}, m_max{n} {
        m_mp[0] = {n, init};
    }

    RangeAssigner(Z min, Z max, T init) 
        : m_min{min}, m_max{max} {
        assert(min <= max);
        m_mp[m_min] = {max, init};
    }

    std::vector<std::tuple<Z, Z, T>> operator()(Z l, Z r) const {
        assert(m_min <= l and l <= r and r <= m_max);
        std::vector<std::tuple<Z, Z, T>> res;
        for (auto it = prev(m_mp.upper_bound(l)) ; it != m_mp.end() and it->first < r ; it++)
            res.emplace_back(std::max(it->first, l), std::min(it->second.first, r), it->second.second);
        return res;
    }

    std::vector<std::tuple<Z, Z, T>> assign(Z l, Z r, T v) {
        assert(m_min <= l and l <= r and r <= m_max);
        std::vector<std::tuple<Z, Z, T>> res;
        {
            auto it = prev(m_mp.upper_bound(l));
            const Z L = it->first, R = it->second.first;
            const T V = it->second.second;
            it->second.first = L;
            m_mp.erase(it);
            if (L < l)
                m_mp[L] = {l, V};
            res.emplace_back(l, std::min(r, R), V);
            if (r < R)
                m_mp[r] = {R, V};
            if (r <= R) {
                m_mp[l] = {r, v};
                return res;
            }
        }
        auto it = m_mp.upper_bound(l);
        for ( ; it != m_mp.end() and it->second.first <= r ; it = m_mp.erase(it))
            res.emplace_back(it->first, it->second.first, it->second.second);
        if (it != m_mp.end() and r < it->second.first) {
            const Z L = it->first, R = it->second.first;
            const T V = it->second.second;
            it = m_mp.erase(it);
            res.emplace_back(L, r, V);
            m_mp[r] = {R, V};
        }
        m_mp[l] = {r, v};
        return res;
    }

private:

    std::map<Z, std::pair<Z, T>> m_mp;

    Z m_min, m_max;

};

} // namespace zawa
