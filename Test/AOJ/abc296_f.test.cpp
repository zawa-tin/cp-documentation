#define PROBLEM "https://atcoder.jp/contests/abc296/tasks/abc296_f"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Sequence/InversionNumber.hpp"

#include <iostream>
#include <vector>

using namespace zawa;

int main() {
    SetFastIO();
    int N;
    std::cin >> N;
    std::vector<int> A(N), B(N);
    for (auto& x : A) {
        std::cin >> x;
        x--;
    }
    for (auto& x : B) {
        std::cin >> x;
        x--;
    }
    // 多重集合として一致しているか？
    std::vector<int> cnt(N);
    for (auto x : A) cnt[x]++;
    for (auto x : B) cnt[x]--;
    for (int i{} ; i < N ; i++) if (cnt[i]) {
        std::cout << "No" << '\n';
        return 0;
    }
    // 同じ要素が含まれているか？
    for (auto x : A) cnt[x]++;
    for (int i{} ; i < N ; i++) if (cnt[i] > 1) {
        std::cout << "Yes" << '\n';
        return 0;
    }
    // 転倒数の偶奇
    bool ans{InversionParity(A.begin(), A.end()) == InversionParity(B.begin(), B.end())};
    std::cout << (ans ? "Yes" : "No") << '\n';
}
