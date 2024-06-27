#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2334"
#define ERROR 0.000000001

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryR2/Point.hpp"
#include "../../Src/GeometryR2/Segment.hpp"
#include "../../Src/GeometryR2/Intersect/SegmentAndSegment.hpp"

#include <iostream>
#include <queue>

using namespace zawa;
using namespace geometryR2;

const Real INF{9e18};

Real solve(int N, const std::vector<Point>& P, const Segment& S) {
    std::vector<std::vector<std::pair<int, Real>>> g(N);
    for (int i{} ; i < N ; i++) {
        for (int j{} ; j < N ; j++) {
            if (i == j) continue;
            Segment cur{P[i], P[j]};
            if (Intersect(cur, S)) continue;
            g[i].emplace_back(j, cur.length());
        }
    }
    std::vector<Real> dist(N, INF);
    using qt = std::pair<Real, int>;
    std::priority_queue<qt, std::vector<qt>, std::greater<qt>> que;
    dist[0] = 0;
    que.emplace(dist[0], 0);
    while (que.size()) {
        auto [d, v]{que.top()};
        que.pop();
        if (Smaller(dist[v], d)) continue;
        for (auto [x, w] : g[v]) {
            if (Smaller(dist[v] + w, dist[x])) {
                dist[x] = dist[v] + w;
                que.emplace(dist[x], x);
            }
        }
    }
    return dist[1] + S.length();
}

int main() {
    SetFastIO();
    int NA, NB;
    std::cin >> NA >> NB;
    std::vector<Point> A(NA), B(NB);
    for (auto& a : A) std::cin >> a;
    for (auto& b : B) std::cin >> b;
    Real ans{std::min(
            solve(NA, A, Segment{B[0], B[1]}),
            solve(NB, B, Segment{A[0], A[1]})
            )};
    SetPrecision(10);
    if (Smaller(ans, INF)) {
        std::cout << ans << '\n';
    }
    else {
        std::cout << -1 << '\n';
    }
}
