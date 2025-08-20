#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../../Src/Sequence/OfflineRangeProduct.hpp"
#include "../../../Src/Algebra/Monoid/MonoidAction.hpp"

#include <algorithm>
#include <vector>
#include <iostream>

using namespace zawa;
using namespace std;
struct M {
    using Element = int;
    static Element identity() {
        return 2000000000;
    }
    static Element operation(Element L, Element R) {
        return min(L, R);
    }
};
using Monoid = AddSelfAction<M>;
struct query {
    int l, r;
};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0 ; i < N ; i++)
        cin >> a[i];
    vector<query> q(Q);
    for (int i = 0 ; i < Q ; i++) {
        int l, r;
        cin >> l >> r;
        q[i] = {l, r};
    }
    for (int ans : OfflineRangeProduct<Monoid>(a, q))
        cout << ans << '\n';
}
