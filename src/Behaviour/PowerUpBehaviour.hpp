/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include "IBehaviour.hpp"
#include "PowerUp.hpp"

namespace ind {

    class PowerUpBehaviour : public IBehaviour {
        public:
            explicit PowerUpBehaviour(PowerUp &powerUp);
            ~PowerUpBehaviour() override = default;
            void update(float deltaTime) override;

        private:
            PowerUp &powerUp;
    };
}
