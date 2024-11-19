#pragma once

#include "./StaticPointAddRectangleSum.hpp"
#include "../../Template/TypeAlias.hpp"

#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

template <class T, class U>
class DynamicPointAddRectangleSum {
public:
    using P = typename T::P;
    using W = typename T::W;
    static_assert(std::same_as<typename T::P, typename U::P>, "T::P and U::P must be same");

    usize add(const T& P) {
        usize res{m_ps.size()};
        m_pos.emplace_back(false, res);
        m_ps.push_back(P);
        return res;
    }

    usize add(T&& P) {
        usize res{m_ps.size()};
        m_pos.emplace_back(false, res);
        m_ps.push_back(std::move(P));
        return res;
    }

    usize product(const U& Q) {
        usize res{m_qs.size()};
        m_pos.emplace_back(true, res);
        m_qs.push_back(Q);
        return res;
    }

    usize product(U&& Q) {
        usize res{m_qs.size()};
        m_pos.emplace_back(true, res);
        m_qs.push_back(std::move(Q));
        return res;
    }

    std::vector<W> execute() const {
        std::vector<W> res(m_qs.size());

        auto rec{[&](auto rec, usize l, usize r) -> void {
            assert(l <= r);
            if (l + 1 >= r) return;
            usize m{(l + r) >> 1};
            rec(rec, l, m);
            rec(rec, m, r);
            std::vector<usize> p, q;
            for (usize i{l} ; i < m ; i++) if (!m_pos[i].first) {
                p.push_back(m_pos[i].second);
            }
            for (usize i{m} ; i < r ; i++) if (m_pos[i].first) {
                q.push_back(m_pos[i].second);
            }
            if (p.empty() or q.empty()) return;
            std::vector<W> kiyo{StaticPointAddRectangleSum<T, U>(
                    std::vector<T>(m_ps.begin() + p.front(), m_ps.begin() + p.back() + 1),
                    std::vector<U>(m_qs.begin() + q.front(), m_qs.begin() + q.back() + 1)
                    )};
            for (usize i{} ; i < q.size() ; i++) {
                res[q[i]] += kiyo[i];
            }
        }};

        rec(rec, usize{0}, m_pos.size());
        return res;
    }

private:

    std::vector<T> m_ps;
    std::vector<U> m_qs;
    std::vector<std::pair<bool, usize>> m_pos;
};

} // namespace zawa
