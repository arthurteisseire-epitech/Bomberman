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
            Player(const Position &position, PlayerNumber playerNum, Board &map, irr::scene::IMeshSceneNode *object);
            ~Player() override;
            void draw();
            void placeBomb();
            void decreaseBombNumber(short number);
            float getSpeed() const;
            short getBombNumber() const;
            void setBombNumber(short);
            bool isAlive() const;
        private:
            short actualBombs = 0;
            short bombPower = 5;
            short _bombNumber = 1;
            float movementSpeed = 30.0f;
            Position boardPosition;
            Board &map;
            irr::scene::IMeshSceneNode *object;
            bool alive;

            irr::core::vector3df correctMovement(const irr::core::vector3df &actualPosition);
            const bool isWalkable(const irr::core::vector3df &pos, const irr::core::vector3df &direction);
            bool checkWalkableTile(const ind::Tile &Tile) const;
    };
}
