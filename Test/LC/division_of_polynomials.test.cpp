#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include "../../Src/FPS/DivisionOfPolynomials.hpp"
using namespace zawa;
using fps = FPSNTTFriendly<998244353>;

#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    fps f(N), g(M);
    for (int i = 0 ; i < N ; i++) {
        int a;
        cin >> a;
        f[i] = a;
    }
    for (int i = 0 ; i < M ; i++) {
        int a;
        cin >> a;
        g[i] = a;
    }
    auto [q, r] = DivisionOfPolynomials(f, g);
    cout << q.size() << ' ' << r.size() << '\n';
    cout << q << '\n';
    cout << r << '\n';
}
