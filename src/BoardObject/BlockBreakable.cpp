/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** OldBlockBreakable.cpp
*/

#include "BlockBreakable.hpp"
#include "Ground.hpp"

ind::BlockBreakable::BlockBreakable(irr::scene::ISceneManager *mgr, Position position) :
    BoardObject(mgr, position, "assets/wood.png")
{
    createGraphicalCube();
    addChild(new Ground(manager, position));
}

ind::Tile ind::BlockBreakable::getTile() const
{
    return BLOCKBREAKABLE;
}
