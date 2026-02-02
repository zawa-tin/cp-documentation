#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../Src/Number/DiscreteLogarithmPrimeLift.hpp"
using namespace zawa;

#include <iostream>
#include <random>
using namespace std;

int main() {
    // {
    //     unsigned long long a=20, b=7, p=3, k=3;
    //     auto ans = DiscreteLogarithmPrimeLift(a, b, p, k);
    //     cerr << ans.value_or(998244353) << endl;
    //     exit(0);
    // }
    mt19937_64 mt{random_device{}()}; 
    for (int p : {2,3,5,7,11,13,17}) {
        unsigned long long md = p;
        unsigned k = 1;
        while (md < (unsigned long long)1e10) {
            unsigned long long ord = md / p * (p - 1);
            for (int i = 0 ; i < 100 ; i++) {
                unsigned long long a = mt() % md, x = mt() % ord;
                unsigned long long b = [&]() {
                    unsigned long long res = 1, base = a;
                    for (unsigned long long i = x ; i ; i >>= 1) {
                        if (i & 1)
                            res = (__uint128_t{res} * base) % md;
                        base = (__uint128_t{base} * base) % md;
                    }
                    return res;
                }();
                cerr << a << ' ' << b << ' ' << p << ' ' << k << endl;
                auto ans = DiscreteLogarithmPrimeLift(a, b, p, k);
                assert(ans.has_value());
                unsigned long long c = [&]() {
                    unsigned long long res = 1, base = a;
                    for (unsigned long long i = ans.value() ; i ; i >>= 1) {
                        if (i & 1)
                            res = (__uint128_t{res} * base) % md;
                        base = (__uint128_t{base} * base) % md;
                    }
                    return res;
                }();
                assert(b == c);
            }
            for (int i = 0 ; i < 100 ; i++) {
                unsigned long long a = mt() % md, b = mt() % md;
                cerr << a << ' ' << b << ' ' << p << ' ' << k << endl;
                auto ans = DiscreteLogarithmPrimeLift(a, b, p, k);
                if (!ans.has_value())
                    continue;
                unsigned long long c = [&]() {
                    unsigned long long res = 1, base = a;
                    for (unsigned long long i = ans.value() ; i ; i >>= 1) {
                        if (i & 1)
                            res = (__uint128_t{res} * base) % md;
                        base = (__uint128_t{base} * base) % md;
                    }
                    return res;
                }();
                assert(b == c);
            }
            md *= p;
            k++;
        }
    }
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}
