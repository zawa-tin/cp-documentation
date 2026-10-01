#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"
#include "../../Src/Combinatorics/StirlingNumberSecondKindFixedN.hpp"
#include <iostream>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    auto ans=zawa::StirlingNumberSecondKindFixedN<998244353>(N);
    for (int i=0 ; i <= N ; i++)
        cout << ans[i].val() << (i==N?'\n':' ');
}
