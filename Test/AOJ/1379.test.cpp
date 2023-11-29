#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1379"

#include "../../Src/GeometryZ2/Point.hpp"
#include "../../Src/GeometryZ2/Segment.hpp"
#include "../../Src/GeometryZ2/Parallel/SegmentAndSegment.hpp"

#include <iostream>
#include <vector>

int main() {
    using namespace zawa::geometryZ2;
    int n; std::cin >> n;
    std::vector<Point> p(n);
    for (auto& v : p) std::cin >> v.x() >> v.y();

    auto check{[&](const std::vector<Segment>& s) -> int{
        int res{};
        for (int i{} ; i < (int)s.size() ; i++) {
            for (int j{i + 1} ; j < (int)s.size() ; j++) {
                res += Parallel(s[i], s[j]);
            }
        }
        return res;
    }};

    auto dfs{[&](auto dfs, int i, std::vector<Segment>& cur, std::vector<bool>& used) -> int {
        if (i == n) return check(cur);
        int res{};
        res = std::max(res, dfs(dfs, i + 1, cur, used));
        if (!used[i]) {
            used[i] = true;
            for (int j{i + 1} ; j < n ; j++) if (!used[j]) {
                used[j] = true;
                cur.emplace_back(p[i], p[j]);
                res = std::max(res, dfs(dfs, i + 1, cur, used));
                cur.pop_back();
                used[j] = false;
            }
            used[i] = false;
        }
        return res;
    }};

    std::vector<Segment> s;
    std::vector<bool> used(n);
    int ans{dfs(dfs, 0, s, used)};
    std::cout << ans << '\n';
}
