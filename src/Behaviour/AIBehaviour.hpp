/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** AiBehaviour.hpp
*/

#ifndef BOMBERMAN_AIBEHAVIOUR_HPP
#define BOMBERMAN_AIBEHAVIOUR_HPP

#include "AIUtils.hpp"
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
            FIND_BLOCKBREACKABLE,
        };
        void action();
        void execFromMap(const std::map<State, std::function<void()>> &map);

        void alterDodge();
        void alterMoveToPlayer();
        void alterFindBlockBreakable();

        void actionDodge();
        void actionMoveToPlayer();
        void actionFindBlockBreackable();

        void move(Orientation dir);
        void stopWalking();

        Player &player;
        Board &board;
        State state;
        Orientation prevDir;
        float deltaTime;
        std::map<State, std::function<void()>> alterStateMap;
        std::map<State, std::function<void()>> actionStateMap;
    };
}

#endif
