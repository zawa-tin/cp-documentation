#define PROBLEM "https://atcoder.jp/contests/abc261/tasks/abc261_f"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Sequence/InversionNumber.hpp"

#include <iostream>
#include <vector>

using namespace zawa;

int main() {
    SetFastIO(); 
    int N;
    std::cin >> N;
    std::vector<int> C(N), X(N);
    for (int& c : C) {
        std::cin >> c;
        c--;
    }
    std::vector<std::vector<int>> A(N);
    for (int i{} ; i < N ; i++) {
        std::cin >> X[i];
        A[C[i]].push_back(X[i]);
    }
    long long ans{(long long)InversionNumber(X.begin(), X.end())};
    for (int i{} ; i < N ; i++) {
        ans -= InversionNumber(A[i].begin(), A[i].end());
    }
    std::cout << ans << '\n';
}
