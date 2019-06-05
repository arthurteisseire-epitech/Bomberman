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
        std::map<ind::Actions, irr::EKEY_CODE> &playerKeys;
        std::map<ind::Actions, irr::EKEY_CODE> playerOneKeys = {
            {PlaceBomb, irr::KEY_KEY_M},
            {Up,        irr::KEY_UP},
            {Left,      irr::KEY_LEFT},
            {Right,     irr::KEY_RIGHT},
            {Down,      irr::KEY_DOWN},
        };
        std::map<ind::Actions, irr::EKEY_CODE> playerTwoKeys = {
            {PlaceBomb, irr::KEY_KEY_1},
            {Up,        irr::KEY_KEY_Z},
            {Left,      irr::KEY_KEY_Q},
            {Right,     irr::KEY_KEY_D},
            {Down,      irr::KEY_KEY_S},
        };
        std::map<ind::Actions, ind::ORIENTATION> directionsMapping = {
            {Up,    ind::NORTH},
            {Down,  ind::SOUTH},
            {Left,  ind::WEST},
            {Right, ind::EAST}
        };
        std::map<ind::ORIENTATION, irr::core::vector3df> directionAngles = {
            {ind::NORTH, {0, 90,  0}},
            {ind::SOUTH, {0, 270, 0}},
            {ind::EAST,  {0, 180, 0}},
            {ind::WEST,  {0, 0,   0}}
        };

        bool wantToWalk() const;
        void move(float deltaTime) const;
    };
}
