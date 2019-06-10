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
        enum State {
            DODGE,
            MOVE_TO_PLAYER,
            PLACE_BOMB,
            NONE,
        };
        std::vector<Position> getAllFutureExplosionsPositions() const;
        std::vector<Position> getPositionsAroundWalkable() const;
        void action();
        void execFromMap(const std::map<State, std::function<void()>> &map);

        void dodgeExplosions();
        void moveToPlayer();

        void alterDodge();
        void alterMoveToPlayer();

        void move(ind::Actions direction);
        bool contain(const std::vector<Position> &pos1, const std::vector<Position> &pos2) const;
        void addPosIfWalkable(std::vector<ind::Position> &positions, int x, int y) const;
        Actions posToDir(const Position &pos) const;
        std::vector<Position> getPositionsAroundWithoutExplosion() const;
        bool isOnFutureExplosion(const Position &pos) const;

        State state;
        Player &player;
        Board &board;
        Actions prevDir;
        float deltaTime;
        std::map<State, std::function<void()>> alterStateMap;
        std::map<State, std::function<void()>> actionStateMap;
    };
}

#endif
