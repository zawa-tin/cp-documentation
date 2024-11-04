#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"

#include "../../Src/Utility/AreaOfUnionOfRectangles.hpp"
#include "../../Src/Template/IOSetting.hpp"

#include <iostream>
#include <vector>

using namespace zawa;
 
int main() {
    SetFastIO();
    int N;
    std::cin >> N;
    std::vector<Rectangle<int>> A(N);
    for (int i{} ; i < N ; i++) {
        int l, d, r, u;
        std::cin >> l >> d >> r >> u;
        A[i] = Rectangle<int>{ l, d, r, u };
    }
    std::cout << AreaOfUnionOfRectangles<int>(A.begin(), A.end()) << '\n';
}
