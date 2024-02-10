#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Components/Lowlink.hpp"

using namespace zawa;

int main() {
    SetFastIO();
    int n, m; std::cin >> n >> m;
    Lowlink g(n);
    for (int _{} ; _ < m ; _++) {
        int s, t; std::cin >> s >> t;
        g.addEdge(s, t);
    }
    g.build();
    for (int i{} ; i < n ; i++) {
        if (g.articular(i)) {
            std::cout << i << '\n';
        }
    }
}
