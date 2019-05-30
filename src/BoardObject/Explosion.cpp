/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Explosion.cpp
*/

#include "TimeoutObjectBehaviour.hpp"
#include "Explosion.hpp"

ind::Explosion::Explosion(ind::Position position) :
    BoardObject(position, "assets/red.jpg"),
    TimeoutObject(1)
{
    createGraphicalCube();
    setBehaviour(new TimeoutObjectBehaviour(*this));
}

ind::Tile ind::Explosion::getTile() const
{
    return EXPLOSION;
}
