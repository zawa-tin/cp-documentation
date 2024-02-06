#pragma once

#include <type_traits>

namespace zawa {

template <class Value>
class SuffixProductMonoidData {
    Value product_{}, suffix_{};
public:
    SuffixProductMonoidData() = default;
    SuffixProductMonoidData(const Value& product, const Value& suffix)
        : product_{product}, suffix_{suffix} {}

    inline const Value& product() const noexcept {
        return product_;
    }
    inline const Value& suffix() const noexcept {
        return suffix_;
    }
};

template <class O, class F>
class SuffixProductMonoid {
    static_assert(std::is_same_v<typename O::Element, typename F::Element>);
public:
    using Element = SuffixProductMonoidData<typename O::Element>;
    static Element identity() noexcept {
        return SuffixProductMonoidData{O::identity(), F::identity()};
    }
    static Element operation(const Element& l, const Element& r) noexcept {
        return SuffixProductMonoidData{
            O::operation(l.product(), r.product()),
            F::operation(O::operation(l.suffix(), r.product()), r.suffix())
        };
    }
};

} // namespace zawa
