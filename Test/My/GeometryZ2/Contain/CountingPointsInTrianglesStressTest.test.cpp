#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../../../Src/GeometryZ2/Contain/CountPointsInTriangles.hpp"
#include "../../../../Src/GeometryZ2/Contain/NaiveCountPointsInTriangles.hpp"

#include <iostream>
#include <vector>
#include <random>
using namespace zawa;
using namespace geometryZ2;

std::mt19937 mt{std::random_device{}()};

bool test(const int N, const int M, const int X, const int Y) {
    const int n = mt() % (N - 2) + 3;
    const int m = mt() % (M - 2) + 3;
    std::vector<Point> a(n), b(m);
    for (int i = 0 ; i < n ; i++) {
        a[i].x() = mt() % (X + 1);
        a[i].y() = mt() % (Y + 1);
    }
    for (int i = 0 ; i < m ; i++) {
        b[i].x() = mt() % (X + 1);
        b[i].y() = mt() % (Y + 1);
    }
    NaiveCountPointsInTriangles ans(a, b);
    CountPointsInTriangles my(a, b);
    auto query = [&](int i, int j, int k) -> bool {
        int p = ans(i, j, k), q = my(i, j, k);
        if (p != q) {
            std::cout << n << '\n';
            for (const Point& v : a) std::cout << v.x() << ' ' << v.y() << '\n';
            std::cout << m << '\n';
            for (const Point& v : b) std::cout << v.x() << ' ' << v.y() << '\n';
            std::cout << 1 << '\n';
            std::cout << i << ' ' << j << ' ' << k << std::endl;
            std::cerr << p << " but you output " << q << std::endl;
            return false;
        }
        return true;
    };
    for (int i = 0 ; i < std::ssize(a) ; i++) {
        for (int j = 0 ; j < std::ssize(a) ; j++) {
            for (int k = 0 ; k < std::ssize(a) ; k++) {
                if (!query(i, j, k)) return false;
            }
        }
    }
    return true;
}

int main() {
    for (int t = 0 ; t < 1000 ; t++) { // tiny
        assert(test(5, 5, 5, 5));
    }
    for (int t = 0 ; t < 100 ; t++) { // small dense
        assert(test(20, 20, 10, 10));
    }
    for (int t = 0 ; t < 100 ; t++) { // small
        assert(test(20, 20, 100, 100));
    }
    assert(test(50, 100, 100, 100));
    std::cout << "Hello World\n";
}
