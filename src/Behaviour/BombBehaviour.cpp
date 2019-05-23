/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "BombBehaviour.hpp"

ind::BombBehaviour::BombBehaviour(ind::Bomb &bomb) : bomb(bomb)
{}

void ind::BombBehaviour::update(float deltaTime)
{
    this->bomb.decreaseTime(deltaTime);
    if (this->bomb.getTime() <= 0.0f)
    {
        this->bomb.explode();
    }
}
