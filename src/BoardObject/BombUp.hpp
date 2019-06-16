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
        explicit BombUp(ind::Position position);
        ~BombUp() override = default;
        PowerType getType() const override;
        std::string toString() const override;
        void upgrade(Player &player) override;
    };
}
