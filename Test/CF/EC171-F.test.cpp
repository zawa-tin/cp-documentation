// #define PROBLEM "https://codeforces.com/contest/2026/problem/F"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * Educational Codeforces Round 171 (Div. 2) F. Bermart Ice Cream
 * https://codeforces.com/contest/2026/submission/315943049
 */

#include "../../Src/DataStructure/SWAG/FoldableDeque.hpp"

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

const int P = 2000;
struct S {
    using Element = std::pair<int, int>; // {p, t}
    using Fold = struct {
        using Element = std::vector<int>;
        static Element identity() {
            Element res(P + 1, -1);
            res[0] = 0;
            return res;
        }
    };
    using F = typename Fold::Element;
    static F convert(Element v) {
        F res = Fold::identity();
        res[v.first] = v.second;
        return res;
    }
    static F pushBack(F dp, Element v) {
        for (int i = P ; i >= v.first ; i--) if (dp[i - v.first] != -1) {
            dp[i] = std::max(dp[i], dp[i - v.first] + v.second);
        }
        return dp;
    }
    static F pushFront(F dp, Element v) {
        for (int i = P ; i >= v.first ; i--) if (dp[i - v.first] != -1) {
            dp[i] = std::max(dp[i], dp[i - v.first] + v.second);
        }
        return dp;
    }
};
int Q, T[30030], x[30030], p[30030], t[30030], ans[30030], pop_id[30030], SIZE = 1;
std::vector<std::pair<int, int>> g[30030];
std::vector<int> need[30030];
int make_node(int par, int id) {
    g[par].push_back({SIZE, id});
    return SIZE++;
}
zawa::FoldableDeque<S> deq;
void dfs(int v) {
    if (need[v].size()) {
        auto [dp, ep] = deq.get();
        for (int i = 1 ; i <= P ; i++) {
            dp[i] = std::max(dp[i], dp[i - 1]);
            ep[i] = std::max(ep[i], ep[i - 1]);
        }
        for (int id : need[v]) {
            ans[id] = 0;
            for (int i = 0 ; i <= p[id] ; i++) ans[id] = std::max(ans[id], dp[i] + ep[p[id] - i]);
        }
    }
    for (auto [x, id] : g[v]) {
        if (T[id] == 2) {
            deq.pushBack({p[id], t[id]});
            dfs(x);
            deq.popBack();
        }
        else if (T[id] == 3) {
            const auto ice = deq.popFront();
            dfs(x);
            deq.pushFront(ice);
        }
        else assert(false);
    }
}

void solve() {
    std::cin >> Q;
    std::vector<int> cur(1);
    for (int i = 0 ; i < Q ; i++) {
        ans[i] = -1;
        std::cin >> T[i] >> x[i];
        x[i]--;
        if (T[i] == 1) {
            cur.push_back(cur[x[i]]);
        }
        else if (T[i] == 2) {
            std::cin >> p[i] >> t[i];
            cur[x[i]] = make_node(cur[x[i]], i);
        }
        else if (T[i] == 3) {
            const int v = cur[x[i]];
            if (pop_id[v] == 0) {
                pop_id[v] = cur[x[i]] = make_node(v, i);
            }
            else {
                cur[x[i]] = pop_id[v];
            }
        }
        else if (T[i] == 4) {
            std::cin >> p[i];
            need[cur[x[i]]].push_back(i);
        }
        else assert(false);
    }
    dfs(0);
    for (int i = 0 ; i < Q ; i++) if (ans[i] != -1) std::cout << ans[i] << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    solve();
#else
    std::cout << "Hello World\n";
#endif
}
