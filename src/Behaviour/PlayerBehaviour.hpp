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
            void update() override;

        private:
            Player &player;
            PlayerNumber playerNumber;
            std::map<ind::Actions, irr::EKEY_CODE> playerOneKeys = {
                {Bomb, irr::KEY_KEY_M},
                {Up, irr::KEY_UP},
                {Left, irr::KEY_LEFT},
                {Right, irr::KEY_RIGHT},
                {Down, irr::KEY_DOWN},
            };
            std::map<ind::Actions, irr::EKEY_CODE> playerTwoKeys = {
                {Bomb, irr::KEY_KEY_1},
                {Up, irr::KEY_KEY_Z},
                {Left, irr::KEY_KEY_Q},
                {Right, irr::KEY_KEY_D},
                {Down, irr::KEY_KEY_S},
            };
    };
}
