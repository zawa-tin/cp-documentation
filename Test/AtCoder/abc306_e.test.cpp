// #define PROBLEM "https://atcoder.jp/contests/abc306/tasks/abc306_e"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 306 E - Best Performances
 * https://atcoder.jp/contests/abc306/submissions/72450475
 */

#include "../../Src/DataStructure/Heap/PartitionedProducts.hpp"
using namespace zawa;

#include <iostream>
using namespace std;
struct OP {
    using Element = long long;
    static Element identity() {
        return 0;
    }
    static void add(Element& v, Element x) {
        v += x;
    }
    static void remove(Element& v, Element x) {
        v -= x;
    }
};
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    PartitionedProducts<OP, int> que(A);
    while (Q--) {
        int t, x;
        cin >> t >> x;
        t--;
        que.erase(A[t]);
        A[t] = x;
        que.insert(A[t]);
        assert(que.adjustBig(K));
        cout << que.bigProd() << '\n';
    }
#else
    cout << "Hello World\n";
#endif
}
