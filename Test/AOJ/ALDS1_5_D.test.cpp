#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Sequence/InversionNumber.hpp"

using namespace zawa;

int main() {
    SetFastIO();
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (auto& a : A) std::cin >> a;
    std::cout << InversionNumber(A.begin(), A.end()) << '\n';
}
