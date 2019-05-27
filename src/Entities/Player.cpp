/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <iostream>
#include <crossPlatform.hpp>
#include "Player.hpp"
#include "Utilities/to2d.hpp"
#include "PlayerBehaviour.hpp"

void ind::Player::placeBomb()
{
    std::string path = "assets";

    if (this->actualBombs < this->bombNumber)
    {
        auto *cube = this->object->getSceneManager()->addCubeSceneNode(TILE_SIZE, nullptr, -1);
        cube->setPosition(this->object->getPosition());
        cube->setMaterialTexture(0, this->object->getSceneManager()->getVideoDriver()->getTexture(((path + DIRECTORYSEPARATOR + "tnt.jpg").c_str())));
        auto *bomb = new Bomb(this->getPosition(), this->getRotation(), this->map, this->bombPower, [this](Bomb *bomb){
            this->decreaseBombNumber(1);
            this->removeChild(bomb);
        }, cube);
        this->map.setAtCoord(this->getPosition(), BOMB);
        this->addChild(bomb);
        this->actualBombs += 1;
    }
}

void ind::Player::draw()
{
    irr::core::vector3df actualPosition = this->object->getPosition();
    const irr::core::vector3df futurePosition = this->correctMovement(actualPosition);
    Position futurePosition2d = to2d(futurePosition);

    this->object->setPosition(futurePosition);
    this->setPosition(futurePosition2d);
    this->force.X = 0;
    this->force.Y = 0;
}

ind::Player::Player(const Position &position, ind::ORIENTATION rotation, PlayerNumber playerNum, Board &map, irr::scene::IMeshSceneNode *object) :
    AbstractEntity(position, rotation, object), map(map)
{
    auto *behaviour = new PlayerBehaviour(*this, playerNum);
    this->setBehaviour(static_cast<IBehaviour *>(behaviour));
}

void ind::Player::decreaseBombNumber(short number)
{
    this->actualBombs -= number;
}

float ind::Player::getSpeed() const
{
    return this->movementSpeed;
}

irr::core::vector3df ind::Player::correctMovement(const irr::core::vector3df &actualPosition)
{
    irr::core::vector3df horizontalNextPos = irr::core::vector3df(actualPosition.X, actualPosition.Y, actualPosition.Z - this->force.X);
    irr::core::vector3df verticalNextPos = irr::core::vector3df(actualPosition.X - this->force.Y, actualPosition.Y, actualPosition.Z);
    irr::core::vector3df nextPos = irr::core::vector3df(actualPosition.X - this->force.Y, actualPosition.Y, actualPosition.Z - this->force.X);
    const bool horizontalWalkable = isWalkable(horizontalNextPos, {0, 0, this->force.X > 0 ? 1.0f : -1.0f});
    const bool verticalWalkable = isWalkable(verticalNextPos, {this->force.Y > 0 ? 1.0f : -1.0f, 0, 0});

    if (horizontalWalkable && verticalWalkable)
        return nextPos;
    if (horizontalWalkable)
        return horizontalNextPos;
    if (verticalWalkable)
        return verticalNextPos;
    return actualPosition;
}

const bool ind::Player::isWalkable(const irr::core::vector3df &position, const irr::core::vector3df &force)
{
    Position pos2d = to2d(position - force * (TILE_SIZE / 2));
    Position mapSize = this->map.getSize();

    if (position.X + TILE_SIZE / 2 >= mapSize.x * TILE_SIZE - TILE_SIZE / 2 || position.X < 0 ||
        position.Z + TILE_SIZE / 2.0f >= mapSize.y * TILE_SIZE - TILE_SIZE / 2 || position.Z < 0)
        return false;
    Tiles tile = this->map.getInfoAtCoord(pos2d);
    return (tile != BLOCKBREAKABLE && tile != BOMB);
}
