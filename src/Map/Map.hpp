/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <vector>
#include "Tiles.hpp"

namespace ind {
    class Map {
        public:
            explicit Map(std::pair<int, int> size);
            ~Map() = default;
            Tiles getInfoAtCoord(std::pair<int, int> coord) const;
            void printMap() const;

        private:
            std::vector<std::vector<ind::Tiles>> map;
            std::pair<int, int> size;
    };
}
