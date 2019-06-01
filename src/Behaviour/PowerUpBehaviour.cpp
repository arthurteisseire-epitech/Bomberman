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
    std::cout << "construit le bhavouil" << std::endl;
}

void ind::PowerUpBehaviour::update(float deltaTime)
{
    std::cout << "BITE" << std::endl;
    auto rotation = this->powerUp.getSceneNode()->getRotation();
    const float rotationAdder = 60 * deltaTime;
    float newRotation = rotation.Y + rotationAdder;
    if (newRotation >= 360.0f)
        newRotation -= 360.0f;
    rotation.Y = newRotation;
    std::cout << "NEW VALUE : " << rotation.X << std::endl;
    this->powerUp.getSceneNode()->setRotation(rotation);
}
