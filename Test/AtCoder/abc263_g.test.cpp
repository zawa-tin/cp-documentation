#define PROBLEM "https://atcoder.jp/contests/abc263/tasks/abc263_g"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/Dinic.hpp"

#include <iostream>
#include <vector>

bool prime(int a) {
    for (long long i{2} ; i * i <= (long long)a ; i++) {
        if (a % i == 0) return false;
    }
    return a != 1;
}

int main() {
    using namespace zawa;
    SetFastIO();
    
    int n; std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i{} ; i < n ; i++) {
        std::cin >> a[i] >> b[i];
    }
    Dinic<long long> mf(2 * n + 2);
    int source{2 * n}, sink{2 * n + 1};
    const long long INF{(long long)1e13};
    for (int i{} ; i < n ; i++) {
        if (a[i] % 2 == 0) {
            mf.addEdge(source, i, b[i]);
        }
        else {
            if (a[i] == 1) continue;
            mf.addEdge(i + n, sink, b[i]);
        }
    }
    for (int i{} ; i < n ; i++) {
        if (a[i] % 2 == 1) continue;
        for (int j{} ; j < n ; j++) {
            if (a[j] % 2 == 0) continue;
            if (a[j] == 1) continue;
            if (!prime(a[i] + a[j])) continue;
            mf.addEdge(i, n + j, INF);
        }
    }
    long long ans{mf.flow(source, sink)};
    for (int i{} ; i < n ; i++) if (a[i] == 1) {
        long long cnt{b[i]};
        int id{(int)mf.addEdge(n + i, sink, cnt)};
        for (int j{} ; j < n ; j++) if (a[j] % 2 == 0) {
            if (!prime(a[i] + a[j])) continue;
            mf.addEdge(j, n + i, INF);
        }
        ans += mf.flow(source, sink);
        cnt -= mf.flowed(id);
        ans += cnt >> 1;
        break;
    }
    std::cout << ans << '\n';
}
