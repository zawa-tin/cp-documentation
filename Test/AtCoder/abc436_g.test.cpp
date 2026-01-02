// #define PROBLEM "https://atcoder.jp/contests/abc436/tasks/abc436_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 436 G - Linear Inequation
 * https://atcoder.jp/contests/abc436/submissions/72141699
 */

#include "../../Src/FPS/BostanMori.hpp"
using namespace zawa;
using mint = atcoder::modint998244353;
using fps = FPSNTTFriendly<mint::mod()>;

#include <iostream>
using namespace std;

int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    long long M;
    cin >> N >> M;
    fps Q{1, -1};
    while (N--) {
        int a;
        cin >> a;
        fps f(a + 1);
        f[0] = 1;
        f[a] = -1;
        Q *= f;
    }
    cout << BostanMori(M, fps{1}, Q).val() << '\n';
#else
    cout << "Hello World\n";
#endif
}
