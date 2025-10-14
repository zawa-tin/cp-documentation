// #define PROBLEM "https://contest.ucup.ac/contest/2551/problem/14140"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * The 4th Universal Cup. Stage 2: Grand Prix of Paris K. $k$ Operations
 * https://contest.ucup.ac/submission/1507848
 */

#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/DataStructure/FenwickTree/FenwickTree.hpp"
#include "../../Src/Sequence/CompressedSequence.hpp"
#include "atcoder/modint.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
using mint = atcoder::modint998244353;
using namespace zawa;
using namespace std;
struct MULT {
    using Element = mint;
    static Element identity() {
        return 1;
    }
    static Element operation(Element l, Element r) {
        return l * r;
    }
    static Element inverse(Element v) {
        return v.inv();
    }
};
int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N);
    for (long long& a : A)
        cin >> a;
    vector<int> L(Q), R(Q);
    vector<long long> K(Q);
    for (int i = 0 ; i < Q ; i++) {
        cin >> L[i] >> R[i] >> K[i];
        L[i]--;
    }
    CompressedSequence compA(A);
    vector<vector<int>> buc(compA.size());
    for (int i = 0 ; i < N ; i++)
        buc[compA.map(i)].push_back(i);
    // detect a_i
    // if first == 998.., all op
    vector<long long> over = [&]() {
        vector<long long> ok(Q, 998244353), ng(Q, 0), mid(Q);
        while (true) {
            vector<int> app, idx;
            for (int i = 0 ; i < Q ; i++)
                if (ok[i] - ng[i] > 1) {
                    mid[i] = (ok[i] + ng[i]) / 2;
                    app.push_back(mid[i]);
                    idx.push_back(i);
                }
            if (idx.empty())
                break;
            CompressedSequence comp(app);
            vector<vector<int>> query(comp.size());
            for (int i = 0 ; i < ssize(app) ; i++)
                query[comp.map(i)].push_back(idx[i]);
            FenwickTree<AdditiveGroup<long long>> fen(N);
            for (int i = 0, j = 0 ; j < ssize(query) ; j++) {
                while (i < ssize(buc) and compA.inverse(i) <= comp.inverse(j)) {
                    for (int k : buc[i])
                        fen.operation(k, A[k] - 1);
                    i++;
                }
                for (int k : query[j]) {
                    long long pd = fen.product(L[k], R[k]);
                    if (pd >= K[k])
                        ok[k] = mid[k];
                    else
                        ng[k] = mid[k];
                }
            }
        }
        return ok;
    }();
    // detect hoge
    vector<pair<int, long long>> bimyou = [&]() {
        vector<long long> app;
        vector<int> idx;
        for (int i = 0 ; i < Q ; i++) {
            if (1 < over[i] and over[i] < 998244353) {
                idx.push_back(i);
                app.push_back(over[i] - 1);
            }
        }
        CompressedSequence comp(app);
        vector<vector<int>> query(comp.size());
        for (int i = 0 ; i < ssize(app) ; i++)
            query[comp.map(i)].push_back(idx[i]);
        FenwickTree<AdditiveGroup<long long>> fen(N);
        vector<long long> res(Q, -1);
        vector<int> cnt(Q, -1);
        for (int i = 0, j = 0 ; j < ssize(query) ; j++) {
            while (i < ssize(buc) and compA.inverse(i) <= comp.inverse(j)) {
                for (int k : buc[i])
                    fen.operation(k, A[k] - 1);
                i++;
            }
            for (int k : query[j]) {
                long long pd = fen.product(L[k], R[k]);
                assert(pd < K[k]);
                cnt[k] = (K[k] - pd) / (over[k] - 1);
                res[k] = (K[k] - pd) % (over[k] - 1);
            }
        }
        vector<pair<int, long long>> tmp(Q);
        for (int i = 0 ; i < Q ; i++)
            tmp[i] = {cnt[i], res[i]};
        return tmp;
    }();
    vector<mint> ans = [&]() {
        vector<mint> res(Q);
        for (int i = 0 ; i < Q ; i++)
            if (over[i] == 998244353)
                res[i] = 1;
        vector<long long> app;
        vector<int> idx;
        for (int i = 0 ; i < Q ; i++) {
            if (1 < over[i] and over[i] < 998244353) {
                idx.push_back(i);
                app.push_back(over[i]);
            }
        }
        CompressedSequence comp(app);
        vector<vector<int>> query(comp.size());
        for (int i = 0 ; i < ssize(app) ; i++)
            query[comp.map(i)].push_back(idx[i]);
        FenwickTree<MULT> fen(N);
        for (int i = ssize(compA) - 1, j = ssize(comp) - 1 ; j >= 0 ; j--) {
            while (i >= 0 and compA.inverse(i) >= comp.inverse(j)) {
                for (int k : buc[i]) {
                    fen.assign(k, A[k]);
                }
                i--;
            }
            for (int k : query[j]) {
                mint pd = fen.product(L[k], R[k]);
                pd /= mint{over[k]}.pow(bimyou[k].first + 1);
                pd *= over[k] - bimyou[k].second;
                res[k] = pd;
            }
        }
        for (int i = 0 ; i < Q ; i++)
            if (over[i] == 1)
                res[i] = fen.product(L[i], R[i]);
        return res;
    }();
    for (mint a : ans)
        cout << a.val() << '\n';
#else
    cout << "Hello World\n";
#endif
}
