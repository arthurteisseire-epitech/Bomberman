/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Explosion.cpp
*/

#include "Explosion.hpp"

ind::Explosion::Explosion(ind::Position position) :
    BoardObject(position, "assets/red.jpg")
{
    createGraphicalCube();
}

ind::Tile ind::Explosion::getTile() const
{
    return EXPLOSION;
}
