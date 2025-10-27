#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../Src/Number/SqrtHeuristicArithmetic.hpp"
using namespace zawa;

#include <iostream>
using namespace std;

void test(long long a, long b, long long m, long long n) {
    cerr << "test " << a << "x+" << b << " mod " << m << " term " << n << endl;
    auto ans = SqrtHeuristicArithmetic<long long>(a, b, m, n);
    if (n < 100) {
        for (auto data : ans) {
            for (int i = 0 ; i < (int)data.n ; i++) {
               cerr << '(' << data(i) << ',' << data.originIndex(i) << ')';
               assert(0 <= data(i) and data(i) < m);
               assert(0 <= data.originIndex(i) and data.originIndex(i) < n);
            }
            cerr << endl; 
        }
    }
    cerr << "sz=" << ssize(ans) << endl;
}

int main() {
    test(7, 1, 17, 15);
    test(1, 0, 2, 1);
    test(3, 5, 10, 8);
    test(1, 1, 100, 20);
    test(123456, 789, 998244353, 100000000);
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}
