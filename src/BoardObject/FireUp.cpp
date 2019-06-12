/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** FireUp.cpp
*/

#include "FireUp.hpp"
#include "Player.hpp"

ind::FireUp::FireUp(ind::Position position, const irr::io::path &path) : PowerUp(position, path)
{
    createGraphicalCube();
}

void ind::FireUp::upgrade(ind::Player &player)
{
    player.fireUp();
}
