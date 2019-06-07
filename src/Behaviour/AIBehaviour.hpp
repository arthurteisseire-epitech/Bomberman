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
        std::vector<Position> getPositionsAroundWalkable() const;
        void addPosIfWalkable(std::vector<ind::Position> &positions, int x, int y) const;
        void move(float deltaTime, ind::Actions direction);
        Actions posToDir(const Position &pos) const;
        bool contain(const std::vector<Position> &pos1, const std::vector<Position> &pos2) const;
        void moveToPlayerOne(float deltaTime, std::vector<ind::Position> &posToTarget);
        void dodgeExplosions(float deltaTime);
        std::vector<Position> getPositionsAroundWithoutExplosion() const;
        bool isOnFutureExplosion(const Position &pos) const;

        Player &player;
        Board &board;
        Actions prevDir;
    };
}

#endif
