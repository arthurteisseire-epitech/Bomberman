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
        AI
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
        bool isAlive() const;
        const Actions getAction();
        void setAction(Actions action);
        const Orientation getDirection();
        void setDirection(Orientation direction);
        void applySettings(const PlayerSettings &settings);
        void checkDeath();
        const Position &getPosition() const;
        irr::core::vector3df nextPos();
        void fireUp();
        void speedUp();
        void enableWallPass();

        private:
        short bombPower;
        short maxBombsPlaced;
        float movementSpeed;
        short actualBombsPlaced = 0;
        bool wallPass;
        Position boardPosition;
        Board &map;
        bool alive;
        Actions _action = Actions::Idle;
        Orientation _direction = Orientation::NONE;
        animations::Animator *_animator;

        const bool isWalkable(const irr::core::vector3df &pos, const irr::core::vector3df &direction);
        bool checkWalkableTile(const Tile &Tile) const;
    };
}