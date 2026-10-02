---
title: Rectangle Sum of Rectangles
documentation_of: //Src/DataStructure/RectangleSum/RectangleSumOfRectangles.hpp
---

## 概要

↓↓雛形↓↓

```cpp
struct RectAdd {
    using P=int;
    using W=long long;
    P l,d,r,u;
    W w;
};
struct Rect {
    using P=int;
    P l,d,r,u;
};
```

↓↓関数呼び出しは↓↓

```cpp
template <concepts::RectangleAdd T,concepts::Rectangle U>
std::vector<typename T::W> RectangleSumOfRectangles(std::vector<T> rs,std::vector<U> qs);
```

log1個でやっているが、定数倍がそこそこデカい。
