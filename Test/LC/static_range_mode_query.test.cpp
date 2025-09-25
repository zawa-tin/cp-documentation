#define PROBLEM "https://judge.yosupo.jp/problem/static_range_mode_query"

#include "../../Src/DataStructure/Mo/RollbackMo.hpp"
#include "../../Src/Sequence/CompressedSequence.hpp"

#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using namespace zawa;
struct Query {
    usize l, r;
};
struct Data {
    int top = -1, last = -1;
};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0 ; i < N ; i++)
        cin >> A[i];
    CompressedSequence<int> comp{A};
    for (int i = 0 ; i < N ; i++)
        A[i] = comp.map(i);
    vector<Query> q(Q);
    for (auto& [l, r] : q)
        cin >> l >> r;
    vector<int> cnt(ssize(comp));
    auto add = [&](int i, Data d) {
        cnt[A[i]]++;
        if (d.top == -1 or cnt[A[i]] > cnt[d.top])
            d.top = A[i];
        d.last = A[i];
        return d;
    };
    auto rollback = [&](const Data& d) {
        cnt[d.last]--;
    };
    auto eval = [&](int, const Data& d) -> pair<int, int> {
        return {comp.inverse(d.top), cnt[d.top]};
    };
    for (auto [a, b] : RollbackMo<Query, Data, decltype(add), decltype(rollback), decltype(eval)>(q, add, add, rollback, eval))
        cout << a << ' ' << b << '\n';
}
