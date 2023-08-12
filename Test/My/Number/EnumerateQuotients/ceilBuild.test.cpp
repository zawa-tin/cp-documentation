#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../../../Src/Template/TypeAlias.hpp"
#include "../../../../Src/Number/EnumerateQuotients.hpp"

#include <cassert>
#include <iostream>
#include <random>

using namespace zawa;

void test(u32 n) {
    EnumerateQuotients q(n, false);
    bool ok{true};
    for (const auto& dat : q) {
        for (u32 i{dat.l()} ; i < dat.r() ; i++) {
            ok &= i * dat.quotient() >= q.n();
            ok &= i * (dat.quotient() - 1) < q.n();
        }
    }
    if (not ok) {
        std::cerr << n << " failed!!!" << std::endl;
        assert(false);
    }
    else {
        std::cerr << n << " ok!!!" << std::endl;
    }
}

int main() {
    std::mt19937 mt{ std::random_device{}() };
    test(0);
    test(1);
    test(2);
    for (u32 i{} ; i < 100 ; i++) {
        test(mt() % (u32)1e6);
    }
    std::cout << "Hello World" << std::endl;
}
