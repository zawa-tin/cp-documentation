#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/3369"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/LinearAlgebra/Matrix.hpp"
#include "../../Src/Algebra/Ring/UsualRing.hpp"
#include "atcoder/modint"

#include <iostream>

using namespace zawa;
using mint = atcoder::modint998244353;
using Mat = Matrix<UsualRing<mint>>;

int main() {
    SetFastIO();
    
    int N, M;
    std::cin >> N >> M;
    Mat g(N, N);
    for (int _{} ; _ < M ; _++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        g[u][u]++;
        g[v][v]++;
        g[u][v] = g[v][u] = mint{-1};
    }
    mint ans{g.cofactor(0, 0) * mint{M - N + 1}};
    std::cout << ans.val() << '\n';
}
