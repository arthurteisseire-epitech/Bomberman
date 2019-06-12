/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <utility>
#include "Path.hpp"
#include "Bomb.hpp"
#include "BombBehaviour.hpp"
#include "Explosion.hpp"
#include "TimeoutObjectBehaviour.hpp"

ind::Bomb::Bomb(const ind::Position &position, ind::Board &map, int power, std::function<void(Bomb *bomb)> onExplode) :
    BoardObject(position, "assets/Bomb/diffusecolorretocado.jpg"),
    TimeoutObject(5),
    map(map),
    power(power),
    onExplode(std::move(onExplode))
{
    node = manager->addMeshSceneNode(manager->getMesh(Path::realpath("assets/Bomb/exportbomb.obj").c_str()));
    node->setMaterialTexture(0, texture);
    node->setRotation(irr::core::vector3df(0, 270, 0));
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

    if (map.in(pos)) {
        if (map.getInfoAtCoord(pos) == BLOCKBREAKABLE) {
            map.emptyTile(pos);
            isEnd = true;
            if (rand() % 3 == 0)
                map.putPowerUp(pos);
        }
        if (map.getInfoAtCoord(pos) == WALL) {
            isEnd = true;
        } else {
            map.explodeTile(pos);
        }
        if (map.getInfoAtCoord(pos) == BOMB)
            toExplode.push_back(pos);
    }
    return isEnd;
}

ind::Tile ind::Bomb::getTile() const
{
    return BOMB;
}

int ind::Bomb::getPower() const
{
    return power;
}

std::vector<ind::Position> ind::Bomb::getExplosionsPositions() const
{
    std::vector<Position> positions;
    std::vector<Position> row;
    const auto &pos = getPosition();

    positions.emplace_back(pos);
    row = getRowPositions([pos](int i) { return Position(pos.x + i, pos.y); });
    positions.insert(positions.end(), row.begin(), row.end());
    row = getRowPositions([pos](int i) { return Position(pos.x - i, pos.y); });
    positions.insert(positions.end(), row.begin(), row.end());
    row = getRowPositions([pos](int i) { return Position(pos.x, pos.y + i); });
    positions.insert(positions.end(), row.begin(), row.end());
    row = getRowPositions([pos](int i) { return Position(pos.x, pos.y - i); });
    positions.insert(positions.end(), row.begin(), row.end());
    return positions;
}

bool ind::Bomb::isExplosionStop(const ind::Position &pos) const
{
    return !map.in(pos) || map.getInfoAtCoord(pos) == BLOCKBREAKABLE || map.getInfoAtCoord(pos) == WALL;
}
