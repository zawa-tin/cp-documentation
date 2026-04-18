// #define PROBLEM "https://atcoder.jp/contests/abc453/tasks/abc453_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 453 G - Copy Query
 * https://atcoder.jp/contests/abc453/submissions/75029259
 */

#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/DataStructure/SegmentTree/PersistentSegmentTree.hpp"

#include <iostream>
#include <vector>
using namespace std;

int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,M,Q;
    cin >> N >> M >> Q;
    vector<int> P(N);
    zawa::PersistentSegmentTree<zawa::AdditiveGroup<long long>> seg(M);
    while (Q--) {
        int T;
        cin >> T;
        if (T == 1) {
            int x,y;
            cin >> x >> y;
            P[--x] = P[--y];
        }
        else if (T == 2) {
            int x,y,z;
            cin >> x >> y >> z;
            x--; y--;
            P[x] = seg.assign(P[x],y,z);
        }
        else if (T == 3) {
            int x,l,r;
            cin >> x >> l >> r;
            x--; l--;
            cout << seg.product(P[x],l,r) << '\n';
        }
        else
            assert(0);
    }
#else
    cout << "Hello World\n";
#endif
}
