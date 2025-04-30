#pragma once

#include "../PointCloud.hpp"

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
        // calc m_cover, m_on
        for (usize i = 0 ; i < m_a.size() ; i++) {
            std::vector<std::pair<Point, usize>> dj;
            std::vector<Vector> dirs;
            {
                std::vector<std::pair<Point, usize>> da, db;
                for (usize j = i + 1 ; j < m_a.size() ; j++) if (m_a[i] != m_a[j]) {
                    da.push_back({m_a[j]-m_a[i], j});
                }
                for (const auto& q : b) if (m_a[i].x() <= q.x() and m_a[i] != q) {
                    db.emplace_back(q-m_a[i],std::numeric_limits<usize>::max());
                    dirs.push_back(q-m_a[i]);
                }
                std::ranges::sort(db);
                dj.resize(db.size() + da.size());
                for (usize j = 0, k = 0, t = 0 ; t < dj.size() ; t++) {
                    if (k == db.size()) dj[t] = std::move(da[j++]);
                    else if (j == da.size()) dj[t] = std::move(db[k++]);
                    else if (da[j] < db[k]) dj[t] = std::move(da[j++]);
                    else dj[t] = std::move(db[k++]);
                }
            }
            std::ranges::sort(dirs, Point::ArgComp);
            dirs.erase(
                    std::unique(dirs.begin(), dirs.end(), [&](const auto& l, const auto& r) { return Zero(Cross(l, r)) and !Negative(Dot(l, r)); }), 
                    dirs.end());
            std::vector<u32> fen(dirs.size() + 1), dat(dirs.size());
            for (const auto& [d, j] : dj) {
                if (j == std::numeric_limits<usize>::max()) {
                    auto it = std::distance(
                            dirs.begin(), 
                            std::ranges::lower_bound(dirs, d, [](const Point& l, const Point& r) {
                                    if (l.area() != r.area()) return l.area() < r.area();
                                    return Positive(Cross(l, r));
                                })
                            );
                    dat[it]++;
                    for (it++ ; it < std::ssize(fen) ; it += it & -it) fen[it]++;
                }
                else {
                    auto it = std::distance(dirs.begin(), std::ranges::upper_bound(dirs, d, Point::ArgComp));
                    if (it and Zero(Cross(d, dirs[it - 1])) and !Negative(Dot(d, dirs[it - 1]))) {
                        m_on[i][j - i] = dat[it - 1];
                    }
                    for ( ; it ; it -= it & -it) m_cover[i][j - i] += fen[it];
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
        // std::cout << i << ' ' << j << ' ' << k << std::endl;
        const Zahlen crs = Cross(m_a[j] - m_a[i], m_a[k] - m_a[i]);
        if (crs == 0) {
            return 0;
        }
        else if (crs > 0) {
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
