#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
// #define PROBLEM "https://atcoder.jp/contests/abc434/tasks/abc434_d"

/*
 * AtCoder Beginner Contest 434 D - Clouds
 * https://atcoder.jp/contests/abc434/submissions/71356471
 */

#include "../../Src/DataStructure/PrefixSum/PrefixSum2D.hpp"
#include "../../Src/DataStructure/PrefixSum/Imos2D.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using namespace zawa;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
#ifdef ATCODER
    const int MAX = 2000;
    int N;
    cin >> N;
    Imos2D<AdditiveGroup<int>> imos(MAX, MAX);
    vector<tuple<int, int, int, int>> A(N);
    for (auto& [l, r, d, u] : A) {
        cin >> l >> r >> d >> u;
        l--;
        d--;
        imos.operation(l, d, r, u, 1);
    }
    auto a = imos.build();
    Ruisekiwa2D<AdditiveGroup<int>> sum(MAX, MAX);
    int base = 0;
    for (int i = 0 ; i < MAX ; i++)
        for (int j = 0 ; j < MAX ; j++) {
            if (a[i][j] == 0)
                base++;
            else if (a[i][j] == 1)
                sum.operation(i, j, 1);
        }
    auto solver = sum.build();
    for (auto [l, r, d, u] : A) {
        int ans = base + solver.product(l, d, r, u);
        cout << ans << '\n';
    }
#else
    cout << "Hello World\n";
#endif
}
