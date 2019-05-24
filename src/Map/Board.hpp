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
#include "Tiles.hpp"

namespace ind {
    class Board {
        public:
            explicit Board(Position size, irr::scene::ISceneManager *manager);
            ~Board() = default;
            Tiles getInfoAtCoord(Position coord) const;
            void setAtCoord(Position coord, Tiles tile);
            void setEntityAtCoord(Position coord, AbstractEntity *entity);
            void printMap() const;
            Position getSize() const;
            void emptyTile(std::pair<ind::Tiles, std::shared_ptr<ind::AbstractEntity>> &tile);
            void emptyTile(Position position);

        private:
            std::vector<std::vector<std::pair<ind::Tiles, std::shared_ptr<ind::AbstractEntity>>>> map;
            Position size;
            irr::scene::ISceneManager *manager = nullptr;
    };
}
