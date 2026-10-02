#pragma once

#include <concepts>
#include <type_traits>

namespace zawa {

namespace concepts {

template <class T>
concept Point = requires (T p) {
    typename T::P;
    typename T::W;
    { p.x } -> std::same_as<typename T::P&>;
    { p.y } -> std::same_as<typename T::P&>;
    { p.w } -> std::same_as<typename T::W&>;
};

template <class T>
concept RectangleAdd = requires (T r) {
    typename T::P;
    typename T::W;
    { r.l } -> std::same_as<typename T::P&>;
    { r.d } -> std::same_as<typename T::P&>;
    { r.r } -> std::same_as<typename T::P&>;
    { r.u } -> std::same_as<typename T::P&>;
    { r.w } -> std::same_as<typename T::W&>;
};

template <class T>
concept Rectangle = requires (T r) {
    typename T::P;
    { r.l } -> std::same_as<typename T::P&>;
    { r.d } -> std::same_as<typename T::P&>;
    { r.r } -> std::same_as<typename T::P&>;
    { r.u } -> std::same_as<typename T::P&>;
};

} // namespace concepts


} // namespace zawa
