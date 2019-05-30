/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** BoardObject.cpp
*/

#include "BoardObject.hpp"

ind::BoardObject::BoardObject(Position position, const irr::io::path &path) :
    AbstractEntity(),
    position(position),
    node(nullptr)
{
    texture = manager->getVideoDriver()->getTexture(path);
}

const ind::Position &ind::BoardObject::getPosition() const
{
    return position;
}

ind::BoardObject::~BoardObject()
{
    node->remove();
}

void ind::BoardObject::createGraphicalCube(int height)
{
    node = manager->addCubeSceneNode(TILE_SIZE, nullptr, -1);
    node->setPosition(irr::core::vector3df(position.x * TILE_SIZE, height * TILE_SIZE, position.y * TILE_SIZE));
    node->setMaterialTexture(0, texture);
}
