/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Ground.cpp
*/

#include "Tile.hpp"
#include "Ground.hpp"

ind::Ground::Ground(Position position) :
    BoardObject(position, "assets/stone.png")
{
    createGraphicalCube(-1);
}

ind::Tile ind::Ground::getTile() const
{
    return EMPTY;
}
