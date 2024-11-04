#define PROBLEM "https://atcoder.jp/contests/abc346/tasks/abc346_g"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Utility/AreaOfUnionOfRectangles.hpp"

using namespace zawa;

int main() {
    SetFastIO();
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (auto& a : A) {
        std::cin >> a;
        a--;
    }
    std::vector<int> left(N, -1), right(N, N);
    std::vector<int> L(N), R(N), D(N), U(N);
    for (int i{} ; i < N ; i++) {
        L[i] = left[A[i]] + 1;
        R[i] = i + 1;
        left[A[i]] = i;
    }
    for (int i{N} ; i-- ; ) {
        D[i] = i;
        U[i] = right[A[i]];
        right[A[i]] = i;
    } 
    std::vector<Rectangle<int>> rect(N);
    for (int i{} ; i < N ; i++) {
        rect[i] = Rectangle<int>{ L[i], D[i], R[i], U[i] };
    }
    std::cout << AreaOfUnionOfRectangles<int>(rect.begin(), rect.end()) << '\n';
}
