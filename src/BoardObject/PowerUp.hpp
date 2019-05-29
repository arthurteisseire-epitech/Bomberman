/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include "BoardObject.hpp"
#include "Player.hpp"

namespace ind {
    class PowerUp : public BoardObject {
        public:
            PowerUp(Position position, const irr::io::path &path);
            ~PowerUp() override = default;
            virtual void upgrade(Player &player) = 0;
            Tile getTile() const override;
    };
}
