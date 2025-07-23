// #define PROBLEM "https://atcoder.jp/contests/abc333/tasks/abc333_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Utility/FloatingMarkerShift.hpp"
#include "../../Src/Utility/RationalBinarySearch.hpp"

#include <iostream>
#include <string>
#include <numeric>

using namespace zawa;
using namespace std;

__int128_t my_abs(__int128_t v) {
    return v < 0 ? -v : v;
}

int main() {
#ifdef ATCODER
    string rs;
    long long n;
    cin >> rs >> n;
    long long num = FloatingMarkerShift(rs, 18), den = 1000000000000000000LL;
    long long g = gcd(num, den);
    num /= g;
    den /= g;
    auto f = [&](long long x, long long y) -> bool {
        return (__int128_t)x * den <= (__int128_t)num * y;
    };
    auto [max_ok, min_ng] = RationalBinarySearch(f, n);
    auto [a, b] = max_ok;
    auto [c, d] = min_ng;
    if ((long double)2 * num * d * b > ((long double)c * b + (long double)a * d) * den) {
        swap(a, c);
        swap(b, d);
    }
    cout << a << ' ' << b << '\n';
#else
    cout << "Hello World\n";
#endif
}
