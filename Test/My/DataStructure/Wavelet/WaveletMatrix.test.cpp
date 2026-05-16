#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../../Src/DataStructure/Wavelet/WaveletMatrix.hpp"
#include "../../../../Src/Random/RandomArray.hpp"
using namespace zawa;

#include <cassert>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

unsigned long long seed = random_device{}();
mt19937 mt{seed};

template <class T>
void accessTest(vector<T> A) {
    WaveletMatrix wav(A);
    bool ok = 1;
    for (int i = 0 ; i < ssize(A) ; i++)
        ok &= wav[i] == A[i];
    if (!ok) {
        cerr << ssize(A) << endl;
        for (T a : A)
            cerr << a << ' ';
        cerr << endl;
        for (int i = 0 ; i < ssize(A) ; i++)
            cerr << wav[i] << ' ';
        cerr << endl;
        assert(0);
    }
}

template <class T,bool time=false>
void accessTest(int MAXN,T MAXA) {
    int N = mt() % MAXN + 1;
    vector<T> A = Random::Array<T>(N,0,MAXA);
    if constexpr (time) {
        T mx = *ranges::max_element(A);
        auto st = chrono::system_clock::now(); 
        accessTest(std::move(A));
        auto en = chrono::system_clock::now();
        auto t = chrono::duration_cast<chrono::milliseconds>(en-st).count();
        cerr << "N=" << N << ",MAXA=" << mx << ",time=" << t << endl;
    }
    else
        accessTest(std::move(A));
}

template <class T>
void frequencyTest(std::vector<T> A,T MAXA) {
    WaveletMatrix wav(A);
    for (int l = 0 ; l < ssize(A) ; l++)
        for (int r = l ; r <= ssize(A) ; r++) {
            for (int t = 0 ; t < 3 ; t++) {
                T d = mt() % (MAXA + 1);
                T u = mt() % (MAXA + 1);
                if (d > u)
                    swap(d,u);
                int v = wav.frequency(l,d,r,u);
                int x = 0;
                for (int i = l ; i < r ; i++)
                    x += d <= A[i] and A[i] < u;
                if (v != x) {
                    for (T a : A)
                        cerr << a << ' ';
                    cerr << endl;
                    cerr << l << ' ' << r << ' ' << d << ' ' << u << endl;
                    cerr << x << " but you " << v << endl;
                    assert(0);
                }
            }
        }
}

template <class T>
void frequencyTest(int MAXN,T MAXA) {
    int N = mt() % MAXN + 1;
    vector<T> A = Random::Array<T>(N,0,MAXA);
    frequencyTest(std::move(A),MAXA);
}

int main() {
    cerr << "seed=" << seed << endl;
    for (int t = 0 ; t < 100 ; t++) {
        int n = mt() % 10 + 1;
        int a = mt() % 10 + 1;
        frequencyTest(n,a);
    }
    frequencyTest<int>({0,6,0,2,5,6,5,3,1},9);
    frequencyTest<int>(100,8);
    frequencyTest<long long>(100,(long long)1e18);
    cerr << "frequencyTest: pass" << endl;
    accessTest<int>({3,7,2,4});
    for (int i = 0 ; i < 500 ; i++)
        accessTest<int>(10,8);
    accessTest<long long>({545377511343558464,487284146122142569,542554624957143677});
    for (int i = 0 ; i < 500 ; i++)
        accessTest<long long>(10,(long long)1e18);
    accessTest<int>(200000,500000);
    accessTest<int>(200000,500000);
    accessTest<long long>(200000,(long long)1e18);
    accessTest<int,true>(200000,(int)1e9);
    int a,b;
    cin >> a >> b;
    cout << a + b << '\n';
}
