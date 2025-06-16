#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Monoid/MonoidConcept.hpp"
#include "../../Sequence/CompressedSequence.hpp"
#include "./SegmentTree.hpp"

#include <cassert>
#include <vector>

namespace zawa {

namespace internal {

template <class T, concepts::Monoid M>
class SegmentTree2D {
public:

    using V = M::Element;

    SegmentTree2D(const std::vector<T>& xs, const std::vector<T>& ys)
        : m_compx{xs}, m_compy(2 * m_compx.size()), m_seg(2 * m_compx.size()) {
        std::vector<std::vector<T>> app(2 * m_compx.size());
        for (usize i = 0 ; i < xs.size() ; i++) {
            T y = ys[i];
            for (usize j = m_compx.map(i) + m_compx.size() ; j ; j >>= 1) {
                app[j].push_back(y);
            }
        }
        for (usize i = 1 ; i < app.size() ; i++) {
           m_compy[i] = CompressedSequence<T>(app[i]);
           m_seg[i] = SegmentTree<M>(m_compy[i].size());
        }
    }

    void set(const T& x, const T& y, const V& v) {
        auto i = m_compx.at(x);
        for (i += m_compx.size() ; i ; i >>= 1) {
            m_seg[i].set(m_compy[i].at(y), v);
        }
    }

    void operation(const T& x, const T& y, const V& v) {
        auto i = m_compx.at(x);
        for (i += m_compx.size() ; i ; i >>= 1) {
            m_seg[i].operation(m_compy[i].at(y), v);
        }
    }

    [[nodiscard]] V product(const T& l, const T& d, const T& r, const T& u) const {
        assert(l <= r and d <= u);
        V L = M::identity(), R = M::identity();
        for (usize lidx = m_compx[l] + m_compx.size(), ridx = m_compx[r] + m_compx.size() ; lidx < ridx ; lidx >>= 1, ridx >>= 1) {
            if (lidx & 1) {
                L = M::operation(L, m_seg[lidx].product(m_compy[lidx][d], m_compy[lidx][u]));
                lidx++;
            }
            if (ridx & 1) {
                ridx--;
                R = M::operation(m_seg[ridx].product(m_compy[ridx][d], m_compy[ridx][u]), R);
            }
        }
        return M::operation(L, R);
    }

private:

    CompressedSequence<T> m_compx;

    std::vector<CompressedSequence<T>> m_compy;

    std::vector<SegmentTree<M>> m_seg;
};

} // namespace internal

template <class T, concepts::Monoid M>
class OfflineSegmentTree2D {
public:

    OfflineSegmentTree2D(usize q = 0) {
        m_xs.reserve(q);
        m_ys.reserve(q);
    }

    void operation(const T& x, const T& y) {
        m_xs.push_back(x);
        m_ys.push_back(y);
    }

    void operation(T&& x, T&& y) {
        m_xs.push_back(std::move(x));
        m_ys.push_back(std::move(y));
    }

    [[nodiscard]] internal::SegmentTree2D<T, M> build() const {
        return internal::SegmentTree2D<T, M>{m_xs, m_ys};
    }

private:

    std::vector<T> m_xs{}, m_ys{};
};

} // namespace zawa
