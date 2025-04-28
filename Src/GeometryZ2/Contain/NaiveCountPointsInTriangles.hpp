#pragma once

#include "../PointCloud.hpp"
#include "../Relation.hpp"

namespace zawa {

namespace geometryZ2 {

class NaiveCountPointsInTriangles {
public:

    NaiveCountPointsInTriangles(PointCloud a, PointCloud b) : m_a{std::move(a)}, m_b{std::move(b)} {}

    u32 operator()(u32 p, u32 q, u32 r) const {
        assert(p < size() and q < size() and r < size());
        if (m_a[p] > m_a[q]) std::swap(p, q);
        if (m_a[q] > m_a[r]) std::swap(q, r);
        if (m_a[p] > m_a[q]) std::swap(p, q);
        RELATION R = Relation(m_a[p], m_a[q], m_a[r]);
        if (R == RELATION::ONLINE_FRONT or R == RELATION::ONLINE_BACK or R == RELATION::ON_SEGMENT) return 0;
        bool ctr = R == RELATION::COUNTER_CLOCKWISE;
        u32 res = 0;
        for (const Point& i : m_b) {
            Zahlen a = Cross(m_a[q] - m_a[p], i - m_a[p]), b = Cross(m_a[r] - m_a[q], i - m_a[q]), c = Cross(m_a[p] - m_a[r], i - m_a[r]);
            if (ctr and a > 0 and b > 0 and c > 0) res++;
            else if (!ctr and a < 0 and b < 0 and c < 0) res++;
        }
        return res;
    }

    inline usize size() const {
        return m_a.size();
    }

private:

    std::vector<Point> m_a, m_b;
};

} // namespace geometryZ2

} // namespace zawa
