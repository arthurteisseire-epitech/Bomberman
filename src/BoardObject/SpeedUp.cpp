/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** SpeedUp.cpp
*/

#include "SpeedUp.hpp"
#include "Player.hpp"

ind::SpeedUp::SpeedUp(ind::Position position, const irr::io::path &path) : PowerUp(position, path)
{
    createGraphicalCube();
}

void ind::SpeedUp::upgrade(ind::Player &player)
{
    player.speedUp();
}
