#pragma once

#include "./RectangleSumOfPointCloud.hpp"
#include "../../Template/TypeAlias.hpp"

#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

template <class T, class U>
requires concepts::RSOPCQuery<T, U>
class PointAddRectangleSum {
public:
    using P = typename T::P;
    using W = typename T::W;

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
            if (r - l > THRESHOLD) {
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
                std::vector<W> kiyo{RectangleSumOfPointCloud<T, U>(
                        std::vector<T>(m_ps.begin() + p.front(), m_ps.begin() + p.back() + 1),
                        std::vector<U>(m_qs.begin() + q.front(), m_qs.begin() + q.back() + 1)
                        )};
                for (usize i{} ; i < q.size() ; i++) {
                    res[q[i]] += kiyo[i];
                }
            }
            else {
                for (usize i{l} ; i < r ; i++) if (m_pos[i].first) {
                    const U& u{m_qs[m_pos[i].second]};
                    for (usize j{l} ; j < i ; j++) if (!m_pos[j].first) {
                        const T& t{m_ps[m_pos[j].second]};
                        if (u.l <= t.x and t.x < u.r and u.d <= t.y and t.y < u.u) {
                            res[m_pos[i].second] += t.w;
                        }
                    }
                }
            }
        }};

        rec(rec, usize{0}, m_pos.size());
        return res;
    }

private:

    static constexpr usize THRESHOLD{200};

    std::vector<T> m_ps;
    std::vector<U> m_qs;
    std::vector<std::pair<bool, usize>> m_pos;
};

} // namespace zawa
