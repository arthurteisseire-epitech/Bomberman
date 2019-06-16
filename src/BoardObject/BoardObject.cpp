/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** BoardObject.cpp
*/

#include "Path.hpp"
#include "BoardObject.hpp"

ind::BoardObject::BoardObject(Position position, const std::string &path) :
    AbstractEntity(),
    position(position),
    node(nullptr)
{
    texture = manager->getVideoDriver()->getTexture(Path::realpath(path).c_str());
}

const ind::Position &ind::BoardObject::getPosition() const
{
    return position;
}

ind::BoardObject::~BoardObject()
{
    if (node)
        node->remove();
}

void ind::BoardObject::createGraphicalCube(int height)
{
    node = manager->addCubeSceneNode(TILE_SIZE, nullptr, -1);
    node->setPosition(irr::core::vector3df(position.x * TILE_SIZE, height * TILE_SIZE, position.y * TILE_SIZE));
    node->setMaterialTexture(0, texture);
}

std::string ind::BoardObject::toString() const
{
    return std::to_string(position.x) + "," + std::to_string(position.y) + " ";
}
