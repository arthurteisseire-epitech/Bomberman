/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** WallPass.hpp
*/

#ifndef BOMBERMAN_WALLPASS_HPP
#define BOMBERMAN_WALLPASS_HPP

#include "PowerUp.hpp"

namespace ind {
    class WallPass : public PowerUp {
    public:
        explicit WallPass(ind::Position position);
        ~WallPass() override = default;
        PowerType getType() const override;
        std::string toString() const override;
        void upgrade(Player &player) override;
    };
}

#endif
