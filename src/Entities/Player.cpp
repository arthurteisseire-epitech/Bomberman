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

void ind::Player::update(float deltaTime)
{}

void ind::Player::draw()
{
}

ind::Player::Player(std::pair<float, float> position, ind::ORIENTATION rotation, IBehaviour &behaviour)
    : AbstractEntity(position, rotation, behaviour)
{}

void ind::Player::move(ind::ORIENTATION direction)
{
    this->rotation = direction;
}
