#pragma once

#include "../Template/TypeAlias.hpp"
#include "../Number/Mersenne61ModInt.hpp"

#include <algorithm>
#include <cassert>
#include <iterator>
#include <memory>
#include <random>
#include <string>
#include <type_traits>
#include <vector>

namespace zawa {

class RollingHashFactory {
public:
    using Modulo = Mersenne61ModInt;
    using Value = Modulo::Value;
    using Size = usize;
    class Hash {
    private:
        Value hash_{};        
        Size len_{};
    public:
        Hash() {}
        Hash(Value hash, usize len) : hash_{hash}, len_{len} {}
        Value hash() const noexcept {
            return hash_;
        }
        Size len() const noexcept {
            return len_;
        }
        friend bool operator==(const Hash& lhs, const Hash& rhs) {
            return lhs.hash() == rhs.hash() and lhs.len() == rhs.len();
        }
        friend bool operator!=(const Hash& lhs, const Hash& rhs) {
            return lhs.hash() != rhs.hash() or lhs.len() != rhs.len();
        }
    };
    static constexpr Value mod{Modulo::Mod()};
private:
    std::mt19937 mt{std::random_device{}()};
    std::vector<Value> pows{};
    Value base{};

    void expand(Size len) {
        Size now{pows.size()};
        if (len + 1 <= now) return;
        pows.resize(len + 1);
        for (Size i{now} ; i < pows.size() ; i++) {
            pows[i] = Modulo::Mul(pows[i - 1], base);
        }
    }

public:
    RollingHashFactory() = default;
    RollingHashFactory(Size initLength, Value maxSigma = 127) 
        : pows(1, Value{1}), base{(mt() % (mod - maxSigma)) + maxSigma + 1} {
        pows.reserve(initLength + 1);
        expand(initLength);
    }

    class RollingHash {
    public:
        using Value = RollingHashFactory::Value;
        using Size = RollingHashFactory::Size;
        using Hash = RollingHashFactory::Hash;
    private:
        using Modulo = RollingHashFactory::Modulo;
        Size n_{};
        std::vector<Hash> prefix_{};
        std::shared_ptr<std::vector<Value>> pows_{};
    public:
        RollingHash() = default;
        RollingHash(const std::vector<Hash>& prefix, const std::vector<Value>& pows) 
            : n_{prefix.size() - 1}, prefix_{prefix}, pows_{std::make_shared<std::vector<Value>>(pows)} {}

        constexpr Size size() const noexcept {
            return n_;
        }

        Hash prefix(Size r) const {
            assert(r <= size());
            return prefix_[r];
        }

        Hash range(Size l, Size r) const {
            assert(l <= size());
            assert(l <= r);
            assert(r <= size());
            static constexpr Value positiver{4ull * Modulo::Mod()};
            return Hash{
                Modulo::Modulo(prefix_[r].hash() + positiver - Modulo::UnsafeMul(prefix_[l].hash(), (*pows_)[r - l])),
                r - l
            };
        }

        Size lcp(Size l1, Size r1, Size l2, Size r2) {
            assert(l1 <= size());
            assert(r1 <= size());
            assert(l2 <= size());
            assert(r2 <= size());
            assert(l1 <= r1);
            assert(l2 <= r2);
            Size L{}, R{std::min(r1 - l1, r2 - l2) + 1};
            while (R - L > 1) {
                Size mid{(L + R) >> 1};
                (range(l1, l1 + mid) == range(l2, l2 + mid) ? L : R) = mid;
            }
            return L;
        }
    };

    template <class RandomAccessIterator>
    RollingHash create(RandomAccessIterator first, RandomAccessIterator last) {
        static_assert(std::is_convertible_v<decltype(*first), Value>, "value must be convertible to unsigned integer");
        Size n{static_cast<Size>(std::distance(first, last))};
        expand(n);
        std::vector<Hash> roll(1);
        roll.reserve(n + 1);
        for (auto it{first} ; it != last ; it++) {
            roll.emplace_back(
                Modulo::Modulo(Modulo::UnsafeMul(roll.back().hash(), base) + *it),
                roll.back().len() + 1
            );
        }
        return RollingHash(roll, pows);
    }

    template <class T>
    RollingHash create(const std::vector<T>& a) {
        return create(a.begin(), a.end()); 
    }

    template <class T>
    Hash hash(const std::vector<T>& a) {
        static_assert(std::is_convertible_v<T, Value>, "value must be convertible to unsigned integer");
        expand(a.size());
        Value value{};
        for (const T& x : a) {
            value = Modulo::Modulo(Modulo::UnsafeMul(value, base) + x);
        }
        return Hash{value, a.size()};
    }

    RollingHash create(const std::string& s) {
        return create(s.begin(), s.end());
    }

    Hash hash(const std::string& s) {
        expand(s.size());
        Value value{};
        for (const char& c : s) {
            value = Modulo::Modulo(Modulo::UnsafeMul(value, base) + c);
        }
        return Hash{value, s.size()};
    }

    Hash concate(const Hash& lhs, const Hash& rhs) {
        return Hash{
            Modulo::Modulo(Modulo::UnsafeMul(lhs.hash(), pows[rhs.len()]) + rhs.hash()),
            lhs.len() + rhs.len()
        };
    }
};


} // namespace zawa
