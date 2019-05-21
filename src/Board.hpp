/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Board.hpp
*/

#ifndef BOMBERMAN_BOARD_HPP
#define BOMBERMAN_BOARD_HPP

#include <vector>

namespace ind {
    struct Size {
        Size(size_t width, size_t height) : width(width), height(height)
        {}

        size_t width;
        size_t height;
    };

    class Board {
    public:
        explicit Board(Size size) : size(size)
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