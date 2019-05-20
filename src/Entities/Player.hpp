/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include "IEntity.hpp"
#include "Orientation.hpp"

namespace ind {

    class Player : public IEntity {
        public:
            explicit Player(std::pair<float, float> position);
            ~Player() override = default;
            void draw() override;
            void update(float deltaTime) override;
            void move(ORIENTATION direction);
            void placeBomb();
            bool isMoving();
            std::pair<float, float> getPosition();
            ORIENTATION getDirection();
        private:
            float timeBeforeStop = -1.0f;
            bool moving = false;
            ORIENTATION direction = NONE;
    };
}
