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
#include "Tile.hpp"

namespace ind {
    class Board {
    public:
        explicit Board(Position size, irr::scene::ISceneManager *manager);
        ~Board() = default;
        Tile getInfoAtCoord(Position coord) const;
        void printMap() const;
        Position getSize() const;
        void emptyTile(std::unique_ptr<BoardObject> &tile);
        void emptyTile(Position position);
        void cleanCorners();

    private:
        std::vector<std::vector<std::unique_ptr<BoardObject>>> map;
        Position size;
        irr::scene::ISceneManager *manager = nullptr;
    };
}
