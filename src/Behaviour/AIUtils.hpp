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
        AIUtils(Player &player, Board &board);

        bool contain(const std::vector<Position> &pos1, const std::vector<Position> &pos2) const;
        void addPosIfWalkable(std::vector<ind::Position> &positions, int x, int y) const;
        Actions posToDir(const Position &pos) const;
        std::vector<Position> getPositionsAroundWithoutExplosion() const;
        bool isOnFutureExplosion(const Position &pos) const;
        std::vector<Position> getAllFutureExplosionsPositions() const;
        std::vector<Position> getPositionsAroundWalkable() const;

    private:
        Player &player;
        Board &board;
    };
}

#endif
