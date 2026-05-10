#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_G"

#include "../../Src/DataStructure/SWAG/SlindingPriority.hpp"
using namespace zawa;

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,W;
    cin >> N >> W;
    const long long INF = -(long long)1e18;
    vector<long long> dp(W+1,INF);
    dp[0] = 0;
    while (N--) {
        int v,w,m;
        cin >> v >> w >> m;
        for (int md = 0 ; md < w ; md++) {
            SlidingPriority<pair<long long,int>,greater<pair<long long,int>>> que;
            for (int i = md,j = 0 ; i <= W ; i += w,j++) {
                if (dp[i] == INF)
                    que.push({INF,j});
                else
                    que.push({dp[i]-(long long)j*v,j});
                while (que.size() and que.top().second < j - m)
                    que.pop();
                if (que.top().first != INF)
                    dp[i] = (long long)j*v+que.top().first;
            }
        }
    }
    cout << *ranges::max_element(dp) << '\n';
}
