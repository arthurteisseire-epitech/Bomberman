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

        bool operator==(const Position &pos) const
        {
            return pos.x == x && pos.y == y;
        }

        int x;
        int y;
    };
}

#endif
