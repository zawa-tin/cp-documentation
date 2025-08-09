#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "../../Src/FPS/FPSNTTFriendly.hpp"

#include <iostream>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    zawa::FPS<998244353> f(N);
    cin >> f;
    cout << f.exp() << '\n';
}
