#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Tree/Sack.hpp"

#include <iostream>
#include <utility>
#include <vector>

/*
 * Codeforces Round 316 (Div. 2) - D Tree Requests
 * https://codeforces.com/contest/570/submission/245736854
 */


using namespace zawa;

void solve() {
    SetFastIO();
    int n, q; std::cin >> n >> q;
    Sack sack(n);
    std::vector<int> dep(n);
    for (int i{1} ; i < n ; i++) {
        int p; std::cin >> p;
        sack.addEdge(p - 1, i);
        dep[i] = dep[p - 1] + 1;
    }
    std::string s; std::cin >> s;
    std::vector dat(n, std::vector<std::pair<int, int>>{});
    for (int i{} ; i < q ; i++) {
        int v, h; std::cin >> v >> h;
        v--; h--;
        dat[v].emplace_back(h, i);
    }

    std::vector<bool> ans(q);
    std::vector<std::array<bool, 26>> parity(n);
    for (int i{} ; i < n ; i++) parity[i].fill(false);
    std::vector<int> odd(n);
    auto add{[&](int v) -> void {
        odd[dep[v]] += (parity[dep[v]][s[v] - 'a'] ? -1 : 1);
        parity[dep[v]][s[v] - 'a'] ^= 1;
    }};
    auto del{[&](int v) -> void {
        odd[dep[v]] += (parity[dep[v]][s[v] - 'a'] ? -1 : 1);
        parity[dep[v]][s[v] - 'a'] ^= 1;
    }};
    auto query{[&](int v) -> void {
        for (auto [h, i] : dat[v]) {
            if (h >= n) ans[i] = true;
            else ans[i] = odd[h] <= 1;
        }
    }};
    auto reset{[](){}};
    sack.execute(0, add, del, query, reset);
    for (int i{} ; i < q ; i++) {
        std::cout << (ans[i] ? "Yes" : "No") << '\n';
    }
}

int main() {
#ifdef ONLINE_JUDGE
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
