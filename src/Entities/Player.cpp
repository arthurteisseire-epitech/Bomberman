/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "Player.hpp"

void ind::Player::placeBomb()
{
}

ind::Player::Player(std::pair<float, float> position)
{
    this->position = position;
}

void ind::Player::move(ind::ORIENTATION direction)
{
    if (this->moving)
        return;
    else if (direction == NONE) {
        this->moving = false;
        this->direction = NONE;
    } else {
        this->moving = true;
        this->direction = direction;
        this->timeBeforeStop = 1.0f;
    }
}

void ind::Player::update(float deltaTime)
{
    this->timeBeforeStop -= deltaTime;
    if (this->timeBeforeStop <= 0.0f)
        this->move(NONE);
}

void ind::Player::draw()
{
}

bool ind::Player::isMoving()
{
    return this->moving;
}

std::pair<float, float> ind::Player::getPosition()
{
    return this->position;
}

ind::ORIENTATION ind::Player::getDirection()
{
    return this->direction;
}
