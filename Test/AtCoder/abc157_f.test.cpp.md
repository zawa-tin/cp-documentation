---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Angle.hpp
    title: Src/GeometryR2/Angle.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Circle.hpp
    title: Src/GeometryR2/Circle.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Contain/CircleContainsPoint.hpp
    title: Src/GeometryR2/Contain/CircleContainsPoint.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Contain/State.hpp
    title: Src/GeometryR2/Contain/State.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/CrossPoint/CircleAndCircle.hpp
    title: Src/GeometryR2/CrossPoint/CircleAndCircle.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Distance/PointAndPoint.hpp
    title: Src/GeometryR2/Distance/PointAndPoint.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Intersect/CircleAndCircle.hpp
    title: Src/GeometryR2/Intersect/CircleAndCircle.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Point.hpp
    title: Src/GeometryR2/Point.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Real.hpp
    title: Src/GeometryR2/Real.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/BinarySearch.hpp
    title: "\u4E8C\u5206\u63A2\u7D22"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: https://atcoder.jp/contests/abc157/tasks/abc157_f
    links:
    - https://atcoder.jp/contests/abc157/tasks/abc157_f
  bundledCode: "#line 1 \"Test/AtCoder/abc157_f.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc157/tasks/abc157_f\"\
    \n#define ERROR 0.000001\n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2\
    \ \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\n\
    namespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\
    \n\n#include <iostream>\n#include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO()\
    \ {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n}\n\nvoid SetPrecision(u32\
    \ dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Utility/BinarySearch.hpp\"\n\n#line 4 \"Src/Utility/BinarySearch.hpp\"\
    \n\n#include <cmath>\n#include <functional>\n#include <type_traits>\n#include\
    \ <utility>\n\nnamespace zawa {\n\nnamespace internal {\n\ntemplate <class T>\n\
    T MidPoint(T a, T b) {\n    if (a > b) std::swap(a, b);\n    return a + ((b -\
    \ a) >> 1);\n}\n\ntemplate <class T>\nT Abs(T a, T b) {\n    return (a >= b ?\
    \ a - b : b - a);\n}\n\n} // namespace zawa::internal\n\ntemplate <class T, class\
    \ Function>\nT BinarySearch(T ok, T ng, const Function& f) {\n    static_assert(std::is_integral_v<T>,\
    \ \"T must be integral type\");\n    static_assert(std::is_convertible_v<Function,\
    \ std::function<bool(T)>>, \"f must be function bool(T)\");\n    while (internal::Abs(ok,\
    \ ng) > 1) {\n        T mid{ internal::MidPoint(ok, ng) };\n        (f(mid) ?\
    \ ok : ng) = mid;\n    }\n    return ok;\n}\n\ntemplate <class T, class Function>\n\
    T BinarySearch(T ok, T ng, const Function& f, u32 upperLimit) {\n    static_assert(std::is_signed_v<T>,\
    \ \"T must be signed arithmetic type\");\n    static_assert(std::is_convertible_v<Function,\
    \ std::function<bool(T)>>, \"f must be function bool(T)\");\n    for (u32 _{}\
    \ ; _ < upperLimit ; _++) {\n        T mid{ (ok + ng) / (T)2 };\n        (f(mid)\
    \ ? ok : ng) = mid;\n    }\n    return ok;\n}\n\n} // namespace zawa\n#line 2\
    \ \"Src/GeometryR2/Point.hpp\"\n\n#line 2 \"Src/GeometryR2/Real.hpp\"\n\n#line\
    \ 4 \"Src/GeometryR2/Real.hpp\"\n\n#line 6 \"Src/GeometryR2/Real.hpp\"\n#include\
    \ <cassert>\n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nusing Real = long\
    \ double;\n\nnamespace internal {\n\nReal EPS{1e-12};\nconstexpr i32 negative{-1};\n\
    constexpr i32 zero{};\nconstexpr i32 positive{1};\n\n} // namespace internal\n\
    \nReal& Eps() {\n    return internal::EPS;\n}\n\ni32 Sign(Real value) {\n    if\
    \ (value < -Eps()) return internal::negative;\n    if (value > Eps()) return internal::positive;\n\
    \    return internal::zero;\n}\n\nbool Zero(Real value) {\n    return Sign(value)\
    \ == internal::zero;\n}\n\nbool Positive(Real value) {\n    return Sign(value)\
    \ == internal::positive;\n}\n\nbool Negative(Real value) {\n    return Sign(value)\
    \ == internal::negative;\n}\n\nbool Equal(Real a, Real b) {\n    return Zero(a\
    \ - b);\n}\n\nbool Smaller(Real a, Real b) {\n    return Negative(a - b);\n}\n\
    \nbool Bigger(Real a, Real b) {\n    return Positive(a - b);\n}\n\nReal Square(Real\
    \ value) {\n    return (Zero(value) ? value : value * value);\n}\n\nReal Sqrt(Real\
    \ value) {\n    assert(!Negative(value));\n    return (Zero(value) ? value : sqrtl(value));\n\
    }\n\nReal Abs(Real value) {\n    return (Negative(value) ? -value : value);\n\
    }\n\n} // namespace geometryR2\n \n} // namespace zawa\n#line 2 \"Src/GeometryR2/Angle.hpp\"\
    \n\n#line 4 \"Src/GeometryR2/Angle.hpp\"\n\n#line 6 \"Src/GeometryR2/Angle.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nconstexpr Real PI{acosl(-1)};\n\
    constexpr Real TAU{static_cast<Real>(2) * PI};\n\nconstexpr Real ArcToRadian(Real\
    \ arc) {\n    return (arc * PI) / static_cast<Real>(180);\n}\n\nconstexpr Real\
    \ RadianToArc(Real radian) {\n    return (radian * static_cast<Real>(180)) / PI;\n\
    }\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 5 \"Src/GeometryR2/Point.hpp\"\
    \n\n#line 9 \"Src/GeometryR2/Point.hpp\"\n\nnamespace zawa {\n\nnamespace geometryR2\
    \ {\n\nclass Point {\nprivate:\n    Real x_{}, y_{};\npublic:\n    /* constructor\
    \ */\n    Point() = default;\n    Point(Real x, Real y) : x_{x}, y_{y} {}\n\n\
    \    /* getter, setter */\n    Real x() const {\n        return x_;\n    }\n \
    \   Real& x() {\n        return x_;\n    }\n    Real y() const {\n        return\
    \ y_;\n    }\n    Real& y() {\n        return y_;\n    }\n\n    /* operator */\n\
    \    Point& operator+=(const Point& rhs) {\n        x_ += rhs.x();\n        y_\
    \ += rhs.y();\n        return *this;\n    }\n    friend Point operator+(const\
    \ Point& lhs, const Point& rhs) {\n        return Point{lhs} += rhs;\n    }\n\
    \    Point operator+() const {\n        return *this;\n    }\n    Point& operator-=(const\
    \ Point& rhs) {\n        x_ -= rhs.x();\n        y_ -= rhs.y();\n        return\
    \ *this;\n    }\n    friend Point operator-(const Point& lhs, const Point& rhs)\
    \ {\n        return Point{lhs} -= rhs;\n    }\n    Point operator-() const {\n\
    \        return Point{} - *this;\n    }\n    Point& operator*=(Real k) {\n   \
    \     x_ *= k;\n        y_ *= k;\n        return *this;\n    }\n    friend Point\
    \ operator*(Real k, const Point& p) {\n        return Point{p} *= k;\n    }\n\
    \    friend Point operator*(const Point& p, Real k) {\n        return Point{p}\
    \ *= k;\n    }\n    Point& operator/=(Real k) {\n        assert(!Zero(k));\n \
    \       x_ /= k;\n        y_ /= k;\n        return *this;\n    }\n    friend Point\
    \ operator/(Real k, const Point& p) {\n        return Point{p} /= k;\n    }\n\
    \    friend Point operator/(const Point& p, Real k) {\n        return Point{p}\
    \ /= k;\n    }\n    friend bool operator==(const Point& lhs, const Point& rhs)\
    \ {\n        return Equal(lhs.x(), rhs.x()) and Equal(lhs.y(), rhs.y());\n   \
    \ }\n    friend bool operator!=(const Point& lhs, const Point& rhs) {\n      \
    \  return !Equal(lhs.x(), rhs.x()) or !Equal(lhs.y(), rhs.y());\n    }\n    friend\
    \ bool operator<(const Point& lhs, const Point& rhs) {\n        return Smaller(lhs.x(),\
    \ rhs.x()) or \n            (Equal(lhs.x(), rhs.x()) and Smaller(lhs.y(), rhs.y()));\n\
    \    }\n    friend bool operator<=(const Point& lhs, const Point& rhs) {\n   \
    \     return Smaller(lhs.x(), rhs.x()) or \n            (Equal(lhs.x(), rhs.x())\
    \ and (Smaller(lhs.y(), rhs.y()) or Equal(lhs.y(), rhs.y())));\n    }\n    friend\
    \ bool operator>(const Point& lhs, const Point& rhs) {\n        return Bigger(lhs.x(),\
    \ rhs.x()) or\n            (Equal(lhs.x(), rhs.x()) and Bigger(lhs.y(), rhs.y()));\n\
    \    }\n    friend bool operator>=(const Point& lhs, const Point& rhs) {\n   \
    \     return Bigger(lhs.x(), rhs.x()) or\n            (Equal(lhs.x(), rhs.x())\
    \ and (Bigger(lhs.y(), rhs.y()) or Equal(lhs.y(), rhs.y())));\n    }\n    friend\
    \ std::istream& operator>>(std::istream& is, Point& p) {\n        is >> p.x_ >>\
    \ p.y_;\n        return is;\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Point& p) {\n        os << '(' << p.x_ << ',' << p.y_ << ')';\n  \
    \      return os;\n    }\n    \n    /* member function */\n    Real normSquare()\
    \ const {\n        return Square(x_) + Square(y_);\n    }\n    Real norm() const\
    \ {\n        return Sqrt(normSquare());\n    }\n    void normalize() {\n     \
    \   assert((*this) != Point{});\n        (*this) /= norm(); \n    }\n    Point\
    \ normalized() const {\n        Point res{*this};\n        res.normalize();\n\
    \        return res;\n    }\n    Point rotated(Real radian) const {\n        return\
    \ Point{\n            x_ * cosl(radian) - y_ * sinl(radian),\n            x_ *\
    \ sinl(radian) + y_ * cosl(radian)\n        };\n    }\n    void rotate(Real radian)\
    \ {\n        *this = rotated(radian); \n    }\n    Point rotatedByArc(Real arc)\
    \ const {\n        return rotated(ArcToRadian(arc));\n    }\n    void rotateByArc(Real\
    \ arc) {\n        *this = rotatedByArc(arc);\n    }\n    Real argument() const\
    \ {\n        return (Negative(y_) ? TAU : static_cast<Real>(0)) + atan2l(y_, x_);\n\
    \    }\n    Real argumentByArc() const {\n        return RadianToArc(argument());\n\
    \    }\n\n    /* friend function */\n    friend Real Dot(const Point& lhs, const\
    \ Point& rhs) {\n        return lhs.x() * rhs.x() + lhs.y() * rhs.y();\n    }\n\
    \    friend Real Cross(const Point& lhs, const Point& rhs) {\n        return lhs.x()\
    \ * rhs.y() - lhs.y() * rhs.x();\n    }\n    friend Real Argument(const Point&\
    \ lhs, const Point& rhs) {\n        return rhs.argument() - lhs.argument();\n\
    \    }\n    friend bool ArgComp(const Point& lhs, const Point& rhs) {\n      \
    \  return Smaller(lhs.argument(), rhs.argument());\n    }\n};\n\nusing Vector\
    \ = Point;\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 2 \"Src/GeometryR2/Circle.hpp\"\
    \n\n#line 2 \"Src/GeometryR2/Distance/PointAndPoint.hpp\"\n\n#line 4 \"Src/GeometryR2/Distance/PointAndPoint.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nReal Distance(const Point& p0,\
    \ const Point& p1) {\n    return Point{p1 - p0}.norm();\n}\n\nReal DistanceSquare(const\
    \ Point& p0, const Point& p1) {\n    return Point{p1 - p0}.normSquare();\n}\n\n\
    } // namespace geometryR2\n\n} // namespace zawa\n#line 7 \"Src/GeometryR2/Circle.hpp\"\
    \n\n#line 10 \"Src/GeometryR2/Circle.hpp\"\n\nnamespace zawa {\n\nnamespace geometryR2\
    \ {\n\nclass Circle {\nprivate:\n    Point center_{};\n    Real radius_{};\npublic:\n\
    \    /* constructor */\n    Circle() = default;\n    Circle(const Point& center,\
    \ Real radius) : center_{center}, radius_{radius} {\n        assert(!Negative(radius));\n\
    \    }\n    Circle(Real x, Real y, Real r) : center_{x, y}, radius_{r} {\n   \
    \     assert(!Negative(r));\n    }\n\n    /* getter setter */\n    const Point&\
    \ center() const {\n        return center_;\n    }\n    Point& center() {\n  \
    \      return center_;\n    }\n    Real radius() const {\n        return radius_;\n\
    \    }\n    Real& radius() {\n        return radius_;\n    }\n\n    /* operator\
    \ */\n    friend bool operator==(const Circle& lhs, const Circle& rhs) {\n   \
    \     return lhs.center() == rhs.center() and Equal(lhs.radius(), rhs.radius());\n\
    \    }\n    friend bool operator!=(const Circle& lhs, const Circle& rhs) {\n \
    \       return lhs.center() != rhs.center() or !Equal(lhs.radius(), rhs.radius());\n\
    \    }\n\n    /* friend function */\n    friend u32 NumberCommonTangent(const\
    \ Circle& c0, const Circle& c1) {\n        Real dist{DistanceSquare(c0.center(),\
    \ c1.center())};\n        Real down{Square(Abs(c0.radius() - c1.radius()))};\n\
    \        if (Smaller(dist, down)) return 0;\n        if (Equal(dist, down)) return\
    \ 1;\n        Real up{Square(c0.radius() + c1.radius())};\n        if (Smaller(dist,\
    \ up)) return 2;\n        if (Equal(dist, up)) return 3;\n        return 4;\n\
    \    }\n};\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 2 \"Src/GeometryR2/Intersect/CircleAndCircle.hpp\"\
    \n\n#line 5 \"Src/GeometryR2/Intersect/CircleAndCircle.hpp\"\n\nnamespace zawa\
    \ {\n\nnamespace geometryR2 {\n\nbool Intersect(const Circle& c0, const Circle&\
    \ c1) {\n    u32 number{NumberCommonTangent(c0, c1)};\n    return 0u < number\
    \ and number < 4u;\n}\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line\
    \ 2 \"Src/GeometryR2/CrossPoint/CircleAndCircle.hpp\"\n\n#line 5 \"Src/GeometryR2/CrossPoint/CircleAndCircle.hpp\"\
    \n\n#line 7 \"Src/GeometryR2/CrossPoint/CircleAndCircle.hpp\"\n\nnamespace zawa\
    \ {\n\nnamespace geometryR2 {\n\nstd::pair<Point, Point> CrossPoint(const Circle&\
    \ lhs, const Circle& rhs) {\n    assert(lhs.center() != rhs.center());\n    assert(Intersect(lhs,\
    \ rhs));\n    assert(!Zero(lhs.radius()) or !Zero(rhs.radius()));\n    if (Zero(lhs.radius()))\
    \ return {lhs.center(), lhs.center()};\n    if (Zero(rhs.radius())) return {rhs.center(),\
    \ rhs.center()};\n    Real d{Distance(lhs.center(), rhs.center())};\n    Real\
    \ cosine{(Square(lhs.radius()) + Square(d) - Square(rhs.radius()))\n        /\
    \ (static_cast<Real>(2)*lhs.radius()*d)};\n    Real rc{lhs.radius()*cosine};\n\
    \    Real rs{Sqrt(Square(lhs.radius()) - Square(rc))};\n    Vector lr{Vector{rhs.center()\
    \ - lhs.center()}.normalized()};\n    Vector h{lhs.center() + lr*rc};\n    std::pair<Point,\
    \ Point> res;\n    res.first = h + lr.rotatedByArc(90) * rs;\n    res.second =\
    \ h + lr.rotatedByArc(-90) * rs;\n    return res;\n}\n\n} // namespace geometryR2\n\
    \    \n} // namespace zawa\n#line 2 \"Src/GeometryR2/Contain/CircleContainsPoint.hpp\"\
    \n\n#line 2 \"Src/GeometryR2/Contain/State.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ geometryR2 {\n\nenum ContainState {\n    INSIDE,\n    ONLINE,\n    OUTSIDE\n\
    };\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 8 \"Src/GeometryR2/Contain/CircleContainsPoint.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nContainState CircleContainsPoint(const\
    \ Circle& circle, const Point& p) {\n    Real dist{Distance(circle.center(), p)};\n\
    \    if (Smaller(dist, circle.radius())) {\n        return INSIDE;\n    }\n  \
    \  else if (Equal(dist, circle.radius())) {\n        return ONLINE;\n    }\n \
    \   else {\n        return OUTSIDE;\n    }\n}\n\n} // namespace geometryR2\n\n\
    } // namespace zawa\n#line 11 \"Test/AtCoder/abc157_f.test.cpp\"\n\nusing namespace\
    \ zawa;\nusing namespace geometryR2;\n\n#include <algorithm>\n#line 17 \"Test/AtCoder/abc157_f.test.cpp\"\
    \n#include <vector>\n\nint main() {\n    SetFastIO();\n    SetPrecision(8);\n\
    \    int n, k; std::cin >> n >> k;\n    std::vector<Point> p(n);\n    std::vector<Real>\
    \ c(n);\n    for (int i{} ; i < n ; i++) {\n        std::cin >> p[i] >> c[i];\n\
    \    }\n\n    if (k == 1) {\n        std::cout << 0 << '\\n';\n        return\
    \ 0;\n    }\n\n    auto f{[&](Real t) -> bool {\n        std::vector<Circle> circles(n);\n\
    \        for (int i{} ; i < n ; i++) {\n            circles[i] = Circle{p[i],\
    \ t / c[i]};\n        }\n        std::vector<Point> cand{p};\n        for (int\
    \ i{} ; i < n ; i++) for (int j{i + 1} ; j < n ; j++) {\n            if (!Intersect(circles[i],\
    \ circles[j])) continue;\n            auto v{CrossPoint(circles[i], circles[j])};\n\
    \            cand.push_back(v.first);\n            cand.push_back(v.second);\n\
    \        }\n        int max{};\n        for (const auto& v : cand) {\n       \
    \     int cnt{};\n            for (const auto& circle : circles) {\n         \
    \       cnt += CircleContainsPoint(circle, v) != OUTSIDE;\n            }\n   \
    \         max = std::max(max, cnt);\n        }\n        return max >= k;\n   \
    \ }};\n\n    Real ans{BinarySearch(Real{4000 * 100}, Real{}, f, 80)};\n    std::cout\
    \ << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc157/tasks/abc157_f\"\n#define\
    \ ERROR 0.000001\n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"\
    ../../Src/Utility/BinarySearch.hpp\"\n#include \"../../Src/GeometryR2/Point.hpp\"\
    \n#include \"../../Src/GeometryR2/Circle.hpp\"\n#include \"../../Src/GeometryR2/Intersect/CircleAndCircle.hpp\"\
    \n#include \"../../Src/GeometryR2/CrossPoint/CircleAndCircle.hpp\"\n#include \"\
    ../../Src/GeometryR2/Contain/CircleContainsPoint.hpp\"\n\nusing namespace zawa;\n\
    using namespace geometryR2;\n\n#include <algorithm>\n#include <iostream>\n#include\
    \ <vector>\n\nint main() {\n    SetFastIO();\n    SetPrecision(8);\n    int n,\
    \ k; std::cin >> n >> k;\n    std::vector<Point> p(n);\n    std::vector<Real>\
    \ c(n);\n    for (int i{} ; i < n ; i++) {\n        std::cin >> p[i] >> c[i];\n\
    \    }\n\n    if (k == 1) {\n        std::cout << 0 << '\\n';\n        return\
    \ 0;\n    }\n\n    auto f{[&](Real t) -> bool {\n        std::vector<Circle> circles(n);\n\
    \        for (int i{} ; i < n ; i++) {\n            circles[i] = Circle{p[i],\
    \ t / c[i]};\n        }\n        std::vector<Point> cand{p};\n        for (int\
    \ i{} ; i < n ; i++) for (int j{i + 1} ; j < n ; j++) {\n            if (!Intersect(circles[i],\
    \ circles[j])) continue;\n            auto v{CrossPoint(circles[i], circles[j])};\n\
    \            cand.push_back(v.first);\n            cand.push_back(v.second);\n\
    \        }\n        int max{};\n        for (const auto& v : cand) {\n       \
    \     int cnt{};\n            for (const auto& circle : circles) {\n         \
    \       cnt += CircleContainsPoint(circle, v) != OUTSIDE;\n            }\n   \
    \         max = std::max(max, cnt);\n        }\n        return max >= k;\n   \
    \ }};\n\n    Real ans{BinarySearch(Real{4000 * 100}, Real{}, f, 80)};\n    std::cout\
    \ << ans << '\\n';\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Utility/BinarySearch.hpp
  - Src/GeometryR2/Point.hpp
  - Src/GeometryR2/Real.hpp
  - Src/GeometryR2/Angle.hpp
  - Src/GeometryR2/Circle.hpp
  - Src/GeometryR2/Distance/PointAndPoint.hpp
  - Src/GeometryR2/Intersect/CircleAndCircle.hpp
  - Src/GeometryR2/CrossPoint/CircleAndCircle.hpp
  - Src/GeometryR2/Contain/CircleContainsPoint.hpp
  - Src/GeometryR2/Contain/State.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc157_f.test.cpp
  requiredBy: []
  timestamp: '2023-11-20 11:32:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc157_f.test.cpp
layout: document
title: ABC157-F Yakiniku Optimization Problem
---

二分探索を考える。 $t$ 秒で $K$ 枚の焼肉を焼くことができる領域には必ず(その $K$ 枚のうちの) $2$ 枚の焼肉が $t$ 秒ぴったりで焼けるような点が存在する。

そのような点は 中心が焼肉の位置、 半径が $\frac{t}{c}$ である円の交点である。

ある円が片方の円を内包する場合に注意 (焼肉の位置ぴったりに熱源を置いた場合も考慮すること)