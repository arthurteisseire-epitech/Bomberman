/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** OldBlockBreakable.cpp
*/

#include "BlockBreakable.hpp"
#include "Ground.hpp"

ind::BlockBreakable::BlockBreakable(irr::scene::ISceneManager *mgr, ind::Position position, int height) :
    BoardObject(mgr, position, "assets/wood.png")
{
    node = manager->addCubeSceneNode(TILE_SIZE, nullptr, -1);
    node->setPosition(irr::core::vector3df(position.x * TILE_SIZE, height, position.y * TILE_SIZE));
    node->setMaterialTexture(0, texture);

    auto *ground = new Ground(manager, position);
    addChild(ground);
}

ind::Tile ind::BlockBreakable::getTile() const
{
    return BLOCKBREAKABLE;
}
