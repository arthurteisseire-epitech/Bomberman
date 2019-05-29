/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Ground.cpp
*/

#include "Tile.hpp"
#include "Ground.hpp"

ind::Ground::Ground(irr::scene::ISceneManager *mgr, ind::Position position) :
    BoardObject(mgr, position, "assets/stone.png")
{
    createGraphicalCube(-1);
}

ind::Tile ind::Ground::getTile() const
{
    return EMPTY;
}
