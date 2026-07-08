// #define PROBLEM "https://atcoder.jp/contests/abc465/tasks/abc465_f"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

/*
 * AtCoder Beginner Contest 465 F - Sjeltzer?
 * https://atcoder.jp/contests/abc465/submissions/77278171
 */

#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/DataStructure/PrefixSum/PrefixSumND.hpp"

#include <array>
#include <iostream>
#include <string>
#include <vector>
using namespace zawa;
using namespace std;
array<int,6> input() {
    string s;
    cin >> s;
    array<int,6> res;
    for (int i = 0 ; i < 6 ; i++)
        res[i] = s[i]-'0';
    return res;
}
int main() {
#ifdef ATCODER
    int N;
    cin >> N;
    RuisekiwaND<AdditiveGroup<long long>,6> builder(array<int,6>{10,10,10,10,10,10});
    while (N--) {
        auto s = input();
        int v;
        cin >> v;
        builder.operation(s,v);
    }
    auto sum = builder.inplaceBuild();
    int Q;
    cin >> Q;
    while (Q--){
        auto x = input();
        auto y = input();
        for (int i = 0 ; i < 6 ; i++)
            y[i]++;
        bool ban = 0;
        for (int i = 0 ; i < 6 ; i++)
            ban |= x[i] > y[i];
        if (ban) {
            cout << 0 << '\n';
            continue;
        }
        cout << sum.product(x,y) << '\n';
    }
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
