#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Number/EnumerateQuotients.hpp"

#include <iostream>

using namespace zawa;

int main() {
    SetFastIO(); 
    u64 N; std::cin >> N;
    EnumerateQuotients eq(N);
    std::cout << eq.size() << std::endl;
    for (i32 i{(i32)eq.size() - 1} ; i >= 0 ; i--) {
        std::cout << eq[i].quotient() << (i ? ' ' : '\n');
    }
}
