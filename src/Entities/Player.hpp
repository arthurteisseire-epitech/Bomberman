/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <vector>
#include "Animator.hpp"
#include "PlayersSettingsSave.hpp"
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
        Walking,
        Idle,
        Up,
        Down,
        Left,
        Right,
        Unknown
    };

    class Player : public AbstractEntity {
        public:
            Player(const Position &position, PlayerNumber playerNum, Board &map);
            ~Player() override = default;
            void draw();
            void placeBomb();
            void decreaseBombNumber(short number);
            float getSpeed() const;
            short getBombNumber() const;
            void setBombNumber(short);
            ind::animations::Animator &getAnimator();
            bool isAlive() const;
            const Actions getAction();
            void setAction(Actions action);
            const ind::ORIENTATION getDirection();
            void setDirection(ind::ORIENTATION direction);
            void applySettings(const PlayerSettings &settings);

        private:
            short actualBombs = 0;
            short bombPower = 5;
            short bombsPlacedMax = 1;
            short maxBombs = 10;
            float movementSpeed = 30.0f;
            Position boardPosition;
            Board &map;
            bool alive;
            irr::core::vector3df correctMovement(const irr::core::vector3df &actualPosition);
            const bool isWalkable(const irr::core::vector3df &pos, const irr::core::vector3df &direction);
            bool checkWalkableTile(const ind::Tile &Tile) const;

        private:
            Actions _action = Actions::Idle;
            ind::ORIENTATION _direction = ind::ORIENTATION::NONE;
            ind::animations::Animator _animator;
    };
}
