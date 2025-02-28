// #define PROBLEM "https://atcoder.jp/contests/abc340/tasks/abc340_e"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/DataStructure/FenwickTree/DualFenwickTree.hpp"

/*
 * Atcoder Beginner Contest 340 - E Mancala 2
 *
 */

#include <iostream>
using namespace zawa;
int N, M, A[200020];
void solve() {
    SetFastIO();
    std::cin >> N >> M;
    for (int i = 0 ; i < N ; i++) std::cin >> A[i];
    DualFenwickTree<AdditiveGroup<long long>> fen{std::vector<long long>(A, A + N)};
    for (int i = 0 ; i < M ; i++) {
        int B;
        std::cin >> B;
        long long v = fen[B];
        fen.set(B, 0LL);
        {
            long long a = std::min<long long>(N - (B + 1), v);
            fen.operation(B + 1, B + 1 + a, 1);
            v -= a;
        }
        {
            long long a = v / N;
            if (a) fen.operation(0, N, a);
            v -= a * N;
        }
        {
            assert(v < N);
            fen.operation(0, v, 1);
        }
    }
    for (int i = 0 ; i < N ; i++) std::cout << fen[i] << (i + 1 == N ? '\n' : ' ');
}
int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World\n";
#endif
}
