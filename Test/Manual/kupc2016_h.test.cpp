#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * Kyoto University Programming Contest 2016 - H 壁壁壁壁壁壁壁
 * https://atcoder.jp/contests/kupc2016/submissions/52990390
 */

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Utility/SlopeTrick.hpp"

#include <iostream>

using namespace zawa;

void solve() {
    SetFastIO();
    int N;
    std::cin >> N;
    std::vector<long long> A(N), B(N);
    for (auto& a : A) std::cin >> a;
    for (auto& b : B) std::cin >> b;
    SlopeTrick<long long, long long> st;
    for (int i{} ; i < 2 * N ; i++) st.addAbsoluteXA(0);
    for (int i{} ; i < N ; i++) {
        st.translation(-(A[i] - B[i]));
        st.prefixMin();
        st.addAbsoluteXA(0);
    }
    std::cout << st.f(0) << '\n';
}

int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
