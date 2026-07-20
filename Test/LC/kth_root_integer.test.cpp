#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"
#include "../../Src/Number/KthRoot.hpp"
#include <iostream>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        unsigned long long a,k;
        cin >> a >> k;
        cout << zawa::KthRoot(a,k) << '\n';
    }
}
