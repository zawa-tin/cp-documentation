#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/Dinic.hpp"

/*
 * ABC239-G Builder Takahashi
 * https://atcoder.jp/contests/abc239/submissions/48902677
 */

void solve() {
    using namespace zawa;
    SetFastIO();
    int n, m; std::cin >> n >> m;
    Dinic<long long> maxflow(2 * n);
    const long long INF{(long long)1e18};
    for (int _{} ; _ < m ; _++) {
        int a, b; std::cin >> a >> b;
        a--; b--;
        maxflow.addEdge(n + a, b, INF);
        maxflow.addEdge(n + b, a, INF);
    }
    std::vector<u32> id(n);
    for (int i{} ; i < n ; i++) {
        int c; std::cin >> c;
        id[i] = maxflow.addEdge(i, i + n, c);
        assert((int)id[i] == m + m + i);
    }
    long long ans{maxflow.flow(n, n - 1)};
    std::cout << ans << '\n';
    auto cut{maxflow.cut(n)};
    std::vector<int> recover;
    for (int i{1} ; i < n - 1 ; i++) {
        if (cut[i] and !cut[i + n]) recover.push_back(i);
    }
    std::cout << recover.size() << '\n';
    for (int i{} ; i < (int)recover.size() ; i++) {
        std::cout << recover[i] + 1 << (i + 1 == (int)recover.size() ? '\n' : ' ');
    }
}

int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
