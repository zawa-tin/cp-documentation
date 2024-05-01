#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * 東京大学プログラミングコンテスト2012-L じょうしょうツリー
 * https://atcoder.jp/contests/utpc2012/submissions/52989718
 */

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Utility/SlopeTrick.hpp"

#include <iostream>
#include <vector>

using namespace zawa;

void solve() {
    SetFastIO();
    int N;
    std::cin >> N;
    std::vector<int> C(N), depth(N);
    std::cin >> C[0];
    std::vector<std::vector<int>> g(N);
    for (int i{1} ; i < N ; i++) {
        int P;
        std::cin >> P >> C[i];
        P--;
        g[P].push_back(i);
        depth[i] = depth[P] + 1;
        C[i] += depth[i];
    }
    std::vector<SlopeTrick<int, long long>> st(N);
    auto dfs{[&](auto dfs, int v) -> void {
        for (auto x : g[v]) {
            dfs(dfs, x);
            st[x].prefixMin();
            if (st[v].size() < st[x].size()) {
                std::swap(st[v], st[x]);
            }
            st[v] += st[x];
            st[x].clear();
        }
        st[v].addAbsoluteXA(C[v]);
    }};
    dfs(dfs, 0);
    std::cout << st[0].min() << '\n';
}

int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}

