/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Position.hpp
*/

#ifndef BOMBERMAN_POSITION_HPP
#define BOMBERMAN_POSITION_HPP

#include <cstddef>

namespace ind {
    struct Position {
        Position(int x, int y) : x(x), y(y)
        {}

        int x;
        int y;
    };
}

#endif
