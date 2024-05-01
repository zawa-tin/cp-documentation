#define PROBLEM "https://atcoder.jp/contests/arc123/tasks/arc123_d"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Utility/SlopeTrick.hpp"

#include <iostream>
#include <vector>

using namespace zawa;

int main() {
    SetFastIO();
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (auto& a : A) std::cin >> a;
    SlopeTrick<long long, long long> dp;
    dp.addAbsoluteXA(0);
    dp.addAbsoluteXA(A[0]);
    for (int i{1} ; i < N ; i++) {
        dp.translation(std::min(A[i] - A[i - 1], 0));
        dp.addAbsoluteXA(0);
        dp.addAbsoluteXA(A[i]);
    }
    std::cout << dp.min() << '\n';
}
