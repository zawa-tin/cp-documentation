#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
// #define PROBLEM "https://codeforces.com/contest/2014/problem/H"

/*
 * Codeforces Round 974 (Div. 3) H. Robin Hood Archery
 * https://codeforces.com/contest/2014/submission/315528073
 */

#include "../../Src/DataStructure/Mo/Mo.hpp"

#include <iostream>
#include <vector>
int N, Q, A[200020], cnt[1000010];
struct query {
    unsigned l, r;
};
using namespace zawa;
void solve() {
    std::cin >> N >> Q;
    for (int i = 0 ; i < N ; i++) std::cin >> A[i];
    std::vector<query> q(Q);
    for (int i = 0 ; i < Q ; i++) {
        std::cin >> q[i].l >> q[i].r;
        q[i].l--;
    }
    int odd = 0;
    auto op = [&](int i) {
        cnt[A[i]] ^= 1;
        odd += (cnt[A[i]] ? 1 : -1);
    };
    auto eval = [&](int) -> bool {
        return odd == 0;
    };
    for (bool ans : Mo(q, op, op, op, op, eval, true)) std::cout << (ans ? "YES\n" : "NO\n");
}

int main() {
#ifdef ONLINE_JUDGE
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) solve();
#else
    std::cout << "Hello World\n";
#endif
}
