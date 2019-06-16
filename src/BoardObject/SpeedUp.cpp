/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** SpeedUp.cpp
*/

#include "SpeedUp.hpp"
#include "Player.hpp"

ind::SpeedUp::SpeedUp(ind::Position position) : PowerUp(position, "assets/fast.jpeg")
{
    createGraphicalCube();
}

void ind::SpeedUp::upgrade(ind::Player &player)
{
    player.speedUp();
}

ind::PowerType ind::SpeedUp::getType() const
{
    return SPEEDUP;
}
