#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AOJ3369 Namori Counting
 * https://onlinejudge.u-aizu.ac.jp/solutions/problem/3369/review/11732361/zawakasu/C++20
 */

#include "../../Src/LinearAlgebra/Matrix.hpp"
#include "../../Src/Algebra/Ring/UsualRing.hpp"
#include "atcoder/modint"

#include <iostream>

using namespace zawa;
using mint = atcoder::modint998244353;
using Mat = Matrix<UsualRing<mint>>;

int main() {
    std::cout << "Hello World" << '\n';
    // std::cin.tie(0);
    // std::cout.tie(0);
    // std::ios::sync_with_stdio(0);
    // int N, M;
    // std::cin >> N >> M;
    // Mat g(N, N);
    // for (int _{} ; _ < M ; _++) {
    //     int u, v;
    //     std::cin >> u >> v;
    //     u--; v--;
    //     g[u][u]++;
    //     g[v][v]++;
    //     g[u][v] = g[v][u] = mint{-1};
    // }
    // mint ans{g.cofactor(0, 0) * mint{M - N + 1}};
    // std::cout << ans.val() << '\n';
}
