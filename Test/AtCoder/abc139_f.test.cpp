// #define PROBLEM "https://atcoder.jp/contests/abc139/tasks/abc139_f"
// #define ERROR 0.0000000001
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Geginner Contest 139 F - Engines
 * https://atcoder.jp/contests/abc139/submissions/74363469
 */

#include "../../Src/GeometryZ2/MinkowskiSum.hpp"

#include <algorithm>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
#ifdef ATCODER
    using namespace zawa;
    using namespace geometryZ2;
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<Polygon> P(N);
    for (int i = 0 ; i < N ; i++) {
        P[i].pushBack(Point{0,0});
        Point p;
        cin >> p;
        P[i].pushBack(p);
    }
    auto rec = [&](auto rec,int l,int r) -> Polygon {
        if (l >= r)
            return Polygon(1);
        if (l + 1 == r)
            return P[l];
        return rec(rec,l,(l+r)/2)+rec(rec,(l+r)/2,r);
    };
    auto prod = rec(rec,0,N);
    Zahlen ans = 0;
    for (int i = 0 ; i < ssize(prod) ; i++)
        ans = max(ans,prod[i].normSquare());
    cout << fixed << setprecision(12) << sqrtl(ans) << '\n';
#else
    std::cout << "Hello World\n";
#endif
}
