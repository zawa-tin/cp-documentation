// #define PROBLEM "https://yukicoder.me/problems/no/3228"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * yukicoder No.3228 Very Large Fibonacci Sum
 * https://yukicoder.me/submissions/1191336
 */
#include "../../Src/Sequence/BMBM.hpp"
#include "atcoder/modint"
using mint=atcoder::modint1000000007;
#include <iostream>
#include <vector>
using namespace std;
int main() {
#ifdef ONLINE_JUDGE
    long long a,b,c,d,e,N;
    cin >> a >> b >> c >> d >> e >> N;
    vector<mint> A{a,b},sum{a,a+b};
    for (int i = 0 ; i < 10 ; i++) {
        mint v=mint{c}*A[ssize(A)-1]+mint{d}*A[ssize(A)-2]+mint{e};
        A.push_back(v);
        sum.push_back(sum.back()+v);
    }
    cout << zawa::BMBM(sum,N).val() << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
