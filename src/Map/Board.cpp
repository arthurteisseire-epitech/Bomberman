/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <stdlib.h>
#include <iostream>
#include <irrlicht/irrlicht.h>
#include "BlockBreakable.hpp"
#include "Ground.hpp"
#include "Board.hpp"
#include "Position.hpp"

ind::Board::Board(Position size) : size(size)
{
    map.reserve(size.x);
    ground.reserve(size.x);
    for (int i = 0; i < size.x; ++i) {
        map.emplace_back();
        ground.emplace_back();
        map[i].reserve(size.y);
        ground[i].reserve(size.y);
        for (int j = 0; j < size.y; ++j) {
            auto first = static_cast<Tile>((rand() % 2) + 1);
            ground[i].emplace_back(new Ground(Position(i, j)));
            if (first == BLOCKBREAKABLE)
                map[i].emplace_back(new BlockBreakable(Position(i, j)));
            else
                map[i].emplace_back(nullptr);
        }
    }
    cleanCorners();
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

void ind::Board::emptyTile(std::unique_ptr<BoardObject> &tile)
{
    if (tile != nullptr)
        tile.reset(new Ground(tile->getPosition()));
}

void ind::Board::emptyTile(ind::Position position)
{
    return emptyTile(map[position.x][position.y]);
}
