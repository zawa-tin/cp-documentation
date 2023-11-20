#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0388"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/GeometryZ2/Point.hpp"
#include "../../Src/GeometryZ2/Line.hpp"

#include <algorithm>
#include <vector>

int main() {
    using namespace zawa;
    using namespace geometryZ2;
    SetFastIO();
    int n, k; std::cin >> n >> k;
    std::vector<Point> p(n);
    for (auto& v : p) std::cin >> v;
    std::vector<Line> all;
    for (int i{} ; i < n ; i++) {
        std::vector<Line> now;
        for (int j{i + 1} ; j < n ; j++) {
            now.emplace_back(p[i], p[j]);
        }
        std::sort(now.begin(), now.end());
        auto m{std::distance(now.begin(), std::unique(now.begin(), now.end()))};
        for (int j{} ; j < m ; j++) {
            all.push_back(now[j]);
        }
    }
    std::sort(all.begin(), all.end());
    bool ans{};
    int r{};
    for (int l{} ; l < (int)all.size() ; l = r) {
        while (r < (int)all.size() and all[l] == all[r]) r++;
        ans |= (r - l + 1) >= k;
    }
    std::cout << ans << '\n';
}
