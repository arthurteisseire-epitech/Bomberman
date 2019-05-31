/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "Player.hpp"
#include "BombUp.hpp"

ind::BombUp::BombUp(ind::Position position, const irr::io::path &path)
    : PowerUp(position, path)
{
    this->createGraphicalCube();
}

void ind::BombUp::upgrade(Player &player)
{
    player.setBombNumber(player.getBombNumber() + 1);
}
