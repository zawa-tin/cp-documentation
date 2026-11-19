// #define PROBLEM "https://atcoder.jp/contests/abc484/tasks/abc484_g"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AtCoder Beginner Contest 484 G - Wildcard Construction
 * https://atcoder.jp/contests/abc484/submissions/80932848
 */
#include "../../Src/Sequence/PowersetConstruction.hpp"
using namespace zawa;
#include "atcoder/modint.hpp"
using mint=atcoder::modint998244353;
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    string S,X,Y;
    cin >> S >> X >> Y;
    const int g1=ssize(X)+ssize(Y),g2=g1+1;
    PowersetConstruction<int,int> nfa(ssize(X)+ssize(Y)+2,2,g1,vector<int>{g1,g2});
    auto addEdge=[&](int from,int to,char c){
        if (c!='1')
            nfa.addTransition(from,to,0);
        if (c!='0')
            nfa.addTransition(from,to,1);
    };
    addEdge(g1,0,X[0]);
    for (int i = 1 ; i < ssize(X) ; i++)
        addEdge(i-1,i,X[i]);
    nfa.addEpsilonTransition(ssize(X)-1,g1);
    addEdge(g1,ssize(X),Y[0]);
    for (int i = 1 ; i < ssize(Y) ; i++)
        addEdge(ssize(X)+i-1,ssize(X)+i,Y[i]);
    nfa.addEpsilonTransition(ssize(X)+ssize(Y)-1,g2); 
    addEdge(g2,0,X[0]);
    auto [g,ok]=nfa.build();
    std::vector<mint> dp(g.size());
    dp[0]=1;
    for (char c : S) {
        std::vector<mint> nxt(g.size());
        for (int i = 0 ; i < ssize(g) ; i++) {
            if (c!='1' and g[i][0]!=ssize(g))
                nxt[g[i][0]]+=dp[i];
            if (c!='0' and g[i][1]!=ssize(g))
                nxt[g[i][1]]+=dp[i];
        }
        dp=move(nxt);
    }
    mint ans=0;
    for (int i = 0 ; i < ssize(g) ; i++)
        if (ok[i])
            ans+=dp[i];
    cout << ans.val() << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
