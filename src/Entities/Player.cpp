/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "Player.hpp"
#include "PlayerBehaviour.hpp"

void ind::Player::placeBomb()
{
}

void ind::Player::update(float deltaTime)
{}

void ind::Player::draw()
{
}

ind::Player::Player(const Position &position, ind::ORIENTATION rotation, PlayerNumber playerNum) :
    AbstractEntity(position, rotation)
{
    auto *behaviour = new PlayerBehaviour(*this, playerNum);
    this->setBehaviour(static_cast<IBehaviour *>(behaviour));
}

void ind::Player::move(ind::ORIENTATION direction)
{
    this->rotation = direction;
}
