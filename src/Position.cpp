/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Position.cpp
*/

#include "Position.hpp"

ind::Position::Position(int x, int y) :
    x(x),
    y(y)
{
}

bool ind::Position::operator==(const Position &pos) const
{
    return pos.x == x && pos.y == y;
}

std::ostream &ind::operator<<(std::ostream &o, const Position &pos)
{
    o << "Position(" << pos.x << "," << pos.y << ")";
    return o;
}
