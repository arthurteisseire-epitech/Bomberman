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
            explicit Board(std::pair<int, int> size, irr::scene::ISceneManager *manager);
            ~Board() = default;
            Tiles getInfoAtCoord(std::pair<int, int> coord) const;
            void setAtCoord(std::pair<int, int> coord, Tiles tile);
            void setEntityAtCoord(std::pair<int, int> coord, AbstractEntity *entity);
            void printMap() const;
            std::pair<int, int> getSize() const;

        private:
            std::vector<std::vector<std::pair<ind::Tiles, std::shared_ptr<ind::AbstractEntity>>>> map;
            std::pair<int, int> size;
            irr::scene::ISceneManager *manager = nullptr;
    };
}
