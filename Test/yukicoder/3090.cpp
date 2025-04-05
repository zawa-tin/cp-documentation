#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * yukicoder No.3090 NimNim
 * https://yukicoder.me/submissions/1064971
 */

#include "../../Src/Utility/MisereNim.hpp"

#include <algorithm>
#include <iostream>

using namespace zawa;
int N, M, A[100010], B[100010];
bool solve() {
    std::cin >> N >> M;
    for (int i = 0 ; i < N ; i++) std::cin >> A[i];
    for (int i = 0 ; i < M ; i++) std::cin >> B[i];
    if (MisereNim(A, A + N) == GameWinner::First) {
        return true;
    }
    else {
        int max = *std::max_element(A, A + N);
        if (max >= 2) {
            return false;
        }
        else {
            int x = 0;
            for (int i = 0 ; i < M ; i++) x ^= B[i];
            return x != 0;
        }
    }
}

int main() {
#ifdef ONLINE_JUDGE
    std::cout << (solve() ? "First\n" : "Second\n");
#else
    std::cout << "Hello World\n";
#endif
}
