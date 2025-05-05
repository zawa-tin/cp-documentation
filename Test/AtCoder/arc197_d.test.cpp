// #define PROBLEM "https://atcoder.jp/contests/arc197/tasks/arc197_d"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Regular Contest 197 (Div. 2) D - Ancestor Relation
 * https://atcoder.jp/contests/arc197/submissions/65531577
 */

#include "../../Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp"
#include "atcoder/modint"
using namespace zawa;
using mint = atcoder::modint998244353;

#include <iostream>
#include <ranges>
int N, A[400][400];
mint solve(std::vector<int> a) {
    if (a.empty()) return 1;
    std::vector<bool> all(N);
    for (int v : a) {
        all[v] = true;
        for (int x : a) if (A[v][x] == 0) all[v] = false;
    }
    if (a[0] == 0 and !all[0]) return 0;
    int cnt = std::ranges::count(all, true);
    if (cnt == 0) return 0;
    if (a[0] == 0) cnt--;
    DisjointSetUnion dsu(N);
    for (int v : a) if (!all[v]) for (int x : a) if (!all[x]) {
        if (A[v][x]) dsu.merge(v, x);
    }
    auto gs = dsu.enumerate<int>();
    mint res = 1;
    for (int i = 1 ; i <= cnt ; i++) res *= mint::raw(i);
    std::vector<bool> next(N);
    for (int v : a) if (!all[v]) next[v] = true;
    for (const std::vector<int>& g : gs) if (next[g[0]]) {
        res *= solve(g);
    }
    return res;
}
int main() {
#ifdef ATCODER
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < N ; j++) std::cin >> A[i][j];
        }
        std::vector<int> a(N);
        std::iota(a.begin(), a.end(), 0);
        std::cout << solve(a).val() << '\n';
    }
#else
    std::cout << "Hello World\n";
#endif
}
