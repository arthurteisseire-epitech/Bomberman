/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Keys.hpp
*/

#ifndef BOMBERMAN_KEYS_HPP
#define BOMBERMAN_KEYS_HPP

#include <map>
#include "Player.hpp"

namespace ind {
    class Keys {
    public:
        static const std::map<ind::Actions, irr::EKEY_CODE> playerOne;
        static const std::map<ind::Actions, irr::EKEY_CODE> playerTwo;
    };
}

#endif
