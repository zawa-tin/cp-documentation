//#define PROBLEM "https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci"
#define PROBOEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * Typical DP Contest T - fibonacci
 * https://atcoder.jp/contests/tdpc/submissions/72142064
 */

#include "../../Src/FPS/KthTerm.hpp"
#include "atcoder/modint"
using mint = atcoder::modint1000000007;

#include <vector>
using namespace std;
using fps = vector<mint>;

int main() {
#ifdef ATCODER
    int K, N;
    cin >> K >> N;
    fps C(K + 1, 1);
    C[0] = 0;
    fps A(K, 1);
    cout << zawa::KthTerm(N - 1, A, C, zawa::NaiveConvolution{}).val() << '\n';
#else
    cout << "Hello World\n";
#endif
}
