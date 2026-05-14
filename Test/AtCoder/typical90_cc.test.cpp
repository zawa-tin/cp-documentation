// #define PROBLEM "https://atcoder.jp/contests/typical90/tasks/typical90_cc"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

/*
 * 競プロ典型90問 081 - Griendly Group
 * https://atcoder.jp/contests/typical90/submissions/75777786
 */

#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/DataStructure/PrefixSum/PrefixSum2D.hpp"
using namespace zawa;

#include <iostream>
#include <vector>
using namespace std;

int main() {
#ifdef ATCODER
    int N,K;
    cin >> N >> K;
    vector A(5001,vector<int>(5001));
    while (N--) {
        int a,b;
        cin >> a >> b;
        A[a][b]++;
    }
    auto sum = BuildRuisekiwa2D<AdditiveGroup<int>>(move(A));
    int ans = 0;
    for (int i = 0 ; i + K + 1 <= 5001 ; i++)
        for (int j = 0 ; j + K + 1 <= 5001 ; j++)
            ans = max(ans,sum.product(i,j,i+K+1,j+K+1));
    cout << ans << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
