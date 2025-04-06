#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
// #define PROBLEM "https://atcoder.jp/contests/abc350/tasks/abc350_c"

/*
 * AtCoder Beginner Contest 350 C - Sort
 * https://atcoder.jp/contests/abc350/submissions/64587344
 */

#include "../../Src/Sequence/PermutationSwapSort.hpp"

#include <iostream>
#include <vector>
int N, A[200020];
int main() {
#ifdef ATCODER
    std::cin >> N;
    for (int i = 0 ; i < N ; i++) {
        std::cin >> A[i];
        A[i]--;
    }
    auto ans = zawa::PermutationSwapSort(A, A + N);
    std::cout << ans.size() << '\n';
    for (auto [i, j] : ans) std::cout << i + 1 << ' ' << j + 1 << '\n';
#else
    std::cout << "Hello World\n";
#endif
}
