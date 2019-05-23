/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <vector>
#include "AbstractEntity.hpp"
#include "Bomb.hpp"
#include "Orientation.hpp"

namespace ind {

    enum PlayerNumber {
        PLAYER_ONE,
        PLAYER_TWO,
    };

    enum Actions {
        PlaceBomb,
        Up,
        Down,
        Left,
        Right,
    };

    class Player : public AbstractEntity {
        public:
            Player(const Position &position, ORIENTATION rotation, PlayerNumber playerNum, Map &map);
            ~Player() override = default;
            void draw() override;
            void update(float deltaTime) override;
            void move(ORIENTATION direction);
            void placeBomb();
            void decreaseBombNumber(short number);
        private:
            short actualBombs = 0;
            short bombPower = 1;
            short bombNumber = 1;
            float movementSpeed = 1.0f;
            Map &map;
    };
}
