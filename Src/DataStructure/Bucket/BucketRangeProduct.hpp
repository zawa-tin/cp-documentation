#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Group/GroupConcept.hpp"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <limits>
#include <vector>

namespace zawa {

template <concepts::Monoid M>
class BucketRangeQuery {
public:

    using V = typename M::Element;

    inline usize size() const {
        return m_n;
    }

    inline usize bucketSize() const {
        return m_b;
    }

    BucketRangeQuery() = default;

    BucketRangeQuery(usize N,usize B = std::numeric_limits<usize>::max()) 
        : m_n{N},m_b{BucketSize(N,B)}, m_data(N,M::identity()), m_bucket((m_n+m_b-1)/m_b,M::identity()) {
        for (usize i = 0 ; i < size() ; i++)
            m_bucket[i/bucketSize()] = M::operation(m_bucket[i/bucketSize()],m_data[i]);
    }

    BucketRangeQuery(std::vector<V> A,usize B = std::numeric_limits<usize>::max())
        : m_n{A.size()},m_b{BucketSize(A.size(),B)},m_data(std::move(A)),m_bucket((m_n+m_b-1)/m_b,M::identity()) {
        for (usize i = 0 ; i < size() ; i++)
            m_bucket[i/bucketSize()] = M::operation(m_bucket[i/bucketSize()],m_data[i]);
    }

    V product(usize l,usize r) const {
        assert(l <= r and r <= size());
        V res = M::identity();
        while (l < r and l % bucketSize())
            res = M::operation(res,m_data[l++]);
        while (l + bucketSize() <= r) {
            res = M::operation(res,m_bucket[l/bucketSize()]);
            l += bucketSize();
        }
        while (l < r)
            res = M::operation(res,m_data[l++]);
        return res;
    }

    V operator[](usize i) const {
        assert(i < size());
        return m_data[i];
    }

    V bucketValue(usize i) const {
        assert(i < m_bucket.size());
        return m_bucket[i];
    }

    void assign(usize i,V x) {
        assert(i < size());
        const usize idx = i/bucketSize();
        if constexpr (concepts::Group<M>) {
            m_bucket[idx] = M::operation(m_bucket[idx],M::inverse(m_data[i]));
            m_data[i] = std::move(x);
            m_bucket[idx] = M::operation(m_bucket[idx],m_data[i]);
        }
        else {
            m_data[i] = std::move(x);
            m_bucket[idx] = M::identity();
            const usize l = idx*bucketSize(),r = std::min(size(),(idx+1)*bucketSize());
            for (usize j = l ; j < r ; j++)
                m_bucket[idx] = M::operation(m_bucket[idx],m_data[j]);
        }
    }

    void operation(usize i,V x) {
        assert(i < size());
        m_bucket[i/bucketSize()] = M::operation(m_bucket[i/bucketSize()],x);
        m_data[i] = M::operation(m_data[i],x);
    }

    template <class F>
    requires std::predicate<F,V>
    usize maxRight(usize i,F f) const {
        assert(i <= size());
        assert(f(M::identity()));
        V pd = M::identity();
        while (i < size() and i % bucketSize()) {
            V nxt = M::operation(pd,m_data[i]);
            if (!f(nxt))
                return i;
            pd = std::move(nxt);
            i++;
        }
        while (i + bucketSize() <= size()) {
            V nxt = M::operation(pd,m_bucket[i/bucketSize()]);
            if (!f(nxt))
                break;
            pd = std::move(nxt);
            i += bucketSize();
        }
        while (i < size()) {
            V nxt = M::operation(pd,m_data[i]);
            if (!f(nxt))
                break;
            pd = std::move(nxt);
            i++;
        }
        return i;
    }

    template <class F>
    requires std::predicate<F,V>
    usize minLeft(usize i,F f) const {
        assert(i <= size());
        assert(f(M::identity()));
        V pd = M::identity();
        while (i % bucketSize()) {
            V nxt = M::operation(m_data[i-1],pd);
            if (!f(nxt))
                return i;
            pd = std::move(nxt);
            i--;
        }
        while (i) {
            V nxt = M::operation(m_bucket[i/bucketSize()-1],pd);
            if (!f(nxt))
                break;
            pd = std::move(nxt);
            i -= bucketSize();
        }
        while (i) {
            V nxt = M::operation(m_data[i-1],pd);
            if (!f(nxt))
                break;
            pd = std::move(nxt);
            i--;
        }
        return i;
    }

private:

    usize m_n,m_b;

    std::vector<V> m_data,m_bucket;

    static usize BucketSize(usize N,usize B) {
        return B == std::numeric_limits<usize>::max() ? std::max<usize>(1,sqrtl(N)) : B;
    }
};


} // namespace zawa
