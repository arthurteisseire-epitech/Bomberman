/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** AiBehaviour.hpp
*/

#ifndef BOMBERMAN_AIBEHAVIOUR_HPP
#define BOMBERMAN_AIBEHAVIOUR_HPP

#include "IBehaviour.hpp"
#include "Player.hpp"

namespace ind {
    class AIBehaviour : public IBehaviour {
    public:
        explicit AIBehaviour(Player &player, Board &board);
        void update(float deltaTime) override;

    private:
        std::vector<Position> getAllFutureExplosionsPositions() const;
        std::vector<Position> getPositionsAround() const;
        void addPosIfInMap(std::vector<ind::Position> &positions, int x, int y) const;
        void move(float deltaTime, ind::Actions direction) const;
        Actions posToDir(const Position &pos) const;
        bool contain(const std::vector<Position> &pos1, const std::vector<Position> &pos2) const;
        Player &player;
        Board &board;
    };
}

#endif
