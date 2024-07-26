#define PROBLEM "https://atcoder.jp/contests/abc308/tasks/abc308_g"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/Other/SortedAdjacentProduct.hpp"
#include "../../Src/Algebra/Group/XorGroup.hpp"

#include <cassert>
#include <iostream>

using namespace zawa;

int main() {
    SetFastIO(); 
    int Q;
    std::cin >> Q;
    SortedAdjacentProduct<XorGroup<int>> data{};
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 1) {
            int x;
            std::cin >> x;
            data.insert(x);
        }
        else if (t == 2) {
            int x;
            std::cin >> x;
            data.erase(x);
        }
        else if (t == 3) {
            std::cout << data.min() << '\n';
        }
        else {
            assert(false);
        }
    }
}
