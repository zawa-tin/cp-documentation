// #define PROBLEM "https://contest.ucup.ac/contest/2021/problem/10728"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * The 3rd Universal Cup. Stage 36: Wulin F. Challenge NPC III
 * https://contest.ucup.ac/submission/1046445
 */

#include "../../Src/Utility/SeparatedFamilySet.hpp"

#include <iostream>
#include <vector>
int N, M, K, C[100010];
std::vector<int> g[100010];
int solve() {
    std::vector<std::vector<int>> col(50);
    for (int i = 0 ; i < N ; i++) col[C[i]].push_back(i);
    for (int t = 0 ; t < 50 ; t++) {
        for (const std::vector<bool>& s : zawa::SeparatedFamilySet(col[t].size())) {
            const int INF = (int)1e9;
            std::vector<int> que, dist(N, INF);
            for (int i = 0 ; i < std::ssize(col[t]) ; i++) if (s[i]) {
                dist[col[t][i]] = 0;
                que.push_back(col[t][i]);
            }
            for (int qt = 0 ; qt < std::ssize(que) ; qt++) {
                const int v = que[qt];
                for (int x : g[v]) if (dist[x] == INF) {
                    dist[x] = dist[v] + 1;
                    que.push_back(x);
                }
            }
            int min = INF;
            for (int i = 0 ; i < std::ssize(col[t]) ; i++) if (!s[i]) {
                min = std::min(min, dist[col[t][i]]);
            }
            if (min + 1 <= K) return false;
        } 
    }
    return true;
}
int main() {
#ifdef ONLINE_JUDGE
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> N >> M >> K;
        for (int i = 0 ; i < N ; i++) {
            std::cin >> C[i];
            C[i]--;
        }
        for (int i = 0 ; i < N ; i++) g[i].clear();
        for (int i = 0 ; i < M ; i++) {
            int u, v;
            std::cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
        }
        std::cout << (solve() ? "YES\n" : "NO\n");
    }
#else
    std::cout << "Hello World\n";
#endif
}
