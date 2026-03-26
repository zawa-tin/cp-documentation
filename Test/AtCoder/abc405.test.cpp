// #define PROBLEM "https://atcoder.jp/contests/abc405/tasks/abc405_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 405 G - Range Shuffle Query
 * https://atcoder.jp/contests/abc405/submissions/74415794
 */

#include "../../Src/DataStructure/Bucket/BucketRangeProduct.hpp"
#include "../../Src/Sequence/MoRangeQuery.hpp"
using namespace zawa;

#include "atcoder/modint"
using mint = atcoder::modint998244353;
#include <cassert>
#include <iostream>
using namespace std;
mint F[300000],invF[300000];
struct M {
    using Element = pair<int,mint>;
    static Element identity() {
        return {0,mint::raw(1)};
    }
    static Element operation(Element L,Element R) {
        return {L.first+R.first,L.second*R.second};
    }
    static Element inverse(Element v) {
        return {-v.first,invF[v.first]};
    }
};
int main() {
#ifdef ATCODER
    int N,Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto& x : A)
        cin >> x;
    F[0] = 1;
    for (int i = 1 ; i <= N ; i++)
        F[i] = F[i - 1] * mint::raw(i);
    invF[N] = F[N].inv();
    for (int i = N ; i >= 1 ; i--)
        invF[i - 1] = invF[i] * mint::raw(i);
    vector<pair<int,int>> LR(Q);
    vector<int> X(Q);
    for (int i = 0 ; i < Q ; i++) {
        cin >> LR[i].first >> LR[i].second >> X[i];
        LR[i].first--;
    }
    BucketRangeQuery<M> buc(N+1,500);
    vector<int> cnt(N+1);
    auto add = [&](int i) {
        cnt[A[i]]++;
        buc.assign(A[i],{cnt[A[i]],F[cnt[A[i]]]});
    };
    auto del = [&](int i) {
        cnt[A[i]]--;
        buc.assign(A[i],{cnt[A[i]],F[cnt[A[i]]]});
    };
    auto eval = [&](int i) -> mint {
        auto [num,inv] = buc.product(0,X[i]);
        return F[num] * inv.inv();
    };
    auto ans = Mo(LR,add,add,del,del,eval);
    for (auto a : ans)
        cout << a.val() << '\n';
#else
    cout << "Hello World\n";
#endif
}
