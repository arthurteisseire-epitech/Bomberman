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
    return this->map[coord.x][coord.y].first;
}

ind::Board::Board(Position size, irr::scene::ISceneManager *manager) : size(size), manager(manager)
{
    std::vector<std::pair<Tile, std::shared_ptr<BoardObject>>> tiles;

    for (int i = 0; i < size.x; ++i) {
        for (int j = 0; j < size.y; ++j) {
            auto first = (ind::Tile)((rand() % 2) + 1);
            if (first == BLOCKBREAKABLE) {
                auto *block = new BlockBreakable(manager, Position(i, j));
                std::pair<Tile, std::shared_ptr<BoardObject>> tmp(first, block);
                tiles.emplace_back(tmp);
            } else {
                auto *ground = new Ground(manager, Position(i, j));
                std::pair<Tile, std::shared_ptr<BoardObject>> tmp(first, ground);
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
    emptyTile(this->map[1][size.y - 1]);
    emptyTile(this->map[size.x - 1][size.y - 1]);
    emptyTile(this->map[size.x - 1][size.y - 2]);
    emptyTile(this->map[size.x - 2][size.y - 1]);
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

void ind::Board::setAtCoord(Position coord, ind::Tile tile)
{
    this->map[coord.x][coord.y].first = tile;
}

ind::Position ind::Board::getSize() const
{
    return this->size;
}

//void ind::Board::setEntityAtCoord(Position coord, ind::AbstractEntity *entity)
//{
//    this->map[coord.x][coord.y] = std::pair<Tile, std::unique_ptr<AbstractEntity>>
//        (this->map[coord.x][coord.y].first, entity);
//}

void ind::Board::emptyTile(std::pair<ind::Tile, std::shared_ptr<ind::BoardObject>> &tile)
{
    tile.first = EMPTY;

    auto *ground = new Ground(manager, tile.second->getPosition());
    std::pair<ind::Tile, std::shared_ptr<ind::BoardObject>> newTile(EMPTY, ground);
    tile = newTile;
}

void ind::Board::emptyTile(ind::Position position)
{
    return this->emptyTile(this->map[position.x][position.y]);
}
