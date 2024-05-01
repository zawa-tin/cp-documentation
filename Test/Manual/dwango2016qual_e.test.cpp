#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * 第ニ回ドワンゴからの挑戦状 予選 - E 花火
 * https://atcoder.jp/contests/dwango2016-prelims/submissions/52988448
 */

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Utility/SlopeTrick.hpp"

#include <iostream>

using namespace zawa;

void solve() {
    SetFastIO();
    int N, L;
    std::cin >> N >> L;
    std::vector<int> t(N), P(N);
    for (int i{} ; i < N ; i++) {
        std::cin >> t[i] >> P[i];
    }
    SlopeTrick<int, long long> st;
    for (int i{} ; i < N ; ) {
        int cur{t[i]};
        st.prefixMin();
        while (i < N and cur == t[i]) {
            st.addAbsoluteXA(P[i]);
            i++;
        }
    }
    std::cout << st.min() << '\n';
}

int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
