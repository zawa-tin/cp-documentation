#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Monoid/MonoidConcept.hpp"

#include <vector>
#include <cassert>
#include <functional>
#include <type_traits>
#include <ostream>

namespace zawa {

template <concepts::Monoid Monoid>
class SegmentTree {
public:

    using VM = Monoid;

    using V = typename VM::Element;

    using OM = Monoid;

    using O = typename OM::Element;

    SegmentTree() = default;

    explicit SegmentTree(usize n) : m_n{ n }, m_dat(n << 1, VM::identity()) {}

    explicit SegmentTree(const std::vector<V>& dat) : m_n{ dat.size() }, m_dat(dat.size() << 1, VM::identity()) {
        for (usize i{} ; i < m_n ; i++) {
            m_dat[i + m_n] = dat[i];
        }
        for (usize i{m_n} ; i-- ; i) {
            m_dat[i] = VM::operation(m_dat[left(i)], m_dat[right(i)]);
        }
    }

    [[nodiscard]] inline usize size() const noexcept {
        return m_n;
    }

    [[nodiscard]] V get(usize i) const {
        assert(i < size());
        return m_dat[i + m_n];
    }

    [[nodiscard]] V operator[](usize i) const {
        assert(i < size());
        return m_dat[i + m_n];
    }

    void operation(usize i, const O& value) {
        assert(i < size());
        i += size();
        m_dat[i] = OM::operation(m_dat[i], value);
        while (i = parent(i), i) {
            m_dat[i] = VM::operation(m_dat[left(i)], m_dat[right(i)]);
        }
    }

    void assign(usize i, const V& value) {
        assert(i < size());
        i += size();
        m_dat[i] = value;
        while (i = parent(i), i) {
            m_dat[i] = VM::operation(m_dat[left(i)], m_dat[right(i)]);
        }
    }

    [[nodiscard]] V product(u32 l, u32 r) const {
        assert(l <= r and r <= size());
        V L{ VM::identity() }, R{ VM::identity() };
        for (l += size(), r += size() ; l < r ; l = parent(l), r = parent(r)) {
            if (l & 1) {
                L = VM::operation(L, m_dat[l++]);
            }
            if (r & 1) {
                R = VM::operation(m_dat[--r], R);
            }
        }
        return VM::operation(L, R);
    }

    template <class Function>
    [[nodiscard]] usize maxRight(usize l, const Function& f) {
        assert(l < size());
        static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>, "maxRight's argument f must be function bool(T)");
        assert(f(VM::identity()));
        usize res{l}, width{1};
        V prod{ VM::identity() };
        // 現在の見ている頂点の幅をwidthで持つ
        // 境界がある頂点を含む部分木の根を探す
        // (折り返す時は必要以上の幅を持つ根になるが、widthを持っているのでオーバーしない)
        for (l += size() ; res + width <= size() ; l = parent(l), width <<= 1) if (l & 1) {
            if (not f(VM::operation(prod, m_dat[l]))) break; 
            res += width;
            prod = VM::operation(prod, m_dat[l++]);
        }
        // 根から下って、境界を発見する
        while (l = left(l), width >>= 1) {
            if (res + width <= size() and f(VM::operation(prod, m_dat[l]))) {
                res += width;
                prod = VM::operation(prod, m_dat[l++]);
            } 
        }
        return res;
    }

    template <class Function>
    [[nodiscard]] usize minLeft(usize r, const Function& f) const {
        assert(r <= size());
        static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>, "minLeft's argument f must be function bool(T)");
        assert(f(VM::identity()));
        usize res{r}, width{1};
        V prod{ VM::identity() };
        for (r += size() ; res >= width ; r = parent(r), width <<= 1) if (r & 1) {
            if (not f(VM::operation(m_dat[r - 1], prod))) break;
            res -= width;
            prod = VM::operation(prod, m_dat[--r]);
        }
        while (r = left(r), width >>= 1) {
            if (res >= width and f(VM::operation(m_dat[r - 1], prod))) {
                res -= width;
                prod = VM::operation(m_dat[--r], prod);
            }
        }
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const SegmentTree& st) {
        for (usize i{1} ; i < 2 * st.size() ; i++) {
            os << st.m_dat[i] << (i + 1 == 2 * st.size() ? "" : " ");
        }
        return os;
    }

private:

    constexpr u32 left(u32 v) const {
        return v << 1;
    }

    constexpr u32 right(u32 v) const {
        return v << 1 | 1;
    }

    constexpr u32 parent(u32 v) const {
        return v >> 1;
    }

    usize m_n;

    std::vector<V> m_dat;
};

} // namespace zawa
