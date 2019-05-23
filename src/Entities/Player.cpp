/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "Player.hpp"
#include "PlayerBehaviour.hpp"

void ind::Player::placeBomb()
{
    if (this->actualBombs < this->bombNumber)
    {
        auto *bomb = new Bomb(this->getPosition(), this->getRotation(), this->map, this->bombPower, [this](Bomb *bomb){
            this->decreaseBombNumber(1);
            this->removeChild(bomb);
        });
        this->map.setAtCoord(std::pair<int, int>(this->getPosition().x, this->getPosition().y), BOMB);
        this->addChild(bomb);
        this->actualBombs += 1;
    }
}

void ind::Player::update(float deltaTime)
{}

void ind::Player::draw()
{
}

ind::Player::Player(const Position &position, ind::ORIENTATION rotation, PlayerNumber playerNum, Map &map) :
    AbstractEntity(position, rotation), map(map)
{
    auto *behaviour = new PlayerBehaviour(*this, playerNum);
    this->setBehaviour(static_cast<IBehaviour *>(behaviour));
}

void ind::Player::move(ind::ORIENTATION direction)
{
    this->rotation = direction;
}

void ind::Player::decreaseBombNumber(short number)
{
    this->actualBombs -= number;
}
