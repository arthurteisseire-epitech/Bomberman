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
        static ind::Orientation posToDir(const Position &playerPos, const ind::Position &pos);
        static void addPosIfWalkable(const Board &board, std::vector<ind::Position> &positions, int x, int y);
        static std::vector<ind::Position> getPositionsAroundWithoutExplosion(const Board &board, const Position &pos);
        static bool isOnFutureExplosion(const Board &board, const ind::Position &pos);
        static std::vector<ind::Position> getAllFutureExplosionsPositions(const Board &board, const Position &pos);
        static std::vector<ind::Position> getPositionsAroundWalkable(const Board &board, const Position &pos);
    };
}

#endif
