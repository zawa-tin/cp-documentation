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
        {
            std::vector<std::pair<Point, usize>> idxs(m_a.size());
            for (usize i = 0 ; i < m_a.size() ; i++) {
                m_on[i].resize(m_a.size() - i);
                m_cover[i].resize(m_a.size() - i);
                idxs[i].first = std::move(a[i]);
                idxs[i].second = i;
            }
            std::sort(idxs.begin(), idxs.end());
            for (usize i = 0 ; i < m_a.size() ; i++) {
                m_a[i] = std::move(idxs[i].first);
                m_inv[idxs[i].second] = i;
            }
        }
        std::sort(b.begin(), b.end());
        // calc m_under and m_eq
        for (usize i = 0 ; i < m_a.size() ; i++) {
            for (usize j = 0 ; j < b.size() and b[j].x() <= m_a[i].x() ; j++) {
                if (b[j].x() == m_a[i].x()) {
                    if (b[j].y() < m_a[i].y()) m_under[i]++;
                    else if (b[j].y() == m_a[i].y()) m_eq[i]++;
                }
            } 
        }
        // calc m_on
        for (usize i = 0 ; i < m_a.size() ; i++) {
            std::vector<std::pair<Point, usize>> dj;
            for (usize j = i + 1 ; j < m_a.size() ; j++) if (m_a[j] != m_a[i]) {
                dj.push_back({m_a[j]-m_a[i], j});
            }
            for (const auto& q : b) if (m_a[i].x() <= q.x() and m_a[i] != q) {
                dj.push_back({q-m_a[i],usize{0}});
            }
            std::ranges::sort(dj, [&](const auto& l, const auto& r) {
                    if (l.first != r.first) return Point::ArgComp(l.first, r.first);
                    else return l.second < r.second;
                    });
            for (usize j = 0, k = 0 ; j < dj.size() ; j = k) {
                while (k < dj.size() and Zero(Cross(dj[j].first, dj[k].first)) and !Negative(Dot(dj[j].first, dj[k].first))) k++;
                for (usize t = j, cnt = 0 ; t < k ; t++) {
                    if (dj[t].second) m_on[i][dj[t].second - i] += cnt - m_eq[dj[t].second];
                    else cnt++;
                }
            }
        }
        // calc m_cover
        for (usize i = 0 ; i < m_a.size() ; i++) {
            std::vector<std::pair<Point, usize>> dj;
            for (usize j = i + 1 ; j < m_a.size() ; j++) if (m_a[i] != m_a[j]) {
                // j > 0
                dj.push_back({m_a[j]-m_a[i], j});
            }
            std::vector<Vector> dirs;
            for (const auto& q : b) if (m_a[i].x() <= q.x() and m_a[i] != q) {
                dj.push_back({q-m_a[i],usize{0}});
                dirs.push_back(q-m_a[i]);
            }
            std::ranges::sort(dj);
            std::ranges::sort(dirs, Point::ArgComp);
            dirs.erase(std::unique(dirs.begin(), dirs.end()), dirs.end());
            std::vector<u32> fen(dirs.size() + 1);
            for (const auto& [d, j] : dj) {
                if (j) {
                    auto it = std::distance(dirs.begin(), std::ranges::upper_bound(dirs, d, Point::ArgComp));
                    for ( ; it ; it -= it & -it) m_cover[i][j - i] += fen[it];
                    m_cover[i][j - i] -= m_eq[j];
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
        i = m_inv[i];
        j = m_inv[j];
        k = m_inv[k];
        if (m_a[i] == m_a[j] or m_a[j] == m_a[k] or m_a[k] == m_a[i]) return 0;
        if (m_a[i] > m_a[j]) std::swap(i, j);
        if (m_a[j] > m_a[k]) std::swap(j, k);
        if (m_a[i] > m_a[j]) std::swap(i, j);
        RELATION r = Relation(m_a[i], m_a[j], m_a[k]);
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

    std::vector<Point> m_a;

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
