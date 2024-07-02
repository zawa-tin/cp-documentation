#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * ABC359-G Sum of Tree Distance
 * TODO: Dropboxにテストケースが登録されたら自動verifyに移行する
 * https://atcoder.jp/contests/abc359/submissions/55138867
 */

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Tree/AuxiliaryTree.hpp"

#include <iostream>
#include <vector>

using namespace zawa;
using vertex = AuxiliaryTree::V;

int main() {
#ifdef ATCODER
    SetFastIO();

    int N;
    std::cin >> N;
    Tree g(N);
    for (int i{1} ; i < N ; i++) {
        int u, v;
        std::cin >> u >> v;
        AddEdge(g, u - 1, v - 1);
    }
    std::vector<int> A(N);
    std::vector<std::vector<vertex>> B(N);
    for (int i{} ; i < N ; i++) {
        std::cin >> A[i];
        A[i]--;
        B[A[i]].push_back(i);
    }
    AuxiliaryTree AT(g);
    long long ans{};
    std::vector<int> size(N);
    std::vector<long long> dp(N);
    for (int c{} ; c < N ; c++) {
        if (B[c].empty()) {
            continue;
        }
        int r{(int)AT.construct(B[c])};
        auto dfs{[&](auto dfs, int v, int p) -> long long {
            if (A[v] == c) size[v]++; 
            long long res{};
            for (auto x : AT[v]) {
                if ((int)x == p) continue;
                res += dfs(dfs, x, v);
                res += dp[v] * size[x] + size[v] * (size[x] * AT.parentEdgeLength(x) + dp[x]);
                dp[v] += dp[x] + AT.parentEdgeLength(x) * size[x];
                size[v] += size[x];
            }
            return res;
        }}; 
        long long val{dfs(dfs, r, -1)};
        ans += val;
        for (auto v : AT.current()) {
            size[v] = 0;
            dp[v] = 0;
        }
    }
    std::cout << ans << '\n';
#else
    std::cout << "Hello World" << '\n';
#endif
}
