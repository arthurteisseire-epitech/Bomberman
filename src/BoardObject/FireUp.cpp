/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** FireUp.cpp
*/

#include "FireUp.hpp"
#include "Player.hpp"

ind::FireUp::FireUp(Position position) : PowerUp(position, "assets/red.jpg")
{
    createGraphicalCube();
}

void ind::FireUp::upgrade(ind::Player &player)
{
    player.fireUp();
}
