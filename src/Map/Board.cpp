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

ind::Tile ind::Board::getInfoAtCoord(Position coord) const
{
    return map[coord.x][coord.y]->getTile();
}

ind::Board::Board(Position size, irr::scene::ISceneManager *manager) : size(size), manager(manager)
{
    std::vector<std::shared_ptr<BoardObject>> tiles;

    for (int i = 0; i < size.x; ++i) {
        for (int j = 0; j < size.y; ++j) {
            auto first = (ind::Tile)((rand() % 2) + 1);
            if (first == BLOCKBREAKABLE) {
                auto *block = new BlockBreakable(manager, Position(i, j));
                tiles.emplace_back(block);
            } else {
                auto *ground = new Ground(manager, Position(i, j));
                tiles.emplace_back(ground);
            }
        }
        map.emplace_back(tiles);
        tiles.clear();
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

//void ind::Board::setEntityAtCoord(Position coord, ind::AbstractEntity *entity)
//{
//    map[coord.x][coord.y] = std::pair<Tile, std::unique_ptr<AbstractEntity>>
//        (map[coord.x][coord.y].first, entity);
//}

void ind::Board::emptyTile(std::shared_ptr<ind::BoardObject> &tile)
{
    tile = std::shared_ptr<BoardObject>(new Ground(manager, tile->getPosition()));
}

void ind::Board::emptyTile(ind::Position position)
{
    return emptyTile(map[position.x][position.y]);
}
