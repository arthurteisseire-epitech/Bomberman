/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** BoardObject.cpp
*/

#include "BoardObject.hpp"

ind::BoardObject::BoardObject(irr::scene::ISceneManager *mgr, Position position, const irr::io::path& path) :
    AbstractEntity(mgr),
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
