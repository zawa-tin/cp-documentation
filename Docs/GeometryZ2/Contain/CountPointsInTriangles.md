---
title: Count Points in Triangles
documentation_of: //Src/GeometryZ2/Contain/CountPointsInTriangles.hpp
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
