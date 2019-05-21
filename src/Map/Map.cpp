/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <stdlib.h>
#include <iostream>
#include "Map.hpp"

ind::Tiles ind::Map::getInfoAtCoord(std::pair<int, int> coord) const
{
    return this->map[coord.first][coord.second];
}

ind::Map::Map(std::pair<int, int> size)
{
    std::vector<Tiles> tiles(size.second);

    for (int i = 0; i < size.first; ++i)
    {
        for (int j = 0; j < size.second; ++j)
        {
            tiles[j] = (ind::Tiles )((rand() % 2) + 1);
        }
        this->map.push_back(tiles);
    }
    std::cout << this->map.size() << std::endl;
    this->map[0][0] = NONE;
    this->map[1][0] = NONE;
    this->map[0][1] = NONE;
    this->map[0][size.second -1] = NONE;
    this->map[0][size.second - 2] = NONE;
    this->map[1][size.second -1] = NONE;
    this->map[size.first - 1][size.second -1] = NONE;
    this->map[size.first - 1][size.second - 2] = NONE;
    this->map[size.first - 2][size.second -1] = NONE;
    this->map[size.first - 1][0] = NONE;
    this->map[size.first - 2][0] = NONE;
    this->map[size.first - 1][1] = NONE;

    this->printMap();
}

void ind::Map::printMap() const
{
    for (auto &it : this->map) {
        for (const auto &it2: it) {
            if (it2 == NONE)
                std::cout << "o";
            else
                std::cout << "x";
        }
        std::cout << std::endl;
    }
}
