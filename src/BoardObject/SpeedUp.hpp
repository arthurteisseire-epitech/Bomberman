/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** SpeedUp.hpp
*/

#ifndef BOMBERMAN_SPEEDUP_HPP
#define BOMBERMAN_SPEEDUP_HPP

#include "PowerUp.hpp"

namespace ind {
    class SpeedUp : public PowerUp {
    public:
        SpeedUp(Position position, const irr::io::path &path);
        ~SpeedUp() override = default;
        void upgrade(Player &player) override;
    };
}

#endif
