#pragma once

#include "../PointCloud.hpp"
#include "../Relation.hpp"

#include <limits>
#include <numeric>
#include <utility>
#include <vector>

namespace zawa {

namespace geometryZ2 {

class CountPointsInTriangles {
public:

    CountPointsInTriangles(PointCloud a, PointCloud b) 
        : m_a(a.size()), m_under(a.size()), m_eq(a.size()), m_on(a.size()), m_cover(a.size()), m_inv(a.size()) {
        for (u32 i = 0 ; i < m_a.size() ; i++) {
            m_on[i].resize(m_a.size() - i);
            m_cover[i].resize(m_a.size() - i);
            m_a[i].first = std::move(a[i]);
            m_a[i].second = i;
        }
        std::sort(m_a.begin(), m_a.end());
        for (usize i = 0 ; i < m_a.size() ; i++) m_inv[m_a[i].second] = i;
        std::sort(b.begin(), b.end());
        // calc m_under and m_eq
        for (const auto& [p, i] : m_a) {
            for (usize j = 0 ; j < b.size() and b[j].x() <= p.x() ; j++) {
                if (b[j].x() == p.x()) {
                    if (b[j].y() < p.y()) m_under[i]++;
                    else if (b[j].y() == p.y()) m_eq[i]++;
                }
            } 
        }
        // calc m_on
        for (usize i = 0 ; i < m_a.size() ; i++) {
            const auto& [p, idx] = m_a[i];
            std::vector<std::pair<Point, usize>> dj;
            for (usize j = i + 1 ; j < m_a.size() ; j++) if (m_a[j].first != p) {
                dj.push_back({m_a[j].first-p, m_a[j].second+1});
            }
            for (const auto& q : b) if (p.x() <= q.x() and p != q) {
                dj.push_back({q-p,usize{0}});
            }
            std::ranges::sort(dj, [&](const auto& l, const auto& r) {
                    if (l.first != r.first) return Point::ArgComp(l.first, r.first);
                    else return l.second < r.second;
                    });
            for (usize j = 0, k = 0 ; j < dj.size() ; j = k) {
                while (k < dj.size() and Zero(Cross(dj[j].first, dj[k].first)) and !Negative(Dot(dj[j].first, dj[k].first))) k++;
                for (usize t = j, cnt = 0 ; t < k ; t++) {
                    auto [pdx, qdx] = std::minmax({idx, dj[t].second-1});
                    if (dj[t].second) m_on[pdx][qdx - pdx] += cnt - m_eq[dj[t].second - 1];
                    else cnt++;
                }
            }
        }
        // calc m_cover
        for (usize i = 0 ; i < m_a.size() ; i++) {
            const auto& [p, idx] = m_a[i];
            std::vector<std::pair<Point, usize>> dj;
            for (usize j = i + 1 ; j < m_a.size() ; j++) if (p != m_a[j].first) {
                dj.push_back({m_a[j].first-p, m_a[j].second+1});
            }
            std::vector<Vector> dirs;
            for (const auto& q : b) if (p.x() <= q.x() and p != q) {
                dj.push_back({q-p,usize{0}});
                dirs.push_back(q-p);
            }
            std::ranges::sort(dj);
            std::ranges::sort(dirs, Point::ArgComp);
            dirs.erase(std::unique(dirs.begin(), dirs.end()), dirs.end());
            std::vector<u32> fen(dirs.size() + 1);
            for (const auto [d, j] : dj) {
                if (j) {
                    auto it = std::distance(dirs.begin(), std::ranges::upper_bound(dirs, d, Point::ArgComp));
                    const auto [pdx, qdx] = std::minmax({idx, j-1});
                    for ( ; it ; it -= it & -it) m_cover[pdx][qdx - pdx] += fen[it];
                    m_cover[pdx][qdx - pdx] -= m_eq[j - 1];
                }
                else {
                    auto it = std::distance(dirs.begin(), std::ranges::lower_bound(dirs, d, Point::ArgComp));
                    for (it++ ; it < std::ssize(fen) ; it += it & -it) fen[it]++;
                }
            }
        }
    }

    inline usize size() const {
        return m_a.size();
    }

    // strictly inside
    u32 operator()(usize i, usize j, usize k) const {
        assert(i < size() and j < size() and k < size());
        if (i == j or j == k or i == k) return 0;
        if (m_a[m_inv[i]].first == m_a[m_inv[j]].first or m_a[m_inv[j]].first == m_a[m_inv[k]].first or m_a[m_inv[k]].first == m_a[m_inv[i]].first) return 0;
        if (m_a[m_inv[i]].first > m_a[m_inv[j]].first) std::swap(i, j);
        if (m_a[m_inv[j]].first > m_a[m_inv[k]].first) std::swap(j, k);
        if (m_a[m_inv[i]].first > m_a[m_inv[j]].first) std::swap(i, j);
        RELATION r = Relation(m_a[m_inv[i]].first, m_a[m_inv[j]].first, m_a[m_inv[k]].first);
        if (r == RELATION::ONLINE_BACK or r == RELATION::ONLINE_FRONT or r == RELATION::ON_SEGMENT) {
            return 0;
        }
        else if (r == RELATION::COUNTER_CLOCKWISE) {
            return cover(i, k) - cover(i, j) - cover(j, k) - m_eq[j] + m_under[j] - on(i, k);
        }
        else {
            return cover(i, j) + cover(j, k) - cover(i, k) - m_under[j] - on(i, j) - on(j, k);
        }
    }
    
private:

    std::vector<std::pair<Point, usize>> m_a;

    std::vector<u32> m_under, m_eq;

    std::vector<std::vector<u32>> m_on, m_cover;
    
    std::vector<usize> m_inv;

    u32 cover(usize i, usize j) const {
        if (i > j) std::swap(i, j);
        return m_cover[i][j - i];
    }

    u32 on(usize i, usize j) const {
        if (i > j) std::swap(i, j);
        return m_on[i][j - i];
    }
};

} // namespace geometryZ2

} // namespace zawa
