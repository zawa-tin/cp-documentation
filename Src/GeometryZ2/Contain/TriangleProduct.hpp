#pragma once

#include "../PointCloud.hpp"
#include "../Distance/PointAndPoint.hpp"
#include "../../Algebra/Group/GroupConcept.hpp"
#include "../../Algebra/Group/AdditiveGroup.hpp"
#include "../../Algebra/Group/CartesianProductGroup.hpp"

#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

namespace geometryZ2 {

template <concepts::Group G>
class TriangleProduct {
public:

    using S = CartesianProductGroup<G,AdditiveGroup<i32>>;

    using T = typename S::Element;

public:

    TriangleProduct() = default;

    TriangleProduct(const PointCloud& A,const PointCloud& B,const std::vector<typename G::Element>& W) 
        : m_n{A.size()}, m_m{B.size()}, m_a{A}, m_same(m_n,S::identity()), m_exact(m_n,S::identity()),
        m_low(m_n,std::vector(m_n,S::identity())), m_onLine(m_n,std::vector(m_n,S::identity())) {
        assert(B.size() == W.size());
        for (usize i = 0 ; i < m_n ; i++)
            for (usize j = 0 ; j < m_m ; j++)
                if (A[i].x() == B[j].x()) {
                    if (B[j].y() == A[i].y())
                        m_exact[i] = S::operation(m_exact[i],T{W[j],1});
                    if (B[j].y() <= A[i].y())
                        m_same[i] = S::operation(m_same[i],T{W[j],1});
                }
        for (usize i = 0 ; i < m_n ; i++)
            for (usize j = 0 ; j < m_n ; j++)
                if (i != j) {
                    for (usize k = 0 ; k < m_m ; k++) {
                        if (Cross(A[j]-A[i],B[k]-A[i]) or Dot(A[j]-A[i],B[k]-A[i]) <= 0)
                            continue;
                        const Zahlen d = Point{B[k]-A[i]}.normSquare();
                        if (0 < d and d < Point{A[j]-A[i]}.normSquare())
                            m_onLine[i][j] = S::operation(m_onLine[i][j],T{W[k],1});
                    }
                    for (usize k = 0 ; k < m_m ; k++) {
                        if (B[k].x() <= std::min(A[i].x(),A[j].x()) or std::max(A[i].x(),A[j].x()) <= B[k].x())
                            continue;
                        if (Cross(A[j]-A[i],B[k]-A[i]) >= 0)
                            continue;
                        m_low[i][j] = S::operation(m_low[i][j],T{W[k],1});
                    }
                }
    }

    TriangleProduct(const PointCloud& A,const std::vector<typename G::Element>& W) : TriangleProduct(A,A,W) {}

    T product(usize a,usize b,usize c) const {
        if (m_a[a] > m_a[b])
            std::swap(a,b);
        if (m_a[b] > m_a[c])
            std::swap(b,c);
        if (m_a[a] > m_a[b])
            std::swap(a,b);
        const Zahlen crs = Cross(m_a[b]-m_a[a],m_a[c]-m_a[a]);
        if (crs > 0) {
            T res = S::operation(m_low[a][c],S::inverse(S::operation(m_low[a][b],m_low[b][c])));
            if (m_a[a].x() < m_a[b].x())
                res = S::operation(res,S::inverse(m_onLine[a][b]));
            if (m_a[b].x() < m_a[c].x())
                res = S::operation(res,S::inverse(m_onLine[b][c]));
            if (m_a[a].x() < m_a[b].x() and m_a[b].x() < m_a[c].x())
                res = S::operation(res,S::inverse(m_same[b]));
            return res;
        }
        else if (crs < 0) {
            T res = S::operation(S::operation(m_low[a][b],m_low[b][c]), S::inverse(S::operation(m_low[a][c],m_onLine[a][c])));
            if (m_a[a].x() < m_a[b].x() and m_a[b].x() < m_a[c].x()) 
                res = S::operation(res,S::operation(m_same[b],S::inverse(m_exact[b])));
            return res;
        }
        else
            return S::identity();
    }

    T onLine(usize i,usize j) const {
        return m_onLine[i][j];
    }

    T exact(usize i) const {
        return m_exact[i];
    }

private:

    usize m_n, m_m;

    std::vector<Point> m_a;

    std::vector<T> m_same, m_exact;

    std::vector<std::vector<T>> m_low, m_onLine;


};

} // namespace geometryZ2

} // namespace zawa
