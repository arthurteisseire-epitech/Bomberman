/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** PlayerFactory.hpp
*/

#ifndef BOMBERMAN_PLAYERFACTORY_HPP
#define BOMBERMAN_PLAYERFACTORY_HPP

#include "Player.hpp"

namespace ind {
    class PlayerFactory {
    public:
        static Player *create(PlayerNumber playerNumber, const Position &position, Board &map);
    private:
        static animations::Animator *initAnimator(const ind::PlayerNumber &playerNumber);
    };
}

#endif
