/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Explosion.hpp
*/

#ifndef BOMBERMAN_EXPLOSION_HPP
#define BOMBERMAN_EXPLOSION_HPP

#include "BoardObject.hpp"

namespace ind {
    class Explosion : public BoardObject {
    public:
        explicit Explosion(Position position);
        Tile getTile() const override;
    };
}

#endif
