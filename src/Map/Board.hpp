/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <vector>
#include <utility>
#include "AbstractEntity.hpp"
#include "BoardObject.hpp"
#include "Ground.hpp"
#include "Tile.hpp"

namespace ind {
    class Board {
    public:
        explicit Board(Position size);
        ~Board() = default;
        Tile getInfoAtCoord(Position coord) const;
        void printMap() const;
        Position getSize() const;
        void emptyTile(std::unique_ptr<BoardObject> &tile);
        void emptyTile(Position position);
        void cleanCorners();
        void initGround();
        void initBlocks();

    private:
        std::vector<std::vector<std::unique_ptr<Ground>>> ground;
        std::vector<std::vector<std::unique_ptr<BoardObject>>> map;
        Position size;
    };
}
