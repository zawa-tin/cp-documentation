#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2827"
#define ERROR 0.001

#include "../../Src/GeometryR2/Angle.hpp"
#include "../../Src/GeometryR2/PointCloud.hpp"
#include "../../Src/GeometryR2/Polygon.hpp"
#include "../../Src/GeometryR2/ConvexHull.hpp"
#include "../../Src/GeometryR2/Distance/SegmentAndSegment.hpp"
#include "../../Src/GeometryR2/Contain/ConvexPolygonContainsPoint.hpp"
using namespace zawa::geometryR2;

#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <queue>
int N, NV[100];
Real H[100], THETA, GAMMA;
Polygon P[100];
Point START, GOAL;
bool inner(const Polygon& p, const Polygon& q) {
    for (int i = 0 ; i < std::ssize(p) ; i++) if (ConvexPolygonContainsPoint(q, p[i]) == OUTSIDE) return false;
    return true;
}
Real Distance(const Polygon& p, const Polygon& q) {
    if (inner(p, q) or inner(q, p)) return 0;
    Real res = 1e18l;
    for (int i = 0 ; i < std::ssize(p) ; i++) for (int j = 0 ; j < std::ssize(q) ; j++) {
        res = std::min(res, Distance(Segment{p[i], p[i+1==std::ssize(p)?0:i+1]},
                    Segment{q[j], q[j+1==std::ssize(q)?0:j+1]}));
    }
    return res;
}
Real NaiveDistance(const Polygon& poly, const Point& p) {
    if (ConvexPolygonContainsPoint(poly, p) != OUTSIDE) {
        return 0;
    }
    else {
        Real res = 1e18l;
        for (int i = 0 ; i < std::ssize(poly) ; i++) {
            res = std::min(res, Distance(p, Segment{poly[i], poly[i+1==std::ssize(poly)?0:i+1]}));
        }
        return res;
    }
}
Real solve() {
    std::vector<Polygon> hulls = [&]() {
        std::vector<PointCloud> pcs(N);
        std::vector<Polygon> res(N);
        for (int i = 0 ; i < N ; i++) {
            const Real shadow_len = H[i] * cosl(GAMMA) / sinl(GAMMA);
            for (int j = 0 ; j < NV[i] ; j++) {
                pcs[i].push_back(P[i][j]);
                pcs[i].push_back(P[i][j] - shadow_len * Point{cosl(THETA), sinl(THETA)});
            }
            res[i] = ConvexHull<true>(pcs[i]);
            assert(std::ssize(res[i]) >= 3);
            res[i].normalForm();
        }
        return res;
    }();
    const int n = N + 2, st = N, go = N + 1;
    std::vector g(n, std::vector<Real>(n));
    for (int i = 0 ; i < N ; i++) {
        const Real w = NaiveDistance(hulls[i], START);
        g[st][i] = g[i][st] = w;
    }
    for (int i = 0 ; i < N ; i++) {
        const Real w = NaiveDistance(hulls[i], GOAL);
        g[go][i] = g[i][go] = w;
    }
    g[st][go] = g[go][st] = Distance(START, GOAL);
    for (int i = 0 ; i < N ; i++) {
        for (int j = i + 1 ; j < N ; j++) {
            g[i][j] = g[j][i] = Distance(hulls[i], hulls[j]);
        }
    }
    std::vector<Real> dist(n, 1e18l);
    using qt = std::pair<Real, int>;
    std::priority_queue<qt, std::vector<qt>, std::greater<qt>> que;
    dist[st] = 0;
    que.push({dist[st], st});
    // for (int i = 0 ; i < n ; i++) {
    //     for (int j = 0 ; j < n ; j++) std::cout << g[i][j] << ' ';
    //     std::cout << std::endl;
    // }
    while (que.size()) {
        auto [d, v] = que.top();
        que.pop();
        if (Bigger(d, dist[v])) continue;
        for (int i = 0 ; i < n ; i++) if (Smaller(d + g[v][i], dist[i])) {
            dist[i] = d + g[v][i];
            que.push({dist[i], i});
        }
    }
    return dist[go];
}
int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(5);
    while (true) {
        std::cin >> N;
        if (N == 0) break;
        for (int i = 0 ; i < N ; i++) {
            std::cin >> NV[i] >> H[i];
            Polygon p(NV[i]);
            for (int j = 0 ; j < NV[i] ; j++) std::cin >> p[j].x() >> p[j].y();
            P[i] = std::move(p);
        }
        std::cin >> THETA >> GAMMA;
        THETA = ArcToRadian(THETA);
        GAMMA = ArcToRadian(GAMMA);
        std::cin >> START.x() >> START.y() >> GOAL.x() >> GOAL.y();
        std::cout << solve() << '\n';
    }
}
