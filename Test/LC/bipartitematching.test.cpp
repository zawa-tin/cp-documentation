#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/Dinic.hpp"

#include <iostream>
#include <vector>

int main() {
    using namespace zawa;
    SetFastIO();
    int l, r, m; std::cin >> l >> r >> m;
    Dinic<int> maxflow(l + r + 2, l + r + m);
    for (int i{} ; i < l ; i++) {
        maxflow.addEdge(l + r, i, 1);
    }
    for (int i{} ; i < r ; i++) {
        maxflow.addEdge(l + i, l + r + 1, 1);
    }
    std::vector<int> id(m);
    std::vector<int> A(m), B(m);
    for (int i{} ; i < m ; i++) {
        int a, b; std::cin >> a >> b;
        A[i] = a;
        B[i] = b;
        id[i] = maxflow.addEdge(a, l + b, 1);
    }
    int ans{maxflow.flow(l + r, l + r + 1)};
    std::cout << ans << '\n';
    for (int i{} ; i < m ; i++) {
        if (maxflow.flowed(id[i])) {
            std::cout << A[i] << ' ' << B[i] << '\n';
        }
    }
}
