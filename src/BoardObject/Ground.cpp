/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Ground.cpp
*/

#include "Tile.hpp"
#include "Ground.hpp"

ind::Ground::Ground(irr::scene::ISceneManager *mgr, ind::Position position, int height) :
    BoardObject(mgr, position, "assets/stone.png")
{
    node = manager->addCubeSceneNode(TILE_SIZE, nullptr, -1);
    node->setPosition(irr::core::vector3df(position.x * TILE_SIZE, height * TILE_SIZE, position.y * TILE_SIZE));
    node->setMaterialTexture(0, texture);
}

ind::Tile ind::Ground::getTile() const
{
    return EMPTY;
}
