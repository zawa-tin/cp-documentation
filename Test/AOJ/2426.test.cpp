#define PROBLEM "http://onlinejudge.u-aizu.ac.jp/problems/2426"

#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/DataStructure/PrefixSum/PrefixSum2D.hpp"
#include "../../Src/Sequence/CompressedSequence.hpp"
using namespace zawa;

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    vector<int> X(N), Y(N);
    for (int i = 0 ; i < N ; i++)
        cin >> X[i] >> Y[i];
    CompressedSequence CX{X}, CY{Y};
    Ruisekiwa2D<AdditiveGroup<int>> a{CX.size(), CY.size()};
    for (int i = 0 ; i < N ; i++) 
        a.operation(CX.map(i), CY.map(i), 1);
    auto sum = a.inplaceBuild();
    while (M--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum.product(CX[x1], CY[y1], CX[x2 + 1], CY[y2 + 1]) << '\n';
    }
}
