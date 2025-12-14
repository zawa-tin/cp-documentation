// #define PROBLEM "https://codeforces.com/contest/2176/problem/F"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Number/LinearSieve.hpp"
#include "../../Src/Utility/GreyCode.hpp"
#include "atcoder/modint"
using mint = atcoder::modint998244353;
#include <array>
#include <iostream>
using namespace std;
using namespace zawa;
const int MAX = 11;
using Item = array<long long, MAX>;
Item zero() {
    Item res;
    res.fill(0);
    return res;
}
struct PD {
    using Element = int;
    static Element identity() {
        return 1;
    }
    static Element add(Element a, Element b) {
        return a * b;
    }
    static Element remove(Element a, Element b) {
        return a / b;
    }
};
void solve() {
    int N, K;
    cin >> N >> K;
    LinearSieve siv(N);
    vector<Item> cnt(N + 1, zero());
    Item ans = zero();
    auto primes = [&](int a) -> vector<int> {
        vector<int> res;
        for (auto d : siv.factorize(a))
            res.push_back(d.factor());
        return res;
    };
    auto calc = [&](int a) {
        vector<int> p = primes(a);
        vector<int> d = EnumerateSubsetProduct<PD>(p);
        vector<Item> cur(1 << ssize(p));
        for (int b = 0 ; b < (1 << ssize(p)) ; b++)
            cur[b] = cnt[d[b]];
        for (int i = 0 ; i < ssize(p) ; i++)
            for (int b = 0 ; b < (1 << ssize(p)) ; b++)
                if (b & (1 << i))
                    for (int j = 0 ; j < MAX ; j++)
                        cur[b ^ (1 << i)][j] -= cur[b][j];
        for (int b = 0 ; b < (1 << ssize(p)) ; b++)
            for (int i = 0 ; i < MAX ; i++) {
                int key = i + ssize(p) - popcount<unsigned>(b);
                if (0 <= key and key < MAX)
                    ans[key] += cur[b][i];
            }
    };
    auto add = [&](int a) {
        vector<int> p = primes(a);
        int m = 1;
        for (int i = 0 ; i < ssize(p) ; i++)
            m *= p[i];
        for (int d : siv.divisor(m))
            cnt[d][p.size()]++;
    };
    for (int i = 0 ; i < N ; i++) {
        int a;
        cin >> a;
        calc(a);
        add(a);
    }
    mint res = 0;
    for (int i = 0 ; i < MAX ; i++)
        res += mint::raw(i).pow(K) * ans[i];
    cout << res.val() << '\n';
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
