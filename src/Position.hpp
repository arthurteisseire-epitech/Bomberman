/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Position.hpp
*/

#ifndef BOMBERMAN_POSITION_HPP
#define BOMBERMAN_POSITION_HPP

#include <cstddef>
#include <iostream>

namespace ind {
    struct Position {
        Position(int x, int y);

        bool operator==(const Position &pos) const;
        bool operator!=(const Position &pos) const;

        int x;
        int y;
    };
    std::ostream &operator<<(std::ostream &o, const Position &pos);
    std::ostream &operator>>(std::ostream &o, Position &pos);
}

#endif
