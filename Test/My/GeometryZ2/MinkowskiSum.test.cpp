#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../../Src/GeometryZ2/MinkowskiSum.hpp"

#include <iostream>
#include <cassert>
#include <vector>
#include <random>
using namespace std;
using namespace zawa::geometryZ2;

int main() {
    vector<Polygon> P(20);
    for (int i = 0 ; i < 20 ; i++)
        P[i].pushBack(Point{0,0});
    mt19937 mt{random_device{}()};
    for (int i = 0 ; i < 100 ; i++) {
        if (mt() % 2 == 0) {
            int j = mt() % 20;
            Point a,b;
            while (a == b) {
                a.x() = mt() % 21 - 10;
                a.y() = mt() % 21 - 10;
                b.x() = mt() % 21 - 10;
                b.y() = mt() % 21 - 10;
            }
            Polygon cur;
            cur.pushBack(a);
            cur.pushBack(b);
            P[j] = P[j] + cur;
            if (ssize(P[j]) >= 3) {
                bool ok = P[j].isConvex();
                for (int k = 0 ; k < ssize(P[j]) ; k++)
                    ok &= P[j][k] != P[j][(k+1)%ssize(P[j])];
                if (!ok) {
                    cout << P[j] << endl;
                    assert(0);
                }
            }
        }
        else {
            int j = mt() % 20, k = mt() % 20;
            P[j] = P[j] + P[k];
            if (ssize(P[j]) >= 3) {
                bool ok = P[j].isConvex();
                for (int k = 0 ; k < ssize(P[j]) ; k++)
                    ok &= P[j][k] != P[j][(k+1)%ssize(P[j])];
                if (!ok) {
                    cout << P[j] << endl;
                    assert(0);
                }
            }
        }
    }
    cout << "Hello World\n";
}
