// #define PROBLEM "https://atcoder.jp/contests/abc136/tasks/abc136_f"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 136 F - Enclosed Points
 * https://atcoder.jp/contests/abc136/submissions/65184629
 */


#include "../../Src/DataStructure/RectangleSum/RectangleSumOfPointCloud.hpp"

#include <vector>
#include <iostream>

#include "atcoder/modint"
using mint = atcoder::modint998244353;
struct Point {
    using P = int; // 座標の型、int, long long 
    using W = int; // 重みの型、int, long long, mint
    P x, y;
    W w;
};
struct Rect {
    using P = int;
    int l, d, r, u;
};
int main() {
#ifdef ATCODER
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<Point> P(N);
    std::vector<Rect> Q(8 * N);
    const int INF = (int)1e9 + 1;
    for (int i = 0 ; i < N ; i++) {
        int x, y;
        std::cin >> x >> y;
        P[i] = {x, y, 1};
        Q[8*i+0]={x+1,-INF, INF, INF};
        Q[8*i+1]={-INF,y+1, INF, INF};
        Q[8*i+2]={-INF,-INF, x, INF};
        Q[8*i+3]={-INF,-INF, INF, y};
        Q[8*i+4]={x+1,y+1, INF, INF};
        Q[8*i+5]={-INF,y+1, x, INF};
        Q[8*i+6]={-INF,-INF, x, y};
        Q[8*i+7]={x+1,-INF, INF, y};
    }
    auto prod = zawa::RectangleSumOfPointCloud(P, Q);
    std::vector<mint> p2(N + 1, 1);
    for (int i = 1 ; i <= N ; i++) p2[i] = p2[i - 1] * mint::raw(2);
    mint ans = 0;     
    for (int i = 0 ; i < N ; i++) {
        mint val = 0;
        val += p2[prod[8*i+0]] - 1;
        val += p2[prod[8*i+1]] - 1;
        val += p2[prod[8*i+2]] - 1;
        val += p2[prod[8*i+3]] - 1;
        val -= p2[prod[8*i+4]] - 1;
        val -= p2[prod[8*i+5]] - 1;
        val -= p2[prod[8*i+6]] - 1;
        val -= p2[prod[8*i+7]] - 1;
        ans += (p2[N - 1] - 1) - val;
    }
    ans += p2[N - 1] * mint::raw(N);
    std::cout << ans.val() << '\n';
#else
    std::cout << "Hello World\n";
#endif
}
