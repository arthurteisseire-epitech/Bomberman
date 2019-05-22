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
        Position(size_t x, size_t y) : x(x), y(y)
        {}

        size_t x;
        size_t y;
    };
}

#endif
