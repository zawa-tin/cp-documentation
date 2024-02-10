#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Tree/Sack.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/DataStructure/FenwickTree/FenwickTree.hpp"

#include <iostream>
#include <vector>

using namespace zawa;

/*
 * Educational Codeforces Round 2 - E Lomsat general
 * https://codeforces.com/contest/600/submission/245734447
 */

void solve() {
    SetFastIO();
    int n; std::cin >> n;
    std::vector<int> c(n);
    for (auto& x : c) {
        std::cin >> x;
        x--;
    }
    Sack sack(n);
    for (int _{} ; _ < n - 1 ; _++) {
        int u, v; std::cin >> u >> v;
        u--; v--;
        sack.addEdge(u, v);
    }

    FenwickTree<AdditiveGroup<long long>> fen(n + 1);
    std::vector<int> num(n);
    std::vector<long long> ans(n);

    auto add{[&](int v) -> void {
        fen.operation(num[c[v]], -(c[v] + 1));
        num[c[v]]++;
        fen.operation(num[c[v]], c[v] + 1);
    }};
    auto del{[&](int v) -> void {
        fen.operation(num[c[v]], -(c[v] + 1));
        num[c[v]]--;
        fen.operation(num[c[v]], c[v] + 1);
    }};
    auto query{[&](int v) -> void {
        auto it{fen.minLeft(n + 1, [](const auto& x) -> bool { return x == 0LL; })};
        ans[v] = fen[it];
    }};
    auto reset{[](){}};
    sack.execute(0, add, del, query, reset);
    for (int i{} ; i < n ; i++) {
        std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
    }
}

int main() {
#ifdef ONLINE_JUDGE
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
