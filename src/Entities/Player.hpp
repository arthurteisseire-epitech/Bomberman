/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include "AbstractEntity.hpp"
#include "Orientation.hpp"

namespace ind {

    class Player : public AbstractEntity {
        public:
            Player(std::pair<float, float> position, ORIENTATION rotation, IBehaviour &behaviour);
            ~Player() override = default;
            void draw() override;
            void update(float deltaTime) override;
            void move(std::pair<float, float>);
            void placeBomb();
            bool isMoving() const;
        private:
            float timeBeforeStop = -1.0f;
            bool moving = false;
            short bombPower = 1;
            short bombNumber = 1;
            float movementSpeed = 1.0f;
    };
}
