/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Wall.cpp
*/

#include "Wall.hpp"

ind::Wall::Wall(ind::Position position) :
    BoardObject(position, "assets/wall.png")
{
    createGraphicalCube();
}

ind::Tile ind::Wall::getTile() const
{
    return WALL;
}

std::string ind::Wall::toString() const
{
    return BoardObject::toString() + WALL_NAME;
}
