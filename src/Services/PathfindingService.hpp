/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by antoine_dh,
*/

#pragma once

#include <queue>
#include "Map/Board.hpp"

namespace ind {
    class PathfindingService {
        public:
            std::vector<ind::Position> searchPath(const ind::Board &board,
                const ind::Position &from,
                const ind::Position &to);

        private:
            struct Node : public Position {
                Node();
                Node(int x, int y, int distance, int heuristic = 0);

                int distance;
                int heuristic;
            };

            struct NodeComparator {
                constexpr bool operator()(const Node &lhs, const Node &rhs) const
                {
                    return lhs.heuristic > rhs.heuristic;
                }
            };

            struct State {
                explicit State(const ind::Board &board);

                void checkNeighbors(const Node &u, const Position &to);
                void backtrack(const Position &begin, int x, int y, int distance);

                std::priority_queue<Node, std::vector<Node>, NodeComparator> open;
                std::vector<std::vector<Node>> closed;
                Position mapSize;
                std::vector<ind::Position> path;
            };

            static int heuristicDistance(const Position &a, const Position &b);
    };
}
