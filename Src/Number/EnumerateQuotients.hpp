#pragma once

#include "../Template/TypeAlias.hpp"

#include <type_traits>
#include <vector>
#include <utility>
#include <cassert>

namespace zawa {

template <class Value>
class EnumerateQuotients {
public:
    class Data {
    private:
        Value quotient_;
        Value l_, r_;
    public:
        Data() = default;
        constexpr Data(Value quotient, Value l, Value r) : quotient_{ quotient }, l_{ l }, r_{ r } {
            assert(l < r);
        }
        
        constexpr Value quotient() const noexcept {
            return quotient_;
        }

        constexpr Value l() const noexcept {
            return l_;
        }

        constexpr Value r() const noexcept {
            return r_;
        }

        constexpr std::pair<Value, Value> range() const noexcept {
            return std::pair{ l_, r_ };
        }

        constexpr Value len() const noexcept {
            return r_ - l_;
        }
    };

private:
    std::vector<Data> seq_;
    Value n_;

    constexpr void templateTypeAssert() const noexcept {
        static_assert(std::is_integral_v<Value>, "Template argument must be unsigned integer type.");
        static_assert(std::is_unsigned_v<Value>, "Template argument must be unsigned integer type.");
    }

    constexpr void floorBuild() noexcept {
        Value l{1U};
        while (l <= n_) {
            Value quotient{ n_ / l };
            Value r{ n_ / quotient + 1 };
            seq_.emplace_back(quotient, l, r);
            l = r;
        } 
    }

    constexpr void ceilBuild() noexcept {
        Value l{1U};
        while (l < n_) {
            Value quotient{ (n_ + l - 1) / l };
            Value r{ (n_ + quotient - 2) / (quotient - 1) };
            seq_.emplace_back(quotient, l, r);
            l = r;
        }
        seq_.emplace_back(1U, n_, n_ + 1);
    }

public:
    constexpr EnumerateQuotients() : seq_{}, n_{} {
        templateTypeAssert();
    }

    constexpr EnumerateQuotients(Value n, bool floor = true) : seq_{}, n_{ n } {
        templateTypeAssert();
        floor ? floorBuild() : ceilBuild();
        seq_.shrink_to_fit();
    }

    constexpr Value n() const noexcept {
        return n_;
    }

    constexpr Data operator[](u32 i) const noexcept {
        return seq_[i];
    }

    constexpr Value quotient(u32 i) const noexcept {
        assert(i < seq_.size()); 
        return seq_[i].quotient();
    }

    constexpr Value l(u32 i) const noexcept {
        assert(i < seq_.size()); 
        return seq_[i].l();
    }

    constexpr Value r(u32 i) const noexcept {
        assert(i < seq_.size()); 
        return seq_[i].r();
    }

    constexpr std::pair<Value, Value> range(u32 i) const noexcept {
        assert(i < seq_.size());
        return std::move(seq_[i].range());
    }

    constexpr Value len(u32 i) const noexcept {
        assert(i < seq_.size());
        return seq_[i].len();
    }

    constexpr usize size() const noexcept {
        return seq_.size();
    }

    constexpr typename decltype(seq_)::const_iterator begin() const noexcept {
        return seq_.begin();
    }

    constexpr typename decltype(seq_)::const_iterator end() const noexcept {
        return seq_.end();
    }

};

} // namespace zawa
