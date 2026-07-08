#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/4077"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/DataStructure/PrefixSum/PrefixSumND.hpp"
using namespace zawa;
#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    std::array<int,8> sz;
    sz.fill(1);
    for (int i = 0 ; i < N ; i++)
        cin >> sz[i];
    RuisekiwaND<AdditiveGroup<long long>,8> builder(sz);
    auto dfs = [&](auto dfs,int i,std::array<int,8>& p) -> void {
        if (i == 8) {
            int v;
            cin >> v;
            builder.assign(p,v);
            return;
        }
        for (int j = 0 ; j < sz[i] ; j++) {
            p[i] = j;
            dfs(dfs,i+1,p);
        }
    };
    std::array<int,8> p;
    dfs(dfs,0,p);
    auto sum = builder.inplaceBuild();
    int Q;
    cin >> Q;
    while (Q--) {
        array<int,8> l,r = sz;
        l.fill(0);
        for (int i = 0 ; i < N ; i++) {
            cin >> l[i] >> r[i];
            l[i]--;
        }
        cout << sum.product(l,r) << '\n';
    }
}
