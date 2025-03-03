// #define PROBLEM "https://atcoder.jp/contests/arc088/tasks/arc088_c"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/DataStructure/FenwickTree/DualFenwickTree.hpp"

/*
 * AtCoder Regular Contest 088 - E Papple Sort
 * https://atcoder.jp/contests/arc088/submissions/63367117
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <numeric>
using namespace zawa;
std::string S;
std::vector<int> pos[26];
std::vector<std::pair<int, int>> match[26];
bool is_palin() {
    int odd = 0;
    for (int i = 0 ; i < 26 ; i++) odd += pos[i].size() & 1;
    return odd <= 1;
}
int main() {
#ifdef ATCODER
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cin >> S;
    for (int i = 0 ; i < (int)S.size() ; i++) pos[S[i] - 'a'].push_back(i);
    if (is_palin()) {
        for (int i = 0 ; i < 26 ; i++) {
            match[i].reserve(pos[i].size() / 2);
            for (int j = 0, k = (int)pos[i].size() - 1 ; j < k ; j++, k--) {
                match[i].push_back({ pos[i][j], pos[i][k] });
            }
            std::reverse(match[i].begin(), match[i].end());
        }
        std::vector<int> init(S.size());
        std::iota(init.begin(), init.end(), 0);
        DualFenwickTree<AdditiveGroup<int>> fen{init};
        long long ans = 0;
        for (int l = 0, r = (int)S.size() - 1 ; l < r ; l++, r--) {
            int min = (int)1e9, arg = -1;
            for (int i = 0 ; i < 26 ; i++) if (match[i].size()) {
                auto [ll, rr] = match[i].back();
                int cost = fen[ll] - l + r - fen[rr];
                if (min > cost) {
                    min = cost;
                    arg = i;
                }
            }
            assert(arg != -1);
            auto [ll, rr] = match[arg].back();
            match[arg].pop_back();
            ans += min;
            fen.operation(0, ll, 1);
            fen.operation(rr + 1, S.size(), -1);
        }
        std::cout << ans << '\n';
    }
    else {
        std::cout << -1 << '\n';
    }
#else
    std::cout << "Hello World\n";
#endif
}
