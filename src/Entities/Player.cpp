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

void ind::Player::move(std::pair<float, float> transform)
{
    this->position.first += transform.first;
    this->position.second += transform.second;
}

void ind::Player::update(float deltaTime)
{
    this->timeBeforeStop -= deltaTime;
}

void ind::Player::draw()
{
}

bool ind::Player::isMoving() const
{
    return this->moving;
}

ind::Player::Player(std::pair<float, float> position, ind::ORIENTATION rotation, IBehaviour &behaviour)
    : AbstractEntity(position, rotation, behaviour)
{}
