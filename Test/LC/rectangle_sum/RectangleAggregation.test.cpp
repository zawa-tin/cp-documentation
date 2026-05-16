#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include "../../../Src/DataStructure/Wavelet/RectangleAggregation.hpp"
using namespace zawa;
#include <iostream>
#include <vector>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,Q;
    cin >> N >> Q;
    vector<pair<int,int>> P(N);
    vector<int> W(N);
    for (int i = 0 ; i < N ; i++)
        cin >> P[i].first >> P[i].second >> W[i];
    RectangleAggregation<int> RA{P};
    vector sum(RA.height(),vector<long long>(RA.width()+1));
    for (int i = 0 ; i < N ; i++)
        for (auto [x,y] : RA.point(i))
            sum[x][y+1] += W[i];
    for (int i = 0 ; i < (int)RA.height() ; i++)
        for (int j = 0 ; j < (int)RA.width() ; j++)
            sum[i][j+1] += sum[i][j];
    while (Q--) {
        int l,d,r,u;
        cin >> l >> d >> r >> u;
        long long ans = 0;
        for (auto [h,L,R] : RA.rectangle(l,d,r,u))
            ans += sum[h][R]-sum[h][L];
        cout << ans << '\n';
    }
}
