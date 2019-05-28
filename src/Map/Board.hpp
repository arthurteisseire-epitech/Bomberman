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
            void setAtCoord(Position coord, Tile tile);
//            void setEntityAtCoord(Position coord, AbstractEntity *entity);
            void printMap() const;
            Position getSize() const;
            void emptyTile(std::pair<ind::Tile, std::shared_ptr<ind::BoardObject>> &tile);
            void emptyTile(Position position);

        private:
            std::vector<std::vector<std::pair<ind::Tile, std::shared_ptr<ind::BoardObject>>>> map;
            Position size;
            irr::scene::ISceneManager *manager = nullptr;
    };
}
