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
                ind::Board &map, int power, std::function<void(Bomb *bomb)> onExplode,
                irr::scene::IMeshSceneNode *object) :
    AbstractEntity(position, rotation, object), map(map), power(power), onExplode(std::move(onExplode))
{
    auto *behaviour = new BombBehaviour(*this);
    setBehaviour(static_cast<IBehaviour *>(behaviour));
}

float ind::Bomb::getTime() const
{
    return timeBeforeExplosion;
}

void ind::Bomb::decreaseTime(float n)
{
    timeBeforeExplosion -= n;
}

void ind::Bomb::explode()
{
    const auto &pos = getPosition();

    map.setAtCoord(pos, EXPLOSION);
    explodeRow([pos](int i) { return Position(pos.x + i, pos.y); });
    explodeRow([pos](int i) { return Position(pos.x - i, pos.y); });
    explodeRow([pos](int i) { return Position(pos.x, pos.y + i); });
    explodeRow([pos](int i) { return Position(pos.x, pos.y - i); });
    onExplode(this);
}

bool ind::Bomb::explodeTile(const Position &pos)
{
    bool isEnd = false;

    if (inMap(pos)) {
        if (map.getInfoAtCoord(pos) == BLOCKBREAKABLE) {
            map.emptyTile(pos);
            isEnd = true;
            //TODO: put powerup ?
        }
        map.setAtCoord(pos, EXPLOSION);
    }
    return isEnd;
}

void ind::Bomb::draw()
{}

bool ind::Bomb::inMap(const Position &pos) const
{
    return pos.x >= 0 && pos.x < map.getSize().x && pos.y >= 0 && pos.y < map.getSize().y;
}
