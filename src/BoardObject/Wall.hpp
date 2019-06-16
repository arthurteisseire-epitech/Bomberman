/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Wall.hpp
*/

#ifndef BOMBERMAN_WALL_HPP
#define BOMBERMAN_WALL_HPP

#include "BoardObject.hpp"

namespace ind {
    class Wall : public BoardObject {
    public:
        explicit Wall(Position position);

        Tile getTile() const override;
        virtual std::string toString() const override;
    };
}

#endif
