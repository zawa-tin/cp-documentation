#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * Educational Codeforces Round 167 - F Simultaneous Coloring
 * https://codeforces.com/contest/1989/submission/307380988
 */

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp"
#include "../../Src/Graph/Components/IncrementalSCC.hpp"

using namespace zawa;

void solve() {
    SetFastIO();
    int N, M, Q;
    std::cin >> N >> M >> Q;
    IncrementalSCC g(N + M);
    for (int i{} ; i < Q ; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y = y - 1 + N;
        char c;
        std::cin >> c;
        if (c == 'R') {
            g.addEdge(y, x);
        }
        else if (c == 'B') {
            g.addEdge(x, y);
        }
    }
    std::vector<std::vector<std::pair<u32, u32>>> event(Q);
    auto T{g.build()};
    for (int i{} ; i < Q ; i++) {
        if (T.same(i)) {
            event[T[i]].emplace_back(g.getEdge(i));
        }
    }
    DisjointSetUnion dsu(N + M);
    long long cur{};
    auto cost{[&](u32 s) -> long long {
        return s == 1u ? 0 : (long long)s * s;
    }};
    for (int i{} ; i < Q ; i++) {
        for (auto [u, v] : event[i]) {
            if (dsu.same(u, v)) {
                continue;
            }
            cur -= cost(dsu.size(u));
            cur -= cost(dsu.size(v));
            dsu.merge(u, v);
            cur += cost(dsu.size(u));
        }
        std::cout << cur << '\n';
    }
}

int main() {
#ifdef ONLINE_JUDGE
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
