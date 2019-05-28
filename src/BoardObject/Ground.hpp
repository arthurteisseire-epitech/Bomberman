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
        Ground(irr::scene::ISceneManager *mgr, Position position, int height = -1);

        Tile getTile() const override;
    };
}

#endif
