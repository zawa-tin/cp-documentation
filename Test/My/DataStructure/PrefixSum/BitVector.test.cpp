#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../../Src/DataStructure/PrefixSum/BitVector.hpp"
using namespace zawa;

#include <iostream>
#include <random>
using namespace std;

void test(vector<int> a) {
    vector<int> sum(ssize(a)+1);
    for (int i = 0 ; i < ssize(a) ; i++)
        sum[i+1] = sum[i]+a[i];
    // cerr << "start: a=";
    // for (int i : a)
    //     cerr << i << ' ';
    // cerr << endl;
    BitVector pref(a);
    for (int i = 0 ; i < ssize(a) ; i++) 
        assert(a[i] == pref.access<int>(i));
    for (int l = 0 ; l < ssize(a) ; l++)
        for (int r = l ; r <= ssize(a) ; r++) {
            // cerr << "query: " << l << ' ' << r << endl;
            assert((int)pref.rank1(l,r) == sum[r]-sum[l]);
            assert((int)pref.rank0(l,r) == r-l-sum[r]+sum[l]);
        }
}

int main() {
    mt19937 mt{random_device{}()};
    for (int n = 1 ; n <= 300 ; n++) {
        for (int t = 0 ; t < 5 ; t++) {
            vector<int> a(n);
            for (int i = 0 ; i < n ; i++)
                a[i] = mt() % 2;
            test(a);
        }
    }
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
}
