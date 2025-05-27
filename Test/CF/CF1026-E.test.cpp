// #define PROBLEM "https://codeforces.com/contest/2110/problem/E"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Sequence/CompressedSequence.hpp"
#include "../../Src/Graph/EulerianTrail.hpp"
using namespace zawa;

#include <iostream>
#include <utility>
#include <vector>

void solve() {
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> E(N);
    std::vector<int> app;
    for (auto& [u, v] : E) {
        std::cin >> u >> v;
        app.push_back(u);
        app.push_back(v);
    }
    CompressedSequence comp{app};
    std::vector<std::pair<int, int>> edge(N);
    for (int i = 0 ; i < N ; i++) {
        edge[i].first = comp[E[i].first];
        edge[i].second = comp.size() + comp[E[i].second];
    }
    auto ans = EulerianTrail(2 * comp.size(), edge, false);
    if (ans) {
        std::cout << "YES\n";
        auto es = std::move(ans->second);
        for (int i = 0 ; i < N ; i++) std::cout << es[i] + 1 << (i + 1 == N ? '\n' : ' ');
    }
    else {
        std::cout << "NO\n";
    }
}

int main() {
#ifdef ONLINE_JUDGE
    int T;
    std::cin >> T;
    while (T--) solve();
#else
    std::cout << "Hello World\n";
#endif
}
