#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/3022"

#include "../../Src/Graph/Components/BlockCutTree.hpp"
using namespace zawa;

#include <iostream>
#include <numeric>
#include <vector>
#include <unordered_set>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N, M;
    std::cin >> N >> M;
    std::vector<int> W(N);
    for (auto& w : W) std::cin >> w;
    std::vector<std::vector<int>> g(N);
    for (int i = 0 ; i < M ; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    BlockCutTree bct{g};
    const long long sum = std::accumulate(W.begin(), W.end(), 0LL);
    std::vector<long long> ans(N);
    for (int i = 0 ; i < N ; i++) if (!bct.isCut(i)) 
        ans[i] = sum - W[i];
    std::vector<bool> vis(bct.size());
    auto rec = [&](auto rec, int v, int p) -> std::pair<std::unordered_set<int>, long long> {
        vis[v] = true;
        long long s = 0LL;
        std::unordered_set<int> set;
        const int pos = bct.type(v) == decltype(bct)::Type::CUT ? bct.cut(v) : -1;
        for (int x : bct[v]) if (x != p) {
            auto [st, k] = rec(rec, x, v);
            if (pos != -1) ans[pos] = std::max(ans[pos], k - (st.contains(pos) ? W[pos] : 0));
            if (set.size() < st.size()) {
                std::swap(set, st);
                std::swap(s, k);
            }
            for (int ch : st) if (!set.contains(ch)) {
                s += W[ch];
                set.insert(ch);
            }
        }
        for (int cur : bct.vertices(v)) {
            if (!set.contains(cur)) {
                set.insert(cur);
                s += W[cur];
            }
        }
        if (pos != -1) ans[pos] = std::max(ans[pos], sum - s);
        return {set, s};
    };
    for (int i = 0 ; i < std::ssize(bct) ; i++) if (!vis[i]) rec(rec, i, -1);
    for (long long i : ans) std::cout << i << '\n';
}
