/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include "PowerUp.hpp"

namespace ind {
    class BombUp : public PowerUp {
        public:
            BombUp(Position position, const irr::io::path &path);
            ~BombUp() override = default;
            void upgrade(Player &player) override;
    };
}
