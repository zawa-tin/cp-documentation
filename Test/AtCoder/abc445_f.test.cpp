// #define PROBLEM "https://atcoder.jp/contests/abc445/tasks/abc445_f"
/*
 * AtCoder Beginner Contest 445 F - Exactly K Steps 2
 * https://atcoder.jp/contests/abc445/submissions/79856158
 */
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../Src/Algebra/Monoid/StaticSquareMatrix.hpp"
#include "../../Src/Algebra/Ring/MinPlusSemiring.hpp"
#include "../../Src/Algebra/Monoid/MonoidPower.hpp"
#include <iostream>
using namespace zawa;
using namespace std;
const int MAX=100;
int main() {
#ifdef ATCODER
    int N,K;
    cin >> N >> K;
    using M=SquareMatrix<MinPlusSemiring<long long,(long long)1e18>,MAX>;
    M C=M::zero();
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < N ; j++)
            cin >> C[i][j];
    auto mat=MonoidPower<M,unsigned>(C,K);
    for (int i = 0 ; i < N ; i++)
        cout << mat[i][i] << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
