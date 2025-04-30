---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Contain/CountPointsInTriangles.hpp
    title: Count Points in Triangles
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Contain/NaiveCountPointsInTriangles.hpp
    title: Src/GeometryZ2/Contain/NaiveCountPointsInTriangles.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Point.hpp
    title: Src/GeometryZ2/Point.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/PointCloud.hpp
    title: Src/GeometryZ2/PointCloud.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Relation.hpp
    title: Src/GeometryZ2/Relation.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Zahlen.hpp
    title: Src/GeometryZ2/Zahlen.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/My/GeometryZ2/Contain/CountingPointsInTrianglesStressTest.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/GeometryZ2/Contain/CountPointsInTriangles.hpp\"\n\n#line 2 \"\
    Src/GeometryZ2/PointCloud.hpp\"\n\n#line 2 \"Src/GeometryZ2/Point.hpp\"\n\n#line\
    \ 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
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
    \    }\n};\n\n} // namespace geometryZ2\n\n} // namespace zawa\n#line 2 \"Src/GeometryZ2/Contain/NaiveCountPointsInTriangles.hpp\"\
    \n\n#line 2 \"Src/GeometryZ2/Relation.hpp\"\n\n#line 5 \"Src/GeometryZ2/Relation.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryZ2 {\n\nenum RELATION {\n    // p0 ->\
    \ p1 -> p2\u306E\u9806\u3067\u76F4\u7DDA\u4E0A\u306B\u4E26\u3093\u3067\u3044\u308B\
    \n    ONLINE_FRONT        = -2,\n    // (p1 - p0) -> (p2 - p0)\u304C\u6642\u8A08\
    \u56DE\u308A\u306B\u306A\u3063\u3066\u3044\u308B\n    CLOCKWISE           = -1,\n\
    \    // p0 -> p2 -> p1\u306E\u9806\u3067\u76F4\u7DDA\u4E0A\u306B\u4E26\u3093\u3067\
    \u3044\u308B\n    ON_SEGMENT          =  0,\n    // (p1 - p0) -> (p2 - p0)\u304C\
    \u53CD\u6642\u8A08\u56DE\u308A\u306B\u306A\u3063\u3066\u3044\u308B\n    COUNTER_CLOCKWISE\
    \   = +1,\n    // p2 -> p0 -> p1\u3001\u307E\u305F\u306Fp1 -> p0 -> p2\u306E\u9806\
    \u3067\u76F4\u7DDA\u4E0A\u306B\u4E26\u3093\u3067\u3044\u308B\n    ONLINE_BACK\
    \         = +2\n};\n\nRELATION Relation(const Point& p0, const Point& p1, const\
    \ Point& p2) {\n    Point a{p1 - p0}, b{p2 - p0};\n    if (Positive(Cross(a, b)))\
    \ return COUNTER_CLOCKWISE;\n    if (Negative(Cross(a, b))) return CLOCKWISE;\n\
    \    if (Negative(Dot(a, b))) return ONLINE_BACK;\n    if (a.normSquare() < b.normSquare())\
    \ return ONLINE_FRONT;\n    return ON_SEGMENT;\n};\n\n} // namespace geometryZ2\n\
    \n} // namespace zawa\n#line 5 \"Src/GeometryZ2/Contain/NaiveCountPointsInTriangles.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryZ2 {\n\nclass NaiveCountPointsInTriangles\
    \ {\npublic:\n\n    NaiveCountPointsInTriangles(PointCloud a, PointCloud b) :\
    \ m_a{std::move(a)}, m_b{std::move(b)} {}\n\n    u32 operator()(u32 p, u32 q,\
    \ u32 r) const {\n        assert(p < size() and q < size() and r < size());\n\
    \        if (m_a[p] > m_a[q]) std::swap(p, q);\n        if (m_a[q] > m_a[r]) std::swap(q,\
    \ r);\n        if (m_a[p] > m_a[q]) std::swap(p, q);\n        RELATION R = Relation(m_a[p],\
    \ m_a[q], m_a[r]);\n        if (R == RELATION::ONLINE_FRONT or R == RELATION::ONLINE_BACK\
    \ or R == RELATION::ON_SEGMENT) return 0;\n        bool ctr = R == RELATION::COUNTER_CLOCKWISE;\n\
    \        u32 res = 0;\n        for (const Point& i : m_b) {\n            Zahlen\
    \ a = Cross(m_a[q] - m_a[p], i - m_a[p]), b = Cross(m_a[r] - m_a[q], i - m_a[q]),\
    \ c = Cross(m_a[p] - m_a[r], i - m_a[r]);\n            if (ctr and a > 0 and b\
    \ > 0 and c > 0) res++;\n            else if (!ctr and a < 0 and b < 0 and c <\
    \ 0) res++;\n        }\n        return res;\n    }\n\n    inline usize size()\
    \ const {\n        return m_a.size();\n    }\n\nprivate:\n\n    std::vector<Point>\
    \ m_a, m_b;\n};\n\n} // namespace geometryZ2\n\n} // namespace zawa\n#line 5 \"\
    Test/My/GeometryZ2/Contain/CountingPointsInTrianglesStressTest.test.cpp\"\n\n\
    #line 8 \"Test/My/GeometryZ2/Contain/CountingPointsInTrianglesStressTest.test.cpp\"\
    \n#include <random>\nusing namespace zawa;\nusing namespace geometryZ2;\n\nstd::mt19937\
    \ mt{std::random_device{}()};\n\nbool test(const int N, const int M, const int\
    \ X, const int Y) {\n    const int n = mt() % (N - 2) + 3;\n    const int m =\
    \ mt() % (M - 2) + 3;\n    std::vector<Point> a(n), b(m);\n    for (int i = 0\
    \ ; i < n ; i++) {\n        a[i].x() = mt() % (X + 1);\n        a[i].y() = mt()\
    \ % (Y + 1);\n    }\n    for (int i = 0 ; i < m ; i++) {\n        b[i].x() = mt()\
    \ % (X + 1);\n        b[i].y() = mt() % (Y + 1);\n    }\n    NaiveCountPointsInTriangles\
    \ ans(a, b);\n    CountPointsInTriangles my(a, b);\n    auto query = [&](int i,\
    \ int j, int k) -> bool {\n        int p = ans(i, j, k), q = my(i, j, k);\n  \
    \      if (p != q) {\n            std::cout << n << '\\n';\n            for (const\
    \ Point& v : a) std::cout << v.x() << ' ' << v.y() << '\\n';\n            std::cout\
    \ << m << '\\n';\n            for (const Point& v : b) std::cout << v.x() << '\
    \ ' << v.y() << '\\n';\n            std::cout << 1 << '\\n';\n            std::cout\
    \ << i << ' ' << j << ' ' << k << std::endl;\n            std::cerr << p << \"\
    \ but you output \" << q << std::endl;\n            return false;\n        }\n\
    \        return true;\n    };\n    for (int i = 0 ; i < std::ssize(a) ; i++) {\n\
    \        for (int j = 0 ; j < std::ssize(a) ; j++) {\n            for (int k =\
    \ 0 ; k < std::ssize(a) ; k++) {\n                if (!query(i, j, k)) return\
    \ false;\n            }\n        }\n    }\n    return true;\n}\n\nint main() {\n\
    \    for (int t = 0 ; t < 1000 ; t++) { // tiny\n        assert(test(5, 5, 5,\
    \ 5));\n    }\n    for (int t = 0 ; t < 100 ; t++) { // small dense\n        assert(test(20,\
    \ 20, 10, 10));\n    }\n    for (int t = 0 ; t < 100 ; t++) { // small\n     \
    \   assert(test(20, 20, 100, 100));\n    }\n    assert(test(50, 100, 100, 100));\n\
    \    std::cout << \"Hello World\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../../../Src/GeometryZ2/Contain/CountPointsInTriangles.hpp\"\
    \n#include \"../../../../Src/GeometryZ2/Contain/NaiveCountPointsInTriangles.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n#include <random>\nusing namespace\
    \ zawa;\nusing namespace geometryZ2;\n\nstd::mt19937 mt{std::random_device{}()};\n\
    \nbool test(const int N, const int M, const int X, const int Y) {\n    const int\
    \ n = mt() % (N - 2) + 3;\n    const int m = mt() % (M - 2) + 3;\n    std::vector<Point>\
    \ a(n), b(m);\n    for (int i = 0 ; i < n ; i++) {\n        a[i].x() = mt() %\
    \ (X + 1);\n        a[i].y() = mt() % (Y + 1);\n    }\n    for (int i = 0 ; i\
    \ < m ; i++) {\n        b[i].x() = mt() % (X + 1);\n        b[i].y() = mt() %\
    \ (Y + 1);\n    }\n    NaiveCountPointsInTriangles ans(a, b);\n    CountPointsInTriangles\
    \ my(a, b);\n    auto query = [&](int i, int j, int k) -> bool {\n        int\
    \ p = ans(i, j, k), q = my(i, j, k);\n        if (p != q) {\n            std::cout\
    \ << n << '\\n';\n            for (const Point& v : a) std::cout << v.x() << '\
    \ ' << v.y() << '\\n';\n            std::cout << m << '\\n';\n            for\
    \ (const Point& v : b) std::cout << v.x() << ' ' << v.y() << '\\n';\n        \
    \    std::cout << 1 << '\\n';\n            std::cout << i << ' ' << j << ' ' <<\
    \ k << std::endl;\n            std::cerr << p << \" but you output \" << q <<\
    \ std::endl;\n            return false;\n        }\n        return true;\n   \
    \ };\n    for (int i = 0 ; i < std::ssize(a) ; i++) {\n        for (int j = 0\
    \ ; j < std::ssize(a) ; j++) {\n            for (int k = 0 ; k < std::ssize(a)\
    \ ; k++) {\n                if (!query(i, j, k)) return false;\n            }\n\
    \        }\n    }\n    return true;\n}\n\nint main() {\n    for (int t = 0 ; t\
    \ < 1000 ; t++) { // tiny\n        assert(test(5, 5, 5, 5));\n    }\n    for (int\
    \ t = 0 ; t < 100 ; t++) { // small dense\n        assert(test(20, 20, 10, 10));\n\
    \    }\n    for (int t = 0 ; t < 100 ; t++) { // small\n        assert(test(20,\
    \ 20, 100, 100));\n    }\n    assert(test(50, 100, 100, 100));\n    std::cout\
    \ << \"Hello World\\n\";\n}\n"
  dependsOn:
  - Src/GeometryZ2/Contain/CountPointsInTriangles.hpp
  - Src/GeometryZ2/PointCloud.hpp
  - Src/GeometryZ2/Point.hpp
  - Src/Template/TypeAlias.hpp
  - Src/GeometryZ2/Zahlen.hpp
  - Src/GeometryZ2/Contain/NaiveCountPointsInTriangles.hpp
  - Src/GeometryZ2/Relation.hpp
  isVerificationFile: true
  path: Test/My/GeometryZ2/Contain/CountingPointsInTrianglesStressTest.test.cpp
  requiredBy: []
  timestamp: '2025-04-30 16:41:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/My/GeometryZ2/Contain/CountingPointsInTrianglesStressTest.test.cpp
layout: document
redirect_from:
- /verify/Test/My/GeometryZ2/Contain/CountingPointsInTrianglesStressTest.test.cpp
- /verify/Test/My/GeometryZ2/Contain/CountingPointsInTrianglesStressTest.test.cpp.html
title: Test/My/GeometryZ2/Contain/CountingPointsInTrianglesStressTest.test.cpp
---
