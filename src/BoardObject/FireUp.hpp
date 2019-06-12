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
        FireUp(Position position, const irr::io::path &path);
        ~FireUp() override = default;
        void upgrade(Player &player) override;
    };
}

#endif
