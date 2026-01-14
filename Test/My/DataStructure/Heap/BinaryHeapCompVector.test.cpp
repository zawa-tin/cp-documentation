#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../../Src/DataStructure/Heap/BinaryHeap.hpp"
using namespace zawa;

#include <queue>
#include <random>
#include <utility>
#include <vector>
#include <iostream>
#include <chrono>
using namespace std;

template <class T, class U>
ostream& operator<<(ostream& os, pair<T, U> p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

template <class T>
ostream& operator<<(ostream& os, vector<T> a) {
    for (int i = 0 ; i < ssize(a) ; i++)
        os << a[i] << (i + 1 == ssize(a) ? "" : " ");
    return os;
}

template <class Queue>
int test(const vector<pair<int, vector<long long>>>& query) {
    Queue q;
    chrono::system_clock::time_point start = chrono::system_clock::now();
    int res = 0;
    for (auto [t, v] : query) {
        if (t == 0) {
            q.push(v);
            res += 1;
        }
        else if (t == 1) {
            if (q.size())
                q.pop();
            res += 2;
        }
    }
    chrono::system_clock::time_point end = chrono::system_clock::now();
    cerr << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
    return res;
}

int main() {
    const int Q = 3000000;
    const int K = 10;
    mt19937_64 mt{random_device{}()};
    const long long V = mt() % (long long)1e18;
    vector<pair<int, vector<long long>>> q(Q);
    for (int i = 0 ; i < Q / 2 ; i++) {
        q[i].first = 0;
        q[i].second = vector<long long>(K, V);
    }
    for (int i = Q / 2 ; i < Q ; i++) {
        q[i].first = mt() % 2;
        q[i].second = vector<long long>(K, V);
    }
    cerr << test<BinaryHeap<vector<long long>>>(q) << endl;
    int A, B;
    cin >> A >> B;
    cout << A + B << '\n';
}
