#define PROBLEM "https://atcoder.jp/contests/abc339/tasks/abc339_g"

/*
 * AtCoder Beginner Contest 339 G - Smaller Sum
 * https://atcoder.jp/contests/abc339/submissions/75810058
 */

#include "../../Src/DataStructure/Wavelet/RangeAggregation.hpp"
using namespace zawa;
#include <iostream>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& x : A)
        cin >> x;
    RangeAggregation<int> RA{A}; 
    vector sum(RA.height(),vector<long long>(N+1));
    for (int i = 0 ; i < N ; i++) {
        for (auto [x,y] : RA.point(i))
            sum[x][y+1] += A[i];
    }
    for (int i = 0 ; i < (int)RA.height() ; i++)
        for (int j = 0 ; j < N ; j++)
            sum[i][j+1] += sum[i][j];
    int Q;
    cin >> Q;
    long long B = 0;
    while (Q--) {
        long long al,be,ga;
        cin >> al >> be >> ga;
        al ^= B;
        be ^= B;
        ga ^= B;
        al--;
        long long ans = 0;
        for (auto [h,l,r] : RA.rectangle(al,0,be,ga+1))
            ans += sum[h][r]-sum[h][l];
        cout << ans << '\n';
        B = ans;
    }
}
