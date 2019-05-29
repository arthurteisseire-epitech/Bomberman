/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Ground.hpp
*/

#ifndef BOMBERMAN_GROUND_HPP
#define BOMBERMAN_GROUND_HPP

#include "BoardObject.hpp"

namespace ind {
    class Ground : public BoardObject {
    public:
        explicit Ground(Position position);

        Tile getTile() const override;
    };
}

#endif
