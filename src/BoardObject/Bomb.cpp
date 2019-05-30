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
#include "Explosion.hpp"
#include "TimeoutObjectBehaviour.hpp"

ind::Bomb::Bomb(const ind::Position &position, ind::Board &map, int power, std::function<void(Bomb *bomb)> onExplode) :
    BoardObject(position, "assets/tnt.jpg"),
    TimeoutObject(1),
    map(map),
    power(power),
    onExplode(std::move(onExplode))
{
    createGraphicalCube();
    setBehaviour(new BombBehaviour(*this));
}

void ind::Bomb::explode()
{
    const auto &pos = getPosition();

    map.explodeTile(pos);
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
        map.explodeTile(pos);
    }
    return isEnd;
}

bool ind::Bomb::inMap(const Position &pos) const
{
    return pos.x >= 0 && pos.x < map.getSize().x && pos.y >= 0 && pos.y < map.getSize().y;
}

ind::Tile ind::Bomb::getTile() const
{
    return BOMB;
}
