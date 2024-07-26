#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/Other/SortedAdjacentProduct.hpp"
#include "../../Src/Utility/BinarySearch.hpp"
#include "../../Src/Algebra/Group/XorGroup.hpp"

#include <iostream>
#include <vector>
using namespace zawa;

long long solve() {
    int N;
    std::cin >> N;
    long long K;
    std::cin >> K;
    std::vector<int> A(N);
    for (auto& a : A) std::cin >> a;
    return BinarySearch(1LL << 32, -1LL, [&](long long v) -> bool {
                SortedAdjacentProduct<XorGroup<int>> data{};
                long long cnt{};
                for (int L{}, R{} ; L < N ; L++) {
                    while (R < N and (data.size() < 2u or data.min() > v)) {
                        data.insert(A[R]);
                        R++;
                    }
                    if (data.size() >= 2u and data.min() <= v) {
                        cnt += N - R + 1;
                    }
                    if (cnt >= K) return true;
                    if (L == R) {
                        R++;
                    }
                    else {
                        data.erase(A[L]);
                    }
                }
                return false;
            });
}

int main() {
#ifdef ONLINE_JUDGE
    SetFastIO();
    int T;
    std::cin >> T;
    while (T--) std::cout << solve() << '\n';
#else
    std::cout << "Hello World" << '\n';
#endif
}
