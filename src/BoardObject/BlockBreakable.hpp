/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** OldBlockBreakable.hpp
*/

#ifndef BOMBERMAN_BLOCKBREAKABLE_HPP
#define BOMBERMAN_BLOCKBREAKABLE_HPP

#include "BoardObject.hpp"

namespace ind {
    class BlockBreakable : public BoardObject {
    public:
        BlockBreakable(irr::scene::ISceneManager *mgr, Position position, int height = 0);

        Tile getTile() const override;
    };
}

#endif
