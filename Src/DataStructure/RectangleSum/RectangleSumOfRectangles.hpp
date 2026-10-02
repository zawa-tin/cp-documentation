#pragma once

#include "../../Template/TypeAlias.hpp"
#include "./RectangleSumConcepts.hpp"

#include <algorithm>
#include <array>
#include <tuple>
#include <vector>
#include <ranges>

namespace zawa {

namespace concepts {

template <class T, class U>
concept RSORQuery = RectangleAdd<T> and Rectangle<U> and std::same_as<typename T::P, typename U::P>;

} // namespace concepts

template <concepts::RectangleAdd T,concepts::Rectangle U>
std::vector<typename T::W> RectangleSumOfRectangles(std::vector<T> rs,std::vector<U> qs) requires concepts::RSORQuery<T,U> {
    using P = typename T::P;
    using W = typename T::W;
    std::vector<P> xs,ys;
    xs.reserve(2*rs.size());
    ys.reserve(2*rs.size());
    for (const T& r : rs) {
        xs.push_back(r.l);
        xs.push_back(r.r);
        ys.push_back(r.d);
        ys.push_back(r.u);
    }
    std::ranges::sort(xs);
    xs.erase(std::unique(xs.begin(),xs.end()),xs.end());
    std::ranges::sort(ys);
    ys.erase(std::unique(ys.begin(),ys.end()),ys.end());
    auto key=[&](std::vector<P>& p,P x) -> i32 {
        return std::ranges::lower_bound(p,x)-p.begin();
    };
    std::vector<std::vector<std::tuple<i32,i32,W>>> add(xs.size()+1);
    std::vector<std::vector<std::tuple<P,P,u32,bool>>> query(xs.size()+1);
    for (const T& r : rs) {
        const i32 kl=key(xs,r.l),kr=key(xs,r.r),kd=key(ys,r.d),ku=key(ys,r.u);
        add[kl].emplace_back(kd,ku,r.w);
        add[kr].emplace_back(kd,ku,-r.w);
    }
    for (u32 i=0 ; i<qs.size() ; i++) {
        const U& r=qs[i];
        const i32 kl=key(xs,r.l),kr=key(xs,r.r);
        query[kl].emplace_back(r.l,r.d,i,false);
        query[kl].emplace_back(r.l,r.u,i,true);
        query[kr].emplace_back(r.r,r.d,i,true);
        query[kr].emplace_back(r.r,r.u,i,false);
    }
    const i32 n=std::ssize(ys);
    std::vector<std::array<W,4>> fen(n+1,{0,0,0,0});
    auto fenadd=[&](i32 i,std::array<W,4> v) {
        for (i++ ; i<std::ssize(fen) ; i+=i&-i)
            for (u32 j=0 ; j<4 ; j++)
                fen[i][j]+=v[j];
    };
    auto fenpref=[&](i32 r) -> std::array<W,4> {
        std::array<W,4> res{0,0,0,0};
        for ( ; r ; r-=r&-r) 
            for (u32 j=0 ; j<4 ; j++)
                res[j]+=fen[r][j];
        return res;
    };
    auto addpoint=[&](P x,P y,W w) {
        const W X=(W)xs[x],Y=(W)ys[y];
        const W wx=w*X,wy=w*Y;
        fenadd(y,{w,wy,wx,wx*Y});
    };
    std::vector<W> ans(qs.size());
    for (i32 x=0 ; x<=std::ssize(xs) ; x++) {
        for (auto [r,u,id,sign] : query[x]) {
            auto pd=fenpref(key(ys,u));
            const W X=(W)r,Y=(W)u;
            const W kiyo=(pd[0]*Y-pd[1])*X-pd[2]*Y+pd[3];
            ans[id]+=(sign?-1:1)*kiyo;
        }
        for (auto [yd,yu,w] : add[x]) {
            addpoint(x,yd,w);
            addpoint(x,yu,-w);
        }
    }
    return ans;
}

} // namespace zawa
