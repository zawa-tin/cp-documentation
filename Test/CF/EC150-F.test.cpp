// #define PROBLEM "https://codeforces.com/contest/1841/problem/F"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * Educational Codeforces Round 150 F. Monocarp and a Strategic Game
 * https://codeforces.com/contest/1841/submission/367948884
 */

#include "../../Src/GeometryZ2/MinkowskiSum.hpp"

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using namespace zawa::geometryZ2;
int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<Polygon> P(N);
    for (int i = 0 ; i < N ; i++) {
        Zahlen a,b,c,d;
        cin >> a >> b >> c >> d;
        P[i].pushBack(Point{0,0});
        P[i].pushBack(Point{a-b,c-d});
    }
    auto rec = [&](auto rec,int l,int r) -> Polygon {
        if (l >= r)
            return Polygon(1);
        if (l + 1 == r)
            return P[l];
        int m = (l + r) / 2;
        return rec(rec,l,m) + rec(rec,m,r);
    };
    auto prod = rec(rec,0,N);
    __int128_t ans = 0;
    for (int i = 0 ; i < ssize(prod) ; i++) {
        Point p = prod[i];
        ans = max(ans,__int128_t(p.x())*p.x()+__int128_t(p.y())*p.y());
    }
    string out;
    while (ans) {
        out += ans%10 + '0';
        ans /= 10;
    }
    if (out.empty())
        out += '0';
    ranges::reverse(out);
    cout << out << '\n';
#else
    cout << "Hello World\n";
#endif
}
