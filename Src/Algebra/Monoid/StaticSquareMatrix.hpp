#pragma once

#include "../../Template/TypeAlias.hpp"

#include <array>
#include <cassert>
#include <span>

namespace zawa {

template <class Semiring,usize N>
class SquareMatrix {
public:

    using T = typename Semiring::Element;

    using A = typename Semiring::Addition;

    using M = typename Semiring::Multiplication;

    using Element = SquareMatrix;

    constexpr SquareMatrix() {
        m_data.fill(A::identity());
    }

    constexpr explicit SquareMatrix(const std::array<T,N*N>& data) : m_data{data} {}

    constexpr explicit SquareMatrix(const std::array<std::array<T,N>,N>& data) {
        for (usize i = 0 ; i < N ; i++)
            for (usize j = 0 ; j < N ; j++)
                m_data[i*N+j] = data[i][j];
    }

    constexpr explicit SquareMatrix(std::initializer_list<std::initializer_list<T>> data) {
        assert(data.size() == N);
        for (usize i = 0 ; const auto& row : data) {
            assert(row.size() == N);
            for (usize j = 0 ; const auto& x : row)
                m_data[i*N+j++]=x;
            i++;
        }
    }

    constexpr std::span<T,N> operator[](usize i) & {
        return std::span<T,N>{m_data.data()+i*N,N};
    }

    constexpr std::span<const T,N> operator[](usize i) const& {
        return std::span<const T,N>{m_data.data()+i*N,N};
    }

    constexpr usize size() const noexcept {
        return N;
    }

    static constexpr Element zero() {
        return SquareMatrix();
    }

    static constexpr Element identity() {
        auto res = SquareMatrix();
        for (usize i = 0 ; i < N ; i++)
            res[i][i] = M::identity();
        return res;
    }

    static constexpr Element operation(const Element& lhs,const Element& rhs) {
        auto res = zero();
        for (usize i = 0 ; i < N ; i++)
            for (usize k = 0 ; k < N ; k++) {
                const T x = lhs[i][k];
                for (usize j = 0 ; j < N ; j++)
                    res[i][j] = A::operation(res[i][j],M::operation(x,rhs[k][j]));
            }
        return res;
    }

private:

    std::array<T,N*N> m_data;
};

} // namespace zawa
