/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <utility>
#include <iostream>
#include "Bomb.hpp"
#include "BombBehaviour.hpp"

ind::Bomb::Bomb(const ind::Position &position, ind::ORIENTATION rotation,
    ind::Board &map, int power, std::function<void(Bomb *bomb)> onExplode, irr::scene::IMeshSceneNode *object) :
    AbstractEntity(position, rotation, object), map(map), power(power), onExplode(std::move(onExplode))
{
    auto *behaviour = new BombBehaviour(*this);
    this->setBehaviour(static_cast<IBehaviour *>(behaviour));
}

float ind::Bomb::getTime() const
{
    return this->timeBeforeExplosion;
}

void ind::Bomb::decreaseTime(float n)
{
    this->timeBeforeExplosion -= n;
}

void ind::Bomb::explode()
{
    bool can_left = true;
    bool can_right = true;
    bool can_up = true;
    bool can_down = true;

    this->map.setAtCoord(std::pair<int, int>(this->getPosition().x, this->getPosition().y), EXPLOSION);
    for (int i = 1; i <= this->power; ++i) {
        if (static_cast<int>(this->getPosition().x) + i < this->map.getSize().first
        && this->map.getInfoAtCoord(std::pair<int, int>(this->getPosition().x + i, this->getPosition().y)) == BLOCKBREAKABLE && can_right) {
            this->map.setAtCoord(std::pair<int, int>(this->getPosition().x + i,
                this->getPosition().y), EXPLOSION);
            can_right = false;
            //TODO: put powerup ?
        } else if (static_cast<int>(this->getPosition().x) + i < this->map.getSize().first && can_right) {
            this->map.setAtCoord(std::pair<int, int>(this->getPosition().x + i,
                this->getPosition().y), EXPLOSION);
        }
        if (static_cast<int>(this->getPosition().x) - i > 0 && this->map.getInfoAtCoord(std::pair<int, int>(this->getPosition().x - i, this->getPosition().y)) == BLOCKBREAKABLE && can_left) {
            this->map.setAtCoord(std::pair<int, int>(this->getPosition().x - i,
                this->getPosition().y), EXPLOSION);
            can_left = false;
            //TODO: put powerup ?
        } else if (static_cast<int>(this->getPosition().x) - i > 0 && can_left) {
            this->map.setAtCoord(std::pair<int, int>(this->getPosition().x - i,
                this->getPosition().y), EXPLOSION);
        }
        if (static_cast<int>(this->getPosition().y) + i < this->map.getSize().second && this->map.getInfoAtCoord(std::pair<int, int>(this->getPosition().x, this->getPosition().y + i)) == BLOCKBREAKABLE && can_up) {
            this->map.setAtCoord(std::pair<int, int>(this->getPosition().x,
                this->getPosition().y + i), EXPLOSION);
            can_up = false;
            //TODO: put powerup ?
        } else if (static_cast<int>(this->getPosition().y) + i < this->map.getSize().second && can_up) {
            this->map.setAtCoord(std::pair<int, int>(this->getPosition().x,
                this->getPosition().y + i), EXPLOSION);
        }
        if (static_cast<int>(this->getPosition().y) - i > 0 && this->map.getInfoAtCoord(std::pair<int, int>(this->getPosition().x, this->getPosition().y - i)) == BLOCKBREAKABLE && can_down) {
            this->map.setAtCoord(std::pair<int, int>(this->getPosition().x,
                this->getPosition().y - i), EXPLOSION);
            can_down = false;
            //TODO: put powerup ?
        } else if (static_cast<int>(this->getPosition().y) - i > 0 && can_down) {
            this->map.setAtCoord(std::pair<int, int>(this->getPosition().x,
                this->getPosition().y - i), EXPLOSION);
        }
    }
    this->onExplode(this);
}

void ind::Bomb::draw()
{}
