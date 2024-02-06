#pragma once

#include <type_traits>

namespace zawa {

template <class Value>
class PrefixProductMonoidData {
    Value product_{}, prefix_{};
public:
    PrefixProductMonoidData() = default;
    PrefixProductMonoidData(const Value& product, const Value& prefix)
        : product_{product}, prefix_{prefix} {}

    inline const Value& product() const noexcept {
        return product_;
    }
    inline const Value& prefix() const noexcept {
        return prefix_;
    }
};

template <class O, class F>
class PrefixProductMonoid {
    static_assert(std::is_same_v<typename O::Element, typename F::Element>);
public:
    using Element = PrefixProductMonoidData<typename O::Element>;
    static Element identity() noexcept {
        return PrefixProductMonoidData{O::identity(), F::identity()};
    }
    static Element operation(const Element& l, const Element& r) noexcept {
        return PrefixProductMonoidData{
            O::operation(l.product(), r.product()),
            F::operation(l.prefix(), O::operation(l.product(), r.prefix()))
        };
    }
};

} // namespace zawa
