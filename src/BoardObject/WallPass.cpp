/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** WallPass.cpp
*/

#include "WallPass.hpp"
#include "Player.hpp"

ind::WallPass::WallPass(ind::Position position) : PowerUp(position, "assets/wallpass.png")
{
    createGraphicalCube();
}

void ind::WallPass::upgrade(ind::Player &player)
{
    player.enableWallPass();
}

ind::PowerType ind::WallPass::getType() const
{
    return WALLPASS;
}

std::string ind::WallPass::toString() const
{
    return BoardObject::toString() + WALLPASS_NAME;
}
