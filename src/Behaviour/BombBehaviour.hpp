/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include "IBehaviour.hpp"
#include "Bomb.hpp"

namespace ind {

    class BombBehaviour : public IBehaviour {
        public:
            explicit BombBehaviour(Bomb &bomb);
            ~BombBehaviour() override = default;
            void update(float deltaTime) override;

        private:
            Bomb &bomb;
    };
}
