/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include <iostream>
#include "PowerUpBehaviour.hpp"

ind::PowerUpBehaviour::PowerUpBehaviour(ind::PowerUp &powerUp) : powerUp(powerUp)
{
}

void ind::PowerUpBehaviour::update(float deltaTime)
{
    auto rotation = this->powerUp.getSceneNode()->getRotation();
    const float rotationAdder = 60 * deltaTime;
    float newRotation = rotation.Y + rotationAdder;
    if (newRotation >= 360.0f)
        newRotation -= 360.0f;
    rotation.Y = newRotation;
    this->powerUp.getSceneNode()->setRotation(rotation);
}
