#define PROBLEM "https://atcoder.jp/contests/abc318/tasks/abc318_g"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/Dinic.hpp"

#include <cassert>
#include <iostream>

int main() {
    using namespace zawa;
    SetFastIO();
    int n, m; std::cin >> n >> m;
    int a, b, c; std::cin >> a >> b >> c;
    a--; b--; c--;
    Dinic<int> mf(2 * n + 2, 2 + n + 2 * m);
    for (int i{} ; i < n ; i++) {
        mf.addEdge(i, i + n, (i == b ? 2 : 1));
    }
    for (int _{} ; _ < m ; _++) {
        int u, v; std::cin >> u >> v;
        u--; v--;
        mf.addEdge(n + u, v, 1);
        mf.addEdge(n + v, u, 1);
    }
    int s{2 * n}, t{s + 1};
    mf.addEdge(s, b, 2);
    mf.addEdge(n + a, t, 1);
    mf.addEdge(n + c, t, 1);
    int flow{mf.flow(s, t)};
    assert(flow == 1 or flow == 2);
    bool ans{flow == 2};
    std::cout << (ans ? "Yes" : "No") << '\n';
}
