#pragma once

#include <cassert>
#include <concepts>
#include <limits>
#include <utility>
#include <set>

namespace zawa {

template <std::signed_integral T>
class MexManager {
public:

    static constexpr T MAX = std::numeric_limits<T>::max();

    static constexpr T MIN = T{-1};

    MexManager() {
        m_rg.insert({MIN, MIN});
        m_rg.insert({MAX, MAX});
    }

    void insert(T v) {
        assert(MIN + 1 <= v and v <= MAX - 1);
        if (!m_set.contains(v)) {
            const T r = [&]() {
                auto it = m_rg.lower_bound({v + 1, MIN});
                if (it->first == v + 1) {
                    int res = it->second;
                    m_rg.erase(it);
                    return res;
                }
                else
                    return v;
            }();
            const T l = [&]() {
                auto it = prev(m_rg.lower_bound({v, MIN}));
                if (it->second + 1 == v) {
                    int res = it->first;
                    m_rg.erase(it);
                    return res;
                }
                else
                    return v;
            }();
            m_rg.insert({l, r});
        }
        m_set.insert(v);
    }

    void erase(T v) {
        if (!m_set.contains(v))
            return;
        m_set.erase(m_set.find(v));
        if (m_set.contains(v))
            return;
        auto it = prev(m_rg.lower_bound({v + 1, MIN}));
        const auto [l, r] = *it;
        assert(l <= v and v <= r);
        it = m_rg.erase(it);
        if (l < v) m_rg.insert({l, v - 1});
        if (v < r) m_rg.insert({v + 1, r});
    }

    T operator()() const {
        return m_rg.begin()->second + 1;
    }

private:

    std::set<std::pair<T, T>> m_rg;

    std::multiset<T> m_set;
};

} // namespace zawa
