#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2201"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryR2/Real.hpp"
#include "../../Src/GeometryR2/Point.hpp"
#include "../../Src/GeometryR2/Line.hpp"
#include "../../Src/GeometryR2/Circle.hpp"
#include "../../Src/GeometryR2/Distance/LineAndPoint.hpp"
#include "../../Src/GeometryR2/Tangent/CommonTangentBetweenCircles.hpp"

#include <iostream>

using namespace zawa;
using namespace geometryR2;

bool solve() {
    int N;
    std::cin >> N;
    if (N == 0) return false;
    std::vector<Point> P(N);
    std::vector<Real> R(N), M(N);
    for (int i{} ; i < N ; i++) {
        std::cin >> P[i] >> R[i] >> M[i];
    }
    auto check{[&](const Line& L) -> int {
        int res{};
        for (int i{} ; i < N ; i++) {
            Real d{Distance(L, P[i])};
            if (Smaller(d, R[i])) continue;
            if (Bigger(d, R[i] + M[i])) continue;
            res++;
        }
        return res;
    }};
    int ans{1};
    for (int i{} ; i < N ; i++) {
        for (int j{i + 1} ; j < N ; j++) {
            for (int bit{} ; bit < 4 ; bit++) {
                Circle lhs{P[i], R[i] + ((bit & (1 << 0)) ? M[i] : Real{})};
                Circle rhs{P[j], R[j] + ((bit & (1 << 1)) ? M[j] : Real{})};
                for (const Line& L : CommonTangentBetweenCircles(lhs, rhs)) {
                    ans = std::max(ans, check(L));
                }
            }
        }
    }
    std::cout << ans << '\n';
    return true;
}

int main() {
    SetFastIO();
    while (solve()) ;
}
