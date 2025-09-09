// #define PROBLEM "https://atcoder.jp/contests/abc422/tasks/abc422_e"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 422 E - Colinear
 * https://atcoder.jp/contests/jsc2025advance-final/submissions/69185007
 */

#include "../../Src/GeometryZ2/Contain/LineContainsPoint.hpp"
using namespace zawa::geometryZ2;
using namespace std;

#include <iostream>
#include <random>

int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<Point> P(N);
    for (auto& p : P)
        cin >> p;
    mt19937 mt{random_device{}()};
    for (int _ = 0 ; _ < 100 ; _++) {
        int p = 0, q = 0;
        while (p == q) {
            p = mt() % N;
            q = mt() % N;
        }
        Line l{P[p], P[q]};
        int cnt = 0;
        for (const Point& v : P)
            cnt += LineContainsPoint(l, v) == ONLINE;
        if (2 * cnt > N) {
            auto [a, b, c] = l.normalForm();
            cout << "Yes\n" << a << ' ' << b << ' ' << c << '\n';
            return 0;
        }
    }
    cout << "No\n";
#else
    cout << "Hello World\n";
#endif
}
