---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Point.hpp
    title: Src/GeometryZ2/Point.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/PointCloud.hpp
    title: Src/GeometryZ2/PointCloud.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Zahlen.hpp
    title: Src/GeometryZ2/Zahlen.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Baekjoon/23249.test.cpp
    title: Test/Baekjoon/23249.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/count_points_in_triangle.test.cpp
    title: Test/LC/count_points_in_triangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/My/GeometryZ2/Contain/CountingPointsInTrianglesStressTest.test.cpp
    title: Test/My/GeometryZ2/Contain/CountingPointsInTrianglesStressTest.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/UC/3-35-L.test.cpp
    title: Test/UC/3-35-L.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/GeometryZ2/Contain/CountPointsInTriangles.hpp\"\n\n\
    #line 2 \"Src/GeometryZ2/PointCloud.hpp\"\n\n#line 2 \"Src/GeometryZ2/Point.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/GeometryZ2/Zahlen.hpp\"\
    \n\n#line 4 \"Src/GeometryZ2/Zahlen.hpp\"\n\n#include <cassert>\n\nnamespace zawa\
    \ {\n\nnamespace geometryZ2 {\n\nusing Zahlen = i64;\n\nnamespace internal {\n\
    \nconstexpr i32 positive{1};\nconstexpr i32 zero{0};\nconstexpr i32 negative{-1};\n\
    \n} // namespace internal\n\nconstexpr i32 Sign(Zahlen value) {\n    if (value\
    \ < 0) return internal::negative;\n    if (value > 0) return internal::positive;\n\
    \    return internal::zero;\n}\n\nconstexpr bool Positive(Zahlen value) {\n  \
    \  return Sign(value) == internal::positive;\n}\n\nconstexpr bool Zero(Zahlen\
    \ value) {\n    return Sign(value) == internal::zero;\n}\n\nconstexpr bool Negative(Zahlen\
    \ value) {\n    return Sign(value) == internal::negative;\n}\n\nconstexpr Zahlen\
    \ Abs(Zahlen value) {\n    return (value > 0 ? value : -value);\n}\n\nconstexpr\
    \ Zahlen Square(Zahlen value) {\n    return value * value;\n}\n\n} // namespace\
    \ geometryZ2\n\n} // namespace zawa\n#line 5 \"Src/GeometryZ2/Point.hpp\"\n\n\
    #include <algorithm>\n#include <iostream>\n#line 9 \"Src/GeometryZ2/Point.hpp\"\
    \n#include <limits>\n\nnamespace zawa {\n\nnamespace geometryZ2 {\n\nclass Point\
    \ {\nprivate:\n    Zahlen x_{}, y_{};\n    static constexpr i32 origin{0};\n \
    \   static constexpr i32 firstQuadrant{1};\n    static constexpr i32 secondQuadrant{2};\n\
    \    static constexpr i32 thirdQuadrant{-2};\n    static constexpr i32 forthQuadrant{-1};\n\
    public:\n    /* constructor */\n    Point() = default;\n    Point(const Point&\
    \ p) : x_{p.x()}, y_{p.y()} {}\n    Point(Zahlen x, Zahlen y) : x_{x}, y_{y} {}\n\
    \n    /* getter setter */\n    Zahlen& x() {\n        return x_;\n    }\n    const\
    \ Zahlen& x() const {\n        return x_;\n    }\n    Zahlen& y() {\n        return\
    \ y_;\n    }\n    const Zahlen& y() const {\n        return y_;\n    }\n\n   \
    \ /* operator */\n    Point& operator=(const Point& p) {\n        x() = p.x();\n\
    \        y() = p.y();\n        return *this;\n    }\n    Point& operator+=(const\
    \ Point& p) {\n        x() += p.x();\n        y() += p.y();\n        return *this;\n\
    \    }\n    friend Point operator+(const Point& p0, const Point& p1) {\n     \
    \   return Point{p0} += p1;\n    }\n    Point& operator-=(const Point& p) {\n\
    \        x() -= p.x();\n        y() -= p.y();\n        return *this;\n    }\n\
    \    friend Point operator-(const Point& p0, const Point& p1) {\n        return\
    \ Point{p0} -= p1;\n    }\n    Point& operator*=(Zahlen k) {\n        x() *= k;\n\
    \        y() *= k;\n        return *this;\n    }\n    friend Point operator*(const\
    \ Point& p, Zahlen k) {\n        return Point{p} *= k;\n    }\n    friend Point\
    \ operator*(Zahlen k, const Point& p) {\n        return Point{p} *= k;\n    }\n\
    \    Point& operator/=(Zahlen k) {\n        assert(k);\n        assert(x() % k\
    \ == 0);\n        assert(y() % k == 0);\n        x() /= k;\n        y() /= k;\n\
    \        return *this;\n    }\n    friend Point operator/(const Point& p, Zahlen\
    \ k) {\n        return Point{p} /= k;\n    }\n    friend bool operator==(const\
    \ Point& p0, const Point& p1) {\n        return p0.x() == p1.x() and p0.y() ==\
    \ p1.y();\n    }\n    friend bool operator!=(const Point& p0, const Point& p1)\
    \ {\n        return p0.x() != p1.x() or p0.y() != p1.y();\n    }\n    friend bool\
    \ operator<(const Point& p0, const Point& p1) {\n        if (p0.x() != p1.x())\
    \ return p0.x() < p1.x();\n        else return p0.y() < p1.y();\n    }\n    friend\
    \ bool operator<=(const Point& p0, const Point& p1) {\n        return (p0 < p1)\
    \ or (p0 == p1);\n    }\n    friend bool operator>(const Point& p0, const Point&\
    \ p1) {\n        if (p0.x() != p1.x()) return p0.x() > p1.x();\n        else return\
    \ p0.y() > p1.y();\n    }\n    friend bool operator>=(const Point& p0, const Point&\
    \ p1) {\n        return (p0 > p1) or (p0 == p1);\n    }\n    friend std::istream&\
    \ operator>>(std::istream& is, Point& p) {\n        is >> p.x() >> p.y();\n  \
    \      return is;\n    }\n    friend std::ostream& operator<<(std::ostream& os,\
    \ const Point& p) {\n        os << '(' << p.x() << ',' << p.y() << ')';\n    \
    \    return os;\n    }\n\n    /* member function */\n    Zahlen normSquare() const\
    \ {\n        return Square(x()) + Square(y());\n    }\n    bool isNormSquareOver(Zahlen\
    \ d) const {\n        assert(!Negative(d));\n        auto [mn, mx]{std::minmax({\
    \ Abs(x()), Abs(y()) })};\n        if (mx and mx > d / mx) {\n            return\
    \ true;\n        }\n        long long s1{Square(mn)}, s2{Square(mx)};\n      \
    \  if (s1 > d - s2) {\n            return true;\n        }\n        return false;\n\
    \    }\n    bool isNormSquareOverflow() const {\n        return isNormSquareOver(std::numeric_limits<Zahlen>::max());\n\
    \    }\n\n    i32 area() const {\n        if (x_ == 0 and y_ == 0) return origin;\n\
    \        if (x_ <= 0 and y_ < 0) return thirdQuadrant;\n        if (x_ > 0 and\
    \ y_ <= 0) return forthQuadrant;\n        if (x_ >= 0 and y_ > 0) return firstQuadrant;\n\
    \        return secondQuadrant;\n    }\n\n    /* static member */\n    static\
    \ bool ArgComp(const Point& p0, const Point& p1) {\n        if (p0.area() != p1.area())\
    \ return p0.area() < p1.area();\n        Zahlen cross{Cross(p0, p1)};\n      \
    \  return (!Zero(cross) ? Positive(cross) : p0.normSquare() < p1.normSquare());\n\
    \    }\n\n    /* friend function */\n    friend Zahlen Dot(const Point& p0, const\
    \ Point& p1) {\n        return p0.x() * p1.x() + p0.y() * p1.y();\n    }\n   \
    \ friend Zahlen Cross(const Point& p0, const Point& p1) {\n        return p0.x()\
    \ * p1.y() - p0.y() * p1.x();\n    }\n};\nusing Vector = Point;\n\n} // namespace\
    \ geometryZ2\n\n} // namespace zawa\n#line 4 \"Src/GeometryZ2/PointCloud.hpp\"\
    \n\n#line 6 \"Src/GeometryZ2/PointCloud.hpp\"\n#include <vector>\n\nnamespace\
    \ zawa {\n\nnamespace geometryZ2 {\n\nusing PointCloud = std::vector<Point>;\n\
    \nvoid ArgSort(PointCloud& p) {\n    std::sort(p.begin(), p.end(), Point::ArgComp);\n\
    }\n\n} // namespace geometryZ2 \n\n} // namespace zawa\n#line 4 \"Src/GeometryZ2/Contain/CountPointsInTriangles.hpp\"\
    \n\n#line 6 \"Src/GeometryZ2/Contain/CountPointsInTriangles.hpp\"\n#include <numeric>\n\
    #include <utility>\n#line 9 \"Src/GeometryZ2/Contain/CountPointsInTriangles.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryZ2 {\n\nclass CountPointsInTriangles\
    \ {\npublic:\n\n    CountPointsInTriangles(PointCloud a, PointCloud b) \n    \
    \    : m_a(a.size()), m_under(a.size()), m_eq(a.size()), m_on(a.size()), m_cover(a.size()),\
    \ m_inv(a.size()) {\n        {\n            std::vector<std::pair<Point, usize>>\
    \ idxs(m_a.size());\n            for (usize i = 0 ; i < m_a.size() ; i++) {\n\
    \                m_on[i].resize(m_a.size() - i);\n                m_cover[i].resize(m_a.size()\
    \ - i);\n                idxs[i].first = std::move(a[i]);\n                idxs[i].second\
    \ = i;\n            }\n            std::sort(idxs.begin(), idxs.end());\n    \
    \        for (usize i = 0 ; i < m_a.size() ; i++) {\n                m_a[i] =\
    \ std::move(idxs[i].first);\n                m_inv[idxs[i].second] = i;\n    \
    \        }\n        }\n        std::sort(b.begin(), b.end());\n        // calc\
    \ m_under and m_eq\n        for (usize i = 0 ; i < m_a.size() ; i++) {\n     \
    \       for (usize j = 0 ; j < b.size() and b[j].x() <= m_a[i].x() ; j++) {\n\
    \                if (b[j].x() == m_a[i].x()) {\n                    if (b[j].y()\
    \ < m_a[i].y()) m_under[i]++;\n                    else if (b[j].y() == m_a[i].y())\
    \ m_eq[i]++;\n                }\n            } \n        }\n        // calc m_cover,\
    \ m_on\n        for (usize i = 0 ; i < m_a.size() ; i++) {\n            std::vector<std::pair<Point,\
    \ usize>> dj;\n            std::vector<Vector> dirs;\n            {\n        \
    \        std::vector<std::pair<Point, usize>> da, db;\n                for (usize\
    \ j = i + 1 ; j < m_a.size() ; j++) if (m_a[i] != m_a[j]) {\n                \
    \    da.push_back({m_a[j]-m_a[i], j});\n                }\n                for\
    \ (const auto& q : b) if (m_a[i].x() <= q.x() and m_a[i] != q) {\n           \
    \         db.emplace_back(q-m_a[i],std::numeric_limits<usize>::max());\n     \
    \               dirs.push_back(q-m_a[i]);\n                }\n               \
    \ std::ranges::sort(db);\n                dj.resize(db.size() + da.size());\n\
    \                for (usize j = 0, k = 0, t = 0 ; t < dj.size() ; t++) {\n   \
    \                 if (k == db.size()) dj[t] = std::move(da[j++]);\n          \
    \          else if (j == da.size()) dj[t] = std::move(db[k++]);\n            \
    \        else if (da[j] < db[k]) dj[t] = std::move(da[j++]);\n               \
    \     else dj[t] = std::move(db[k++]);\n                }\n            }\n   \
    \         std::ranges::sort(dirs, Point::ArgComp);\n            dirs.erase(\n\
    \                    std::unique(dirs.begin(), dirs.end(), [&](const auto& l,\
    \ const auto& r) { return Zero(Cross(l, r)) and !Negative(Dot(l, r)); }), \n \
    \                   dirs.end());\n            std::vector<u32> fen(dirs.size()\
    \ + 1), dat(dirs.size());\n            for (const auto& [d, j] : dj) {\n     \
    \           if (j == std::numeric_limits<usize>::max()) {\n                  \
    \  auto it = std::distance(\n                            dirs.begin(), \n    \
    \                        std::ranges::lower_bound(dirs, d, [](const Point& l,\
    \ const Point& r) {\n                                    if (l.area() != r.area())\
    \ return l.area() < r.area();\n                                    return Positive(Cross(l,\
    \ r));\n                                })\n                            );\n \
    \                   dat[it]++;\n                    for (it++ ; it < std::ssize(fen)\
    \ ; it += it & -it) fen[it]++;\n                }\n                else {\n  \
    \                  auto it = std::distance(dirs.begin(), std::ranges::upper_bound(dirs,\
    \ d, Point::ArgComp));\n                    if (it and Zero(Cross(d, dirs[it -\
    \ 1])) and !Negative(Dot(d, dirs[it - 1]))) {\n                        m_on[i][j\
    \ - i] = dat[it - 1];\n                    }\n                    for ( ; it ;\
    \ it -= it & -it) m_cover[i][j - i] += fen[it];\n                }\n         \
    \   }\n        }\n    }\n\n    inline usize size() const {\n        return m_a.size();\n\
    \    }\n\n    // strictly inside\n    u32 operator()(usize i, usize j, usize k)\
    \ const {\n        assert(i < size() and j < size() and k < size());\n       \
    \ if (i == j or j == k or i == k) return 0;\n        i = m_inv[i];\n        j\
    \ = m_inv[j];\n        k = m_inv[k];\n        if (m_a[i] == m_a[j] or m_a[j] ==\
    \ m_a[k] or m_a[k] == m_a[i]) return 0;\n        if (m_a[i] > m_a[j]) std::swap(i,\
    \ j);\n        if (m_a[j] > m_a[k]) std::swap(j, k);\n        if (m_a[i] > m_a[j])\
    \ std::swap(i, j);\n        // std::cout << i << ' ' << j << ' ' << k << std::endl;\n\
    \        const Zahlen crs = Cross(m_a[j] - m_a[i], m_a[k] - m_a[i]);\n       \
    \ if (crs == 0) {\n            return 0;\n        }\n        else if (crs > 0)\
    \ {\n            return cover(i, k) - cover(i, j) - cover(j, k) - m_eq[j] + m_under[j]\
    \ - on(i, k);\n        }\n        else {\n            return cover(i, j) + cover(j,\
    \ k) - cover(i, k) - m_under[j] - on(i, j) - on(j, k);\n        }\n    }\n   \
    \ \nprivate:\n\n    std::vector<Point> m_a;\n\n    std::vector<u32> m_under, m_eq;\n\
    \n    std::vector<std::vector<u32>> m_on, m_cover;\n    \n    std::vector<usize>\
    \ m_inv;\n\n    u32 cover(usize i, usize j) const {\n        if (i > j) std::swap(i,\
    \ j);\n        return m_cover[i][j - i];\n    }\n\n    u32 on(usize i, usize j)\
    \ const {\n        if (i > j) std::swap(i, j);\n        return m_on[i][j - i];\n\
    \    }\n};\n\n} // namespace geometryZ2\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../PointCloud.hpp\"\n\n#include <limits>\n#include\
    \ <numeric>\n#include <utility>\n#include <vector>\n\nnamespace zawa {\n\nnamespace\
    \ geometryZ2 {\n\nclass CountPointsInTriangles {\npublic:\n\n    CountPointsInTriangles(PointCloud\
    \ a, PointCloud b) \n        : m_a(a.size()), m_under(a.size()), m_eq(a.size()),\
    \ m_on(a.size()), m_cover(a.size()), m_inv(a.size()) {\n        {\n          \
    \  std::vector<std::pair<Point, usize>> idxs(m_a.size());\n            for (usize\
    \ i = 0 ; i < m_a.size() ; i++) {\n                m_on[i].resize(m_a.size() -\
    \ i);\n                m_cover[i].resize(m_a.size() - i);\n                idxs[i].first\
    \ = std::move(a[i]);\n                idxs[i].second = i;\n            }\n   \
    \         std::sort(idxs.begin(), idxs.end());\n            for (usize i = 0 ;\
    \ i < m_a.size() ; i++) {\n                m_a[i] = std::move(idxs[i].first);\n\
    \                m_inv[idxs[i].second] = i;\n            }\n        }\n      \
    \  std::sort(b.begin(), b.end());\n        // calc m_under and m_eq\n        for\
    \ (usize i = 0 ; i < m_a.size() ; i++) {\n            for (usize j = 0 ; j < b.size()\
    \ and b[j].x() <= m_a[i].x() ; j++) {\n                if (b[j].x() == m_a[i].x())\
    \ {\n                    if (b[j].y() < m_a[i].y()) m_under[i]++;\n          \
    \          else if (b[j].y() == m_a[i].y()) m_eq[i]++;\n                }\n  \
    \          } \n        }\n        // calc m_cover, m_on\n        for (usize i\
    \ = 0 ; i < m_a.size() ; i++) {\n            std::vector<std::pair<Point, usize>>\
    \ dj;\n            std::vector<Vector> dirs;\n            {\n                std::vector<std::pair<Point,\
    \ usize>> da, db;\n                for (usize j = i + 1 ; j < m_a.size() ; j++)\
    \ if (m_a[i] != m_a[j]) {\n                    da.push_back({m_a[j]-m_a[i], j});\n\
    \                }\n                for (const auto& q : b) if (m_a[i].x() <=\
    \ q.x() and m_a[i] != q) {\n                    db.emplace_back(q-m_a[i],std::numeric_limits<usize>::max());\n\
    \                    dirs.push_back(q-m_a[i]);\n                }\n          \
    \      std::ranges::sort(db);\n                dj.resize(db.size() + da.size());\n\
    \                for (usize j = 0, k = 0, t = 0 ; t < dj.size() ; t++) {\n   \
    \                 if (k == db.size()) dj[t] = std::move(da[j++]);\n          \
    \          else if (j == da.size()) dj[t] = std::move(db[k++]);\n            \
    \        else if (da[j] < db[k]) dj[t] = std::move(da[j++]);\n               \
    \     else dj[t] = std::move(db[k++]);\n                }\n            }\n   \
    \         std::ranges::sort(dirs, Point::ArgComp);\n            dirs.erase(\n\
    \                    std::unique(dirs.begin(), dirs.end(), [&](const auto& l,\
    \ const auto& r) { return Zero(Cross(l, r)) and !Negative(Dot(l, r)); }), \n \
    \                   dirs.end());\n            std::vector<u32> fen(dirs.size()\
    \ + 1), dat(dirs.size());\n            for (const auto& [d, j] : dj) {\n     \
    \           if (j == std::numeric_limits<usize>::max()) {\n                  \
    \  auto it = std::distance(\n                            dirs.begin(), \n    \
    \                        std::ranges::lower_bound(dirs, d, [](const Point& l,\
    \ const Point& r) {\n                                    if (l.area() != r.area())\
    \ return l.area() < r.area();\n                                    return Positive(Cross(l,\
    \ r));\n                                })\n                            );\n \
    \                   dat[it]++;\n                    for (it++ ; it < std::ssize(fen)\
    \ ; it += it & -it) fen[it]++;\n                }\n                else {\n  \
    \                  auto it = std::distance(dirs.begin(), std::ranges::upper_bound(dirs,\
    \ d, Point::ArgComp));\n                    if (it and Zero(Cross(d, dirs[it -\
    \ 1])) and !Negative(Dot(d, dirs[it - 1]))) {\n                        m_on[i][j\
    \ - i] = dat[it - 1];\n                    }\n                    for ( ; it ;\
    \ it -= it & -it) m_cover[i][j - i] += fen[it];\n                }\n         \
    \   }\n        }\n    }\n\n    inline usize size() const {\n        return m_a.size();\n\
    \    }\n\n    // strictly inside\n    u32 operator()(usize i, usize j, usize k)\
    \ const {\n        assert(i < size() and j < size() and k < size());\n       \
    \ if (i == j or j == k or i == k) return 0;\n        i = m_inv[i];\n        j\
    \ = m_inv[j];\n        k = m_inv[k];\n        if (m_a[i] == m_a[j] or m_a[j] ==\
    \ m_a[k] or m_a[k] == m_a[i]) return 0;\n        if (m_a[i] > m_a[j]) std::swap(i,\
    \ j);\n        if (m_a[j] > m_a[k]) std::swap(j, k);\n        if (m_a[i] > m_a[j])\
    \ std::swap(i, j);\n        // std::cout << i << ' ' << j << ' ' << k << std::endl;\n\
    \        const Zahlen crs = Cross(m_a[j] - m_a[i], m_a[k] - m_a[i]);\n       \
    \ if (crs == 0) {\n            return 0;\n        }\n        else if (crs > 0)\
    \ {\n            return cover(i, k) - cover(i, j) - cover(j, k) - m_eq[j] + m_under[j]\
    \ - on(i, k);\n        }\n        else {\n            return cover(i, j) + cover(j,\
    \ k) - cover(i, k) - m_under[j] - on(i, j) - on(j, k);\n        }\n    }\n   \
    \ \nprivate:\n\n    std::vector<Point> m_a;\n\n    std::vector<u32> m_under, m_eq;\n\
    \n    std::vector<std::vector<u32>> m_on, m_cover;\n    \n    std::vector<usize>\
    \ m_inv;\n\n    u32 cover(usize i, usize j) const {\n        if (i > j) std::swap(i,\
    \ j);\n        return m_cover[i][j - i];\n    }\n\n    u32 on(usize i, usize j)\
    \ const {\n        if (i > j) std::swap(i, j);\n        return m_on[i][j - i];\n\
    \    }\n};\n\n} // namespace geometryZ2\n\n} // namespace zawa\n"
  dependsOn:
  - Src/GeometryZ2/PointCloud.hpp
  - Src/GeometryZ2/Point.hpp
  - Src/Template/TypeAlias.hpp
  - Src/GeometryZ2/Zahlen.hpp
  isVerificationFile: false
  path: Src/GeometryZ2/Contain/CountPointsInTriangles.hpp
  requiredBy: []
  timestamp: '2025-04-30 16:41:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/count_points_in_triangle.test.cpp
  - Test/My/GeometryZ2/Contain/CountingPointsInTrianglesStressTest.test.cpp
  - Test/Baekjoon/23249.test.cpp
  - Test/UC/3-35-L.test.cpp
documentation_of: Src/GeometryZ2/Contain/CountPointsInTriangles.hpp
layout: document
title: Count Points in Triangles
---

```
CountPointsInTriangles(PointCloud A, PointCloud B)
```

`A`が三角形の頂点の候補、`B`が対象の点群

```
u32 operator()(usize i, usize j, usize k) const
```

で`A`の $3$ 点を指定し、三角形の**真に内部に**存在するような`B`上の点の個数を`u32`で返す。

計算量は`|A|`を $N$ 、 `|B|`を $M$ とすると前計算 $\Theta(N(N+M)\log M)$ 、クエリ毎 $\Theta(1)$ 
