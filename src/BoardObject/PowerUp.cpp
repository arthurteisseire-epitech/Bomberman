/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#include "PowerUp.hpp"

ind::PowerUp::PowerUp(ind::Position position, const irr::io::path &path)
    : BoardObject(position, path)
{
}

ind::Tile ind::PowerUp::getTile() const
{
    return POWERUP;
}
