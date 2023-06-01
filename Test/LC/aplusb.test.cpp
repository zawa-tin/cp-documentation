#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"

#include <iostream>

using namespace zawa;

int main() {
    i32 A, B;
    std::cin >> A >> B;
    i32 ans = AdditiveGroup<i32>::operation(A, B);
    std::cout << ans << std::endl;
}
