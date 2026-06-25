#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/3451"
#include "../../Src/GeometryZ2/Contain/TriangleProduct.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
using namespace zawa;
using namespace geometryZ2;
#include <iostream>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    PointCloud P(N);
    vector<long long> W(N);
    for (int i = 0 ; i < N ; i++)
        cin >> P[i] >> W[i];
    TriangleProduct<AdditiveGroup<long long>> cpit{P,W};
    const long long INF = (long long)-1e18;
    auto makeDP = [&](vector<pair<int,int>> ord) -> vector<vector<long long>> {
        vector dp(N,vector<long long>(N,INF));
        for (int i = 0 ; i < N ; i++)
            dp[i][i] = cpit.exact(i).first;
        for (auto [mid,to] : ord) {
            assert(P[mid] != P[to]);
            if (cpit.onLine(mid,to).second)
                continue;
            for (int from = 0 ; from < N ; from++)
                if (dp[from][mid] != INF) {
                    long long add = cpit.product(from,mid,to).first+cpit.onLine(mid,to).first+cpit.exact(to).first;
                    if (Cross(P[mid]-P[from],P[to]-P[mid]))
                        add += cpit.onLine(from,to).first;
                    dp[from][to] = max(dp[from][to],dp[from][mid]+add);
                }
        }
        return dp;
    };
    vector<pair<int,int>> dn,up;
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < N ; j++)
            if (P[i] != P[j]) {
                if (P[i].x() < P[j].x() or (P[i].x() == P[j].x() and P[i].y() < P[j].y()))
                    dn.push_back({i,j});
                else
                    up.push_back({i,j});
            }
    ranges::sort(dn,[&](const auto& i,const auto& j) -> bool {
                Zahlen crs = Cross(P[i.second]-P[i.first],P[j.second]-P[j.first]);
                if (crs)
                    return crs > 0;
                return P[i.first] < P[j.first];
            });
    ranges::sort(up,[&](const auto& i,const auto& j) -> bool {
                Zahlen crs = Cross(P[i.second]-P[i.first],P[j.second]-P[j.first]);
                if (crs)
                    return crs > 0;
                return P[i.first] > P[j.first];
            });
    auto dp = makeDP(dn), ep = makeDP(up);
    long long ans = *ranges::max_element(W);
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < N ; j++)
            if (dp[i][j] != INF)
                ans = max(ans,dp[i][j]+ep[j][i]-cpit.exact(i).first-cpit.exact(j).first-cpit.onLine(i,j).first);
    cout << ans << '\n';
}
