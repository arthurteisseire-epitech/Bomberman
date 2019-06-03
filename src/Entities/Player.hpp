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
        Player(const Position &position, Board &map, animations::Animator *animator);
        ~Player() override;
        void draw();
        void placeBomb();
        void decreaseBombNumber(short number);
        float getSpeed() const;
        short getBombNumber() const;
        void setBombNumber(short);
        animations::Animator &getAnimator();
        void setAnimator(animations::Animator *animator);
        bool isAlive() const;
        const Actions getAction();
        void setAction(Actions action);
        const ORIENTATION getDirection();
        void setDirection(ORIENTATION direction);
        void applySettings(const PlayerSettings &settings);
        void checkDeath();

    private:
        short bombPower;
        short maxBombsPlaced;
        float movementSpeed;
        short actualBombsPlaced = 0;
        Position boardPosition;
        Board &map;
        bool alive;
        Actions _action = Actions::Idle;
        ORIENTATION _direction = ORIENTATION::NONE;
        animations::Animator *_animator;

        irr::core::vector3df correctMovement(const irr::core::vector3df &actualPosition);
        const bool isWalkable(const irr::core::vector3df &pos, const irr::core::vector3df &direction);
        bool checkWalkableTile(const Tile &Tile) const;
    };
}