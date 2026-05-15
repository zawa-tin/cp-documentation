#pragma once

#include "./RangeAggregation.hpp"
#include "../../Sequence/CompressedSequence.hpp"

namespace zawa {

template <class T>
class RectangleAggregation {
public:

    RectangleAggregation(std::vector<std::pair<T,T>> p) : m_points{p},m_comp{std::move(p)} {
        std::vector<T> ys(m_comp.size());
        for (usize i = 0 ; i < size() ; i++)
            ys[m_comp.map(i)] = m_points[i].second;
        m_solver = RangeAggregation<T>(std::move(ys));
    }

    inline usize size() const {
        return m_points.size();
    }

    inline usize width() const {
        return m_comp.size();
    }

    inline usize height() const {
        return m_solver.height();
    }

    std::vector<std::pair<usize,usize>> point(usize i) const {
        assert(i < size());
        std::vector<std::pair<usize,usize>> res;
        res.reserve(height());
        return m_solver.point(m_comp.map(i));
    }

    std::pair<T,T> operator[](usize i) const {
        assert(i < size());
        return m_points[i];
    }

    std::vector<std::pair<usize,usize>> point(std::pair<T,T> p) const {
        return m_solver.point(m_comp.at(p));
    }

    std::vector<std::tuple<usize,usize,usize>> rectangle(T l,T d,T r,T u) const {
        assert(l <= r and d <= u);     
        if (l == r)
            return {};
        return m_solver.rectangle(m_comp[{l,d}],d,m_comp[{r-1,u}],u);
    }

    u32 count(T l,T d,T r,T u) const {
        assert(l <= r and d <= u);     
        if (l == r or d == u)
            return 0;
        return m_solver.count(m_comp[{l,d}],d,m_comp[{r-1,u}],u);
    }

private:

    std::vector<std::pair<T,T>> m_points;

    CompressedSequence<std::pair<T,T>> m_comp;

    RangeAggregation<T> m_solver;
};

} // namespace zawa
