/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** FireUp.hpp
*/

#ifndef BOMBERMAN_FIREUP_HPP
#define BOMBERMAN_FIREUP_HPP

#include "PowerUp.hpp"

namespace ind {
    class FireUp : public PowerUp {
    public:
        explicit FireUp(Position position);
        ~FireUp() override = default;
        PowerType getType() const override;
        std::string toString() const override;
        void upgrade(Player &player) override;
    };
}

#endif
