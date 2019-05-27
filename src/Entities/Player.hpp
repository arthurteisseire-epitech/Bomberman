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
            Player(const Position &position, ORIENTATION rotation, PlayerNumber playerNum, Board &map, irr::scene::IMeshSceneNode *object);
            ~Player() override = default;
            void draw() override;
            void placeBomb();
            void decreaseBombNumber(short number);
            float getSpeed() const;
        private:
            short actualBombs = 0;
            short bombPower = 5;
            short bombNumber = 1;
            float movementSpeed = 30.0f;
            Board &map;

            irr::core::vector3df correctMovement(const irr::core::vector3df &actualPosition);
            const bool isWalkable(const irr::core::vector3df &position, const irr::core::vector3df &force);
    };
}
