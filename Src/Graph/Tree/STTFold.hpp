#pragma once

#include "./StaticTopTree.hpp"
#include "./STTDPInterface.hpp"

#include <concepts>
#include <variant>
#include <vector>

namespace zawa {

template <concepts::STTDPInterface DP>
typename DP::PathCluster STTFold(const STTGraph& g,usize root,std::vector<typename DP::Vertex> vs,std::vector<typename DP::Edge> es) {
    assert(g.size()==vs.size());
    assert(g.size()==es.size()+1);
    using Vertex=typename DP::Vertex;
    using Edge=typename DP::Edge;
    using Path=typename DP::PathCluster;
    using Point=typename DP::PointCluster;
    using Item=std::variant<Path,Point>;
    static constexpr usize PathId = 0;
    static constexpr usize PointId = 1;
    StaticTopTree stt{g,root};
    std::vector<Item> dp(stt.size());
    for (usize i = 0 ; i < stt.size() ; i++)
        if (i != StaticTopTree::Empty) {
            const StaticTopTree::Node& node = stt[i];
            switch (node.type) {
                case STTOp::Vertex:
                    {
                        Vertex v = std::move(vs[node.invV]);
                        dp[i] = Item{std::in_place_index<PathId>, DP::vertex(std::move(v))};
                        break;
                    }
                case STTOp::AddVertex:
                    {
                        Point ch = std::move(std::get<PointId>(dp[node[0]]));
                        Vertex v = std::move(vs[node.invV]);
                        dp[i] = Item{std::in_place_index<PathId>, DP::addVertex(std::move(ch),std::move(v))};
                        break;
                    }
                case STTOp::AddEdge:
                    {
                        Path ch = std::move(std::get<PathId>(dp[node[0]]));
                        Edge e = std::move(es[node.invE]);
                        dp[i] = Item{std::in_place_index<PointId>, DP::addEdge(std::move(ch), std::move(e))};
                        break;
                    }
                case STTOp::Rake:
                    {
                        Point l = std::move(std::get<PointId>(dp[node[0]]));
                        Point r = std::move(std::get<PointId>(dp[node[1]]));
                        dp[i] = Item{std::in_place_index<PointId>, DP::rake(std::move(l),std::move(r))};
                        break;
                    }
                case STTOp::Compress:
                    {
                        Path l = std::move(std::get<PathId>(dp[node[0]]));
                        Edge e = std::move(es[node.invE]);
                        Path r = std::move(std::get<PathId>(dp[node[1]]));
                        dp[i] = Item{std::in_place_index<PathId>, DP::compress(std::move(l),std::move(e),std::move(r))};
                        break;
                    }
                default:
                    break;
            }

        }
    return std::move(std::get<PathId>(dp[stt.root()]));
}

} // namespace zawa
