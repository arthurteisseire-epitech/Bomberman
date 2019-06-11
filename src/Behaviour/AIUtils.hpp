/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** AiUtils.hpp
*/

#ifndef BOMBERMAN_AIUTILS_HPP
#define BOMBERMAN_AIUTILS_HPP

#include "Player.hpp"

namespace ind {
    class AIUtils {
    public:
        static bool contain(const std::vector<Position> &pos1, const std::vector<Position> &pos2);
        static Orientation posToDir(const Position &playerPos, const Position &pos);
        static void addPosIfInMap(const Board &board, std::vector<Position> &positions, int x, int y);
        static std::vector<Position> getPositionsAroundWithoutExplosion(const Board &board, const Position &pos);
        static bool isOnFutureExplosion(const Board &board, const Position &pos);
        static std::vector<Position> getAllFutureExplosionsPositions(const Board &board, const Position &pos);
        static std::vector<Position> getPositionsAroundWalkable(const Board &board, const Position &pos);
        static std::vector<Position> getPositionsAround(const Board &board, const Position &pos);
        static std::vector<Position> getPositionsAside(const Board &board, const Position &pos);
        static std::vector<Position> findBlockBreakable(const Board &board, const Position &playerPos);
        static bool isBlockBreakableAround(const Board &board, const Position &playerPos);
        static std::vector<Position> findNearestPlayerPositions(Board &board, const Position &pos);

        template<typename Pos>
        static void applyUntil(const Board &board, std::vector<Position> &positions, Pos getPosAt)
        {
            for (int i = 1; ; ++i) {
                positions.push_back(getPosAt(i));
                if (!board.isWalkable(getPosAt(i)))
                    break;
            }
        }
    };
}

#endif
