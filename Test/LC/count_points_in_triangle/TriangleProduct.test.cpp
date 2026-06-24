#define PROBLEM "https://judge.yosupo.jp/problem/count_points_in_triangle"

#include "../../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../../Src/GeometryZ2/Contain/TriangleProduct.hpp"
using namespace zawa;
using namespace geometryZ2;

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    PointCloud P(N);
    for (int i = 0 ; i < N ; i++)
        cin >> P[i];
    int M;
    cin >> M;
    PointCloud Q(M);
    for (int i = 0 ; i < M ; i++)
        cin >> Q[i];
    TriangleProduct<AdditiveGroup<long long>> cpit(P,Q,vector<long long>(M,1));
    int q;
    cin >> q;
    while (q--) {
        int a,b,c;
        cin >> a >> b >> c;
        auto [pd,cnt] = cpit.product(a,b,c);
        assert(pd == cnt);
        cout << pd << '\n';
    }
}
