// #define PROBLEM "https://contest.ucup.ac/contest/2693/problem/15032"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#include "../../Src/Number/DiscreteLogarithmPrimeLift.hpp"
using namespace zawa;

/*
 * GP of Jinan A. Cipher
 * https://contest.ucup.ac/submission/1997925
 */

#include <iostream>
using namespace std;

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        unsigned long long a, b;
        cin >> a >> b;
        auto ans = DiscreteLogarithmPrimeLift(a, b, 2, 64);
        if (ans.has_value())
            cout << ans.value() << '\n';
        else
            cout << "broken message\n";
    }
#else
    cout << "Hello World\n";
#endif
}
