/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <irrlicht/irrlicht.h>
#include "BlockBreakable.hpp"
#include "Ground.hpp"
#include "Board.hpp"

ind::BlockBreakable::BlockBreakable(const ind::Position &boardPosition,
    ind::ORIENTATION rotation, irr::scene::IMeshSceneNode *object, Board &map
) : AbstractEntity(boardPosition, rotation, object), board(map)
{
    auto *cube = this->object->getSceneManager()->addCubeSceneNode(10.0f, NULL, -1);
    cube->setPosition(irr::core::vector3df(this->object->getPosition().X, this->object->getPosition().Y - 10.0f, this->object->getPosition().Z));

    auto *ground = new Ground(this->getPosition(), this->getRotation(), cube);
    this->addChild(ground);
}

void ind::BlockBreakable::breakBlock()
{
    this->board.setAtCoord(std::pair<int, int>(this->getPosition().x, this->getPosition().y), EMPTY);
}

void ind::BlockBreakable::draw()
{}
