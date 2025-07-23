#define PROBLEM "https://judge.yosupo.jp/problem/rational_approximation"

#include "../../Src/Utility/RationalBinarySearch.hpp"

#include <iostream>
using namespace zawa;
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0); 
    int T;
    cin >> T;
    while (T--) {
        long long N, x, y;
        cin >> N >> x >> y;
        auto f = [&](long long a, long long b) -> bool {
            return a * y <= x * b;
        };
        auto [max_ok, min_ng] = RationalBinarySearch(f, N);
        auto [a, b] = max_ok;
        auto [c, d] = min_ng;
        if (a * y == x * b) {
            cout << a << ' ' << b << ' ' << a << ' ' << b << '\n';
        }
        else {
            cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
        }
    }
}
