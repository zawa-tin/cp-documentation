---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/RectangleSum/RectangleSumConcepts.hpp
    title: Src/DataStructure/RectangleSum/RectangleSumConcepts.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc477_f.test.cpp
    title: Test/AtCoder/abc477_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/static_rectangle_add_rectangle_sum.test.cpp
    title: Test/LC/static_rectangle_add_rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/RectangleSum/RectangleSumOfRectangles.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/RectangleSum/RectangleSumConcepts.hpp\"\
    \n\n#include <concepts>\n#include <type_traits>\n\nnamespace zawa {\n\nnamespace\
    \ concepts {\n\ntemplate <class T>\nconcept Point = requires (T p) {\n    typename\
    \ T::P;\n    typename T::W;\n    { p.x } -> std::same_as<typename T::P&>;\n  \
    \  { p.y } -> std::same_as<typename T::P&>;\n    { p.w } -> std::same_as<typename\
    \ T::W&>;\n};\n\ntemplate <class T>\nconcept RectangleAdd = requires (T r) {\n\
    \    typename T::P;\n    typename T::W;\n    { r.l } -> std::same_as<typename\
    \ T::P&>;\n    { r.d } -> std::same_as<typename T::P&>;\n    { r.r } -> std::same_as<typename\
    \ T::P&>;\n    { r.u } -> std::same_as<typename T::P&>;\n    { r.w } -> std::same_as<typename\
    \ T::W&>;\n};\n\ntemplate <class T>\nconcept Rectangle = requires (T r) {\n  \
    \  typename T::P;\n    { r.l } -> std::same_as<typename T::P&>;\n    { r.d } ->\
    \ std::same_as<typename T::P&>;\n    { r.r } -> std::same_as<typename T::P&>;\n\
    \    { r.u } -> std::same_as<typename T::P&>;\n};\n\n} // namespace concepts\n\
    \n\n} // namespace zawa\n#line 5 \"Src/DataStructure/RectangleSum/RectangleSumOfRectangles.hpp\"\
    \n\n#include <algorithm>\n#include <array>\n#include <tuple>\n#include <vector>\n\
    #include <ranges>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class\
    \ T, class U>\nconcept RSORQuery = RectangleAdd<T> and Rectangle<U> and std::same_as<typename\
    \ T::P, typename U::P>;\n\n} // namespace concepts\n\ntemplate <concepts::RectangleAdd\
    \ T,concepts::Rectangle U>\nstd::vector<typename T::W> RectangleSumOfRectangles(std::vector<T>\
    \ rs,std::vector<U> qs) requires concepts::RSORQuery<T,U> {\n    using P = typename\
    \ T::P;\n    using W = typename T::W;\n    std::vector<P> xs,ys;\n    xs.reserve(2*rs.size());\n\
    \    ys.reserve(2*rs.size());\n    for (const T& r : rs) {\n        xs.push_back(r.l);\n\
    \        xs.push_back(r.r);\n        ys.push_back(r.d);\n        ys.push_back(r.u);\n\
    \    }\n    std::ranges::sort(xs);\n    xs.erase(std::unique(xs.begin(),xs.end()),xs.end());\n\
    \    std::ranges::sort(ys);\n    ys.erase(std::unique(ys.begin(),ys.end()),ys.end());\n\
    \    auto key=[&](std::vector<P>& p,P x) -> i32 {\n        return std::ranges::lower_bound(p,x)-p.begin();\n\
    \    };\n    std::vector<std::vector<std::tuple<i32,i32,W>>> add(xs.size()+1);\n\
    \    std::vector<std::vector<std::tuple<P,P,u32,bool>>> query(xs.size()+1);\n\
    \    for (const T& r : rs) {\n        const i32 kl=key(xs,r.l),kr=key(xs,r.r),kd=key(ys,r.d),ku=key(ys,r.u);\n\
    \        add[kl].emplace_back(kd,ku,r.w);\n        add[kr].emplace_back(kd,ku,-r.w);\n\
    \    }\n    for (u32 i=0 ; i<qs.size() ; i++) {\n        const U& r=qs[i];\n \
    \       const i32 kl=key(xs,r.l),kr=key(xs,r.r);\n        query[kl].emplace_back(r.l,r.d,i,false);\n\
    \        query[kl].emplace_back(r.l,r.u,i,true);\n        query[kr].emplace_back(r.r,r.d,i,true);\n\
    \        query[kr].emplace_back(r.r,r.u,i,false);\n    }\n    const i32 n=std::ssize(ys);\n\
    \    std::vector<std::array<W,4>> fen(n+1,{0,0,0,0});\n    auto fenadd=[&](i32\
    \ i,std::array<W,4> v) {\n        for (i++ ; i<std::ssize(fen) ; i+=i&-i)\n  \
    \          for (u32 j=0 ; j<4 ; j++)\n                fen[i][j]+=v[j];\n    };\n\
    \    auto fenpref=[&](i32 r) -> std::array<W,4> {\n        std::array<W,4> res{0,0,0,0};\n\
    \        for ( ; r ; r-=r&-r) \n            for (u32 j=0 ; j<4 ; j++)\n      \
    \          res[j]+=fen[r][j];\n        return res;\n    };\n    auto addpoint=[&](P\
    \ x,P y,W w) {\n        const W X=(W)xs[x],Y=(W)ys[y];\n        const W wx=w*X,wy=w*Y;\n\
    \        fenadd(y,{w,wy,wx,wx*Y});\n    };\n    std::vector<W> ans(qs.size());\n\
    \    for (i32 x=0 ; x<=std::ssize(xs) ; x++) {\n        for (auto [r,u,id,sign]\
    \ : query[x]) {\n            auto pd=fenpref(key(ys,u));\n            const W\
    \ X=(W)r,Y=(W)u;\n            const W kiyo=(pd[0]*Y-pd[1])*X-pd[2]*Y+pd[3];\n\
    \            ans[id]+=(sign?-1:1)*kiyo;\n        }\n        for (auto [yd,yu,w]\
    \ : add[x]) {\n            addpoint(x,yd,w);\n            addpoint(x,yu,-w);\n\
    \        }\n    }\n    return ans;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"./RectangleSumConcepts.hpp\"\
    \n\n#include <algorithm>\n#include <array>\n#include <tuple>\n#include <vector>\n\
    #include <ranges>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class\
    \ T, class U>\nconcept RSORQuery = RectangleAdd<T> and Rectangle<U> and std::same_as<typename\
    \ T::P, typename U::P>;\n\n} // namespace concepts\n\ntemplate <concepts::RectangleAdd\
    \ T,concepts::Rectangle U>\nstd::vector<typename T::W> RectangleSumOfRectangles(std::vector<T>\
    \ rs,std::vector<U> qs) requires concepts::RSORQuery<T,U> {\n    using P = typename\
    \ T::P;\n    using W = typename T::W;\n    std::vector<P> xs,ys;\n    xs.reserve(2*rs.size());\n\
    \    ys.reserve(2*rs.size());\n    for (const T& r : rs) {\n        xs.push_back(r.l);\n\
    \        xs.push_back(r.r);\n        ys.push_back(r.d);\n        ys.push_back(r.u);\n\
    \    }\n    std::ranges::sort(xs);\n    xs.erase(std::unique(xs.begin(),xs.end()),xs.end());\n\
    \    std::ranges::sort(ys);\n    ys.erase(std::unique(ys.begin(),ys.end()),ys.end());\n\
    \    auto key=[&](std::vector<P>& p,P x) -> i32 {\n        return std::ranges::lower_bound(p,x)-p.begin();\n\
    \    };\n    std::vector<std::vector<std::tuple<i32,i32,W>>> add(xs.size()+1);\n\
    \    std::vector<std::vector<std::tuple<P,P,u32,bool>>> query(xs.size()+1);\n\
    \    for (const T& r : rs) {\n        const i32 kl=key(xs,r.l),kr=key(xs,r.r),kd=key(ys,r.d),ku=key(ys,r.u);\n\
    \        add[kl].emplace_back(kd,ku,r.w);\n        add[kr].emplace_back(kd,ku,-r.w);\n\
    \    }\n    for (u32 i=0 ; i<qs.size() ; i++) {\n        const U& r=qs[i];\n \
    \       const i32 kl=key(xs,r.l),kr=key(xs,r.r);\n        query[kl].emplace_back(r.l,r.d,i,false);\n\
    \        query[kl].emplace_back(r.l,r.u,i,true);\n        query[kr].emplace_back(r.r,r.d,i,true);\n\
    \        query[kr].emplace_back(r.r,r.u,i,false);\n    }\n    const i32 n=std::ssize(ys);\n\
    \    std::vector<std::array<W,4>> fen(n+1,{0,0,0,0});\n    auto fenadd=[&](i32\
    \ i,std::array<W,4> v) {\n        for (i++ ; i<std::ssize(fen) ; i+=i&-i)\n  \
    \          for (u32 j=0 ; j<4 ; j++)\n                fen[i][j]+=v[j];\n    };\n\
    \    auto fenpref=[&](i32 r) -> std::array<W,4> {\n        std::array<W,4> res{0,0,0,0};\n\
    \        for ( ; r ; r-=r&-r) \n            for (u32 j=0 ; j<4 ; j++)\n      \
    \          res[j]+=fen[r][j];\n        return res;\n    };\n    auto addpoint=[&](P\
    \ x,P y,W w) {\n        const W X=(W)xs[x],Y=(W)ys[y];\n        const W wx=w*X,wy=w*Y;\n\
    \        fenadd(y,{w,wy,wx,wx*Y});\n    };\n    std::vector<W> ans(qs.size());\n\
    \    for (i32 x=0 ; x<=std::ssize(xs) ; x++) {\n        for (auto [r,u,id,sign]\
    \ : query[x]) {\n            auto pd=fenpref(key(ys,u));\n            const W\
    \ X=(W)r,Y=(W)u;\n            const W kiyo=(pd[0]*Y-pd[1])*X-pd[2]*Y+pd[3];\n\
    \            ans[id]+=(sign?-1:1)*kiyo;\n        }\n        for (auto [yd,yu,w]\
    \ : add[x]) {\n            addpoint(x,yd,w);\n            addpoint(x,yu,-w);\n\
    \        }\n    }\n    return ans;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/RectangleSum/RectangleSumConcepts.hpp
  isVerificationFile: false
  path: Src/DataStructure/RectangleSum/RectangleSumOfRectangles.hpp
  requiredBy: []
  timestamp: '2026-10-02 17:24:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc477_f.test.cpp
  - Test/LC/static_rectangle_add_rectangle_sum.test.cpp
documentation_of: Src/DataStructure/RectangleSum/RectangleSumOfRectangles.hpp
layout: document
title: Rectangle Sum of Rectangles
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
