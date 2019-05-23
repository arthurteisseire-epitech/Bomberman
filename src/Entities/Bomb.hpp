/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include "AbstractEntity.hpp"
#include "Map.hpp"

namespace ind {

    class Bomb : public AbstractEntity {

        public:
            Bomb(const Position &position, ORIENTATION rotation, Map &map, int power);
            ~Bomb() = default;

        private:
            Map &map;
            int power;
            float timeBeforeExplosion = 1.0f;
    };

}
