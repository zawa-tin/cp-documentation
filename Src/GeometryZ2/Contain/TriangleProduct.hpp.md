---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/CartesianProductGroup.hpp
    title: Src/Algebra/Group/CartesianProductGroup.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/GroupConcept.hpp
    title: Src/Algebra/Group/GroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/PowerableConcept.hpp
    title: Src/Algebra/PowerableConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Distance/PointAndPoint.hpp
    title: Src/GeometryZ2/Distance/PointAndPoint.hpp
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
    path: Test/AOJ/3451.test.cpp
    title: "AOJ3451 \u6700\u9AD8\u306E\u30B1\u30FC\u30AD\u3092\u4F5C\u308D\u3046 (colinear\u3067\
      \u306A\u3044\u51F8\u5305dp)"
  - icon: ':heavy_check_mark:'
    path: Test/LC/count_points_in_triangle/TriangleProduct.test.cpp
    title: Test/LC/count_points_in_triangle/TriangleProduct.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/GeometryZ2/Contain/TriangleProduct.hpp\"\n\n#line 2\
    \ \"Src/GeometryZ2/PointCloud.hpp\"\n\n#line 2 \"Src/GeometryZ2/Point.hpp\"\n\n\
    #line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
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
    }\n\n} // namespace geometryZ2 \n\n} // namespace zawa\n#line 2 \"Src/GeometryZ2/Distance/PointAndPoint.hpp\"\
    \n\n#line 5 \"Src/GeometryZ2/Distance/PointAndPoint.hpp\"\n\nnamespace zawa {\n\
    \nnamespace geometryZ2 {\n\nZahlen DistanceSquare(const Point& p0, const Point&\
    \ p1) {\n    return Vector{p1 - p0}.normSquare();\n}\n\n} // namespace geometryZ2\n\
    \n} // namespace zawa\n#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\n\n#line\
    \ 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T>\nconcept Semigroup = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Inversible\
    \ = requires {\n    typename T::Element;\n    { T::inverse(std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\ntemplate <class\
    \ T>\nconcept Group = Monoid<T> and Inversible<T>;\n\n} // namespace Concept\n\
    \n} // namespace zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace\
    \ zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n    using Element\
    \ = T;\n    static constexpr T identity() noexcept {\n        return T{};\n  \
    \  }\n    static constexpr T operation(T l,T r) noexcept {\n        return l +\
    \ r;\n    }\n    static constexpr T inverse(T v) noexcept {\n        return -v;\n\
    \    }\n    template <class U>\n    static constexpr T power(T v,U exp) noexcept\
    \ {\n        return v * static_cast<T>(exp);\n    }\n};\n\n} // namespace zawa\n\
    #line 2 \"Src/Algebra/Group/CartesianProductGroup.hpp\"\n\n#line 2 \"Src/Algebra/PowerableConcept.hpp\"\
    \n\n#line 4 \"Src/Algebra/PowerableConcept.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ concepts {\n\ntemplate <class T,class U>\nconcept Powerable = requires {\n \
    \   typename T::Element;\n    { T::power(std::declval<typename T::Element>(),\
    \ std::declval<U>()) }\n        -> std::same_as<typename T::Element>;\n};\n\n\
    } // namespace concepts\n\n} // namespace zawa\n#line 5 \"Src/Algebra/Group/CartesianProductGroup.hpp\"\
    \n\n#include <utility>\n\nnamespace zawa {\n\ntemplate <concepts::Group G1, concepts::Group\
    \ G2 = G1>\nclass CartesianProductGroup {\npublic:\n\n    using Element = std::pair<typename\
    \ G1::Element,typename G2::Element>;\n\n    static Element identity() {\n    \
    \    return {G1::identity(),G2::identity()};\n    }\n\n    static Element operation(const\
    \ Element& l,const Element& r) {\n        return {G1::operation(l.first,r.first),G2::operation(l.second,r.second)};\n\
    \    }\n\n    static Element inverse(const Element& v) {\n        return {G1::inverse(v.first),G2::inverse(v.second)};\n\
    \    }\n\n    template <class U>\n    static Element power(const Element& v,U\
    \ exp) requires (concepts::Powerable<G1,U> and concepts::Powerable<G2,U>) {\n\
    \        return {G1::power(v.first,exp),G2::power(v.second,exp)};\n    }\n};\n\
    \n} // namespace zawa\n#line 8 \"Src/GeometryZ2/Contain/TriangleProduct.hpp\"\n\
    \n#line 12 \"Src/GeometryZ2/Contain/TriangleProduct.hpp\"\n\nnamespace zawa {\n\
    \nnamespace geometryZ2 {\n\ntemplate <concepts::Group G>\nclass TriangleProduct\
    \ {\npublic:\n\n    using S = CartesianProductGroup<G,AdditiveGroup<i32>>;\n\n\
    \    using T = typename S::Element;\n\npublic:\n\n    TriangleProduct() = default;\n\
    \n    TriangleProduct(const PointCloud& A,const PointCloud& B,const std::vector<typename\
    \ G::Element>& W) \n        : m_n{A.size()}, m_m{B.size()}, m_a{A}, m_same(m_n,S::identity()),\
    \ m_exact(m_n,S::identity()),\n        m_low(m_n,std::vector(m_n,S::identity())),\
    \ m_onLine(m_n,std::vector(m_n,S::identity())) {\n        assert(B.size() == W.size());\n\
    \        for (usize i = 0 ; i < m_n ; i++)\n            for (usize j = 0 ; j <\
    \ m_m ; j++)\n                if (A[i].x() == B[j].x()) {\n                  \
    \  if (B[j].y() == A[i].y())\n                        m_exact[i] = S::operation(m_exact[i],T{W[j],1});\n\
    \                    if (B[j].y() <= A[i].y())\n                        m_same[i]\
    \ = S::operation(m_same[i],T{W[j],1});\n                }\n        for (usize\
    \ i = 0 ; i < m_n ; i++)\n            for (usize j = 0 ; j < m_n ; j++)\n    \
    \            if (i != j) {\n                    for (usize k = 0 ; k < m_m ; k++)\
    \ {\n                        if (Cross(A[j]-A[i],B[k]-A[i]) or Dot(A[j]-A[i],B[k]-A[i])\
    \ <= 0)\n                            continue;\n                        const\
    \ Zahlen d = Point{B[k]-A[i]}.normSquare();\n                        if (0 < d\
    \ and d < Point{A[j]-A[i]}.normSquare())\n                            m_onLine[i][j]\
    \ = S::operation(m_onLine[i][j],T{W[k],1});\n                    }\n         \
    \           for (usize k = 0 ; k < m_m ; k++) {\n                        if (B[k].x()\
    \ <= std::min(A[i].x(),A[j].x()) or std::max(A[i].x(),A[j].x()) <= B[k].x())\n\
    \                            continue;\n                        if (Cross(A[j]-A[i],B[k]-A[i])\
    \ >= 0)\n                            continue;\n                        m_low[i][j]\
    \ = S::operation(m_low[i][j],T{W[k],1});\n                    }\n            \
    \    }\n    }\n\n    TriangleProduct(const PointCloud& A,const std::vector<typename\
    \ G::Element>& W) : TriangleProduct(A,A,W) {}\n\n    T product(usize a,usize b,usize\
    \ c) const {\n        if (m_a[a] > m_a[b])\n            std::swap(a,b);\n    \
    \    if (m_a[b] > m_a[c])\n            std::swap(b,c);\n        if (m_a[a] > m_a[b])\n\
    \            std::swap(a,b);\n        const Zahlen crs = Cross(m_a[b]-m_a[a],m_a[c]-m_a[a]);\n\
    \        if (crs > 0) {\n            T res = S::operation(m_low[a][c],S::inverse(S::operation(m_low[a][b],m_low[b][c])));\n\
    \            if (m_a[a].x() < m_a[b].x())\n                res = S::operation(res,S::inverse(m_onLine[a][b]));\n\
    \            if (m_a[b].x() < m_a[c].x())\n                res = S::operation(res,S::inverse(m_onLine[b][c]));\n\
    \            if (m_a[a].x() < m_a[b].x() and m_a[b].x() < m_a[c].x())\n      \
    \          res = S::operation(res,S::inverse(m_same[b]));\n            return\
    \ res;\n        }\n        else if (crs < 0) {\n            T res = S::operation(S::operation(m_low[a][b],m_low[b][c]),\
    \ S::inverse(S::operation(m_low[a][c],m_onLine[a][c])));\n            if (m_a[a].x()\
    \ < m_a[b].x() and m_a[b].x() < m_a[c].x()) \n                res = S::operation(res,S::operation(m_same[b],S::inverse(m_exact[b])));\n\
    \            return res;\n        }\n        else\n            return S::identity();\n\
    \    }\n\n    T onLine(usize i,usize j) const {\n        return m_onLine[i][j];\n\
    \    }\n\n    T exact(usize i) const {\n        return m_exact[i];\n    }\n\n\
    private:\n\n    usize m_n, m_m;\n\n    std::vector<Point> m_a;\n\n    std::vector<T>\
    \ m_same, m_exact;\n\n    std::vector<std::vector<T>> m_low, m_onLine;\n\n\n};\n\
    \n} // namespace geometryZ2\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../PointCloud.hpp\"\n#include \"../Distance/PointAndPoint.hpp\"\
    \n#include \"../../Algebra/Group/GroupConcept.hpp\"\n#include \"../../Algebra/Group/AdditiveGroup.hpp\"\
    \n#include \"../../Algebra/Group/CartesianProductGroup.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\nnamespace geometryZ2\
    \ {\n\ntemplate <concepts::Group G>\nclass TriangleProduct {\npublic:\n\n    using\
    \ S = CartesianProductGroup<G,AdditiveGroup<i32>>;\n\n    using T = typename S::Element;\n\
    \npublic:\n\n    TriangleProduct() = default;\n\n    TriangleProduct(const PointCloud&\
    \ A,const PointCloud& B,const std::vector<typename G::Element>& W) \n        :\
    \ m_n{A.size()}, m_m{B.size()}, m_a{A}, m_same(m_n,S::identity()), m_exact(m_n,S::identity()),\n\
    \        m_low(m_n,std::vector(m_n,S::identity())), m_onLine(m_n,std::vector(m_n,S::identity()))\
    \ {\n        assert(B.size() == W.size());\n        for (usize i = 0 ; i < m_n\
    \ ; i++)\n            for (usize j = 0 ; j < m_m ; j++)\n                if (A[i].x()\
    \ == B[j].x()) {\n                    if (B[j].y() == A[i].y())\n            \
    \            m_exact[i] = S::operation(m_exact[i],T{W[j],1});\n              \
    \      if (B[j].y() <= A[i].y())\n                        m_same[i] = S::operation(m_same[i],T{W[j],1});\n\
    \                }\n        for (usize i = 0 ; i < m_n ; i++)\n            for\
    \ (usize j = 0 ; j < m_n ; j++)\n                if (i != j) {\n             \
    \       for (usize k = 0 ; k < m_m ; k++) {\n                        if (Cross(A[j]-A[i],B[k]-A[i])\
    \ or Dot(A[j]-A[i],B[k]-A[i]) <= 0)\n                            continue;\n \
    \                       const Zahlen d = Point{B[k]-A[i]}.normSquare();\n    \
    \                    if (0 < d and d < Point{A[j]-A[i]}.normSquare())\n      \
    \                      m_onLine[i][j] = S::operation(m_onLine[i][j],T{W[k],1});\n\
    \                    }\n                    for (usize k = 0 ; k < m_m ; k++)\
    \ {\n                        if (B[k].x() <= std::min(A[i].x(),A[j].x()) or std::max(A[i].x(),A[j].x())\
    \ <= B[k].x())\n                            continue;\n                      \
    \  if (Cross(A[j]-A[i],B[k]-A[i]) >= 0)\n                            continue;\n\
    \                        m_low[i][j] = S::operation(m_low[i][j],T{W[k],1});\n\
    \                    }\n                }\n    }\n\n    TriangleProduct(const\
    \ PointCloud& A,const std::vector<typename G::Element>& W) : TriangleProduct(A,A,W)\
    \ {}\n\n    T product(usize a,usize b,usize c) const {\n        if (m_a[a] > m_a[b])\n\
    \            std::swap(a,b);\n        if (m_a[b] > m_a[c])\n            std::swap(b,c);\n\
    \        if (m_a[a] > m_a[b])\n            std::swap(a,b);\n        const Zahlen\
    \ crs = Cross(m_a[b]-m_a[a],m_a[c]-m_a[a]);\n        if (crs > 0) {\n        \
    \    T res = S::operation(m_low[a][c],S::inverse(S::operation(m_low[a][b],m_low[b][c])));\n\
    \            if (m_a[a].x() < m_a[b].x())\n                res = S::operation(res,S::inverse(m_onLine[a][b]));\n\
    \            if (m_a[b].x() < m_a[c].x())\n                res = S::operation(res,S::inverse(m_onLine[b][c]));\n\
    \            if (m_a[a].x() < m_a[b].x() and m_a[b].x() < m_a[c].x())\n      \
    \          res = S::operation(res,S::inverse(m_same[b]));\n            return\
    \ res;\n        }\n        else if (crs < 0) {\n            T res = S::operation(S::operation(m_low[a][b],m_low[b][c]),\
    \ S::inverse(S::operation(m_low[a][c],m_onLine[a][c])));\n            if (m_a[a].x()\
    \ < m_a[b].x() and m_a[b].x() < m_a[c].x()) \n                res = S::operation(res,S::operation(m_same[b],S::inverse(m_exact[b])));\n\
    \            return res;\n        }\n        else\n            return S::identity();\n\
    \    }\n\n    T onLine(usize i,usize j) const {\n        return m_onLine[i][j];\n\
    \    }\n\n    T exact(usize i) const {\n        return m_exact[i];\n    }\n\n\
    private:\n\n    usize m_n, m_m;\n\n    std::vector<Point> m_a;\n\n    std::vector<T>\
    \ m_same, m_exact;\n\n    std::vector<std::vector<T>> m_low, m_onLine;\n\n\n};\n\
    \n} // namespace geometryZ2\n\n} // namespace zawa\n"
  dependsOn:
  - Src/GeometryZ2/PointCloud.hpp
  - Src/GeometryZ2/Point.hpp
  - Src/Template/TypeAlias.hpp
  - Src/GeometryZ2/Zahlen.hpp
  - Src/GeometryZ2/Distance/PointAndPoint.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/Algebra/Group/CartesianProductGroup.hpp
  - Src/Algebra/PowerableConcept.hpp
  isVerificationFile: false
  path: Src/GeometryZ2/Contain/TriangleProduct.hpp
  requiredBy: []
  timestamp: '2026-06-24 20:41:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/count_points_in_triangle/TriangleProduct.test.cpp
  - Test/AOJ/3451.test.cpp
documentation_of: Src/GeometryZ2/Contain/TriangleProduct.hpp
layout: document
title: "\u4E09\u89D2\u5F62\u306B\u542B\u307E\u308C\u308B\u70B9\u91CD\u307F\u306E\u7DCF\
  \u7A4D"
---

## ライブラリの使い方

```
template <concepts::Group G>
```

テンプレートに群を指定知る必要がある。さらに、**可換**である必要がある。

```cpp
TriangleProduct() = default;
TriangleProduct(const PointCloud& A,const PointCloud& B,const std::vector<typename G::Element>& W);
TriangleProduct(const PointCloud& A,const std::vector<typename G::Element>& W) : TriangleProduct(A,A,W);
```

コンストラクタ $A$ から三点選んでその三角形に属している $B$ の点の重み $W_{i}$ の`G`による総積を計算する。

`B.size()==W.size()`が必要で、そうでないと`assert`にひっかかる

```cpp
T product(usize a,usize b,usize c) const
```

$A_{a},A_{b},A_{c}$の凸包に**真に内側に**含まれる$B$の点$B_{i}$の重み$W_{i}$の総積を計算する。

- `std::pair`が返ってきて、`first`は総積、`second`は点の個数

$a,b,c$はdistinctである必要はない。その場合は自明に空なので単位元が返ってくる。

```cpp
T onLine(usize i,usize j) const
```

$A_i,A_j$を端点とした線分に、端点を除いて含まれる$B$の点の総積を返す。返り値は`product`と同様

```cpp
T exact(usize i) const
```

$A_i$同じ位置にある$B$の点の総積を返す。

## 計算量

初期化に $\Theta(N^2M)$ 、クエリに $\Theta(1)$ 。ただし、`G::operation`が $O(1)$ であることを仮定している。
