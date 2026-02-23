// #define PROBLEM "https://yukicoder.me/problems/no/3189"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * yukicoder No.3189 Semifinal Stage
 * https://yukicoder.me/submissions/1149147
 */

#include "../../Src/Graph/Tree/HeavyLightDecomposition.hpp"
#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"

#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include <tuple>
#include <ranges>
namespace ranges = std::ranges;
namespace views = std::views;
using namespace zawa;
#include <set>
using namespace std;
struct M {
    using Element = int;
    static Element identity() {
        return (int)1e9;
    }
    static Element operation(Element L, Element R) {
        return min(L, R);
    }
};
int N, Q;
int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    vector<vector<int>> g(N);
    for (int i = 0 ; i < N - 1 ; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    HeavyLightDecomposition hld{g};
    SegmentTree<M> seg(N), seg2(N);
    vector<set<pair<int, int>>> bk(N);
    auto upd = [&](int u, int v) -> void {
        pair<int, int> cur{hld.depth(v), v};
        auto it = bk[u].find(cur);
        if (it != bk[u].end()) bk[u].erase(it);
        else bk[u].insert(cur);
        seg.assign(hld[u], bk[u].size() ? (bk[u].begin()->first - 2 * (int)hld.depth(u)) : M::identity());
        seg2.assign(hld[u], bk[u].size() ? bk[u].begin()->first : M::identity());
    };
    auto leaf_prod = [&](int v) -> int {
        int u = hld.bottom(v);
        tie(u, v) = minmax({hld[u], hld[v]});
        return seg2.product(u, v + 1);
    };
    cin >> Q;
    while (Q--) {
        int T, V;
        cin >> T >> V;
        V--;
        if (T == 1) {
            for (auto [u, v] : hld(V, 0)) {
                upd(u, V);
                if (u != v) upd(v, V);
            }
        }
        else if (T == 2) {
            int ans = M::identity();
            for (auto [u, v] : hld(V, 0)) {
                if (hld.depth(u) > hld.depth(v)) {
                    ans = min(ans, leaf_prod(u) - 2 * (int)hld.depth(u));
                }
                else {
                    ans = min(ans, leaf_prod(v) - 2 * (int)hld.depth(v));
                }
                tie(u, v) = minmax({hld[u], hld[v]});
                ans = min<int>(ans, seg.product(u, v + 1));
            }
            ans += hld.depth(V);
            cout << ans << '\n';
        }
        else assert(false);
    }
#else
    cout << "Hello World\n";
#endif
}
