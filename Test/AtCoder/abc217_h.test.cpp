#define PROBLEM "https://atcoder.jp/contests/abc217/tasks/abc217_h"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Utility/SlopeTrick.hpp"

#include <iostream>
#include <vector>

using namespace zawa;

int main() {
    int N;
    std::cin >> N;
    std::vector<int> T(N + 1), D(N + 1), X(N + 1);
    for (int i{} ; i < N ; i++) {
        std::cin >> T[i + 1] >> D[i + 1] >> X[i + 1];
    }
    SlopeTrick<long long, long long> st;
    for (int i{} ; i < 2 * N ; i++) st.addAbsoluteXA(0);
    for (int i{} ; i < N ; i++) {
        long long c{T[i + 1] - T[i]};
        st.slidingWindowMin(-c, c);
        if (D[i + 1] == 0) {
            st.addMax0AX(X[i + 1]);
        }
        else if (D[i + 1] == 1) {
            st.addMax0XA(X[i + 1]);
        }
    }
    std::cout << st.min() << '\n';
}
