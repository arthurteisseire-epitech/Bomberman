/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <stdlib.h>
#include <iostream>
#include <irrlicht/irrlicht.h>
#include <cstdlib>
#include "Bomb.hpp"
#include "BoardBehaviour.hpp"
#include "Explosion.hpp"
#include "BlockBreakable.hpp"
#include "Ground.hpp"
#include "BombUp.hpp"
#include "PowerUp.hpp"
#include "Board.hpp"
#include "Position.hpp"

ind::Board::Board(Position size) :
    AbstractEntity(),
    size(size)
{
    initGround();
    initBlocks();
    cleanCorners();
    setBehaviour(new BoardBehaviour(*this));
}

void ind::Board::initGround()
{
    ground.reserve(size.x);
    for (int i = 0; i < size.x; ++i) {
        ground.emplace_back();
        ground[i].reserve(size.y);
        for (int j = 0; j < size.y; ++j) {
            ground[i].emplace_back(new Ground(Position(i, j)));
        }
    }
}

void ind::Board::initBlocks()
{
    map.reserve(size.x);
    for (int i = 0; i < size.x; ++i) {
        map.emplace_back();
        map[i].reserve(size.y);
        for (int j = 0; j < size.y; ++j) {
            auto first = static_cast<ind::Tile>((rand() % 2) + 1);
            if (first == ind::BLOCKBREAKABLE)
                map[i].emplace_back(new ind::BlockBreakable(ind::Position(i, j)));
            else
                map[i].emplace_back(nullptr);
        }
    }
}

void ind::Board::cleanCorners()
{
    emptyTile(map[0][0]);
    emptyTile(map[1][0]);
    emptyTile(map[0][1]);
    emptyTile(map[0][size.y - 1]);
    emptyTile(map[0][size.y - 2]);
    emptyTile(map[1][size.y - 1]);
    emptyTile(map[size.x - 1][size.y - 1]);
    emptyTile(map[size.x - 1][size.y - 2]);
    emptyTile(map[size.x - 2][size.y - 1]);
    emptyTile(map[size.x - 1][0]);
    emptyTile(map[size.x - 2][0]);
    emptyTile(map[size.x - 1][1]);
}

ind::Tile ind::Board::getInfoAtCoord(Position coord) const
{
    auto &tile = map[coord.x][coord.y];

    if (tile == nullptr)
        return EMPTY;
    return tile->getTile();
}

void ind::Board::printMap() const
{
    for (auto &it : map) {
        for (const auto &it2: it) {
            if (it2->getTile() != EMPTY)
                std::cout << "o";
            else
                std::cout << "x";
        }
        std::cout << std::endl;
    }
}

ind::Position ind::Board::getSize() const
{
    return size;
}

void ind::Board::emptyTile(std::shared_ptr<BoardObject> &tile)
{
    tile = nullptr;
}

void ind::Board::emptyTile(ind::Position position)
{
    return emptyTile(map[position.x][position.y]);
}

void ind::Board::explodeTile(const ind::Position &position)
{
    auto explosion = new Explosion(position);

    map[position.x][position.y].reset(explosion);
    timeoutObjectManager.addObject(map[position.x][position.y], explosion);
    addChild(explosion);
}

void ind::Board::placeBomb(const ind::Position &position, int power, const std::function<void(Bomb *)> &f)
{
    auto bomb = new Bomb(position, *this, power, [this, f](Bomb *b) {
        f(b);
        removeChild(b);
    });

    map[position.x][position.y].reset(bomb);
    timeoutObjectManager.addObject(map[position.x][position.y], bomb);
    addChild(bomb);
}

void ind::Board::removeDeadObjects()
{
    auto deadObjects = timeoutObjectManager.popDeadObjects();
    for (auto &row : map)
        for (auto &tile : row)
            if (std::find(deadObjects.begin(), deadObjects.end(), tile) != deadObjects.end()) {
                std::cout << "remove child" << std::endl;
                removeChild(tile.get());
                std::cout << "remove tile" << std::endl;
                tile = nullptr;
            }
}

void ind::Board::putPowerUp(const ind::Position &position)
{
    std::shared_ptr<BombUp> powerUp = std::make_shared<BombUp>(position, "assets/bombUp.png");
    this->map[position.x][position.y] = powerUp;
}

ind::PowerUp *ind::Board::getPowerUp(
    const ind::Position &position
)
{
    auto *ptr = dynamic_cast<PowerUp *>(this->map[position.x][position.y].get());
    return ptr;
}
