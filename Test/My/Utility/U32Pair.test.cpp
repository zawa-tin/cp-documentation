#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../../Src/Utility/U32Pair.hpp"

#include <cassert>
#include <iostream>
#include <unordered_set>
#include <limits>

int main() {
    using namespace zawa;
    std::unordered_set<U32Pair, U32PairHash> set;
    U32Pair a{ 1, 1 }, b{ 2, 0 }, c{ 0, 1 };
    assert(a.first() == 1);
    assert(a.second() == 1);
    assert(b.first() == 2);
    assert(b.second() == 0);
    assert(c.first() == 0);
    assert(c.second() == 1);
    set.insert(a);
    set.insert(b);
    set.insert(c);
    assert(set.find(a) != set.end());
    assert(set.find(b) != set.end());
    assert(set.find(c) != set.end());
    assert(set.find(U32Pair{ 99, 99 }) == set.end());
    u32 max{std::numeric_limits<u32>::max()};
    U32Pair maxPair{max, max};
    assert(maxPair.first() == max);
    assert(maxPair.second() == max);
    std::cout << "Hello World" << '\n';
}
