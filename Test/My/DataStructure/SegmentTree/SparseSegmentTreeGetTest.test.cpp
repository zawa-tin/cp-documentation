#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../../../Src/DataStructure/SegmentTree/SparseSegmentTree.hpp"

#include <iostream>
#include <vector>
#include <random>
struct M {
    using Element = int;
    static Element identity() {
        return 0;
    }
    static Element operation(Element,Element) {
        return 0;
    }
};

int main() {
    std::mt19937 mt{std::random_device{}()};
    const int size = 10000;
    std::vector<int> a(size, M::identity());
    zawa::SparseSegmentTree<M> seg(size);
    int q = 1000000;
    while (q--) {
        if (mt() % 2) {
            int i = mt() % size;
            assert(a[i] == seg.get(i));
        }
        else {
            int i = mt() % size, v = mt() % 100;
            a[i] = v;
            seg.assign(i, v);
        }
    }
    std::cout << "Hello World\n";
}
