#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Tree/Centroid.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace zawa;

#include "atcoder/convolution"

int main() {
    SetFastIO();
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> T(N);
    for (int i{} ; i < N - 1 ; i++) {
        int a, b;
        std::cin >> a >> b;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    Centroid C(std::move(T));
    std::vector<int> dep(N);
    auto calc_dep{[&](auto dfs, int v, int p, int d) -> void {
        dep[v] = d;
        for (auto x : C[v]) if ((int)x != p and !C.isRemoved(x)) {
            dfs(dfs, x, v, d + 1);
        }
    }};
    std::vector<long long> ans(N);
    auto dfs{[&](auto dfs, int v) -> void {
        v = C.rooting(v);
        calc_dep(calc_dep, v, -1, 0);
        C.remove(v);
        std::vector<std::vector<int>> subtree;
        for (auto x : C.adjlist(v)) {
            subtree.push_back(C.component(x));
        }
        std::vector<long long> sq_sum, sum_sq;
        for (const auto& comp : subtree) {
            int max_d{};
            for (auto x : comp) max_d = std::max(max_d, dep[x]);
            std::vector<long long> cur(max_d + 1);
            for (auto x : comp) {
                ans[dep[x]]++; // vを端点としたパスの寄与
                cur[dep[x]]++;
            }
            while (sum_sq.size() < cur.size()) sum_sq.push_back(0LL);
            for (int i{} ; i < (int)cur.size() ; i++) {
                sum_sq[i] += cur[i];
            }
            cur = atcoder::convolution_ll(cur, cur);
            while (sq_sum.size() < cur.size()) sq_sum.push_back(0LL);
            for (int i{} ; i < (int)cur.size() ; i++) {
                sq_sum[i] += cur[i];
            }
        }
        sum_sq = atcoder::convolution_ll(sum_sq, sum_sq);
        for (int i{} ; i < (int)sum_sq.size() ; i++) {
            ans[i] += sum_sq[i] >> 1;
        }
        for (int i{} ; i < (int)sq_sum.size() ; i++) {
            ans[i] -= sq_sum[i] >> 1;
        }
        for (auto x : C.adjlist(v)) {
            dfs(dfs, x);
        }
    }};
    dfs(dfs, 0);
    for (int i{1} ; i < N ; i++) {
        std::cout << ans[i] << (i + 1 == N ? '\n' : ' ');
    }
}
