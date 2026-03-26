// #define PROBLEM "https://atcoder.jp/contests/awc0032/tasks/awc0032_e"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Weekday Contest 0032 Beta E - Multiple Bonus
 * https://atcoder.jp/contests/awc0032/submissions/74415255
 */

#include "../../Src/DataStructure/Bucket/BucketRangeProduct.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
using namespace zawa;

#include <cassert>
#include <iostream>
using namespace std;

int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,Q;
    cin >> N >> Q;
    std::vector<long long> A(N);
    for (long long& a : A)
        cin >> a;
    BucketRangeQuery<AdditiveGroup<long long>> buc(A);
    const int sz = buc.bucketSize();
    vector<long long> add(sz);
    while (Q--) {
        int T;
        cin >> T;
        if (T == 1) {
            int k,v;
            cin >> k >> v;
            if (k < sz)
                add[k] += v;
            else
                for (int i = k ; i <= N ; i += k)
                    buc.operation(i-1,v);
        }
        else if (T == 2) {
            int r;
            cin >> r;
            long long ans = buc.product(0,r);
            for (int i = 1 ; i < sz ; i++)
                ans += add[i] * (r/i);
            cout << ans << '\n';
        }
        else
            assert(0);
    }
#else
    cout << "Hello World\n";
#endif
}
