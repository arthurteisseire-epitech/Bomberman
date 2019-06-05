/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include <map>
#include "Player.hpp"

namespace ind {
    class PlayerBehaviour : public IBehaviour {
    public:
        PlayerBehaviour(Player &player, PlayerNumber playerNumber);
        void update(float) override;

    private:
        Player &player;
        const std::map<ind::Actions, irr::EKEY_CODE> &playerKeys;

        bool wantToWalk() const;
        void move(float deltaTime) const;
        void updateAnimation() const;
    };
}
