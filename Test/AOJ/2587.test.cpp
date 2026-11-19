#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2587"
#include "../../Src/Sequence/PowersetConstruction.hpp"
using namespace zawa;
#include <cassert>
#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
bool solve() {
    int N;
    cin >> N;
    if (N == 0)
        return false;
    vector<pair<int,int>> LH(N);
    for (auto& [low,high] : LH)
        cin >> low >> high;
    vector<tuple<int,int,int>> to; 
    int n=0;
    // コード汚すぎ！
    auto add=[&](vector<int> prevs,int low,int high)->vector<int>{
        if (high < 10) {
            int cur=n++;
            for (int i = low ; i <= high ; i++)
                for (int from : prevs)
                    to.push_back({from,cur,i});
            return {cur};
        }
        else if (low < 10) {
            int l=n++;
            int m=n++;
            int mm=n++;
            int r=n++;
            int rr=n++;
            for (int i = low ; i <= 9 ; i++)
                for (int from : prevs)
                    to.push_back({from,l,i});
            for (int i = 1 ; i < high/10 ; i++)
                for (int from : prevs)
                    to.push_back({from,m,i});
            for (int from : prevs)
                to.push_back({from,r,high/10});
            for (int i = 0 ; i <= 9 ; i++)
                to.push_back({m,mm,i});
            for (int i = 0 ; i <= high%10 ; i++)
                to.push_back({r,rr,i});
            return {l,mm,rr};
        }
        else if (low/10%10==high/10%10) {
            int v1=n++;
            int v2=n++;
            for (int from : prevs)
                to.push_back({from,v1,low/10});
            for (int i = low%10 ; i <= high%10 ; i++)
                to.push_back({v1,v2,i});
            return {v2};
        }
        else {
            int l=n++;
            int ll=n++;
            int m=n++;
            int mm=n++;
            int r=n++;
            int rr=n++;
            for (int from : prevs)
                to.push_back({from,l,low/10});
            for (int i = low/10+1 ; i < high/10 ; i++)
                for (int from : prevs)
                    to.push_back({from,m,i});
            for (int from : prevs)
                to.push_back({from,r,high/10});
            for (int i = low%10 ; i <= 9 ; i++)
                to.push_back({l,ll,i});
            for (int i = 0 ; i <= 9 ; i++)
                to.push_back({m,mm,i});
            for (int i = 0 ; i <= high%10 ; i++)
                to.push_back({r,rr,i});
            return {ll,mm,rr};
        }
    };
    const int st=n++;
    auto last=add({0},LH[0].first,LH[0].second);
    for (int i = 1 ; i < N ; i++)
        last=add(last,LH[i].first,LH[i].second);
    const int gl=n++; 
    PowersetConstruction<int,int> nfa(n,10,st,{gl});
    for (auto [from,to,i] : to)
        nfa.addTransition(from,to,i);
    for (int v : last)
        nfa.addEpsilonTransition(v,gl);
    auto [g,ok]=nfa.build();
    vector<long long> dp(ssize(g));
    vector<int> deg(ssize(g));
    for (int i = 0 ; i < ssize(g) ; i++)
        for (int j = 0 ; j < 10 ; j++)
            if (g[i][j]<ssize(g))
                deg[g[i][j]]++;
    assert(deg[0]==0);
    vector<int> que;
    for (int i = 0 ; i < ssize(g) ; i++)
        if (deg[i]==0)
            que.push_back(i);
    dp[0]=1;
    for (int t = 0 ; t < ssize(que) ; t++) {
        int v = que[t];
        for (int x : g[v]) 
            if (x<ssize(g)) {
                dp[x]+=dp[v];
                deg[x]--;
                if (deg[x]==0)
                    que.push_back(x);
            }
    }
    long long ans=0;
    for (int i = 0 ; i < ssize(g) ; i++)
        if (ok[i])
            ans+=dp[i];
    cout << ans << '\n';
    return true;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    while (solve()) ;
}
