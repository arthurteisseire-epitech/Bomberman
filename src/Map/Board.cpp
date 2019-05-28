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

ind::Board::Board(Position size, irr::scene::ISceneManager *manager) : size(size), manager(manager)
{
    BoardObject *obj;

    for (int i = 0; i < size.x; ++i) {
        map.emplace_back();
        for (int j = 0; j < size.y; ++j) {
            auto first = (ind::Tile)((rand() % 2) + 1);
            if (first == BLOCKBREAKABLE)
                obj = new BlockBreakable(manager, Position(i, j));
            else
                obj = new Ground(manager, Position(i, j));
            map[i].emplace_back(obj);
        }
    }
    std::cout << map.size() << std::endl;
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

    printMap();
}

ind::Tile ind::Board::getInfoAtCoord(Position coord) const
{
    return map[coord.x][coord.y]->getTile();
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
    tile.reset(new Ground(manager, tile->getPosition()));
}

void ind::Board::emptyTile(ind::Position position)
{
    return emptyTile(map[position.x][position.y]);
}
