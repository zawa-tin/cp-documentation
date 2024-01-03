#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/SuccessiveShortestPath.hpp"

#include <iostream>
#include <string>
#include <vector>

/*
 * AtCoder Library Practice Contest - E MinCostFlow
 * https://atcoder.jp/contests/practice2/submissions/49008995
 */

void solve() {
    using namespace zawa;
    SetFastIO();
    int n, k; std::cin >> n >> k;
    SuccessiveShortestPath<int, long long> mcf(2 * n + 2);
    int source{2 * n}, sink{2 * n + 1};
    for (int i{} ; i < n ; i++) {
        mcf.addEdge(source, i, k, 0);
        mcf.addEdge(n + i, sink, k, 0);
    }
    const long long INF{(long long)1e9};
    std::vector A(n, std::vector<int>(n));
    std::vector id(n, std::vector<int>(n));
    for (int i{} ; i < n ; i++) {
        for (int j{} ; j < n ; j++) {
            int a; std::cin >> a;
            A[i][j] = a;
            a = INF - a;
            id[i][j] = mcf.addEdge(i, n + j, 1, a);
        }
    }
    mcf.addEdge(source, sink, INF, INF);
    assert(mcf.flow(source, sink, n * k));
    std::vector S(n, std::string(n, '.'));
    long long ans{};
    for (int i{} ; i < n ; i++) {
        for (int j{} ; j < n ; j++) {
            if (mcf.flowed(id[i][j])) {
                ans += A[i][j];
                S[i][j] = 'X';
            }
        }
    }
    std::cout << ans << '\n';
    for (int i{} ; i < n ; i++) {
        std::cout << S[i] << '\n';
    }
}

int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
