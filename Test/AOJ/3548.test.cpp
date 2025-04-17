#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AOJ3548 String Puzzle
 * https://onlinejudge.u-aizu.ac.jp/status/users/zawakasu/submissions/1/3548/judge/10394036/C++20
 */

#include <iostream>
#include <string>
#include <unordered_set>

#include "../../Src/Sequence/EnumerateStaticLengthProduct.hpp"
#include "../../Src/Algebra/Monoid/RollingHashMonoid.hpp"

using namespace zawa;

using Monoid = RollingHashMonoid;
using E = Monoid::Element;
using V = E::Value;

V E::base{
    E::randomValue(26)
};

std::vector<E> input() {
    std::string S;
    std::cin >> S;
    std::vector<E> A(S.size());
    for (int i{} ; i < (int)S.size() ; i++) {
        A[i] = E{S[i]};
    }
    return A;
}

bool check(const std::vector<E>& S, const std::vector<E>& T) {
    std::unordered_set<V> set;
    for (const auto& hash : T) set.insert(hash.hash);
    bool ok{true};
    for (const auto& hash : S) ok &= set.find(hash.hash) != set.end();
    return ok;
}

int solve() {
    int N, M, K;
    std::cin >> N >> M >> K;
    std::vector<E> S(input());
    std::vector<E> T(input());
    if (!check(S, T)) return -1;
    std::unordered_set<V> set;
    for (const auto& hash : EnumerateStaticLengthProduct<Monoid>(T, K)) {
        set.insert(hash.hash);
    }
    std::vector<E> P(EnumerateStaticLengthProduct<Monoid>(S, K));
    int ans{};
    for (int i{} ; i < (int)P.size() ; ) {
        if (set.find(P[i].hash) == set.end()) {
            i++;
        }
        else {
            ans++;
            i += K;
        }
    }
    return ans;
}

int main() {
#ifdef ONLINE_JUDGE
    std::cout << solve() << '\n';
#else
    std::cout << "Hello World" << '\n';
#endif
}
