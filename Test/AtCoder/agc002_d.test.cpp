#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
// #define PROBLEM "https://atcoder.jp/contests/agc002/tasks/agc002_d"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Utility/ParallelBinarySearch.hpp"
#include "../../Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp"

/*
 * AGC002-D Stampl Rally
 * https://atcoder.jp/contests/agc002/submissions/63106870
 */

#include <algorithm>
#include <vector>

using namespace zawa;
int N, M, A[100010], B[100010], Q, X[100010], Y[100010], Z[100010];
void solve() {
    auto f = [&](auto a) {
        std::sort(a.begin(), a.end());
        std::vector<std::pair<bool, int>> res(a.size());
        DisjointSetUnion dsu(N);
        for (int i = 1, j = 0 ; i <= M ; i++) {
            dsu.merge(A[i], B[i]);
            assert(j == (int)a.size() or a[j].first >= i);
            while (j < (int)a.size() and a[j].first == i) {
                int id = a[j].second;
                int num = (int)dsu.size(X[id]) + (dsu.same(X[id], Y[id]) ? 0 : (int)dsu.size(Y[id]));
                bool ans = num >= Z[id];
                res[j++] = {ans, id};
            }
        }
        return res;
    };
    auto ans = ParallelBinarySearch(std::vector<int>(Q, M), std::vector<int>(Q, 0), f);
    for (int i = 0 ; i < Q ; i++) std::cout << ans[i] << '\n';
}
int main() {
#ifdef ATCODER
    SetFastIO();
    std::cin >> N >> M;
    for (int i = 1 ; i <= M ; i++) {
        std::cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }
    std::cin >> Q;
    for (int i = 0 ; i < Q ; i++) {
        std::cin >> X[i] >> Y[i] >> Z[i];
        X[i]--; Y[i]--;
    }
    solve();
#else
    std::cout << "Hello World\n";
#endif
}
