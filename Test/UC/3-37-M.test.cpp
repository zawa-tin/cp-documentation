// #define PROBLEM "https://contest.ucup.ac/contest/2025/problem/10748"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * The 3rd Universal Cup. Stage 37: Wuhan M. Flight Tracker
 * https://contest.ucup.ac/submission/1067790
 */

#include "../../Src/GeometryR3/Point.hpp"
#include "../../Src/GeometryR3/Plane.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace zawa::geometryR3;
using point = Point<long double>;

long double R;
point P, S, T;

long double CenterAngle(const point& s, const point& t) {
    const long double cosT = 1.0l - DistanceSquare(s, t) / (2 * R * R);
    return acosl(std::clamp(cosT, -1.0l, 1.0l));
}

long double ArcLength(const point& p, const point& q) {
    return R * CenterAngle(p, q);
}

long double solve() {
    P = R * P.normalized(); 
    S = R * S.normalized(); 
    T = R * T.normalized(); 
    const long double theta = CenterAngle(S, T);
    auto ST = [&](long double r) -> point {
        const point n = Plane{S, T}.normalVector();
        return S.rotated(n, theta * r);
    };
    long double l = 0, r = 1;
    for (int t = 0 ; t < 50 ; t++) {
        const long double m1 = (l + l + r) / 3, m2 = (l + r + r) / 3;
        const long double d1 = ArcLength(P, ST(m1)), d2 = ArcLength(P, ST(m2));
        if (d1 <= d2) r = m2;
        else l = m1;
    }
    return ArcLength(P, ST(l));
}

int main() {
#ifdef ONLINE_JUDGE
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int t;
    std::cin >> t;
    std::cout << std::fixed << std::setprecision(7);
    while (t--) {
        std::cin >> R >> P >> S >> T;
        std::cout << solve() << '\n';
    }
#else
    std::cout << "Hello World\n";
#endif
}
