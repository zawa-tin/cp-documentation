#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../../../Src/Template/TypeAlias.hpp"
#include "../../../../Src/Number/EnumerateQuotients.hpp"

#include <cassert>
#include <iostream>

using namespace zawa;

int main() {
    EnumerateQuotients q(100u, false);
    for (const auto& dat : q) {
        std::cerr << '[' << dat.l() << ',' << dat.r() << ") : " << dat.quotient() << std::endl;
        for (u32 i{dat.l()} ; i < dat.r() ; i++) {
            assert(i * dat.quotient() >= q.n());
            assert(i * (dat.quotient() - 1) < q.n());
        }
    }
    std::cout << "Hello World" << std::endl;
}
