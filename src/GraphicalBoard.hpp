/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** GraphicalBoard.hpp
*/

#ifndef BOMBERMAN_GRAPHICALBOARD_HPP
#define BOMBERMAN_GRAPHICALBOARD_HPP

#include <vector>
#include "Size.hpp"
#include "Board.hpp"

namespace ind {
    class GraphicalBoard {
    public:
        explicit GraphicalBoard(Size size) : size(size)
        {}

        template<typename Func>
        void create(Func f)
        {
            for (size_t y = 0; y < size.height; ++y) {
                cells.emplace_back();
                for (size_t x = 0; x < size.width; ++x) {
                    cells[y].emplace_back(f());
                    cells[y][x]->setPosition(irr::core::vector3df(
                        x * (abs(cells[y][x]->getBoundingBox().MinEdge.X) + abs(cells[y][x]->getBoundingBox().MaxEdge.X + 5)),
                        0,
                        y * (abs(cells[y][x]->getBoundingBox().MinEdge.Y) + abs(cells[y][x]->getBoundingBox().MaxEdge.Y + 5))));
                }
            }
        }

    private:
        std::vector<std::vector<irr::scene::ISceneNode *>> cells;
        Size size;
    };
}

#endif
