#define PROBLEM "https://atcoder.jp/contests/arc070/tasks/arc070_e"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Utility/SlopeTrick.hpp"

#include <iostream>
#include <vector>

using namespace zawa;

int main() {
    int N;
    std::cin >> N;
    std::vector<int> l(N), r(N);
    for (int i{} ; i < N ; i++) {
        std::cin >> l[i] >> r[i];
    }
    SlopeTrick<long long, long long> st;
    st.addAbsoluteXA(l[0]);
    for (int i{1} ; i < N ; i++) {
        st.slidingWindowMin(-(r[i] - l[i]), r[i - 1] - l[i - 1]);
        st.addAbsoluteXA(l[i]);
    }
    std::cout << st.min() << '\n';
}
