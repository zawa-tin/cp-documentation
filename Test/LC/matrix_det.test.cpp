#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/LinearAlgebra/Matrix.hpp"
#include "../../Src/Algebra/Ring/UsualRing.hpp"
#include "atcoder/modint"

using namespace zawa;
using mint = atcoder::modint998244353;
using M = Matrix<UsualRing<mint>>;

int main() {
    int N;
    std::cin >> N;
    M A(N, N);
    for (int i{} ; i < N ; i++) {
        for (int j{} ; j < N ; j++) {
            int a;
            std::cin >> a;
            A[i][j] = mint::raw(a);
        }
    }
    std::cout << A.determinant().val() << '\n';
}
