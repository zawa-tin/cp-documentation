#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"

#include "../../../Src/Sequence/CompressedSequence.hpp"
#include "../../../Src/DataStructure/Set/OfflineOrderedSet.hpp"
using namespace zawa;

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N), T(Q), X(Q);
    OfflineOrderedSet<int> st;
    for (int& a : A) {
        cin >> a;
        st.reserveInsert(a);
    }
    for (int i = 0 ; i < Q ; i++) {
        cin >> T[i] >> X[i];
        if (T[i] == 0)
            st.reserveInsert(X[i]);
    }
    auto exe = st.build();
    for (int i = 0 ; i < N ; i++) {
        exe.insert(A[i]);
    }
    for (int i = 0 ; i < Q ; i++) {
        if (T[i] == 0) 
            exe.insert(X[i]);
        else if (T[i] == 1) 
            exe.erase(X[i]);
        else if (T[i] == 2) 
            cout << exe.kth(X[i]).value_or(-1) << '\n';
        else if (T[i] == 3)
            cout << exe.countLessEqual(X[i]) << '\n';
        else if (T[i] == 4) 
            cout << exe.prevEqual(X[i]).value_or(-1) << '\n';
        else if (T[i] == 5) 
            cout << exe.nextEqual(X[i]).value_or(-1) << '\n';
        else assert(false);
        cout.flush();
    }
}
