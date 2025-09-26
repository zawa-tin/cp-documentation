// #define PROBLEM "https://codeforces.com/contest/2149/problem/G"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * Codeforces Round 1054 (Div. 3) G - Buratsuta 3
 * https://codeforces.com/contest/2149/submission/340565209
 */

#include "../../Src/Sequence/CompressedSequence.hpp"
#include "../../Src/DataStructure/Mo/RollbackMo.hpp"

#include <iostream>
#include <vector>
using namespace std;
using namespace zawa;
struct Query {
    usize l, r;
};
struct Data {
    int top1 = -1, top2 = -1, last_op = -1;
};
void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int& a : A)
        cin >> a;
    vector<Query> q(Q);
    for (auto& [l, r] : q) {
        cin >> l >> r;
        l--;
    }
    CompressedSequence comp{A};
    for (int i = 0 ; i < N ; i++)
        A[i] = comp.map(i);
    vector<int> cnt(ssize(comp));
    auto add = [&](int i, Data d) {
        cnt[A[i]]++; 
        if (d.top1 == A[i])
            ;
        else if (d.top2 == A[i]) {
            if (cnt[d.top1] < cnt[d.top2])
                swap(d.top1, d.top2);
        }
        else if (d.top1 == -1 or cnt[A[i]] > cnt[d.top1]) {
            d.top2 = d.top1;
            d.top1 = A[i];
        }
        else if (d.top2 == -1 or cnt[A[i]] > cnt[d.top2])
            d.top2 = A[i];
        d.last_op = A[i];
        return d;
    };
    auto rollback = [&](const Data& d) {
        cnt[d.last_op]--;
    };
    auto eval = [&](int i, const Data& d) {
        vector<int> res;
        const int len = q[i].r - q[i].l;
        if (d.top1 != -1 and cnt[d.top1] * 3 > len)
            res.push_back(comp.inverse(d.top1));
        if (d.top2 != -1 and cnt[d.top2] * 3 > len)
            res.push_back(comp.inverse(d.top2));
        if (ssize(res) == 2 and res[0] > res[1])
            swap(res[0], res[1]);
        if (res.empty())
            res.push_back(-1);
        return res;
    };
    for (const vector<int>& ans : RollbackMo<Query, Data, decltype(add), decltype(rollback), decltype(eval)>(q, add, add, rollback, eval))
        for (int i = 0 ; i < ssize(ans) ; i++)
            cout << ans[i] << (i + 1 == ssize(ans) ? '\n' : ' ');
}
int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
        solve();
#else
    cout << "Hello World\n";
#endif
}
