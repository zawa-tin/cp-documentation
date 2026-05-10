// #define PROBLEM "https://atcoder.jp/contests/abc269/tasks/abc269_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 269 G - Reversible Cards 2
 * https://atcoder.jp/contests/abc269/submissions/75694189
 */

#include "../../Src/DataStructure/SWAG/SlindingPriority.hpp"
using namespace zawa;

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
#ifdef ATCODER
    int N,M;
    cin >> N >> M;
    int base = 0;
    vector<int> cnt(2*M+1);
    for (int i = 0 ; i < N ; i++) {
        int A,B;
        cin >> A >> B;
        base += A;
        cnt[B-A+M]++;
    }
    const int INF = (int)1e9;
    vector<int> dp(M+1,INF);
    dp[base] = 0;
    for (int w = -M ; w <= M ; w++)
        if (w and cnt[w+M] > 0) {
            for (int md = 0 ; md < abs(w) ; md++) {
                SlidingPriority<pair<int,int>> que;
                std::vector<int> idxs;
                for (int i = md ; i <= M ; i += abs(w))
                    idxs.push_back(i);
                if (w < 0)
                    ranges::reverse(idxs);
                int j = 0;
                for (int i : idxs) {
                    que.push({min(dp[i]-j,INF),j});
                    while (que.size() and que.top().second < j-cnt[w+M])
                        que.pop();
                    if (que.top().first != INF)
                        dp[i] = que.top().first+j;
                    j++;
                }
            }
        }
    for (int i = 0 ; i <= M ; i++)
        cout << (dp[i] == INF ? -1 : dp[i]) << '\n';
#else
    cout << "Hello World\n";
#endif
}
