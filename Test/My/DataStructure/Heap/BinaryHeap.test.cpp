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
vector<long long> test(const vector<pair<int, long long>>& query) {
    Queue q;
    vector<long long> res;
    res.reserve(q.size());
    chrono::system_clock::time_point start = chrono::system_clock::now();
    for (auto [t, v] : query) {
        if (t == 0) {
            q.push(v);
            res.push_back(v);
        }
        else if (t == 1) {
            if (q.empty())
                res.push_back(-1);
            else {
                res.push_back(q.top());
                q.pop();
            }
        }
    }
    chrono::system_clock::time_point end = chrono::system_clock::now();
    cerr << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
    return res;
}

int main() {
    const int Q = 4000000;
    vector<pair<int, long long>> q(Q);
    vector<long long> ins(Q/2);
    mt19937_64 mt{random_device{}()};
    for (int i = 0 ; i < Q / 2 ; i++) {
        q[i].first = 0;
        q[i].second = mt() % (long long)1e18;
        ins[i] = q[i].second;
    }
    for (int i = 0 ; i < Q / 2 ; i++) {
        q[Q/2 + i].first = mt() % 2;
        q[Q/2 + i].second = q[Q/2 + i].first ? -1LL : (mt() % (long long)1e18);
    }
    auto a = test<BinaryHeap<long long>>(q);
    auto b = test<priority_queue<long long, vector<long long>, greater<long long>>>(q);
    assert(a == b);
    {
        chrono::system_clock::time_point start = chrono::system_clock::now();
        vector<long long> c = ins;
        BinaryHeap<long long> heap(std::move(ins));
        c.reserve(Q);
        for (int i = Q / 2 ; i < Q ; i++) {
            auto [t, v] = q[i];
            if (t == 0) {
                heap.push(v);
                c.push_back(v);
            }
            else if (t == 1) {
                if (heap.empty())
                    c.push_back(-1);
                else {
                    c.push_back(heap.top());
                    heap.pop();
                }
            }
        }
        assert(a == c);
        chrono::system_clock::time_point end = chrono::system_clock::now();
        cerr << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
    }
    int A, B;
    cin >> A >> B;
    cout << A + B << '\n';
}
