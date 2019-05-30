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
    bomb.decreaseTime(deltaTime);
    if (bomb.getTime() <= 0.0f) {
        bomb.explode();
    }
}
