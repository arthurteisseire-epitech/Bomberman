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

ind::Tiles ind::Board::getInfoAtCoord(std::pair<int, int> coord) const
{
    std::cout << "trying to get info at : X " << coord.first << " Y :" << coord.second << std::endl;
    return this->map[coord.first][coord.second].first;
}

ind::Board::Board(std::pair<int, int> size, irr::scene::ISceneManager *manager) : manager(manager)
{
    std::vector<std::pair<Tiles, std::shared_ptr<AbstractEntity>>> tiles;

    for (int i = 0; i < size.first; ++i)
    {
        for (int j = 0; j < size.second; ++j)
        {

            auto first = (ind::Tiles )((rand() % 2) + 1);
            if (first == BLOCKBREAKABLE) {
                auto *cube = this->manager->addCubeSceneNode(10.0f, NULL, -1);
                cube->setPosition(irr::core::vector3df(i * 10.0f , 0, j * 10.0f));
                cube->setMaterialTexture(0, cube->getSceneManager()->getVideoDriver()->getTexture("assets/wood.png"));
                auto *block = new BlockBreakable(Position(i, j), NONE, cube, *this);
                std::pair<Tiles, std::shared_ptr<AbstractEntity>> tmp(first, block);
                tiles.emplace_back(tmp);
            } else {
                auto *cube = this->manager->addCubeSceneNode(10.0f, NULL, -1);
                cube->setPosition(irr::core::vector3df(i * 10.0f , -10.0f, j * 10.0f));
                std::cout << "position : X : " << size.first * 10.0f << " Y : " << size.second * 10.0f << std::endl;
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
    emptyTile(this->map[0][size.second -1]);
    emptyTile(this->map[0][size.second - 2]);
    emptyTile(this->map[1][size.second -1]);
    emptyTile(this->map[size.first - 1][size.second -1]);
    emptyTile(this->map[size.first - 1][size.second - 2]);
    emptyTile(this->map[size.first - 2][size.second -1]);
    emptyTile(this->map[size.first - 1][0]);
    emptyTile(this->map[size.first - 2][0]);
    emptyTile(this->map[size.first - 1][1]);

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

void ind::Board::setAtCoord(std::pair<int, int> coord, ind::Tiles tile)
{
    this->map[coord.first][coord.second].first = tile;
}

std::pair<int, int> ind::Board::getSize() const
{
    return this->size;
}

void ind::Board::setEntityAtCoord(std::pair<int, int> coord,
    ind::AbstractEntity *entity
)
{
    this->map[coord.first][coord.second] =
        std::pair<Tiles, std::unique_ptr<AbstractEntity>>
        (this->map[coord.first][coord.second].first, entity);
}

void ind::Board::emptyTile(std::pair<ind::Tiles, std::shared_ptr<ind::AbstractEntity>> &tile)
{
    irr::core::vector3df pos = tile.second->getObject()->getPosition();
    tile.first = EMPTY;
    auto *cube = tile.second->getObject()->getSceneManager()->addCubeSceneNode();
    cube->setMaterialTexture(0, tile.second->getObject()->getSceneManager()->getVideoDriver()->getTexture("assets/stone.png"));
    cube->setPosition(irr::core::vector3df(pos.X, -10.0f, pos.Z));
    tile.second->getObject()->remove();

    auto *ground = new Ground(tile.second->getPosition(), NONE, cube);
    std::pair<ind::Tiles, std::shared_ptr<ind::AbstractEntity>> newTile(EMPTY, ground);
    tile = newTile;
}
