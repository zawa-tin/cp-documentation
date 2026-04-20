#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../../Src/DataStructure/SparseTable/SparseTable.hpp"
#include "../../../../Src/DataStructure/RMQ/PM1RMQ.hpp"
using namespace zawa;

#include <vector>
#include <iostream>
#include <random>
using namespace std;
struct MIN {
    using Element = pair<int,int>;
    static Element operation(const Element l,const Element r) {
        return r.first < l.first ? r : l;
    }
};
mt19937 mt{random_device{}()};
void test(int N,int Q) {
    cerr << "test: " << N << ' ' << Q << endl;
    vector<int> A(N);
    vector<MIN::Element> B(N);
    A[0] = mt() % (int)1e9 + 1;
    for (int i = 1 ; i < N ; i++)
        A[i] = A[i-1] + (mt() % 2 ? 1 : -1);
    for (int i = 0 ; i < N ; i++)
        B[i] = {A[i],i};
    PM1RMQ RMQ(A);
    SparseTable<MIN> spt(B);
    while (Q--) {
        int l = mt() % N;
        int r = mt() % N;
        if (l > r)
            swap(l,r);
        r++;
        assert((int)RMQ(l,r) == spt.product(l,r).second);
    }
}
int main() {
    for (int n = 1 ; n <= 10 ; n++)
        test(n,10);
    test(100,200);
    test(1000,2000);
    test(200000,300000);
    int a,b;
    cin >> a >> b;
    cout << a + b << '\n';
}
