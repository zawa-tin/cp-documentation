#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2641"

#include "../../Src/GeometryR3/Segment.hpp"
#include "../../Src/GeometryR3/Sphere.hpp"
using namespace zawa::geometryR3;

#include <iostream>

int N, Q;
long long L[50];
Sphere<long double> B[50];
int main() {
    std::cin >> N >> Q;
    for (int i = 0 ; i < N ; i++) {
        std::cin >> B[i].center() >> B[i].radius() >> L[i];
    }
    while (Q--) {
        Segment<long double> s;
        std::cin >> s.p() >> s.q();
        long long ans = 0;
        for (int i = 0 ; i < N ; i++) {
            const long double d = Distance(B[i].center(), s);
            if (B[i].radius() - d > -1e-8) ans += L[i];
        }
        std::cout << ans << '\n';
    }
}
