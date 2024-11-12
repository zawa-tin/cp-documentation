#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * Typical DP Contest T - フィボナッチ
 * https://atcoder.jp/contests/tdpc/submissions/59717471
 */

#include "../../Src/FPS/KthTerm.hpp"
#include "./atcoder/modint"

#include <iostream>
#include <vector>

using namespace zawa;

using mint = atcoder::modint1000000007;

mint solve() {
    int K, N;
    std::cin >> K >> N;
    return KthTerm(N - 1, std::vector<mint>(K, 1), std::vector<mint>(K, 1), [](const std::vector<mint>& L, const std::vector<mint>& R) -> std::vector<mint> {
                if (L.empty() or R.empty()) return {};
                std::vector<mint> res(L.size() + R.size() - 1);
                for (int i{} ; i < (int)L.size() ; i++) for (int j{} ; j < (int)R.size() ; j++) {
                    res[i + j] += L[i] * R[j];
                }
                return res;
            });
}

int main() {
#ifdef ATCODER
    std::cout << solve().val() << '\n';
#else
    std::cout << "Hello World\n";
#endif
}
