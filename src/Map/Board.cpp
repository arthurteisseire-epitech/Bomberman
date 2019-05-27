/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <stdlib.h>
#include <iostream>
#include <irrlicht/irrlicht.h>
#include <Entities/BlockBreakable.hpp>
#include "Board.hpp"
#include "Ground.hpp"
#include "Position.hpp"

ind::Tiles ind::Board::getInfoAtCoord(Position coord) const
{
    return this->map[coord.x][coord.y].first;
}

ind::Board::Board(Position size, irr::scene::ISceneManager *manager) : size(size), manager(manager)
{
    std::vector<std::pair<Tiles, std::shared_ptr<AbstractEntity>>> tiles;

    for (int i = 0; i < size.x; ++i)
    {
        for (int j = 0; j < size.y; ++j)
        {
            auto first = (ind::Tiles )((rand() % 2) + 1);
            if (first == BLOCKBREAKABLE) {
                auto *cube = this->manager->addCubeSceneNode(TILE_SIZE, NULL, -1);
                cube->setPosition(irr::core::vector3df(i * TILE_SIZE , 0, j * TILE_SIZE));
                cube->setMaterialTexture(0, cube->getSceneManager()->getVideoDriver()->getTexture("assets/wood.png"));
                auto *block = new BlockBreakable(Position(i, j), NONE, cube, *this);
                std::pair<Tiles, std::shared_ptr<AbstractEntity>> tmp(first, block);
                tiles.emplace_back(tmp);
            } else {
                auto *cube = this->manager->addCubeSceneNode(TILE_SIZE, NULL, -1);
                cube->setPosition(irr::core::vector3df(i * TILE_SIZE , -TILE_SIZE, j * TILE_SIZE));
                std::cout << "position : X : " << size.x * TILE_SIZE << " Y : " << size.y * TILE_SIZE << std::endl;
                cube->setMaterialTexture(0, cube->getSceneManager()->getVideoDriver()->getTexture("assets/stone.png"));

                auto *ground = new Ground(Position(i, j), NONE, cube);
                std::pair<Tiles, std::shared_ptr<AbstractEntity>> tmp(first, ground);
                tiles.emplace_back(tmp);
            }
        }
        this->map.emplace_back(tiles);
        tiles.clear();
    }
    std::cout << this->map.size() << std::endl;
    emptyTile(this->map[0][0]);
    emptyTile(this->map[1][0]);
    emptyTile(this->map[0][1]);
    emptyTile(this->map[0][size.y - 1]);
    emptyTile(this->map[0][size.y - 2]);
    emptyTile(this->map[1][size.y -1]);
    emptyTile(this->map[size.x - 1][size.y -1]);
    emptyTile(this->map[size.x - 1][size.y - 2]);
    emptyTile(this->map[size.x - 2][size.y -1]);
    emptyTile(this->map[size.x - 1][0]);
    emptyTile(this->map[size.x - 2][0]);
    emptyTile(this->map[size.x - 1][1]);

    this->printMap();
}

void ind::Board::printMap() const
{
    for (auto &it : this->map) {
        for (const auto &it2: it) {
            if (it2.first == EMPTY)
                std::cout << "o";
            else
                std::cout << "x";
        }
        std::cout << std::endl;
    }
}

void ind::Board::setAtCoord(Position coord, ind::Tiles tile)
{
    this->map[coord.x][coord.y].first = tile;
}

ind::Position ind::Board::getSize() const
{
    return this->size;
}

void ind::Board::setEntityAtCoord(Position coord,
    ind::AbstractEntity *entity
)
{
    this->map[coord.x][coord.y] =
        std::pair<Tiles, std::unique_ptr<AbstractEntity>>
        (this->map[coord.x][coord.y].first, entity);
}

void ind::Board::emptyTile(std::pair<ind::Tiles, std::shared_ptr<ind::AbstractEntity>> &tile)
{
    irr::core::vector3df pos = tile.second->getObject()->getPosition();
    tile.first = EMPTY;
    auto *cube = tile.second->getObject()->getSceneManager()->addCubeSceneNode();
    cube->setMaterialTexture(0, tile.second->getObject()->getSceneManager()->getVideoDriver()->getTexture("assets/stone.png"));
    cube->setPosition(irr::core::vector3df(pos.X, -TILE_SIZE, pos.Z));

    auto *ground = new Ground(tile.second->getPosition(), NONE, cube);
    std::pair<ind::Tiles, std::shared_ptr<ind::AbstractEntity>> newTile(EMPTY, ground);
    tile = newTile;
}

void ind::Board::emptyTile(ind::Position position)
{
    return this->emptyTile(this->map[position.x][position.y]);
}
