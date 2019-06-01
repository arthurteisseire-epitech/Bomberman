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
    TimeoutObject(5),
    map(map),
    power(power),
    onExplode(std::move(onExplode))
{
    //createGraphicalCube();
    this->node = this->manager->addMeshSceneNode(this->manager->getMesh("assets/Bomb/exportbomb.obj"));
    this->node->setMaterialTexture(0, manager->getVideoDriver()->getTexture("assets/Bomb/diffusecolorretocado.jpg"));
    this->node->setRotation(irr::core::vector3df(0, 270, 0));
    node->setPosition(irr::core::vector3df(position.x * TILE_SIZE, 0, position.y * TILE_SIZE));
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
            if (rand() % 3 == 0)
                this->map.putPowerUp(pos);
        }
        if (map.getInfoAtCoord(pos) == EMPTY)
            map.explodeTile(pos);
        if (map.getInfoAtCoord(pos) == BOMB)
            this->toExplode.push_back(pos);
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

ind::Bomb::~Bomb()
{
}
