#pragma once

#include <optional>

namespace zawa {

template <class T>
class SameMonoidData {
private:
    std::optional<T> element_{};
    bool same_{true};
public:

    static std::optional<T> merge(const std::optional<T>& l, const std::optional<T>& r) noexcept {
        if (l and r) return (l.value() == r.value() ? l : std::nullopt);
        if (l) return l;
        if (r) return r;
        return std::nullopt;
    }

    SameMonoidData() = default;
    SameMonoidData(const T& element) 
        : element_{element}, same_{true} {}
    SameMonoidData(const std::optional<T>& element, bool same)
        : element_{element}, same_{same} {}

    bool empty() const noexcept {
        return same_ and !element_.has_value();
    }
    bool same() const noexcept {
        return same_;
    }
    std::optional<T> element() const noexcept {
        return element_;
    }
    T value() const noexcept {
        return element_.value();
    }
};

template <class T>
struct SameMonoid {
public:
    using Element = SameMonoidData<T>;
    static Element identity() noexcept {
        return Element{}; 
    }
    static Element operation(const Element& l, const Element& r) {
        if (l.empty() and r.empty()) return identity();
        if (l.empty()) return r;
        if (r.empty()) return l;
        std::optional<T> element{Element::merge(l.element(), r.element())};
        return Element{element, l.same() and r.same() and element.has_value()};
    }
};

} // namespace zawa
