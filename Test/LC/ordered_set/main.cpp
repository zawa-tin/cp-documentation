#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"

#include "../../../Src/Sequence/CompressedSequence.hpp"
#include "../../../Src/DataStructure/Set/FenwickSet.hpp"
using namespace zawa;

#include <cassert>
#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <algorithm>

using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
#ifdef DEBUG
    while (true) {
    std::mt19937 mt{random_device{}()};
    int N = mt() % 500000 + 1;
    int Q = mt() % 500000 + 1;
    vector<int> A(N), T(Q), X(Q);
    for (int i = 0 ; i < N ; i++) A[i] = mt() % (int)1e9;
    for (int i = 0 ; i < Q ; i++) {
        T[i] = mt() % 2;
        X[i] = mt() % (int)1e9;
        if (T[i] == 1) T[i] = 5;
    }
    // cout << N << ' ' << Q << endl;
    // sort(A.begin(), A.end());
    // for (int i = 0 ; i < N ; i++) cout << A[i] << ' ';
    // cout << endl;
    // for (int i = 0 ; i < Q ; i++) cout << T[i] << ' ' << X[i] << endl;
#else
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N), T(Q), X(Q);
    for (int& a : A) {
        cin >> a;
    }
    for (int i = 0 ; i < Q ; i++) 
        cin >> T[i] >> X[i];
#endif

    // set<int> nv;
    CompressedSequence<int> comp([&]() {
                vector<int> res;
                res.reserve(N + Q);
                for (int a : A) res.push_back(a);
                for (int i = 0 ; i < Q ; i++) 
                    if (T[i] == 0 or T[i] == 1)
                        res.push_back(X[i]);
                return res;
            }());
    FenwickSet st(ssize(comp));
    for (int i = 0 ; i < N ; i++) {
        st.insert(comp.at(A[i]));
        // nv.insert(comp.at(A[i]));
    }
    for (int i = 0 ; i < Q ; i++) {
        if (T[i] == 0) {
            st.insert(comp.at(X[i]));
            // nv.insert(comp.at(X[i]));
        }
        else if (T[i] == 1) {
            st.erase(comp.at(X[i]));
            // nv.erase(comp.at(X[i]));
        }
        else if (T[i] == 2) {
            int res = st.kth(X[i]).value_or(-1);
            cout << (res == -1 ? res : comp.inverse(res)) << '\n';
        }
        else if (T[i] == 3)
            cout << st.countLessEqual((int)comp.upper_bound(X[i]) - 1) << '\n';
        else if (T[i] == 4) {
            int res = st.prevEqual((int)comp.upper_bound(X[i]) - 1).value_or(-1);
            cout << (res == -1 ? res : comp.inverse(res)) << '\n';
        }
        else if (T[i] == 5) {
            // for (auto n : nv) cout << n << ' ';
            // cout << endl;
            // cout << "query " << comp[X[i]] << endl;
            int res = st.nextEqual(comp[X[i]]).value_or(-1);
            cout << (res == -1 ? res : comp.inverse(res)) << '\n';
            // auto it = nv.lower_bound(comp[X[i]]);
            // int nvv = it == nv.end() ? -1 : *it;
            // if (res != nvv) {
            //     cout << res << ' ' << nvv << endl;
            //     exit(0);
            // }
        }
        else assert(false);
        cout.flush();
    }
#ifdef DEBUG
    cout << "--------------------------------------------" << endl;
    }
#endif
}
