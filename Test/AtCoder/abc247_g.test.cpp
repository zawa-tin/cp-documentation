#define PROBLEM "https://atcoder.jp/contests/abc247/tasks/abc247_g"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/SuccessiveShortestPath.hpp"

int main() {
    using namespace zawa;
    SetFastIO();
    int n; std::cin >> n;
    const int m{150};
    SuccessiveShortestPath<int, long long> mcf(2 * m + 2, 2 * m + n);
    int source{2 * m}, sink{2 * m + 1};
    const long long INF{(long long)1e9};
    for (int i{} ; i < m ; i++) {
        mcf.addEdge(source, i, 1, 0);
        mcf.addEdge(m + i, sink, 1, 0);
    }
    for (int i{} ; i < n ; i++) {
        int a, b, c; std::cin >> a >> b >> c;
        a--; b--;
        c = INF - c;
        mcf.addEdge(a, m + b, 1, c);
    }

    auto info{mcf.slope(source, sink)};
    int k{(int)info.size() - 1};
    std::cout << k << '\n';
    for (int i{1} ; i <= k ; i++) {
        long long ans{INF * (long long)i - info[i]};
        std::cout << ans << '\n';
    }
}
