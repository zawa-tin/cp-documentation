#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
// #define PROBLEM "https://atcoder.jp/contests/arc194/tasks/arc194_d"

#include "../../Src/Graph/Tree/SubtreesHash.hpp"
using namespace zawa;
#include "atcoder/modint"
using mint = atcoder::modint998244353;

#include <iostream>
#include <vector>
int N, SIZE = 1;
std::string S;
std::vector<int> g[5010];
mint F[5010], invF[5010];
mint solve() {
    std::cin >> N >> S;
    std::vector<int> stk;
    stk.push_back(0);
    for (char c : S) {
        if (c == '(') {
            g[stk.back()].push_back(SIZE);
            stk.push_back(SIZE++);
        }
        else {
            stk.pop_back();
        }
    }
    F[0] = 1;
    for (int i = 1 ; i <= SIZE ; i++) F[i] = F[i - 1] * mint::raw(i);
    invF[SIZE] = F[SIZE].inv();
    for (int i = SIZE ; i >= 1 ; i--) invF[i - 1] = invF[i] * mint::raw(i);
    auto hash = SubtreesHasher{}(std::vector(g, g + SIZE));
    auto dfs = [&](auto dfs, int v, int p) -> mint {
        std::vector<int> ch;
        ch.reserve(g[v].size());
        mint res = 1;
        for (int x : g[v]) if (x != p) {
            res *= dfs(dfs, x, v);
            ch.push_back(hash[x]);
        }
        std::sort(ch.begin(), ch.end());
        res *= F[ch.size()];
        for (int i = 0, j = 0 ; i < (int)ch.size() ; i = j) {
            while (j < (int)ch.size() and ch[i] == ch[j]) j++;
            res *= invF[j - i];
        }
        return res;
    };
    return dfs(dfs, 0, -1);
}

int main() {
#ifdef ATCODER
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << solve().val() << '\n';
#else
    std::cout << "Hello World\n";
#endif
}
