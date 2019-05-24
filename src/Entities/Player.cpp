/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <iostream>
#include <crossPlatform.hpp>
#include "Player.hpp"
#include "PlayerBehaviour.hpp"

void ind::Player::placeBomb()
{
    std::string path = "assets";

    if (this->actualBombs < this->bombNumber)
    {
        auto *cube = this->object->getSceneManager()->addCubeSceneNode(10.0f, nullptr, -1);
        cube->setPosition(this->object->getPosition());
        cube->setMaterialTexture(0, this->object->getSceneManager()->getVideoDriver()->getTexture(((path + DIRECTORYSEPARATOR + "tnt.jpg").c_str())));
        auto *bomb = new Bomb(this->getPosition(), this->getRotation(), this->map, this->bombPower, [this](Bomb *bomb){
            this->decreaseBombNumber(1);
            this->removeChild(bomb);
        }, cube);
        this->map.setAtCoord(std::pair<int, int>(this->getPosition().x, this->getPosition().y), BOMB);
        this->addChild(bomb);
        this->actualBombs += 1;
    }
}

void ind::Player::draw()
{
    std::cout << "Bomb numbers :" << this->actualBombs << std::endl;
    std::cout << "Elem numbers :" << this->children.size() << std::endl;
    this->object->setPosition(irr::core::vector3df(this->object->getPosition().X - this->force.Y, this->object->getPosition().Y, this->object->getPosition().Z - this->force.X));
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
