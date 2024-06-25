#pragma once

#include "../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <type_traits>
#include <utility>
#include <vector>

namespace zawa {

template <class Semiring>
class Matrix {
public:
    using E = typename Semiring::Element;
    using A = typename Semiring::Addition;
    using M = typename Semiring::Multiplication;

    Matrix() = default;
    Matrix(usize n) : dat_(n, std::vector<E>(n, Zero())) {}
    Matrix(usize h, usize w) : dat_(h, std::vector<E>(w, Zero())) {}
    Matrix(const Matrix& mat) : dat_{mat.dat_} {}
    Matrix(Matrix&& mat) : dat_{std::move(mat.dat_)} {}

    static E Zero() {
        return A::identity();
    }
    static E One() {
        return M::identity();
    }
    static Matrix O(usize h, usize w) {
        return Matrix(h, w);
    }
    static Matrix I(usize n) {
        Matrix res(n);
        for (usize i{} ; i < n ; i++) {
            res[i][i] = One();
        }
        return res;
    }

    inline bool empty() const {
        return dat_.empty();
    }
    inline usize height() const {
        return dat_.size();
    }
    inline usize width() const {
        assert(not empty());
        return dat_[0].size();
    }
    void fill(const E& v) {
        for (usize i{} ; i < height() ; i++) {
            std::fill(dat_[i].begin(), dat_[i].end(), v);
        }
    } 
    Matrix rotated() const {
        Matrix res(width(), height());
        for (usize i{} ; i < height() ; i++) {
            for (usize j{} ; j < width() ; j++) {
                res[j][i] = dat_[i][j];
            }
        }
        return res;
    }
    Matrix pow(u64 exp) const {
        assert(height() == width());
        Matrix res{I(height())}, base{*this};
        while (exp) {
            if (exp & 1) {
                res = res * base;
            }
            base = base * base;
            exp >>= 1;
        }
        return res;
    }

    const std::vector<E>& operator[](usize i) const {
        assert(i < height());
        return dat_[i];
    }
    std::vector<E>& operator[](usize i) {
        assert(i < height());
        return dat_[i];
    }
    Matrix& operator=(const Matrix& mat) {
        dat_ = mat.dat_;
        return *this;
    }
    Matrix& operator=(Matrix&& mat) {
        dat_ = std::move(mat.dat_);
        return *this;
    }
    Matrix& operator+=(const Matrix& mat) {
        assert(height() == mat.height());
        assert(width() == mat.width());
        for (usize i{} ; i < height() ; i++) {
            for (usize j{} ; j < width() ; j++) {
                dat_[i][j] = A::operation(dat_[i][j], mat[i][j]);
            }
        }
        return *this;
    }
    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
        return Matrix{lhs} += rhs;
    }
    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
        assert(lhs.height() == rhs.width());
        assert(lhs.width() == rhs.height());
        Matrix res(lhs.height(), rhs.width());
        for (usize i{} ; i < lhs.height() ; i++) {
            for (usize j{} ; j < rhs.width() ; j++) {
                for (usize k{} ; k < lhs.width() ; k++) {
                    res[i][j] = A::operation(res[i][j], M::operation(lhs[i][k], rhs[k][j]));
                }
            }
        }
        return res;
    }

    // 行列式
    E determinant() const {
        assert(height() == width());
        usize n{height()};
        Matrix<Semiring> dat{*this};
        E res{M::identity()};
        const E m1{A::inverse(M::identity())}; // -1
        for (usize i{} ; i < n ; i++) {
            for (usize j{i} ; j < n ; j++) {
                if (dat[j][i] == A::identity()) {
                    continue; 
                }
                if (i != j) {
                    std::swap(dat[i], dat[j]);
                    res = M::operation(res, m1);
                }
                break;
            }
            res = M::operation(res, dat[i][i]);
            if (dat[i][i] == A::identity()) continue;
            for (usize j{i + 1} ; j < n ; j++) {
                if (dat[j][i] == A::identity()) {
                    continue;
                }
                E coef{M::operation(m1, M::operation(dat[j][i], M::inverse(dat[i][i])))};
                for (usize k{i} ; k < n ; k++) {
                    dat[j][k] = A::operation(dat[j][k], M::operation(coef, dat[i][k]));
                }
            }
        }
        return res;
    }
    // 余因子
    E cofactor(usize r, usize c) const {
        assert(height() == width());
        usize n{height()};
        assert(n >= usize{2});
        Matrix tmp(n - 1, n - 1);
        for (usize i{} ; i < n ; i++) {
            if (i == r) {
                continue;
            }
            for (usize j{} ; j < n ; j++) {
                if (j == c) {
                    continue;
                }
                tmp[i > r ? i - 1 : i][j > c ? j - 1 : j] = dat_[i][j];
            }
        }
        return tmp.determinant();
    }

private:
    std::vector<std::vector<E>> dat_;
};

} // namespace zawa
