/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Orientation.cpp
*/

#include "Orientation.hpp"

std::ostream &ind::operator<<(std::ostream &os, Orientation orientation)
{
    if (orientation == NORTH)
        os << "NORTH";
    else if (orientation == SOUTH)
        os << "SOUTH";
    else if (orientation == WEST)
        os << "WEST";
    else if (orientation == EAST)
        os << "EAST";
    else
        os << "NONE";
    return os;
}
