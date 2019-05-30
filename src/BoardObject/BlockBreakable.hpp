/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** BlockBreakable.hpp
*/

#ifndef BOMBERMAN_BLOCKBREAKABLE_HPP
#define BOMBERMAN_BLOCKBREAKABLE_HPP

#include "BoardObject.hpp"

namespace ind {
    class BlockBreakable : public BoardObject {
    public:
        explicit BlockBreakable(Position position);

        Tile getTile() const override;
    };
}

#endif
