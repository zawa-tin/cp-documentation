// #define PROBLEM "https://atcoder.jp/contests/arc197/tasks/arc197_c"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Regular Contest 197 (Div. 2) C - Removal of Multiples
 * https://atcoder.jp/contests/arc197/submissions/74416251
 */

#include "../../Src/DataStructure/Bucket/BucketRangeProduct.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
using namespace zawa;

#include <iostream>
using namespace std;

int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int Q;
    cin >> Q;
    const int MAX = 3000000;
    vector<bool> del(MAX);
    const int B = 2500;
    BucketRangeQuery<AdditiveGroup<int>> buc(vector<int>(MAX,1),B);
    while (Q--) {
        int A,B;
        cin >> A >> B;
        if (A < MAX and !del[A]) {
            for (int i = 1 ; i * A < MAX ; i++)
                if (!del[A*i]) {
                    del[A*i] = 1;
                    buc.operation(A*i,-1);
                }
        }
        cout << buc.maxRight(1,[&](int v) { return v < B; }) << '\n';
    }
#else
    cout << "Hello World\n";
#endif
}
