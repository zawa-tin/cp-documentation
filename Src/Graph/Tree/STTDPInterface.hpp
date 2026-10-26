#pragma once

#include <concepts>
#include <utility>

namespace zawa {

namespace concepts {

template <class T>
concept STTDPInterface = requires {
    typename T::Vertex;
    typename T::Edge;
    typename T::PathCluster;
    typename T::PointCluster;
    { T::vertex(std::declval<typename T::Vertex>()) } -> std::same_as<typename T::PathCluster>;
    { T::addVertex(std::declval<typename T::PointCluster>(), std::declval<typename T::Vertex>()) } -> std::same_as<typename T::PathCluster>;
    { T::addEdge(std::declval<typename T::PathCluster>(), std::declval<typename T::Edge>()) } -> std::same_as<typename T::PointCluster>;
    { T::rake(std::declval<typename T::PointCluster>(), std::declval<typename T::PointCluster>()) } -> std::same_as<typename T::PointCluster>;
    { T::compress(std::declval<typename T::PathCluster>(), std::declval<typename T::Edge>(), std::declval<typename T::PathCluster>()) } -> std::same_as<typename T::PathCluster>;
};

} // namespace concepts

} // namespace zawa
