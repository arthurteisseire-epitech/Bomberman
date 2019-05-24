/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <Map/Board.hpp>
#include "AbstractEntity.hpp"

namespace ind {

    class BlockBreakable : public AbstractEntity {
        public:
            BlockBreakable(const Position &boardPosition, ORIENTATION rotation, irr::scene::IMeshSceneNode *object, Board &map);
            ~BlockBreakable() override = default;
            void draw() override;
            void breakBlock();

        private:
            Board &board;
    };
}
