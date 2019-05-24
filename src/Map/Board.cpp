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
                cube->setPosition(irr::core::vector3df(size.first * 10.0f , 0, size.second * 10.0f));

                auto *block = new BlockBreakable(Position(size.first, size.second), NONE, cube, *this);
                std::pair<Tiles, std::shared_ptr<AbstractEntity>> tmp(first, block);
                tiles.emplace_back(tmp);
            } else {
                auto *cube = this->manager->addCubeSceneNode(10.0f, NULL, -1);
                cube->setPosition(irr::core::vector3df(size.first * 10.0f , 0, size.second * 10.0f));

                auto *ground = new Ground(Position(size.first, size.second), NONE, cube);
                std::pair<Tiles, std::shared_ptr<AbstractEntity>> tmp(first, ground);
                tiles.emplace_back(tmp);
            }
        }
        this->map.emplace_back(tiles);
        tiles.clear();
    }
    std::cout << this->map.size() << std::endl;
    this->map[0][0].first = EMPTY;
    this->map[1][0].first = EMPTY;
    this->map[0][1].first = EMPTY;
    this->map[0][size.second -1].first = EMPTY;
    this->map[0][size.second - 2].first = EMPTY;
    this->map[1][size.second -1].first = EMPTY;
    this->map[size.first - 1][size.second -1].first = EMPTY;
    this->map[size.first - 1][size.second - 2].first = EMPTY;
    this->map[size.first - 2][size.second -1].first = EMPTY;
    this->map[size.first - 1][0].first = EMPTY;
    this->map[size.first - 2][0].first = EMPTY;
    this->map[size.first - 1][1].first = EMPTY;

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
