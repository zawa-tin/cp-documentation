#pragma once

#include <queue>
#include <optional>
#include <type_traits>
#include <vector>

namespace zawa {

    // domain, codomain
    template <class D, class C>
    class SlopeTrick {
        static_assert(std::is_integral_v<D>, "zawa::SlopeTrick::D must be integral");
        static_assert(std::is_integral_v<C>, "zawa::SlopeTrick::C must be integral");
    public:
        using SizeType = usize;
        SlopeTrick() = default;
        SlopeTrick(const SlopeTrick& st) : L_{st.L_}, R_{st.R_}, min_{st.min_} {}
        SlopeTrick(SlopeTrick&& st) : L_{std::move(st.L_)}, R_{std::move(st.R_)}, min_{st.min_} {}
        SlopeTrick& operator=(const SlopeTrick& st) {
            L_ = st.L_;
            R_ = st.R_;
            min_ = st.min_;
            return *this;
        }
        SlopeTrick& operator=(SlopeTrick&& st) {
            L_ = std::move(st.L_);
            R_ = std::move(st.R_);
            min_ = st.min_;
            return *this;
        }
        // get min
        C min() const {
            return min_;
        }
        // get [l0, r0]
        std::pair<std::optional<D>, std::optional<D>> argmin() const {
            return {
                L_.empty() ? std::nullopt : std::optional<D>{lvalue(L_.top())},
                R_.empty() ? std::nullopt : std::optional<D>{rvalue(R_.top())}
            };
        }
        // add y = c
        void addConstant(C c) {
            min_ += c;
        }
        // add y = max(0, x - a)
        void addMax0XA(D a) {
            if (L_.empty() or lvalue(L_.top()) <= a) {
                pushR(a);
            }
            else {
                pushR(lvalue(L_.top()));
                min_ += lvalue(L_.top()) - a;
                L_.pop();
                pushL(a);
            }
        }
        // add y = max(0, a - x)
        void addMax0AX(D a) {
            if (R_.empty() or a <= rvalue(R_.top())) {
                pushL(a);
            }
            else {
                pushL(rvalue(R_.top()));
                min_ += a - rvalue(R_.top());
                R_.pop();
                pushR(a);
            }
        }
        // add y = |x - a|
        void addAbsoluteXA(D a) {
            addMax0XA(a);
            addMax0AX(a);
        }
        // 前から累積minをとった関数に置き換える
        void prefixMin() {
            R_ = std::move(decltype(R_){});
            addR_ = D{0};
        }
        // 後ろから累積minをとった関数に置き換える
        void suffixMin() {
            L_ = std::move(decltype(L_){});
            addL_ = D{0};
        }
        // g(x) = min f(k) (x - a <= k <= x - b)に置き換える
        void slidingWindowMin(D a, D b) {
            addR_ += b;
            addL_ += a;
        }
        // x軸方向にc平行移動する
        void translation(D c) {
            slidingWindowMin(c, c);
        }
        // 傾きがk -> k + 1 (x < 0)となる点を列挙する
        std::vector<D> enumerateL() const {
            decltype(L_) L{L_};
            std::vector<D> res;
            while (L.size()) {
                res.emplace_back(lvalue(L.top()));
                L.pop();
            }
            return res;
        }
        // 傾きがk -> k + 1 (x >= 0)となる点を列挙する
        std::vector<D> enumerateR() const {
            decltype(R_) R{R_};
            std::vector<D> res;
            while (R.size()) {
                res.emplace_back(rvalue(R.top()));
                R.pop();
            }
            return res;
        }
        // get f(x)
        // 注意: O(N\log N)かかる
        C f(D x) const {
            C res{min_};
            for (auto l : enumerateL()) {
                res += std::max(D{0}, l - x);
            }
            for (auto r : enumerateR()) {
                res += std::max(D{0}, x - r);
            }
            return res;
        }
        void clear() {
            L_ = decltype(L_){};
            R_ = decltype(R_){};
            min_ = D{0};
        }
        SlopeTrick& operator+=(const SlopeTrick& st) {
            min_ += st.min();
            for (auto l : st.enumerateL()) {
                addMax0AX(l);
            }
            for (auto r : st.enumerateR()) {
                addMax0XA(r);
            }
            return *this;
        }
        inline SizeType sizeL() const {
            return L_.size();
        }
        inline SizeType sizeR() const {
            return R_.size();
        }
        inline SizeType size() const {
            return sizeL() + sizeR();
        }
    private:
        std::priority_queue<D> L_{};
        std::priority_queue<D, std::vector<D>, std::greater<D>> R_{};
        D addL_{}, addR_{};
        C min_{};

        inline D lvalue(D l) const noexcept {
            return l + addL_;
        }
        inline D rvalue(D r) const noexcept {
            return r + addR_;
        }
        inline void pushL(D v) noexcept {
            L_.push(v - addL_);
        }
        inline void pushR(D v) noexcept {
            R_.push(v - addR_);
        }
    };

} // namespace zawa
