#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../../Src/Utility/U32Pair.hpp"

#include <cassert>
#include <iostream>
#include <unordered_set>

int main() {
    using namespace zawa;
    std::unordered_set<U32Pair, U32PairHash> set;
    U32Pair a{ 1, 1 }, b{ 1, 0 }, c{ 0, 1 };
    set.insert(a);
    set.insert(b);
    set.insert(c);
    assert(set.find(a) != set.end());
    assert(set.find(b) != set.end());
    assert(set.find(c) != set.end());
    assert(set.find(U32Pair{ 99, 99 }) == set.end());
    std::cout << "Hello World" << '\n';
}
