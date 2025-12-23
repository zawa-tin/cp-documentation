// #define PROBLEM "https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_e"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * 第7回日本情報オリンピック本選 (過去問) E - ペンキの色
 * https://atcoder.jp/contests/joi2008ho/submissions/71931671
 */

#include "../../Src/Sequence/CompressedSequence.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/DataStructure/PrefixSum/Imos2D.hpp"

#include <iostream>
#include <cassert>

namespace zawa {}
using namespace zawa;
using namespace std;
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int W, H, N;
    cin >> W >> H >> N;
    vector<int> xs{0, W - 1}, ys{0, H - 1};
    vector<tuple<int, int, int, int>> ita(N);
    for (auto& [l, d, r, u] : ita) {
        cin >> l >> d >> r >> u;
        xs.push_back(l);
        if (r < W)
            xs.push_back(r);
        ys.push_back(d);
        if (u < H)
            ys.push_back(u);
    }
    CompressedSequence cx{xs}, cy{ys};
    Imos2D<AdditiveGroup<int>> imos(cx.size(), cy.size()); 
    for (auto [l, d, r, u] : ita) {
        imos.operation(cx[l], cy[d], cx[r], cy[u], 1);
    }
    auto solver = imos.destructiveBuild();
    vector id(cx.size(), vector<int>(cy.size(), -1));
    int ans = 0;
    for (int i = 0 ; i < ssize(cx) and cx.inverse(i) < W ; i++) 
        for (int j = 0 ; j < ssize(cy) and cy.inverse(j) < H ; j++) 
            if (id[i][j] == -1 and solver[i][j] == 0) {
                vector<pair<int, int>> que;
                que.emplace_back(i, j);
                ans++;
                for (int t = 0 ; t < ssize(que) ; t++) {
                    auto [x, y] = que[t];
                    if (x - 1 >= 0 and id[x - 1][y] == -1 and solver[x - 1][y] == 0) {
                        id[x - 1][y] = 1;
                        que.emplace_back(x - 1, y);
                    }
                    if (x + 1 < ssize(cx) and cx.inverse(x + 1) < W and id[x + 1][y] == -1 and solver[x + 1][y] == 0) {
                        id[x + 1][y] = 1;
                        que.emplace_back(x + 1, y);
                    }
                    if (y - 1 >= 0 and id[x][y - 1] == -1 and solver[x][y - 1] == 0) {
                        id[x][y - 1] = 1;
                        que.emplace_back(x, y - 1);
                    }
                    if (y + 1 < ssize(cy) and cy.inverse(y + 1) < H and id[x][y + 1] == -1 and solver[x][y + 1] == 0) {
                        id[x][y + 1] = 1;
                        que.emplace_back(x, y + 1);
                    }
                }
            }
    cout << ans << '\n';
#else
    cout << "Hello World\n";
#endif
}

