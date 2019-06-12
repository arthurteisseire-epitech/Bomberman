/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** WallPass.cpp
*/

#include "WallPass.hpp"
#include "Player.hpp"

ind::WallPass::WallPass(ind::Position position, const irr::io::path &path) : PowerUp(position, path)
{
    createGraphicalCube();
}

void ind::WallPass::upgrade(ind::Player &player)
{
    player.enableWallPass();
}
